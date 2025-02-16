//#define _CRT_SECURE_NO_WARNINGS
//
////1544.整理字符串
//
//char* makeGood(char* s)
//{
//    int len = strlen(s);
//    char* ret = (char*)malloc(sizeof(char) * (len + 1));
//    ret[0] = s[0];
//    int j = 0;
//    for (int i = 1; i < len; i++)
//    {
//        if (j >= 0 && (ret[j] == s[i] + 32 || ret[j] == s[i] - 32))
//            j--;
//        else
//            ret[++j] = s[i];
//    }
//    ret[++j] = '\0';
//    return ret;
//}
//
////1556.千位分隔数
//
//int count_digit(int n)
//{
//    int cnt = 1;
//    while (n > 9)
//    {
//        cnt++;
//        n /= 10;
//    }
//    return cnt;
//}
//// char* thousandSeparator(int n) 
//// {
////     int cnt = count_digit(n);
////     int dot = (cnt - 1) / 3;
////     char* ret = (char*)malloc(sizeof(char) * (cnt + dot + 1));
////     //printf("cnt = %d, dot = %d\n", cnt, dot);
////     ret[cnt + dot] = '\0';
////     int i = cnt + dot - 1;
////     ret[i] = n % 10 + 48;
////     while(n > 9)
////     {
////         n /= 10;
////         ret[--i] = n % 10 + 48;
////         if(i > 0 && (cnt + dot + 1 - i) % 4 == 0)
////         ret[--i] = '.';
////         //printf("i = %d\n", i);
////     }
////     return ret;
//// }
//void reverse(char* s, int l, int r)
//{
//    while (l < r)
//    {
//        int tmp = s[l];
//        s[l++] = s[r];
//        s[r--] = tmp;
//    }
//}
//char* thousandSeparator(int n)
//{
//    int cnt = count_digit(n);
//    int dot = (cnt - 1) / 3;
//    char* ret = (char*)malloc(sizeof(char) * (cnt + dot + 1));
//    ret[cnt + dot] = '\0';
//    int i = 0;
//    do
//    {
//        ret[i++] = n % 10 + 48;
//        n /= 10;
//        if (n && i % 4 == 3)
//            ret[i++] = '.';
//    } while (n);
//    reverse(ret, 0, cnt + dot - 1);
//    return ret;
//}
//
////1582.二进制矩阵中的特殊位置
//
//int numSpecial(int** mat, int matSize, int* matColSize)
//{
//    int x[matSize];
//    memset(x, 0, sizeof(int) * matSize);
//    int y[*matColSize];
//    memset(y, 0, sizeof(int) * (*matColSize));
//    for (int i = 0; i < matSize; i++)
//    {
//        for (int j = 0; j < *matColSize; j++)
//        {
//            x[i] += mat[i][j];
//        }
//        //printf("x[%d] = %d\n", i, x[i]);
//    }
//    for (int i = 0; i < *matColSize; i++)
//    {
//        for (int j = 0; j < matSize; j++)
//        {
//            y[i] += mat[j][i];
//        }
//        //printf("y[%d] = %d\n", i, y[i]);
//    }
//    int n = 0;
//    for (int i = 0; i < matSize; i++)
//    {
//        for (int j = 0; j < *matColSize; j++)
//        {
//            if ((mat[i][j]) && (x[i] == 1) && (y[j] == 1))
//                n++;
//        }
//    }
//    return n;
//}