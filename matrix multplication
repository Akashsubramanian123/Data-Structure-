#include<stdio.h>

int main()
{
	int r1, c1, r2, c2;
	printf("Enter the order of the first matrix: ");
	scanf("%d %d", &r1, &c1);
	printf("Enter the order of the second matrix: ");
	scanf("%d %d", &r2, &c2);
	if (c1 != r2)
	{
		r2 = c1;
		printf("The rows of the matrix 2 must be equal to the column of the matrix 1\n");
		printf("The order is changed for the second matrix as %d x %d\n", r2, c2);
	}
	int i, j, k;
	int m1[r1][c1], m2[r2][c2], mul[10][10];
	printf("Enter the elements of the first matrix: \n");
	for (i = 0; i < r1; i++)
	{
		for (j = 0; j < c1; j++)
		{
			scanf("%d", &m1[i][j]);
		}
	}
	printf("Enter the elements of the second matrix: \n");
	for (i = 0; i < r2; i++)
	{
		for (j = 0; j < c2; j++)
		{
			scanf("%d", &m2[i][j]);
		}
	}
	for (i = 0; i < r1; i++)
	{
		for (j = 0; j < c2; j++)
		{
			mul[i][j] = 0;
			for (k = 0; k < c1; k++)
			{
				mul[i][j] += m1[i][k] * m2[k][j];
			}
			printf("%d\t", mul[i][j]);
		}
		printf("\n");
	}
	return 0;
}
