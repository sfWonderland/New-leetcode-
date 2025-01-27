//#define _CRT_SECURE_NO_WARNINGS
//
////762.二进制表示中质数个计算置位
//
//bool is_prime(int n)
//{
//    if (2 == n || 3 == n || 5 == n || 7 == n || 11 == n || 13 == n || 17 == n || 19 == n)
//        return true;
//    else
//        return false;
//}
//int count_digit(int n)
//{
//    int count = 0;
//    while (n)
//    {
//        n &= (n - 1);
//        count++;
//    }
//
//    return count;
//}
//int countPrimeSetBits(int left, int right)
//{
//    int count = 0;
//    for (int i = left; i <= right; i++)
//    {
//        if (is_prime(count_digit(i)))
//            count++;
//        //printf("i = %d, count = %d\n", i, count);
//    }
//    return count;
//}
//
////766.托普利茨矩阵
//
//bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize)
//{
//    for (int i = 1; i < matrixSize; i++)
//    {
//        for (int j = 1; j < *matrixColSize; j++)
//        {
//            if (matrix[i][j] != matrix[i - 1][j - 1])
//                return false;
//        }
//    }
//    return true;
//}
//
////771.宝石与石头
//
//int numJewelsInStones(char* jewels, char* stones)
//{
//    int lenj = strlen(jewels);
//    int lens = strlen(stones);
//    int count = 0;
//    for (int i = 0; i < lenj; i++)
//    {
//        for (int j = 0; j < lens; j++)
//        {
//            if (stones[j] == jewels[i])
//                count++;
//        }
//    }
//    return count;
//}
//
////796.旋转字符串
//
//bool rotateString(char* s, char* goal)
//{
//    int len = strlen(s);
//    int leng = strlen(goal);
//    if (len != leng)
//        return false;
//    char dbs[2 * len + 1];
//    for (int i = 0; i < 2 * len; i++)
//    {
//        if (i < len)
//            dbs[i] = s[i];
//        else
//            dbs[i] = s[i - len];
//
//        //printf("dbs[%d] = %c\n", i, dbs[i]);
//    }
//    dbs[2 * len] = 0;
//
//    if (strstr(dbs, goal) != NULL)
//        return true;
//    else
//        return false;
//}
//
////2103.环和杆
//
//int countPoints(char* rings)
//{
//    int len = strlen(rings) / 2;
//    //define rings in different colors
//    int red[10];
//    int green[10];
//    int blue[10];
//    for (int i = 0; i < 10; i++)
//    {
//        red[i] = 0;
//        green[i] = 0;
//        blue[i] = 0;
//    }
//    //search all
//    for (int i = 0; i < len; i++)
//    {
//        if ('R' == rings[2 * i])
//            red[rings[2 * i + 1] - 48]++;
//        else if ('G' == rings[2 * i])
//            green[rings[2 * i + 1] - 48]++;
//        else
//            blue[rings[2 * i + 1] - 48]++;
//    }
//    //check three colors
//    int count = 0;
//    for (int i = 0; i < 10; i++)
//    {
//        if (red[i] && green[i] && blue[i])
//            count++;
//    }
//    //return
//    return count;
//}
//
////1941.检查是否所有字符的出现次数相同
//
//bool areOccurrencesEqual(char* s)
//{
//    int len = strlen(s);
//    int hash[26] = { 0 };
//    for (int i = 0; i < len; i++)
//    {
//        hash[s[i] - 'a']++;
//    }
//
//    int n = hash[s[0] - 'a'];
//    for (int i = 0; i < 26; i++)
//    {
//        if (hash[i] != 0 && hash[i] != n)
//            return false;
//    }
//    return true;
//}
//
////1047.删除字符串中的所有相邻重复项
//
//char* removeDuplicates(char* s)
//{
//    int len = strlen(s);
//    char copy[len];
//    for (int i = 0; i < len; i++)
//    {
//        copy[i] = s[i];
//    }
//
//    for (int i = 0; i < len - 1; i++)
//    {
//        while (i < len - 1 && (!copy[i]))
//            i++;
//        if (i >= len - 1)
//            break;
//        if (copy[i] == copy[i + 1])
//        {
//            int left = i - 1;
//            int right = i + 2;
//            copy[i] = 0;
//            copy[i + 1] = 0;
//            while (left >= 0 && right <= len - 1)
//            {
//                while (left >= 0 && (!copy[left]))
//                    left--;
//                while (right <= len - 1 && (!copy[right]))
//                    right++;
//                if (left < 0 || right > len - 1)
//                    break;
//                if (copy[left] == copy[right])
//                {
//                    copy[left] = 0;
//                    copy[right] = 0;
//                    left--;
//                    right++;
//                }
//                else
//                    break;
//            }
//        }
//    }
//
//    int j = 0;
//    for (int i = 0; i < len; i++)
//    {
//        if (copy[i] != 0)
//            s[j++] = copy[i];
//    }
//    s[j] = 0;
//    return s;
//}
//
////2716.最小化字符串长度
//
//int minimizedStringLength(char* s)
//{
//    int len = strlen(s);
//    int hash[26] = { 0 };
//    for (int i = 0; i < len; i++)
//    {
//        hash[s[i] - 'a']++;
//    }
//
//    int count = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        if (hash[i])
//            count++;
//    }
//    return count;
//}
