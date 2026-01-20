////1357. 每隔 n 个顾客打折
//
//typedef struct {
//    int id;
//    int n;
//    int discount;
//    int* products;
//} Cashier;
//
//
//Cashier* cashierCreate(int n, int discount, int* products, int productsSize, int* prices, int pricesSize) {
//    Cashier* obj = (Cashier*)malloc(sizeof(Cashier));
//    obj->id = 0;
//    obj->n = n;
//    obj->discount = discount;
//    obj->products = (int*)malloc(sizeof(int) * 201);
//    for (int i = 0; i < productsSize; i++) {
//        obj->products[products[i]] = prices[i];
//    }
//    return obj;
//}
//
//double cashierGetBill(Cashier* obj, int* product, int productSize, int* amount, int amountSize) {
//    double ret = 0;
//    for (int i = 0; i < productSize; i++) {
//        ret += obj->products[product[i]] * amount[i];
//    }
//    obj->id++;
//    if (obj->id % obj->n == 0)
//        return ret * (100 - obj->discount) / 100.0;
//
//    return ret;
//}
//
//void cashierFree(Cashier* obj) {
//    free(obj->products);
//    free(obj);
//}
//
///**
// * Your Cashier struct will be instantiated and called as such:
// * Cashier* obj = cashierCreate(n, discount, products, productsSize, prices, pricesSize);
// * double param_1 = cashierGetBill(obj, product, productSize, amount, amountSize);
//
// * cashierFree(obj);
//*/
//
////831. 隐藏个人信息    
//
//char* MaskEmail(char* s, int pos)
//{
//    int m = strlen(s) - pos + 10;
//    char* s1 = (char*)malloc(sizeof(char) * m);
//
//    s1[0] = s[0] < 'a' ? s[0] + 32 : s[0];
//    for (int i = 1; i < 6; i++)
//    {
//        s1[i] = '*';
//    }
//    s1[6] = s[pos - 1] < 'a' ? s[pos - 1] + 32 : s[pos - 1];
//
//    int j = 7;
//    for (int i = pos; s[i]; i++)
//    {
//        s1[j++] = s[i];
//        if (s[i] >= 'A' && s[i] <= 'Z')
//            s1[j - 1] += 32;
//    }
//    s1[j] = '\0';
//    return s1;
//}
//char* MaskTele(char* s)
//{
//    char* s1 = (char*)malloc(sizeof(char) * 13);
//    int n = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] <= '9' && s[i] >= '0')
//            s1[n++] = s[i];
//    }
//    char* s2 = (char*)malloc(sizeof(char) * 18);
//    int i = 0, j = 0;
//    if (n > 10)
//    {
//        s2[j++] = '+';
//        for (; i < n - 10; i++)
//        {
//            s2[j++] = '*';
//        }
//        s2[j++] = '-';
//    }
//    for (int i = 0; i < 6; i++)
//    {
//        s2[j++] = '*';
//        if (i % 3 == 2)
//            s2[j++] = '-';
//    }
//    for (int i = n - 4; i < n; i++)
//    {
//        s2[j++] = s1[i];
//    }
//    s2[j] = '\0';
//    return s2;
//}
//char* maskPII(char* s)
//{
//    int pos = -1; // @ postion;
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] == '@')
//        {
//            pos = i;
//            break;
//        }
//    }
//    return pos == -1 ? MaskTele(s) : MaskEmail(s, pos);
//}
//
////1093. 大样本统计
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//double* sampleStats(int* count, int countSize, int* returnSize) {
//    int tot = 0;
//    double min = 256;
//    double max = -1;
//    double mean = 0;
//    long long sum = 0;
//    double median = 0;
//    int maxCnt = 0;
//    double mode = 0;
//    for (int i = 0; i < countSize; i++)
//    {
//        if (count[i] == 0)
//            continue;
//
//        if (min > 255)
//            min = i;
//
//        max = fmax(max, i);
//        tot += count[i];
//        if (maxCnt < count[i])
//        {
//            maxCnt = count[i];
//            mode = i;
//        }
//        sum += 1ll * count[i] * i;
//    }
//    mean = 1.0 * sum / (1.0 * tot);
//    int cnt = 0;
//    int left = (tot + 1) / 2;
//    int right = (tot + 2) / 2;
//    for (int i = 0; i < countSize; i++)
//    {
//        if (count[i] == 0)
//            continue;
//        if (cnt < right && cnt + count[i] >= right)
//            median += i;
//        if (cnt < left && cnt + count[i] >= left)
//            median += i;
//        cnt += count[i];
//    }
//    median /= 2.0;
//    double* ans = (double*)malloc(sizeof(double) * 5);
//    ans[0] = min; ans[1] = max; ans[2] = mean; ans[3] = median; ans[4] = mode;
//    *returnSize = 5;
//    return ans;
//}
//
////897. 递增顺序搜索树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* cur;
//void reLine(struct TreeNode* node)
//{
//    if (node == NULL)
//        return;
//
//    reLine(node->left);
//    cur->right = node;
//    node->left = NULL;
//    cur = node;
//    reLine(node->right);
//}
//struct TreeNode* increasingBST(struct TreeNode* root) {
//    struct TreeNode* dummy = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    dummy->left = dummy->right = NULL;
//    dummy->val = -1;
//    cur = dummy;
//    reLine(root);
//    return dummy->right;
//}
//
