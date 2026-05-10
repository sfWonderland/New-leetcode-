//// 3921. 分数验证器
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* scoreValidator(char** events, int eventsSize, int* returnSize)
//{
//    int score = 0, counter = 0;
//    for (int i = 0; i < eventsSize && counter < 10; i++)
//    {
//        if (events[i][0] <= '6')
//            score += events[i][0] - '0';
//        else if (events[i][1])
//            score++;
//        else
//            counter++;
//    }
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    ans[0] = score; ans[1] = counter;
//    *returnSize = 2;
//    return ans;
//}
//
//// 3922. 使二进制字符串连贯的最少翻转次数   
//
//int minFlips(char* s)
//{
//    int n = strlen(s);
//    if (n < 3)
//        return 0;
//    int cnt = 0; // cnt of '1'; times;
//    // 几种允许的情况
//    // 1. 全是1
//    // 2. 1 0 0 ... 0 1, 只有首尾两个1
//    // 3. 首尾不全是1，最多一个1
//
//    // 修改方案
//    // 1. 将1变为0，减少1的个数
//    // 2. 将0变为1，全变为1
//    for (int i = 0; i < n; i++)
//    {
//        cnt += s[i] & 1;
//    }
//    if (cnt == n || cnt == 0)
//        return 0;
//    int ans = n - cnt;
//    if (s[0] + s[n - 1] == 98)
//        ans = fmin(ans, cnt - 2);
//    else
//        ans = fmin(ans, cnt - 1);
//    return ans;
//}
//
//// 3923. 得到目标点的最少代数
//
//int minGenerations(int** points, int pointsSize, int* pointsColSize, int* target, int targetSize)
//{
//    int n = pointsSize;
//    int* queue[450];
//    bool vis[450] = { 0 }; // x << 6 | y << 3 | z; 110110110 = 438
//    int bottom = 0, top = 0;
//    int x0 = target[0], y0 = target[1], z0 = target[2];
//    // int max_x = 0, max_y = 0, max_z = 0;
//    // int min_x = 6, min_y = 6, min_z = 6;
//    for (int i = 0; i < n; i++)
//    {
//        queue[top++] = points[i];
//        int x = points[i][0];
//        int y = points[i][1];
//        int z = points[i][2];
//        if (x == x0 && y == y0 && z == z0)
//            return 0;
//        int mask = (x << 6) | (y << 3) | z;
//        vis[mask] = true;
//    }
//    if (n == 1)
//        return -1;
//    int generation = 1;
//    while (bottom < top)
//    {
//        int start = generation > 1 ? bottom : 0;
//        bottom = top;
//        for (int i = 0; i < bottom; i++)
//        {
//            int x1 = queue[i][0];
//            int y1 = queue[i][1];
//            int z1 = queue[i][2];
//            start = start ? start : i + 1;
//            for (int j = start; j < bottom; j++)
//            {
//                int x = (x1 + queue[j][0]) / 2;
//                int y = (y1 + queue[j][1]) / 2;
//                int z = (z1 + queue[j][2]) / 2;
//                int mask = (x << 6) | (y << 3) | z;
//                if (vis[mask])
//                    continue;
//                if (x == x0 && y == y0 && z == z0)
//                    return generation;
//                vis[mask] = true;
//                queue[top] = (int*)malloc(sizeof(int) * 3);
//                queue[top][0] = x;
//                queue[top][1] = y;
//                queue[top++][2] = z;
//            }
//        }
//        generation++;
//    }
//    return -1;
//}
//
//// 面试题 04.10. 检查子树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool check(struct TreeNode* t1, struct TreeNode* t2)
//{
//    if (t1 == NULL)
//        return t2 ? false : true;
//    if (t2 == NULL)
//        return false;
//    if (t1->val != t2->val)
//        return false;
//    bool left = check(t1->left, t2->left);
//    bool right = check(t1->right, t2->right);
//    return left & right;
//}
//bool checkSubTree(struct TreeNode* t1, struct TreeNode* t2)
//{
//    if (t2 == NULL)
//        return true;
//    if (t1 == NULL)
//        return false;
//    if (t1->val == t2->val && check(t1, t2))
//        return true;
//
//    bool left = checkSubTree(t1->left, t2);
//    bool right = checkSubTree(t1->right, t2);
//    return left | right;
//}
//
