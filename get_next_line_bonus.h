/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiamant <mdiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:51:49 by mdiamant          #+#    #+#             */
/*   Updated: 2023/03/14 12:12:05 by mdiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
void	ft_read_stack(t_list **stack, int fd);
void	go_to_stack(t_list **stack, char *buffer, int r_read);
void	extract_line(t_list *stack, char **line);
t_list	*lst_getlast(t_list *stack);
int		chearch_endline(t_list *stack);
void	generate_line(char **line, t_list *stack);
void	free_stack(t_list *stack);
int		ft_strlen(const char *s);
void	clean_stack(t_list **stack);

#endif