//// 396. 旋转函数
//
//int maxRotateFunction(int* nums, int numsSize)
//{
//    int sum = 0, pre = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//        pre += i * nums[i];
//    }
//    int ans = pre;
//    for (int i = 1; i < numsSize; i++)
//    {
//        pre = pre - nums[(numsSize - i) % numsSize] * numsSize + sum;
//        ans = fmax(ans, pre);
//    }
//    return ans;
//}
//
////  LCR 119. 最长连续序列  
//
//typedef struct
//{
//    int key;
//    UT_hash_handle hh;
//}HashItem;
//
//int longestConsecutive(int* nums, int numsSize)
//{
//    HashItem* exist = NULL;
//    HashItem* p = NULL;
//    for (int i = 0; i < numsSize; i++)
//    {
//        HASH_FIND_INT(exist, &nums[i], p);
//        if (p == NULL)
//        {
//            p = (HashItem*)malloc(sizeof(HashItem));
//            p->key = nums[i];
//            HASH_ADD_INT(exist, key, p);
//        }
//    }
//
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = nums[i];
//        int y = x - 1;
//        HASH_FIND_INT(exist, &y, p);
//        if (p) continue;
//
//        y = x;
//        do
//        {
//            y++;
//            HASH_FIND_INT(exist, &y, p);
//        } while (p);
//        ans = fmax(ans, y - x);
//    }
//    return ans;
//}
//
//// LCR 124. 推理二叉树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* deduceTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
//{
//    int n = preorderSize;
//    if (n == 0)
//        return NULL;
//    int root_val = preorder[0];
//    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    root->val = root_val;
//    root->left = NULL;
//    root->right = NULL;
//    int j = -1;
//    for (int i = 0; i < n; i++)
//    {
//        if (inorder[i] == root_val)
//        {
//            j = i;
//            break;
//        }
//    }
//    root->left = deduceTree(preorder + 1, j, inorder, j);
//    root->right = deduceTree(preorder + 1 + j, n - 1 - j, inorder + 1 + j, n - 1 - j);
//    return root;
//}
//
//// 105. 从前序与中序遍历序列构造二叉树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
//{
//    int n = preorderSize;
//    if (n == 0)
//        return NULL;
//    int root_val = preorder[0];
//    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    root->val = root_val;
//    root->left = NULL;
//    root->right = NULL;
//    int j = -1;
//    for (int i = 0; i < n; i++)
//    {
//        if (inorder[i] == root_val)
//        {
//            j = i;
//            break;
//        }
//    }
//    root->left = buildTree(preorder + 1, j, inorder, j);
//    root->right = buildTree(preorder + 1 + j, n - 1 - j, inorder + 1 + j, n - 1 - j);
//    return root;
//}
//
