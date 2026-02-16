////3838. 带权单词映射
//
//char* mapWordWeights(char** words, int wordsSize, int* weights, int weightsSize)
//{
//    int n = wordsSize;
//    char* ans = (char*)malloc(sizeof(char) * (n + 1));
//    for (int i = 0; i < n; i++)
//    {
//        int sum = 0;
//        for (int j = 0; words[i][j]; j++)
//        {
//            sum += weights[words[i][j] - 'a'];
//        }
//        ans[i] = (25 - sum % 26) + 'a';
//    }
//    ans[n] = '\0';
//    return ans;
//}
//
////3839. 前缀连接组的数目    
//
//typedef struct
//{
//    char* key;
//    bool val;
//    UT_hash_handle hh;
//}HashItem;
//int prefixConnected(char** words, int wordsSize, int k)
//{
//    HashItem* cnt = NULL;
//    HashItem* p1 = NULL;
//    for (int i = 0; i < wordsSize; i++)
//    {
//        int n = strlen(words[i]);
//        if (n < k)
//            continue;
//
//        words[i][k] = '\0';
//        HASH_FIND_STR(cnt, words[i], p1);
//        if (p1 == NULL)
//        {
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = words[i];
//            p1->val = false;
//            HASH_ADD_STR(cnt, key, p1);
//        }
//        else
//            p1->val = true;
//    }
//    int ans = 0;
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, cnt, p1, tmp)
//    {
//        ans += p1->val;
//        HASH_DEL(cnt, p1);
//        free(p1);
//    }
//    return ans;
//}
//
////3840. 打家劫舍 V
//
//long long rob(int* nums, int numsSize, int* colors, int colorsSize)
//{
//    int n = numsSize;
//    long long f[n + 1];
//    f[0] = 0;
//    for (int i = 0; i < n; i++)
//    {
//        long long notake = f[i];
//        long long take;
//        if (i == 0 || colors[i] != colors[i - 1])
//            take = f[i] + nums[i];
//        else
//            take = f[i - 1] + nums[i];
//
//        f[i + 1] = fmax(notake, take);
//    }
//    return f[n];
//}
//
//long long rob(int* nums, int numsSize, int* colors, int colorsSize)
//{
//    int n = numsSize;
//    long long f1 = 0, f2 = 0, f3 = 0;
//    for (int i = 0; i < n; i++)
//    {
//        long long notake = f2;
//        long long take;
//        if (i == 0 || colors[i] != colors[i - 1])
//            take = f2 + nums[i];
//        else
//            take = f3 + nums[i];
//
//        f1 = fmax(notake, take);
//        f3 = f2;
//        f2 = f1;
//    }
//    return f1;
//}
//
//
////912. 排序数组
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int Partition(int* nums, int low, int high)
//{
//    int i = low + rand() % (high - low + 1);
//    int pivot = nums[i];
//    nums[i] = nums[low];
//    nums[low] = pivot;
//    while (low < high)
//    {
//        while (low < high && nums[high] >= pivot)
//            high--;
//        nums[low] = nums[high];
//        while (low < high && nums[low] <= pivot)
//            low++;
//        nums[high] = nums[low];
//    }
//    nums[low] = pivot;
//    return low;
//}
//void sort(int* nums, int low, int high)
//{
//    bool ordered = true;
//    for (int i = low; i < high; i++)
//    {
//        if (nums[i] > nums[i + 1])
//        {
//            ordered = false;
//            break;
//        }
//    }
//    if (ordered)
//        return;
//
//    int pivotPos = Partition(nums, low, high);
//    sort(nums, low, pivotPos - 1);
//    sort(nums, pivotPos + 1, high);
//}
//int* sortArray(int* nums, int numsSize, int* returnSize)
//{
//    sort(nums, 0, numsSize - 1);
//    *returnSize = numsSize;
//    return nums;
//}
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//#define SWAP(a, b) do { int tmp = (a); (a) = (b); (b) = tmp; } while (0)
//int Partition(int* nums, int low, int high)
//{
//    int i = low + rand() % (high - low + 1);
//    int pivot = nums[i];
//    SWAP(nums[i], nums[low]);
//    i = low + 1;
//    int j = high;
//    while (1)
//    {
//        while (i <= j && nums[i] < pivot)
//            i++;
//        while (i <= j && nums[j] > pivot)
//            j--;
//        if (i >= j) break;
//        SWAP(nums[i], nums[j]);
//        i++;
//        j--;
//    }
//    SWAP(nums[low], nums[j]);
//    return j;
//}
//void sort(int* nums, int low, int high)
//{
//    bool ordered = true;
//    for (int i = low; i < high; i++)
//    {
//        if (nums[i] > nums[i + 1])
//        {
//            ordered = false;
//            break;
//        }
//    }
//    if (ordered)
//        return;
//
//    int i = Partition(nums, low, high);
//    sort(nums, low, i - 1);
//    sort(nums, i + 1, high);
//}
//int* sortArray(int* nums, int numsSize, int* returnSize)
//{
//    srand(time(NULL));
//    sort(nums, 0, numsSize - 1);
//    *returnSize = numsSize;
//    return nums;
//}
//
