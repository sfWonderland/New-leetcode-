////1529. ���ٵĺ�׺��ת����
//
//int minFlips(char* target)
//{
//    int ans = target[0] - '0';
//    for (int i = 1; target[i]; i++)
//    {
//        ans += abs(target[i] - target[i - 1]);
//    }
//    return ans;
//}
//
////1144. �ݼ�Ԫ��ʹ����ʾ��״
//
//int movesToMakeZigzag(int* nums, int numsSize)
//{
//    int s[2] = { 0 };
//    for (int i = 0; i < numsSize; i++)
//    {
//        int left = i > 0 ? nums[i - 1] : INT_MAX;
//        int right = i < numsSize - 1 ? nums[i + 1] : INT_MAX;
//        s[i & 1] += fmax(0, nums[i] - fmin(left, right) + 1);
//    }
//    return fmin(s[0], s[1]);
//}
//
////3228. �� 1 �ƶ���ĩβ������������
//
//int maxOperations(char* s)
//{
//    int ans = 0, t = 0, sum = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] - '0')
//            t++;
//        else
//        {
//            sum += t;
//            ans += t ? sum : 0;
//            t = 0;
//        }
//    }
//    return ans;
//}
//
////2086. ιʳ�������Сʳ��Ͱ��
//
//int minimumBuckets(char* hamsters)
//{
//    int ans = 0, bucketPos = -2;
//    for (int i = 0; hamsters[i]; i++)
//    {
//        if (hamsters[i] == 'H')
//        {
//            if (bucketPos == i - 1)
//                continue;
//            else if (hamsters[i + 1] == '.')
//            {
//                bucketPos = i + 1;
//                ans++;
//            }
//            else if (i > 0 && hamsters[i - 1] == '.')
//                ans++;
//            else
//                return -1;
//        }
//    }
//    return ans;
//}
//
