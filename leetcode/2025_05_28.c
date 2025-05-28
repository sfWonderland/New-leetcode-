////2410. 运动员和训练师的最大匹配数
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int matchPlayersAndTrainers(int* players, int playersSize, int* trainers, int trainersSize)
//{
//    qsort(players, playersSize, sizeof(int), cmp);
//    qsort(trainers, trainersSize, sizeof(int), cmp);
//    int n = 0;
//    for (int i = 0; i < trainersSize && n < playersSize; i++)
//    {
//        if (trainers[i] >= players[n])
//            n++;
//    }
//    return n;
//}
//
////1433. 检查一个字符串是否可以打破另一个字符串
//
//// int cmp(const void* e1, const void* e2)
//// {
////     return *(char*)e1 - *(char*)e2;
//// }
//// bool checkIfCanBreak(char* s1, char* s2) 
//// {
////     int n = strlen(s1);
////     qsort(s1, n, sizeof(char), cmp);
////     qsort(s2, n, sizeof(char), cmp);
////     int flag = 0;
////     for(int i = 0; i < n; i++)
////     {
////         if(s1[i] < s2[i])
////         {
////             flag = 1;
////             break;
////         }
////     }
////     if(flag == 0)
////     return true;
////     flag = 0;
////     for(int i = 0; i < n; i++)
////     {
////         if(s2[i] < s1[i])
////             return false;
////     }
//
////     return true;
//// }
//
//bool checkIfCanBreak(char* s1, char* s2)
//{
//    int hash[26] = { 0 };
//    for (int i = 0; s1[i]; i++)
//    {
//        hash[s1[i] - 'a']++;
//        hash[s2[i] - 'a']--;
//    }
//    int sum = 0;
//    bool max1 = true, max2 = true;
//    for (int i = 0; i < 26; i++)
//    {
//        sum += hash[i];
//        if (max1 && sum < 0) max1 = false;
//        if (max2 && sum > 0) max2 = false;
//        if (!max1 && !max2) return false;
//    }
//    return true;
//}
//
////3191. 使二进制数组全部等于 1 的最少操作次数 I
//
//int minOperations(int* nums, int numsSize)
//{
//    int times = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] == 0)
//        {
//            if (i > numsSize - 3)
//                return -1;
//
//            nums[i] ^= 1;
//            nums[i + 1] ^= 1;
//            nums[i + 2] ^= 1;
//            times++;
//        }
//    }
//    return times;
//}
//
////2027. 转换字符串的最少操作次数
//
//int minimumMoves(char* s)
//{
//    int n = strlen(s), ans = 0;
//    for (int i = 0; i < n - 2; i++)
//    {
//        if (s[i] == 'X')
//        {
//            s[i] = 'O';
//            s[i + 1] = 'O';
//            s[i + 2] = 'O';
//            ans++;
//        }
//    }
//    if (s[n - 2] == 'X' || s[n - 1] == 'X')
//        ans++;
//    return ans;
//}
//
