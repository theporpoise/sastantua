/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 19:49:36 by mgould            #+#    #+#             */
/*   Updated: 2016/10/30 23:40:46 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_putchar(char c);


int 	i_power(int nb, int power)
{
	int temp;
	int i;

	i = 0;
	temp = 1;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	while (i < power)
	{
		temp = temp * nb;
		i++;
	}
	return (temp);
}

int		group_last_line_size(int group_number)
{
	int temp1;
	int temp2;
	int temp3;
	int temp4;

	temp1 = i_power(group_number, 2);
	temp2 = i_power(-1, group_number);
	temp3 = (6 * temp1) + (28 * group_number) + temp2 - 5;
	temp4 = temp3 / 4;

	return temp4;
}

int	whitespace(size, group)
{
	int left_half;
	int first_line_half;
	int spaces;

	left_half = group_last_line_size(size);
	first_line_half = (group_last_line_size(group) - 1) / 2;
	spaces = left_half - first_line_half;
	
	return spaces;
}

void	group_row_printer(int leading_spaces, int group, int row)
{
	int line_size;

	line_size = group_last_line_size(group) - (((group + 2) - row) * 2);
	while(leading_spaces > 0)
	{
		ft_putchar(' ');
		leading_spaces--;
	}
	while(line_size > 0)
	{
		ft_putchar('*');
		line_size--;
	}
	ft_putchar('\n');
}

// int size is actually the number of groups, it's size of group set.
void	sastantua(int size)
{
	int row_count;
	int group_count;
	int leading_spaces;

	leading_spaces = 0;
	row_count = 1;
	group_count = 1;	
	
	if (size < 1)
		return;
	while (group_count <= size)
	{
		leading_spaces = whitespace(size, group_count);
		while(row_count <= (group_count + 2))
		{
			group_row_printer(leading_spaces, group_count, row_count);
			row_count++;
			leading_spaces--;
		}
		row_count = 1;
		group_count++;
	}
}







