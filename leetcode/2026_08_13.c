//// 68. ÎÄ±¾×óÓÒ¶ÔÆë
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//void manage(char** ans, char** words, int left, int right, int sum, int maxWidth, int* n)
//{
//    ans[*n] = (char*)malloc(sizeof(char) * (maxWidth + 1));
//    int d = maxWidth - sum, m = right - left - 1;
//    int cnt = m ? d / m : d;
//    int a = 0, b = m;
//    if (m && d % m)
//    {
//        a = d % m;
//        b -= a;
//    }
//    int len = 0;
//    for (int i = left; i < right; i++)
//    {
//        for (int j = 0; words[i][j]; j++)
//        {
//            ans[*n][len++] = words[i][j];
//        }
//        if (m && i == right - 1) continue;
//        int blanks = cnt;
//        if (a)
//        {
//            a--;
//            blanks++;
//        }
//        for (int j = 0; j < blanks; j++)
//        {
//            ans[*n][len++] = ' ';
//        }
//    }
//    ans[*n][len] = '\0';
//    (*n)++;
//}
//char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize)
//{
//    int capacity = 8, sum = 0, left = 0;
//    char** ans = (char**)malloc(sizeof(char*) * capacity);
//    *returnSize = 0;
//    for (int i = 0; i < wordsSize; i++)
//    {
//        int m = strlen(words[i]);
//        if (sum + i - left + m > maxWidth)
//        {
//            manage(ans, words, left, i, sum, maxWidth, returnSize);
//            if ((*returnSize) >= capacity)
//            {
//                capacity *= 2;
//                ans = (char**)realloc(ans, sizeof(char*) * capacity);
//            }
//            sum = 0;
//            left = i;
//        }
//        sum += m;
//    }
//    int len = 0;
//    ans[*returnSize] = (char*)malloc(sizeof(char) * (maxWidth + 1));
//    for (int i = left; i < wordsSize; i++)
//    {
//        for (int j = 0; words[i][j]; j++)
//        {
//            ans[*returnSize][len++] = words[i][j];
//        }
//        if (len < maxWidth)
//            ans[*returnSize][len++] = ' ';
//    }
//    while (len < maxWidth)
//        ans[*returnSize][len++] = ' ';
//    ans[*returnSize][len] = '\0';
//    (*returnSize)++;
//    return ans;
//}
//
