////1382. 将二叉搜索树变平衡
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* balanceBST(struct TreeNode* root)
//{
//    int capacity = 64;
//    int* nums = (int*)malloc(sizeof(int) * capacity);
//    int k = 0;
//    void dfs1(struct TreeNode* node)
//    {
//        if (node == NULL)
//            return;
//
//        dfs1(node->left);
//        nums[k++] = node->val;
//        if (k >= capacity)
//        {
//            capacity *= 2;
//            nums = realloc(nums, sizeof(int) * capacity);
//        }
//        dfs1(node->right);
//    }
//    dfs1(root);
//    struct TreeNode* dfs2(int left, int right)
//    {
//        if (left > right)
//            return NULL;
//        int mid = (left + right) / 2;
//        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//        node->val = nums[mid];
//        node->left = dfs2(left, mid - 1);
//        node->right = dfs2(mid + 1, right);
//        return node;
//    }
//    return dfs2(0, k - 1);
//}
//
////3794. 反转字符串前缀    
//
//char* reversePrefix(char* s, int k)
//{
//    int left = 0, right = k - 1;
//    while (left < right)
//    {
//        char tmp = s[left];
//        s[left++] = s[right];
//        s[right--] = tmp;
//    }
//    return s;
//}
//
////3795. 不同元素和至少为 K 的最短子数组长度
//
//int minLength(int* nums, int numsSize, int k)
//{
//    int hash[100001];
//    memset(hash, -1, sizeof(hash));
//    int l = 0, sum = 0, ans = numsSize + 1;
//    for (int r = 0; r < numsSize; r++)
//    {
//        if (hash[nums[r]] < 0)
//        {
//            sum += nums[r];
//        }
//        hash[nums[r]] = r;
//        if (sum < k)
//            continue;
//
//        while (l <= r && sum >= k)
//        {
//            if (hash[nums[l]] == l)
//            {
//                hash[nums[l]] = -1;
//                sum -= nums[l];
//            }
//            l++;
//        }
//        ans = fmin(r - l + 2, ans);
//        //printf("%d %d %d %d\n", l, r, sum, ans);
//    }
//    return ans <= numsSize ? ans : -1;
//}
//
////3796. 找到带限制序列的最大值
//
//int findMaxVal(int n, int** restrictions, int restrictionsSize, int* restrictionsColSize, int* diff, int diffSize)
//{
//    int nums[n];
//    memset(nums, 0x3f, sizeof(nums));
//    nums[0] = 0;
//    for (int i = 0; i < restrictionsSize; i++)
//    {
//        int j = restrictions[i][0], val = restrictions[i][1];
//        nums[j] = val;
//    }
//    for (int i = 1; i < n; i++)
//    {
//        nums[i] = fmin(nums[i - 1] + diff[i - 1], nums[i]);
//    }
//    int ans = nums[n - 1];
//    for (int i = n - 2; i > 0; i--)
//    {
//        nums[i] = fmin(nums[i + 1] + diff[i], nums[i]);
//        ans = fmax(nums[i], ans);
//    }
//
//    return ans;
//}
//
