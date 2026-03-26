////3084. 统计以给定字符开头和结尾的子字符串总数
//
//long long countSubstrings(char* s, char c)
//{
//    int cnt = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] == c)
//            cnt++;
//    }
//    return 1ll * cnt * (cnt + 1) / 2;
//}
//
////3096. 得到更多分数的最少关卡数目    
//
//int minimumLevels(int* possible, int possibleSize)
//{
//    int suf = 0;
//    for (int i = 0; i < possibleSize; i++)
//    {
//        suf += possible[i] ? 1 : -1;
//    }
//    int pre = 0, ans = -1;
//    for (int i = 0; i < possibleSize - 1; i++)
//    {
//        int t = possible[i] ? 1 : -1;
//        pre += t;
//        suf -= t;
//        if (pre > suf)
//        {
//            ans = i + 1;
//            break;
//        }
//    }
//    return ans;
//}
//
////3105. 最长的严格递增或递减子数组
//
//int longestMonotonicSubarray(int* nums, int numsSize)
//{
//    int inc = 1, dec = 1, ans = 1;
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (nums[i] > nums[i - 1])
//        {
//            inc++;
//            dec = 1;
//        }
//        else if (nums[i] < nums[i - 1])
//        {
//            dec++;
//            inc = 1;
//        }
//        else
//        {
//            dec = 1;
//            inc = 1;
//        }
//        ans = fmax(ans, fmax(dec, inc));
//    }
//    return ans;
//}
//
////3127. 构造相同颜色的正方形
//
//bool canMakeSquare(char** grid, int gridSize, int* gridColSize)
//{
//    bool check(int x, int y)
//    {
//        int cnt[2] = { 0 };
//        for (int i = 0; i < 2; i++)
//        {
//            for (int j = 0; j < 2; j++)
//            {
//                int k = grid[x + i][y + j] == 'B';
//                cnt[k]++;
//            }
//        }
//        return cnt[0] - cnt[1];
//    }
//    for (int i = 0; i < gridSize - 1; i++)
//    {
//        for (int j = 0; j < gridColSize[0] - 1; j++)
//        {
//            if (check(i, j))
//                return true;
//        }
//    }
//    return false;
//}
//
