////739. 每日温度
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize)
//{
//    int n = temperaturesSize;
//    int* st = (int*)malloc(sizeof(int) * n);
//    int* ans = (int*)malloc(sizeof(int) * n);
//    int top = -1;
//    for (int i = 0; i < n; i++)
//    {
//        while (top >= 0 && temperatures[st[top]] < temperatures[i])
//        {
//            int t = st[top--];
//            ans[t] = i - t;
//        }
//        st[++top] = i;
//    }
//    while (top >= 0)
//    {
//        ans[st[top--]] = 0;
//    }
//    *returnSize = n;
//    return ans;
//}
//
//int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize)
//{
//    int n = temperaturesSize;
//    int* st = (int*)malloc(sizeof(int) * n);
//    int* ans = (int*)calloc(sizeof(int), n);
//    int top = -1;
//    for (int i = 0; i < n; i++)
//    {
//        while (top >= 0 && temperatures[st[top]] < temperatures[i])
//        {
//            int t = st[top--];
//            ans[t] = i - t;
//        }
//        st[++top] = i;
//    }
//    *returnSize = n;
//    return ans;
//}
//
//int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize)
//{
//    int n = temperaturesSize;
//    int* st = (int*)malloc(sizeof(int) * n);
//    int* ans = (int*)calloc(sizeof(int), n);
//    int top = -1;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        while (top >= 0 && temperatures[st[top]] <= temperatures[i])
//            top--;
//        if (top >= 0) ans[i] = st[top] - i;
//        st[++top] = i;
//    }
//    *returnSize = n;
//    return ans;
//}
//
////503. 下一个更大元素 II
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* nextGreaterElements(int* nums, int numsSize, int* returnSize)
//{
//    int n = numsSize;
//    int* st = (int*)malloc(sizeof(int) * n);
//    int* ans = (int*)malloc(sizeof(int) * n);
//    int top = -1;
//    for (int i = 0; i < 2 * n; i++)
//    {
//        int t = nums[i % n];
//        while (top >= 0 && nums[st[top]] < t)
//        {
//            int j = st[top--];
//            ans[j] = t;
//        }
//        if (i < n)
//            st[++top] = i;
//    }
//    while (top >= 0)
//    {
//        int j = st[top--];
//        ans[j] = -1;
//    }
//    *returnSize = n;
//    return ans;
//}
//
//int* nextGreaterElements(int* nums, int numsSize, int* returnSize)
//{
//    int n = numsSize;
//    int* st = (int*)malloc(sizeof(int) * n);
//    int* ans = (int*)malloc(sizeof(int) * n);
//    memset(ans, -1, sizeof(int) * n);
//    int top = -1;
//    for (int i = 2 * n - 1; i >= 0; i--)
//    {
//        int t = nums[i % n];
//        while (top >= 0 && nums[st[top]] <= t)
//            top--;
//        if (top >= 0 && i < n)
//            ans[i] = nums[st[top]];
//        st[++top] = i % n;
//    }
//    *returnSize = n;
//    return ans;
//}
//
////901. 股票价格跨度
//
//typedef struct
//{
//    int* arr;
//    int cur;
//    int* st;
//    int t;
//} StockSpanner;
//
//
//StockSpanner* stockSpannerCreate()
//{
//    StockSpanner* obj = (StockSpanner*)malloc(sizeof(StockSpanner));
//    obj->arr = (int*)malloc(sizeof(int) * 10001);
//    obj->st = (int*)malloc(sizeof(int) * 10000);
//    obj->t = 0;
//    obj->cur = 0;
//    obj->arr[obj->cur] = INT_MAX;
//    obj->st[obj->t] = 0;
//    return obj;
//}
//
//int stockSpannerNext(StockSpanner* obj, int price)
//{
//    int* nums = obj->arr;
//    int* stack = obj->st;
//    int top = obj->t;
//    int day = obj->cur;
//    while (top > 0 && price >= nums[stack[top]])
//    {
//        top--;
//    }
//    nums[++day] = price;
//    int ans = day - stack[top];
//    stack[++top] = day;
//    obj->t = top;
//    obj->cur = day;
//    return ans;
//}
//
//void stockSpannerFree(StockSpanner* obj)
//{
//    free(obj->st);
//    free(obj->arr);
//    free(obj);
//}
//
///**
// * Your StockSpanner struct will be instantiated and called as such:
// * StockSpanner* obj = stockSpannerCreate();
// * int param_1 = stockSpannerNext(obj, price);
//
// * stockSpannerFree(obj);
//*/
//
////1019. 链表中的下一个更大节点
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//int get_len(struct ListNode* node)
//{
//    if (node == NULL)
//        return 0;
//
//    return get_len(node->next) + 1;
//}
//int* nums;
//int* st;
//int i;
//int top;
//void dfs(struct ListNode* node, int* ans)
//{
//    if (node == NULL)
//        return;
//
//    int x = node->val;
//    while (top >= 0 && x > nums[st[top]])
//    {
//        int j = st[top--];
//        ans[j] = x;
//    }
//    nums[++i] = x;
//    st[++top] = i;
//    dfs(node->next, ans);
//}
//int* nextLargerNodes(struct ListNode* head, int* returnSize)
//{
//    int n = get_len(head);
//    nums = (int*)malloc(sizeof(int) * n);
//    st = (int*)malloc(sizeof(int) * n);
//    top = -1, i = -1;
//    int* ans = (int*)malloc(sizeof(int) * n);
//    dfs(head, ans);
//    while (top >= 0)
//    {
//        int j = st[top--];
//        ans[j] = 0;
//    }
//    *returnSize = n;
//    return ans;
//}
//
////1944. 队列中可以看到的人数
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* canSeePersonsCount(int* heights, int heightsSize, int* returnSize)
//{
//    int n = heightsSize;
//    int* ans = (int*)calloc(sizeof(int), n);
//    int* st = (int*)malloc(sizeof(int) * n);
//    int top = 0;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        while (top > 0 && st[top - 1] < heights[i])
//        {
//            top--;
//            ans[i]++;
//        }
//        if (top > 0)
//            ans[i]++;
//        st[top++] = heights[i];
//    }
//    *returnSize = n;
//    return ans;
//}
//
