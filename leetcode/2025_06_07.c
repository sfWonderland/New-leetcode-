////1975. ������
//
//long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize)
//{
//    long long sum = 0;
//    int minus = INT_MAX, neg = 0;
//    for (int i = 0; i < matrixSize; i++)
//    {
//        for (int j = 0; j < matrixColSize[0]; j++)
//        {
//            int t = abs(matrix[i][j]);
//            sum += t;
//            minus = fmin(minus, t);
//            neg += (matrix[i][j] < 0);
//        }
//    }
//
//    return neg & 1 ? sum - 2 * minus : sum;
//}
//
////2139. �õ�Ŀ��ֵ�������ж�����
//
//int minMoves(int target, int maxDoubles)
//{
//    int cnt = 0;
//    while (target > 1)
//    {
//        if (target & 1)
//        {
//            target--;
//            cnt++;
//        }
//        else
//        {
//            if (maxDoubles)
//            {
//                target >>= 1;
//                cnt++;
//                maxDoubles--;
//            }
//            else
//            {
//                cnt += target - 1;
//                target = 1;
//            }
//        }
//    }
//    return cnt;
//}
//
////1558. �õ�Ŀ����������ٺ������ô���
//
//int minOperations(int* nums, int numsSize)
//{
//    int cnt = 0, digit = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int num = 0, d = 0, n = nums[i];
//        while (n > 1)
//        {
//            num += (n & 1);
//            n >>= 1;
//            d++;
//        }
//        digit = fmax(digit, d);
//        cnt += num + n;
//    }
//
//    return cnt + digit;
//}
//
////2914. ʹ�������ַ����������������޸Ĵ���
//
//int minChanges(char* s)
//{
//    int ans = 0;
//    for (int i = 0; s[i]; i += 2)
//    {
//        ans += (s[i] != s[i + 1]);
//    }
//    return ans;
//}
