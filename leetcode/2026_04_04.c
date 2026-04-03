////2087. 网格图中机器人回家的最小代价
//
//int minCost(int* startPos, int startPosSize, int* homePos, int homePosSize, int* rowCosts, int rowCostsSize, int* colCosts, int colCostsSize)
//{
//    int x0 = startPos[0], y0 = startPos[1];
//    int x1 = homePos[0], y1 = homePos[1];
//    int left = fmin(x0, x1), up = fmin(y0, y1);
//    int right = x0 + x1 - left, down = y0 + y1 - up;
//    int ans = -rowCosts[x0] - colCosts[y0];
//    for (int i = left; i <= right; i++)
//    {
//        ans += rowCosts[i];
//    }
//    for (int i = up; i <= down; i++)
//    {
//        ans += colCosts[i];
//    }
//    return ans;
//}
//
////3522. 执行指令后的得分    
//
//long long calculateScore(char** instructions, int instructionsSize, int* values, int valuesSize)
//{
//    long long ans = 0;
//    int n = valuesSize;
//    for (int i = 0; i >= 0 && i < n && instructions[i][0]; )
//    {
//        int sym = instructions[i][0];
//        instructions[i][0] = '\0';
//        if (sym == 'j')
//        {
//            i += values[i];
//        }
//        else
//        {
//            ans += values[i++];
//        }
//    }
//    return ans;
//}
//
////3560. 木材运输的最小成本
//
//long long minCuttingCost(int n, int m, int k)
//{
//    long long ans = n > k ? 1ll * (n - k) * k : 0;
//    return m > k ? ans + 1ll * (m - k) * k : ans;
//}
//
////3527. 找到最常见的回答
//
//typedef struct
//{
//    char* key;
//    int idx;
//    UT_hash_handle hh;
//}Count;
//typedef struct
//{
//    char* key;
//    UT_hash_handle hh;
//}Exist;
//char* findCommonResponse(char*** responses, int responsesSize, int* responsesColSize)
//{
//    int n = responsesSize, capacity = 8;
//    int* cnt = (int*)malloc(sizeof(int) * capacity);
//    char** w = (char**)malloc(sizeof(char*) * capacity);
//    int size = 0;
//    Count* words = NULL;
//    Count* p1 = NULL;
//    int max = 0;
//    char* ans = NULL;
//    for (int i = 0; i < n; i++)
//    {
//        Exist* group = NULL;
//        Exist* p2 = NULL;
//        for (int j = 0; j < responsesColSize[i]; j++)
//        {
//            char* key = responses[i][j];
//            HASH_FIND_STR(group, key, p2);
//            if (p2) continue;
//
//            p2 = (Exist*)malloc(sizeof(Exist));
//            p2->key = key;
//            HASH_ADD_STR(group, key, p2);
//
//            HASH_FIND_STR(words, key, p1);
//            if (p1 == NULL)
//            {
//                p1 = (Count*)malloc(sizeof(Count));
//                p1->key = key;
//                p1->idx = size;
//                w[size] = key;
//                cnt[size++] = 0;
//                if (size >= capacity)
//                {
//                    capacity *= 2;
//                    w = (char**)realloc(w, sizeof(char*) * capacity);
//                    cnt = (int*)realloc(cnt, sizeof(int) * capacity);
//                }
//                HASH_ADD_STR(words, key, p1);
//            }
//            int k = p1->idx;
//            cnt[k]++;
//
//            if (max < cnt[k] || (max == cnt[k] && strcmp(w[k], ans) < 0))
//            {
//                max = cnt[k];
//                ans = w[k];
//            }
//        }
//        Exist* tmp = NULL;
//        HASH_ITER(hh, group, p2, tmp)
//        {
//            HASH_DEL(group, p2);
//            free(p2);
//        }
//    }
//    Count* tmp = NULL;
//    HASH_ITER(hh, words, p1, tmp)
//    {
//        HASH_DEL(words, p1);
//        free(p1);
//    }
//    free(cnt);
//    free(w);
//    return ans;
//}
//
