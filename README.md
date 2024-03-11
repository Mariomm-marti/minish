<div align='center'>

# miniSH
#### _A reduced functionality bash-like_

[About the project](#about-the-project) ~
[Features](#features) ~
[Compiling and using](#compiling-and-using)

</div>

## About the project
In this project we built a functional bash-like shell that offers some functionality.
The project is completely built in C with limited external libraries (namely `readline`).

## Features
This small bash-like shell offers the following features, from which you can
expect a similar behaviour to the one you'd find in bash.

[x] A prompt
    [x] Fully functional history (using [readline](https://tiswww.case.edu/php/chet/readline/rltop.html))
[x] Environment variables
    [x] Find all with both `env` and `export`
    [x] Set more with `export VAR=value`
    [x] Access their values with `$VAR`
    [x] Status code variable `$?` which represents the latest command executed' status code
[x] Path resolving
    [x] Relative path: `../my_program`, `./my_program`, `./bin/my_program`, ...
    [x] Absolute path: `/bin/bash`, `/bin/ls`, `/usr/bin/find`, ...
    [x] Path resolving: from the env `PATH` all programs so you can execute `bash`, `ls`, `find`, ... without relative or absolute path
[x] Pipes: allowing streaming data between processes: `cat /dev/urandom | hexdump | head -n 5` will streamline all lines until one process
    decides to stop accepting / processing the stream
[x] Quoting
    [x] Single quotes to skip everything: `echo 'whatever | happens $HERE is "skipped"'`
    [x] Double quotes to skip everything except variables: `echo "$PATH"$PATH"$PATH"` will produce three times concatenated `$PATH`'s value
[x] Redirections
    [x] Input redirection: `cat < /etc/shells` will pass `/etc/shells` to the `/bin/cat` command by `stdin`
    [x] Output redirection: `cat < /etc/shells > ./test` will first receive `/etc/shells` as `stdin` and then forward the output to `./test`,
        effectively copying `/etc/shells` into `./test`
    [x] Output redirection in append: as the previous one, but preserves the target file's content
    [x] Heredocs: `cat << EOF` will allow you to write several lines until the word `EOF` is written, processing everything as one single entry
[x] Signals! `Ctrl+C`, `Ctrl+D` and `Ctrl+\` allowing seemingless interaction by our normal ideas of a terminal
[x] Builtins
    [x] `echo` with `-n`
    [x] `cd` with both relative and absolute paths
    [x] `pwd`
    [x] `export`
    [x] `unset`
    [x] `env`
    [x] `exit`

## Compiling and using
> ⚠️  The usage of `readline` is necessary! You can install it in MacOS using `brew install readline`.
> ⚠️  The expected path for `readline` is `/opt/homebrew/opt/readline/`. Other paths must be indicated
> by replacing the variables `RL_LIB` and `RL_INC` on the Makefile.

A simple clone and `make` of the repository should be enough to compile the program into `./minishell`.

> ℹ️  You can set `minishell` as your default shell (_if you are out of your mind_) by adding it to
> `/etc/shells` and executing `/usr/bin/chsh` in MacOS.
