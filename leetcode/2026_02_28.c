////1921. 消灭怪物的最大数量
//
//int* d, * s;
//int cmp(const void* e1, const void* e2)
//{
//    int a = *(int*)e1, b = *(int*)e2;
//    return (d[a] + s[a] - 1) / s[a] - (d[b] + s[b] - 1) / s[b];
//}
//int eliminateMaximum(int* dist, int distSize, int* speed, int speedSize)
//{
//    int idx[distSize];
//    for (int i = 0; i < distSize; i++)
//    {
//        idx[i] = i;
//    }
//    d = dist; s = speed;
//    qsort(idx, distSize, sizeof(int), cmp);
//    for (int i = 0; i < distSize; i++)
//    {
//        int j = idx[i];
//        if (dist[j] <= speed[j] * i)
//            return i;
//    }
//    return distSize;
//}
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int eliminateMaximum(int* dist, int distSize, int* speed, int speedSize)
//{
//    int time[distSize];
//    for (int i = 0; i < distSize; i++)
//    {
//        time[i] = (dist[i] + speed[i] - 1) / speed[i];
//    }
//    qsort(time, distSize, sizeof(int), cmp);
//    for (int i = 0; i < distSize; i++)
//    {
//        if (time[i] <= i)
//            return i;
//    }
//    return distSize;
//}
//
//int eliminateMaximum(int* dist, int distSize, int* speed, int speedSize)
//{
//    int cnt[distSize + 1];
//    memset(cnt, 0, sizeof(cnt));
//    for (int i = 0; i < distSize; i++)
//    {
//        int x = fmin((dist[i] + speed[i] - 1) / speed[i], distSize);
//        cnt[x]++;
//    }
//    int ans = 0;
//    for (int i = 0; i < distSize; i++)
//    {
//        ans += cnt[i];
//        if (ans > i)
//            return i;
//    }
//    return distSize;
//}
//
//// 1936. 新增的最少台阶数   
//
//int addRungs(int* rungs, int rungsSize, int dist)
//{
//    int ans = (rungs[0] - 1) / dist;
//    for (int i = 1; i < rungsSize; i++)
//    {
//        if (rungs[i] - rungs[i - 1] > dist)
//            ans += (rungs[i] - rungs[i - 1] - 1) / dist;
//    }
//    return ans;
//}
//
////1958. 检查操作是否合法
//
//static const int dir[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
//bool checkMove(char** board, int boardSize, int* boardColSize, int rMove, int cMove, char color)
//{
//    int m = boardSize, n = boardColSize[0];
//    int x = rMove, y = cMove;
//    for (int i = 0; i < 8; i++)
//    {
//        int mx = x + dir[i][0];
//        int my = y + dir[i][1];
//        if (mx < 0 || mx >= m || my < 0 || my >= n || board[mx][my] != (color ^ 'B' ^ 'W'))
//            continue;
//        while (1)
//        {
//            mx += dir[i][0];
//            my += dir[i][1];
//            if (mx < 0 || mx >= m || my < 0 || my >= n || board[mx][my] == '.')
//                break;
//
//            if (board[mx][my] == color)
//                return true;
//        }
//    }
//    return false;
//}
//
////1980. 找出不同的二进制字符串
//
//int bitToI(char* num)
//{
//    int x = 0;
//    for (int i = 0; num[i]; i++)
//    {
//        x <<= 1;
//        x += num[i] - '0';
//    }
//    return x;
//}
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//char* findDifferentBinaryString(char** nums, int numsSize)
//{
//    char* ans = (char*)malloc(sizeof(char) * (numsSize + 1));
//    int arr[numsSize];
//    for (int i = 0; i < numsSize; i++)
//    {
//        arr[i] = bitToI(nums[i]);
//    }
//    ans[numsSize] = '\0';
//    qsort(arr, numsSize, sizeof(int), cmp);
//    int tmp = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (tmp == arr[i])
//            tmp++;
//        else
//            break;
//    }
//    for (int i = 0; i < numsSize; i++)
//    {
//        ans[numsSize - 1 - i] = (tmp & 1) + '0';
//        tmp >>= 1;
//    }
//    return ans;
//}
//
//// 康托对角线
//// 构造串的第i个字符和nums[i][i]不同，这个串就和所有的串都不同
//// 假设构造出来的串res和nums其中一个串相同，即res == nums[j]
//// 因为res[j]的字符和nums[j][j]不同，与假设矛盾
//char* findDifferentBinaryString(char** nums, int numsSize)
//{
//    char* ans = (char*)malloc(sizeof(char) * (numsSize + 1));
//    for (int i = 0; i < numsSize; i++)
//    {
//        ans[i] = '1' - nums[i][i] + '0';
//    }
//    ans[numsSize] = '\0';
//    return ans;
//}
//
