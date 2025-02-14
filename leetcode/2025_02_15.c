//#define _CRT_SECURE_NO_WARNINGS
//
////1496.判断路径是否相交
//
//bool isPathCrossing(char* path)
//{
//    int x = 0;
//    int y = 0;
//    int** set = (int**)malloc(sizeof(int*) * 201);
//    for (int i = 0; i < 201; i++)
//    {
//        set[i] = (int*)malloc(sizeof(int) * 201);
//        memset(set[i], 0, sizeof(int) * 201);
//    }
//    set[100][100] = 1;
//    for (int i = 0; path[i]; i++)
//    {
//        if (path[i] == 'N')
//            y--;
//        else if (path[i] == 'S')
//            y++;
//        else if (path[i] == 'E')
//            x++;
//        else
//            x--;
//        //printf("path[%d] = %c, x = %d, y = %d\n", i, path[i], x, y);
//        if (set[x + 100][y + 100])
//            return true;
//        else
//            set[x + 100][y + 100] = 1;
//    }
//    free(set);
//    return false;
//}
//
////1502.判断能否形成等差数列
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//bool canMakeArithmeticProgression(int* arr, int arrSize)
//{
//    qsort(arr, arrSize, sizeof(int), cmp);
//    int d = arr[1] - arr[0];
//    for (int i = 2; i < arrSize; i++)
//    {
//        if (arr[i] - arr[i - 1] != d)
//            return false;
//    }
//    return true;
//}
//
////1518.换水问题
//
//// int numWaterBottles(int numBottles, int numExchange) 
//// {
////     int sum = numBottles;
////     int empty = numBottles;
////     while(empty >= numExchange)
////     {
////         int exchange = empty / numExchange;
////         sum += exchange;
////         empty -= exchange * (numExchange - 1);
////     }
////     return sum;
//// }
//int numWaterBottles(int numBottles, int numExchange)
//{
//    return numBottles >= numExchange ? (numBottles - 1) / (numExchange - 1) + numBottles : numBottles;
//}
//
////1523.在区间范围内统计奇数数目
//
//int countOdds(int low, int high)
//{
//    return (high + 1) / 2 - low / 2;
//}
//
////2980.检查按位或是否存在尾随零
//
//bool hasTrailingZeros(int* nums, int numsSize)
//{
//    int n = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (!(nums[i] & 1))
//            n++;
//        if (n > 1)
//            return true;
//    }
//    return false;
//}
//
////2710.移除字符串中的尾随零
//
//char* removeTrailingZeros(char* num)
//{
//    int len = strlen(num);
//    for (int i = len - 1; i >= 0; i--)
//    {
//        if ('0' != num[i])
//        {
//            num[i + 1] = '\0';
//            break;
//        }
//    }
//    return num;
//}
//
////1528.重新排序字符串 
//
//char* restoreString(char* s, int* indices, int indicesSize)
//{
//    char* ret = (char*)malloc(sizeof(char) * (indicesSize + 1));
//    ret[indicesSize] = 0;
//    for (int i = 0; i < indicesSize; i++)
//    {
//        ret[indices[i]] = s[i];
//    }
//
//    return ret;
//}
//
////1534.统计好三元组
//
//int countGoodTriplets(int* arr, int arrSize, int a, int b, int c)
//{
//    int num = 0;
//    for (int i = 0; i < arrSize - 2; i++)
//    {
//        for (int j = i + 1; j < arrSize - 1; j++)
//        {
//            if (abs(arr[i] - arr[j]) > a)
//                continue;
//            for (int k = j + 1; k < arrSize; k++)
//            {
//                if ((abs(arr[j] - arr[k]) > b) || (abs(arr[i] - arr[k]) > c))
//                    continue;
//
//                num++;
//                //printf("i = %d, j = %d, k = %d\n", i, j, k);
//            }
//        }
//    }
//
//    return num;
//}
//
////1995.统计特殊四元组
//
//int countQuadruplets(int* nums, int numsSize)
//{
//    int num = 0;
//    for (int a = 0; a < numsSize - 3; a++)
//    {
//        for (int b = a + 1; b < numsSize - 2; b++)
//        {
//            for (int c = b + 1; c < numsSize - 1; c++)
//            {
//                for (int d = c + 1; d < numsSize; d++)
//                {
//                    if (0 == nums[a] + nums[b] + nums[c] - nums[d])
//                        num++;
//                }
//            }
//        }
//    }
//    return num;
//}
////待改善
//
////2475.数组中不等单元组的数目
//
//int unequalTriplets(int* nums, int numsSize)
//{
//    int n = 0;
//    for (int i = 0; i < numsSize - 2; i++)
//    {
//        for (int j = i + 1; j < numsSize - 1; j++)
//        {
//            if (nums[i] ^ nums[j])
//                for (int k = j + 1; k < numsSize; k++)
//                {
//                    if ((nums[i] ^ nums[k]) && (nums[j] ^ nums[k]))
//                        n++;
//                }
//        }
//    }
//    return n;
//}
