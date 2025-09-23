////166. 分数到小数
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}Hash;
//void reverse(char* s, int l, int r)
//{
//    while (l < r)
//    {
//        char tmp = s[l];
//        s[l++] = s[r];
//        s[r--] = tmp;
//    }
//}
//void to_string(char* s, int* idx, long long x)
//{
//    int pre = *idx;
//    while (x)
//    {
//        s[(*idx)++] = x % 10 + '0';
//        x /= 10;
//    }
//    reverse(s, pre, (*idx) - 1);
//}
//char* fractionToDecimal(int numerator, int denominator)
//{
//    char* ans = (char*)malloc(sizeof(char) * 10000);
//    long long a = numerator, b = denominator;
//    int idx = 0;
//    if (a* b < 0)
//        ans[idx++] = '-';
//    a = a > 0 ? a : -a;
//    b = b > 0 ? b : -b;;
//    long long q = a / b, r = a % b;
//    if (q > 0)
//        to_string(ans, &idx, q);
//    else
//        ans[idx++] = '0';
//    if (r == 0)
//    {
//        ans[idx] = '\0';
//        return ans;
//    }
//    ans[idx++] = '.';
//    Hash* hash = NULL;
//    Hash* tmp = NULL;
//    while (r)
//    {
//        r *= 10;
//        q = r / b;
//        HASH_FIND_INT(hash, &r, tmp);
//        if (tmp == NULL)
//        {
//            tmp = (Hash*)malloc(sizeof(Hash));
//            tmp->key = r;
//            tmp->val = idx;
//            HASH_ADD_INT(hash, key, tmp);
//        }
//        else
//        {
//            int pre = tmp->val;
//            for (int i = idx; i > pre; i--)
//            {
//                ans[i] = ans[i - 1];
//            }
//            ans[pre] = '(';
//            ans[++idx] = ')';
//            ++idx;
//            break;
//        }
//        r %= b;
//        //printf("%lld ", r);
//        ans[idx++] = '0' + q;
//    }
//    Hash* s = NULL;
//    HASH_ITER(hh, hash, tmp, s)
//    {
//        HASH_DEL(hash, tmp);
//        free(tmp);
//    }
//    ans[idx] = '\0';
//    return ans;
//}
//
////974. 和可被 K 整除的子数组
//
//int subarraysDivByK(int* nums, int numsSize, int k)
//{
//    int hash[k];
//    memset(hash, 0, sizeof(hash));
//    hash[0] = 1;
//    int sum = 0, ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum = (sum + nums[i] + 5000 * k) % k;
//        ans += hash[sum]++;
//    }
//    return ans;
//}
//
////523. 连续的子数组和
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}Hash;
//
//bool checkSubarraySum(int* nums, int numsSize, int k)
//{
//    Hash* hash = NULL;
//    Hash* tmp = (Hash*)malloc(sizeof(Hash));
//    tmp->key = 0;
//    tmp->val = -1;
//    HASH_ADD_INT(hash, key, tmp);
//    int sum = 0;
//    bool flag = false;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum = (sum + nums[i]) % k;
//        sum = sum >= 0 ? sum : k + sum;
//        HASH_FIND_INT(hash, &sum, tmp);
//        if (tmp == NULL)
//        {
//            tmp = (Hash*)malloc(sizeof(Hash));
//            tmp->key = sum;
//            tmp->val = i;
//            HASH_ADD_INT(hash, key, tmp);
//        }
//        else if (i - tmp->val >= 2)
//        {
//            flag = true;
//            break;
//        }
//    }
//    Hash* s = NULL;
//    HASH_ITER(hh, hash, tmp, s)
//    {
//        HASH_DEL(hash, tmp);
//        free(tmp);
//    }
//    return flag;
//}
//
////437. 路径总和 III
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
//int dfs(struct TreeNode* node, int targetSum, long long sum)
//{
//    if (node == NULL)
//        return 0;
//
//    sum = sum + node->val;
//    return (sum == targetSum) + dfs(node->left, targetSum, sum) + dfs(node->right, targetSum, sum);
//}
//int pathSum(struct TreeNode* root, int targetSum)
//{
//    if (root == NULL)
//        return 0;
//
//    return dfs(root, targetSum, (long long)0) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
//}
//
