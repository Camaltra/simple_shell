# 0X16.C - Simple_shell

![](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg)
### S/o Julien Barbier
## Simple shell :
```
Holberton School 
```

## Table of Contents :
* [Description](#description)
* [Files](#files)
* [Usage](#usage)
* [Example of Use](#example-of-use)
* [Authors](#authors)

## Description :
simple_shell is a command line interpreter, or shell, in the tradition of the first Unix shell written by Ken Thompson in 1971. This shell is intentionally minimalistic, yet includes the basic functionality of a traditional Unix-like command line user interface. 

## Files :
* [Function] :
  * [main](./main.c) - main function with shell body
  * [exevc](./_exevc.c) - recreate execve funtcion
  * [exit](./_exit_.c) - exit the simple shell 
  * [memcpy](./_memcpy.c) - recreate memcpy funtcion
  * [prompt](./_prompt.c) - recreate prompt funtcion
  * [realloc](./_realloc.c) - recreate realloc funtcion
  * [echo_command](./echo_command.c) - implementation of echo command in shell 
  * [node_function](./node_function.c) - Add a node a the end of the linked list
  * [_atoi](./_atoi.c) - Convert the first number of a str to an interger.
  * [execut_command](./execut_command.c) - Test and execute a command
  * [sep_to_space](./sep_to_space.c) - Change \t and \r into a space
  * [signal_handler](./signal_handler.c) - Catch a Ctrl - C and disable him

* [PATH function] :
  * [init_path](./init_path.c) - Initialise a linked list of the PATH contain
  * [search_command_path](./search_command_path.c) - Search if a command is in the PATH

* [str function] :
  * [strcmp](./_strcmp.c) - function compares the two strings
  * [strdup](./_strdup.c) - function returns a pointer to a new string which is a duplicate of the string
  * [strlen](./_strlen.c) - function calculates the length of the string pointed to by s
  * [strtok](./_strtok.c) - breaks a string into a sequence of zero or
       more nonempty tokens

* [check] :
   * [check_built_in](./check_built_in.c) - check all built-in command before the first fork
   * [check_user_input](./check_user_input.c) - Put a '\0' at the end of the input and check if there is any comment

* [environement function] :
  * [setenv](./_setenv.c) - set new environement
  * [setenv_necceseray](./_setenv_necceseray.c) - extension of setenv function
  * [_unsetenv](./_unsetenv.c) - unset environement, set with setenv
  * [get_env](./get_env.c) - get actual  environement 
  * [print_env](./print_env.c) - print environement
  * [copy_env](./copy_env.c) - copy environement

* [free memory file] :
  * [free_all](./free_all.c) - free all malloc / realloc / buffer

* [Header file] :
   * [shell.h](./shell.h) - Header file contain all prototype / standart library / and structure

* [Helping files] :
  * [README.md](./README.md)
  * [man](./man_1_simple_shell) 
  * [AUTHORS](./AUTHORS) 
  * [_help](./_help.c) 
  * [_help_function](./_help_function.c) 

## Requirements :


## Usage :

### Features :
- [x] uses the PATH
- [x] implements builtins
- [x] handles command line arguments
- [x] custom strtok function
- [x] uses exit status
- [x] shell continues upon Crtl+C (**^C**)
- [x] handles comments (#)
- [ ] handles **;**
- [x] custom getline type function
- [ ] handles **&&** and **||**
- [ ] aliases


### Builtins :

- [x] exit
- [x] env
- [x] setenv
- [x] unsetenv
- [x] cd
- [x] help

## Example of Use :
Run the executable in your terminal after compiling:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

./hsh
```
exemple:
```
./hsh
$  # type you command here
$ ls
    bermuda_triangle.c I_hate_simple_shell.c README.md
$ echo $$
    24413
$ env
    SHELL=/bin/bash
    COLORTERM=truecolor
    TERM_PROGRAM_VERSION=1.62.3
    LC_ADDRESS=C.UTF-8
    LC_NAME=C.UTF-8
    LC_MONETARY=C.UTF-8
    PWD=/home/vagrant/Simple_shell
    LOGNAME=vagrant
    XDG_SESSION_TYPE=tty
    VSCODE_GIT_ASKPASS_NODE=/home/vagrant/.vscode-server/bin/ccbaa2d27e38e5afa3e5c21c1c7bef4657064247/node
    MOTD_SHOWN=pam
    ...
$ exit # leave de shell ctrl C hase disable
```
### AUTHORS :

 ### [Mickael Boillaud](https://github.com/Camaltra) & [Axel Valentin](https://github.com/Pixeloceax) & [Jason Leuchart](https://github.com/Astambar) 

# for Holberton School
