//#define _CRT_SECURE_NO_WARNINGS
//
////1408.数组中的字符串匹配
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** stringMatching(char** words, int wordsSize, int* returnSize)
//{
//    char** p = (char**)malloc(sizeof(char*) * wordsSize);
//    int n = 0;
//    for (int i = 0; i < wordsSize; i++)
//    {
//        for (int j = 0; j < wordsSize; j++)
//        {
//            if (i != j && strstr(words[j], words[i]))
//            {
//                p[n++] = words[i];
//                break;
//            }
//        }
//    }
//
//    *returnSize = n;
//    return p;
//}
//
////1413.逐步求和得到正数的最小值
//
//int minStartValue(int* nums, int numsSize)
//{
//    int sum = 0;
//    int min = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//        if (min > sum)
//            min = sum;
//    }
//
//    return 1 - min;
//}
//
////1512.好数对的数目
//
//int numIdenticalPairs(int* nums, int numsSize)
//{
//    int hash[100] = { 0 };
//    for (int i = 0; i < numsSize; i++)
//    {
//        hash[nums[i] - 1]++;
//    }
//    int ret = 0;
//    for (int i = 0; i < 100; i++)
//    {
//        if (hash[i] > 1)
//            ret += (hash[i] * (hash[i] - 1)) >> 1;
//    }
//    return ret;
//}
//
////1417. 重新格式化字符串
//
//char* reformat(char* s)
//{
//    if (!s[1])
//        return s;
//    int len = strlen(s);
//    int letter = 0;
//    int num = 0;
//    for (int i = 0; i < len; i++)
//    {
//        if (s[i] >= 'a' && s[i] <= 'z')
//            letter++;
//        else
//            num++;
//    }
//    //printf("letter = %d, num = %d\n", letter, num);
//    if ((abs(letter - num)) > 1)
//        return "";
//
//    char l = 'a';
//    char r = 'z';
//    if (letter < num)
//    {
//        l = '0';
//        r = '9';
//    }
//    int a = 0;
//    int b = 1;
//    char* p = (char*)malloc(sizeof(char) * (len + 1));
//    p[len] = '\0';
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] >= l && s[i] <= r)
//        {
//            p[a] = s[i];
//            a += 2;
//        }
//        else
//        {
//            p[b] = s[i];
//            b += 2;
//        }
//    }
//    return p;
//}
//
////859.亲密字符串
//
//bool buddyStrings(char* s, char* goal)
//{
//    //比较长度
//    int len = strlen(s);
//    int leng = strlen(goal);
//    if (len != leng || 1 == len)
//        return false;
//    if (2 == len)
//        return (s[0] == goal[1] && s[1] == goal[0]);
//    //比较哈希表
//    int hash[26] = { 0 };
//    int hash1[26] = { 0 };
//    int num = 0;
//    for (int i = 0; i < len; i++)
//    {
//        if (s[i] != goal[i])
//            num++;
//        if (num > 2)
//            return false;
//        hash[s[i] - 'a']++;
//        hash1[goal[i] - 'a']++;
//    }
//    int max = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        if (hash[i] != hash1[i])
//            return false;
//        if (max < hash[i])
//            max = hash[i];
//    }
//    if (num != 2 && max < 2)
//        return false;
//    else
//        return true;
//}
//
////1790. 仅执行一次字符串交换能否使两个字符串相等
//
//bool areAlmostEqual(char* s1, char* s2)
//{
//    int num = 0;
//    int diff[2] = { 0 };
//    for (int i = 0; s1[i]; i++)
//    {
//        if (s1[i] != s2[i])
//        {
//            if (num >= 2)
//                return false;
//            diff[num++] = i;
//        }
//    }
//
//    if (!num)
//        return true;
//
//    if (num != 2)
//        return false;
//
//    return s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]];
//}
//
////16.15. master-mind-lcci 珠玑妙算
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* masterMind(char* solution, char* guess, int* returnSize)
//{
//    int* answer = (int*)malloc(sizeof(int) * 2);
//    memset(answer, 0, sizeof(int) * 2);
//    int hashs[26] = { 0 };
//    int hashg[26] = { 0 };
//    for (int i = 0; guess[i]; i++)
//    {
//        if (solution[i] == guess[i])
//            answer[0]++;
//        else
//        {
//            hashs[solution[i] - 'A']++;
//            hashg[guess[i] - 'A']++;
//        }
//    }
//    for (int i = 0; i < 26; i++)
//    {
//        if (1 == i || 6 == i || 17 == i || 24 == i)
//            answer[1] += hashs[i] > hashg[i] ? hashg[i] : hashs[i];
//    }
//    *returnSize = 2;
//    return answer;
//}
//
////1422.分割字符串的最大得分
//
//int maxScore(char* s)
//{
//    int len = strlen(s);
//    int num = 0;
//    for (int i = 0; i < len; i++)
//    {
//        if (s[i] == '1')
//            num++;
//    }
//    int max = 0;
//    for (int i = 0; i < len - 1; i++)
//    {
//        if (s[i] == '1')
//            num--;
//        else
//            num++;
//        if (num > max)
//            max = num;
//    }
//    return max;
//}
//
////1629. 按键持续时间最长的键
//
//char slowestKey(int* releaseTimes, int releaseTimesSize, char* keysPressed)
//{
//    char ret = keysPressed[0];
//    int max = releaseTimes[0];
//    for (int i = 1; i < releaseTimesSize; i++)
//    {
//        int t = releaseTimes[i] - releaseTimes[i - 1];
//        if (t > max)
//        {
//            max = t;
//            ret = keysPressed[i];
//        }
//        else if (t == max && keysPressed[i] > ret)
//            ret = keysPressed[i];
//    }
//
//    return ret;
//}