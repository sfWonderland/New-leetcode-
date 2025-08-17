////679. 24 点游戏
//
//#define EPS 1e-9
//bool dfs(int n, double* cards)
//{
//    if (n == 1)
//        return fabs(cards[0] - 24) < EPS;
//
//    for (int i = 0; i < n; i++)
//    {
//        double x = cards[i];
//        double* new_cards = (double*)malloc(sizeof(double) * n);
//        memcpy(new_cards, cards, sizeof(double) * n);
//        for (int j = i + 1; j < n; j++)
//        {
//            double y = cards[j];
//            double candidate[6] = { x + y, x - y, y - x, x * y, 0, 0 };
//            int m = 4;
//            if (fabs(x) > EPS) candidate[m++] = y / x;
//            if (fabs(y) > EPS) candidate[m++] = x / y;
//            new_cards[j] = new_cards[n - 1];
//            for (int k = 0; k < m; k++)
//            {
//                new_cards[i] = candidate[k];
//                if (dfs(n - 1, new_cards)) return true;
//            }
//            new_cards[j] = y;
//        }
//    }
//    return false;
//}
//bool judgePoint24(int* cards, int cardsSize)
//{
//    double* cards_double = (double*)malloc(sizeof(double) * cardsSize);
//    for (int i = 0; i < cardsSize; i++)
//    {
//        cards_double[i] = (double)cards[i];
//    }
//    return dfs(cardsSize, cards_double);
//}
//
////2641. 二叉树的堂兄弟节点 II
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* replaceValueInTree(struct TreeNode* root)
//{
//    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100000);
//    int front = 0, rear = 0;
//    int next_sum = root->val;
//    queue[rear++] = root;
//    while (rear > front)
//    {
//        int sum = next_sum;
//        next_sum = 0;
//        int start = front;
//        front = rear;
//        for (int i = start; i < front; i++)
//        {
//            queue[i]->val = sum - queue[i]->val;
//            if (queue[i]->left)
//            {
//                queue[rear++] = queue[i]->left;
//                next_sum += queue[i]->left->val;
//            }
//            if (queue[i]->right)
//            {
//                queue[rear++] = queue[i]->right;
//                next_sum += queue[i]->right->val;
//            }
//            if (queue[i]->left && queue[i]->right)
//            {
//                queue[i]->left->val = queue[i]->left->val + queue[i]->right->val;
//                queue[i]->right->val = queue[i]->left->val;
//            }
//        }
//    }
//    return root;
//}
//
////116. 填充每个节点的下一个右侧节点指针
//
///**
// * Definition for a Node.
// * struct Node {
// *     int val;
// *     struct Node *left;
// *     struct Node *right;
// *     struct Node *next;
// * };
// */
//
//struct Node* connect(struct Node* root)
//{
//    if (!root) return NULL;
//    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * 5000);
//    int front = 0, rear = 0;
//    queue[rear++] = root;
//    while (rear > front)
//    {
//        int start = front;
//        front = rear;
//        for (int i = start; i < front; i++)
//        {
//            if (i < front - 1)
//                queue[i]->next = queue[i + 1];
//            if (queue[i]->left) queue[rear++] = queue[i]->left;
//            if (queue[i]->right) queue[rear++] = queue[i]->right;
//        }
//    }
//    return root;
//}
//
///**
// * Definition for a Node.
// * struct Node {
// *     int val;
// *     struct Node *left;
// *     struct Node *right;
// *     struct Node *next;
// * };
// */
//
//struct Node* connect(struct Node* root)
//{
//    struct Node dummy = { 0, NULL, NULL, NULL };
//    struct Node* cur = root;
//    while (cur)
//    {
//        dummy.next = NULL;
//        struct Node* nxt = &dummy;
//        while (cur)
//        {
//            if (cur->left)
//            {
//                nxt->next = cur->left;
//                nxt = cur->left;
//            }
//            if (cur->right)
//            {
//                nxt->next = cur->right;
//                nxt = cur->right;
//            }
//            cur = cur->next;
//        }
//        cur = dummy.next;
//    }
//    return root;
//}
//
////117. 填充每个节点的下一个右侧节点指针 II
//
///**
// * Definition for a Node.
// * struct Node {
// *     int val;
// *     struct Node *left;
// *     struct Node *right;
// *     struct Node *next;
// * };
// */
//
//struct Node* connect(struct Node* root)
//{
//    struct Node dummy = { 0, NULL, NULL, NULL };
//    struct Node* cur = root;
//    while (cur)
//    {
//        dummy.next = NULL;
//        struct Node* nxt = &dummy;
//        while (cur)
//        {
//            if (cur->left)
//            {
//                nxt->next = cur->left;
//                nxt = cur->left;
//            }
//            if (cur->right)
//            {
//                nxt->next = cur->right;
//                nxt = cur->right;
//            }
//            cur = cur->next;
//        }
//        cur = dummy.next;
//    }
//    return root;
//}
//
