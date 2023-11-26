/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiamant <mdiamant@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:50:36 by mdiamant          #+#    #+#             */
/*   Updated: 2023/08/15 16:29:40 by mdiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
#include <sys/time.h>


// long long int	get_time(void)
// {
// 	struct timeval	tv;
// 	long long int	time;

// 	gettimeofday(&tv, NULL);
// 	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
// 	return (time);
// }
long long int	get_time(void)
{
	struct timeval tv;
	long long int time_ms;

	gettimeofday(&tv, NULL);
	time_ms = tv.tv_sec * 1000LL + tv.tv_usec / 1000LL;
	return time_ms;
}
int	main(int argc, char **argv)
{
	char	*line;
	int		fd;
	long long int	time;

	time = get_time();
	if (argc != 2)
		return (0);
	line = NULL;

	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	printf("\n");
	printf("Time: %lld\n", get_time() - time);
	return (0);
}
