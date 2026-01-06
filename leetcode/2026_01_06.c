////2241. 设计一个 ATM 机器
//
//typedef struct
//{
//    int* deno;
//    int* notes;
//} ATM;
//
//
//ATM* aTMCreate()
//{
//    ATM* obj = (ATM*)malloc(sizeof(ATM));
//    obj->deno = (int*)malloc(sizeof(int) * 5);
//    obj->deno[0] = 20; obj->deno[1] = 50;
//    obj->deno[2] = 100; obj->deno[3] = 200;
//    obj->deno[4] = 500;
//    obj->notes = (int*)calloc(sizeof(int), 5);
//    return obj;
//}
//
//void aTMDeposit(ATM* obj, int* banknotesCount, int banknotesCountSize)
//{
//    for (int i = 0; i < banknotesCountSize; i++)
//    {
//        obj->notes[i] += banknotesCount[i];
//    }
//}
//
//int* aTMWithdraw(ATM* obj, int amount, int* retSize)
//{
//    *retSize = 1;
//    int* ret = (int*)calloc(sizeof(int), 5);
//    for (int i = 4; i >= 0; i--)
//    {
//        if (obj->notes[i] && amount >= obj->deno[i])
//        {
//            ret[i] = fmin(amount / obj->deno[i], obj->notes[i]);
//            amount -= ret[i] * obj->deno[i];
//        }
//    }
//    if (amount > 0)
//    {
//        ret[0] = -1;
//        return ret;
//    }
//    else
//    {
//        for (int i = 0; i < 5; i++)
//        {
//            obj->notes[i] -= ret[i];
//        }
//    }
//    *retSize = 5;
//    return ret;
//}
//
//void aTMFree(ATM* obj)
//{
//    free(obj->deno);
//    free(obj->notes);
//    free(obj);
//}
//
///**
// * Your ATM struct will be instantiated and called as such:
// * ATM* obj = aTMCreate();
// * aTMDeposit(obj, banknotesCount, banknotesCountSize);
//
// * int* param_2 = aTMWithdraw(obj, amount, retSize);
//
// * aTMFree(obj);
//*/
//
////2232. 向表达式添加括号后的最小结果    
//
//char* minimizeResult(char* expression)
//{
//    char* s1 = strtok(expression, "+");
//    char* s2 = strtok(NULL, "+");
//    int m = strlen(s1), n = strlen(s2);
//    int min = INT_MAX, left = 0, right = 0;
//    for (int i = 0; i < m; i++)
//    {
//        char tmp1 = s1[i];
//        s1[i] = '\0';
//        int mul1 = fmax(1, atoi(s1));
//        s1[i] = tmp1;
//        int plus1 = atoi(s1 + i);
//        //printf("%d %d\n", mul1, plus1);
//        for (int j = 1; j <= n; j++)
//        {
//            char tmp2 = s2[j];
//            s2[j] = '\0';
//            int plus2 = atoi(s2);
//            s2[j] = tmp2;
//            int mul2 = fmax(1, atoi(s2 + j));
//            //printf("%d %d |", plus2, mul2);
//            int sum = mul1 * mul2 * (plus1 + plus2);
//            if (min > sum)
//            {
//                min = sum;
//                left = i;
//                right = j;
//            }
//            //printf("%d %d %d\n", i, j, min);
//        }
//        //printf("\n");
//    }
//    char* ans = (char*)malloc(sizeof(char) * (m + n + 4));
//    int idx = 0;
//    for (int i = 0; i < m; i++)
//    {
//        if (i == left)
//            ans[idx++] = '(';
//        ans[idx++] = s1[i];
//    }
//    ans[idx++] = '+';
//    for (int i = 0; i < n; i++)
//    {
//        if (i == right)
//            ans[idx++] = ')';
//        ans[idx++] = s2[i];
//    }
//    if (n == right)
//        ans[idx++] = ')';
//    ans[idx] = '\0';
//    return ans;
//}
//
////2766. 重新放置石块
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    int key;
//    UT_hash_handle hh;
//}HashItem;
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int* relocateMarbles(int* nums, int numsSize, int* moveFrom, int moveFromSize, int* moveTo, int moveToSize, int* returnSize)
//{
//    HashItem* cnt = NULL;
//    HashItem* pEntry = NULL;
//    int sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        HASH_FIND_INT(cnt, &nums[i], pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = nums[i];
//            HASH_ADD_INT(cnt, key, pEntry);
//            sum++;
//        }
//    }
//    int n = moveFromSize;
//    for (int i = 0; i < n; i++)
//    {
//        HASH_FIND_INT(cnt, &moveFrom[i], pEntry);
//        HASH_DEL(cnt, pEntry);
//        HASH_FIND_INT(cnt, &moveTo[i], pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = moveTo[i];
//            HASH_ADD_INT(cnt, key, pEntry);
//        }
//    }
//    int* ans = (int*)malloc(sizeof(int) * sum);
//    int idx = 0;
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, cnt, pEntry, tmp)
//    {
//        ans[idx++] = pEntry->key;
//        free(pEntry);
//    }
//    qsort(ans, idx, sizeof(int), cmp);
//    *returnSize = idx;
//    return ans;
//}
//
////3080. 执行操作标记数组中的元素
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* arr;
//int cmp(const void* e1, const void* e2)
//{
//    return arr[*(int*)e1] == arr[*(int*)e2] ? *(int*)e1 - *(int*)e2 : arr[*(int*)e1] - arr[*(int*)e2];
//}
//long long* unmarkedSumArray(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
//{
//    int* idx = (int*)malloc(sizeof(int) * numsSize);
//    long long sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        idx[i] = i;
//        sum += nums[i];
//    }
//    arr = nums;
//    qsort(idx, numsSize, sizeof(int), cmp);
//    long long* ans = (long long*)malloc(sizeof(long long) * queriesSize);
//    int ansSize = 0, k = 0; // the index of the minium element
//    for (int i = 0; i < queriesSize; i++)
//    {
//        if (k == numsSize)
//        {
//            ans[i] = 0;
//            continue;
//        }
//        sum -= nums[queries[i][0]];
//        nums[queries[i][0]] = 0;
//        while (k < numsSize && queries[i][1])
//        {
//            if (nums[idx[k]] == 0)
//            {
//                k++;
//                continue;
//            }
//            sum -= nums[idx[k]];
//            nums[idx[k++]] = 0;
//            queries[i][1]--;
//        }
//        ans[i] = sum;
//    }
//    *returnSize = queriesSize;
//    return ans;
//}
//
////2365. 任务调度器 II
//
//typedef struct
//{
//    int key;
//    long long val;
//    UT_hash_handle hh;
//}HashItem;
//long long taskSchedulerII(int* tasks, int tasksSize, int space)
//{
//    HashItem* completed = NULL;
//    HashItem* pEntry = NULL;
//    long long sum = 0;
//    for (int i = 0; i < tasksSize; i++)
//    {
//        HASH_FIND_INT(completed, &tasks[i], pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = tasks[i];
//            HASH_ADD_INT(completed, key, pEntry);
//        }
//        else
//        {
//            if (sum < space + pEntry->val)
//                sum = space + pEntry->val;
//        }
//        pEntry->val = ++sum;
//        //printf("%d ", sum);
//    }
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, completed, pEntry, tmp)
//    {
//        free(pEntry);
//    }
//    return sum;
//}
//
