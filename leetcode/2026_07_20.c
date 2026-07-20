//// 1620. 网络信号最好的坐标
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* bestCoordinate(int** towers, int towersSize, int* towersColSize, int radius, int* returnSize)
//{
//    int mx = 0, x0 = 0, y0 = 0;
//    for (int x = 0; x <= 50; x++)
//    {
//        for (int y = 0; y <= 50; y++)
//        {
//            int sum = 0;
//            for (int i = 0; i < towersSize; i++)
//            {
//                int x1 = towers[i][0], y1 = towers[i][1];
//                int d2 = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
//                if (d2 > radius * radius) continue;
//                int power = towers[i][2];
//                sum += power / (1 + sqrt(d2));
//            }
//            if (mx < sum)
//            {
//                x0 = x;
//                y0 = y;
//                mx = sum;
//            }
//            else if (mx == sum)
//            {
//                if (x0 > x || (x0 == x && y0 > y))
//                {
//                    x0 = x;
//                    y0 = y;
//                }
//            }
//        }
//    }
//
//    *returnSize = 2;
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    ans[0] = x0, ans[1] = y0;
//    return ans;
//}
//
