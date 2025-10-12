////3159. 查询数组中元素的出现位置
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* occurrencesOfElement(int* nums, int numsSize, int* queries, int queriesSize, int x, int* returnSize)
//{
//    int st[numsSize];
//    int top = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] == x)
//            st[top++] = i;
//    }
//    for (int i = 0; i < queriesSize; i++)
//    {
//        queries[i] = queries[i] > top ? -1 : st[queries[i] - 1];
//    }
//    *returnSize = queriesSize;
//    return queries;
//}
//
////538. 把二叉搜索树转换为累加树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//void dfs(struct TreeNode* s, int* sum)
//{
//    if (s == NULL)
//        return;
//
//    dfs(s->right, sum);
//    *sum += s->val;
//    s->val = *sum;
//    dfs(s->left, sum);
//}
//struct TreeNode* convertBST(struct TreeNode* root)
//{
//    int sum = 0;
//    dfs(root, &sum);
//    return root;
//}
//
////2679. 矩阵中的和
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int matrixSum(int** nums, int numsSize, int* numsColSize)
//{
//    int m = numsSize, n = numsColSize[0];
//    for (int i = 0; i < m; i++)
//    {
//        qsort(nums[i], n, sizeof(int), cmp);
//    }
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int mx = 0;
//        for (int j = 0; j < m; j++)
//        {
//            mx = fmax(mx, nums[j][i]);
//        }
//        ans += mx;
//    }
//    return ans;
//}
//
////LCR 041. 数据流中的移动平均值
//
//typedef struct
//{
//    int* nums;
//    int i;
//    int n;
//    int sum;
//} MovingAverage;
//
///** Initialize your data structure here. */
//
//MovingAverage* movingAverageCreate(int size)
//{
//    MovingAverage* obj = (MovingAverage*)malloc(sizeof(MovingAverage));
//    obj->nums = (int*)calloc(sizeof(int), size);
//    obj->i = 0;
//    obj->n = size;
//    obj->sum = 0;
//    return obj;
//}
//
//double movingAverageNext(MovingAverage* obj, int val)
//{
//    obj->sum += val - obj->nums[obj->i % obj->n];
//    obj->nums[obj->i % obj->n] = val;
//    int num = fmin(obj->i + 1, obj->n);
//    obj->i++;
//    return 1.0 * obj->sum / num;
//}
//
//void movingAverageFree(MovingAverage* obj)
//{
//    free(obj->nums);
//    free(obj);
//}
//
///**
// * Your MovingAverage struct will be instantiated and called as such:
// * MovingAverage* obj = movingAverageCreate(size);
// * double param_1 = movingAverageNext(obj, val);
//
// * movingAverageFree(obj);
//*/
//
