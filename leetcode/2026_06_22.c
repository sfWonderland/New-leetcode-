//// 3968. 移动后的最大曼哈顿距离
//
//int maxDistance(char* moves)
//{
//    int h = 0, x = 0, opt = 0;
//    for (int i = 0; moves[i]; i++)
//    {
//        if (moves[i] == 'U')
//            h++;
//        else if (moves[i] == 'D')
//            h--;
//        else if (moves[i] == 'L')
//            x--;
//        else if (moves[i] == 'R')
//            x++;
//        else
//            opt++;
//    }
//    h = h >= 0 ? h : -h;
//    x = x >= 0 ? x : -x;
//
//    return h + x + opt;
//}
//
//// 3969. 求和后首尾数字相同的有效子数组 I    
//
//int countValidSubarrays(int* nums, int numsSize, int x)
//{
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        long long sum = 0;
//        for (int j = i; j < numsSize; j++)
//        {
//            sum += nums[j];
//            if (sum % 10 != x)
//                continue;
//
//            long long tmp = sum;
//            while (tmp >= 10)
//                tmp /= 10;
//
//            ans += tmp == x;
//        }
//    }
//    return ans;
//}
//
