////950. 按递增顺序显示卡牌
//
////逆约瑟夫环，占一个坑位，跳一个坑位
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize)
//{
//    int n = deckSize;
//    qsort(deck, n, sizeof(int), cmp);
//    int* ans = (int*)malloc(sizeof(int) * n);
//    bool* vis = (bool*)calloc(sizeof(bool), n);
//    int i = 0, k = 0;
//    int next(int x)
//    {
//        for (int i = x; i < n; i++)
//        {
//            if (vis[i] == 0)
//                return i;
//        }
//        for (int i = 0; i < x; i++)
//        {
//            if (vis[i] == 0)
//                return i;
//        }
//        return -1;
//    }
//    while (1)
//    {
//        ans[i] = deck[k++];
//        vis[i] = 1;
//
//        i = next(next(i + 1) + 1);
//        if (i == -1)
//            break;
//    }
//    *returnSize = n;
//    return ans;
//}
//
////3433. 统计用户被提及情况
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    int timestamp;
//    int type;
//    int id;
//}Event;
//int cmp(const void* e1, const void* e2)
//{
//    Event* a = (Event*)e1;
//    Event* b = (Event*)e2;
//    return a->timestamp == b->timestamp ? a->type - b->type : a->timestamp - b->timestamp;
//}
//int* countMentions(int numberOfUsers, char*** events, int eventsSize, int* eventsColSize, int* returnSize)
//{
//    int n = numberOfUsers;
//    int* ans = (int*)calloc(sizeof(int), n);
//    Event* es = (Event*)malloc(sizeof(Event) * eventsSize * 2);
//    int es_size = 0;
//    int all = 0;
//
//    for (int k = 0; k < eventsSize; k++)
//    {
//        char** e = events[k];
//        int cur_t = atoi(e[1]);
//        char* mention = e[2];
//
//        if (e[0][0] == 'O')
//        {
//            int i = atoi(mention);
//            es[es_size++] = (Event){ cur_t, 1, i };
//            es[es_size++] = (Event){ cur_t + 60, -1, i };
//        }
//        else if (mention[0] == 'A')
//            all++;
//        else if (mention[0] == 'H')
//        {
//            all++;
//            es[es_size++] = (Event){ cur_t, 2, -1 };
//        }
//        else
//        {
//            for (char* tok = strtok(mention, " "); tok; tok = strtok(NULL, " "))
//            {
//                ans[atoi(tok + 2)]++;
//            }
//        }
//    }
//
//    qsort(es, es_size, sizeof(Event), cmp);
//    int here = 0;
//    for (int k = 0; k < es_size; k++)
//    {
//        Event e = es[k];
//        if (e.type == 2)
//            here++;
//        else
//        {
//            int i = e.id;
//            ans[i] += e.type * here;
//        }
//    }
//    for (int i = 0; i < n; i++)
//    {
//        ans[i] += all;
//    }
//
//    *returnSize = n;
//    return ans;
//}
//
////LCR 081. 组合总和
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
//{
//    int n = candidatesSize;
//    int** ans = (int**)malloc(sizeof(int*) * 150);
//    *returnSize = 0;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * 150);
//    int* path = (int*)malloc(sizeof(int) * 500);
//    int pathSize = 0;
//    int sum = target;
//    void dfs(int i)
//    {
//        if (sum < 0)
//            return;
//        else if (sum == 0)
//        {
//            ans[*returnSize] = (int*)malloc(sizeof(int) * pathSize);
//            for (int j = 0; j < pathSize; j++)
//            {
//                ans[*returnSize][j] = path[j];
//            }
//            (*returnColumnSizes)[(*returnSize)++] = pathSize;
//        }
//        else
//        {
//            for (int j = i; j >= 0; j--)
//            {
//                path[pathSize++] = candidates[j];
//                sum -= candidates[j];
//                dfs(j);
//                sum += candidates[j];
//                pathSize--;
//            }
//        }
//    }
//    dfs(n - 1);
//    return ans;
//}
//
////1817. 查找用户活跃分钟数
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    int key;
//    UT_hash_handle hh;
//}HashSetItem;
//typedef struct
//{
//    int key;
//    HashSetItem* val;
//    UT_hash_handle hh;
//}HashMapItem;
//int* findingUsersActiveMinutes(int** logs, int logsSize, int* logsColSize, int k, int* returnSize)
//{
//    HashMapItem* map = NULL;
//    HashMapItem* pMapEntry = NULL;
//    for (int i = 0; i < logsSize; i++)
//    {
//        int id = logs[i][0], time = logs[i][1];
//        HASH_FIND_INT(map, &id, pMapEntry);
//        if (pMapEntry == NULL)
//        {
//            pMapEntry = (HashMapItem*)malloc(sizeof(HashMapItem));
//            pMapEntry->key = id;
//            pMapEntry->val = NULL;
//            HASH_ADD_INT(map, key, pMapEntry);
//        }
//        HashSetItem* pSetEntry = NULL;
//        HASH_FIND_INT(pMapEntry->val, &time, pSetEntry);
//        if (pSetEntry == NULL)
//        {
//            pSetEntry = (HashSetItem*)malloc(sizeof(HashSetItem));
//            pSetEntry->key = time;
//            HASH_ADD_INT(pMapEntry->val, key, pSetEntry);
//        }
//    }
//    int* ans = (int*)calloc(sizeof(int), k);
//    HashMapItem* tmp = NULL;
//    HASH_ITER(hh, map, pMapEntry, tmp)
//    {
//        int cnt = HASH_COUNT(pMapEntry->val);
//        ans[cnt - 1]++;
//        free(pMapEntry);
//    }
//    *returnSize = k;
//    return ans;
//}
//
