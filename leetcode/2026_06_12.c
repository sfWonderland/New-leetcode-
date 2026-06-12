//// 556. 下一个更大元素 III
//
//void swap(int* nums, int i, int j)
//{
//    int tmp = nums[i];
//    nums[i] = nums[j];
//    nums[j] = tmp;
//}
//int nextGreaterElement(int n)
//{
//    int nums[11];
//    int k = 0;
//    while (n)
//    {
//        nums[k++] = n % 10;
//        n /= 10;
//    }
//    int idx = -1;
//    for (int i = 0; i < k - 1 && idx == -1; i++)
//    {
//        if (nums[i + 1] < nums[i])
//        {
//            idx = i + 1;
//            break;
//        }
//    }
//    if (idx == -1) return -1;
//    for (int i = 0; i < idx; i++)
//    {
//        if (nums[i] > nums[idx])
//        {
//            swap(nums, i, idx);
//            break;
//        }
//    }
//    for (int left = 0, right = idx - 1; left < right; left++, right--)
//    {
//        swap(nums, left, right);
//    }
//    long long ans = 0;
//    for (int i = k - 1; i >= 0; i--)
//    {
//        ans = ans * 10 + nums[i];
//    }
//    return ans > INT_MAX ? -1 : ans;
//}
//
