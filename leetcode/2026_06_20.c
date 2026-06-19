//// 3387. 两天自由外汇交易后的最大货币数
//
//typedef struct
//{
//    char* key;
//    double val;
//    UT_hash_handle hh;
//}Amount;
//typedef struct
//{
//    char* key;
//    char* to;
//    double rate;
//    UT_hash_handle hh;
//}HashItem;
//void HashAdd(HashItem** grid, char* key, char* to, double rate)
//{
//    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
//    pEntry->key = key;
//    pEntry->to = to;
//    pEntry->rate = rate;
//    HASH_ADD_STR(*grid, key, pEntry);
//}
//Amount* calcAmount(char* initialCurrency, char*** pairs, int pairsSize, int* pairsColSize, double* rates, int ratesSize)
//{
//    HashItem* grid = NULL;
//    for (int i = 0; i < pairsSize; i++)
//    {
//        char* p1 = pairs[i][0];
//        char* p2 = pairs[i][1];
//        double r = rates[i];
//        HashAdd(&grid, p1, p2, r);
//        HashAdd(&grid, p2, p1, 1.0 / r);
//    }
//
//    Amount* cur = NULL;
//    void dfs(char* x, double curAmount)
//    {
//        Amount* found = NULL;
//        HASH_FIND_STR(cur, x, found);
//        if (found) return;
//
//        Amount* tmp = (Amount*)malloc(sizeof(Amount));
//        tmp->key = x;
//        tmp->val = curAmount;
//        HASH_ADD_STR(cur, key, tmp);
//
//        HashItem* pEntry = NULL;
//        HashItem* temp = NULL;
//        HASH_ITER(hh, grid, pEntry, temp)
//        {
//            if (strcmp(pEntry->key, x) == 0)
//            {
//                Amount* t = NULL;
//                HASH_FIND_STR(cur, pEntry->to, t);
//                if (!t)
//                    dfs(pEntry->to, curAmount * pEntry->rate);
//            }
//        }
//    }
//
//    dfs(initialCurrency, 1.0);
//    return cur;
//}
//double maxAmount(char* initialCurrency, char*** pairs1, int pairs1Size, int* pairs1ColSize, double* rates1, int rates1Size, char*** pairs2, int pairs2Size, int* pairs2ColSize, double* rates2, int rates2Size)
//{
//    Amount* day1_amount = calcAmount(initialCurrency, pairs1, pairs1Size, rates1, rates1Size);
//    Amount* day2_amount = calcAmount(initialCurrency, pairs2, pairs2Size, rates2, rates2Size);
//    double ans = 0;
//    Amount* p = NULL, * tmp = NULL;
//    HASH_ITER(hh, day2_amount, p, tmp)
//    {
//        Amount* p2 = NULL;
//        HASH_FIND_STR(day1_amount, p->key, p2);
//        if (p2)
//            ans = fmax(ans, p2->val / p->val);
//
//        HASH_DEL(day2_amount, p);
//        free(p);
//    }
//    HASH_ITER(hh, day1_amount, p, tmp)
//    {
//        HASH_DEL(day1_amount, p);
//        free(p);
//    }
//    return ans;
//}
//
