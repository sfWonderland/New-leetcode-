////2840. 判断通过操作能否让字符串相等 II
//
//bool checkStrings(char* s1, char* s2)
//{
//    int n = strlen(s1);
//    int cnt[2][26];
//    memset(cnt[0], 0, sizeof(int) * 26);
//    memset(cnt[1], 0, sizeof(int) * 26);
//    for (int i = 0; i < n; i++)
//    {
//        cnt[i % 2][s1[i] - 'a']++;
//        cnt[i % 2][s2[i] - 'a']--;
//    }
//    for (int i = 0; i < 26; i++)
//    {
//        if (cnt[0][i] || cnt[1][i])
//            return false;
//    }
//    return true;
//}
//
////3175. 找到连续赢 K 场比赛的第一位玩家    
//
//int findWinningPlayer(int* skills, int skillsSize, int k)
//{
//    int win = 0, ans = 0;
//    for (int i = 1; i < skillsSize; i++)
//    {
//        if (skills[i] < skills[ans])
//            win++;
//        else
//        {
//            win = 1;
//            ans = i;
//        }
//
//        if (win == k)
//            break;
//    }
//    return ans;
//}
//
////846. 一手顺子
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//
//void up(int* heap, int i)
//{
//    int x = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j] <= x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//        if (j == 0)
//            break;
//    }
//    heap[i] = x;
//}
//
//void down(int* heap, int n, int i)
//{
//    int x = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1] < heap[j])
//            j++;
//
//        if (heap[j] >= x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//
//bool isNStraightHand(int* hand, int handSize, int groupSize)
//{
//    HashItem* cnt = NULL;
//    HashItem* pEntry = NULL;
//    int* heap = (int*)malloc(sizeof(int) * handSize);
//    int heapSize = 0;
//    for (int i = 0; i < handSize; i++)
//    {
//        HASH_FIND_INT(cnt, &hand[i], pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = hand[i];
//            pEntry->val = 0;
//            HASH_ADD_INT(cnt, key, pEntry);
//
//            heap[heapSize++] = hand[i];
//            up(heap, heapSize - 1);
//        }
//        pEntry->val++;
//    }
//    // for(int i = 0; i < heapSize; i++)
//    // {
//    //     printf("%d ", heap[i]);
//    // }
//    // printf("\n");
//    while (heapSize > 0)
//    {
//        while (1)
//        {
//            HASH_FIND_INT(cnt, &heap[0], pEntry);
//            if (pEntry->val)
//                break;
//            heap[0] = heap[--heapSize];
//            if (heapSize == 0)
//                break;
//            down(heap, heapSize, 0);
//        }
//
//        if (heapSize == 0)
//            break;
//
//        for (int i = heap[0]; i < heap[0] + groupSize; i++)
//        {
//            HASH_FIND_INT(cnt, &i, pEntry);
//            if (pEntry && pEntry->val)
//                pEntry->val--;
//            else
//                return false;
//        }
//    }
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, cnt, pEntry, tmp)
//    {
//        HASH_DEL(cnt, pEntry);
//        free(pEntry);
//    }
//    free(heap);
//    return true;
//}
//
////2191. 将杂乱无章的数字排序
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    long long ans = *(long long*)e1 - *(long long*)e2;
//    if (ans == 0)
//        return 0;
//
//    return ans > 0 ? 1 : -1;
//}
//int* sortJumbled(int* mapping, int mappingSize, int* nums, int numsSize, int* returnSize)
//{
//    long long* arr = (long long*)malloc(sizeof(long long) * numsSize);
//    for (int i = 0; i < numsSize; i++)
//    {
//        arr[i] = i;
//        long long base = 100000, num = nums[i];
//        if (!num)
//            arr[i] += base * mapping[num % 10];
//        while (num)
//        {
//            arr[i] += base * mapping[num % 10];
//            num /= 10;
//            base *= 10;
//        }
//    }
//    qsort(arr, numsSize, sizeof(long long), cmp);
//    int* ans = (int*)malloc(sizeof(int) * numsSize);
//    for (int i = 0; i < numsSize; i++)
//    {
//        //printf("%lld ", arr[i]);
//        ans[i] = nums[arr[i] % 100000];
//    }
//    *returnSize = numsSize;
//    return ans;
//}
//
