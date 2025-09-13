////147. 对链表进行插入排序
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* insertionSortList(struct ListNode* head)
//{
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = head;
//    struct ListNode* p = head;
//    while (p)
//    {
//        struct ListNode* nxt = p->next;
//        if (nxt && p->val > nxt->val)
//        {
//            p->next = p->next->next;
//            struct ListNode* s = dummy;
//            while (nxt->val > s->next->val)
//                s = s->next;
//            nxt->next = s->next;
//            s->next = nxt;
//        }
//        else
//            p = nxt;
//    }
//    return dummy->next;
//}
//
////725. 分隔链表
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
//struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize)
//{
//    struct ListNode** res = (struct ListNode**)malloc(sizeof(struct ListNode*) * k);
//    for (int i = 0; i < k; i++)
//    {
//        res[i] = NULL;
//    }
//    *returnSize = k;
//    if (!head)
//        return res;
//
//    res[0] = head;
//    struct ListNode* p = head;
//    int n = 1;
//    while (p->next)
//    {
//        p = p->next;
//        n++;
//    }
//
//    int div = n / k;
//    int remainder = n % k;
//    p = head;
//    int t = 1;
//    int num = 1;
//    while (p->next)
//    {
//        if (t < div || (t == div && remainder))
//        {
//            t++;
//            p = p->next;
//        }
//        else
//        {
//            t = 1;
//            if (remainder) remainder--;
//            struct ListNode* s = p;
//            p = p->next;
//            s->next = NULL;
//            res[num++] = p;
//        }
//    }
//
//    return res;
//}
//
////872. 叶子相似的树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//void dfs(struct TreeNode* root, int* arr, int* idx)
//{
//    if (root->left || root->right)
//    {
//        if (root->left)
//            dfs(root->left, arr, idx);
//        if (root->right)
//            dfs(root->right, arr, idx);
//    }
//    else
//        arr[(*idx)++] = root->val;
//}
//bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2)
//{
//    if (!root1 && !root2)
//        return true;
//    if (!(root1 && root2))
//        return false;
//    int* arr1 = (int*)malloc(sizeof(int) * 101);
//    int idx1 = 0;
//    int* arr2 = (int*)malloc(sizeof(int) * 101);
//    int idx2 = 0;
//    dfs(root1, arr1, &idx1);
//    dfs(root2, arr2, &idx2);
//    if (idx1 != idx2) return false;
//    for (int i = 0; i < idx1; i++)
//    {
//        if (arr1[i] != arr2[i])
//            return false;
//    }
//    return true;
//}
//
////LCP 44. 开幕式焰火
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//
//void dfs(struct TreeNode* node, bool* color, int* n)
//{
//    if (node == NULL)
//        return;
//
//    int x = node->val;
//    if (!color[x])
//    {
//        color[x] = true;
//        (*n)++;
//    }
//    dfs(node->left, color, n);
//    dfs(node->right, color, n);
//}
//int numColor(struct TreeNode* root)
//{
//    bool* color = (bool*)calloc(sizeof(bool), 1001);
//    int n = 0;
//    dfs(root, color, &n);
//    return n;
//}
//
