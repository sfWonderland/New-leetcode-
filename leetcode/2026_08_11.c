//// 406. 根据身高重建队列
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    int* a = *(int**)e1, * b = *(int**)e2;
//    return a[0] == b[0] ? a[1] - b[1] : b[0] - a[0];
//}
//int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes)
//{
//    int n = peopleSize;
//    qsort(people, n, sizeof(int*), cmp);
//    int** ans = (int**)malloc(sizeof(int*) * n);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
//    int ansSize = 0;
//    int** st = (int**)malloc(sizeof(int*) * n);
//    for (int i = 0; i < n; i++)
//    {
//        int k = people[i][1];
//        int top = 0;
//        while (ansSize > k)
//        {
//            st[top++] = ans[--ansSize];
//        }
//        ans[ansSize++] = people[i];
//        while (top)
//        {
//            ans[ansSize++] = st[--top];
//        }
//        (*returnColumnSizes)[ansSize - 1] = 2;
//    }
//    free(st);
//    *returnSize = ansSize;
//    return ans;
//}
//
