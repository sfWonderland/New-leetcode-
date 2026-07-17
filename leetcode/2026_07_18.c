//// 1591. 奇怪的打印机 II
//
//// 该题目主要考察拓扑排序，但建图前需要根据矩阵颜色分布进行处理，提取出有效信息来建图。
//// 主要难点在于提取矩阵信息。主要需要提取出现的矩阵颜色，各个颜色的矩阵大小范围。
//// 然后根据大小范围，确定各个颜色涂色需要的先后顺序。具体为外部先涂，内部后涂
//// 根据以上信息建图，然后按照一般的拓扑排序题目的做法。
//// 确定将入度为0的各点不断去掉后，最后各点都能消除，说明满足题意。
//#define COLORS 61
//bool isPrintable(int** targetGrid, int targetGridSize, int* targetGridColSize)
//{
//    // 确定各个颜色的矩形范围，注意赋值
//    int m = targetGridSize, n = targetGridColSize[0];
//    int* up = (int*)malloc(sizeof(int) * COLORS);
//    memset(up, 0x3f, sizeof(int) * COLORS);
//    int* down = (int*)calloc(sizeof(int), COLORS);
//    int* left = (int*)malloc(sizeof(int) * COLORS);
//    memset(left, 0x3f, sizeof(int) * COLORS);
//    int* right = (int*)calloc(sizeof(int), COLORS);
//    // 记录已出现颜色
//    int* points = (int*)malloc(sizeof(int) * COLORS);
//    int k = 0;
//    // 用数组模拟哈希表，映射颜色编号和已出现颜色编号
//    int* pos = (int*)malloc(sizeof(int) * COLORS);
//    memset(pos, 0x3f, sizeof(int) * COLORS);
//    // 遍历矩阵
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            int color = targetGrid[i][j];
//            // 将未出现的颜色加入数组
//            if (pos[color] == 0x3f3f3f3f)
//            {
//                pos[color] = k;
//                points[k++] = color;
//            }
//            // 确定颜色矩阵边界
//            up[color] = fmin(up[color], i);
//            down[color] = fmax(down[color], i);
//            left[color] = fmin(left[color], j);
//            right[color] = fmax(right[color], j);
//        }
//    }
//    // 根据已出现颜色建图
//    int** grid = (int**)malloc(sizeof(int*) * k);
//    int* capacity = (int*)malloc(sizeof(int) * k);
//    int* len = (int*)malloc(sizeof(int) * k);
//    for (int i = 0; i < k; i++)
//    {
//        capacity[i] = 8;
//        grid[i] = (int*)malloc(sizeof(int) * capacity[i]);
//        len[i] = 0;
//    }
//    // 记录遍历每一中颜色过程出现过的颜色，这些颜色需要在当前颜色后面才能涂色，这样构成拓扑有向图
//    bool* vis = (bool*)calloc(sizeof(bool), k);
//    // 记录各颜色的入度
//    int* cnt = (int*)calloc(sizeof(int), k);
//    for (int x = 0; x < k; x++)
//    {
//        vis[x] = true;
//        // 需要将编号映射到具体颜色，才能确定该颜色矩阵范围
//        int color0 = points[x];
//        // 遍历该颜色矩阵内的各个颜色，构建有向图
//        for (int i = up[color0]; i <= down[color0]; i++)
//        {
//            for (int j = left[color0]; j <= right[color0]; j++)
//            {
//                int color = targetGrid[i][j];
//                // 从颜色映射到编号
//                int y = pos[color];
//                // 将未出现过的结点加到有向图
//                if (!vis[y])
//                {
//                    vis[y] = true;
//                    cnt[y]++;
//                    grid[x][len[x]++] = y;
//                    if (len[x] >= capacity[x])
//                    {
//                        capacity[x] *= 2;
//                        grid[x] = (int*)realloc(grid[x], sizeof(int) * capacity[x]);
//                    }
//                }
//            }
//        }
//        // 每一种颜色遍历结束后，需要将访问信息重置
//        memset(vis, 0, sizeof(bool) * k);
//    }
//    // bfs遍历，从入度为0的结点开始遍历，遍历结束后各结点入度全为0说明满足拓扑结构，满足先后顺序
//    int* queue = (int*)malloc(sizeof(int) * k);
//    int rear = 0, front = 0;
//    // 入度不为0的结点数，初始为结点数
//    int count = k;
//    // 将入度为0的结点加入队列
//    for (int i = 0; i < k; i++)
//    {
//        if (cnt[i] == 0)
//            queue[rear++] = i;
//    }
//    // 遍历队列
//    while (rear > front)
//    {
//        int x = queue[front++];
//        // 每遍历一个结点，将入度不为0的结点数减1
//        count--;
//        // 消除当前结点指向各后继结点的指针
//        for (int i = 0; i < len[x]; i++)
//        {
//            int y = grid[x][i];
//            // 将处理后入度为0的结点加入队列
//            if (--cnt[y] == 0)
//                queue[rear++] = y;
//        }
//    }
//    // 将各个动态分配的内存释放
//    free(up);
//    free(down);
//    free(left);
//    free(right);
//    free(pos);
//    free(points);
//    for (int i = 0; i < k; i++)
//        free(grid[i]);
//    free(capacity);
//    free(len);
//    free(vis);
//    free(cnt);
//    free(queue);
//    // 最后的有向图如果入度全为0说明满足拓扑排序，可以满足先后涂色的题目要求
//    return count == 0;
//}
