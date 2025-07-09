////3169. 无需开会的工作日
//
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e1)[0] - (*(int**)e2)[0];
//}
//int countDays(int days, int** meetings, int meetingsSize, int* meetingsColSize)
//{
//    int n = meetingsSize;
//    qsort(meetings, n, sizeof(int) * 2, cmp);
//    int left = 1, right = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (meetings[i][0] > right)
//        {
//            days -= right - left + 1;
//            left = meetings[i][0];
//        }
//        right = fmax(meetings[i][1], right);
//    }
//    days -= right - left + 1;
//    return days;
//}
//
////56. 合并区间
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e1)[0] - (*(int**)e2)[0];
//}
//int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
//{
//    int n = intervalsSize;
//    qsort(intervals, n, sizeof(int) * 2, cmp);
//    int** ans = (int**)malloc(sizeof(int*) * n);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
//    ans[0] = (int*)malloc(sizeof(int) * 2);
//    ans[0][0] = intervals[0][0], ans[0][1] = intervals[0][1];
//    (*returnColumnSizes)[0] = 2;
//    int index = 0;
//    for (int i = 1; i < n; i++)
//    {
//        if (intervals[i][0] > ans[index][1])
//        {
//            ans[++index] = (int*)malloc(sizeof(int) * 2);
//            ans[index][0] = intervals[i][0];
//            (*returnColumnSizes)[index] = 2;
//        }
//        ans[index][1] = fmax(intervals[i][1], ans[index][1]);
//    }
//    *returnSize = index + 1;
//    return ans;
//}
//
////57. 插入区间
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes)
//{
//    if (0 == intervalsSize)
//    {
//        *returnSize = 1;
//        *returnColumnSizes = (int*)malloc(sizeof(int));
//        (*returnColumnSizes)[0] = 2;
//        int** ans = (int**)malloc(sizeof(int*));
//        ans[0] = (int*)malloc(sizeof(int) * 2);
//        ans[0][0] = newInterval[0], ans[0][1] = newInterval[1];
//        return ans;
//    }
//    int** ans = (int**)malloc(sizeof(int*) * (intervalsSize + 1));
//    *returnColumnSizes = (int*)malloc(sizeof(int) * (intervalsSize + 1));
//    if (intervals[intervalsSize - 1][1] < newInterval[0])
//    {
//        for (int i = 0; i < intervalsSize; i++)
//        {
//            ans[i] = (int*)malloc(sizeof(int) * 2);
//            ans[i][0] = intervals[i][0], ans[i][1] = intervals[i][1];
//            (*returnColumnSizes)[i] = 2;
//        }
//        ans[intervalsSize] = (int*)malloc(sizeof(int) * 2);
//        ans[intervalsSize][0] = newInterval[0];
//        ans[intervalsSize][1] = newInterval[1];
//        (*returnColumnSizes)[intervalsSize] = 2;
//        *returnSize = intervalsSize + 1;
//        return ans;
//    }
//    else if (intervals[0][0] > newInterval[1])
//    {
//        ans[0] = (int*)malloc(sizeof(int) * 2);
//        ans[0][0] = newInterval[0];
//        ans[0][1] = newInterval[1];
//        (*returnColumnSizes)[0] = 2;
//        for (int i = 0; i < intervalsSize; i++)
//        {
//            ans[i + 1] = (int*)malloc(sizeof(int) * 2);
//            ans[i + 1][0] = intervals[i][0], ans[i + 1][1] = intervals[i][1];
//            (*returnColumnSizes)[i + 1] = 2;
//        }
//        *returnSize = intervalsSize + 1;
//        return ans;
//    }
//    int index = -1, i = 0;
//    for (; i < intervalsSize; i++)
//    {
//        int left = intervals[i][0], right = intervals[i][1];
//        ans[++index] = (int*)malloc(sizeof(int) * 2);
//        if (right < newInterval[0])
//        {
//            ans[index][0] = left, ans[index][1] = right;
//            (*returnColumnSizes)[index] = 2;
//        }
//        else if (left > newInterval[1])
//        {
//            ans[index][0] = newInterval[0], ans[index][1] = newInterval[1];
//            (*returnColumnSizes)[index] = 2;
//            break;
//        }
//        else
//        {
//            ans[index][0] = fmin(left, newInterval[0]);
//            while ((i < intervalsSize) && (intervals[i][0] <= newInterval[1]))
//                i++;
//            ans[index][1] = fmax(newInterval[1], intervals[i - 1][1]);
//            (*returnColumnSizes)[index] = 2;
//            break;
//        }
//        //printf("%d %d\n", i, index);
//    }
//    while (i < intervalsSize)
//    {
//        ans[++index] = (int*)malloc(sizeof(int) * 2);
//        ans[index][0] = intervals[i][0], ans[index][1] = intervals[i][1];
//        (*returnColumnSizes)[index] = 2;
//        i++;
//    }
//    *returnSize = index + 1;
//    return ans;
//}
//
////763. 划分字母区间
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* partitionLabels(char* s, int* returnSize)
//{
//    int n = strlen(s);
//    int last[26] = { 0 };
//    for (int i = 0; i < n; i++)
//    {
//        last[s[i] - 'a'] = i;
//    }
//    int* ans = (int*)malloc(sizeof(int) * n);
//    int idx = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        int end = last[s[i] - 'a'];
//        for (int j = i + 1; j <= end; j++)
//        {
//            end = fmax(last[s[j] - 'a'], end);
//        }
//        ans[idx++] = end - i + 1;
//        i = end;
//    }
//    *returnSize = idx;
//    return ans;
//}
//
