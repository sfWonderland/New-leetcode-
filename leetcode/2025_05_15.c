////2900. 最长相邻不相等子序列 I
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//void input(char** words, char** ans, int* n, int x)
//{
//    ans[*n] = (char*)malloc(sizeof(char) * 11);
//    int i = 0;
//    for (; words[x][i]; i++)
//    {
//        ans[*n][i] = words[x][i];
//    }
//    ans[(*n)++][i] = '\0';
//}
//char** getLongestSubsequence(char** words, int wordsSize, int* groups, int groupsSize, int* returnSize)
//{
//    int left = groups[0], n = 0;
//    char** ans = (char**)malloc(sizeof(char*) * groupsSize);
//    input(words, ans, &n, 0);
//    for (int right = 1; right < groupsSize; right++)
//    {
//        if (groups[right] ^ left)
//        {
//            input(words, ans, &n, right);
//            left = groups[right];
//        }
//    }
//
//    *returnSize = n;
//    return ans;
//}
//
////3541. 找到频率最高的元音和辅音
//
//int maxFreqSum(char* s)
//{
//    int hash[26] = { 0 };
//    for (int i = 0; s[i]; i++)
//    {
//        hash[s[i] - 'a']++;
//    }
//    int vowel = 0, consonant = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20)
//            vowel = fmax(vowel, hash[i]);
//        else
//            consonant = fmax(consonant, hash[i]);
//    }
//    return consonant + vowel;
//}
//
////2974. 最小数字游戏
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//void swap(int* a, int* b)
//{
//    int tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//int* numberGame(int* nums, int numsSize, int* returnSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    for (int i = 1; i < numsSize; i += 2)
//    {
//        swap(&nums[i], &nums[i - 1]);
//    }
//    *returnSize = numsSize;
//    return nums;
//}
//
////3248. 矩阵中的蛇
//
//int finalPositionOfSnake(int n, char** commands, int commandsSize)
//{
//    int ans = 0;
//    for (int i = 0; i < commandsSize; i++)
//    {
//        if (commands[i][0] == 'R')
//            ans++;
//        else if (commands[i][0] == 'L')
//            ans--;
//        else if (commands[i][0] == 'D')
//            ans += n;
//        else
//            ans -= n;
//    }
//    return ans;
//}
//
