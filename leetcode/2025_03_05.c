////1812. �жϹ�������������һ�����ӵ���ɫ
//
//bool squareIsWhite(char* coordinates)
//{
//    return (coordinates[0] + coordinates[1]) & 1;
//}
//
////3274. ������̷�����ɫ�Ƿ���ͬ
//
//bool checkTwoChessboards(char* coordinate1, char* coordinate2)
//{
//    int a = (coordinate1[0] + coordinate1[1]) & 1;
//    int b = (coordinate2[0] + coordinate2[1]) & 1;
//    return (!(a ^ b));
//}
//
////1822. ����Ԫ�ػ��ķ���
//
//int arraySign(int* nums, int numsSize)
//{
//    int positive = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (0 == nums[i])
//            return 0;
//        else if (nums[i] < 0)
//            positive++;
//    }
//    return positive & 1 ? -1 : 1;
//}
//
////1328. �ƻ����Ĵ�
//
//char* breakPalindrome(char* palindrome)
//{
//    int len = strlen(palindrome);
//    if (len == 1)
//        return "";
//    int i = 0;
//    for (i = 0; i < len / 2; i++)
//    {
//        if (palindrome[i] != 'a')
//        {
//            palindrome[i] = 'a';
//            return palindrome;
//        }
//    }
//
//    palindrome[len - 1]++;
//    return palindrome;
//}
//
////2855. ʹ�����Ϊ����������������ƴ���
//
//int minimumRightShifts(int* nums, int numsSize)
//{
//    int i = 1;
//    while (i < numsSize && nums[i - 1] < nums[i])
//        i++;
//    if (i == numsSize)
//        return 0;
//    else if (nums[numsSize - 1] > nums[0])
//        return -1;
//    int mid = i;
//
//    for (i = i + 1; i < numsSize; i++)
//    {
//        if (nums[i] < nums[i - 1])
//            return -1;
//    }
//
//    return numsSize - mid;
//}
//
