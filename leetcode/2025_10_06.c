////2336. 无限集中的最小数字
//
//typedef struct
//{
//    int* nums;
//    bool* hash;
//    int n;
//} SmallestInfiniteSet;
//
//void HeapDown(int* nums, int k, int n)
//{
//    nums[0] = nums[k];
//    for (int i = 2 * k; i <= n; i = 2 * i)
//    {
//        if (i < n && nums[i + 1] < nums[i])
//            i++;
//        if (nums[i] >= nums[0])
//            break;
//        nums[k] = nums[i];
//        k = i;
//    }
//    nums[k] = nums[0];
//}
//
//void HeapUp(int* nums, int k, int n)
//{
//    nums[0] = nums[k];
//    for (int i = k / 2; i > 0; i /= 2)
//    {
//        if (nums[i] <= nums[0])
//            break;
//        nums[k] = nums[i];
//        k = i;
//    }
//    nums[k] = nums[0];
//}
//
//SmallestInfiniteSet* smallestInfiniteSetCreate()
//{
//    SmallestInfiniteSet* obj = (SmallestInfiniteSet*)malloc(sizeof(SmallestInfiniteSet));
//    obj->nums = (int*)malloc(sizeof(int) * 1001);
//    obj->hash = (bool*)calloc(sizeof(bool), 1001);
//    for (int i = 1; i < 1001; i++)
//    {
//        obj->nums[i] = i;
//    }
//    obj->n = 1000;
//    return obj;
//}
//
//int smallestInfiniteSetPopSmallest(SmallestInfiniteSet* obj)
//{
//    int x = obj->nums[1];
//    obj->hash[obj->nums[1]] = true;
//    obj->nums[1] = obj->nums[obj->n--];
//    // printf("%d |", obj -> nums[1]);
//    HeapDown(obj->nums, 1, obj->n);
//    // for(int i = 0; i < obj -> n; i++)
//    // {
//    //     printf("%d ", obj -> nums[i + 1]);
//    // }
//    // printf("\n");
//    return x;
//}
//
//void smallestInfiniteSetAddBack(SmallestInfiniteSet* obj, int num)
//{
//    if (obj->hash[num])
//    {
//        obj->hash[num] = false;
//        obj->nums[++obj->n] = num;
//        HeapUp(obj->nums, obj->n, obj->n);
//    }
//    // for(int i = 0; i < obj -> n; i++)
//    // {
//    //     printf("%d ", obj -> nums[i + 1]);
//    // }
//    // printf("\n");
//}
//
//void smallestInfiniteSetFree(SmallestInfiniteSet* obj)
//{
//    free(obj->nums);
//    free(obj);
//}
//
///**
// * Your SmallestInfiniteSet struct will be instantiated and called as such:
// * SmallestInfiniteSet* obj = smallestInfiniteSetCreate();
// * int param_1 = smallestInfiniteSetPopSmallest(obj);
//
// * smallestInfiniteSetAddBack(obj, num);
//
// * smallestInfiniteSetFree(obj);
//*/
//
////2530. 执行 K 次操作后的最大分数
//
//void swap(int* nums, int i, int j)
//{
//    int tmp = nums[i];
//    nums[i] = nums[j];
//    nums[j] = tmp;
//}
//void HeapDown(int* nums, int i, int n)
//{
//    int x = nums[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && nums[j + 1] > nums[j])
//            j++;
//        if (nums[j] <= x)
//            break;
//        nums[i] = nums[j];
//        i = j;
//    }
//    nums[i] = x;
//}
//void HeapBuild(int* nums, int n)
//{
//    for (int i = n / 2 - 1; i >= 0; i--)
//    {
//        HeapDown(nums, i, n);
//    }
//}
//void HeapSort(int* nums, int n)
//{
//    HeapBuild(nums, n);
//    for (int i = n - 1; i > 0; i--)
//    {
//        HeapDown(nums, 0, i);
//    }
//}
//long long maxKelements(int* nums, int numsSize, int k)
//{
//    HeapSort(nums, numsSize);
//    long long ans = 0;
//    while (k--)
//    {
//        ans += nums[0];
//        nums[0] = (nums[0] + 2) / 3;
//        HeapDown(nums, 0, numsSize);
//    }
//    return ans;
//}
//
////3066. 超过阈值的最少操作数 II
//
//void swap(long long* nums, int i, int j)
//{
//    long long tmp = nums[i];
//    nums[i] = nums[j];
//    nums[j] = tmp;
//}
//void HeapDown(long long* nums, int i, int n)
//{
//    long long x = nums[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && nums[j + 1] < nums[j])
//            j++;
//        if (nums[j] >= x)
//            break;
//        nums[i] = nums[j];
//        i = j;
//    }
//    nums[i] = x;
//}
//void BuildMinHeap(long long* nums, int n)
//{
//    for (int i = n / 2 - 1; i >= 0; i--)
//    {
//        HeapDown(nums, i, n);
//    }
//}
//void HeapSort(long long* nums, int n)
//{
//    BuildMinHeap(nums, n);
//    for (int i = n - 1; i > 0; i--)
//    {
//        HeapDown(nums, 0, i);
//    }
//}
//int minOperations(int* nums, int numsSize, int k)
//{
//    long long arr[numsSize];
//    for (int i = 0; i < numsSize; i++)
//    {
//        arr[i] = nums[i];
//    }
//    HeapSort(arr, numsSize);
//    // for(int i = 0; i < numsSize; i++)
//    // {
//    //     printf("%lld ", arr[i]);
//    // }
//    // printf("\n");
//    int ans = 0, n = numsSize;
//    while (arr[0] < k)
//    {
//        ans++;
//        int x = arr[0];
//        swap(arr, 0, --n);
//        HeapDown(arr, 0, n);
//        arr[0] = fmin(arr[0], x) + arr[0] + x;
//        HeapDown(arr, 0, n);
//        // for(int i = 0; i < n; i++)
//        // {
//        //     printf("%lld ", arr[i]);
//        // }
//        // printf("\n");
//    }
//    return ans;
//}
//
////1962. 移除石子使总数最小
//
//void HeapDown(int* nums, int i, int n)
//{
//    int x = nums[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && nums[j + 1] > nums[j])
//            j++;
//        if (nums[j] <= x)
//            break;
//        nums[i] = nums[j];
//        i = j;
//    }
//    nums[i] = x;
//}
//void BuildMaxHeap(int* nums, int n)
//{
//    for (int i = n / 2 - 1; i >= 0; i--)
//    {
//        HeapDown(nums, i, n);
//    }
//}
//void HeapSort(int* nums, int n)
//{
//    BuildMaxHeap(nums, n);
//    for (int i = n - 1; i > 0; i--)
//    {
//        HeapDown(nums, 0, i);
//    }
//}
//int minStoneSum(int* piles, int pilesSize, int k)
//{
//    HeapSort(piles, pilesSize);
//    while (k--)
//    {
//        piles[0] = (piles[0] + 1) / 2;
//        HeapDown(piles, 0, pilesSize);
//    }
//    int ans = 0;
//    for (int i = 0; i < pilesSize; i++)
//    {
//        ans += piles[i];
//    }
//    return ans;
//}
//
