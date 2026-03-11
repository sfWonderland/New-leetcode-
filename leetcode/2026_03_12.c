////1324. 竖直打印单词
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** printVertically(char* s, int* returnSize)
//{
//    int n = strlen(s);
//    char* words[n];
//    int words_len[n];
//    int len = 0, max = 0;
//    for (int i = 0; i < n; )
//    {
//        int j = i;
//        while (s[j] && s[j] != ' ')
//            j++;
//        words[len] = s + i;
//        words_len[len++] = j - i;
//        s[j] = '\0';
//        max = fmax(j - i, max);
//        i = j + 1;
//    }
//    char** ans = (char**)malloc(sizeof(char*) * max);
//    for (int i = 0; i < max; i++)
//    {
//        ans[i] = (char*)malloc(sizeof(char) * (len + 1));
//        for (int j = 0; j < len; j++)
//        {
//            int m = words_len[j];
//            ans[i][j] = i < m ? words[j][i] : ' ';
//        }
//        int k = len - 1;
//        while (ans[i][k] == ' ')
//            k--;
//        ans[i][k + 1] = '\0';
//    }
//    *returnSize = max;
//    return ans;
//}
//
////1387. 将整数按权重排序    
//
//int* nums;
//int cmp(const void* e1, const void* e2)
//{
//    return nums[*(int*)e1] == nums[*(int*)e2] ? *(int*)e1 - *(int*)e2 : nums[*(int*)e1] - nums[*(int*)e2];
//}
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int getKth(int lo, int hi, int k)
//{
//    int n = hi - lo + 1;
//    HashItem* memo = NULL;
//    int dfs(int i)
//    {
//        if (i == 1)
//            return 0;
//
//        HashItem* p1 = NULL;
//        HASH_FIND_INT(memo, &i, p1);
//        if (p1)
//            return p1->val;
//        int res = 0;
//        res = i & 1 ? dfs((3 * i + 1) / 2) + 2 : dfs(i / 2) + 1;
//        p1 = (HashItem*)malloc(sizeof(HashItem));
//        p1->key = i;
//        p1->val = res;
//        HASH_ADD_INT(memo, key, p1);
//        return res;
//    }
//    nums = (int*)malloc(sizeof(int) * n);
//    int idx[n];
//    for (int i = 0; i < n; i++)
//    {
//        nums[i] = dfs(i + lo);
//        idx[i] = i;
//    }
//    qsort(idx, n, sizeof(int), cmp);
//    free(nums);
//    HashItem* p = NULL, * tmp = NULL;
//    HASH_ITER(hh, memo, p, tmp)
//    {
//        HASH_DEL(memo, p);
//        free(p);
//    }
//    return idx[k - 1] + lo;
//}
//
////1410. HTML 实体解析器
//
//char* special[6] = { "&quot;", "&apos;", "&amp;", "&gt;", "&lt;", "&frasl;" };
//char symbol[6] = { '\"', '\'', '&', '>', '<', '/' };
//char pair(char* s, int* left)
//{
//    for (int i = 0; i < 6; i++)
//    {
//        int j = 0;
//        for (; special[i][j] && special[i][j] == s[j + (*left)]; j++)
//            ;
//        if (special[i][j] == '\0')
//        {
//            *left += j - 1;
//            return symbol[i];
//        }
//    }
//    return '&';
//}
//char* entityParser(char* text)
//{
//    int idx = 0;
//    for (int i = 0; text[i]; i++)
//    {
//        if (text[i] == '&')
//        {
//            int c = pair(text, &i);
//            text[idx++] = c;
//        }
//        else
//            text[idx++] = text[i];
//    }
//    text[idx] = '\0';
//    return text;
//}
//
////1451. 重新排列句子中的单词
//
//int* words_len;
//int cmp(const void* e1, const void* e2)
//{
//    return words_len[*(int*)e1] == words_len[*(int*)e2] ? *(int*)e1 - *(int*)e2 : words_len[*(int*)e1] - words_len[*(int*)e2];
//}
//char* arrangeWords(char* text)
//{
//    text[0] |= 32;
//    int n = strlen(text), capacity = 8;
//    char** words = (char**)malloc(sizeof(char*) * capacity);
//    words_len = (int*)malloc(sizeof(int) * capacity);
//    int* idx = (int*)malloc(sizeof(int) * capacity);
//    int len = 0;
//    for (int i = 0; i < n; )
//    {
//        int j = i;
//        while (text[j] && text[j] != ' ')
//            j++;
//        words[len] = text + i;
//        idx[len] = len;
//        words_len[len++] = j - i;
//        if (len >= capacity)
//        {
//            capacity *= 2;
//            words = (char**)realloc(words, sizeof(char*) * capacity);
//            words_len = (int*)realloc(words_len, sizeof(int) * capacity);
//            idx = (int*)realloc(idx, sizeof(int) * capacity);
//        }
//        text[j] = '\0';
//        i = j + 1;
//    }
//    qsort(idx, len, sizeof(int), cmp);
//    char* ans = (char*)malloc(sizeof(char) * (n + 1));
//    int ansSize = 0;
//    for (int i = 0; i < len; i++)
//    {
//        int j = idx[i];
//        for (int k = 0; words[j][k]; k++)
//        {
//            ans[ansSize++] = words[j][k];
//        }
//        ans[ansSize++] = ' ';
//    }
//    ans[0] -= 32;
//    ans[n] = '\0';
//    free(words);
//    free(words_len);
//    free(idx);
//    return ans;
//}
//
