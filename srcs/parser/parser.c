#include <readline/readline.h>
#include <stdlib.h>
#include <command.h>

t_command	*command_splitter(char const *line);
void	command_replace_vars(t_command *cmd);

#include <stdio.h>
void	print_all(t_command const *command)
{
	size_t	current_arg;

	if (!command)
		return ;
	printf("cmd: %s\n", command->cmd);
	printf("argc: %d\n", command->argc);
	printf("argv: %p\n", command->argv);
	current_arg = 0;
	while (command->argv && command->argv[current_arg])
	{
		printf("argv: %s\n", command->argv[current_arg]);
		current_arg++;
	}
	printf("tmp: %s\n", command->tempargs);
	printf("fdin: %d\n", command->fdin);
	printf("fdout: %d\n\n", command->fdout);
	print_all(command->next);
}

int		main(void)
{
	char		*line;
	t_command	*commands;

	line = readline("CMD line: ");

	commands = command_splitter(line);
	command_iterator(commands, command_replace_vars); 

	print_all(commands);
	free(line);
}
