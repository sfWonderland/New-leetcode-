////3432. ͳ��Ԫ�غͲ�ֵΪż���ķ�������
//
//int countPartitions(int* nums, int numsSize)
//{
//    int sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//    }
//    return sum & 1 ? 0 : numsSize - 1;
//}
//
////2396. �ϸ���ĵ�����
//
//bool isStrictlyPalindromic(int n)
//{
//    return false;
//}
//
////3227. �ַ���Ԫ����Ϸ
//
//bool doesAliceWin(char* s)
//{
//    int cnt = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        cnt |= 1 << (s[i] - 'a');
//    }
//    //printf("%x", cnt);
//    return cnt & 0x104111;
//}
//
////2419. ��λ�������������
//
//int longestSubarray(int* nums, int numsSize)
//{
//    int max = 0, cnt = 0, ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (max < nums[i])
//        {
//            max = nums[i];
//            ans = 1;
//            cnt = 1;
//        }
//        else if (max == nums[i])
//        {
//            cnt++;
//            ans = fmax(ans, cnt);
//        }
//        else
//            cnt = 0;
//    }
//
//    return ans;
//}
//
