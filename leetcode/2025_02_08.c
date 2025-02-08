//#define _CRT_SECURE_NO_WARNINGS
//
////1539.��k��ȱʧ��������
//
//// ʱ�临�Ӷ�O(N)
//// int findKthPositive(int* arr, int arrSize, int k) 
//// {
////     int miss = 0;
////     int current = 1;
////     int i = 0;
////     while(1)
////     {
////         if(i < arrSize && arr[i] == current)
////             i++;
////         else
////             miss++;
//
////         if(miss == k)
////         break;
////         current++;    
////     }
//
////     return current;
//// }
//
//// int findKthPositive(int* arr, int arrSize, int k) 
//// {
////     for (int i = 0; i < arrSize; i++) 
////     {
////         if (arr[i] <= k) 
////             k++;
////     }
//
////     return k;
//// }
//
//// ʱ�临�Ӷ�O(log(N))
//int findKthPositive(int* arr, int arrSize, int k)
//{
//    if (arr[0] > k)
//        return k;
//
//    int left = 0;
//    int right = arrSize - 1;
//    while (left <= right)
//    {
//        int mid = (right - left) / 2 + left;
//        printf("left = %d, right = %d, mid = %d\n", left, right, mid);
//        if (arr[mid] - mid - 1 < k)
//            left = mid + 1;
//        else
//            right = mid - 1;
//    }
//    printf("left = %d\n", left);
//    return k + left;
//}
//
////1394.�ҳ������е�������
//
//int findLucky(int* arr, int arrSize)
//{
//    int h[501] = { 0 };
//    for (int i = 0; i < arrSize; i++)
//        h[arr[i]]++;
//    for (int j = 500; j > 0; j--)
//    {
//        if (h[j] == j)
//            return j;
//    }
//    return -1;
//}
//
////1991.�ҵ�������м�λ�ã��ģ�
//
//int findMiddleIndex(int* nums, int numsSize)
//{
//    int total = 0;
//
//    for (int i = 0; i < numsSize; i++)
//        total += nums[i];
//
//    int sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (2 * sum + nums[i] == total)
//            return i;
//
//        sum += nums[i];
//    }
//    return -1;
//}
//
