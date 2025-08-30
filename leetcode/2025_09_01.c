////2342. 数位和相等数对的最大和
//
//int maximumSum(int* nums, int numsSize)
//{
//    int ans = -1;
//    int hash[82] = { 0 };
//    for (int i = 0; i < numsSize; i++)
//    {
//        int s = 0, x = nums[i];
//        while (x)
//        {
//            s += x % 10;
//            x /= 10;
//        }
//        if (hash[s])
//            ans = fmax(ans, hash[s] + nums[i]);
//        hash[s] = fmax(hash[s], nums[i]);
//    }
//    return ans;
//}
//
////2815. 数组中的最大数对和
//
//int maxSum(int* nums, int numsSize)
//{
//    int ans = -1;
//    int hash[10] = { 0 };
//    for (int i = 0; i < numsSize; i++)
//    {
//        int s = 0, x = nums[i];
//        while (x)
//        {
//            s = fmax(s, x % 10);
//            x /= 10;
//        }
//        if (hash[s])
//            ans = fmax(ans, hash[s] + nums[i]);
//        hash[s] = fmax(hash[s], nums[i]);
//    }
//    return ans;
//}
//
////1010. 总持续时间可被 60 整除的歌曲
//
//int numPairsDivisibleBy60(int* time, int timeSize)
//{
//    int cnt[60] = { 0 };
//    int sum = 0;
//    for (int i = 0; i < timeSize; i++)
//    {
//        sum += cnt[(60 - time[i] % 60) % 60];
//        cnt[time[i] % 60]++;
//    }
//    return sum;
//}
//
////303. 区域和检索 - 数组不可变
//
//typedef struct
//{
//    int* prefix;
//    int n;
//} NumArray;
//
//
//NumArray* numArrayCreate(int* nums, int numsSize)
//{
//    NumArray* obj = (NumArray*)malloc(sizeof(NumArray));
//    obj->prefix = (int*)malloc(sizeof(int) * (numsSize + 1));
//    obj->prefix[0] = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        obj->prefix[i + 1] = obj->prefix[i] + nums[i];
//    }
//    obj->n = numsSize + 1;
//    return obj;
//}
//
//int numArraySumRange(NumArray* obj, int left, int right)
//{
//    return obj->prefix[right + 1] - obj->prefix[left];
//}
//
//void numArrayFree(NumArray* obj)
//{
//    free(obj->prefix);
//    free(obj);
//}
//
///**
// * Your NumArray struct will be instantiated and called as such:
// * NumArray* obj = numArrayCreate(nums, numsSize);
// * int param_1 = numArraySumRange(obj, left, right);
//
// * numArrayFree(obj);
//*/
//
