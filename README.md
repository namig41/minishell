# minishell

<p align="center">
  <img src="minishell.png" width="100%" />
</p>

## About

### Instructions

- You must program a *mini UNIX command interpreter*.
- This interpreter must display a prompt (a simple `current path > ` for example)
  by displaying a message adapted to the error output.
  and the environment (copy of system char `**environ`).
- You must implement a series of builtins:
  - `cd`
  - `setenv`
  - `help`
  - `pwd`
  - `clear`
  - `echo`
  - `eval`
  - `exit`

#### Allowed Functions

- malloc, free
- open, close, read, write
- opendir, readdir, closedir
- fork, execve
- wait
- exit

## Project Structure

### Source files

```
src
├── builtins
│   ├── cmd_cd.c
│   ├── cmd_clear.c
│   ├── cmd_echo.c
│   ├── cmd_env.c
│   ├── cmd_eval.c
│   ├── cmd_exit.c
│   ├── cmd_help.c
│   ├── cmd_pwd.c
│   └── cmd_setenv.c
├── commands.c
├── env.c
├── minishell.c
├── parser.c
├── path.c
├── process.c
└── utilities.c

1 directory, 16 files

```

### Header files

```
includes
└── minishell.h

0 directories, 1 file

```

### How to use it

Using ``make`` will create the ``minishell`` executable.

Simply run it with :

```

./minishell

```

You can separate commands with ``;``, as well as use redirections ``>`` ``>>`` ``<`` and pipes ``|``.

