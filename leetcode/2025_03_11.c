////1844. 将所有数字用字符替换
//
//char shift(char c, int x)
//{
//    x -= 48;
//    return c + x;
//}
//char* replaceDigits(char* s)
//{
//    int len = strlen(s);
//    for (int i = 1; i < len; i += 2)
//    {
//        s[i] = shift(s[i - 1], s[i]);
//    }
//    return s;
//}
//
////1848. 到目标元素的最小距离
//
//int getMinDistance(int* nums, int numsSize, int target, int start)
//{
//    int left = start, right = start;
//    while (left >= 0 || right < numsSize)
//    {
//        if (left >= 0 && nums[left] == target)
//            return start - left;
//        else if (right < numsSize && nums[right] == target)
//            return right - start;
//        left--;
//        right++;
//    }
//    return -1;
//}
//
////1909. 删除一个元素使数组严格递增
//
//bool canBeIncreasing(int* nums, int numsSize)
//{
//    if (numsSize <= 2)
//        return true;
//    int abnormal = 0;
//    for (int i = 0; i < numsSize - 1; i++)
//    {
//        if (nums[i] >= nums[i + 1])
//        {
//            if ((i == 0 || i == numsSize - 2 || nums[i + 1] > nums[i - 1] || nums[i + 2] > nums[i]) && 0 == abnormal)
//                abnormal++;
//            else
//                return false;
//        }
//    }
//    return true;
//}
//
