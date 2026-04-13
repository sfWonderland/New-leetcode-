//// LCR 012. 寻找数组的中心下标
//
//int pivotIndex(int* nums, int numsSize)
//{
//    int suf = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        suf += nums[i];
//    }
//    int pre = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        suf -= nums[i];
//
//        if (pre == suf)
//            return i;
//
//        pre += nums[i];
//    }
//    return -1;
//}
//
//// LCR 013. 二维区域和检索 - 矩阵不可变   
//
//typedef struct
//{
//    int** sum;
//    int m;
//    int n;
//} NumMatrix;
//
//
//NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize)
//{
//    int m = matrixSize, n = matrixColSize[0];
//    NumMatrix* obj = (NumMatrix*)malloc(sizeof(NumMatrix));
//    obj->sum = (int**)malloc(sizeof(int*) * (m + 1));
//    obj->sum[0] = (int*)calloc(sizeof(int), (n + 1));
//    for (int i = 0; i < m; i++)
//    {
//        obj->sum[i + 1] = (int*)malloc(sizeof(int) * (n + 1));
//        obj->sum[i + 1][0] = 0;
//        for (int j = 0; j < n; j++)
//        {
//            obj->sum[i + 1][j + 1] = matrix[i][j] + obj->sum[i + 1][j] + obj->sum[i][j + 1] - obj->sum[i][j];
//        }
//    }
//    obj->m = m + 1;
//    obj->n = n + 1;
//    return obj;
//}
//
//int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2)
//{
//    return obj->sum[row2 + 1][col2 + 1] - obj->sum[row2 + 1][col1] - obj->sum[row1][col2 + 1] + obj->sum[row1][col1];
//}
//
//void numMatrixFree(NumMatrix* obj)
//{
//    for (int i = 0; i < obj->m; i++)
//    {
//        free(obj->sum[i]);
//    }
//    free(obj);
//}
//
///**
// * Your NumMatrix struct will be instantiated and called as such:
// * NumMatrix* obj = numMatrixCreate(matrix, matrixSize, matrixColSize);
// * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
//
// * numMatrixFree(obj);
//*/
//
////LCR 014. 字符串的排列
//
//bool checkInclusion(char* s1, char* s2)
//{
//    int cnt[26] = { 0 };
//    int m = strlen(s1), n = strlen(s2);
//    if (n < m) return false;
//    for (int i = 0; i < m; i++)
//    {
//        cnt[s1[i] - 'a']--;
//    }
//    int left = 0;
//    for (int i = 0; i < n; i++)
//    {
//        cnt[s2[i] - 'a']++;
//        while (cnt[s2[i] - 'a'] > 0)
//        {
//            cnt[s2[left] - 'a']--;
//            left++;
//        }
//        if (i - left + 1 == m)
//            return true;
//    }
//    return false;
//}
//
////LCR 001. 两数相除
//
//bool quick_mul(int y, int z, int x)
//{
//    int add = y, res = 0;
//    while (z)
//    {
//        if (z & 1)
//        {
//            if (res < x - add)
//                return false;
//            res += add;
//        }
//
//        if (z != 1)
//        {
//            if (add < x - add)
//                return false;
//            add += add;
//        }
//        z >>= 1;
//    }
//    return true;
//}
//
//int divide(int a, int b)
//{
//    if (a == 0)
//        return 0;
//
//    if (a == INT_MIN)
//    {
//        if (b == 1)
//            return a;
//
//        if (b == -1)
//            return INT_MAX;
//    }
//
//    if (b == INT_MIN)
//    {
//        return a == b;
//    }
//
//    bool rev = false;
//    if (a > 0)
//    {
//        a = -a;
//        rev = !rev;
//    }
//    if (b > 0)
//    {
//        b = -b;
//        rev = !rev;
//    }
//
//    int left = 1, right = INT_MAX, ans = 0;
//    while (left <= right)
//    {
//        int mid = left + ((right - left) >> 1);
//        bool check = quick_mul(b, mid, a);
//        if (check)
//        {
//            ans = mid;
//            if (mid == INT_MAX)
//                break;
//
//            left = mid + 1;
//        }
//        else
//            right = mid - 1;
//    }
//    return rev ? -ans : ans;
//}
//
