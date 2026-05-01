//// 106. 从中序与后序遍历序列构造二叉树  
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) 
//{
//    if(inorderSize == 0)
//        return NULL;
//    int n = inorderSize;
//    int root_val = postorder[n - 1];    
//    int j = -1;
//    for(int i = 0; i < n; i++)
//    {
//        if(inorder[i] == root_val)
//        {
//            j = i;
//            break;
//        }
//    }
//    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    root -> val = root_val;
//    root -> left = buildTree(inorder, j, postorder, j);
//    root -> right = buildTree(inorder + j + 1, n - j - 1, postorder + j, n - j - 1);
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
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//struct TreeNode* bulidTreeNodes(int* postorder, int n, int k, HashItem** ad_pos)
//{
//    if (n == 0)
//        return NULL;
//    
//    HashItem* pos = *ad_pos;
//    HashItem* p = NULL;
//    
//    // 后序遍历的最后一个元素是根节点
//    int root_val = postorder[n - 1];    
//    
//    // 使用哈希表 O(1) 查找根节点在中序遍历中的位置
//    HASH_FIND_INT(pos, &root_val, p);
//    int root_index = p->val;  // 根节点在中序遍历中的索引
//    
//    // 计算左子树节点数量
//    int left_size = root_index - k;
//    int right_size = n - left_size - 1;
//    
//    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    root->val = root_val;
//    
//    // 递归构建左子树：
//    // 后序遍历前 left_size 个元素，中序起始位置为 k
//    root->left = bulidTreeNodes(postorder, left_size, k, ad_pos);
//    
//    // 递归构建右子树：
//    // 后序遍历跳过 left_size 个元素后的部分，中序起始位置为 root_index + 1
//    root->right = bulidTreeNodes(postorder + left_size, right_size, root_index + 1, ad_pos);
//    
//    return root;
//}
//struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) 
//{
//    HashItem* pos = NULL;
//    HashItem* p = NULL;
//    for(int i = 0; i < inorderSize; i++)
//    {
//        p = (HashItem*)malloc(sizeof(HashItem));
//        p -> key = inorder[i];
//        p -> val = i;
//        HASH_ADD_INT(pos, key, p);
//    }
//    struct TreeNode* root = bulidTreeNodes(postorder, inorderSize, 0, &pos);
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, pos, p, tmp)
//    {
//        HASH_DEL(pos, p);
//        free(p);
//    }
//    return root;
//}
//
//// LCR 152. 验证二叉搜索树的后序遍历序列
//
//bool bulidTree(int* postorder, int n, int mn, int mx)
//{
//    if(n == 0)
//        return true;
//    int root_val = postorder[n - 1];
//    // printf("%d %d %d\n", root_val, mn, mx);
//    if(n == 1)
//        return root_val > mn && root_val < mx;
//    int j = -1;
//    for(int i = n - 2; i >= 0; i--)
//    {
//        if(postorder[i] < root_val)
//        {
//            j = i;
//            break;
//        }
//    }
//    int left = j + 1;
//    int right = n - left - 1;
//    return bulidTree(postorder, left, mn, fmin(mx, root_val)) 
//        && bulidTree(postorder + left, right, fmax(mn, root_val), mx);
//}
//bool verifyTreeOrder(int* postorder, int postorderSize) 
//{
//    return bulidTree(postorder, postorderSize, INT_MIN, INT_MAX);
//}
//
//// LCS 02. 完成一半题目
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//
//int halfQuestions(int* questions, int questionsSize)
//{
//    int n = questionsSize;
//    int freq[n];
//    memset(freq, 0, sizeof(freq));
//    int size = 0;
//    HashItem* cnt = NULL;
//    HashItem* p = NULL;
//    for(int i = 0; i < n; i++)
//    {
//        HASH_FIND_INT(cnt, &questions[i], p);
//        if(p == NULL)
//        {
//            p = (HashItem*)malloc(sizeof(HashItem));
//            p -> key = questions[i];
//            p -> val = size++;
//            HASH_ADD_INT(cnt, key, p);
//        }
//        freq[p -> val]++;
//    }
//    qsort(freq, size, sizeof(int), cmp);
//    int m = n / 2 - 1;
//    for(int i = 0; i < size; i++)
//    {
//        m -= freq[i];
//        if(m < 0)
//        return i + 1;
//    }
//    return size;
//}
//
//// 面试题 01.01. 判定字符是否唯一
//
//bool isUnique(char* astr) 
//{
//    bool alpha[26] = {0};
//    for(int i = 0; astr[i]; i++)
//    {
//        if(alpha[astr[i] - 'a'])
//            return false;
//        alpha[astr[i] - 'a'] = true;
//    }    
//    return true;
//}
//
