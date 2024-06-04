/bin/ls
/bin/hostname
/usr/bin/vim
/usr/bin/whoami
/usr/bin/wc
/bin/ls -la
/bin/hostname -s
echo
echo -n
echo -n -n -n -n
echo -n -n -n hola tu que -n pasa colega -n
echo hola tu que -n pasa colega -n
echo $INVENT hola $USER y '$PWD'
./minishell ./minishell → exit asdkahd → numeric argument required (pero ejecuta y sale) → $? = 255
./minishell ./minishell → exit → $? = 0
/minishell ./minishell → exit 42 → $? = 42
/minishell ./minishell → exit 42 45 2124 → exit: too many arguments (y no ejecuta ni sale) → $? = 1
/minishell ./minishell → exit 42 asdasd 2124 → exit: too many arguments (y no ejecuta ni sale) → $? = 1
/minishell ./minishell → exit -452 → $? = 60
echo $?+$?
ctrl-C in an empty prompt should display a new line with a new prompt.
ctrl-\ in an empty prompt should not do anything → ps | grep minishell → kill -s SIGQUIT [pid]
ctrl-D in an empty prompt should quit minishell --> RELAUNCH!
ctrl-Z que no de seg_fault
ctrl-C in a prompt after you wrote some stuff should display a new line with a new prompt. The buffer should be clean too. Press "Enter" to make sure nothing from the previous line is executed.
ctrl-D in a prompt after you wrote some stuff should not do anything. 
ctrl-\ in a prompt after you wrote some stuff should not do anything.
Try ctrl-C after running a blocking command like cat without arguments or grep "something".
Try ctrl-\ after running a blocking command like cat without arguments or grep "something".
Try ctrl-D after running a blocking command like cat without arguments or grep "something". Repeat multiple times using different commands.
CTRL + D en bloqueante → añadir varios input → ejecutar
BLOQUEANTE + HEREDOC → CTRL D sale pero ejecuta / CTRL C sale
echo "cat lol.c | cat > lol.c"
l"s" -l"a"|gr"ep" 'Make'file
ls | grep 'Mak'e'file'
echo hola$IVENT"$PWD"$TEST'$HOME'$HOME tu
echo ' '
echo hola '     ' tu que p"  "asa
echo ""
env asdlakdas asldkasd alssd -> $? = 127
env env env
env - -> $? = 0
env -la -> $? = 1
env -lachota
export TEST=1234
export 1TEST=1234 -> $? = 1
export 1TEST=12=34 -> $? = 1
export . -> $? = 1
export - -> $? = 1
export TEST=hola
export TEST2=hola
unset TEST
unset TEST2
unset
unset asdad
unset -1HOLA
unset 1HOLA
unset unset unset unset
unset unset unset unset USER
unset unset unset unset /USER PWD
cd -
cd ../
cd
export -> checkPWD / OLDPWD
unset HOME | cd
unset PWD OLDPWD | cd ..
mkdir test | cd /test | chmod 000 ../test | ls
mkdir test | cd /test | chmod 000 ../test | cd
mkdir test | cd /test | chmod 000 ../test | echo hola
pwd
pwd lachota larga
pwd -q
[from Users/pgomez-r/github/minishell/] ../../../../bin/ls -la
[from Users/pgomez-r/github/minishell/] ../../../../usr/bin/wc -c
ls | grep Makefile | wc -c
unset PATH
ls | grep Makefile | wc -c
Set the $PATH to a multiple directory value (directory1:directory2) and ensure that directories are checked in order from left to right
export PATH=/bin
ls
wc
export PATH=/bin:/usr/bin
wc -c "hola" | ls
ls -la | wc -w
> out ls
< out cat
<< 0 wc -w (sin input para heredoc, meter EOF o CTRL-D)
cat << 0 > out | cat -e out (con y sin input para heredoc)
ls << 0 (con y sin input para heredoc)
ls > out | cat -e out
echo "taluego.txt" >> out | cat -e out
echo "hola" > out | echo "hola" > out | echo "hola" > out | echo "hola" > out | echo "hola" > out | echo "hola" > out | echo "hola" > out
echo "hola" >> out | echo "hola" >> out | echo "hola" >> out | echo "hola" >> out | echo "hola" >> out | echo "hola" >> out | echo "hola" >> out
wc -l < out >> out | wc -l < out >> out | wc -l < out >> out | wc -l < out >> out | wc -l < out >> out
wc -w << 0 > out | echo hola >> out | wc -w << 0 >> out | cat -e out
<< eof + CTRL-D / EOF sin nada mas en input -> no debe hacer nada
wc -w << eof + CTRL-D / EOF -> debe recibir el heredoc como argumento aunque no tenga nada
cat out | grep hola | more
cat noexiste | grep chota | more
Type a command line, then use ctrl-C and press "Enter". The buffer should be clean and there should be nothing left to execute
lachotaasdd
"asdadmine".,asd'"'
wc -w "hola" "compadre" que pasa loco como estas
echo 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50
find . -name '*.c' -o -name '*.h' -o -name '*.cpp' -o -name '*.hpp' -o -name '*.py' -o -name '*.java' -o -name '*.js' -o -name '*.ts' -o -name '*.html' -o -name '*.css' -o -name '*.scss' -o -name '*.go' -o -name '*.rb' -o -name '*.php'
echo hola$INVENT"$PWD"$TEST'$HOME'$HOME tucara $LANG'$OLDPWD'
ls -la; grep Makefile
ls -la || grep Makefile
ls -la | (grep Makefile)
ls -la \  grep Makefile
ls -la && grep Makefile
ls -la & grep Makefile
ls -la; ps || grep minishell && id; (ls -la) \ michotalarga | echo "$USER"'$HOME' > delocos
echo "$USER"'$HOME'

echo "> >> < * ? [ ] | ; [ ] || && ( ) & # $ \ <<"
echo "$"
echo $
cat minishell.h | grep ");"$

$EMPTY
$EMPTY echo hid