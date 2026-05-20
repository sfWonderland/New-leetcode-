//// 470. 用 Rand7() 实现 Rand10()
//
//// The rand7() API is already defined for you.
//// int rand7();
//// @return a random integer in the range 1 to 7
//
//int rand10()
//{
//    int row, col;
//    while ((row = rand7()) > 6);
//    while ((col = rand7()) > 5);
//    return row & 1 ? col : col + 5;
//}
//
//// The rand7() API is already defined for you.
//// int rand7();
//// @return a random integer in the range 1 to 7
//
//int rand10()
//{
//    int ans = 0;
//    do
//    {
//        int x = rand7();
//        int y = rand7();
//        ans = (x - 1) * 7 + (y - 1);
//    } while (ans >= 40);
//    return 1 + ans % 10;
//}
//
//// 3043. 最长公共前缀的长度   
//
//typedef struct
//{
//    int key;
//    UT_hash_handle hh;
//}HashItem;
//int longestCommonPrefix(int* arr1, int arr1Size, int* arr2, int arr2Size)
//{
//    HashItem* pre = NULL;
//    for (int i = 0; i < arr1Size; i++)
//    {
//        int x = arr1[i];
//        HashItem* p1 = NULL;
//        while (x)
//        {
//            HASH_FIND_INT(pre, &x, p1);
//            if (p1 == NULL)
//            {
//                p1 = (HashItem*)malloc(sizeof(HashItem));
//                p1->key = x;
//                HASH_ADD_INT(pre, key, p1);
//            }
//            x /= 10;
//        }
//    }
//    int ans = 0;
//    for (int i = 0; i < arr2Size; i++)
//    {
//        int x = arr2[i];
//        HashItem* p1 = NULL;
//        while (x > ans)
//        {
//            HASH_FIND_INT(pre, &x, p1);
//            if (p1)
//                ans = x;
//            x /= 10;
//        }
//    }
//    HashItem* p1 = NULL, * tmp = NULL;
//    HASH_ITER(hh, pre, p1, tmp)
//    {
//        HASH_DEL(pre, p1);
//        free(p1);
//    }
//    if (ans == 0)
//        return 0;
//    int len = 0;
//    while (ans)
//    {
//        len++;
//        ans /= 10;
//    }
//    return len;
//}
//
//// 900. RLE 迭代器
//
//typedef struct
//{
//    int* encoding;
//    int n;
//    int p;
//} RLEIterator;
//
//
//RLEIterator* rLEIteratorCreate(int* encoding, int encodingSize)
//{
//    RLEIterator* obj = (RLEIterator*)malloc(sizeof(RLEIterator));
//    obj->encoding = encoding;
//    obj->n = encodingSize;
//    obj->p = 0;
//    while (encoding[obj->p] == 0)
//    {
//        obj->p += 2;
//    }
//    return obj;
//}
//
//int rLEIteratorNext(RLEIterator* obj, int n)
//{
//    int res = -1;
//    while (obj->p < obj->n && n)
//    {
//        if (obj->encoding[obj->p] >= n)
//        {
//            obj->encoding[obj->p] -= n;
//            res = obj->encoding[obj->p + 1];
//            n = 0;
//        }
//        else
//        {
//            n -= obj->encoding[obj->p];
//            obj->encoding[obj->p] = 0;
//            while (obj->p < obj->n && obj->encoding[obj->p] == 0)
//                obj->p += 2;
//        }
//    }
//    return res;
//}
//
//void rLEIteratorFree(RLEIterator* obj)
//{
//    free(obj);
//}
//
///**
// * Your RLEIterator struct will be instantiated and called as such:
// * RLEIterator* obj = rLEIteratorCreate(encoding, encodingSize);
// * int param_1 = rLEIteratorNext(obj, n);
//
// * rLEIteratorFree(obj);
//*/
//
//// 937. 重新排列日志文件
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    char* log;
//    int idx;
//} Pair;
//int cmp(const void* e1, const void* e2)
//{
//    char* s1 = ((Pair*)e1)->log;
//    char* s2 = ((Pair*)e2)->log;
//    char* split1 = strstr(s1, " ");
//    char* split2 = strstr(s2, " ");
//    bool isDigit1 = isdigit(split1[1]);
//    bool isDigit2 = isdigit(split2[1]);
//    if (isDigit1 && isDigit2)
//        return ((Pair*)e1)->idx - ((Pair*)e2)->idx;
//    else if (!isDigit1 && !isDigit2)
//    {
//        int sc = strcmp(split1, split2);
//        if (sc)
//            return sc;
//        return strcmp(s1, s2);
//    }
//
//    return isDigit1 ? 1 : -1;
//}
//char** reorderLogFiles(char** logs, int logsSize, int* returnSize)
//{
//    Pair* arr = (Pair*)malloc(sizeof(Pair) * logsSize);
//    for (int i = 0; i < logsSize; i++)
//    {
//        arr[i].log = logs[i];
//        arr[i].idx = i;
//    }
//    qsort(arr, logsSize, sizeof(Pair), cmp);
//    char** ans = (char**)malloc(sizeof(char*) * logsSize);
//    for (int i = 0; i < logsSize; i++)
//    {
//        ans[i] = arr[i].log;
//    }
//    free(arr);
//    *returnSize = logsSize;
//    return ans;
//}
//
