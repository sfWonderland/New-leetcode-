//#define _CRT_SECURE_NO_WARNINGS
//
////1175.��������
//#define MOD 1000000007
//int numPrime(int n)
//{
//    int prime[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//    for (int i = 0; i < 25; i++)
//    {
//        if (n < prime[i])
//            return i;
//    }
//    return 25;
//}
//
//long factorial(int n) {
//    long res = 1;
//    for (int i = 1; i <= n; i++)
//    {
//        res *= i;
//        res %= MOD;
//    }
//    return res;
//}
//
//int numPrimeArrangements(int n)
//{
//    int nump = numPrime(n);
//    int numc = n - nump;
//    return (int)(factorial(nump) * factorial(numc) % MOD);
//}
//
////1184.����վ��ľ���
//
//int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination)
//{
//    if (start < destination)
//    {
//        int tmp = start;
//        start = destination;
//        destination = tmp;
//    }
//
//    int left = start;
//    int right = start;
//    int sumL = 0;
//    int sumR = 0;
//    while (1)
//    {
//        if (left != destination)
//        {
//            sumL += distance[left - 1];
//            left--;
//        }
//        if (right - distanceSize != destination)
//        {
//            if (right < distanceSize)
//                sumR += distance[right];
//            else
//                sumR += distance[right - distanceSize];
//            right++;
//        }
//        //printf("sumL = %d, sumR = %d\n", sumL, sumR);
//        if ((left == destination) && (right - distanceSize == destination))
//            break;
//    }
//
//    return sumL < sumR ? sumL : sumR;
//}
//
////1185.һ���еĵڼ���
//
//char* dayOfTheWeek(int day, int month, int year)
//{
//    //Thur. 1970.12.31
//    //the distance from the year to 1971
//    int dst = year - 1971;
//    //1461 days per 4 years
//    //rough culculation, remainder years : 365 days per year, 30 days per month 
//    int sum = (dst / 4 * 1461) + (dst % 4) * 365 + (month - 1) * 30 + day;
//    if ((dst % 4 > 1) || ((1 == dst % 4 && year != 2100) && month > 2))
//        sum++;
//    switch (month)
//    {
//    case 2: sum++; break;
//    case 3: sum--; break;
//    case 6: sum++; break;
//    case 7: sum++; break;
//    case 8: sum += 2; break;
//    case 9: sum += 3; break;
//    case 10: sum += 3; break;
//    case 11: sum += 4; break;
//    case 12: sum += 4; break;
//    }
//
//    sum %= 7;
//    switch (sum)
//    {
//    case 0: return "Thursday"; break;
//    case 1: return "Friday"; break;
//    case 2: return "Saturday"; break;
//    case 3: return "Sunday"; break;
//    case 4: return "Monday"; break;
//    case 5: return "Tuesday"; break;
//    case 6: return "Wednesday"; break;
//    }
//
//    return "Error";
//}
//
//char* dayOfTheWeek(int day, int month, int year)
//{
//    //Thur. 1970.12.31
//    char* week[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
//    int monthdays[11] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
//    //the distance from the year - 1 to 1971
//    int days = (year - 1971) * 365 + (year - 1969) / 4;
//    //from 12.31 to the last day of the last month. 
//    for (int i = 0; i < month - 1; ++i)
//        days += monthdays[i];
//    if (((0 == year % 400) || (0 == year % 4) && (0 != year % 100)) && (month > 2))
//        days++;
//    //from the last day of the last month to the day
//    days += day;
//
//    //printf("days = %d\n", days);
//    return week[(days + 4) % 7];
//}
//
////1189.�����򡱵��������
//
//int maxNumberOfBalloons(char* text)
//{
//    int len = strlen(text);
//    int hash[5] = { 0 };
//    for (int i = 0; i < len; i++)
//    {
//        if ('a' == text[i])
//            hash[0]++;
//        else if ('b' == text[i])
//            hash[1]++;
//        else if ('l' == text[i])
//            hash[2]++;
//        else if ('n' == text[i])
//            hash[3]++;
//        else if ('o' == text[i])
//            hash[4]++;
//    }
//    hash[2] /= 2;
//    hash[4] /= 2;
//
//    int ret = hash[0];
//    for (int i = 1; i < 5; i++)
//    {
//        if (hash[i] < ret)
//            ret = hash[i];
//    }
//
//    return ret;
//}
//
////1207.��һ�޶��ĳ��ִ���
//
//bool uniqueOccurrences(int* arr, int arrSize)
//{
//    int hash1[2001] = { 0 };
//    int hash2[1000] = { 0 };
//    for (int i = 0; i < arrSize; i++)
//    {
//        hash1[arr[i] + 1000]++;
//    }
//    for (int i = 0; i <= 2000; i++)
//    {
//        if (hash1[i] != 0)
//        {
//            if (0 == hash2[hash1[i] - 1])
//                hash2[hash1[i] - 1]++;
//            else
//                return false;
//        }
//    }
//    return true;
//}
//
////1266.�������е����Сʱ��
//
//int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize)
//{
//    int sum = 0;
//    for (int i = 1; i < pointsSize; i++)
//    {
//        int dx = abs(points[i][0] - points[i - 1][0]);
//        int dy = abs(points[i][1] - points[i - 1][1]);
//        sum += dx > dy ? dx : dy;
//    }
//
//    return sum;
//}
//
////1688.�����е���Դ���
//
//int numberOfMatches(int n)
//{
//    int sum = 0;
//    while (n > 1)
//    {
//        int t = n / 2;
//        sum += t;
//        n -= t;
//    }
//
//    return sum;
//}
//
////2549.ͳ�������ϵĲ�ͬ����
//
//int distinctIntegers(int n)
//{
//    return n > 1 ? n - 1 : 1;
//}
//
////������10.05 Sparse Array Search LCCIϡ����������
//˼·
//������������ȫ�棬�޸Ĳ�����������ԣ����ּ����bug���ʡ�
//�����������λ���е���к��Լ��ĵ��ԣ����ó��Ľ����
//������ʱ�临�Ӷ�O(N)
//���ֲ��ң�ʱ�临�Ӷ�O(LogN)
//������������������⣬�����������������ʵ���ϻ�������⡣���ύͨ�����ԣ��������ַ����Կɣ����͵����϶��ԣ��Ǵ���bug�ġ�
//���磺�޸����еĲ�������
//��words[5] = ������Ϊ��a����words[7] = ��car����Ϊ��aar��
//words =
//["at", "", "", "", "ball", "a", "", "aar", "", "", "dad", "", ""]
//s =
//"at"
//�����᷵�ؽ����4���������ĺܶ���ֲ��ҷ���ⶼ�᷵�ء� - 1���������Խ����֧�ֺ��ߣ�����һ�����Ե�bug��
//�������
//�����Թ��������ܶ��ֲ��ҷ������ṩһ��˼·��
//??
////������ʱ�临�Ӷ�O(n)
//int findString(char** words, int wordsSize, char* s)
//{
//    for (int i = 0; i < wordsSize; ++i)
//    {
//        if (strcmp(words[i], s) == 0)
//            return i;
//    }
//    return -1;
//}
////mid������s�ַ��������������ٷֱ���ֲ��ң�ʱ�临�Ӷ�O(logN)
//int BinarySearch(char** words, int left, int right, char* s)
//{
//    int mid = 0;
//    while (left <= right)
//    {
//        while (left <= right && 0 == strcmp(words[left], ""))
//            left++;
//        if (left > right)
//            break;
//        while (right >= 0 && 0 == strcmp(words[right], ""))
//            right--;
//        if (right < 0)
//            break;
//
//        mid = ((right - left) >> 1) + left;
//        //mid����λ�ò�Ϊs
//        if (0 != strcmp(words[mid], s))
//        {
//            //���ҷֱ���ֲ���
//            int retLeft = BinarySearch(words, left, mid - 1, s);
//            int retRight = BinarySearch(words, mid + 1, right, s);
//            //����з����±����±�һ����-1�󣬶�Ϊ-1�򷵻��ĸ���һ��
//            return retLeft > retRight ? retLeft : retRight;
//        }
//        //mid����λ��Ϊs
//        else
//            return mid;
//    }
//    return -1;
//}
//
//int findString(char** words, int wordsSize, char* s)
//{
//    return BinarySearch(words, 0, wordsSize - 1, s);
//}
//
////��bug����ȫ���Ͻ�����Ķ��ֲ��ң�ʱ�临�Ӷ�O(logN)��
////��mid�������ǿ��ַ�������midΪs��ֱ�ӷ���mid���±ꡣ
////��ǰ�߲�ͬ�ĵط����ڣ���mid������sʱ�����ȽϽ��С��s������˵�����mid + 1��
////���ȽϽ������s�����Ҷ˵�����mid - 1��
////������©��һ��������bug��
//int findString(char** words, int wordsSize, char* s)
//{
//
//    int left = 0;
//    int right = wordsSize - 1;
//    int mid = 0;
//    while (left <= right)
//    {
//        while (left < wordsSize && 0 == strcmp(words[left], ""))
//            left++;
//        if (left >= wordsSize)
//            break;
//        while (right >= 0 && 0 == strcmp(words[right], ""))
//            right--;
//        if (right < 0)
//            break;
//
//        mid = ((right - left) >> 1) + left;
//        while (mid < right && 0 == strcmp(words[mid], ""))
//            mid++;
//
//        if (strcmp(words[mid], s) < 0)
//            left = mid + 1;
//        else if (strcmp(words[mid], s) > 0)
//            right = mid - 1;
//        else
//            return mid;
//    }
//
//    return -1;
//}
