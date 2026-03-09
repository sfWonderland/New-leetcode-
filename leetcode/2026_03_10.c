////775. 全局倒置与局部倒置
//
//bool isIdealPermutation(int* nums, int numsSize)
//{
//    int n = numsSize;
//    int min = nums[n - 1];
//    for (int i = n - 3; i >= 0; i--)
//    {
//        if (nums[i] > min)
//            return false;
//        if (nums[i + 1] < min)
//            min = nums[i + 1];
//    }
//    return true;
//}
//
////779. 第K个语法符号    
//
//int kthGrammar(int n, int k)
//{
//    k--;
//    bool res = 0;
//    while (k)
//    {
//        res ^= 1;
//        k &= k - 1;
//    }
//    return res;
//}
//
////791. 自定义字符串排序
//
//int prior[26] = { 0 };
//int cmp(const void* e1, const void* e2)
//{
//    return prior[*(char*)e2 - 'a'] - prior[*(char*)e1 - 'a'];
//}
//char* customSortString(char* order, char* s)
//{
//    for (int i = 0; order[i]; i++)
//    {
//        prior[order[i] - 'a'] = 25 - i;
//    }
//    int n = strlen(s);
//    qsort(s, n, sizeof(char), cmp);
//    return s;
//}
//
////915. 分割数组
//
//int partitionDisjoint(int* nums, int numsSize)
//{
//    int suf[numsSize + 1];
//    suf[numsSize] = INT_MAX;
//    for (int i = numsSize - 1; i >= 0; i--)
//    {
//        suf[i] = suf[i + 1] < nums[i] ? suf[i + 1] : nums[i];
//    }
//    int pre = INT_MIN;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] > pre)
//            pre = nums[i];
//        if (pre <= suf[i + 1])
//            return i + 1;
//    }
//
//    return numsSize;
//}
//
