//// 939. 最小面积矩形
//
//typedef struct
//{
//    int key;
//    UT_hash_handle hh;
//}HashItem;
//int minAreaRect(int** points, int pointsSize, int* pointsColSize)
//{
//    int n = pointsSize;
//    HashItem* pointSet = NULL;
//    HashItem* p0 = NULL;
//    for (int i = 0; i < n; i++)
//    {
//        p0 = (HashItem*)malloc(sizeof(HashItem));
//        p0->key = 40001 * points[i][0] + points[i][1];
//        HASH_ADD_INT(pointSet, key, p0);
//    }
//
//    int ans = INT_MAX;
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = i + 1; j < n; ++j)
//        {
//            // 找对角点
//            if (points[i][0] != points[j][0] && points[i][1] != points[j][1])
//            {
//                HashItem* p1 = NULL, * p2 = NULL;
//                int x = 40001 * points[i][0] + points[j][1];
//                int y = 40001 * points[j][0] + points[i][1];
//                HASH_FIND_INT(pointSet, &x, p1);
//                HASH_FIND_INT(pointSet, &y, p2);
//                if (p1 && p2)
//                    ans = fmin(ans, abs(points[j][0] - points[i][0])
//                        * abs(points[j][1] - points[i][1]));
//            }
//        }
//    }
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, pointSet, p0, tmp)
//    {
//        HASH_DEL(pointSet, p0);
//        free(p0);
//    }
//    return ans < INT_MAX ? ans : 0;
//}
//
