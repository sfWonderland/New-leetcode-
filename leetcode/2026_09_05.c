//// 2261. 含最多 K 个可整除元素的子数组
//
//typedef struct Node
//{
//    struct Node** son;
//    bool end;
//} Node;
//void freeTrie(Node* node, int m)
//{
//    if (node == NULL) return;
//    for (int i = 0; i < m; i++)
//    {
//        freeTrie(node->son[i], m);
//    }
//    free(node->son);
//    free(node);
//}
//int countDistinct(int* nums, int numsSize, int k, int p)
//{
//    int ans = 0, n = numsSize;
//    bool isgood[n];
//    memset(isgood, 0, sizeof(isgood));
//    int max = -1, min = 201;
//    for (int i = 0; i < n; i++)
//    {
//        min = fmin(min, nums[i]);
//        max = fmax(max, nums[i]);
//        isgood[i] = (nums[i] % p == 0);
//    }
//    int m = max - min + 1;
//    Node* root = (Node*)calloc(1, sizeof(Node));
//    root->son = (Node**)calloc(m, sizeof(Node));
//    //固定左端移动右端
//    for (int i = 0; i < n; i++)
//    {
//        int cnt = 0;
//        Node* cur = root; // 每次从根节点开始
//        for (int j = i; j < n; j++)
//        {
//            if (isgood[j]) cnt++;
//            if (cnt > k) break;
//            int c = nums[j] - min;
//            if (cur->son[c] == NULL)
//            {
//                cur->son[c] = (Node*)calloc(1, sizeof(Node));
//                cur->son[c]->son = (Node**)calloc(m, sizeof(Node));
//            }
//            cur = cur->son[c];
//            if (!cur->end) // 去重
//            {
//                ans++;
//                cur->end = true;
//            }
//        }
//    }
//    freeTrie(root, m);
//    return ans;
//}
//
