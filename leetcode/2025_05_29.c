////3111. �������е�����پ�����Ŀ
//
//int cmp(const void* e1, const void* e2)
//{
//    return *((int**)e1)[0] - *((int**)e2)[0];
//}
//int minRectanglesToCoverPoints(int** points, int pointsSize, int* pointsColSize, int w)
//{
//    qsort(points, pointsSize, sizeof(int) * 2, cmp);
//    int ans = 1, left = points[0][0];
//    for (int i = 0; i < pointsSize; i++)
//    {
//        if (points[i][0] > left + w)
//        {
//            left = points[i][0];
//            ans++;
//        }
//    }
//    return ans;
//}
//
////2957. �������ڽ�������ַ�
//
//int removeAlmostEqualCharacters(char* word)
//{
//    int ans = 0, n = strlen(word);
//    for (int i = 1; i < n; i++)
//    {
//        if (abs(word[i] - word[i - 1]) <= 1)
//        {
//            ans++;
//            i++;
//        }
//    }
//    return ans;
//}
//
////3192. ʹ����������ȫ������ 1 �����ٲ������� II
//
////����һ����¼��������
//// int minOperations(int* nums, int numsSize) 
//// {
////     int ans = 0;
////     for(int i = 0; i < numsSize; i++)
////     {
////         if(nums[i] == (ans & 1))
////             ans++;
////     }
////     return ans;
//// }
////���������Ƚ�����Ԫ��
//int minOperations(int* nums, int numsSize)
//{
//    int ans = nums[0] ^ 1;
//    for (int i = 1; i < numsSize; i++)
//    {
//        ans += nums[i] ^ nums[i - 1];
//    }
//    return ans;
//}
//
////2789. �ϲ��������е����Ԫ��
//
//long long maxArrayValue(int* nums, int numsSize)
//{
//    long long ans = nums[numsSize - 1];
//    for (int i = numsSize - 2; i >= 0; i--)
//    {
//        if (ans >= nums[i])
//            ans += nums[i];
//        else
//            ans = nums[i];
//    }
//    return ans;
//}
//
