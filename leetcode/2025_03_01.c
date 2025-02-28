////LCR 139. ÑµÁ·¼Æ»® I
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//void swap(int* a, int* b)
//{
//    int t = *a;
//    *a = *b;
//    *b = t;
//}
//int* trainingPlan(int* actions, int actionsSize, int* returnSize)
//{
//    int left = 0;
//    int right = actionsSize - 1;
//    while (left < right)
//    {
//        while (left < right & actions[left] % 2)
//            left++;
//        while (left < right & 0 == actions[right] % 2)
//            right--;
//        if (left < right)
//            swap(&actions[left], &actions[right]);
//    }
//    *returnSize = actionsSize;
//    return actions;
//}
//
////LCR 126. ì³²¨ÄÇÆõÊý
//
//#define mod 1000000007;
//int fib(int n)
//{
//    if (n < 2)
//        return n;
//    int a = 0;
//    int b = 1;
//    while (n - 1)
//    {
//        int t = b;
//        b = (a + b) % mod;
//        a = t;
//        n--;
//    }
//    return b;
//}
//
////LCR 127. ÌøÔ¾ÑµÁ·
//
//#define mod 1000000007;
//int trainWays(int num)
//{
//    int a = 0;
//    int b = 0;
//    int ret = 0;
//    for (int i = 0; i < num; i++)
//    {
//        if (i <= 1)
//            ret = i + 1;
//        else
//            ret = (a + b) % mod;
//
//        b = a;
//        a = ret;
//    }
//    return ret ? ret : 1;
//}
//
////LCR 186. ÎÄÎï³¯´úÅÐ¶Ï
//
//// bool checkDynasty(int* places, int placesSize) 
//// {
////     int h[14] = {0};
////     int min = 14;
////     int max = 0;
////     for(int i = 0; i < placesSize; i++)
////     {
////         if(0 == places[i])
////         continue;
////         if(0 == h[places[i]])
////         h[places[i]]++;
////         else
////         return false;
////         max = places[i] > max ? places[i] : max;
////         min = places[i] < min ? places[i] : min;
////     }
////     return max - min < 5;
//// }
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//bool checkDynasty(int* places, int placesSize)
//{
//    qsort(places, placesSize, sizeof(int), cmp);
//    int unknown = 0;
//    for (int i = 0; i < placesSize - 1; i++)
//    {
//        if (0 == places[i])
//            unknown++;
//        else if (0 == places[i + 1] - places[i])
//            return false;
//    }
//    return places[placesSize - 1] - places[unknown] < 5;
//}
//
