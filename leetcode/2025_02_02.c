//#define _CRT_SECURE_NO_WARNINGS
//
////997.找到小镇的法官
//
//int findJudge(int n, int** trust, int trustSize, int* trustColSize)
//{
//    int suspect[n];
//    for (int i = 0; i < n; i++)
//        suspect[i] = 1;
//
//    for (int i = 0; i < trustSize; i++)
//        suspect[trust[i][0] - 1] = 0;
//
//
//    for (int i = 0; i < n; i++)
//    {
//        if (suspect[i])
//        {
//            int num = 0;
//            for (int j = 0; j < trustSize; j++)
//            {
//                if (i + 1 == trust[j][1])
//                    num++;
//            }
//            //printf("num = %d\n", num);
//            if (num == n - 1)
//                return i + 1;
//        }
//
//    }
//
//    return -1;
//}
//
//
////999.可以被一步捕获的棋子数
//
//int numRookCaptures(char** board, int boardSize, int* boardColSize)
//{
//    int RX = 0;
//    int RY = 0;
//    //search for the position of Castle
//    for (int i = 0; i < boardSize; i++)
//    {
//        for (int j = 0; j < *boardColSize; j++)
//        {
//            if ('R' == board[i][j])
//            {
//                RX = i;
//                RY = j;
//                break;
//            }
//        }
//    }
//    //check the possible move
//    int left = RX - 1;
//    int right = RX + 1;
//    int up = RY - 1;
//    int down = RY + 1;
//    int ret = 0;
//    //left
//    while (left >= 0)
//    {
//        //no barrier to pawns, ret + 1，stop;
//        if ('p' == board[left][RY])
//        {
//            ret++;
//            break;
//        }
//        //no barrier to Bishop, stop;
//        else if ('B' == board[left][RY])
//            break;
//        //no chess in this blank
//        left--;
//    }
//    //right
//    while (right < *boardColSize)
//    {
//        //no barrier to pawns, ret + 1，stop;
//        if ('p' == board[right][RY])
//        {
//            ret++;
//            break;
//        }
//        //no barrier to Bishop, stop;
//        else if ('B' == board[right][RY])
//            break;
//        //no chess in this blank
//        right++;
//    }
//    //up
//    while (up >= 0)
//    {
//        //no barrier to pawns, ret + 1，stop;
//        if ('p' == board[RX][up])
//        {
//            ret++;
//            break;
//        }
//        //no barrier to Bishop, stop;
//        else if ('B' == board[RX][up])
//            break;
//        //no chess in this blank
//        up--;
//    }
//    //down
//    while (down < boardSize)
//    {
//        //no barrier to pawns, ret + 1，stop;
//        if ('p' == board[RX][down])
//        {
//            ret++;
//            break;
//        }
//        //no barrier to Bishop, stop;
//        else if ('B' == board[RX][down])
//            break;
//        //no chess in this blank
//        down++;
//    }
//
//    return ret;
//}
//
////1005.K次取反后最大化的数组的数组和
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//
//int min(int a, int b)
//{
//    return a < b ? a : b;
//}
//int largestSumAfterKNegations(int* nums, int numsSize, int k)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int ret = 0;
//    if (nums[0] >= 0)
//    {
//        for (int i = 1; i < numsSize; i++)
//        {
//            ret += nums[i];
//        }
//        if (k % 2)
//            ret -= nums[0];
//        else
//            ret += nums[0];
//    }
//    else
//    {
//        int i = 0;
//        for (i = 0; i < numsSize; i++)
//        {
//            if (nums[i] >= 0)
//                break;
//            if (k)
//            {
//                nums[i] = -nums[i];
//                k--;
//            }
//            ret += nums[i];
//        }
//        int boundary = i;
//        for (; i < numsSize; i++)
//            ret += nums[i];
//        //discuss the remainder of k
//        if (k % 2)
//        {
//            if (boundary != numsSize)
//                ret -= min(nums[boundary], nums[boundary - 1]) * 2;
//            else
//                ret -= nums[boundary - 1] * 2;
//        }
//    }
//
//    return ret;
//}
//
////1009.十进制整数的补码
//
//int bitwiseComplement(int n)
//{
//    int t = 1;
//    int tmp = n;
//    while (tmp > 1)
//    {
//        tmp >>= 1;
//        t++;
//    }
//
//    return t < 31 ? (1 << t) - n - 1 : n ^ 0x7fffffff;
//
//}
//
////1025.除数博弈
//
//bool divisorGame(int n)
//{
//    return n % 2 - 1;
//}
//
////1037.有效的回旋镖
//
//bool isBoomerang(int** points, int pointsSize, int* pointsColSize)
//{
//    return (points[1][1] - points[0][1]) * (points[2][0] - points[0][0]) != (points[2][1] - points[0][1]) * (points[1][0] - points[0][0]);
//}
//
////1051.高度检查器
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int heightChecker(int* heights, int heightsSize)
//{
//    int expect[heightsSize];
//    for (int i = 0; i < heightsSize; i++)
//    {
//        expect[i] = heights[i];
//    }
//    qsort(expect, heightsSize, sizeof(int), cmp);
//
//    int error = 0;
//    for (int i = 0; i < heightsSize; i++)
//    {
//        if (expect[i] != heights[i])
//            error++;
//    }
//
//    return error;
//}
//
////1071.字符串的最大公因子
//
//int CommonFactor(int a, int b)
//{
//    while (a % b)
//    {
//        int tmp = b;
//        b = a % b;
//        a = tmp;
//    }
//    return b;
//}
//char* gcdOfStrings(char* str1, char* str2)
//{
//    int len1 = strlen(str1);
//    int len2 = strlen(str2);
//
//    int len3 = CommonFactor(len1, len2);
//    char str3[len3 + 1];
//    for (int i = 0; i < len3; i++)
//    {
//        str3[i] = str1[i];
//        printf("%c ", str3[i]);
//    }
//    str3[len3] = '\0';
//
//    for (int i = 0; i < len1; i++)
//    {
//        if (str1[i] != str3[i % len3])
//            return "";
//    }
//    for (int i = 0; i < len2; i++)
//    {
//        if (str2[i] != str3[i % len3])
//            return "";
//    }
//    str1[len3] = '\0';
//    return str1;
//
//}
//
////2413.最小偶倍数
//
//int smallestEvenMultiple(int n)
//{
//    return n % 2 ? n * 2 : n;
//}
//
////1952.三除数
//
//bool isThree(int n)
//{
//    if (4 == n || 9 == n || 25 == n || 49 == n || 121 == n || 169 == n || 289 == n || 361 == n || 23 * 23 == n || 29 * 29 == n || 31 * 31 == n || 37 * 37 == n || 41 * 41 == n || 43 * 43 == n || 47 * 47 == n || 53 * 53 == n || 59 * 59 == n || 61 * 61 == n || 67 * 67 == n || 71 * 71 == n || 73 * 73 == n || 53 * 53 == n || 79 * 79 == n || 83 * 83 == n || 89 * 89 == n || 97 * 97 == n)
//        return true;
//    else
//        return false;
//}
//
////1979.找出数组的最大公约数
//
//int CommonFactor(int a, int b)
//{
//    while (a % b)
//    {
//        int tmp = b;
//        b = a % b;
//        a = tmp;
//    }
//    return b;
//}
//
//int findGCD(int* nums, int numsSize)
//{
//    int min = 1001;
//    int max = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (max < nums[i])
//            max = nums[i];
//        if (min > nums[i])
//            min = nums[i];
//    }
//    return CommonFactor(max, min);
//}
//
////1089.复写零
//
//void duplicateZeros(int* arr, int arrSize)
//{
//    int top = 0;
//    int i = 0;
//    while (top < arrSize)
//    {
//        if (arr[i])
//            top++;
//        else
//            top += 2;
//        i++;
//    }
//
//    i--;
//    int j = arrSize - 1;
//    if (top == arrSize + 1)
//    {
//        arr[j] = 0;
//        i--;
//        j--;
//    }
//
//    while (j >= 0)
//    {
//        arr[j] = arr[i];
//        j--;
//        if (!arr[i])
//        {
//            arr[j] = arr[i];
//            j--;
//        }
//        i--;
//    }
//}
//
////1128.等价多诺米骨牌对的数量
//
//int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize)
//{
//    int num[100] = { 0 };
//    int ret = 0;
//    for (int i = 0; i < dominoesSize; i++)
//    {
//        int val = (dominoes[i][0] < dominoes[i][1]) ? dominoes[i][0] * 10 + dominoes[i][1] : dominoes[i][1] * 10 + dominoes[i][0];
//        ret += num[val];
//        num[val]++;
//    }
//
//    return ret;
//}
//
////1154.一年中的第几天
//
//bool is_leapYear(int yr)
//{
//    if (yr % 4)
//        return false;
//    else
//    {
//        if (yr % 100)
//            return true;
//        else if (0 == yr % 400)
//            return true;
//        else
//            return false;
//    }
//}
//int dayOfYear(char* date)
//{
//    int yr = 0;
//    for (int i = 0; i < 4; i++)
//    {
//        yr *= 10;
//        yr += date[i] - 48;
//    }
//    //printf("yr = %d\n", yr);
//    int month = (date[5] - 48) * 10 + date[6] - 48;
//    int day = 0;
//    switch (month)
//    {
//    case 12: day += 334 + is_leapYear(yr); break;
//    case 11: day += 304 + is_leapYear(yr); break;
//    case 10: day += 273 + is_leapYear(yr); break;
//    case 9: day += 243 + is_leapYear(yr); break;
//    case 8: day += 212 + is_leapYear(yr); break;
//    case 7: day += 181 + is_leapYear(yr); break;
//    case 6: day += 151 + is_leapYear(yr); break;
//    case 5: day += 120 + is_leapYear(yr); break;
//    case 4: day += 90 + is_leapYear(yr); break;
//    case 3: day += 59 + is_leapYear(yr); break;
//    case 2: day += 31; break;
//    }
//    //printf("day = %d\n", day);
//    day += (date[8] - 48) * 10 + date[9] - 48;
//    return day;
//}