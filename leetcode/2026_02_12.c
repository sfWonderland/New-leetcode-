////532. 数组中的 k-diff 数对
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int findPairs(int* nums, int numsSize, int k)
//{
//    int n = numsSize, ans = 0;
//    qsort(nums, n, sizeof(int), cmp);
//    for (int i = 0; i < n - 1; i++)
//    {
//        if (i > 0 && nums[i] == nums[i - 1])
//            continue;
//
//        int left = i + 1, right = n - 1, target = nums[i] + k;
//        while (left <= right)
//        {
//            int mid = (left + right) / 2;
//            if (nums[mid] > target)
//                right = mid - 1;
//            else
//                left = mid + 1;
//        }
//        left--;
//        if (left > i && nums[left] == target)
//            ans++;
//    }
//    return ans;
//}
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int findPairs(int* nums, int numsSize, int k)
//{
//    int n = numsSize, ans = 0;
//    qsort(nums, n, sizeof(int), cmp);
//    for (int i = 0, j = 0; i < n - 1 && j < n; i++)
//    {
//        if (i > 0 && nums[i] == nums[i - 1])
//            continue;
//
//        // 须j > i
//        j = fmax(j, i + 1);
//
//        while (j < n && (nums[j] < nums[i] + k))
//            j++;
//
//        if (j < n && nums[j] == nums[i] + k)
//            ans++;
//    }
//    return ans;
//}
//
////553. 最优除法    
//
//char* optimalDivision(int* nums, int numsSize)
//{
//    char* ans = (char*)malloc(sizeof(char) * 52);
//    if (numsSize == 1)
//        sprintf(ans, "%d", nums[0]);
//    else if (numsSize == 2)
//        sprintf(ans, "%d/%d", nums[0], nums[1]);
//    else
//    {
//        sprintf(ans, "%d/(", nums[0]);
//        for (int i = 1; i < numsSize; i++)
//        {
//            char* s = (char*)malloc(sizeof(char) * 6);
//            sprintf(s, "%d/", nums[i]);
//            strcat(ans, s);
//        }
//        int n = strlen(ans);
//        ans[n - 1] = ')';
//        ans[n] = '\0';
//    }
//    return ans;
//}
//
////565. 数组嵌套
//
//int arrayNesting(int* nums, int numsSize)
//{
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] == -1)
//            continue;
//
//        int sum = 0, x = i;
//        while (nums[x] != -1)
//        {
//            int tmp = nums[x];
//            nums[x] = -1;
//            sum++;
//            x = tmp;
//        }
//        if (sum > ans) ans = sum;
//    }
//    return ans;
//}
//
////665. 非递减数列
//
//bool checkPossibility(int* nums, int numsSize)
//{
//    bool divert = false;
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (nums[i] >= nums[i - 1])
//            continue;
//
//        if (divert)
//            return false;
//
//        divert = true;
//        if (i > 1 && nums[i - 2] > nums[i])
//            nums[i] = nums[i - 1];
//    }
//    return true;
//}
//
