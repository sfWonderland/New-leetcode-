////3495. ʹ����Ԫ�ض���Ϊ������ٲ�������
//
//long long f(int n)
//{
//    int m = 0;
//    unsigned int x = n;
//    while (x)
//    {
//        x >>= 1;
//        m++;
//    }
//    // O(qlogU)
//    // long long ret = 0;
//    // for(int i = 1; i < m; i++)
//    // {
//    //     ret += 1ll * (i + 1) / 2 << (i - 1);
//    // }
//    // return ret + 1ll * (m + 1) / 2 * (1 + n - (1 << m >> 1));
//    //O(1)
//    int k = (m - 1) / 2 * 2;
//    long long ret = (1ll * k << k >> 1) - (1 << k) / 3; // -1 ����ʡ��
//    return ret + 1ll * (m + 1) / 2 * (1 + n - (1 << k));
//}
//long long minOperations(int** queries, int queriesSize, int* queriesColSize)
//{
//    long long ans = 0;
//    for (int i = 0; i < queriesSize; i++)
//    {
//        ans += (f(queries[i][1]) - f(queries[i][0] - 1) + 1) / 2;
//    }
//    return ans;
//}
//
////1685. ���������в����ֵ֮��
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* getSumAbsoluteDifferences(int* nums, int numsSize, int* returnSize)
//{
//    int n = numsSize;
//    int suf[n];
//    suf[n - 1] = nums[n - 1];
//    for (int i = n - 2; i >= 0; i--)
//    {
//        suf[i] = suf[i + 1] + nums[i];
//    }
//    int pre = 0;
//    int* ans = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        ans[i] = i * nums[i] - pre + suf[i] - (n - i) * nums[i];
//        pre += nums[i];
//    }
//    *returnSize = n;
//    return ans;
//}
//
////2696. ɾ���Ӵ�����ַ�����С����
//
//int minLength(char* s)
//{
//    int n = strlen(s);
//    char* st = (char*)malloc(sizeof(char) * n);
//    int top = -1;
//    for (int i = 0; i < n; i++)
//    {
//        if (top >= 0)
//        {
//            if (st[top] == 'A' && s[i] == 'B')
//                top--;
//            else if (st[top] == 'C' && s[i] == 'D')
//                top--;
//            else
//                st[++top] = s[i];
//        }
//        else
//            st[++top] = s[i];
//    }
//    return top + 1;
//}
//
////3561. �Ƴ������ַ�
//
//char* resultingString(char* s)
//{
//    int n = strlen(s);
//    char* st = (char*)malloc(sizeof(char) * (n + 1));
//    int top = -1;
//    for (int i = 0; i < n; i++)
//    {
//        if (top >= 0)
//        {
//            if (abs(st[top] - s[i]) == 1 || abs(st[top] - s[i]) == 25)
//                top--;
//            else
//                st[++top] = s[i];
//        }
//        else
//            st[++top] = s[i];
//    }
//    st[++top] = '\0';
//    return st;
//}
//
