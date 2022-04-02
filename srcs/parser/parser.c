#include <command.h>
#include <stdlib.h>
#include <unistd.h>

t_command	*parser_parse(char *line)
{
	t_command	*commands;

	commands = command_splitter(line);
	command_iterator(commands, command_replace_vars); 
	command_iterator(commands, command_redirections); 

	return (commands);
}

void	parser_free(t_command *commands)
{
	if (!commands)
		return ;
	parser_free(commands->next);
	free(commands->cmd);
	ft_split_free(commands->argv);
	if (commands->fdin != 0)
		close(commands->fdin);
	if (commands->fdout != 0)
		close(commands->fdout);
}
