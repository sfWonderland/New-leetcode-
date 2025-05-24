////2894. 分类求和并作差
//
//int differenceOfSums(int n, int m)
//{
//    int num1 = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        num1 += i;
//    }
//    int num2 = 0;
//    for (int i = m; i <= n; i += m)
//    {
//        num2 += i;
//    }
//    return num1 - 2 * num2;
//}
//
////2592. 最大化数组的伟大值
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int maximizeGreatness(int* nums, int numsSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int slow = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] > nums[slow])
//            slow++;
//    }
//    return slow;
//}
////numsSize - maxCnt
//
////2576. 求出最多标记下标
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//bool check(int* nums, int numsSize, int k)
//{
//    for (int i = 0; i < k; i++)
//    {
//        if (nums[i] * 2 > nums[numsSize - k + i])
//            return false;
//    }
//    return true;
//}
//int maxNumOfMarkedIndices(int* nums, int numsSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int left = 0, right = numsSize / 2 + 1;
//    while (left + 1 < right)
//    {
//        int mid = left + (right - left) / 2;
//        if (check(nums, numsSize, mid))
//            left = mid;
//        else
//            right = mid;
//    }
//    return left * 2;
//}
//
////2037. 使每位学生都有座位的最少移动次数
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize)
//{
//    qsort(seats, seatsSize, sizeof(int), cmp);
//    qsort(students, studentsSize, sizeof(int), cmp);
//    int ans = 0;
//    for (int i = 0; i < seatsSize; i++)
//    {
//        ans += abs(seats[i] - students[i]);
//    }
//    return ans;
//}
//
