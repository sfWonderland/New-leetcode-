////1844. �������������ַ��滻
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
////1848. ��Ŀ��Ԫ�ص���С����
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
////1909. ɾ��һ��Ԫ��ʹ�����ϸ����
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
