////2274. 不含特殊楼层的最大连续楼层数
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int maxConsecutive(int bottom, int top, int* special, int specialSize)
//{
//    qsort(special, specialSize, sizeof(int), cmp);
//    int ans = special[0] - bottom;
//    for (int i = 1; i < specialSize; i++)
//    {
//        int d = special[i] - special[i - 1] - 1;
//        if (d > ans)
//            ans = d;
//    }
//    int last = top - special[specialSize - 1];
//    if (last > ans)
//        ans = last;
//    return ans;
//}
//
////2284. 最多单词数的发件人    
//
//typedef struct
//{
//    char* key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//char* largestWordCount(char** messages, int messagesSize, char** senders, int sendersSize)
//{
//    HashItem* identity = NULL;
//    HashItem* p = NULL;
//    char* ans = NULL;
//    int cnt = 0, n = messagesSize;
//    for (int i = 0; i < n; i++)
//    {
//        int count = 1;
//        for (int j = 0; messages[i][j]; j++)
//        {
//            if (messages[i][j] == ' ')
//                count++;
//        }
//        HASH_FIND_STR(identity, senders[i], p);
//        if (p == NULL)
//        {
//            p = (HashItem*)malloc(sizeof(HashItem));
//            p->key = senders[i];
//            p->val = 0;
//            HASH_ADD_STR(identity, key, p);
//        }
//        p->val += count;
//        if (p->val > cnt || (p->val == cnt && strcmp(senders[i], ans) > 0))
//        {
//            ans = senders[i];
//            cnt = p->val;
//        }
//    }
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, identity, p, tmp)
//    {
//        HASH_DEL(identity, p);
//        free(p);
//    }
//    return ans;
//}
//
////2288. 价格减免
//
//bool exchange(char* s, char* ans, int* pos, int discount)
//{
//    double x = 0;
//    if (s[1] < '0' || s[1] > '9')
//        return false;
//    for (int i = 1; s[i] && s[i] != ' '; i++)
//    {
//        if (s[i] < '0' || s[i] > '9')
//            return false;
//        x *= 10;
//        x += s[i] - '0';
//    }
//    x *= (100.0 - discount) / 100.0;
//    sprintf(ans + (*pos), "%.2lf", x);
//    while (ans[(*pos)])
//        (*pos)++;
//    return true;
//}
//char* discountPrices(char* sentence, int discount)
//{
//    int n = strlen(sentence);
//    char* ans = (char*)calloc(sizeof(char), 3 * n);
//    int pos = 0;
//    for (char* s = strtok(sentence, " "); s; s = strtok(NULL, " "))
//    {
//        ans[pos++] = s[0];
//        int m = strlen(s);
//        bool flag = false;
//        if (s[0] == '$')
//            flag = exchange(s, ans, &pos, discount);
//        if (!flag)
//        {
//            strcpy(ans + pos, s + 1);
//            pos += m - 1;
//        }
//        ans[pos++] = ' ';
//    }
//    ans[--pos] = '\0';
//    return ans;
//}
//
////2352. 相等行列对
//
//int equalPairs(int** grid, int gridSize, int* gridColSize)
//{
//    int n = gridColSize[0];
//    int ans = 0;
//    int col[n];
//    // 行与列比
//    // 固定列
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//            col[j] = grid[j][i];
//        // 固定行
//        for (int j = 0; j < n; j++)
//        {
//            // 遍历，将固定列的元素与固定行的元素比较
//            ans += (memcmp(col, grid[j], sizeof(int) * n) == 0);
//        }
//    }
//    return ans;
//}
//
//typedef struct
//{
//    int* key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int equalPairs(int** grid, int gridSize, int* gridColSize)
//{
//    int n = gridSize, ans = 0;
//    int* col = (int*)malloc(sizeof(int) * n);
//    int* row = (int*)malloc(sizeof(int) * n);
//    HashItem* cntC = NULL, * cntR = NULL;
//    HashItem* p1 = NULL, * p2 = NULL;
//    // 行与列比
//    // 固定列
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            col[j] = grid[j][i];
//            row[j] = grid[i][j];
//        }
//        HASH_FIND(hh, cntC, col, sizeof(int*), p1);
//        if (p1 == NULL)
//        {
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = (int*)malloc(sizeof(int) * n);
//            memcpy(p1->key, col, sizeof(int) * n);
//            p1->val = 0;
//            HASH_ADD(hh, cntC, key, sizeof(int*), p1);
//        }
//        p1->val++;
//
//        HASH_FIND(hh, cntR, row, sizeof(int*), p2);
//        if (p2 == NULL)
//        {
//            p2 = (HashItem*)malloc(sizeof(HashItem));
//            p2->key = (int*)malloc(sizeof(int) * n);
//            memcpy(p2->key, row, sizeof(int) * n);
//            p2->val = 0;
//            HASH_ADD(hh, cntR, key, sizeof(int*), p2);
//        }
//        p2->val++;
//    }
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, cntC, p1, tmp)
//    {
//        HashItem* t = NULL;
//        HASH_ITER(hh, cntR, p2, t)
//        {
//            ans += (memcmp(p1->key, p2->key, sizeof(int) * n) == 0) * p1->val;
//        }
//        HASH_DEL(cntC, p1);
//        free(p1->key);
//        free(p1);
//    }
//    HASH_ITER(hh, cntR, p2, tmp)
//    {
//        HASH_DEL(cntR, p2);
//        free(p2->key);
//        free(p2);
//    }
//    free(col);
//    free(row);
//    return ans;
//}
//
