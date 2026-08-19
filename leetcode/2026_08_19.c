//// 392. 判断子序列
//
//bool isSubsequence(char* s, char* t)
//{
//    if (!s[0]) return true;
//    int i = 0;
//    for (int j = 0; t[j]; j++)
//    {
//        if (t[j] == s[i] && !s[++i])
//            return true;
//    }
//    return false;
//}
//
//#define SIGMA 26
//
//bool isSubsequence(char* s, char* t)
//{
//    int n = strlen(t);
//    int (*nxt)[SIGMA] = malloc((n + 1) * sizeof(int[SIGMA]));
//    for (int j = 0; j < SIGMA; j++)
//    {
//        nxt[n][j] = n;
//    }
//    for (int i = n - 1; i >= 0; i--)
//    {
//        memcpy(nxt[i], nxt[i + 1], SIGMA * sizeof(int));
//        nxt[i][t[i] - 'a'] = i;
//    }
//    int i = -1;
//    for (int j = 0; s[j] && i < n; j++)
//    {
//        i = nxt[i + 1][s[j] - 'a'];
//    }
//    free(nxt);
//    return i < n;
//}
//
//// 4024. 最近的可用无人机
//
//int nearestDrone(int** drones, int dronesSize, int* dronesColSize, int* target, int targetSize)
//{
//    int ans = -1, dist = INT_MAX;
//    int x0 = target[0], y0 = target[1];
//    for (int i = 0; i < dronesSize; i++)
//    {
//        int x = drones[i][0];
//        int y = drones[i][1];
//        int scope = drones[i][2];
//        int d = abs(x - x0) + abs(y - y0);
//        if (d <= scope && dist > d)
//        {
//            dist = d;
//            ans = i;
//        }
//    }
//    return ans;
//}
//
//// 4025. 交通灯的最大等待时间
//
//int minPenalty(int period, int* lights, int lightsSize, int* arrivalTime, int arrivalTimeSize)
//{
//    int mx = 0;
//    for (int i = 0; i < lightsSize; i++)
//    {
//        mx = fmax(lights[i], mx);
//    }
//    int ans = 0;
//    for (int i = 0; i < arrivalTimeSize; i++)
//    {
//        int r = arrivalTime[i] % period;
//        if (r < mx) continue;
//        ans = fmax(ans, period - r);
//    }
//    return ans;
//}
//
//// 4026. 工位的最大间隔
//
//int maximumGap(char* skill, char* station)
//{
//    int n = strlen(skill);
//    int suf[n];
//    int j = strlen(station) - 1;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        while (station[j] != skill[i])
//            j--;
//        // 保证skill为station子序列前提下，skill下标i的字母在station中最右的位置
//        suf[i] = j--;
//    }
//    int ans = 0;
//    int pre = 0;
//    for (int i = 0; i < n - 1; i++)
//    {
//        // 保证skill为station子序列前提下，skill下标i的字母在station中最左的位置
//        while (station[pre] != skill[i])
//            pre++;
//        // 计算两个字母间最大间隔
//        ans = fmax(ans, suf[i + 1] - pre);
//        // 用过的字母要划走
//        pre++;
//    }
//    return ans;
//}
//
