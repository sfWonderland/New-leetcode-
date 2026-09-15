//// 4049. 统计等间距出现整数数目 II
//
//typedef struct
//{
//    int key;
//    int pre;
//    int d;
//    int cnt;
//    UT_hash_handle hh;
//}HashItem;
//int countSpecialIntegers(int* nums, int numsSize)
//{
//    HashItem* equalDist = NULL;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = nums[i];
//        HashItem* p1 = NULL;
//        HASH_FIND_INT(equalDist, &x, p1);
//        if (p1 == NULL)
//        {
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = x;
//            p1->pre = i;
//            p1->d = 0;
//            p1->cnt = 0;
//            HASH_ADD_INT(equalDist, key, p1);
//        }
//        if (p1->cnt == -1) continue;
//        if (p1->pre + p1->d != i)
//        {
//            if (p1->d)
//            {
//                p1->cnt = -1;
//                continue;
//            }
//            p1->d = i - p1->pre;
//        }
//        p1->pre = i;
//        p1->cnt++;
//    }
//
//    int ans = 0;
//    HashItem* p0 = NULL, * tmp = NULL;
//    HASH_ITER(hh, equalDist, p0, tmp)
//    {
//        if (p0->cnt >= 3) ans++;
//        HASH_DEL(equalDist, p0);
//        free(p0);
//    }
//    return ans;
//}
//
//typedef struct
//{
//    int key;
//    int pre;
//    int d;
//    int cnt;
//    UT_hash_handle hh;
//}HashItem;
//int countSpecialIntegers(int* nums, int numsSize)
//{
//    HashItem* equalDist = NULL;
//    HashItem nodes[numsSize];
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = nums[i];
//        HashItem* p1 = NULL;
//        HASH_FIND_INT(equalDist, &x, p1);
//        if (p1 == NULL)
//        {
//            p1 = &nodes[i];
//            p1->key = x;
//            p1->pre = i;
//            p1->d = 0;
//            p1->cnt = 0;
//            HASH_ADD_INT(equalDist, key, p1);
//        }
//        if (p1->cnt == -1) continue;
//        if (p1->pre + p1->d != i)
//        {
//            if (p1->d)
//            {
//                p1->cnt = -1;
//                continue;
//            }
//            p1->d = i - p1->pre;
//        }
//        p1->pre = i;
//        p1->cnt++;
//    }
//
//    int ans = 0;
//    HashItem* p0 = NULL, * tmp = NULL;
//    HASH_ITER(hh, equalDist, p0, tmp)
//    {
//        if (p0->cnt >= 3) ans++;
//        HASH_DEL(equalDist, p0);
//    }
//    return ans;
//}
//
