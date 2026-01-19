////2062. 统计字符串中的元音子字符串
//
//int countVowelSubstrings(char* word)
//{
//    int ans = 0;
//    for (char* s = strtok(word, "bcdfghjklmnpqrstvwxyz"); s; s = strtok(NULL, "bcdfghjklmnpqrstvwxyz"))
//    {
//        printf("%s\n", s);
//        int n = strlen(s);
//        if (n < 5)
//            continue;
//        int left = 0;
//        int cnt[26] = { 0 };
//        for (int right = 0; right < n; right++)
//        {
//            cnt[s[right] - 'a']++;
//            while (cnt[s[left] - 'a'] > 1)
//            {
//                cnt[s[left] - 'a']--;
//                left++;
//            }
//
//            if (cnt[0] && cnt[4] && cnt[8] && cnt[14] && cnt[20])
//                ans += left + 1;
//        }
//    }
//    return ans;
//}
//
////2452. 距离字典两次编辑以内的单词    
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** twoEditWords(char** queries, int queriesSize, char** dictionary, int dictionarySize, int* returnSize)
//{
//    int n = queriesSize, m = dictionarySize;
//    int len[m];
//    for (int i = 0; i < m; i++)
//    {
//        len[i] = strlen(dictionary[i]);
//    }
//    char** ans = (char**)malloc(sizeof(char*) * n);
//    *returnSize = 0;
//    for (int i = 0; i < n; i++)
//    {
//        char* word = queries[i];
//        int x = strlen(word);
//        bool flag = false;
//        for (int j = 0; j < m; j++)
//        {
//            if (len[j] != x)
//                continue;
//
//            char* pattern = dictionary[j];
//            int t = 2, k;
//            for (k = 0; k < x; k++)
//            {
//                if (word[k] != pattern[k])
//                {
//                    if (t > 0)
//                        t--;
//                    else
//                        break;
//                }
//            }
//            if (k == x)
//            {
//                flag = true;
//                break;
//            }
//        }
//        if (flag)
//            ans[(*returnSize)++] = word;
//    }
//    return ans;
//}
//
////2924. 找到冠军 II
//
//int findChampion(int n, int** edges, int edgesSize, int* edgesColSize)
//{
//    int cnt[n];
//    memset(cnt, 0, sizeof(int) * n);
//    for (int i = 0; i < edgesSize; i++)
//    {
//        cnt[edges[i][1]]++;
//    }
//    int ans = -1;
//    for (int i = 0; i < n; i++)
//    {
//        if (cnt[i])
//            continue;
//
//        if (ans != -1)
//            return -1;
//
//        ans = i;
//    }
//    return ans;
//}
//
////2596. 检查骑士巡视方案
//
//int dir[8][2] = { {-2, -1}, {-2, 1}, {-1, 2}, {-1, -2}, {1, -2}, {1, 2}, {2, 1}, {2, -1} };
//bool checkValidGrid(int** grid, int gridSize, int* gridColSize)
//{
//    if (grid[0][0])
//        return false;
//    int n = gridSize;
//    int m = n * n, k = 0, x = 0, y = 0;
//    while (k < m - 1)
//    {
//        int i = 0;
//        for (; i < 8; i++)
//        {
//            int mx = x + dir[i][0];
//            int my = y + dir[i][1];
//            if (mx >= 0 && mx < n && my >= 0 && my < n && grid[mx][my] == k + 1)
//            {
//                x = mx; y = my; k++;
//                break;
//            }
//        }
//        if (i == 8)
//            return false;
//    }
//    return true;
//}
//
