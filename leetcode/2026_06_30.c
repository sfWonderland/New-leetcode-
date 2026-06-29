//// 785. ÅÐ¶Ï¶þ·ÖÍ¼
//
//bool isBipartite(int** graph, int graphSize, int* graphColSize)
//{
//    int n = graphSize;
//    int colors[n];
//    memset(colors, 0, sizeof(colors));
//    bool dfs(int x, int c)
//    {
//        colors[x] = c;
//        for (int i = 0; i < graphColSize[x]; i++)
//        {
//            int y = graph[x][i];
//            if (colors[y] == c || (colors[y] == 0 && !dfs(y, -c)))
//                return false;
//        }
//        return true;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        if (colors[i] == 0 && !dfs(i, 1))
//            return false;
//    }
//    return true;
//}
//
