////238. 除自身以外数组的乘积
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* productExceptSelf(int* nums, int numsSize, int* returnSize)
//{
//    int* suf = malloc(numsSize * sizeof(int));
//    suf[numsSize - 1] = 1;
//    for (int i = numsSize - 2; i >= 0; i--)
//    {
//        suf[i] = nums[i + 1] * suf[i + 1];
//    }
//    int pre = 1;
//    for (int i = 0; i < numsSize; i++)
//    {
//        suf[i] *= pre;
//        pre *= nums[i];
//    }
//    returnSize[0] = numsSize;
//    return suf;
//}
//
////2680. 最大或值
//
//long long maximumOr(int* nums, int numsSize, int k)
//{
//    long long* suf = malloc(numsSize * sizeof(long long));
//    suf[numsSize - 1] = 0;
//    for (int i = numsSize - 2; i >= 0; i--)
//    {
//        suf[i] = nums[i + 1] | suf[i + 1];
//    }
//    long long pre = 0;
//    long long max = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        max = fmax(max, suf[i] | pre | ((long long)nums[i] << k));
//        pre |= nums[i];
//    }
//    free(suf);
//    return max;
//}
//
////LCR 140. 训练计划 II
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* trainingPlan(struct ListNode* head, int cnt)
//{
//    struct ListNode* left = head;
//    struct ListNode* right = head;
//    while (cnt--)
//    {
//        right = right->next;
//    }
//    while (right)
//    {
//        right = right->next;
//        left = left->next;
//    }
//    return left;
//}
//
