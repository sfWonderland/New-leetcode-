////295. 数据流的中位数
//
//void upL(int* heap, int n, int i)
//{
//    int x = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j] >= x)
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
//void upR(int* heap, int n, int i)
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
//void downL(int* heap, int n, int i)
//{
//    int x = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1] > heap[j])
//            j++;
//        if (heap[j] <= x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//
//void downR(int* heap, int n, int i)
//{
//    int x = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1] < heap[j])
//            j++;
//        if (heap[j] >= x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//
//typedef struct
//{
//    int* heapL; //MaxHeap
//    int left;
//    int* heapR; //MinHeap
//    int right;
//} MedianFinder;
//
//
//MedianFinder* medianFinderCreate()
//{
//    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
//    obj->heapL = (int*)malloc(sizeof(int) * 25000);
//    obj->left = 0;
//    obj->heapR = (int*)malloc(sizeof(int) * 25000);
//    obj->right = 0;
//    return obj;
//}
//
//void medianFinderAddNum(MedianFinder* obj, int num)
//{
//    if (obj->left == obj->right)
//    {
//        //将num加入右最小堆
//        obj->heapR[obj->right] = num;
//        obj->right++;
//        upR(obj->heapR, obj->right, obj->right - 1);
//        //将右最小堆堆顶元素加入左最大堆
//        obj->heapL[obj->left] = obj->heapR[0];
//        obj->left++;
//        upL(obj->heapL, obj->left, obj->left - 1);
//        //将右最小堆堆顶移除堆
//        obj->heapR[0] = obj->heapR[--obj->right];
//        downR(obj->heapR, obj->right, 0);
//    }
//    else
//    {
//        //将num加入左最大堆
//        obj->heapL[obj->left] = num;
//        obj->left++;
//        upL(obj->heapL, obj->left, obj->left - 1);
//        //将左最大堆堆顶元素加入右最小堆
//        obj->heapR[obj->right] = obj->heapL[0];
//        obj->right++;
//        upR(obj->heapR, obj->right, obj->right - 1);
//        //将左最大堆堆顶移除堆
//        obj->heapL[0] = obj->heapL[--obj->left];
//        downL(obj->heapL, obj->left, 0);
//    }
//}
//
//double medianFinderFindMedian(MedianFinder* obj)
//{
//    if (obj->left > obj->right)
//        return obj->heapL[0];
//    else
//        return 1.0 * (obj->heapL[0] + obj->heapR[0]) / 2;
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
////984. 不含 AAA 或 BBB 的字符串
//
//char* strWithout3a3b(int a, int b)
//{
//    char* ans = (char*)malloc(sizeof(char) * (a + b + 1));
//    ans[0] = '\0';
//    ans[a + b] = '\0';
//    while (a + b)
//    {
//        if (a > b)
//        {
//            if (a > 1)
//            {
//                a -= 2;
//                strcat(ans, "aa");
//                if (b)
//                {
//                    b--;
//                    strcat(ans, "b");
//                }
//            }
//            else
//            {
//                a--;
//                strcat(ans, "a");
//            }
//        }
//        else if (a < b)
//        {
//            if (b > 1)
//            {
//                b -= 2;
//                strcat(ans, "bb");
//                if (a)
//                {
//                    a--;
//                    strcat(ans, "a");
//                }
//            }
//            else
//            {
//                b--;
//                strcat(ans, "b");
//            }
//        }
//        else
//        {
//            strcat(ans, "ab");
//            a--;
//            b--;
//        }
//    }
//    return ans;
//}
//
////3545. 不同字符数量最多为 K 时的最少删除数
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int minDeletion(char* s, int k)
//{
//    int n = strlen(s);
//    int* cnt = (int*)calloc(sizeof(int), 26);
//    for (int i = 0; i < n; i++)
//    {
//        cnt[s[i] - 'a']++;
//    }
//    qsort(cnt, 26, sizeof(int), cmp);
//    for (int i = 0; i < k; i++)
//    {
//        n -= cnt[i];
//    }
//    free(cnt);
//    return n;
//}
//
////1481. 不同整数的最少数目
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//
//int cmp(const void* e1, const void* e2)
//{
//    return ((HashItem*)e1)->val - ((HashItem*)e2)->val;
//}
//
//int findLeastNumOfUniqueInts(int* arr, int arrSize, int k)
//{
//    HashItem* cnt = NULL;
//    HashItem* pEntry = NULL;
//    for (int i = 0; i < arrSize; i++)
//    {
//        HASH_FIND_INT(cnt, &arr[i], pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = arr[i];
//            pEntry->val = 1;
//            HASH_ADD_INT(cnt, key, pEntry);
//        }
//        else
//            pEntry->val++;
//    }
//    HASH_SORT(cnt, cmp);
//    int ans = 0;
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, cnt, pEntry, tmp)
//    {
//        if (pEntry->val <= k)
//            k -= pEntry->val;
//        else
//            ans++;
//        free(pEntry);
//    }
//    return ans;
//}
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//
//int findLeastNumOfUniqueInts(int* arr, int arrSize, int k)
//{
//    qsort(arr, arrSize, sizeof(int), cmp);
//    int* freq = (int*)malloc(sizeof(int) * arrSize);
//    int idx = 0;
//    freq[idx] = 1;
//    for (int i = 1; i < arrSize; i++)
//    {
//        if (arr[i] == arr[i - 1])
//            freq[idx]++;
//        else
//            freq[++idx] = 1;
//    }
//    qsort(freq, idx + 1, sizeof(int), cmp);
//    int i = 0;
//    for (; i <= idx; i++)
//    {
//        if (freq[i] <= k)
//            k -= freq[i];
//        else
//            break;
//    }
//    return idx + 1 - i;
//}
//
