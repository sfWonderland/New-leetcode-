////2895. ��С����ʱ��
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int minProcessingTime(int* processorTime, int processorTimeSize, int* tasks, int tasksSize)
//{
//    qsort(processorTime, processorTimeSize, sizeof(int), cmp);
//    qsort(tasks, tasksSize, sizeof(int), cmp);
//
//    int ans = 0;
//    for (int i = 0; i < processorTimeSize; i++)
//    {
//        ans = fmax(ans, processorTime[i] + tasks[tasksSize - 1 - 4 * i]);
//    }
//    return ans;
//}
//
////1753. �Ƴ�ʯ�ӵ����÷�
//
//int maximumScore(int a, int b, int c)
//{
//    int max = fmax(c, fmax(a, b));
//    int min = fmin(c, fmin(a, b));
//    int mid = a + b + c - max - min;
//
//    return mid + min >= max ? (mid + min + max) / 2 : mid + min;
//}
//
////3216. �������ֵ�����С���ַ���
//
//char* getSmallestString(char* s)
//{
//    int n = strlen(s);
//    for (int i = 0; i < n - 1; i++)
//    {
//        if (s[i + 1] < s[i] && ((s[i] - s[i + 1]) & 1) == 0)
//        {
//            char tmp = s[i];
//            s[i] = s[i + 1];
//            s[i + 1] = tmp;
//            break;
//        }
//    }
//    return s;
//}
//
////2697. �ֵ�����С���Ĵ�
//
//char* makeSmallestPalindrome(char* s)
//{
//    int n = strlen(s);
//    int left = 0, right = n - 1;
//    while (left < right)
//    {
//        if (s[left] > s[right])
//            s[left] = s[right];
//        else if (s[left] < s[right])
//            s[right] = s[left];
//        left++;
//        right--;
//    }
//    return s;
//}
//
////2929. ��С�����Ƿ��ǹ� II
//
//long long C2(long long n)
//{
//    return n > 1 ? n * (n - 1) / 2 : 0;
//}
//long long distributeCandies(int n, int limit)
//{
//    return C2(n + 2) - 3 * C2(n - limit + 1) + 3 * C2(n - 2 * limit) - C2(n - 3 * limit - 1);
//}
//
