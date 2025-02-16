//#define _CRT_SECURE_NO_WARNINGS
//
////1299.ÿ��Ԫ���滻Ϊ�Ҳ�����Ԫ�أ��ģ�
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* replaceElements(int* arr, int arrSize, int* returnSize)
//{
//    int t = arr[arrSize - 1];
//    arr[arrSize - 1] = -1;
//    for (int i = arrSize - 2; i >= 0; i--)
//    {
//        if (arr[i] > t)
//        {
//            int tmp = arr[i];
//            arr[i] = t;
//            t = tmp;
//        }
//        else
//            arr[i] = t;
//    }
//    *returnSize = arrSize;
//    return arr;
//}
//
////2078.������ɫ��ͬ�Ҿ�����Զ�ķ���
//
//// int maxDistance(int* colors, int colorsSize) 
//// {
////     int n = 1;
////     for(int i = 0; i < colorsSize; i++)
////     {
////         for(int j = colorsSize - 1; j > i; j--)
////         {
////             if(colors[i] != colors[j] && j - i > n)
////             n = j - i;
////         }
////     }
////     return n;
//// }
//
//int maxDistance(int* colors, int colorsSize)
//{
//    int c = colors[0];
//    if (c != colors[colorsSize - 1])
//        return colorsSize - 1;
//
//    int left = 1;
//    int right = colorsSize - 2;
//    while (colors[left] == c)
//        left++;
//    while (colors[right] == c)
//        right--;
//    return right > colorsSize - 1 - left ? right : colorsSize - 1 - left;
//}
//
////2016.����Ԫ��֮�������ֵ
//
//int maximumDifference(int* nums, int numsSize)
//{
//    int min = nums[0];
//    int n = 0;
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (nums[i] < min)
//            min = nums[i];
//        else if (nums[i] - min > n)
//            n = nums[i] - min;
//    }
//    return n ? n : -1;
//}
//
////121.������Ʊ�����ʱ��
//
//int maxProfit(int* prices, int pricesSize)
//{
//    int min = prices[0];
//    int n = 0;
//    for (int i = 1; i < pricesSize; i++)
//    {
//        if (prices[i] < min)
//            min = prices[i];
//        else if (prices[i] - min > n)
//            n = prices[i] - min;
//    }
//    return n;
//}
//
////1550.����������������������
//
//bool threeConsecutiveOdds(int* arr, int arrSize)
//{
//    int n = 0;
//    for (int i = 0; i < arrSize; i++)
//    {
//        if (arr[i] & 1)
//            n++;
//        else
//            n = 0;
//        if (n > 2)
//            return true;
//    }
//    return false;
//}
//
////1572.����Խ���Ԫ�صĺ�
//
//int diagonalSum(int** mat, int matSize, int* matColSize)
//{
//    int sum = 0;
//    for (int i = 0; i < matSize; i++)
//    {
//        sum += mat[i][i] + mat[matSize - 1 - i][i];
//    }
//    return sum - mat[matSize / 2][matSize / 2] * (matSize & 1);
//}
//
////2133.����Ƿ�ÿһ��ÿһ�ж�����ȫ������ 
//
//bool checkValid(int** matrix, int matrixSize, int* matrixColSize)
//{
//    int hash[matrixSize];
//    memset(hash, 0, sizeof(int) * matrixSize);
//    for (int i = 0; i < matrixSize; i++)
//    {
//        for (int j = 0; j < matrixSize; j++)
//        {
//            if (hash[matrix[i][j] - 1] > i)
//                return false;
//            else
//                hash[matrix[i][j] - 1]++;
//        }
//    }
//
//    for (int i = 0; i < matrixSize; i++)
//    {
//        for (int j = 0; j < matrixSize; j++)
//        {
//            if (hash[matrix[j][i] - 1] > i + matrixSize)
//                return false;
//            else
//                hash[matrix[j][i] - 1]++;
//        }
//    }
//    return true;
//}
//
//
////2319.�жϾ����Ƿ���һ�� X ����
//
//bool checkXMatrix(int** grid, int gridSize, int* gridColSize)
//{
//    for (int i = 0; i < gridSize; i++)
//    {
//        for (int j = 0; j < gridSize; j++)
//        {
//            if ((!grid[i][j]) == (i == j || i + j == gridSize - 1))
//                return false;
//        }
//    }
//    return true;
//}
//
////1576.�滻���е��ʺ�
//
//char get_alpha(char x, char y)
//{
//    if (x != 'a' && y != 'a')
//        return 'a';
//    else if (x + y != 195)
//        return 'b';
//    else
//        return 'c';
//}
//char* modifyString(char* s)
//{
//    int len = strlen(s);
//    for (int i = 0; i < len; i++)
//    {
//        if (s[i] == '?')
//        {
//            if (0 == i)
//                s[i] = get_alpha(s[i + 1], 'z');
//            else if (len - 1 == i)
//                s[i] = get_alpha(s[i - 1], 'z');
//            else
//                s[i] = get_alpha(s[i + 1], s[i - 1]);
//        }
//    }
//    return s;
//}
