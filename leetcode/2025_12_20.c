////1078. Bigram 分词
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** findOcurrences(char* text, char* first, char* second, int* returnSize)
//{
//    int reset = 0;
//    if (strcmp(first, second) == 0)
//        reset++;
//    char** ans = (char**)malloc(sizeof(char*) * 200);
//    *returnSize = 0;
//    int k = 0;
//    for (char* s = strtok(text, " "); s; s = strtok(NULL, " "))
//    {
//        if (k == 2)
//        {
//            int n = strlen(s);
//            ans[(*returnSize)] = (char*)malloc(sizeof(char) * (n + 1));
//            strcpy(ans[(*returnSize)], s);
//            (*returnSize)++;
//            k = reset;
//        }
//        if (k == 1)
//            k += strcmp(s, second) == 0 ? 1 : -1;
//        if (k == 0)
//            k += (strcmp(s, first) == 0);
//    }
//    return ans;
//}
//
////1694. 重新格式化电话号码
//
//char* reformatNumber(char* number)
//{
//    int n = strlen(number);
//    char* ans = (char*)malloc(sizeof(char) * ((n + 2) / 3 * 4 + 1));
//    int d = 0, k = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (k % 4 == 3)
//        {
//            ans[k++] = '-';
//        }
//        if (number[i] == ' ' || number[i] == '-')
//            continue;
//
//        ans[k++] = number[i];
//    }
//    if (ans[k - 1] == '-')
//        k--;
//    if (k > 1 && k % 4 == 1)
//    {
//        char tmp = ans[k - 3];
//        ans[k - 3] = '-';
//        ans[k - 2] = tmp;
//    }
//    ans[k] = '\0';
//    return ans;
//}
//
////1668. 最大重复子字符串
//
//int maxRepeating(char* sequence, char* word)
//{
//    int m = strlen(word), n = strlen(sequence);
//    int ans = 0;
//    for (int i = 0; i <= n - m; i++)
//    {
//        int k = 0;
//        for (int j = i; j < n;)
//        {
//            if (strncmp(sequence + j, word, m) == 0)
//            {
//                k++;
//                ans = fmax(ans, k);
//                j += m;
//            }
//            else
//            {
//                k = 0;
//                j++;
//            }
//        }
//    }
//    return ans;
//}
//
////1566. 重复至少 K 次且长度为 M 的模式
//
//bool containsPattern(int* arr, int arrSize, int m, int k)
//{
//    for (int i = 0; i <= arrSize - m * k; i++)
//    {
//        int offset = 0;
//        for (; offset < m * k; offset++)
//        {
//            if (arr[i + offset] != arr[i + offset % m])
//                break;
//        }
//        if (offset == m * k)
//            return true;
//    }
//    return false;
//}
//
