//// 面试题 17.17. 多次搜索
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** multiSearch(char* big, char** smalls, int smallsSize, int* returnSize, int** returnColumnSizes)
//{
//    int n = smallsSize;
//    int** ans = (int**)malloc(sizeof(int*) * n);
//    *returnSize = n;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
//    int len = strlen(big);
//    for (int i = 0; i < n; i++)
//    {
//        char* s2 = smalls[i], * s1 = big;
//        int m = strlen(s2);
//        (*returnColumnSizes)[i] = 0;
//        if (m == 0)
//            continue;
//        ans[i] = (int*)malloc(sizeof(int) * len);
//        char* p = NULL;
//        while (p = strstr(s1, s2))
//        {
//            ans[i][(*returnColumnSizes)[i]++] = p - big;
//            s1 = p + 1;
//        }
//    }
//    return ans;
//}
//
//// 面试题 17.18. 最短超串    
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int* shortestSeq(int* big, int bigSize, int* small, int smallSize, int* returnSize)
//{
//    HashItem* nums = NULL;
//    for (int i = 0; i < smallSize; i++)
//    {
//        HashItem* p1 = NULL;
//        p1 = (HashItem*)malloc(sizeof(HashItem));
//        p1->key = small[i];
//        p1->val = 0;
//        HASH_ADD_INT(nums, key, p1);
//    }
//    int len = bigSize + 1, left = 0, cnt = 0;
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    for (int i = 0; i < bigSize; i++)
//    {
//        HashItem* p1 = NULL;
//        HASH_FIND_INT(nums, &big[i], p1);
//        if (p1 == NULL)
//            continue;
//
//        cnt += (p1->val == 0);
//        p1->val++;
//        if (cnt < smallSize)
//            continue;
//        while (cnt == smallSize)
//        {
//            // printf("%d ", left);
//            HASH_FIND_INT(nums, &big[left], p1);
//            left++;
//            if (p1 == NULL)
//                continue;
//
//            p1->val--;
//            cnt -= (p1->val == 0);
//        }
//        // printf("\n");
//        if (len > i - left + 2)
//        {
//            len = i - left + 2;
//            ans[0] = left - 1;
//            ans[1] = i;
//        }
//    }
//    HashItem* p1 = NULL, * tmp = NULL;
//    HASH_ITER(hh, nums, p1, tmp)
//    {
//        HASH_DEL(nums, p1);
//        free(p1);
//    }
//    *returnSize = len <= bigSize ? 2 : 0;
//    return ans;
//}
//
//// 面试题 17.19. 消失的两个数字
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* missingTwo(int* nums, int numsSize, int* returnSize)
//{
//    int n = numsSize + 2;
//    int xorsum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        xorsum ^= nums[i];
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        xorsum ^= i;
//    }
//    int lsb = xorsum == INT_MIN ? xorsum : xorsum & (-xorsum);
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    ans[0] = ans[1] = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] & lsb)
//            ans[0] ^= nums[i];
//        else
//            ans[1] ^= nums[i];
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        if (i & lsb)
//            ans[0] ^= i;
//        else
//            ans[1] ^= i;
//    }
//    *returnSize = 2;
//    return ans;
//}
//
//// 面试题 17.20. 连续中值
//
//void up(int* heap, int i, int dir)
//{
//    int x = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if ((heap[j] - x) * dir <= 0)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//
//        if (j == 0)
//            break;
//    }
//    heap[i] = x;
//}
//
//void down(int* heap, int i, int n, int dir)
//{
//    int x = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && (heap[j + 1] - heap[j]) * dir < 0)
//            j++;
//
//        if ((heap[j] - x) * dir >= 0)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//
//void push(int* heap, int* i, int dir, int x)
//{
//    heap[*i] = x;
//    up(heap, *i, dir);
//    (*i)++;
//}
//
//int pop(int* heap, int n, int dir, int x)
//{
//    int y = heap[0];
//    heap[0] = x;
//    down(heap, 0, n, dir);
//    return y;
//}
//
//typedef struct
//{
//    int* heapL;
//    int* heapR;
//    int left;
//    int right;
//} MedianFinder;
//
///** initialize your data structure here. */
//
//MedianFinder* medianFinderCreate()
//{
//    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
//    obj->heapL = (int*)malloc(sizeof(int) * 10000);
//    obj->heapR = (int*)malloc(sizeof(int) * 10000);
//    obj->left = obj->right = 0;
//    return obj;
//}
//
//void medianFinderAddNum(MedianFinder* obj, int num)
//{
//    if (obj->left > obj->right)
//    {
//        if (num >= obj->heapL[0])
//            push(obj->heapR, &obj->right, 1, num);
//        else
//        {
//            int x = pop(obj->heapL, obj->left, -1, num);
//            push(obj->heapR, &obj->right, 1, x);
//        }
//    }
//    else
//    {
//        if (obj->right == 0 || num <= obj->heapR[0])
//            push(obj->heapL, &obj->left, -1, num);
//        else
//        {
//            int x = pop(obj->heapR, obj->right, 1, num);
//            push(obj->heapL, &obj->left, -1, x);
//        }
//    }
//}
//
//double medianFinderFindMedian(MedianFinder* obj)
//{
//    return obj->left > obj->right ? 1.0 * obj->heapL[0] : 1.0 * (obj->heapL[0] + obj->heapR[0]) / 2.0;
//}
//
//void medianFinderFree(MedianFinder* obj)
//{
//    free(obj->heapL);
//    free(obj->heapR);
//    free(obj);
//}
//
///**
// * Your MedianFinder struct will be instantiated and called as such:
// * MedianFinder* obj = medianFinderCreate();
// * medianFinderAddNum(obj, num);
//
// * double param_2 = medianFinderFindMedian(obj);
//
// * medianFinderFree(obj);
//*/
//
