//#define _CRT_SECURE_NO_WARNINGS
//
////812.最大的三角形面积
//
//double triagleArea(int i0, int j0, int k0, int i1, int j1, int k1)
//{
//    return 0.5 * abs((j0 - i0) * (k1 - i1) - (k0 - i0) * (j1 - i1));
//}
//
//double largestTriangleArea(int** points, int pointsSize, int* pointsColSize)
//{
//    //printf("pointsSize = %d\n", pointsSize);
//    double ret = 0;
//    for (int i = 0; i < pointsSize - 2; i++)
//    {
//        for (int j = i + 1; j < pointsSize - 1; j++)
//        {
//            for (int k = j + 1; k < pointsSize; k++)
//            {
//                double area = triagleArea(points[i][0], points[j][0], points[k][0], points[i][1], points[j][1], points[k][1]);
//                if (ret < area)
//                    ret = area;
//                //printf("i = %d, j = %d, k = %d, area = %lf\n", i, j, k, area);
//            }
//        }
//    }
//    return ret;
//}
//
////976.三角形的最大周长
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int largestPerimeter(int* nums, int numsSize)
//{
//    int ret = 0;
//    qsort(nums, numsSize, sizeof(int), cmp);
//    for (int i = 0; i < numsSize - 2; i++)
//    {
//        int perimeter = nums[i] + nums[i + 1] + nums[i + 2];
//        if (nums[i] < nums[i + 1] + nums[i + 2])
//        {
//            ret = perimeter;
//            break;
//        }
//    }
//    return ret;
//}
//
////836.矩形重叠
//
//bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size)
//{
//    if (rec1[0] >= rec2[2])
//        return false;
//    else if (rec1[1] >= rec2[3])
//        return false;
//    else if (rec1[2] <= rec2[0])
//        return false;
//    else if (rec1[3] <= rec2[1])
//        return false;
//    else
//        return true;
//}
//
////860.柠檬水找零
//
//bool lemonadeChange(int* bills, int billsSize)
//{
//    int cinq = 0;
//    int dix = 0;
//    for (int i = 0; i < billsSize; i++)
//    {
//        if (5 == bills[i])
//            cinq++;
//        else if (10 == bills[i])
//        {
//            dix++;
//            cinq--;
//        }
//        else
//        {
//            if (dix)
//            {
//                dix--;
//                cinq--;
//            }
//            else
//                cinq -= 3;
//        }
//        if (cinq < 0 || dix < 0)
//            return false;
//    }
//
//    return true;
//}
//
////868.二进制间距
//
//int distance(int left, int right)
//{
//    int count = 0;
//    int n = left / right;
//    while (n > 1)
//    {
//        n >>= 1;
//        count++;
//        //printf("n = %d, count = %d\n", n, count);
//    }
//    return count;
//}
//
//int binaryGap(int n)
//{
//    int right = 0;
//    int left = 0;
//    int ret = 0;
//    do
//    {
//        right = left;
//        int tmp = n;
//        n &= n - 1;
//        left = tmp - n;
//        if (right > 0)
//        {
//            //printf("left = %d, right = %d\n", left, right);
//            int len = distance(left, right);
//            if (len > ret)
//                ret = len;
//        }
//    } while (n);
//
//    return ret;
//}
//
////2506.统计相似字符串对的数目
//
//int similarPairs(char** words, int wordsSize)
//{
//    int hash[wordsSize][26];
//    for (int i = 0; i < wordsSize; i++)
//    {
//        for (int j = 0; j < 26; j++)
//        {
//            hash[i][j] = 0;
//        }
//    }
//
//    for (int i = 0; i < wordsSize; i++)
//    {
//        int len = strlen(words[i]);
//        for (int j = 0; j < len; j++)
//        {
//            hash[i][words[i][j] - 'a']++;
//        }
//    }
//
//    // for(int i = 0; i < wordsSize; i++)
//    // {
//    //     for(int j = 0; j < 26; j++)
//    //     {
//    //         printf("hash[%d][%d] = %d ", i, j, hash[i][j]);
//    //     }
//    //     printf("\n");
//    // }
//
//    int count = 0;
//    for (int i = 0; i < wordsSize - 1; i++)
//    {
//        for (int j = i + 1; j < wordsSize; j++)
//        {
//            int flag = 0;
//            for (int k = 0; k < 26; k++)
//            {
//                if ((0 == hash[i][k] * hash[j][k]) && (hash[i][k] + hash[j][k] != 0))
//                {
//                    flag = 1;
//                    //printf("B, k = %d\n", k);
//                    break;
//                }
//            }
//            if (!flag)
//                count++;
//
//            //printf("i = %d, j = %d, flag = %d\n", i, j, flag);
//        }
//    }
//
//    return count;
//}
//
//
////1684.统计一致字符串的数目
//
//int countConsistentStrings(char* allowed, char** words, int wordsSize)
//{
//    int hash[26] = { 0 };
//    int len = strlen(allowed);
//
//    for (int i = 0; i < len; i++)
//    {
//        hash[allowed[i] - 'a']++;
//    }
//
//    int count = 0;
//    for (int i = 0; i < wordsSize; i++)
//    {
//        int lenw = strlen(words[i]);
//        int flag = 1;
//        for (int j = 0; j < lenw; j++)
//        {
//            if (!hash[words[i][j] - 'a'])
//            {
//                flag = 0;
//                break;
//            }
//        }
//        if (flag)
//            count++;
//    }
//
//    return count;
//}
//
//
