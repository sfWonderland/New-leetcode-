//// 4052. 行列循环移位
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//void reverseRow(int* nums, int l, int r)
//{
//    while (l < r)
//    {
//        int tmp = nums[l];
//        nums[l++] = nums[r];
//        nums[r--] = tmp;
//    }
//}
//void reverseCol(int** grid, int j, int l, int r)
//{
//    while (l < r)
//    {
//        int tmp = grid[l][j];
//        grid[l++][j] = grid[r][j];
//        grid[r--][j] = tmp;
//    }
//}
//int** cyclicShift(int n, int** grid, int gridSize, int* gridColSize, int* rowShift, int rowShiftSize, int* colShift, int colShiftSize, int* returnSize, int** returnColumnSizes)
//{
//    *returnSize = n;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        int k = rowShift[i];
//        reverseRow(grid[i], 0, n - 1);
//        reverseRow(grid[i], 0, n - k - 1);
//        reverseRow(grid[i], n - k, n - 1);
//        (*returnColumnSizes)[i] = n;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        int k = colShift[i];
//        reverseCol(grid, i, 0, n - 1);
//        reverseCol(grid, i, 0, n - k - 1);
//        reverseCol(grid, i, n - k, n - 1);
//    }
//    return grid;
//}
//
//// 3217. 从链表中移除在数组中存在的节点
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//#define MAX_SIZE 100001
//struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head)
//{
//    bool exist[MAX_SIZE] = { 0 };
//    for (int i = 0; i < numsSize; i++)
//    {
//        exist[nums[i]] = true;
//    }
//    struct ListNode* cur = head;
//    while (cur && exist[cur->val])
//    {
//        struct ListNode* node = cur;
//        cur = cur->next;
//        free(node);
//    }
//    head = cur;
//    while (cur)
//    {
//        struct ListNode* nxt = cur->next;
//        while (nxt && exist[nxt->val])
//        {
//            struct ListNode* node = nxt;
//            cur->next = node->next;
//            nxt = node->next;
//            free(node);
//        }
//        cur = cur->next;
//    }
//    return head;
//}
//
//// 83. 删除排序链表中的重复元素
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* deleteDuplicates(struct ListNode* head)
//{
//    struct ListNode* cur = head;
//    while (cur)
//    {
//        struct ListNode* nxt = cur->next;
//        while (nxt && nxt->val == cur->val)
//        {
//            struct ListNode* node = nxt;
//            nxt = nxt->next;
//            cur->next = nxt;
//            free(node);
//        }
//        cur = cur->next;
//    }
//    return head;
//}
//
//// 82. 删除排序链表中的重复元素 II
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* deleteDuplicates(struct ListNode* head)
//{
//    if (head == NULL || head->next == NULL) return head;
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = head;
//    struct ListNode* cur = dummy;
//    while (cur)
//    {
//        struct ListNode* nxt = cur->next;
//        while (nxt && nxt->next && nxt->val == nxt->next->val)
//        {
//            int x = nxt->val;
//            while (nxt && nxt->val == x)
//            {
//                struct ListNode* node = nxt;
//                nxt = nxt->next;
//                free(node);
//            }
//        }
//        cur->next = nxt;
//        cur = cur->next;
//    }
//    return dummy->next;
//}
//
