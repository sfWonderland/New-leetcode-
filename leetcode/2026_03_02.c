////1536. 排布二进制网格的最少交换次数
//
//int minSwaps(int** grid, int gridSize, int* gridColSize)
//{
//    int n = gridSize;
//    int tailZeros[n];
//    for (int i = 0; i < n; i++)
//    {
//        tailZeros[i] = n;
//        for (int j = n - 1; j >= 0; j--)
//        {
//            if (grid[i][j])
//            {
//                tailZeros[i] = n - 1 - j;
//                break;
//            }
//        }
//    }
//
//    int ans = 0;
//    for (int i = 0; i < n - 1; i++)
//    {
//        int j = i;
//        while (j < n && tailZeros[j] < n - 1 - i)
//            j++;
//
//        if (j == n) return -1;
//
//        ans += j - i;
//        for (int k = j - 1; k >= i; k--)
//        {
//            tailZeros[k + 1] = tailZeros[k];
//        }
//    }
//    return ans;
//}
//
////421. 数组中两个数的最大异或值    
//
//typedef struct
//{
//    int key;
//    UT_hash_handle hh;
//}HashItem;
//int findMaximumXOR(int* nums, int numsSize)
//{
//    int high_bit = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i])
//            high_bit = fmax(high_bit, 31 - __builtin_clz(nums[i]));
//    }
//    int ans = 0, mask = 0;
//    HashItem* seen = NULL;
//    for (int i = high_bit; i >= 0; i--)
//    {
//        mask |= 1 << i;
//        int new_ans = ans | (1 << i);
//        for (int j = 0; j < numsSize; j++)
//        {
//            int x = nums[j] & mask;
//            int key = x ^ new_ans;
//            HashItem* p1 = NULL;
//            HASH_FIND_INT(seen, &key, p1);
//            if (p1)
//            {
//                ans = new_ans;
//                break;
//            }
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = x;
//            HASH_ADD_INT(seen, key, p1);
//        }
//        HashItem* p = NULL, * tmp = NULL;
//        HASH_ITER(hh, seen, p, tmp)
//        {
//            HASH_DEL(seen, p);
//            free(p);
//        }
//    }
//    return ans;
//}
//
////2074. 反转偶数长度组的节点
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* reverse(struct ListNode* node, struct ListNode* pre)
//{
//    struct ListNode* cur = node;
//    while (cur)
//    {
//        struct ListNode* next = cur->next;
//        cur->next = pre;
//        pre = cur;
//        cur = next;
//    }
//    return pre;
//}
//struct ListNode* reverseEvenLengthGroups(struct ListNode* head)
//{
//    struct ListNode* left = head;
//    int cnt = 0, size = 1;
//    for (struct ListNode* node = head; node != NULL; node = node->next)
//    {
//        cnt++;
//        if (cnt == size || node->next == NULL) // 统计到 size 个节点，或到达链表末尾
//        {
//            if (cnt % 2 == 0) // 有偶数个节点
//            {
//                struct ListNode* tail = left->next;
//                struct ListNode* next = node->next;
//                node->next = NULL;
//                left->next = reverse(tail, NULL);
//                tail->next = next;
//                node = tail;
//            }
//            left = node;
//            size++;
//            cnt = 0;
//        }
//    }
//    return head;
//}
//
////2091. 从数组中移除最大值和最小值
//
//int minimumDeletions(int* nums, int numsSize)
//{
//    if (numsSize <= 2)
//        return numsSize;
//    int max = INT_MIN, min = INT_MAX;
//    int idx1 = -1, idx2 = -2;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (min > nums[i])
//        {
//            min = nums[i];
//            idx2 = i;
//        }
//        if (max < nums[i])
//        {
//            max = nums[i];
//            idx1 = i;
//        }
//    }
//    if (idx1 > idx2)
//    {
//        int tmp = idx1;
//        idx1 = idx2;
//        idx2 = tmp;
//    }
//    //printf("%d %d\n%d %d\n", max, idx1, min, idx2);
//    int planA = idx2 + 1;
//    int planB = numsSize - idx1;
//    int planC = numsSize + 1 - idx2 + idx1;
//    //printf("%d %d %d\n", planA, planB, planC);
//    return fmin(planA, fmin(planB, planC));
//}
//
