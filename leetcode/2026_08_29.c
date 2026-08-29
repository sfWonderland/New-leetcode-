//// 2948. 交换得到字典序最小的数组
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* arr;
//int cmp1(const void* e1, const void* e2)
//{
//    return arr[*(int*)e1] - arr[*(int*)e2];
//}
//int cmp2(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int* lexicographicallySmallestArray(int* nums, int numsSize, int limit, int* returnSize)
//{
//    int n = numsSize;
//    int pos[n];
//    for (int i = 0; i < n; i++)
//    {
//        pos[i] = i;
//    }
//    arr = nums;
//    qsort(pos, n, sizeof(int), cmp1);
//    int* ans = (int*)malloc(sizeof(int) * n);
//    int start = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (i == n - 1 || nums[pos[i + 1]] - nums[pos[i]] > limit)
//        {
//            int len = i - start + 1;
//            int sub_pos[len];
//            for (int j = 0; j < len; j++)
//            {
//                sub_pos[j] = pos[start + j];
//            }
//            qsort(sub_pos, len, sizeof(int), cmp2);
//            for (int j = 0; j < len; j++)
//            {
//                ans[sub_pos[j]] = nums[pos[start + j]];
//            }
//            start = i + 1;
//        }
//    }
//    *returnSize = n;
//    return ans;
//}
//
//// 3043. 最长公共前缀的长度 
//
//typedef struct Node
//{
//    struct Node* son[10];
//}Node;
//
//void getNums(int* nums, int* len, int x)
//{
//    while (x)
//    {
//        nums[(*len)++] = x % 10;
//        x /= 10;
//    }
//}
//
//void trieInsert(Node* root, int* nums, int n)
//{
//    Node* cur = root;
//    for (int j = n - 1; j >= 0; j--)
//    {
//        int c = nums[j];
//        if (cur->son[c] == NULL)
//        {
//            cur->son[c] = (Node*)calloc(1, sizeof(Node));
//        }
//        cur = cur->son[c];
//    }
//}
//
//int getLength(Node* root, int* nums, int n)
//{
//    Node* cur = root;
//    int sum = n;
//    for (int j = n - 1; j >= 0; j--)
//    {
//        int c = nums[j];
//        if (cur->son[c] == NULL)
//        {
//            sum = n - 1 - j;
//            break;
//        }
//        cur = cur->son[c];
//    }
//    return sum;
//}
//
//void freeTrie(Node* node)
//{
//    if (node == NULL) return;
//    for (int i = 0; i < 10; i++)
//    {
//        freeTrie(node->son[i]);
//    }
//    free(node);
//}
//
//int longestCommonPrefix(int* arr1, int arr1Size, int* arr2, int arr2Size)
//{
//    Node* root = (Node*)calloc(1, sizeof(Node));
//    int* nums = (int*)malloc(sizeof(int) * 9);
//    for (int i = 0; i < arr1Size; i++)
//    {
//        int m = 0;
//        getNums(nums, &m, arr1[i]);
//        trieInsert(root, nums, m);
//    }
//    int ans = 0;
//    for (int i = 0; i < arr2Size; i++)
//    {
//        int m = 0;
//        getNums(nums, &m, arr2[i]);
//        ans = fmax(getLength(root, nums, m), ans);
//    }
//    freeTrie(root);
//    return ans;
//}
//
