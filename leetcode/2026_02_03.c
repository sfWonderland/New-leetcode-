////3637. 三段式数组 I
//
//bool isTrionic(int* nums, int numsSize)
//{
//    if (nums[1] <= nums[0])
//        return false;
//    int dir = 1, cnt = 1;
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (nums[i] == nums[i - 1])
//            return false;
//        if (dir * (nums[i] - nums[i - 1]) < 0)
//        {
//            if (cnt < 3)
//            {
//                cnt++;
//                dir = -dir;
//            }
//            else
//                return false;
//        }
//    }
//    return cnt == 3;
//}
//
////114. 二叉树展开为链表    
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//void flatten(struct TreeNode* root)
//{
//    struct TreeNode* dummy = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    dummy->right = root;
//    struct TreeNode* cur = dummy;
//    void dfs(struct TreeNode* root)
//    {
//        if (root == NULL)
//            return;
//
//        struct TreeNode* left = root->left;
//        struct TreeNode* right = root->right;
//        cur->right = root;
//        root->left = NULL;
//        cur = root;
//        dfs(left);
//        dfs(right);
//    }
//    dfs(root);
//}
//
////451. 根据字符出现频率排序
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//char* frequencySort(char* s)
//{
//    int sym[128] = { 0 };
//    for (int i = 0; i < 127; i++)
//    {
//        sym[i] = i + 1;
//    }
//    for (int i = 0; s[i]; i++)
//    {
//        sym[s[i]] += 130;
//    }
//    qsort(sym, 128, sizeof(int), cmp);
//    int k = 0;
//    for (int i = 0; sym[i] / 130; i++)
//    {
//        int d = sym[i] / 130;
//        char ch = sym[i] % 130 - 1;
//        for (int j = k; j < k + d; j++)
//        {
//            s[j] = ch;
//        }
//        k += d;
//    }
//    return s;
//}
//
////382. 链表随机节点
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
//
//
//typedef struct
//{
//    struct ListNode* head;
//} Solution;
//
//
//Solution* solutionCreate(struct ListNode* head)
//{
//    Solution* obj = (Solution*)malloc(sizeof(Solution));
//    obj->head = head;
//    return obj;
//}
//
//int solutionGetRandom(Solution* obj)
//{
//    int ans = 0, idx = 0;
//    struct ListNode* cur = obj->head;
//    while (cur)
//    {
//        idx++;
//        if (rand() % idx == 0)
//            ans = cur->val;
//
//        cur = cur->next;
//    }
//    return ans;
//}
//
//void solutionFree(Solution* obj)
//{
//    free(obj);
//}
//
///**
// * Your Solution struct will be instantiated and called as such:
// * Solution* obj = solutionCreate(head);
// * int param_1 = solutionGetRandom(obj);
//
// * solutionFree(obj);
//*/
//
