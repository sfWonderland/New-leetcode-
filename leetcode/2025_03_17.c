//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>
//static int DIR[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };//сробвСио
//int main()
//{
//	int n = 0, m = 0;
//	scanf("%d %d", &m, &n);
//	int** square = (int**)malloc(sizeof(int*) * m);
//	for (int i = 0; i < n; i++)
//	{
//		square[i] = (int*)malloc(sizeof(int) * n);
//		memset(square[i], 0, n);
//	}
//	int row = m;
//	int col = n;
//	int size = m * n;
//	int num = 0;
//	int i = 0, j = -1;
//	for (int di = 0; num < size; di = (di + 1) % 4)
//	{
//		for (int t = 0; t < n; t++)
//		{
//			i += DIR[di][0];
//			j += DIR[di][1];
//			square[i][j] = ++num;
//		}
//		int tmp = n;
//		n = m - 1;
//		m = tmp;
//	}
//	for (int a = 0; a < row; a++)
//	{
//		for (int b = 0; b < col; b++)
//			printf("%d ", square[a][b]);
//		printf("\n");
//	}
//	free(square);
//	return 0;
//}