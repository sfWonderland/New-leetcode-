////2997. ʹ�������͵��� K �����ٲ�������
//
//int minOperations(int* nums, int numsSize, int k)
//{
//    int n = k;
//    for (int i = 0; i < numsSize; i++)
//    {
//        n ^= nums[i];
//    }
//    int ans = 0;
//    while (n)
//    {
//        ans++;
//        n &= n - 1;
//    }
//    return ans;
//}
//
////1442. �γ������������������Ԫ����Ŀ
//
//int countTriplets(int* arr, int arrSize)
//{
//    int* pre = (int*)malloc(sizeof(int) * (arrSize + 1));
//    pre[0] = 0;
//    for (int i = 1; i < arrSize + 1; i++)
//    {
//        pre[i] = pre[i - 1] ^ arr[i - 1];
//    }
//    int ans = 0;
//    for (int i = 0; i < arrSize; i++)
//    {
//        for (int k = i + 1; k < arrSize; k++)
//        {
//            // ����ʽ S[i]?=S[k+1]����ʱ
//            // [i+1,k] �ķ�Χ�ڵ����� j ���Ƿ���Ҫ���
//            // ��Ӧ����Ԫ�����Ϊ k?i���������ֻ��ö���±� i �� k��
//            if (pre[i] == pre[k + 1])
//                ans += k - i;
//        }
//    }
//    return ans;
//}
//
////2429. ��С���
//
//int minimizeXor(int num1, int num2)
//{
//    int digit1 = 0, digit2 = 0;
//    int t = num1;
//    while (t)
//    {
//        t &= t - 1;
//        digit1++;
//    }
//    t = num2;
//    while (t)
//    {
//        t &= t - 1;
//        digit2++;
//    }
//    for (; digit2 < digit1; digit2++)
//    {
//        num1 &= num1 - 1;
//    }
//    for (; digit1 < digit2; digit1++)
//    {
//        num1 |= num1 + 1;
//    }
//
//    return num1;
//}
//
////2527. ��ѯ�����������ֵ
//
//int xorBeauty(int* nums, int numsSize)
//{
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        ans ^= nums[i];
//    }
//    return ans;
//}
//
