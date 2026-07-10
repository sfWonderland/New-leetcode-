//// 863. 二叉树中所有距离为 K 的结点
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
//
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//
//int* distanceK(struct TreeNode* root, struct TreeNode* target, int k, int* returnSize)
//{
//    int N = 510, M = 1540;
//    // 链表头，下一个结点值，下一个链表头编号
//    int heads[N], points[M], nxt[M];
//    int idx = 0;
//    void add(int a, int b)
//    {
//        points[idx] = b;
//        // 头插法
//        nxt[idx] = heads[a];
//        heads[a] = idx++;
//    }
//    memset(heads, 0x3f, sizeof(heads));
//    void dfs(struct TreeNode* root)
//    {
//        if (root == NULL) return;
//        if (root->left)
//        {
//            add(root->val, root->left->val);
//            add(root->left->val, root->val);
//            dfs(root->left);
//        }
//        if (root->right)
//        {
//            add(root->val, root->right->val);
//            add(root->right->val, root->val);
//            dfs(root->right);
//        }
//    }
//    dfs(root);
//    bool vis[N];
//    memset(vis, 0, sizeof(vis));
//    int queue[N];
//    int front = 0, rear = 0;
//    queue[rear++] = target->val;
//    vis[target->val] = true;
//    int* ans = (int*)malloc(sizeof(int) * N);
//    *returnSize = 0;
//    while (rear > front && k >= 0)
//    {
//        int size = rear - front;
//        while (size-- > 0)
//        {
//            int poll = queue[front++];
//            if (k == 0)
//            {
//                ans[(*returnSize)++] = poll;
//                continue;
//            }
//            for (int i = heads[poll]; i != 0x3f3f3f3f; i = nxt[i])
//            {
//                int j = points[i];
//                if (!vis[j])
//                {
//                    queue[rear++] = j;
//                    vis[j] = true;
//                }
//            }
//        }
//        k--;
//    }
//    return ans;
//}
//
