////2269. 找到一个数字的 K 美丽值
//T(N) = O(logN)
//int divisorSubstrings(int num, int k)
//{
//    long m = 1;
//    while (k)
//    {
//        m *= 10;
//        k--;
//    }
//    int t = num;
//    int n = 0;
//    while (t >= m / 10)
//    {
//        int tmp = t % m;
//        //printf("tmp = %d\n", tmp);
//        n += ((tmp != 0) && (0 == num % tmp));
//        t /= 10;
//    }
//    return n;
//}
//
////1837. K 进制表示下的各位数字总和
//T(N) = O(logN)
//int sumBase(int n, int k)
//{
//    int sum = 0;
//    while (n)
//    {
//        sum += n % k;
//        n /= k;
//    }
//    return sum;
//}
//
////1854. 人口最多的年份
//T(N) = O(N)
//int maximumPopulation(int** logs, int logsSize, int* logsColSize)
//{
//    //差分法
//    int delta[101] = { 0 };
//    int offset = 1950;
//    //出生年加1，死亡年减1
//    for (int i = 0; i < logsSize; i++)
//    {
//        delta[logs[i][0] - offset]++;
//        delta[logs[i][1] - offset]--;
//    }
//    //从前到后统计人数最大年
//    int max = 0;
//    int yr = 0;
//    int current = 0;
//    for (int i = 0; i <= 100; i++)
//    {
//        if (0 == delta[i])
//            continue;
//        current += delta[i];
//        if (max < current)
//        {
//            max = current;
//            yr = i;
//        }
//    }
//    //加上本底值
//    return yr + offset;
//}
//
////1832. 判断句子是否为全字母句
//
//////方法一：数组
//////T(n) = O(n+C)
//// bool checkIfPangram(char* sentence) 
//// {
////     int len = strlen(sentence);
////     if(sentence < 26)
////     return false;
//
////     int alpha[26] = {0};
////     for(int i = 0; i < len; i++)
////     {
////         alpha[sentence[i] - 'a'] = 1;
////     }
////     for(int i = 0; i < 26; i++)
////     {
////         if(0 == alpha[i])
////         return false;
////     }
////     return true;
//// }
//
////方法二：二进制表示集合
////T(n) = O(n) 
//bool checkIfPangram(char* sentence)
//{
//    int exist = 0;
//    for (int i = 0; sentence[i]; i++)
//    {
//        exist |= 1 << (sentence[i] - 'a');
//    }
//    return exist == (1 << 26) - 1;
//}
//
