////2843. 统计对称整数的数目
//
//int countSymmetricIntegers(int low, int high)
//{
//    if (high < 11 || low == 10000)
//        return 0;
//
//    if (high > 99 && high < 1001)
//        high = 99;
//    else if (high == 10000)
//        high = 9999;
//
//    if (low < 11)
//        low = 11;
//    else if (low > 99 && low < 1001)
//        low = 1001;
//
//    int n = 0;
//    int flag = low > 1000;
//    for (int i = low; i <= high; i++)
//    {
//        if (i > 99 && i < 1001)
//        {
//            i = 1001;
//            flag = 1;
//        }
//
//        if (flag)
//        {
//            int c = i / 1000 + i / 100 % 10;
//            int d = i / 10 % 10 + i % 10;;
//            if (c == d)
//                n++;
//        }
//        else
//        {
//            if (i % 11 == 0)
//                n++;
//        }
//    }
//    return n;
//}
//
////2309. 兼具大小写的最好英文字母
//
//char* greatestLetter(char* s)
//{
//    int hash[26][2] = { 0 };
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] >= 'a' && s[i] <= 'z')
//        {
//            hash[s[i] - 'a'][0] |= 2;
//            if (hash[s[i] - 'a'][1] == 0)
//                hash[s[i] - 'a'][1] = i;
//        }
//        else if (s[i] >= 'A' && s[i] <= 'Z')
//        {
//            hash[s[i] - 'A'][0] |= 1;
//            if (hash[s[i] - 'A'][1] == 0)
//                hash[s[i] - 'A'][1] = i;
//        }
//    }
//    int max = 0;
//    char* ret = malloc(2);
//    ret[0] = 0;
//    ret[1] = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        if (hash[i][0] == 3)
//        {
//            max = fmax(max, hash[i][1]);
//            ret[0] = i + 'A';
//        }
//    }
//    return ret;
//}
//
////2363. 合并相似的物品
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e1)[0] - (*(int**)e2)[0];
//}
//int** mergeSimilarItems(int** items1, int items1Size, int* items1ColSize, int** items2, int items2Size, int* items2ColSize, int* returnSize, int** returnColumnSizes)
//{
//    int** ret = (int**)malloc(sizeof(int*) * (items1Size + items2Size));
//    for (int i = 0; i < items1Size + items2Size; i++)
//    {
//        ret[i] = (int*)malloc(sizeof(int) * 2);
//    }
//    qsort(items1, items1Size, sizeof(int) * 2, cmp);
//    qsort(items2, items2Size, sizeof(int) * 2, cmp);
//    int n = 0;
//    int i = 0, j = 0;
//    while (i < items1Size && j < items2Size)
//    {
//        if (items1[i][0] < items2[j][0])
//        {
//            ret[n][0] = items1[i][0];
//            ret[n++][1] = items1[i][1];
//            i++;
//        }
//        else if (items1[i][0] > items2[j][0])
//        {
//            ret[n][0] = items2[j][0];
//            ret[n++][1] = items2[j][1];
//            j++;
//        }
//        else
//        {
//            ret[n][0] = items1[i][0];
//            ret[n++][1] = items1[i][1] + items2[j][1];
//            i++; j++;
//        }
//    }
//    while (i < items1Size)
//    {
//        ret[n][0] = items1[i][0];
//        ret[n++][1] = items1[i][1];
//        i++;
//    }
//    while (j < items2Size)
//    {
//        ret[n][0] = items2[j][0];
//        ret[n++][1] = items2[j][1];
//        j++;
//    }
//    returnSize[0] = n;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        (*returnColumnSizes)[i] = 2;
//    }
//    return ret;
//}
//
////2423. 删除字符使频率相同
//
//bool equalFrequency(char* word)
//{
//    int hash[26] = { 0 };
//    int n = 0;
//    for (int i = 0; word[i]; i++)
//    {
//        hash[word[i] - 'a']++;
//        n++;
//    }
//    int min = INT_MAX;
//    int max = 0;
//    int num = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        if (hash[i])
//        {
//            min = fmin(hash[i], min);
//            max = fmax(hash[i], max);
//            num++;
//        }
//    }
//    for (int i = 0; i < 26; i++)//频率超过2种排除
//    {
//        if (hash[i] && hash[i] != min && hash[i] != max)
//            return false;
//    }
//    return max == 1 || n == num * (max - 1) + 1 || n == (num - 1) * max + 1;
//    // 1.min = max = 1
//    // 2.max = min + 1; 且只有一个max
//    // 3.min = 1; 且只有一个min
//}
//
