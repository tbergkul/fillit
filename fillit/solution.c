/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:20:21 by tbergkul          #+#    #+#             */
/*   Updated: 2019/11/19 13:05:02 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_coordinates(char *tetrimino, t_coordinates *coordinates)
{
	int	y;

	y = -1;
	while (tetrimino[++y])
		if (tetrimino[y] != '.' && tetrimino[y] != '\n')
		{
			//printf("%c\n", tetrimino[y]);
			//printf("first coord = %d\n", y);
			coordinates->a = y;
			break ;
		}
	while (tetrimino[++y])
		if (tetrimino[y] != '.' && tetrimino[y] != '\n')
		{
			coordinates->b = y;
			break ;
		}
	while (tetrimino[++y])
		if (tetrimino[y] != '.' && tetrimino[y] != '\n')
		{
			coordinates->c = y;
			break ;
		}
	while (tetrimino[++y])
		if (tetrimino[y] != '.' && tetrimino[y] != '\n')
		{
			coordinates->d = y;
			break ;
		}
}

int		letter_check(char *solution, int j, int letter, int size)
{
	int	count;
	int	newline;

	newline = 0;
	count = 0;
	if (solution[j + 1] == letter)
		count++;
	if (solution[j - 1] == letter)
		count++;
	if (solution[j - size - 1] == letter)
		count++;
	if (solution[j + size + 1] == letter)
		count++;

	/*if (solution[j + 1] == '\n')
		newline = 1;
	if (solution[j + 1 + newline] == letter)
		count++;
	if (newline == 1)
		newline = 0;
	if (solution[j - 1] == '\n')
		newline = 1;
	if (solution[j - 1 - newline] == letter)
		count++;
	if (solution[j - size - 1] == letter)
		count++;
	if (solution[j + size + 1] == letter)
		count++;*/
	return (count);
}

int		letter_neighbours(char *solution, int letter, int size)
{
	int	j;
	int	amount;

	j = -1;
	amount = 0;
	while (solution[++j])
		if (solution[j] == letter)
			amount =  amount + letter_check(solution, j, letter, size);
	printf("neighbours: %d\n", amount);
	if (amount != 6 && amount != 8)
				return (-1);
	return (0);
}

char	*ft_strnew_newline(int size)
{
	char	*str;
	int		i;
	int		length;
	int		counter;

	if (!(str = (char *)malloc(sizeof(char) * (size * size + size + 1))))
		return (NULL);
	i = 0;
	length = size * size + size + 1;
	counter = 1;
	while (--length > 0)
	{
		if (counter != 0 && counter % (size + 1) == 0)
		{
			str[i++] = '\n';
			counter = 0;
		}
		else
			str[i++] = '.';
		counter++;
	}
	str[i] = '\0';
	return (str);
}

int		ft_solution(char ***tetris, char **solution, int size, int grid)//size = size of grid, grid = which grid/solution
{
	t_coordinates	coordinates;
	int				x;
	int				i;
	int				j;
	int				letter;//Problem: coordinater med olika size av solution funkar ej(2x2, 3x3, 4x4 osv)
	int				index;//Problem: borjar int om fran tetris[0] when ft_solution is called again
							// with bigger size and grid
	solution[grid] = ft_strnew_newline(size);
	//printf("solution[%d]:\n%s", grid, solution[grid]);
	letter = 65;
	/*while ()
	{*/
		x = -1;
		while (*tetris[++x] && grid <= 4)//byt condition nar storre solution
		{
			ft_coordinates(*tetris[x], &coordinates);
			/*printf("tetris[%d]coord.a = %d\n", x, coordinates.a);
			printf("tetris[%d]coord.b = %d\n", x, coordinates.b);
			printf("tetris[%d]coord.c = %d\n", x, coordinates.c);
			printf("tetris[%d]coord.d = %d\n", x, coordinates.d);*/
			j = -1;
			while (solution[grid][++j])
			{
				if ((solution[grid][j] == '.') &&
				((solution[grid][j + (coordinates.b - coordinates.a + (size - 4))] == '.') &&
				(solution[grid][j + (coordinates.c - coordinates.a + (size - 4))] == '.') &&
				(solution[grid][j + (coordinates.d - coordinates.a + (size - 4))] == '.')))
				{
					//printf("fill letter\n");
					solution[grid][j] = letter;
					solution[grid][j + (coordinates.b - coordinates.a + (size - 4))] = letter;
					solution[grid][j + (coordinates.c - coordinates.a + (size - 4))] = letter;
					solution[grid][j + (coordinates.d - coordinates.a + (size - 4))] = letter;
					//printf("solution[0]:\n%s\n", solution[0]);
					//printf("check return: %d\n", letter_neighbours(solution[grid], letter, size));
					if (letter_neighbours(solution[grid], letter, size) < 0)
					{
						//printf("reset\n");
						solution[grid][j] = '.';
						solution[grid][j + (coordinates.b - coordinates.a + (size - 4))] = '.';
						solution[grid][j + (coordinates.c - coordinates.a + (size - 4))] = '.';
						solution[grid][j + (coordinates.d - coordinates.a + (size - 4))] = '.';
					}
					//printf("solution[%d]:\n%s", grid, solution[grid]);
					break ;
				}
				//printf("%c\n", letter);
			}
			//Om den inte hittade en plats,
			//call function again with bigger grid and size

			index = -1;
			while (solution[grid][++index])
			{
				if (solution[grid][index] == letter)
				{
					//printf("Found letter\n");
					break ;
				}
				if (solution[grid][index + 1] == '\0')
				{
					//size++;
					//grid++;
					//printf("size: %d, grid: %d\n", size, grid);
					printf("not same letter anywhere in solution, return -1\n");
					return (-1);
				}
			}
			//printf("A done\n");
			letter++;
			//printf("x = %d\n", x);
		}
	//}
	//printf("x = %d\n", x);
	grid++;
	solution[grid] = NULL;
	//printf("solution[0]:\n%s\n", solution[0]);
	//printf("solution[1]:\n%s\n", solution[1]);
	return (0);
}
