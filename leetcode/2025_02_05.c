//#define _CRT_SECURE_NO_WARNINGS
//
////1221.分割平衡字符串
//
//int balancedStringSplit(char* s)
//{
//    int d = 0;
//    int sum = 0;
//
//    for (int i = 0; s[i]; i++)
//    {
//        s[i] == 'L' ? ++d : --d;
//        if (!d)
//            sum++;
//    }
//
//    return sum;
//}
//
////1232.缀点成线
//
//bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize)
//{
//    if (2 == coordinatesSize)
//        return true;
//
//    int dx0 = coordinates[1][0] - coordinates[0][0];
//    int dy0 = coordinates[1][1] - coordinates[0][1];
//
//    for (int i = 2; i < coordinatesSize; i++)
//    {
//        int dxi = coordinates[i][0] - coordinates[0][0];
//        int dyi = coordinates[i][1] - coordinates[0][1];
//        if (dxi * dy0 != dx0 * dyi)
//            return false;
//    }
//
//    return true;
//}
//
////3038.相同分数的最大操作数目
//
//int maxOperations(int* nums, int numsSize)
//{
//    int ret = 0;
//    for (int i = 1; i < numsSize; i += 2)
//    {
//        if (nums[0] + nums[1] != nums[i - 1] + nums[i])
//            break;
//
//        ret++;
//    }
//
//    return ret;
//}
//
////1252.奇数值单元格的数目
//
//int oddCells(int m, int n, int** indices, int indicesSize, int* indicesColSize)
//{
//    int arr[m][n];
//    memset(arr, 0, sizeof(arr));
//    for (int i = 0; i < indicesSize; i++)
//    {
//        //X line
//        for (int j = 0; j < n; j++)
//        {
//            arr[indices[i][0]][j]++;
//        }
//        //Y line
//        for (int k = 0; k < m; k++)
//        {
//            arr[k][indices[i][1]]++;
//        }
//    }
//
//    int sum = 0;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (arr[i][j] % 2)
//                sum++;
//        }
//    }
//    return sum;
//}
//
////1275.找出井字棋的胜利者
//
//char* tictactoe(int** moves, int movesSize, int* movesColSize)
//{
//    char* result[4] = { "A", "B", "Draw", "Pending" };
//    char chess[3][3] = { 0 };
//    for (int i = 0; i < movesSize; i++)
//    {
//        chess[moves[i][0]][moves[i][1]] = 'A';
//        if (i % 2)
//            chess[moves[i][0]][moves[i][1]]++;
//    }
//
//    for (int i = 0; i < 3; i++)
//    {
//        if (chess[i][0] && chess[i][0] == chess[i][1] && chess[i][0] == chess[i][2])
//            return chess[i][0] == 'A' ? result[0] : result[1];
//
//        if (chess[0][i] && chess[0][i] == chess[1][i] && chess[0][i] == chess[2][i])
//            return chess[0][i] == 'A' ? result[0] : result[1];
//    }
//    if (chess[0][0] && chess[0][0] == chess[1][1] && chess[0][0] == chess[2][2])
//        return chess[0][0] == 'A' ? result[0] : result[1];
//    if (chess[2][0] && chess[0][2] == chess[1][1] && chess[2][0] == chess[1][1])
//        return chess[0][2] == 'A' ? result[0] : result[1];
//
//    return 9 == movesSize ? result[2] : result[3];
//}
//
////2525.根据规则将箱子分类
//
//char* categorizeBox(int length, int width, int height, int mass)
//{
//    int bigger = length > width ? length : width;
//    int max = bigger > height ? bigger : height;
//    char* result[4] = { "Both", "Neither", "Bulky", "Heavy" };
//    int flag = 0;
//    if (max >= 10000)
//        flag = 1;
//    else
//    {
//        long long vol = (long long)length * width * height;
//        if (vol >= 1000000000)
//            flag = 1;
//    }
//
//    if (mass >= 100)
//        return flag ? result[0] : result[3];
//    else
//        return flag ? result[2] : result[1];
//}
//
////2347.最好的扑克手牌
//
//char* bestHand(int* ranks, int ranksSize, char* suits, int suitsSize)
//{
//    int flush = 1;
//    for (int i = 1; i < suitsSize; i++)
//    {
//        if (suits[i] != suits[i - 1])
//        {
//            flush = 0;
//            break;
//        }
//    }
//    if (flush)
//        return "Flush";
//    else
//    {
//        int hashr[13] = { 0 };
//        for (int i = 0; i < ranksSize; i++)
//        {
//            hashr[ranks[i] - 1]++;
//        }
//
//        int num = 0;
//        for (int i = 0; i < 13; i++)
//        {
//            if (hashr[i] > 2)
//                return "Three of a Kind";
//            else if (1 == hashr[i])
//                num++;
//        }
//
//        if (5 == num)
//            return "High Card";
//    }
//    return "Pair";
//}
//
////1281.整数的各位积和之差
//
//int subtractProductAndSum(int n)
//{
//    int multi = 1;
//    int sum = 0;
//    while (n)
//    {
//        int tmp = n % 10;
//        sum += tmp;
//        multi *= tmp;
//        n /= 10;
//    }
//
//    return multi - sum;
//}
//
////1287.有序数组中出现次数超过25%的元素
//
//int findSpecialInteger(int* arr, int arrSize)
//{
//    int step = arrSize / 4;
//    for (int i = step; i < arrSize; i++)
//    {
//        if (arr[i] == arr[i - step])
//            return arr[i];
//    }
//    return -1;
//}
//
////1295.统计位数为偶数的数字
//
//int get_digit(int n)
//{
//    int sum = 1;
//    while (n > 9)
//    {
//        n /= 10;
//        sum++;
//    }
//    return sum;
//}
//int findNumbers(int* nums, int numsSize)
//{
//    int ret = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (0 == get_digit(nums[i]) % 2)
//            ret++;
//    }
//    return ret;
//}
//
////3232.判断是否可以赢得数字游戏
//
//bool canAliceWin(int* nums, int numsSize)
//{
//    int sdigit = 0;
//    int ddigit = 0;
//
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] > 9)
//            ddigit += nums[i];
//        else
//            sdigit += nums[i];
//    }
//
//    return sdigit != ddigit;
//}
//
////1309.解码字母到整数映射
//
//char* freqAlphabets(char* s)
//{
//    int len = strlen(s);
//    char* str = malloc(sizeof(char) * (len + 1));
//    int i = 0;
//    int cnt = 0;
//    while (i < len)
//    {
//        if (i < len - 2 && '#' == s[i + 2])
//        {
//            str[cnt++] = 'a' + (s[i] - '0') * 10 + s[i + 1] - '1';
//            i += 3;
//        }
//        else
//        {
//            str[cnt++] = 'a' + s[i] - '1';
//            i++;
//        }
//        //printf("%d ", i);
//    }
//
//    str[cnt] = '\0';
//    return str;
//}