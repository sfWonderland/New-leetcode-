////2643. 一最多的行
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* rowAndMaximumOnes(int** mat, int matSize, int* matColSize, int* returnSize)
//{
//    int* ret = (int*)malloc(sizeof(int) * 2);
//    memset(ret, 0, sizeof(int) * 2);
//    for (int i = 0; i < matSize; i++)
//    {
//        int sum = 0;
//        for (int j = 0; j < matColSize[0]; j++)
//        {
//            sum += mat[i][j];
//        }
//        if (ret[1] < sum)
//        {
//            ret[1] = sum;
//            ret[0] = i;
//        }
//    }
//    returnSize[0] = 2;
//    return ret;
//}
//
////2300. 咒语和药水的成功对数
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize)
//{
//    int* ret = (int*)malloc(sizeof(int) * spellsSize);
//    qsort(potions, potionsSize, sizeof(int), cmp);
//    int n = 0;
//    for (int i = 0; i < spellsSize; i++)
//    {
//        int left = 0;
//        int right = potionsSize - 1;
//        while (left <= right)
//        {
//            int mid = left + ((right - left) >> 1);
//            long long power = (long long)spells[i] * potions[mid];
//            if (power >= success)
//                right = mid - 1;
//            else
//                left = mid + 1;
//        }
//        ret[n++] = potionsSize - left;
//    }
//    returnSize[0] = n;
//    return ret;
//}
//
////2057. 值相等的最小索引
//
//int smallestEqual(int* nums, int numsSize)
//{
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (i % 10 == nums[i])
//            return i;
//    }
//    return -1;
//}
//
////LCR 142. 训练计划 IV
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* trainningPlan(struct ListNode* l1, struct ListNode* l2)
//{
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* p = dummy;
//
//    while (l1 && l2)
//    {
//        if (l1->val < l2->val)
//        {
//            p->next = l1;
//            l1 = l1->next;
//        }
//        else
//        {
//            p->next = l2;
//            l2 = l2->next;
//        }
//        p = p->next;
//    }
//
//    p->next = l1 ? l1 : l2;
//    return dummy->next;
//}
//
