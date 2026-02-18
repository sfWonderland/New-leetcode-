////893. 特殊等价字符串组
//
//typedef struct
//{
//    char* key; // 先奇数位后偶数位
//    UT_hash_handle hh;
//}HashItem;
//int cmp(const void* e1, const void* e2)
//{
//    return *(char*)e1 - *(char*)e2;
//}
//int numSpecialEquivGroups(char** words, int wordsSize)
//{
//    HashItem* cnt = NULL;
//    int n = strlen(words[0]);
//    char* odd = (char*)malloc(sizeof(char) * (n + 2) / 2);
//    char* even = (char*)malloc(sizeof(char) * (n + 3) / 2);
//    odd[n / 2] = '\0'; even[(n + 1) / 2] = '\0';
//    for (int i = 0; i < wordsSize; i++)
//    {
//        int lenO = 0, lenE = 0;
//        for (int j = 0; j < n; j++)
//        {
//            if (j % 2)
//                odd[lenO++] = words[i][j];
//            else
//                even[lenE++] = words[i][j];
//        }
//        qsort(odd, lenO, sizeof(char), cmp);
//        qsort(even, lenE, sizeof(char), cmp);
//        char s[n + 1];
//        sprintf(s, "%s%s", odd, even);
//        HashItem* p1 = NULL;
//        HASH_FIND_STR(cnt, s, p1);
//        if (p1 == NULL)
//        {
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = (char*)malloc(sizeof(char) * (n + 1));
//            strcpy(p1->key, s);
//            HASH_ADD_STR(cnt, key, p1);
//        }
//    }
//    HashItem* p1 = NULL, * tmp = NULL;
//    int ans = 0;
//    HASH_ITER(hh, cnt, p1, tmp)
//    {
//        ans++;
//        HASH_DEL(cnt, p1);
//        free(p1->key);
//        free(p1);
//    }
//    return ans;
//}
//
////874. 模拟行走机器人    
//
//typedef struct
//{
//    int key;
//    UT_hash_handle hh;
//}HashItem;
//const int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // 上北右东下南左西
//int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize)
//{
//    int aspect = 0, x = 0, y = 0;
//    HashItem* obs = NULL;
//    for (int i = 0; i < obstaclesSize; i++)
//    {
//        int key = obstacles[i][0] * 60001 + obstacles[i][1];
//        HashItem* p1 = (HashItem*)malloc(sizeof(HashItem));
//        p1->key = key;
//        HASH_ADD_INT(obs, key, p1);
//    }
//    int ans = 0;
//    for (int i = 0; i < commandsSize; i++)
//    {
//        if (commands[i] < 0)
//        {
//            // aspect = (aspect + d) % 4;
//            // commands[i] == -2, d = 3, commands[i] == -1, d = 1;
//            aspect = (aspect - 2 * commands[i] - 1) % 4;
//        }
//
//        for (int d = 0; d < commands[i]; d++)
//        {
//            int key = (x + dir[aspect][0]) * 60001 + y + dir[aspect][1];
//            HashItem* p1 = NULL;
//            HASH_FIND_INT(obs, &key, p1);
//            if (p1)
//                break;
//
//            x += dir[aspect][0];
//            y += dir[aspect][1];
//        }
//        ans = fmax(ans, x * x + y * y);
//    }
//    return ans;
//}
//
////849. 到最近的人的最大距离
//
//int maxDistToClosest(int* seats, int seatsSize)
//{
//    int n = seatsSize;
//    int dist[n];
//    memset(dist, 0x3f, sizeof(dist));
//    int d = n;
//    for (int i = 0; i < n; i++)
//    {
//        if (seats[i] == 1)
//            d = 0;
//
//        dist[i] = d++;
//    }
//    d = n;
//    int ans = 0;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        if (seats[i] == 1)
//            d = 0;
//
//        dist[i] = fmin(d++, dist[i]);
//        ans = fmax(ans, dist[i]);
//    }
//    return ans;
//}
//
////973. 最接近原点的 K 个点
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int* dist;
//int cmp(const void* e1, const void* e2)
//{
//    return dist[*(int*)e1] - dist[*(int*)e2];
//}
//int** kClosest(int** points, int pointsSize, int* pointsColSize, int k, int* returnSize, int** returnColumnSizes)
//{
//    int n = pointsSize;
//    int idx[n];
//    for (int i = 0; i < n; i++)
//    {
//        idx[i] = i;
//    }
//    dist = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        dist[i] = points[i][0] * points[i][0] + points[i][1] * points[i][1];
//    }
//    qsort(idx, n, sizeof(int), cmp);
//    int** ans = (int**)malloc(sizeof(int*) * k);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * k);
//    *returnSize = k;
//    for (int i = 0; i < k; i++)
//    {
//        ans[i] = points[idx[i]];
//        (*returnColumnSizes)[i] = 2;
//    }
//    return ans;
//}
//
