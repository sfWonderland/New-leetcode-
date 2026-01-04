////3047. 求交集区域内的最大正方形面积
//
//long long largestSquareArea(int** bottomLeft, int bottomLeftSize, int* bottomLeftColSize, int** topRight, int topRightSize, int* topRightColSize)
//{
//    int n = bottomLeftSize;
//    long long ans = 0;
//    // 遍历所有矩形组合，找出交集矩形尺寸
//    for (int i = 0; i < n - 1; i++)
//    {
//        int x1 = bottomLeft[i][0], x2 = topRight[i][0];
//        int y1 = bottomLeft[i][1], y2 = topRight[i][1];
//        for (int j = i + 1; j < n; j++)
//        {
//            int xL = fmax(x1, bottomLeft[j][0]), xR = fmin(x2, topRight[j][0]);
//            int yL = fmax(y1, bottomLeft[j][1]), yR = fmin(y2, topRight[j][1]);
//            if (xL > xR || yL > yR)
//                continue;
//            // 以最短边为正方形边长
//            int size = fmin(xR - xL, yR - yL);
//            ans = fmax(1ll * size * size, ans);
//        }
//    }
//    return ans;
//}
//
////1386. 安排电影院座位    
//
//int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize)
//{
//    int* seats = (int*)calloc(sizeof(int), n);
//    for (int i = 0; i < reservedSeatsSize; i++)
//    {
//        int row = reservedSeats[i][0] - 1;
//        int col = reservedSeats[i][1] - 1;
//        seats[row] |= 1 << col;
//    }
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        bool left = (seats[i] >> 1 & 15) == 0;
//        bool right = (seats[i] >> 5 & 15) == 0;
//        if (left || right)
//            ans += left + right;
//        else if ((seats[i] >> 3 & 15) == 0)
//            ans++;
//    }
//    return ans;
//}
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize)
//{
//    int left = 0xf0, right = 0xf, mid = 0xc3;
//    HashItem* seats = NULL;
//    HashItem* pEntry = NULL;
//    int sum = 0;
//    for (int i = 0; i < reservedSeatsSize; i++)
//    {
//        if (reservedSeats[i][1] >= 2 && reservedSeats[i][1] <= 9)
//        {
//            HASH_FIND_INT(seats, &reservedSeats[i][0], pEntry);
//            if (pEntry == NULL)
//            {
//                pEntry = (HashItem*)malloc(sizeof(HashItem));
//                pEntry->key = reservedSeats[i][0];
//                pEntry->val = (1 << (reservedSeats[i][1] - 2));
//                HASH_ADD_INT(seats, key, pEntry);
//                sum++;
//            }
//            else
//                pEntry->val |= (1 << (reservedSeats[i][1] - 2));
//        }
//    }
//    int ans = 2 * (n - sum);
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, seats, pEntry, tmp)
//    {
//        int x = pEntry->val;
//        if ((x | left) == left || (x | mid) == mid || (x | right) == right)
//            ans++;
//
//        free(pEntry);
//    }
//    return ans;
//}
//
////1604. 警告一小时内使用相同员工卡大于等于三次的人
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
//int getTime(char* time)
//{
//    char* s = strtok(time, ":");
//    int mins = atoi(s) * 60;
//    s = strtok(NULL, ":");
//    mins += atoi(s);
//    return mins;
//}
//int* times;
//int cmp1(const void* e1, const void* e2)
//{
//    return times[*(int*)e1] - times[*(int*)e2];
//}
//int cmp2(const void* e1, const void* e2)
//{
//    return strcmp(*(char**)e1, *(char**)e2);
//}
//char** alertNames(char** keyName, int keyNameSize, char** keyTime, int keyTimeSize, int* returnSize)
//{
//    HashItem* employee = NULL;
//    HashItem* pEntry = NULL;
//    int n = keyNameSize;
//    times = (int*)malloc(sizeof(int) * n);
//    int* idx = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        times[i] = getTime(keyTime[i]);
//        idx[i] = i;
//    }
//    qsort(idx, n, sizeof(int), cmp1);
//    int left = 0;
//    pEntry = (HashItem*)malloc(sizeof(HashItem));
//    pEntry->key = keyName[idx[0]];
//    pEntry->val = 1;
//    HASH_ADD_STR(employee, key, pEntry);
//    char** ans = (char**)malloc(sizeof(char*) * n);
//    int k = 0; // ansSize
//    for (int i = 1; i < n; i++)
//    {
//        while (times[idx[i]] > times[idx[left]] + 60)
//        {
//            HASH_FIND_STR(employee, keyName[idx[left]], pEntry);
//            pEntry->val--;
//            left++;
//        }
//        HASH_FIND_STR(employee, keyName[idx[i]], pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = keyName[idx[i]];
//            pEntry->val = 1;
//            HASH_ADD_STR(employee, key, pEntry);
//        }
//        else
//            pEntry->val++;
//
//        if (pEntry->val >= 3)
//        {
//            int m = strlen(pEntry->key);
//            ans[k] = (char*)malloc(sizeof(char) * (m + 1));
//            strcpy(ans[k], pEntry->key);
//            k++;
//            pEntry->val = -n;
//        }
//    }
//    qsort(ans, k, sizeof(char*), cmp2);
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, employee, pEntry, tmp);
//    {
//        free(pEntry);
//    }
//    *returnSize = k;
//    return ans;
//}
//
////3319. 第 K 大的完美二叉子树的大小
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int kthLargestPerfectSubtree(struct TreeNode* root, int k)
//{
//    int treeIter(struct TreeNode* root)
//    {
//        if (root == NULL)
//            return 0;
//
//        return treeIter(root->left) + treeIter(root->right) + 1;
//    }
//    int n = treeIter(root);
//    int* nums = (int*)malloc(sizeof(int) * n);
//    int idx = 0;
//    int dfs(struct TreeNode* node)
//    {
//        if (node == NULL)
//            return 0;
//
//        int left = dfs(node->left);
//        int right = dfs(node->right);
//        if (left == -1 || right != left)
//            return -1;
//
//        nums[idx++] = left + 1;
//        return left + 1;
//    }
//    dfs(root);
//    if (idx < k)
//        return -1;
//    qsort(nums, idx, sizeof(int), cmp);
//    return pow(2, nums[k - 1]) - 1;
//}
//
