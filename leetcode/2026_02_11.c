////692. 前K个高频单词
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    char* key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//
//int cmp(const void* e1, const void* e2)
//{
//    return ((HashItem*)e2)->val == ((HashItem*)e1)->val ?
//        strcmp(((HashItem*)e1)->key, ((HashItem*)e2)->key) :
//        ((HashItem*)e2)->val - ((HashItem*)e1)->val;
//}
//char** topKFrequent(char** words, int wordsSize, int k, int* returnSize)
//{
//    HashItem* cnt = NULL;
//    for (int i = 0; i < wordsSize; i++)
//    {
//        HashItem* p1 = NULL;
//        HASH_FIND_STR(cnt, words[i], p1);
//        if (p1 == NULL)
//        {
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = words[i];
//            p1->val = 0;
//            HASH_ADD_STR(cnt, key, p1);
//        }
//        p1->val++;
//    }
//    HASH_SORT(cnt, cmp);
//    char** ans = (char**)malloc(sizeof(char*) * k);
//    *returnSize = 0;
//    HashItem* cur = NULL, * tmp = NULL;
//    HASH_ITER(hh, cnt, cur, tmp)
//    {
//        if ((*returnSize) < k)
//            ans[(*returnSize)++] = cur->key;
//        HASH_DEL(cnt, cur);
//        free(cur);
//    }
//    return ans;
//}
//
////701. 二叉搜索树中的插入操作    
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* insertIntoBST(struct TreeNode* root, int val)
//{
//    if (root == NULL)
//    {
//        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//        node->left = node->right = NULL;
//        node->val = val;
//        return node;
//    }
//    if (val > root->val)
//        root->right = insertIntoBST(root->right, val);
//    else
//        root->left = insertIntoBST(root->left, val);
//    return root;
//}
//
////653. 两数之和 IV - 输入二叉搜索树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool findTarget(struct TreeNode* root, int k)
//{
//    int nums[10000];
//    int n = 0;
//    void dfs(struct TreeNode* node)
//    {
//        if (node == NULL)
//            return;
//        dfs(node->left);
//        nums[n++] = node->val;
//        dfs(node->right);
//    }
//    dfs(root);
//
//    int left = 0, right = n - 1;
//    while (left < right && nums[left] + nums[right] != k)
//    {
//        if (nums[left] + nums[right] > k)
//            right--;
//        else
//            left++;
//    }
//    return left != right;
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
//bool findTarget(struct TreeNode* root, int k)
//{
//    if (k > 20000 || k < -20000)
//        return false;
//    bool nums[20001] = { 0 };
//    bool dfs(struct TreeNode* node)
//    {
//        if (node == NULL)
//            return false;
//
//        if (dfs(node->left))
//            return true;
//        if (k - node->val >= -10000 && k - node->val <= 10000 && nums[k - node->val + 10000])
//            return true;
//        nums[node->val + 10000] = true;
//        return dfs(node->right);
//    }
//    return dfs(root);
//}
//
////540. 有序数组中的单一元素
//
//int singleNonDuplicate(int* nums, int numsSize)
//{
//    int left = 0, right = numsSize - 1;
//    while (left <= right)
//    {
//        int mid = (right + left) / 2;
//        if (mid & 1)
//        {
//            if (nums[mid - 1] == nums[mid])
//                left = mid + 1;
//            else
//                right = mid - 1;
//        }
//        else
//        {
//            if (mid < numsSize - 1 && nums[mid + 1] == nums[mid])
//                left = mid + 1;
//            else
//                right = mid - 1;
//        }
//    }
//    return nums[left];
//}
//
