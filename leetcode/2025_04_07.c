////1704. 判断字符串的两半是否相似
//
//bool halvesAreAlike(char* s)
//{
//    int n = strlen(s) / 2;
//    int a = 0;
//    for (int i = 0; i < 2 * n; i++)
//    {
//        int t = s[i] + 32 * (s[i] < 'a');
//        int tmp = (((1 << (t - 'a')) & 0x104111) > 0);
//        if (i < n)
//            a += tmp;
//        else
//            a -= tmp;
//    }
//    return a == 0;
//}
//
////2068. 检查两个字符串是否几乎相等
//
//bool checkAlmostEquivalent(char* word1, char* word2)
//{
//    int hash[26] = { 0 };
//    for (int i = 0; word1[i]; i++)
//    {
//        hash[word1[i] - 'a']++;
//    }
//    for (int i = 0; word2[i]; i++)
//    {
//        hash[word2[i] - 'a']--;
//    }
//    for (int i = 0; i < 26; i++)
//    {
//        if (abs(hash[i]) > 3)
//            return false;
//    }
//    return true;
//}
//
////2190. 数组中紧跟 key 之后出现最频繁的数字
//
//int mostFrequent(int* nums, int numsSize, int key)
//{
//    int hash[1001] = { 0 };
//    int maxCnt = 0;
//    int val = 0;
//    for (int i = 0; i < numsSize - 1; i++)
//    {
//        if (nums[i] == key && ++hash[nums[i + 1]] > maxCnt)
//        {
//            maxCnt = hash[nums[i + 1]];
//            val = nums[i + 1];
//        }
//    }
//    return val;
//}
//
////2481. 分割圆的最少切割次数
//
//int numberOfCuts(int n) {
//    if (1 == n)
//        return 0;
//    return n & 1 ? n : n >> 1;
//}
//
