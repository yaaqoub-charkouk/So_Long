#include "../header.h"
// validate_map_chars 
static void    ft_init_vars(t_count *count, int *i)
{
	count->c_count = 0;
	count->e_count = 0;
	count->p_count = 0;
	*i = 0;
}
static int	map_chars_counter(char c, t_count *counter)
{
	if (c == 'E')
		counter->e_count++;
	else if (c == 'P')
		counter->p_count++;
	else if (c == 'C')
		counter->c_count++;
	else if (c != '0' && c != '1')
		return (ft_printf("Map error: invalid char '%c' \n", c), 0);
	return (1);
}

int validate_map_chars(char **map) // this is the important haha !!!!!!!!!!
{
	t_count counter;
	int i;
	int j;
	int check;

	ft_init_vars(&counter, &i);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			check = map_chars_counter(map[i][j], &counter);
			if (check == 0)
				return (0);
			j++;
		}
		i++;
	}
	if (counter.e_count != 1)
		return (ft_printf("Map error: it must be one exit.\n"), 0);
	if (counter.p_count != 1)
		return (ft_printf("Map error: it must be one player.\n"), 0);
	if (counter.c_count < 1)
		return (ft_printf("Map error: it must be at least one collectable.\n"), 0);
	return (1);
}
