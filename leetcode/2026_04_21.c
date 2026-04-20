////LCR 053. 二叉搜索树中的中序后继
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* inorderSuccessor(struct TreeNode* root, struct TreeNode* p)
//{
//    struct TreeNode* cur = root;
//    struct TreeNode* res = NULL;
//    while (cur)
//    {
//        if (cur->val > p->val)
//        {
//            res = cur;
//            cur = cur->left;
//        }
//        else {
//            cur = cur->right;
//        }
//    }
//    return res;
//}
//
//// LCR 056. 两数之和 IV - 输入二叉搜索树    
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
//bool findTarget(struct TreeNode* root, int k)
//{
//    if (k <= -20000 || k >= 20000)
//        return false;
//
//    bool nums[20001] = { false };
//    bool ans = false;
//    void dfs(struct TreeNode* node)
//    {
//        if (node == NULL)
//            return;
//
//        dfs(node->left);
//        int x = k - node->val;
//        if (x < node->val && -10000 <= x && x <= 10000 && nums[x + 10000])
//        {
//            ans = true;
//            return;
//        }
//        nums[node->val + 10000] = true;
//        dfs(node->right);
//    }
//    dfs(root);
//    return ans;
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
//
//
//bool findTarget(struct TreeNode* root, int k)
//{
//    if (k <= -20000 || k >= 20000)
//        return false;
//
//    int capacity = 8;
//    int* nums = (int*)malloc(sizeof(int) * capacity);
//    int n = 0;
//    void dfs(struct TreeNode* node)
//    {
//        if (node == NULL)
//            return;
//
//        dfs(node->left);
//        nums[n++] = node->val;
//        if (n >= capacity)
//        {
//            capacity *= 2;
//            nums = (int*)realloc(nums, sizeof(int) * capacity);
//        }
//        dfs(node->right);
//    }
//    dfs(root);
//    if (n == 1) return false;
//    if (nums[0] + nums[1] > k || nums[n - 1] + nums[n - 2] < k)
//        return false;
//    int left = 0, right = n - 1;
//    while (left < right)
//    {
//        if (nums[left] + nums[right] < k)
//            left++;
//        else if (nums[left] + nums[right] == k)
//            return true;
//        else
//            right--;
//    }
//    free(nums);
//    return false;
//}
//
////LCR 059. 数据流中的第 K 大元素
//
//typedef struct
//{
//    int* heap;
//    int heapSize;
//    int n;
//} KthLargest;
//
//void up(int* heap, int i)
//{
//    int x = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j] < x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//
//        if (j == 0)
//            break;
//    }
//    heap[i] = x;
//}
//
//void down(int* heap, int i, int n)
//{
//    int x = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1] < heap[j])
//            j++;
//
//        if (heap[j] > x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//
//void push(int* heap, int* heapSize, int n, int x)
//{
//    if (*heapSize < n)
//    {
//        heap[*heapSize] = x;
//        up(heap, *heapSize);
//        (*heapSize)++;
//    }
//    else
//    {
//        if (x < heap[0])
//            return;
//
//        heap[0] = x;
//        down(heap, 0, n);
//    }
//}
//
//KthLargest* kthLargestCreate(int k, int* nums, int numsSize)
//{
//    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
//    obj->heap = (int*)malloc(sizeof(int) * k);
//    obj->heapSize = 0;
//    obj->n = k;
//    for (int i = 0; i < numsSize; i++)
//    {
//        push(obj->heap, &obj->heapSize, obj->n, nums[i]);
//    }
//    // for(int i = 0; i < k; i++)
//    // {
//    //     printf("%d ", obj -> heap[i]);
//    // }
//    // printf("\n");
//    return obj;
//}
//
//int kthLargestAdd(KthLargest* obj, int val)
//{
//    push(obj->heap, &obj->heapSize, obj->n, val);
//    // for(int i = 0; i < obj -> heapSize; i++)
//    // {
//    //     printf("%d ", obj -> heap[i]);
//    // }
//    // printf("\n");
//    return obj->heap[0];
//}
//
//void kthLargestFree(KthLargest* obj)
//{
//    free(obj->heap);
//    free(obj);
//}
//
///**
// * Your KthLargest struct will be instantiated and called as such:
// * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
// * int param_1 = kthLargestAdd(obj, val);
//
// * kthLargestFree(obj);
//*/
//
////LCR 060. 前 K 个高频元素
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//
//void up(int** heap, int i)
//{
//    int x = heap[0][i], freq = heap[1][i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[1][j] < freq)
//            break;
//
//        heap[0][i] = heap[0][j];
//        heap[1][i] = heap[1][j];
//        i = j;
//
//        if (j == 0)
//            break;
//    }
//    heap[0][i] = x;
//    heap[1][i] = freq;
//}
//
//void down(int** heap, int i, int n)
//{
//    int x = heap[0][i], freq = heap[1][i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[1][j + 1] < heap[1][j])
//            j++;
//
//        if (heap[1][j] > freq)
//            break;
//
//        heap[0][i] = heap[0][j];
//        heap[1][i] = heap[1][j];
//        i = j;
//    }
//    heap[0][i] = x;
//    heap[1][i] = freq;
//}
//
//void push(int** heap, int* heapSize, int n, int x, int freq)
//{
//    if (*heapSize < n)
//    {
//        heap[0][*heapSize] = x;
//        heap[1][*heapSize] = freq;
//        up(heap, *heapSize);
//        (*heapSize)++;
//    }
//    else
//    {
//        if (freq < heap[1][0])
//            return;
//
//        heap[0][0] = x;
//        heap[1][0] = freq;
//        down(heap, 0, n);
//    }
//}
//
//int* topKFrequent(int* nums, int numsSize, int k, int* returnSize)
//{
//    HashItem* cnt = NULL;
//    HashItem* p1 = NULL;
//    int capacity = 8;
//    int** arr = (int**)malloc(sizeof(int*) * capacity);
//    int size = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        HASH_FIND_INT(cnt, &nums[i], p1);
//        if (p1 == NULL)
//        {
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = nums[i];
//            p1->val = size;
//            HASH_ADD_INT(cnt, key, p1);
//
//            arr[size] = (int*)malloc(sizeof(int) * 2); // x, freq
//            arr[size][0] = nums[i]; // x
//            arr[size++][1] = 0; // freq
//            if (size >= capacity)
//            {
//                capacity *= 2;
//                arr = (int**)realloc(arr, sizeof(int*) * capacity);
//            }
//        }
//        else
//            arr[p1->val][1]++;
//    }
//
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, cnt, p1, tmp)
//    {
//        HASH_DEL(cnt, p1);
//        free(p1);
//    }
//
//    int** heap = (int**)malloc(sizeof(int*) * 2);
//    heap[0] = (int*)malloc(sizeof(int) * k); // x
//    heap[1] = (int*)malloc(sizeof(int) * k); // freq
//    int heapSize = 0;
//    for (int i = 0; i < size; i++)
//    {
//        push(heap, &heapSize, k, arr[i][0], arr[i][1]);
//    }
//
//    for (int i = 0; i < size; i++)
//    {
//        free(arr[i]);
//    }
//    free(heap[1]);
//
//    *returnSize = k;
//    return heap[0];
//}
//
