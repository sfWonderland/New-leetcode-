////2110. 股票平滑下跌阶段的数目
//
//long long getDescentPeriods(int* prices, int pricesSize)
//{
//    long long ans = 0;
//    int pre = -1, j = -1;
//    for (int i = 0; i < pricesSize; i++)
//    {
//        if (prices[i] != pre - 1)
//            j = i - 1;
//        ans += i - j;
//        pre = prices[i];
//    }
//    return ans;
//}
//
////705. 设计哈希集合
//
//typedef struct
//{
//    bool* nums;
//} MyHashSet;
//
//
//MyHashSet* myHashSetCreate()
//{
//    MyHashSet* obj = (MyHashSet*)malloc(sizeof(MyHashSet));
//    obj->nums = (bool*)calloc(sizeof(bool), 1000001);
//    return obj;
//}
//
//void myHashSetAdd(MyHashSet* obj, int key)
//{
//    obj->nums[key] = 1;
//}
//
//void myHashSetRemove(MyHashSet* obj, int key)
//{
//    obj->nums[key] = 0;
//}
//
//bool myHashSetContains(MyHashSet* obj, int key)
//{
//    return obj->nums[key];
//}
//
//void myHashSetFree(MyHashSet* obj)
//{
//    free(obj->nums);
//    free(obj);
//}
//
///**
// * Your MyHashSet struct will be instantiated and called as such:
// * MyHashSet* obj = myHashSetCreate();
// * myHashSetAdd(obj, key);
//
// * myHashSetRemove(obj, key);
//
// * bool param_3 = myHashSetContains(obj, key);
//
// * myHashSetFree(obj);
//*/
//
////706. 设计哈希映射
//
//typedef struct
//{
//    int* nums;
//} MyHashMap;
//
//
//MyHashMap* myHashMapCreate()
//{
//    MyHashMap* obj = (MyHashMap*)malloc(sizeof(MyHashMap));
//    obj->nums = (int*)calloc(sizeof(int), 1000001);
//    return obj;
//}
//
//void myHashMapPut(MyHashMap* obj, int key, int value)
//{
//    obj->nums[key] = value + 1;
//}
//
//int myHashMapGet(MyHashMap* obj, int key)
//{
//    if (obj->nums[key])
//        return obj->nums[key] - 1;
//
//    return -1;
//}
//
//void myHashMapRemove(MyHashMap* obj, int key)
//{
//    obj->nums[key] = 0;
//}
//
//void myHashMapFree(MyHashMap* obj)
//{
//    free(obj->nums);
//    free(obj);
//}
//
///**
// * Your MyHashMap struct will be instantiated and called as such:
// * MyHashMap* obj = myHashMapCreate();
// * myHashMapPut(obj, key, value);
//
// * int param_2 = myHashMapGet(obj, key);
//
// * myHashMapRemove(obj, key);
//
// * myHashMapFree(obj);
//*/
//
////697. 数组的度
//
//int findShortestSubArray(int* nums, int numsSize)
//{
//    long long hash[50000] = { 0 };
//    int max_cnt = 0, ans = numsSize;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (hash[nums[i]] == 0)
//            hash[nums[i]] = 1ll * (i + 1) * 50000;
//
//        hash[nums[i]]++;
//        int cnt = hash[nums[i]] % 50000;
//        if (max_cnt <= cnt)
//        {
//            int l = hash[nums[i]] / 50000 - 1;
//            if (max_cnt < cnt)
//            {
//                max_cnt = cnt;
//                ans = i - l + 1;
//            }
//            else
//                ans = fmin(ans, i - l + 1);
//        }
//    }
//
//    return ans;
//}
//
