/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiamant <mdiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:51:30 by mdiamant          #+#    #+#             */
/*   Updated: 2023/03/14 14:08:50 by mdiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *src)
{
	int	len;

	len = 0;
	while (*src++)
		len++;
	return (len);
}

void	generate_line(char **line, t_list *stack)
{
	int	i;
	int	len;

	len = 0;
	while (stack)
	{
		i = 0;
		while (stack->content[i])
		{
			if (stack->content[i] == '\n')
			{
				len++;
				break ;
			}
			i++;
			len++;
		}
		stack = stack->next;
	}
	*line = malloc(sizeof(char) * (len +1));
}

void	free_stack(t_list *stack)
{
	t_list	*new_temp;
	t_list	*next;

	new_temp = stack;
	while (new_temp)
	{
		free(new_temp->content);
		next = new_temp->next;
		free(new_temp);
		new_temp = next;
	}
}

void	clean_stack(t_list **stack)
{
	t_list	*temp;
	t_list	*last;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = malloc(sizeof(t_list));
	if (!stack || !temp)
		return ;
	temp->next = NULL;
	last = lst_getlast(*stack);
	while (last->content[i] != '\n' && last->content[i])
		i++;
	if (last->content[i] == '\n')
		i++;
	temp->content = malloc(sizeof(char) * (ft_strlen(last->content + i) + 1));
	if (!temp->content)
		return ;
	while (last->content[i])
		temp->content[j++] = last->content[i++];
	temp->content[j] = 0;
	free_stack(*stack);
	*stack = temp;
}

void	extract_line(t_list *stack, char **line)
{
	int		i;
	int		j;

	j = 0;
	if (!stack)
		return ;
	generate_line(line, stack);
	if (!*line)
		return ;
	while (stack)
	{
		i = 0;
		while (stack->content[i])
		{
			if (stack->content[i] == '\n')
			{
				(*line)[j++] = stack->content[i];
				break ;
			}
			(*line)[j++] = stack->content[i++];
		}
		stack = stack->next;
	}
	(*line)[j] = 0;
}
