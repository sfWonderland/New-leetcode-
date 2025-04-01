////2873. 有序三元组中的最大值 I
//
//long long maximumTripletValue(int* nums, int numsSize)
//{
//    long long ans = 0;
//    int preMax = 0, maxDiff = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        ans = fmax(ans, 1LL * maxDiff * nums[i]);
//        maxDiff = fmax(maxDiff, preMax - nums[i]);
//        preMax = fmax(preMax, nums[i]);
//    }
//    return ans;
//}
//
//
////2000. 反转单词前缀
//
//void reverse(char* s, int left, int right)
//{
//    while (left < right)
//    {
//        char tmp = s[left];
//        s[left] = s[right];
//        s[right] = tmp;
//        left++;
//        right--;
//    }
//}
//char* reversePrefix(char* word, char ch)
//{
//    for (int i = 0; word[i]; i++)
//    {
//        if (word[i] == ch)
//        {
//            reverse(word, 0, i);
//            break;
//        }
//    }
//    return word;
//}
//
////496. 下一个更大元素 I
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
//{
//    for (int i = 0; i < nums1Size; i++)
//    {
//        int t = nums1[i];
//        nums1[i] = -1;
//        for (int j = nums2Size - 1; j >= 0; j--)
//        {
//            if (nums2[j] == t)
//                break;
//            if (nums2[j] > t)
//                nums1[i] = nums2[j];
//        }
//    }
//    returnSize[0] = nums1Size;
//    return nums1;
//}
//
////3174. 清除数字
//
//char* clearDigits(char* s)
//{
//    int slow = 0;
//    int flag = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (slow >= 1 && s[i] < 97 && flag)
//        {
//            slow--;
//            flag = slow < 1 ? 0 : s[slow - 1] >= 'a';
//        }
//        else
//        {
//            s[slow] = s[i];
//            flag = s[slow++] >= 'a';
//        }
//    }
//    s[slow] = '\0';
//    return s;
//}
//
