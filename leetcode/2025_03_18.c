////2614. 对角线上的质数
//
//bool is_prime(int n)
//{
//    if (n == 1)
//        return false;
//    int k = sqrt(n);
//    for (int i = 2; i <= k; i++)
//    {
//        if (n % i == 0)
//            return false;
//    }
//    return true;
//}
//int diagonalPrime(int** nums, int numsSize, int* numsColSize)
//{
//    int max = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (is_prime(nums[i][i]))
//            max = fmax(max, nums[i][i]);
//        if (is_prime(nums[numsSize - 1 - i][i]))
//            max = fmax(max, nums[numsSize - 1 - i][i]);
//    }
//    return max;
//}
//
////LCR 123. 图书整理 I
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//void reverse(int* arr, int left, int right)
//{
//    while (left < right)
//    {
//        int tmp = arr[left];
//        arr[left] = arr[right];
//        arr[right] = tmp;
//        left++;
//        right--;
//    }
//}
//int* reverseBookList(struct ListNode* head, int* returnSize)
//{
//    struct ListNode* p = head; //无头结点
//    int n = 0;
//    while (p != NULL)
//    {
//        p = p->next;
//        n++;
//    }
//    int* ret = (int*)malloc(sizeof(int) * n);
//    p = head;
//    n = 0;
//    while (p != NULL)
//    {
//        ret[n++] = p->val;
//        p = p->next;
//    }
//    reverse(ret, 0, n - 1);
//    *returnSize = n;
//    return ret;
//}
//
////LCR 141. 训练计划 III
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* trainningPlan(struct ListNode* head)
//{
//    struct ListNode* L = (struct ListNode*)malloc(sizeof(struct ListNode));
//    L->next = NULL;
//    struct ListNode* p = head;
//    struct ListNode* s;
//    while (p != NULL)
//    {
//        s = (struct ListNode*)malloc(sizeof(struct ListNode));
//        s->val = p->val;
//        s->next = L->next;
//        L->next = s;
//        p = p->next;
//    }
//    return L->next;
//}
//
////21. 合并两个有序链表
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//    struct ListNode* L = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* p = L;
//
//    while (list1 && list2)
//    {
//        if ((list1->val) < (list2->val))
//        {
//            p->next = list1;
//            list1 = list1->next;
//        }
//        else
//        {
//            p->next = list2;
//            list2 = list2->next;
//        }
//        p = p->next;
//    }
//    p->next = list1 ? list1 : list2;
//    return L->next;
//}
//
