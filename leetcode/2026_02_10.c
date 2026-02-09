////515. 在每个树行中找最大值
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//int* largestValues(struct TreeNode* root, int* returnSize)
//{
//    if (root == NULL)
//    {
//        *returnSize = 0;
//        return NULL;
//    }
//    int capacity = 64;
//    int* ans = (int*)malloc(sizeof(int) * 10000);
//    struct TreeNode* queue[10000];
//    int front = 0, rear = 0;
//    queue[rear++] = root;
//    int depth = 0;
//    while (rear > front)
//    {
//        int start = front;
//        front = rear;
//        int max = INT_MIN;
//        for (int i = start; i < front; i++)
//        {
//            max = fmax(max, queue[i]->val);
//            if (queue[i]->left) queue[rear++] = queue[i]->left;
//            if (queue[i]->right) queue[rear++] = queue[i]->right;
//        }
//        ans[depth++] = max;
//    }
//    *returnSize = depth;
//    return ans;
//}
//
////508. 出现次数最多的子树元素和    
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int* findFrequentTreeSum(struct TreeNode* root, int* returnSize)
//{
//    HashItem* cnt = NULL;
//    int maxCnt = 0;
//    int dfs(struct TreeNode* node)
//    {
//        if (node == NULL)
//            return 0;
//
//        int sum = node->val + dfs(node->left) + dfs(node->right);
//        HashItem* p1 = NULL;
//        HASH_FIND_INT(cnt, &sum, p1);
//        if (p1 == NULL)
//        {
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = sum;
//            p1->val = 0;
//            HASH_ADD_INT(cnt, key, p1);
//        }
//        p1->val++;
//        maxCnt = fmax(p1->val, maxCnt);
//        return sum;
//    }
//    dfs(root);
//    int n = HASH_COUNT(cnt);
//    int* ans = (int*)malloc(sizeof(int) * n);
//    int idx = 0;
//    for (HashItem* p1 = cnt; p1; p1 = p1->hh.next)
//    {
//        if (p1->val == maxCnt)
//            ans[idx++] = p1->key;
//    }
//    HashItem* cur, * tmp;
//    HASH_ITER(hh, cnt, cur, tmp)
//    {
//        HASH_DEL(cnt, cur);
//        free(cur);
//    }
//    *returnSize = idx;
//    return ans;
//}
//
////468. 验证IP地址
//
//bool check4(char* ip)
//{
//    int m = strlen(ip);
//    if (ip[0] == '.' || ip[m - 1] == '.')
//        return false;
//    int cnt = 0, j = 0;
//    for (int i = 0; i < m; i = j)
//    {
//        while (ip[j] != '.' && ip[j])
//        {
//            if (ip[j] > '9')
//                return false;
//            if (ip[j] == '0' && (ip[j + 1] != '.' && ip[j + 1]) && (j - 1 < 0 || ip[j - 1] == '.'))
//                return false;
//            j++;
//        }
//
//        if (ip[j] && ip[j + 1] == '.')
//            return false;
//
//        int n = j - i;
//        if (n > 3) return false;
//
//        char tmp = ip[j];
//        ip[j] = '\0';
//        int x = atoi(ip + i);
//        ip[j++] = tmp;
//        if (x > 255) return false;
//        cnt++;
//    }
//    return cnt == 4;
//}
//bool check6(char* ip)
//{
//    int m = strlen(ip);
//    if (ip[0] == ':' || ip[m - 1] == ':')
//        return false;
//    int cnt = 0, j = 0;
//    for (int i = 0; i < m; i = j)
//    {
//        while (ip[j] != ':' && ip[j])
//        {
//            //printf("%c ", ip[j]);
//            if (!((ip[j] >= '0' && ip[j] <= '9') || (ip[j] >= 'A' && ip[j] <= 'F') || (ip[j] >= 'a' && ip[j] <= 'f')))
//                return false;
//            j++;
//        }
//
//        //printf("%c ", ip[j]);
//        if (ip[j] && ip[j + 1] == ':')
//            return false;
//
//        int n = j - i;
//        //printf("%d\n", n);
//        if (n < 1 || n > 4)
//            return false;
//        j++;
//        cnt++;
//    }
//    return cnt == 8;
//}
//char* validIPAddress(char* queryIP)
//{
//    if (strstr(queryIP, ".") && check4(queryIP)) return "IPv4";
//    if (strstr(queryIP, ":") && check6(queryIP)) return "IPv6";
//    return "Neither";
//}
//
////581. 最短无序连续子数组
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int findUnsortedSubarray(int* nums, int numsSize)
//{
//    int nums1[numsSize];
//    memcpy(nums1, nums, sizeof(nums1));
//    qsort(nums1, numsSize, sizeof(int), cmp);
//    int left = 0, right = numsSize - 1;
//    while (left <= right)
//    {
//        if (nums1[left] == nums[left])
//            left++;
//        else
//            break;
//    }
//    while (left <= right)
//    {
//        if (nums1[right] == nums[right])
//            right--;
//        else
//            break;
//    }
//    return right - left + 1;
//}
//
//int findUnsortedSubarray(int* nums, int numsSize)
//{
//    int i = 0, j = numsSize - 1;
//    while (i < j && nums[i] <= nums[i + 1]) i++;
//    while (i < j && nums[j - 1] <= nums[j]) j--;
//    for (int k = i; k <= j; k++)
//    {
//        while (i >= 1 && nums[k] < nums[i - 1]) i--;
//        while (j < numsSize - 1 && nums[k] > nums[j + 1]) j++;
//    }
//    return i == j ? 0 : j - i + 1;
//}
//
