/**
 * @file resolve_labyrinth.cpp
 *
 * @version 01.01 2020-08-15
 *
 * @brief 
 *
 * @ingroup resolve_labyrinth
 * (Note: this needs exactly one @defgroup somewhere)
 *
 * @author Castellani Davide
 *
 * Contact: contacts@castellanidavide.it
 *
 */
#include <stdio.h>
#define SIZE 12

int n = 1;

void check(char lab[SIZE][SIZE], int x, int y);

int main()
{
	// printf() displays the string inside quotation
	printf("resolve_labyrinth\n");

	char lab[SIZE][SIZE] = {"############",
							"#...##.....#",
							"x.#.##.###.#",
							"###.##...#.#",
							"#....###.#.#",
							"####.#.#.#.#",
							"#..#.#.#.#.#",
							"##.#.#.#.#..",
							"#........#.#",
							"######.###.#",
							"#......###..",
							"############"};

	int x = 2;
	int y = 0;

	check(lab, x, y);

	return 0;
}

void check(char lab[SIZE][SIZE], int x, int y)
{
	//printf("Test [%d, %d]\n", x, y);

	if (x > 0)
	{
		if (lab[x - 1][y] == '.')
		{
			lab[x - 1][y] = 'x';
			check(lab, x - 1, y);
			lab[x - 1][y] = '.';
		}
	}
	if (x < SIZE - 1)
	{
		if (lab[x + 1][y] == '.')
		{
			lab[x + 1][y] = 'x';
			check(lab, x + 1, y);
			lab[x + 1][y] = '.';
		}
	}
	if (y > 0)
	{
		if (lab[x][y - 1] == '.')
		{
			lab[x][y - 1] = 'x';
			check(lab, x, y - 1);
			lab[x][y - 1] = '.';
		}
	}
	if (y < SIZE - 1)
	{
		if (lab[x][y + 1] == '.')
		{
			lab[x][y + 1] = 'x';
			check(lab, x, y + 1);
			lab[x][y + 1] = '.';
		}
	}
	if (y == SIZE - 1) // end
	{
		printf("---Solution %d---\n", n++);
		for (size_t i = 0; i < SIZE; i++)
		{
			for (size_t j = 0; j < SIZE; j++)
			{
				printf("%c", lab[i][j]);
			}
			puts("");
		}
		puts("");
	}
}