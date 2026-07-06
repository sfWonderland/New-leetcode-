//// 789. ÌÓÍÑ×è°­Õß
//
//int dist(int x1, int y1, int x2, int y2)
//{
//    return abs(x1 - x2) + abs(y1 - y2);
//}
//bool escapeGhosts(int** ghosts, int ghostsSize, int* ghostsColSize, int* target, int targetSize)
//{
//    int cur = dist(0, 0, target[0], target[1]);
//    for (int i = 0; i < ghostsSize; i++)
//    {
//        if (dist(ghosts[i][0], ghosts[i][1], target[0], target[1]) <= cur)
//            return false;
//    }
//    return true;
//}
//
