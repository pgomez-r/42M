/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 22:04:00 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/03/01 13:50:31 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"

/*DEFS*/
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"
/*Types/Tokens*/
# define T_VOID '0' //sin catalogar todavía o literal
# define T_CMD 'c' //command (de momento no hace falta catalogar este tipo)
# define T_OPT 'o' //option (de momento no hace falta catalogar este tipo)
# define T_BLT 'b' //built (no se usa, tenemos built-in_flag en cada t_command)
# define T_PIP '|' //pipe
# define T_INF 'i' //infile - archivo entrada/input fd
# define T_OUF 'o' //outfile - archivo salida/output fd
# define T_APF 'O' //outfile para APPEND
# define T_DQT '\"' //bloque en comillas dobles
# define T_SQT '\'' //bloque comillas simples
# define T_VAR '$' //variable (si hay que expandir, si no tipo '0')
# define T_INR '<' //redirección entrada
# define T_OUR '>' //redirección salida
# define T_HDC 'h' //heredoc '<<'
# define T_APP 'a' //redirección salida con APPEND '>>'
# define T_EOF 'E' //end of file para heredoc (expande variables)
# define T_EOD 'e' //end of file para heredoc (no expande variables)
# define T_BSL '\\' //backslash
# define T_SCL ';' //semicolon
# define T_AND '&' //"&&" AND operator

int							g_sign;

typedef struct s_input		t_input;
typedef struct s_element	t_element;
typedef struct s_data		t_data;
typedef struct s_env		t_env;
/*STRUCTS*/
/*Estructura para cada elemento del input, guarda tipo y su contenido en str*/
typedef struct s_element
{
	char	type;
	char	*data;
}	t_element;

/*Estructura que uso solamente para pipex/exegguttor de momento, veré si puedo
pasar sus elementos a otra de element o input o si es mejor tenerla aislada*/
typedef struct s_command
{
	int			size;
	int			fd_in;
	int			fd_out;
	int			fd_error;
	int			built;
	int			open_hd;
	char		**paths;
	char		*path_cmd;
	char		*cmd_line;
	char		**cmd_tab;
	t_element	*tokens;
	t_data		*dataptr;
}	t_command;

/*Estructura para la lectura del input completo, dentro guardamos varias flags
o info general y un array con todos los elementos de la linea, esto lo re-
utilizamos en cada lectura*/
typedef struct s_input
{
	int			n_elements;
	int			cmd_n;
	int			(*pipes)[2];
	char		**sp_input;
	t_element	*elements;
	t_command	*cmds;
	t_data		*dptr;
}	t_input;

/*Estructura para cada variable de entorno (tendremos que crear un array de
este tipo de struct)*/
typedef struct s_env
{
	char	*full;
	char	*title;
	char	*line;
}	t_env;

/*Estructura "general", iremos añadiendo elementos según vayamos necesitando*/
typedef struct s_data
{
	char		**env_dup;
	char		**env_exp;
	t_env		*env_arr;
	int			env_size;
	char		*rl_input;
	int			og_stdin;
	int			og_stdout;
	int			exit_code;
	char		*var;
	char		*val;
	char		*aux;
	t_input		in;
	char		*content;
	char		*read;
	char		*eof;
	pid_t		pid;
	int			pes;
	char		q;
	int			q_flag;
	int			exp_flag;
}	t_data;

/**********************[main.c]***********************************/
void					ft_engine(t_data *d);
/**********************[mini_utils.c]***********************************/
void					ft_wait(pid_t pid, t_data *d, int mode);
void					ft_free_str(char *str);
char					*ft_str_rplc(char *src, char *new);
int						ft_is_space(char c);
void					ft_flag_check(t_data *d, char c, int mode);
/**********************[mini_utils_1.c]***********************************/
void					ft_free_flags(t_data *d, int mode, int *pos);
int						ft_is_num(char *str);
int						ft_is_dir(t_data *d, char *str);
void					ft_excve_dircheck(char *str);
int						ft_cd_protect(t_data *d, char *var);
/**********************[signals.c]***********************************/
void					ft_signal(void);
void					ft_cmd_sig(int sig);
void					ft_here_sig(int sig);
void					ft_handler(int sig);
void					ft_control_d(t_data *d);
/**********************[init.c]***********************************/
void					ft_init_pipes(t_input *in);
void					ft_parse_env(t_data *d, char **env);
void					ft_split_env(t_data *d, char *var, size_t x);
void					ft_get_envarray(t_data *d);
void					ft_init(t_data *d, char **env);
/**********************[manage_input.c]***********************************/
int						ft_manage_input(t_data *d);
void					ft_fill_elements(t_input *in);
int						ft_check_elements(t_input *in, t_element *array, t_data *d);
int						ft_its_dollar(char *str);
void					ft_dollar_check(t_command *cmd, t_data *d);
/**********************[check_spchar.c]***********************************/
int						ft_is_special_char(char c);
void					ft_check_special_chars_right(t_data *d);
char					*ft_insert_right_space(char *s, int pos);
void					ft_check_special_chars_left(t_data *d);
char					*ft_insert_left_space(char *s, int pos);
/**********************[lexer.c]***********************************/
int						ft_lexer(t_data *d);
void					ft_token_spchars(t_input *in);
void					ft_token_redirs(t_input *in);
void					ft_token_files(t_input *in);
void					ft_token_and(t_input *in);
/**********************[lexer_utils.c]***********************************/
int						ft_is_red(char	*s);
void					ft_syntax_error(t_input *in, int i);
int						ft_eof_check(t_input *in);
void					ft_error(t_data *d, int code, char *msg);
int						ft_char_pos(char *s, char c);
/**********************[arr_tools_0.c]***********************************/
t_element				*ft_arr_update(t_input *in, int i, char c);
void					ft_fill_arr(t_input *in, t_element *new_arr, int tar, char **tab);
char					**ft_element_split(char *str, char c);
t_element				*ft_db_redirs(t_input *in, int i, char c);
char					**ft_dbredir_split(char *str, char c);
/**********************[arr_tools_1.c]***********************************/
void					ft_tag_type(t_element *arr, int start, int size, char c);
char					*ft_write_token(char c);
size_t					ft_count_elements(char *str, char c);
void					ft_tag_redtype(t_element *arr, int start, int size, char c);
char					*ft_save_dbred(char c);
/**********************[syntax_check.c]***********************************/
int						ft_syntax_check(t_input *in);
int						ft_stdset_check(t_input *in);
int						ft_spcset_check(t_input *in);
/**********************[cmd_maker.c]***********************************/
void					ft_cmd_maker(t_input *in);
void					ft_init_cmd(t_input *in);
void					ft_get_cmdline(t_command *cmd);
void					ft_format_cmd(t_command *cmd, t_data *d);
int						ft_check_empty(t_command *cmd);
/**********************[cmd_maker_utils.c]***********************************/
int						ft_element_cnt(t_input	*in, char c);
int						ft_cmd_size(t_input *in, int *start);
char					*ft_addspace(char *str);
void					ft_init_files(t_command *cmd);
t_element				*ft_delete_element(t_command *cmd, int pos);
/**********************[expand.c]**************************************/
char					*ft_expand_excd(char *src, t_data *d);
void					ft_quote_exp(char c, t_data *d);
char					*ft_expand_other(char *content, t_data *d, int pos);
char					*ft_rplc_content(char *content, char *value, int start, int del);
char					*ft_expand(char *content, t_data *d);
/**********************[expand_utils.c]**************************************/
void					ft_expand_init(char *content, t_data *d, int i);
char					*ft_get_dollar_word(char *str, int start);
char					*ft_search_value(char *comp, t_env *env, int lenv);
char					*ft_var_del(char *s);
void					ft_quotes(t_command *cmd, t_data *d);
/**********************[quotes.c]***********************************/
void					ft_separate_quotes(t_data *d);
void					ft_recovery_sp(t_input *input);
int						ft_is_quote(char c);
int						ft_in_quotes(char *str, int c);
int						ft_quote_in_data(char *str);
/**********************[quotes2.c]***********************************/
int						ft_management_quotes(t_element *element, t_data *d);
int						ft_closed_quotes(char *str);
char					ft_define_qtype(t_element element);
char					*ft_clean_quotes(t_element *element, t_data *d);
int						ft_count_quotes(char *str);
/**********************[heredoc.c]***********************************/
void					ft_write_doc(t_command *cmd, char *content);
void					ft_heredoc(t_command *cmd, int pos, t_data *d, int *exit);
int						ft_heredoc_loop(t_command *cmd, t_data *d);
void					ft_is_heredoc(t_command *cmd, t_data *d);
/**********************[heredoc_utils.c]***********************************/
void					ft_content_buffer(t_data *d);
void					ft_heredoc_init(t_data *d, t_command *cmd, int pos);
void					ft_check_hdocfile(t_command *cmd);
int						ft_expand_char(char c);
/**********************[redir.c]***********************************/
void					ft_file_fds(t_command *cmd);
void					ft_open_file(t_command *cmd, char *file, int type);
void					ft_open_check(t_command *cmd, int fd, char *file_path);
int						ft_std_redir(t_command *cmd);
void					ft_std_shield(t_data *d, int mode);
/**********************[cmd_driver.c]***********************************/
int						ft_cmd_driver(t_data *d, t_command *cmds);
void					ft_shell_pipex(t_data *d, int i);
void					ft_built_exe(t_command *cmd, t_data *d);
void					ft_exegguttor(t_command *cmds, t_data *d);
void					ft_excve(t_command *cmd, t_data *d, int mode);
/**********************[exegguttor_utils.c]***********************************/
int						is_path(char *str);
void					ft_excve_error(t_command *cmd);
void					ft_split_cmd(t_command *st, t_data *d);
int						find_path_index(t_command *st, char *cmd);
void					get_paths(t_command *st, char **env);
/**********************[bi_utils.c]***********************************/
void					ft_tag_builts(t_command *cmds, int len);
int						ft_is_built(char *str);
char					*ft_getenv(t_data *d, char *var);
void					ft_overwrite_var(t_data *d, char *var, char *new);
/**********************[bi_exit_echo.c]***********************************/
int						ft_env_withargs(char **args, t_data *d);
void					bi_env(char **args, t_data *d);
void					bi_exit(char **args, t_data *d);
void					bi_echo(t_data *d, char **args);
void					ft_exit_mod(char **args, t_data *d);
/**********************[bi_dir.c]***********************************/
void					bi_pwd(t_data *d);
void					ft_update_pwd(t_data *d, char *old_pwd);
void					bi_cd(t_data *d, t_command *cmd);
int						ft_dir_back(t_data *d, char *arg);
void					ft_dir_home(t_data *d);
/**********************[bi_exp.c]***********************************/
void					bi_export(t_data *d, t_command *cmd);
char					**ft_env_update(t_data *d, char *var);
char					**ft_exp_update(t_data *d, char *var);
int						ft_var_replace(t_data *d, char *var);
/**********************[bi_exp_utils.c]***********************************/
int						ft_val_id(char *arg, int mode);
int						ft_isvar(char *arg);
void					ft_export_print(t_data *d);
char					**ft_export_order(char **env);
char					*ft_export_varcopy(char *str);
/**********************[bi_unset.c]***********************************/
void					bi_unset(t_data *d, t_command *cmd);
char					**ft_delete_var(char **str_tab, int pos);
void					ft_unset_env(t_data *d, char *arg);
void					ft_unset_exp(t_data *d, char *arg);
/**********************[free.c]***********************************/
void					ft_clean_input(t_input *input);
void					ft_free_data(t_data *d);
void					ft_free_arr(t_input *in, int size);
void					ft_clean_exit(t_data *d);
void					ft_free_cmds(t_input *in);
/**********************basura***********************************/
void					print_error(char *s);

#endif