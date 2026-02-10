////341. 扁平化嵌套列表迭代器
//
///**
// * *********************************************************************
// * // This is the interface that allows for creating nested lists.
// * // You should not implement it, or speculate about its implementation
// * *********************************************************************
// *
// * // Return true if this NestedInteger holds a single integer, rather than a nested list.
// * bool NestedIntegerIsInteger(struct NestedInteger *);
// *
// * // Return the single integer that this NestedInteger holds, if it holds a single integer
// * // The result is undefined if this NestedInteger holds a nested list
// * int NestedIntegerGetInteger(struct NestedInteger *);
// *
// * // Return the nested list that this NestedInteger holds, if it holds a nested list
// * // The result is undefined if this NestedInteger holds a single integer
// * struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);
// *
// * // Return the nested list's size that this NestedInteger holds, if it holds a nested list
// * // The result is undefined if this NestedInteger holds a single integer
// * int NestedIntegerGetListSize(struct NestedInteger *);
// * };
// */
//struct NestedIterator
//{
//    int* vals;
//    int size;
//    int cur;
//};
//
//void dfs(struct NestedIterator* iter, struct NestedInteger** nestedList, int nestedListSize)
//{
//    for (int i = 0; i < nestedListSize; i++)
//    {
//        if (NestedIntegerIsInteger(nestedList[i]))
//            (iter->vals)[iter->size++] = NestedIntegerGetInteger(nestedList[i]);
//        else
//            dfs(iter, NestedIntegerGetList(nestedList[i]), NestedIntegerGetListSize(nestedList[i]));
//    }
//}
//
//struct NestedIterator* nestedIterCreate(struct NestedInteger** nestedList, int nestedListSize)
//{
//    struct NestedIterator* obj = (struct NestedIterator*)malloc(sizeof(struct NestedIterator));
//    obj->vals = (int*)malloc(sizeof(int) * 20001);
//    obj->size = 0;
//    obj->cur = 0;
//    dfs(obj, nestedList, nestedListSize);
//    return obj;
//}
//
//bool nestedIterHasNext(struct NestedIterator* iter)
//{
//    return iter->cur != iter->size;
//}
//
//int nestedIterNext(struct NestedIterator* iter)
//{
//    return (iter->vals)[iter->cur++];
//}
//
///** Deallocates memory previously allocated for the iterator */
//void nestedIterFree(struct NestedIterator* iter)
//{
//    free(iter->vals);
//    free(iter);
//}
//
///**
// * Your NestedIterator will be called like this:
// * struct NestedIterator *i = nestedIterCreate(nestedList, nestedListSize);
// * while (nestedIterHasNext(i)) printf("%d\n", nestedIterNext(i));
// * nestedIterFree(i);
// */
//
// //669. 修剪二叉搜索树    
//
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     struct TreeNode *left;
//  *     struct TreeNode *right;
//  * };
//  */
//struct TreeNode* trimBST(struct TreeNode* root, int low, int high)
//{
//    if (root == NULL)
//        return NULL;
//
//    if (root->val < low)
//        return trimBST(root->right, low, high);
//    else if (root->val > high)
//        return trimBST(root->left, low, high);
//    root->left = trimBST(root->left, low, high);
//    root->right = trimBST(root->right, low, high);
//    return root;
//}
//
////985. 查询后的偶数和
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* sumEvenAfterQueries(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
//{
//    int sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] & 1)
//            continue;
//
//        sum += nums[i];
//    }
//    int* ans = (int*)malloc(sizeof(int) * queriesSize);
//    for (int i = 0; i < queriesSize; i++)
//    {
//        int j = queries[i][1], x = queries[i][0];
//        if ((nums[j] % 2) == 0)
//            sum -= nums[j];
//
//        nums[j] += x;
//        if ((nums[j] % 2) == 0)
//            sum += nums[j];
//        ans[i] = sum;
//    }
//    *returnSize = queriesSize;
//    return ans;
//}
//
////986. 区间列表的交集
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** intervalIntersection(int** firstList, int firstListSize, int* firstListColSize, int** secondList, int secondListSize, int* secondListColSize, int* returnSize, int** returnColumnSizes)
//{
//    int capacity = 64;
//    int** ans = (int**)malloc(sizeof(int*) * capacity);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);
//    int i = 0, j = 0, idx = 0;
//    while (i < firstListSize && j < secondListSize)
//    {
//        if (firstList[i][1] < secondList[j][0])
//            i++;
//        else if (firstList[i][0] > secondList[j][1])
//            j++;
//        else
//        {
//            int left = firstList[i][0], right = firstList[i][1];
//            if (left < secondList[j][0])
//            {
//                left = secondList[j][0];
//                firstList[i][0] = secondList[j][0];
//            }
//            else
//                secondList[j][0] = firstList[i][0];
//
//            if (right > secondList[j][1])
//            {
//                right = secondList[j][1];
//                firstList[i][0] = right + 1;
//                j++;
//            }
//            else if (right == secondList[j][1])
//            {
//                i++; j++;
//            }
//            else
//            {
//                secondList[j][0] = right + 1;
//                i++;
//            }
//            //printf("! ");
//            ans[idx] = (int*)malloc(sizeof(int) * 2);
//            ans[idx][0] = left, ans[idx][1] = right;
//            (*returnColumnSizes)[idx++] = 2;
//            if (idx >= capacity)
//            {
//                capacity *= 2;
//                ans = (int**)realloc(ans, sizeof(int*) * capacity);
//                *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * capacity);
//            }
//        }
//    }
//    *returnSize = idx;
//    return ans;
//}
//
