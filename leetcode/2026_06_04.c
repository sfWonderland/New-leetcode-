//// 373. 查找和最小的 K 对数字
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//
//void up(int heap[][3], int i)
//{
//    int sum = heap[i][0], x = heap[i][1], y = heap[i][2];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j][0] >= sum)
//            break;
//
//        heap[i][0] = heap[j][0];
//        heap[i][1] = heap[j][1];
//        heap[i][2] = heap[j][2];
//        i = j;
//
//        if (j == 0)
//            break;
//    }
//    heap[i][0] = sum;
//    heap[i][1] = x;
//    heap[i][2] = y;
//}
//
//void down(int heap[][3], int i, int n)
//{
//    int sum = heap[i][0], x = heap[i][1], y = heap[i][2];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1][0] > heap[j][0])
//            j++;
//
//        if (heap[j][0] <= sum)
//            break;
//
//        heap[i][0] = heap[j][0];
//        heap[i][1] = heap[j][1];
//        heap[i][2] = heap[j][2];
//        i = j;
//    }
//    heap[i][0] = sum;
//    heap[i][1] = x;
//    heap[i][2] = y;
//}
//
//void pop(int heap[][3], int n, int x, int y)
//{
//    heap[0][0] = x + y;
//    heap[0][1] = x;
//    heap[0][2] = y;
//    down(heap, 0, n);
//}
//
//void push(int heap[][3], int* n, int x, int y)
//{
//    heap[*n][0] = x + y;
//    heap[*n][1] = x;
//    heap[*n][2] = y;
//    up(heap, *n);
//    (*n)++;
//}
//
//int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes)
//{
//    int heap[k][3];
//    int m = 0;
//    for (int i = 0; i < nums1Size; i++)
//    {
//        for (int j = 0; j < nums2Size; j++)
//        {
//            if (m < k)
//                push(heap, &m, nums1[i], nums2[j]);
//            else if (heap[0][0] > nums1[i] + nums2[j])
//                pop(heap, k, nums1[i], nums2[j]);
//            else
//                break;
//        }
//    }
//    int** ans = (int**)malloc(sizeof(int*) * k);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * k);
//    for (int i = 0; i < k; i++)
//    {
//        ans[i] = (int*)malloc(sizeof(int) * 2);
//        ans[i][0] = heap[i][1];
//        ans[i][1] = heap[i][2];
//        (*returnColumnSizes)[i] = 2;
//    }
//    *returnSize = k;
//    return ans;
//}
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//
//void up(int heap[][3], int i)
//{
//    int sum = heap[i][0], x = heap[i][1], y = heap[i][2];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j][0] <= sum)
//            break;
//
//        heap[i][0] = heap[j][0];
//        heap[i][1] = heap[j][1];
//        heap[i][2] = heap[j][2];
//        i = j;
//
//        if (j == 0)
//            break;
//    }
//    heap[i][0] = sum;
//    heap[i][1] = x;
//    heap[i][2] = y;
//}
//
//void down(int heap[][3], int i, int n)
//{
//    int sum = heap[i][0], x = heap[i][1], y = heap[i][2];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1][0] < heap[j][0])
//            j++;
//
//        if (heap[j][0] >= sum)
//            break;
//
//        heap[i][0] = heap[j][0];
//        heap[i][1] = heap[j][1];
//        heap[i][2] = heap[j][2];
//        i = j;
//    }
//    heap[i][0] = sum;
//    heap[i][1] = x;
//    heap[i][2] = y;
//}
//
//void pop(int heap[][3], int n, int x, int y, int z)
//{
//    heap[0][0] = x;
//    heap[0][1] = y;
//    heap[0][2] = z;
//    down(heap, 0, n);
//}
//
//void push(int heap[][3], int* n, int x, int y, int z)
//{
//    heap[*n][0] = x;
//    heap[*n][1] = y;
//    heap[*n][2] = z;
//    up(heap, *n);
//    (*n)++;
//}
//
//int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes)
//{
//    int** ans = (int**)malloc(sizeof(int*) * k);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * k);
//    int heap[2 * k + 1][3];
//    int n = nums1Size, m = nums2Size, k0 = 0, pos = 0;
//    push(heap, &pos, nums1[0] + nums2[0], 0, 0);
//    while (k0 < k)
//    {
//        int i = heap[0][1], j = heap[0][2];
//        ans[k0] = (int*)malloc(sizeof(int) * 2);
//        ans[k0][0] = nums1[i];
//        ans[k0][1] = nums2[j];
//        (*returnColumnSizes)[k0++] = 2;
//        pop(heap, pos, INT_MAX, 0, 0);
//        if (j == 0 && i + 1 < n)
//            push(heap, &pos, nums1[i + 1] + nums2[j], i + 1, j);
//        if (j + 1 < m)
//            push(heap, &pos, nums1[i] + nums2[j + 1], i, j + 1);
//    }
//    *returnSize = k;
//    return ans;
//}
//
