////11. 盛最多水的容器
//
//int maxArea(int* height, int heightSize)
//{
//    int left = 0;
//    int right = heightSize - 1;
//    int max = 0;
//    while (left < right)
//    {
//        max = fmax(max, fmin(height[left], height[right]) * (right - left));
//        if (height[left] < height[right])
//            left++;
//        else
//            right--;
//    }
//    return max;
//}
//
////12. 整数转罗马数字
//
//// char* reverse(char* s, int left, int right)
//// {
////     while(left < right)
////     {
////         char tmp = s[left];
////         s[left] = s[right];
////         s[right] = tmp;
////         left++;
////         right--;
////     }
////     return s;
//// }
//// char* intToRoman(int num) 
//// {
////     char* ret = (char*)malloc(sizeof(char) * 16);
////     int i = 0;
////     char nums[] = "IVXLCDM"; 
////     int k = 0;
////     while(num)
////     {
////         int t = num % 10;
////         switch(t)
////         {
////             case 9: ret[i++] = nums[k + 2]; ret[i++] = nums[k]; break;
////             case 8: ret[i++] = nums[k]; 
////             case 7: ret[i++] = nums[k];
////             case 6: ret[i++] = nums[k];
////             case 5: ret[i++] = nums[k + 1]; break;
////             case 4: ret[i++] = nums[k + 1]; ret[i++] = nums[k]; break;
////             case 3: ret[i++] = nums[k];
////             case 2: ret[i++] = nums[k];
////             case 1: ret[i++] = nums[k];
////         }
////         k += 2;
////         num /= 10;
////     }    
////     ret[i] = '\0';
////     ret = reverse(ret, 0, i - 1);
////     return ret;
//// }
//const char* R[4][10] =
//{
//    {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}, //个位
//    {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, //十位
//    {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, //百位
//    {"", "M", "MM", "MMM"}, //千位
//};
//
//char* intToRoman(int num)
//{
//    char* ans = malloc(16);
//    strcpy(ans, R[3][num / 1000]);
//    strcat(ans, R[2][num / 100 % 10]);
//    strcat(ans, R[1][num / 10 % 10]);
//    strcat(ans, R[0][num % 10]);
//    return ans;
//}
//
////62. 不同路径
//
//int uniquePaths(int m, int n)
//{
//    long long ans = 1;
//    int t = fmin(m - 1, n - 1);
//    for (int i = 1; i <= t; i++)
//    {
//        ans = ans * (m + n - 2 - i + 1) / i;
//    }
//    return ans;
//}
//
////94. 二叉树的中序遍历
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
//void Traversal(struct TreeNode* root, int* nums, int* n)
//{
//    if (root == NULL)
//        return;
//    Traversal(root->left, nums, n);
//    nums[(*n)++] = root->val;
//    Traversal(root->right, nums, n);
//}
//int* inorderTraversal(struct TreeNode* root, int* returnSize)
//{
//    int* ret = (int*)malloc(sizeof(int) * 100);
//    *returnSize = 0;
//    Traversal(root, ret, returnSize);
//    return ret;
//}
//
