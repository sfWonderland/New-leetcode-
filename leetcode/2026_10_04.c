//// 2331. 计算布尔二叉树的值
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool evaluateTree(struct TreeNode* root)
//{
//    if (root->val < 2)
//        return root->val;
//    bool left = evaluateTree(root->left);
//    bool right = evaluateTree(root->right);
//    return root->val == 2 ? left | right : left & right;
//}
//
//// 508. 出现次数最多的子树元素和    
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
//int* findFrequentTreeSum(struct TreeNode* root, int* returnSize)
//{
//    HashItem* cnt = NULL;
//    int mx = 0, cntN = 0;
//    int dfs(struct TreeNode* node)
//    {
//        if (node == NULL) return 0;
//        cntN++;
//        int x = node->val + dfs(node->left) + dfs(node->right);
//        HashItem* p1 = NULL;
//        HASH_FIND_INT(cnt, &x, p1);
//        if (p1 == NULL)
//        {
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = x;
//            p1->val = 0;
//            HASH_ADD_INT(cnt, key, p1);
//        }
//        p1->val++;
//        mx = mx > p1->val ? mx : p1->val;
//        return x;
//    }
//    dfs(root);
//    int* ans = (int*)malloc(sizeof(int) * cntN);
//    *returnSize = 0;
//    HashItem* p0 = NULL, * tmp = NULL;
//    HASH_ITER(hh, cnt, p0, tmp)
//    {
//        if (mx == p0->val)
//            ans[(*returnSize)++] = p0->key;
//        HASH_DEL(cnt, p0);
//        free(p0);
//    }
//    return ans;
//}
//
//// 563. 二叉树的坡度
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* node, int* tilts)
//{
//    if (node == NULL) return 0;
//    int left = dfs(node->left, tilts);
//    int right = dfs(node->right, tilts);
//    *tilts += abs(left - right);
//    return node->val + left + right;
//}
//int findTilt(struct TreeNode* root)
//{
//    int ans = 0;
//    dfs(root, &ans);
//    return ans;
//}
//
//// 3997. 统计二叉树中支配节点的数量
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* node, int* dominant)
//{
//    if (node == NULL) return 0;
//    int left = dfs(node->left, dominant);
//    int right = dfs(node->right, dominant);
//    int maxSon = left > right ? left : right;
//    if (maxSon <= node->val)
//    {
//        (*dominant)++;
//        return node->val;
//    }
//    return maxSon;
//}
//int countDominantNodes(struct TreeNode* root)
//{
//    int ans = 0;
//    dfs(root, &ans);
//    return ans;
//}
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* node, int* dominant)
//{
//    if (node == NULL) return 0;
//    int left = dfs(node->left, dominant);
//    int right = dfs(node->right, dominant);
//    int maxSon = left > right ? left : right;
//    if (maxSon > node->val)
//        return maxSon;
//    (*dominant)++;
//    return node->val;
//}
//int countDominantNodes(struct TreeNode* root)
//{
//    int ans = 0;
//    dfs(root, &ans);
//    return ans;
//}
//
