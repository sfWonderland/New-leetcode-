//// 501. 二叉搜索树中的众数   
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int* findMode(struct TreeNode* root, int* returnSize)
//{
//    HashItem* cnt = NULL;
//    int max = 0;
//    void dfs(struct TreeNode* node)
//    {
//        if (node == NULL)
//            return;
//
//        dfs(node->left);
//        HashItem* p1 = NULL;
//        HASH_FIND_INT(cnt, &node->val, p1);
//        if (p1 == NULL)
//        {
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = node->val;
//            p1->val = 0;
//            HASH_ADD_INT(cnt, key, p1);
//        }
//        p1->val++;
//        max = fmax(max, p1->val);
//        dfs(node->right);
//    }
//    dfs(root);
//    int capacity = 8;
//    int* ans = (int*)malloc(sizeof(int) * capacity);
//    int n = 0;
//    HashItem* p = NULL, * tmp = NULL;
//    HASH_ITER(hh, cnt, p, tmp)
//    {
//        if (max == p->val)
//        {
//            ans[n++] = p->key;
//            if (capacity <= n)
//            {
//                capacity *= 2;
//                ans = (int*)realloc(ans, sizeof(int) * capacity);
//            }
//        }
//        HASH_DEL(cnt, p);
//        free(p);
//    }
//    *returnSize = n;
//    return ans;
//}
//
