#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
void roundNum(int** square,int start, int row, int col)
{
	if (row == col)
	{
		if(start != col)
			for (int i = start; i < col; i++)
			{
				square[start][i] = start + i;
			}
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int** square = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
	{
		square[i] = (int*)malloc(sizeof(int) * n);
		memset(square[i], 0, n);
	}
	int row = n;
	int col = n;
	roundNum(square, 0, n, n);
}