### minishell

## Overview

minishell is a simplified implementation of a Unix shell, written in C. It provides basic command execution, input/output redirection, piping, and built-in shell commands, while mimicking Bash-like behavior.

## Features

Displays a prompt and waits for user input.

Maintains a command history.

Executes commands found in PATH, as well as relative and absolute paths.

Supports environment variable expansion ($VAR).

Implements the following built-in commands:

```
echo (with -n option)

cd (relative or absolute path)

pwd

export

unset

env

exit
```

Supports input/output redirection:

```
< for input redirection.

> for output redirection.

>> for output redirection in append mode.

<< (here-document) reads input until a specified delimiter is reached.
```

Implements pipes (|) to connect commands.

Handles special shell behaviors:

```
ctrl-C starts a new prompt.

ctrl-D exits the shell.

ctrl-\ does nothing.
```

Expands $? to return the exit status of the last executed command.

## Installation

**Prerequisites**

GCC or Clang compiler

Make

Libft (must be included in the project)

**Build***

Clone the repository and compile the program:

``` sh
make
```

This will generate the minishell executable.

To clean up object files:

``` sh
make clean
```

To remove binaries and object files:

``` sh
make fclean
```

To recompile everything:

``` sh
make re
```

## Usage

Run the shell:

``` sh
./minishell
```

Once started, minishell will display a prompt and wait for user commands.

## External Functions Used

Readline Library: readline, rl_clear_history, add_history, rl_on_new_line, rl_replace_line, rl_redisplay

Standard C Functions: printf, malloc, free, write, strerror, perror

File Operations: open, close, read, access, unlink, stat, lstat, fstat

Process Management: fork, wait, waitpid, wait3, wait4, execve, kill, exit

Pipes & Redirections: dup, dup2, pipe

Signals: signal, sigaction, sigemptyset, sigaddset

Environment & Directories: getcwd, chdir, getenv

Terminal Control: isatty, ttyslot, tcgetattr, tcsetattr, tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs

## License

This project follows the 42 School project guidelines.