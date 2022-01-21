#include "sandpiles.h"

/**
 * sandpiles_sum - sums two sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 *
 * Return: void
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
	if (grid1[0][0] > 3 || grid1[0][1] > 3 || grid1[0][2] > 3 ||
		grid1[1][0] > 3 || grid1[1][1] > 3 || grid1[1][2] > 3 ||
		grid1[2][0] > 3 || grid1[2][1] > 3 || grid1[2][2] > 3)
	{
		printf("=\n");
		_print_grid(grid1);
		topples_sandpiles(grid1);
	}
}

/**
 * topples_sandpiles - checks if a sandpile is stable
 * @grid1: first sandpile
 *
 * Return: void
 */

void topples_sandpiles(int grid1[3][3])
{
	int i, j;
	int grid2[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid2[i][j] = 1;

			}

		}
	}
	stables_sandpiles(grid1, grid2);
}


/**
 * stables_sandpiles - checks if a sandpile is stable
 * @grid1: first sandpile
 * @grid2: second sandpile
 *
 * Return: void
 */


void stables_sandpiles(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid2[i][j] == 1)
			{
				grid1[i][j] = grid1[i][j] - 4;
				if (i - 1 >= 0)
					grid1[i - 1][j]++;
				if (i + 1 < 3)
					grid1[i + 1][j]++;
				if (j - 1 >= 0)
					grid1[i][j - 1]++;
				if (j + 1 < 3)
					grid1[i][j + 1]++;
			}
		}
	}
	if (grid1[0][0] > 3 || grid1[0][1] > 3 || grid1[0][2] > 3 ||
		grid1[1][0] > 3 || grid1[1][1] > 3 || grid1[1][2] > 3 ||
		grid1[2][0] > 3 || grid1[2][1] > 3 || grid1[2][2] > 3)
	{
		printf("=\n");
		_print_grid(grid1);
		topples_sandpiles(grid1);
	}
}

/**
 * _print_grid - prints a 3x3 grid
 * @grid: 3x3 grid
 *
 * Return: void
 */

void _print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
