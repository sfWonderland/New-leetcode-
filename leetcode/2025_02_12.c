//#define _CRT_SECURE_NO_WARNINGS
//
////1760.������������Ŀ����
//
////�������֪��һ�����ӵ����ߴ磬��ô�����Ǹı�������⡪��������������С���������Ƕ���
////��ע�⣬�������ߴ�����ӣ���С�����������٣�������ǿ��Զ����ߴ���ж��ֲ���
//int minimumSize(int* nums, int numsSize, int maxOperations)
//{
//    //���ֵ
//    int max = nums[0];
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (max < nums[i])
//            max = nums[i];
//    }
//
//    //���ַ�����
//    int min = 1;
//    int ret = 0;
//    while (min <= max)
//    {
//        long long n = 0;
//        int mid = min + ((max - min) >> 1);
//        for (int i = 0; i < numsSize; i++)
//        {
//            //���������㣬����ȡ��
//            if (nums[i] > mid)
//                n += (nums[i] - 1) / mid;
//        }
//        //���ڲ������������ޣ���֮��������
//        if (n > maxOperations)
//            min = mid + 1;
//        else
//        {
//            max = mid - 1;
//            ret = mid;
//        }
//    }
//
//    return ret;
//}
//
////2064.������̵�������Ʒ����Сֵ
//
//int minimizedMaximum(int n, int* quantities, int quantitiesSize)
//{
//    //���ֵ
//    int max = quantities[0];
//    for (int i = 1; i < quantitiesSize; i++)
//    {
//        if (max < quantities[i])
//            max = quantities[i];
//    }
//
//    //���ַ�����
//    int min = 1;
//    int ret = 0;
//    while (min <= max)
//    {
//        long long num = 0;
//        int mid = min + ((max - min) >> 1);
//        for (int i = 0; i < quantitiesSize; i++)
//        {
//            //���������㣬����ȡ��
//            if (quantities[i] > mid)
//                num += (quantities[i] - 1) / mid;
//        }
//        //���ڲ������������ޣ���֮��������
//        if (num > n - quantitiesSize)
//            min = mid + 1;
//        else
//        {
//            max = mid - 1;
//            ret = mid;
//        }
//    }
//
//    return ret;
//}
//
////875.�����㽶������
//
//int minEatingSpeed(int* piles, int pilesSize, int h)
//{
//    //���ֵ
//    int max = piles[0];
//    for (int i = 1; i < pilesSize; i++)
//    {
//        if (max < piles[i])
//            max = piles[i];
//    }
//
//    //���ַ�����
//    int min = 1;
//    int ret = 0;
//    while (min <= max)
//    {
//        long long num = 0;
//        int mid = min + ((max - min) >> 1);
//        for (int i = 0; i < pilesSize; i++)
//        {
//            //���������㣬����ȡ��
//            num += (piles[i] - 1 + mid) / mid;
//        }
//        //���ڲ������������ޣ���֮��������
//        if (num > h)
//            min = mid + 1;
//        else
//        {
//            max = mid - 1;
//            ret = mid;
//        }
//    }
//
//    return ret;
//}
//
////1011.��D�����ʹ����������
//
//int shipWithinDays(int* weights, int weightsSize, int days)
//{
//    //���ֵ
//    int max = weights[0];
//    int min = weights[0];
//    for (int i = 1; i < weightsSize; i++)
//    {
//        max += weights[i];
//        if (min < weights[i])
//            min = weights[i];
//    }
//
//    //���ַ�����
//    int ret = min;
//    while (min <= max)
//    {
//        int mid = min + ((max - min) >> 1);
//        int num = 1;
//        int sum = 0;
//        for (int i = 0; i < weightsSize; i++)
//        {
//            //���������㣬��һ���ͻ���
//            if (sum + weights[i] > mid)
//            {
//                sum = 0;
//                num++;
//            }
//            sum += weights[i];
//        }
//        //���ڲ������������ޣ���֮��������
//        if (num > days)
//            min = mid + 1;
//        else
//        {
//            max = mid - 1;
//            ret = mid;
//        }
//    }
//
//    return ret;
//}
//
////2226.ÿ��С������ֵܷ������ǹ�
//
//int maximumCandies(int* candies, int candiesSize, long long k)
//{
//    //���ֵ
//    int max = candies[0];
//    for (int i = 1; i < candiesSize; i++)
//    {
//        if (max < candies[i])
//            max = candies[i];
//    }
//
//    //���ַ�����
//    int min = 1;
//    int ret = 0;
//    while (min <= max)
//    {
//        long long num = 0;
//        int mid = min + ((max - min) >> 1);
//        for (int i = 0; i < candiesSize; i++)
//        {
//            //���������㣬����ȡ��
//            if (candies[i] >= mid)
//                num += candies[i] / mid;
//        }
//        //���ڲ������������ޣ���֮��������
//        if (num >= k)
//        {
//            min = mid + 1;
//            ret = mid;
//        }
//        else
//            max = mid - 1;
//    }
//
//    return ret;
//}
//
////1870.׼ʱ������г���Сʱ��
//
//#define TIMES 100
//int minSpeedOnTime(int* dist, int distSize, double hour)
//{
//    long long h = llround(hour * TIMES);
//    //��쳵���ܷ��ܵ���
//    if (h <= (distSize - 1) * TIMES)
//        return -1;
//    //���ַ�����
//    int min = 1;
//    int max = 10000000;
//    while (min <= max)
//    {
//        double num = 0;
//        int mid = min + ((max - min) >> 1);
//        for (int i = 0; i < distSize - 1; i++)
//        {
//            //���������㣬����ȡ��
//            num += (dist[i] + mid - 1) / mid;
//        }
//        num *= mid;
//        num += dist[distSize - 1];
//        //���ڲ������������ޣ���֮��������
//        if (num * TIMES > h * mid)
//            min = mid + 1;
//        else
//            max = mid - 1;
//    }
//
//    return min;
//}
//
////2187.�����;������ʱ�� 
//
//long long minimumTime(int* time, int timeSize, int totalTrips)
//{
//    long long max = time[0];
//    for (int i = 1; i < timeSize; i++)
//    {
//        if (time[i] < max)
//            max = time[i];
//    }
//    max *= totalTrips;
//    //���ַ�����
//    long long min = 1;
//    while (min < max)
//    {
//        long long num = 0;
//        long long mid = min + ((max - min) >> 1);
//        for (int i = 0; i < timeSize; i++)
//        {
//            //���������㣬����ȡ��
//            num += mid / time[i];
//        }
//        //���ڵ��ڲ������������ޣ���֮��������
//        if (num >= totalTrips)
//            max = mid;
//        else
//            min = mid + 1;
//    }
//
//    return min;
//}
//
////1103.���ǹ�
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* distributeCandies(int candies, int num_people, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * num_people);
//    memset(ans, 0, sizeof(int) * num_people);
//    for (int i = 0; ; i++)
//    {
//        if (candies >= i + 1)
//        {
//            ans[i % num_people] += i + 1;
//            candies -= i + 1;
//        }
//        else
//        {
//            ans[i % num_people] += candies;
//            break;
//        }
//    }
//
//    *returnSize = num_people;
//    return ans;
//}
//
//int* distributeCandies(int candies, int num_people, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * num_people);
//    memset(ans, 0, sizeof(int) * num_people);
//    //����ظ���
//    int n = (int)(sqrt(2 * candies + 0.25) - 0.5);
//    //printf("n = %d\n", n);
//    //��������
//    int m = n / num_people;
//    //printf("m = %d\n", m);
//    for (int i = 0; i < num_people; i++)
//    {
//        ans[i] = m * (i + 1) + m * (m - 1) / 2 * num_people;
//    }
//    //ʣ�µ��ǣ��������źͷ�ʣ�µ�
//    int left = n % num_people;
//    //printf("left = %d\n", left);
//    for (int i = 0; i < left; i++)
//    {
//        ans[i] += m * num_people + 1 + i;
//    }
//    ans[left] += candies - n * (n + 1) / 2;
//    //printf("ans[%d] = %d\n", left, ans[left]);
//    *returnSize = num_people;
//    return ans;
//}
//
////2591.��Ǯ�ָ����Ķ�ͯ
//
//int distMoney(int money, int children)
//{
//    //ÿ���˱���������1��Ԫ
//    if (money < children)
//        return -1;
//    //��Ǯ���㣬����ÿ����ƽ��8��Ԫ�����������һ����8��Ԫ��ʣ�µ�Ǯ����һ����
//    if (money > children * 8)
//        return children - 1;
//    //ʣ�µ�������ȷ�ÿ��1��Ԫ���ٿ��ּܷ�����7��Ԫ�ճ�8��Ԫ
//    //������Ƿ�ʣ��һ���˻������ַ��䷽�����õ�4��Ԫ�����������������һ�����õ�8��Ԫ��
//    money -= children;
//    int n = money / 7;
//    if (3 == money % 7 && n + 1 == children)
//        n--;
//    return n < 1 ? 0 : n;
//}
//
////1716.�����������е�Ǯ
//
//int totalMoney(int n)
//{
//    int week = n / 7;
//    int days = n % 7;
//    return days * (days + 1) / 2 + week * days + 7 * week * (week + 7) / 2;
//}
//
