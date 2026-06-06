//// 475. 供暖器
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//bool check(int* houses, int* heaters, int n, int m, int x)
//{
//    for (int i = 0, j = 0; i < n; i++)
//    {
//        // 超出heater[j]处的辐射右半径，就检查下一个加热器是否能辐射到当前房屋
//        while (j < m && houses[i] > heaters[j] + x)
//            j++;
//
//        // 当前房屋在heater[j]的辐射范围内，可以继续检查
//        // 上一个判断已经判断了房屋在heater[j] + x左边，只需判断房屋是否在heater[j]的左半径范围内
//        if (j < m && heaters[j] - x <= houses[i])
//            continue;
//        // 没有加热器可以辐射到当前房屋，该辐射半径太小，不可取
//        return false;
//    }
//    // 遍历完所有房屋，加热器都可以辐射到，该半径可以满足供暖需要
//    return true;
//}
//int findRadius(int* houses, int housesSize, int* heaters, int heatersSize)
//{
//    int n = housesSize, m = heatersSize;
//    // 将房屋序号和加热器序号从小到大排序
//    qsort(houses, n, sizeof(int), cmp);
//    qsort(heaters, m, sizeof(int), cmp);
//    int l = 0, r = (int)1e9;
//    while (l <= r)
//    {
//        int mid = (l + r) >> 1;
//        if (check(houses, heaters, n, m, mid))
//            r = mid - 1;
//        else
//            l = mid + 1;
//    }
//    return l;
//}
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int findRadius(int* houses, int housesSize, int* heaters, int heatersSize)
//{
//    int n = housesSize, m = heatersSize;
//    qsort(houses, n, sizeof(int), cmp);
//    qsort(heaters, m, sizeof(int), cmp);
//    int ans = 0;
//    for (int i = 0, j = 0; i < n; i++)
//    {
//        while (j < m - 1 && abs(houses[i] - heaters[j]) >= abs(houses[i] - heaters[j + 1]))
//            j++;
//
//        ans = fmax(ans, abs(houses[i] - heaters[j]));
//    }
//    return ans;
//}
//
