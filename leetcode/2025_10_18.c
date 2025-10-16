////49. 字母异位词分组
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    char* key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(char*)e1 - *(char*)e2;
//}
//
//char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes)
//{
//    char*** ans = (char***)malloc(sizeof(char**) * strsSize);
//    *returnColumnSizes = (int*)calloc(sizeof(int), strsSize);
//    int idx = 0;
//    HashItem* hash = NULL;
//    HashItem* tmp = NULL;
//    for (int i = 0; i < strsSize; i++)
//    {
//        int n = strlen(strs[i]);
//        char* s = (char*)malloc(sizeof(char) * (n + 1));
//        strcpy(s, strs[i]);
//        qsort(s, n, sizeof(char), cmp);
//        HASH_FIND_STR(hash, s, tmp);
//        if (tmp == NULL)
//        {
//            tmp = (HashItem*)malloc(sizeof(HashItem));
//            tmp->key = s;
//            tmp->val = idx;
//            ans[idx++] = (char**)malloc(sizeof(char*) * strsSize);
//            HASH_ADD_STR(hash, key, tmp);
//        }
//        ans[tmp->val][(*returnColumnSizes)[tmp->val]++] = strs[i];
//    }
//    HashItem* tm = NULL;
//    HASH_ITER(hh, hash, tmp, tm)
//    {
//        HASH_DEL(hash, tmp);
//        free(tmp);
//    }
//    *returnSize = idx;
//    return ans;
//}
//
////215. 数组中的第K个最大元素
//
//void down(int* nums, int n, int i)
//{
//    int x = nums[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && nums[j + 1] > nums[j])
//            j++;
//        if (nums[j] <= x)
//            break;
//        nums[i] = nums[j];
//        i = j;
//    }
//    nums[i] = x;
//}
//void BuildMaxHeap(int* nums, int n)
//{
//    for (int i = n / 2 - 1; i >= 0; i--)
//    {
//        down(nums, n, i);
//    }
//}
//void HeapSort(int* nums, int n)
//{
//    BuildMaxHeap(nums, n);
//    for (int i = n - 1; i > 0; i--)
//    {
//        down(nums, i, 0);
//    }
//}
//// void swap(int* nums, int i, int j)
//// {
////     int tmp = nums[i];
////     nums[i] = nums[j];
////     nums[j] = tmp;
//// }
//int findKthLargest(int* nums, int numsSize, int k)
//{
//    HeapSort(nums, numsSize);
//    int i = 0;
//    while (i < k - 1)
//    {
//        nums[0] = -10001;
//        down(nums, numsSize, 0);
//        i++;
//    }
//    return nums[0];
//}
//
////109. 有序链表转换二叉搜索树
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     struct TreeNode *left;
//  *     struct TreeNode *right;
//  * };
//  */
//struct TreeNode* sortedListToBST(struct ListNode* head)
//{
//    if (head == NULL)
//        return NULL;
//    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    if (head->next == NULL)
//    {
//        root->val = head->val;
//        root->left = NULL;
//        root->right = NULL;
//        return root;
//    }
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//    struct ListNode* pre = NULL;
//    while (fast && fast->next)
//    {
//        pre = slow;
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    pre->next = NULL;
//    root->val = slow->val;
//    root->left = sortedListToBST(head);
//    root->right = sortedListToBST(slow->next);
//    return root;
//}
//
////299. 猜数字游戏
//
//void reverse(char* s, int l, int r)
//{
//    while (l < r)
//    {
//        char tmp = s[l];
//        s[l++] = s[r];
//        s[r--] = tmp;
//    }
//}
//char* getHint(char* secret, char* guess)
//{
//    int cnt[11] = { 0 };
//    int a = 0;
//    for (int i = 0; secret[i]; i++)
//    {
//        if (secret[i] != guess[i])
//            cnt[secret[i] - '0']++;
//        else
//        {
//            a++;
//            guess[i] = '0' + 10;
//        }
//    }
//    int b = 0;
//    for (int i = 0; guess[i]; i++)
//    {
//        if (cnt[guess[i] - '0'])
//        {
//            cnt[guess[i] - '0']--;
//            b++;
//        }
//    }
//    char* ans = (char*)malloc(sizeof(char) * 9);
//    sprintf(ans, "%dA%dB", a, b);
//    return ans;
//}
//
