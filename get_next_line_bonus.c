/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiamant <mdiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:51:12 by mdiamant          #+#    #+#             */
/*   Updated: 2023/03/14 14:08:38 by mdiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_list	*stack[1024];
	char			*line;

	line = NULL;
	if (fd < 0 || read(fd, &line, 0) < 0 || BUFFER_SIZE < 0)
		return (NULL);
	ft_read_stack(&stack[fd], fd);
	if (!stack[fd])
		return (NULL);
	extract_line(stack[fd], &line);
	clean_stack(&stack[fd]);
	if (line[0] == 0)
	{
		free_stack(stack[fd]);
		stack[fd] = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

void	ft_read_stack(t_list **stack, int fd)
{
	char	*buffer;
	int		r_read;

	r_read = 1;
	while (!chearch_endline(*stack) && r_read != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		r_read = read(fd, buffer, BUFFER_SIZE);
		if ((!*stack && r_read == 0) || r_read == -1)
		{
			free(buffer);
			return ;
		}
		buffer[r_read] = 0;
		go_to_stack(stack, buffer, r_read);
		free(buffer);
	}
}

int	chearch_endline(t_list *stack)
{
	int		i;
	t_list	*last;

	if (!stack)
		return (0);
	last = lst_getlast(stack);
	i = 0;
	while (last->content[i])
	{
		if (last->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*lst_getlast(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	while (temp && temp->next)
		temp = temp->next;
	return (temp);
}

void	go_to_stack(t_list **stack, char *buffer, int r_read)
{
	int		cnt;
	t_list	*temp;
	t_list	*last;

	cnt = 0;
	temp = malloc(sizeof(t_list));
	if (!temp)
		return ;
	temp->next = NULL;
	temp->content = malloc(sizeof(char) * (r_read + 1));
	if (!temp->content)
		return ;
	while (buffer[cnt] && cnt < r_read)
	{
		temp->content[cnt] = buffer[cnt];
		cnt++;
	}
	temp->content[cnt] = 0;
	if (!*stack)
	{
		*stack = temp;
		return ;
	}
	last = lst_getlast(*stack);
	last->next = temp;
}
