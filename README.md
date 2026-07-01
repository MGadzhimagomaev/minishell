# minishell

*This project has been created as part of the 42 curriculum by rmarkov, mgadzhim.*

## Description

A minimal Unix shell implemented in C, modeled on Bash. The goal is to understand how a shell actually works, from reading a line of input to forking processes, wiring up pipes, and managing file descriptors, by building one from scratch.

The shell handles the full lifecycle of a command. It tokenizes the raw input, parses it into a command list, expands variables and quotes, then executes it with the correct redirections and pipe connections. All of this runs inside an interactive loop that respects the same signal behavior as Bash.

**Features:**

- Interactive prompt with command history (via `readline` / `add_history`)
- Executable lookup via `PATH`, relative paths, and absolute paths
- Single quotes `'...'`: no interpretation of any metacharacter inside
- Double quotes `"..."`: metacharacter interpretation suppressed except for `$`
- Environment variable expansion: `$VAR` expands to its value
- Exit-status expansion: `$?` expands to the exit code of the last foreground pipeline
- Redirections: `<` (input), `>` (output), `>>` (append), `<<` (heredoc)
- Pipes: `cmd1 | cmd2 | cmd3 ...`, stdout of each command connected to stdin of the next
- Unclosed quotes and unsupported special characters (`\`, `;`) are not interpreted
- Signal handling matching Bash interactive mode:
  - `ctrl-C`: prints a new prompt on a new line
  - `ctrl-D`: exits the shell
  - `ctrl-\`: does nothing
- Exactly one global variable, used only to store the received signal number
- Built-in commands (implemented without forking):
  - `echo [-n]`
  - `cd [path]`
  - `pwd`
  - `export [name=value]`
  - `unset [name]`
  - `env`
  - `exit [code]`
- All heap-allocated memory is freed before exit. `readline`'s own leaks are exempted per the subject.

## Instructions

**Requirements:** `cc`, `make`, `libreadline-dev` (already present on 42 machines)

```bash
# Clone and build
git clone <repo-url>
cd minishell
make

# Run
./minishell

# Remove object files
make clean

# Remove object files and binary
make fclean

# Rebuild from scratch
make re
```

## Work split

**Done together:** overall architecture, struct definitions and header (`minishell.h`), Makefile, memory cleanup (`free.c`), signal handling (`signals.c`).

**rmarkov, parsing pipeline**
- Lexer and tokenizer (`lexer.c`, `lexer2.c`, `lexer_utils.c`)
- Parser and command-list builder (`parser.c`, `parser2.c`, `parser_utils.c`)
- Variable expansion and quote resolution (`expand.c`, `expand_utils.c`)
- Environment list utilities (`env_utils.c`, `env_utils2.c`)

**mgadzhim, execution pipeline**
- Executor and process management (`executor.c`, `executor_utils.c`, `exec_cmd.c`)
- Pipe chaining, redirections, and heredoc (`redirects.c`, `heredoc.c`, `path.c`)
- All built-in commands (`ft_echo.c`, `ft_cd.c`, `ft_pwd.c`, `ft_export.c`, `ft_unset.c`, `ft_env.c`, `ft_exit.c`)
- Main loop and entry point (`main.c`)

## Resources

- [GNU Bash manual](https://www.gnu.org/software/bash/manual/bash.html): reference for undefined behavior
- [GNU Readline library](https://tiswww.case.edu/php/chet/readline/rltop.html): documentation for `readline`, `add_history`, and signal-safe usage
- *Advanced Programming in the UNIX Environment* (Stevens & Rago): process model, `fork`/`exec`/`pipe`, signal handling
- `man 2 execve`, `man 2 pipe`, `man 2 dup2`, `man 7 signal`: primary syscall references

**AI usage:** We used Claude to discuss design trade-offs (for example, preserving raw quotes during tokenization versus stripping them early), to clarify edge cases in `$?` expansion and heredoc signal handling, and to help edit this README. We reviewed and tested every suggestion against Bash before using it, and wrote the code ourselves.
