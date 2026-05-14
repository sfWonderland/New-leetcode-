//// 面试题 10.01. 合并排序的数组
//
//void merge(int* A, int ASize, int m, int* B, int BSize, int n)
//{
//    int right = ASize - 1, j = n - 1; // end of A, end of B
//    for (int i = m - 1; i >= 0; i--) // end of A
//    {
//        while (j >= 0 && B[j] > A[i])
//        {
//            A[right--] = B[j--];
//        }
//        A[right--] = A[i];
//    }
//    while (j >= 0)
//    {
//        A[right--] = B[j--];
//    }
//}
//
//// 面试题 10.02. 变位词组    
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    char* key;
//    int val1;
//    int val2;
//    UT_hash_handle hh;
//}HashItem;
//int cmp(const void* e1, const void* e2)
//{
//    return *(char*)e1 - *(char*)e2;
//}
//char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes)
//{
//    int n = strsSize;
//    char*** ans = (char***)malloc(sizeof(char**) * n);
//    *returnColumnSizes = (int*)calloc(sizeof(int), n);
//    *returnSize = 0;
//    //ans[i] = (char**)malloc(sizeof(char*) * n);
//    HashItem* cnt = NULL;
//    HashItem* p1 = NULL;
//    for (int i = 0; i < n; i++)
//    {
//        int m = strlen(strs[i]);
//        char* s = (char*)malloc(sizeof(char) * (m + 1));
//        strcpy(s, strs[i]);
//        qsort(s, m, sizeof(char), cmp);
//        HASH_FIND_STR(cnt, s, p1);
//        if (p1 == NULL)
//        {
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = s;
//            p1->val1 = *returnSize;
//            p1->val2 = 0;
//            HASH_ADD_STR(cnt, key, p1);
//            ans[(*returnSize)++] = (char**)malloc(sizeof(char*) * n);
//        }
//        ans[p1->val1][p1->val2++] = strs[i];
//        (*returnColumnSizes)[p1->val1]++;
//    }
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, cnt, p1, tmp)
//    {
//        HASH_DEL(cnt, p1);
//        free(p1);
//    }
//    return ans;
//}
//
//// 面试题 10.03. 搜索旋转数组
//
//int search(int* arr, int arrSize, int target)
//{
//    int n = arrSize;
//    int left = 0, right = n - 1;
//    while (left <= right)
//    {
//        // 一定是最左边的数，所以直接返回即可
//        // 如果开始就满足条件，那么left等于0，故一定成立
//        // 如果是中途，那么上一轮可能的情况为：
//        // 1. arr[mid]与arr[0]相同，详细可以看循环最后一行left++处的注释，这种情况下，target一定在上一轮mid的左边，而mid右边一定都是arr[0]，所以一定重复left + 1, 实质上转化为了left从左到右O(n)遍历，所以一定是先遇到第一个等于target的数组值。
//        // 2. arr[mid] == target，或者target在右半边，该轮left与上一轮相同，不可能；
//        // 3. 若target在左半边，则该轮与上一轮left相同，不可能；若在右半边，arr[left - 1]不等于target，而arr[left]等于target，left一定是第一个等于target的数的索引下标。
//        // 综上，arr[left] == target, left一定是第一个等于target的数的索引下标。
//        // 没有这一步可能会被"if(arr[mid] == target) right = mid;"这里卡住
//        if (arr[left] == target)
//            return left;
//
//        int mid = left + (right - left) / 2;
//        // 左边还可能有，向左继续找
//        if (arr[mid] == target)
//            right = mid;
//        // mid在左半边，升序
//        else if (arr[mid] > arr[0])
//        {
//            // target 在左半边
//            if (target >= arr[0] && target < arr[mid])
//                right = mid - 1;
//            // target 在右半边
//            else
//                left = mid + 1;
//        }
//        // mid在右半边
//        else if (arr[mid] < arr[0])
//        {
//            // target 在右半边
//            if (target > arr[mid] && target <= arr[n - 1])
//                left = mid + 1;
//            // target 在左半边
//            else
//                right = mid - 1;
//        }
//        // arr[mid] == arr[0] && target != arr[0]
//        // 两种情况：
//        // 1. mid在左半边，那么arr[0, mid]都是arr[0], target在mid右边
//        // 2. mid在右半边，那么arr[mid, n - 1]都是arr[0], target在mid左边
//        // mid两边都有可能，不能取任何一边，但确定是target != arr[0]
//        // 可以考虑left右移，具体到两种情况的情景如下：
//        // 1. mid在左半边，target在mid右边，右移left使mid靠向target所在的方向，继续二分判断
//        // 2. mid在右半边，target在mid左边，mid右边的数组值一定还是arr[0]，通过不断右移left在开头判断arr[left]是否等于target，实际上变成了O(n)遍历left找target
//        else
//            left++;
//    }
//    return -1;
//}
//
//// 面试题 10.09. 排序矩阵查找
//
//bool searchMatrix(int** matrix, int matrixSize, int matrixColSize, int target)
//{
//    int m = matrixSize, n = matrixColSize;
//    if (m == 0 || n == 0)
//        return false;
//    int left = 0, right = n - 1;
//    for (int i = 0; i < m; i++)
//    {
//        if (target > matrix[i][right])
//            continue;
//        if (target < matrix[i][0])
//            return false;
//        for (int j = left; j <= right; j++)
//        {
//            if (target == matrix[i][j])
//                return true;
//            if (target < matrix[i][j])
//            {
//                right = j - 1;
//            }
//        }
//    }
//    return false;
//}
//
//bool searchMatrix(int** matrix, int matrixSize, int matrixColSize, int target)
//{
//    int m = matrixSize, n = matrixColSize;
//    if (m == 0 || n == 0)
//        return false;
//    int i = 0, j = n - 1;
//    while (i < m && j >= 0)
//    {
//        if (matrix[i][j] == target)
//            return 1;
//        if (matrix[i][j] < target)
//            i++;
//        else
//            j--;
//    }
//    return false;
//}
//
