////2311. С�ڵ��� K ���������������
//
//int longestSubsequence(char* s, int k)
//{
//    int sum = 0, cnt = 0, n = strlen(s);
//    int bits = (int)(log2(k)) + 1;
//    for (int i = 0; i < n; i++)
//    {
//        char ch = s[n - 1 - i];
//        if (ch == '1')
//        {
//            if (i < bits && sum + (1 << i) <= k)
//            {
//                sum += 1 << i;
//                cnt++;
//            }
//        }
//        else
//            cnt++;
//    }
//    return cnt;
//}
//
////3028. �߽��ϵ�����
//
//int returnToBoundaryCount(int* nums, int numsSize)
//{
//    int cnt = 0, dist = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        dist += nums[i];
//        cnt += (dist == 0);
//    }
//    return cnt;
//}
//
////2120. ִ�����к�׺ָ��
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* executeInstructions(int n, int* startPos, int startPosSize, char* s, int* returnSize)
//{
//    int len = strlen(s);
//    int* ans = (int*)malloc(sizeof(int) * len);
//    int j = 0;
//    for (int i = 0; i < len; i++)
//    {
//        int x = startPos[1];
//        int y = startPos[0];
//        for (j = i; j < len; j++)
//        {
//            switch (s[j])
//            {
//            case 'L': --x; break;
//            case 'R': ++x; break;
//            case 'U': --y; break;
//            case 'D': ++y; break;
//            }
//            if (x < 0 || x > n - 1 || y < 0 || y > n - 1)
//                break;
//        }
//        ans[i] = j - i;
//    }
//    *returnSize = len;
//    return ans;
//}
//
////1551. ʹ����������Ԫ����ȵ���С������
//
//int minOperations(int n)
//{
//    return n & 1 ? (n * n - 1) / 4 : n * n / 4;
//}
//
