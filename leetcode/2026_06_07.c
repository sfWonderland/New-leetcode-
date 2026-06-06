//// 2196. 根据描述创建二叉树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//typedef struct
//{
//    int key;
//    bool sub;
//    struct TreeNode* node;
//    UT_hash_handle hh;
//}HashItem;
//struct TreeNode* createBinaryTree(int** descriptions, int descriptionsSize, int* descriptionsColSize)
//{
//    HashItem* nums = NULL;
//    for (int i = 0; i < descriptionsSize; i++)
//    {
//        int fa = descriptions[i][0], child = descriptions[i][1];
//        bool is_left = descriptions[i][2];
//        HashItem* p1 = NULL;
//        HASH_FIND_INT(nums, &fa, p1);
//        if (p1 == NULL)
//        {
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = fa;
//            p1->sub = 0;
//            p1->node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//            p1->node->val = fa;
//            p1->node->left = p1->node->right = NULL;
//            HASH_ADD_INT(nums, key, p1);
//        }
//        struct TreeNode* nodeF = p1->node;
//        HASH_FIND_INT(nums, &child, p1);
//        if (p1 == NULL)
//        {
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = child;
//            p1->sub = 0;
//            p1->node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//            p1->node->val = child;
//            p1->node->left = p1->node->right = NULL;
//            HASH_ADD_INT(nums, key, p1);
//        }
//        p1->sub = true;
//        struct TreeNode* nodeC = p1->node;
//        if (is_left)
//            nodeF->left = nodeC;
//        else
//            nodeF->right = nodeC;
//    }
//    struct TreeNode* root = NULL;
//    HashItem* p = NULL, * tmp = NULL;
//    HASH_ITER(hh, nums, p, tmp)
//    {
//        if (!root && !p->sub)
//            root = p->node;
//        HASH_DEL(nums, p);
//        free(p);
//    }
//    return root;
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
//struct TreeNode* createBinaryTree(int** descriptions, int descriptionsSize, int* descriptionsColSize)
//{
//    struct TreeNode* nodes[100001] = { NULL };
//    bool nums[100001] = { 0 };
//    for (int i = 0; i < descriptionsSize; i++)
//    {
//        int fa = descriptions[i][0], child = descriptions[i][1];
//        bool is_left = descriptions[i][2];
//        if (nodes[fa] == NULL)
//        {
//            nodes[fa] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//            nodes[fa]->val = fa;
//            nodes[fa]->left = nodes[fa]->right = NULL;
//        }
//        struct TreeNode* nodeF = nodes[fa];
//        if (nodes[child] == NULL)
//        {
//            nodes[child] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//            nodes[child]->val = child;
//            nodes[child]->left = nodes[child]->right = NULL;
//        }
//        struct TreeNode* nodeC = nodes[child];
//        if (is_left)
//            nodeF->left = nodeC;
//        else
//            nodeF->right = nodeC;
//        nums[child] = true;
//    }
//    struct TreeNode* root = NULL;
//    for (int i = 0; i < descriptionsSize && !root; i++)
//    {
//        int x = descriptions[i][0];
//        if (!nums[x])
//            root = nodes[x];
//    }
//    return root;
//}
//
