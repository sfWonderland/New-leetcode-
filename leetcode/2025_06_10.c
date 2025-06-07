////2745. 构造最长的新字符串
//
//int longestString(int x, int y, int z)
//{
//    return x >= y ? (y * 2 + (x > y) + z) * 2 : (2 * x + 1 + z) * 2;
//}
//
////3442. 奇偶频次间的最大差值 I
//
//int maxDifference(char* s)
//{
//    int cnt[26] = { 0 };
//    for (int i = 0; s[i]; i++)
//    {
//        cnt[s[i] - 'a']++;
//    }
//    int a1 = -1, a2 = INT_MAX;
//    for (int i = 0; i < 26; i++)
//    {
//        if (cnt[i] & 1)
//            a1 = fmax(a1, cnt[i]);
//        else if (cnt[i])
//            a2 = fmin(a2, cnt[i]);
//    }
//    a2 = a2 == INT_MAX ? 0 : a2;
//    return a1 - a2;
//}
//
////1899. 合并若干三元组以形成目标三元组
//
//bool mergeTriplets(int** triplets, int tripletsSize, int* tripletsColSize, int* target, int targetSize)
//{
//    bool flag[3] = { 0 };
//    for (int i = 0; i < tripletsSize; i++)
//    {
//        if (triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2])
//            continue;
//
//        for (int k = 0; k < targetSize; k++)
//        {
//            if (triplets[i][k] == target[k])
//                flag[k] = 1;
//        }
//    }
//
//    return flag[0] && flag[1] && flag[2];
//}
//
////2498. 青蛙过河 II
//
//int maxJump(int* stones, int stonesSize)
//{
//    if (stonesSize < 3)
//        return stones[1] - stones[0];
//
//    int odd = 0, even = 0;
//    for (int i = 2; i < stonesSize; i++)
//    {
//        if (i & 1) odd = fmax(odd, stones[i] - stones[i - 2]);
//        else even = fmax(even, stones[i] - stones[i - 2]);
//    }
//    return fmax(odd, even);
//}
//
