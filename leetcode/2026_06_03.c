//// 131. ·Ö¸î»ØÎÄ´®
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//char*** subPalindromes;
//int subPalindromesSize;
//int* Tlen;
//
//char** subStrings;
//int subStringsSize;
//int* len;
//
//int n;
//int idx;
//
//bool isPalindrome(char* s, int left, int right)
//{
//    while (left < right)
//    {
//        if (s[left++] != s[right--])
//            return false;
//    }
//    return true;
//}
//
//void dfs(char* s, int i, int start)
//{
//    if (n == i)
//    {
//        subPalindromes[subPalindromesSize] = (char**)malloc(sizeof(char*) * subStringsSize);
//        for (int j = 0; j < subStringsSize; j++)
//        {
//            subPalindromes[subPalindromesSize][j] = (char*)malloc(sizeof(char) * (len[j] + 1));
//            strcpy(subPalindromes[subPalindromesSize][j], subStrings[j]);
//        }
//        Tlen[subPalindromesSize++] = subStringsSize;
//        return;
//    }
//
//    if (n - 1 > i)
//        dfs(s, i + 1, start);
//
//    if (isPalindrome(s, start, i))
//    {
//        subStrings[subStringsSize] = (char*)malloc(sizeof(char) * (i - start + 2));
//        strncpy(subStrings[subStringsSize], s + start, i - start + 1);
//        subStrings[subStringsSize][i - start + 1] = '\0';
//        len[subStringsSize++] = i - start + 1;
//        dfs(s, i + 1, i + 1);
//        free(subStrings[--subStringsSize]);
//    }
//}
//
//char*** partition(char* s, int* returnSize, int** returnColumnSizes)
//{
//    n = strlen(s);
//    int sum = 1 << (n - 1);
//    subPalindromes = (char***)malloc(sizeof(char**) * sum);
//    subStrings = (char**)malloc(sizeof(char*) * n);
//
//    Tlen = (int*)malloc(sizeof(int) * sum);
//    len = (int*)malloc(sizeof(int) * n);
//
//    subPalindromesSize = 0;
//    subStringsSize = 0;
//    idx = 0;
//
//    dfs(s, 0, 0);
//
//    *returnSize = subPalindromesSize;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * subPalindromesSize);
//    for (int i = 0; i < subPalindromesSize; i++)
//    {
//        (*returnColumnSizes)[i] = Tlen[i];
//    }
//    return subPalindromes;
//}
//
