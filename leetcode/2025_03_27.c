//2094. �ҳ� 3 λż��

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool may_be_formed(const int* hash, const int hashSize, int x)
{
    int h[10] = { 0 };
    while (x)
    {
        int t = x % 10;
        h[t]++;
        if (h[t] > hash[t])
            return false;
        x /= 10;
    }
    return true;
}
int* findEvenNumbers(int* digits, int digitsSize, int* returnSize)
{
    int h[10] = { 0 };
    for (int i = 0; i < digitsSize; i++)
    {
        h[digits[i]]++;
    }
    int* res = (int*)malloc(sizeof(int) * 450);
    int n = 0;
    for (int i = 100; i < 1000; i += 2)
    {
        if (may_be_formed(h, 10, i))
            res[n++] = i;
    }
    returnSize[0] = n;
    return res;
}

//2124. ����Ƿ����� A ���� B ֮ǰ

// bool checkString(char* s) 
// {
//     int flag = 0;
//     for(int i = 0; s[i]; i++)    
//     {
//         if(0 == flag && s[i] == 'b')
//         flag = 1;
//         if(flag && s[i] == 'a')
//         return false;
//     }
//     return true;
// }

bool checkString(char* s)
{
    return strstr(s, "ba") == 0;
}

//2220. ת�����ֵ�����λ��ת����

int minBitFlips(int start, int goal)
{
    int t = start ^ goal;
    int n = 0;
    while (t)
    {
        t &= t - 1;
        n++;
    }
    return n;
}

//3370. ������λλ����С����

int smallestNumber(int n)
{
    int t = 1;
    while (n > t)
        t = (t << 1) + 1;
    return t;
}

