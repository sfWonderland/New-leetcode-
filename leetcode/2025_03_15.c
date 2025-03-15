<<<<<<< HEAD
////3110. 字符串的分数
//
//int scoreOfString(char* s)
//{
//    int ret = 0;
//    for (int i = 1; s[i]; i++)
//    {
//        ret += abs(s[i] - s[i - 1]);
//    }
//    return ret;
//}
//
////423. 从英文中重建数字
//
//char* originalDigits(char* s)
//{
//    int alpha[26] = { 0 };
//    for (int i = 0; s[i]; i++)
//    {
//        alpha[s[i] - 'a']++;
//    }
//    int nums[10] = { 0 };
//    nums[0] = alpha[25];//Z - ZERO 0
//    nums[2] = alpha[22];//W - TWO 2
//    nums[6] = alpha[23];//X - SIX 6
//    nums[8] = alpha[6];//G - EIGHT 8
//    nums[3] = alpha[7] - nums[8];//H - EIGHT THREE 3
//    nums[7] = alpha[18] - nums[6];//S - SIX SEVEN 7
//    nums[5] = alpha[21] - nums[7];//V - SEVEN FIVE 5
//    nums[4] = alpha[5] - nums[5];//F - FIVE FOUR 4
//    nums[1] = alpha[14] - nums[0] - nums[2] - nums[4];//O - ZERO TWO FOUR ONE 1
//    nums[9] = alpha[8] - nums[5] - nums[6] - nums[8];//I - FIVE SIX EIGHT NINE 9
//    // 计算总数字字符数
//    int sum = 0;
//    for (int i = 0; i < 10; i++) sum += nums[i];
//    char* ret = (char*)malloc(sizeof(char) * (sum + 1));
//    //printf("sum = %d\n", sum);
//    int cnt = 0;
//    for (int i = 0; i < 10; i++)
//    {
//        //printf("i = %d, nums[%d] = %d\n", i, i, nums[i]);
//        while (nums[i] > 0)
//        {
//            ret[cnt++] = i + '0';
//            //printf("ret[%d] = %c\n", cnt - 1, ret[cnt - 1]);
//            nums[i]--;
//        }
//    }
//    ret[sum] = 0;
//    return ret;
//}
//
////338. 比特位计数
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
// // 方法二：动态规划——最高有效位
// // int* countBits(int n, int* returnSize) 
// // {
// //     int* ret = (int*)malloc(sizeof(int) * (n + 1));
// //     memset(ret, 0, sizeof(int) * (n + 1));
// //     returnSize[0] = n + 1;
// //     int num = 0;
// //     for(int i = 1; i < n + 1; i++)
// //     {
// //         if(i & (i - 1))
// //         ret[i] = 1 + ret[i - num];
// //         else
// //         {
// //             ret[i] = 1;
// //             num = i;
// //         }
// //     }
// //     return ret;
// // }
// // 方法三：动态规划——最低有效位
// // int* countBits(int n, int* returnSize) 
// // {
// //     int* ret = (int*)malloc(sizeof(int) * (n + 1));
// //     ret[0] = 0;
// //     returnSize[0] = n + 1;
// //     for(int i = 1; i < n + 1; i++)
// //     {
// //         ret[i] = (i & 1) + ret[i >> 1];
// //     }
// //     return ret;
// // }
// // 方法四：动态规划——最低设置位
//int* countBits(int n, int* returnSize)
//{
//    int* ret = (int*)malloc(sizeof(int) * (n + 1));
//    ret[0] = 0;
//    returnSize[0] = n + 1;
//    for (int i = 1; i < n + 1; i++)
//    {
//        ret[i] = ret[i & (i - 1)] + 1;
//    }
//    return ret;
//}
//
////832. 翻转图像
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes)
//{
//    int n = imageSize;
//    returnSize[0] = n;
//    *returnColumnSizes = imageColSize;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n / 2; j++)
//        {
//            if (image[i][j] == image[i][n - 1 - j])
//            {
//                image[i][j] ^= 1;
//                image[i][n - 1 - j] ^= 1;
//            }
//        }
//        if (n & 1)
//            image[i][n / 2] ^= 1;
//    }
//    return image;
//}
//
=======
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>
//static int DIR[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };//右下左上
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
