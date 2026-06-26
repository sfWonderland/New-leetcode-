//// 3020. 子集中元素的最大数量
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int maximumLength(int* nums, int numsSize)
//{
//    HashItem* cnt = NULL;
//    HashItem* p1 = NULL;
//    for (int i = 0; i < numsSize; i++)
//    {
//        HASH_FIND_INT(cnt, &nums[i], p1);
//        if (p1 == NULL)
//        {
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = nums[i];
//            p1->val = 0;
//            HASH_ADD_INT(cnt, key, p1);
//        }
//        p1->val++;
//    }
//    int t = 1;
//    HASH_FIND_INT(cnt, &t, p1);
//    int ans = p1 ? (p1->val - 1) | 1 : 1;
//    if (p1) p1->val = 0;
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, cnt, p1, tmp)
//    {
//        int x = p1->key;
//        int sum = 0;
//        while (p1 && p1->val >= 2)
//        {
//            sum += 2;
//            if (x >= 32000)
//            {
//                p1 = NULL;
//                break;
//            }
//            x *= x;
//            HASH_FIND_INT(cnt, &x, p1);
//        }
//        ans = fmax(ans, p1 ? sum + 1 : sum - 1);
//    }
//    HASH_ITER(hh, cnt, p1, tmp)
//    {
//        free(p1);
//    }
//    return ans;
//}
//
