////1296. 划分数组为连续数字的集合
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//
//void up(int* heap, int i)
//{
//    int x = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j] <= x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//        if (j == 0)
//            break;
//    }
//    heap[i] = x;
//}
//
//void down(int* heap, int n, int i)
//{
//    int x = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1] < heap[j])
//            j++;
//
//        if (heap[j] >= x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//
//bool isPossibleDivide(int* nums, int numsSize, int k)
//{
//    HashItem* cnt = NULL;
//    HashItem* pEntry = NULL;
//    int* heap = (int*)malloc(sizeof(int) * numsSize);
//    int heapSize = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        HASH_FIND_INT(cnt, &nums[i], pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = nums[i];
//            pEntry->val = 0;
//            HASH_ADD_INT(cnt, key, pEntry);
//
//            heap[heapSize++] = nums[i];
//            up(heap, heapSize - 1);
//        }
//        pEntry->val++;
//    }
//    // for(int i = 0; i < heapSize; i++)
//    // {
//    //     printf("%d ", heap[i]);
//    // }
//    // printf("\n");
//    while (heapSize > 0)
//    {
//        while (1)
//        {
//            HASH_FIND_INT(cnt, &heap[0], pEntry);
//            if (pEntry->val)
//                break;
//            heap[0] = heap[--heapSize];
//            if (heapSize == 0)
//                break;
//            down(heap, heapSize, 0);
//        }
//
//        if (heapSize == 0)
//            break;
//
//        for (int i = heap[0]; i < heap[0] + k; i++)
//        {
//            HASH_FIND_INT(cnt, &i, pEntry);
//            if (pEntry && pEntry->val)
//                pEntry->val--;
//            else
//                return false;
//        }
//    }
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, cnt, pEntry, tmp)
//    {
//        HASH_DEL(cnt, pEntry);
//        free(pEntry);
//    }
//    free(heap);
//    return true;
//}
//
////3011. 判断一个数组是否可以变为有序    
//
//int check(int x)
//{
//    int ret = 0;
//    while (x)
//    {
//        x &= x - 1;
//        ret++;
//    }
//    return ret;
//}
//bool canSortArray(int* nums, int numsSize)
//{
//    int pre = 0, min = 256, max = 0, bit = 0;
//    for (int i = 0; i <= numsSize; i++)
//    {
//        int new = i == numsSize ? -1 : check(nums[i]);
//        if (new != bit)
//        {
//            if (min < pre)
//                return false;
//
//            bit = new;
//            pre = max;
//            min = 256;
//            max = 0;
//        }
//        if (i < numsSize)
//        {
//            max = fmax(nums[i], max);
//            min = fmin(nums[i], min);
//        }
//    }
//    return true;
//}
//
////1904. 你完成的完整对局数
//
//int getTime(char* s)
//{
//    char* s1 = strtok(s, ":");
//    int ret = atoi(s1) * 60;
//    s1 = strtok(NULL, ":");
//    ret += atoi(s1);
//    return ret;
//}
//int numberOfRounds(char* loginTime, char* logoutTime)
//{
//    int time1 = getTime(loginTime), time2 = getTime(logoutTime);
//    int match1 = (time1 + 14) / 15, match2 = time2 / 15;
//    int ans = match2 - match1;
//    return time1 > time2 ? ans + 96 : fmax(ans, 0);
//}
//
////998. 最大二叉树 II
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* insertIntoMaxTree(struct TreeNode* root, int val)
//{
//    if (root == NULL || val > root->val)
//    {
//        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//        node->val = val;
//
//        node->left = root;
//        node->right = NULL;
//
//        return node;
//    }
//
//    root->right = insertIntoMaxTree(root->right, val);
//
//    return root;
//}
//
