////3424. ���������ͬ����С����
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//long long minCost(int* arr, int arrSize, int* brr, int brrSize, long long k)
//{
//    long long sum1 = 0;
//    for (int i = 0; i < arrSize; i++)
//    {
//        sum1 += abs(arr[i] - brr[i]);
//    }
//
//    if (sum1 <= k)
//        return sum1;
//
//    qsort(arr, arrSize, sizeof(int), cmp);
//    qsort(brr, brrSize, sizeof(int), cmp);
//
//    long long sum2 = k;
//    for (int i = 0; i < arrSize; i++)
//    {
//        sum2 += abs(arr[i] - brr[i]);
//    }
//
//    return fmin(sum1, sum2);
//}
//
////3207. �����ս�����������
//
//long long maximumPoints(int* enemyEnergies, int enemyEnergiesSize, int currentEnergy)
//{
//    int min = INT_MAX;
//    long long sum = currentEnergy;
//    for (int i = 0; i < enemyEnergiesSize; i++)
//    {
//        sum += enemyEnergies[i];
//        min = fmin(min, enemyEnergies[i]);
//    }
//
//    if (min > currentEnergy)
//        return 0;
//
//    return sum / min - 1;
//}
//
////2811. �ж��Ƿ��ܲ������
//
//bool canSplitArray(int* nums, int numsSize, int m)
//{
//    if (numsSize < 3)
//        return true;
//    int deux = nums[0] + nums[1];
//    int max = deux;
//    for (int i = 2; i < numsSize; i++)
//    {
//        deux = nums[i] + deux - nums[i - 2];
//        max = fmax(max, deux);
//    }
//
//    return max >= m;
//}
//
////2211. ͳ�Ƶ�·�ϵ���ײ����
//
//int countCollisions(char* directions)
//{
//    int left = 0, right = strlen(directions) - 1;
//    while ('L' == directions[left])
//        left++;
//    while (right >= 0 && 'R' == directions[right])
//        right--;
//    
//    int statusS = 0;
//    for (int i = 0; i <= right; i++)
//    {
//        if ('S' == directions[i])
//            statusS++;
//    }
//    return right - left + 1 - statusS;
//}
