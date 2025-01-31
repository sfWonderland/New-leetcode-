//#define _CRT_SECURE_NO_WARNINGS
//
////33.搜索旋转排序数组I
//
//int search(int* nums, int numsSize, int target)
//{
//    int k = 0;
//    if (nums[0] > nums[numsSize - 1])
//    {
//        for (int i = 0; i < numsSize - 1; i++)
//        {
//            if (nums[i] > nums[i + 1])
//                k = i + 1;
//        }
//    }
//    //printf("k = %d\n", k);
//
//    int left = k;
//    int right = numsSize - 1;
//    if (k)
//    {
//        if (nums[k] > target)
//            return -1;
//        else if (nums[k] == target)
//            return k;
//
//        if (nums[0] < target)
//        {
//            if (nums[k - 1] < target)
//                return -1;
//            else if (target == nums[k - 1])
//                return k - 1;
//            left = 0;
//            right = k - 1;
//        }
//        else if (target == nums[0])
//            return 0;
//    }
//
//    while (left <= right)
//    {
//        if (target == nums[left])
//            return left;
//        else
//            left++;
//
//        if (target == nums[right])
//            return right;
//        else
//            right--;
//        //printf("left = %d, right = %d\n", left, right);
//    }
//
//    return -1;
//}
//
////81.搜索旋转排序数组II
//
//bool search(int* nums, int numsSize, int target)
//{
//    int k = 0;
//    if (nums[0] > nums[numsSize - 1])
//    {
//        for (int i = 0; i < numsSize - 1; i++)
//        {
//            if (nums[i] > nums[i + 1])
//                k = i + 1;
//        }
//    }
//    //printf("k = %d\n", k);
//
//    int left = k;
//    int right = numsSize - 1;
//    if (k)
//    {
//        if (nums[k] > target)
//            return false;
//        else if (nums[k] == target)
//            return true;
//
//        if (nums[0] < target)
//        {
//            if (nums[k - 1] < target)
//                return false;
//            else if (target == nums[k - 1])
//                return true;
//            left = 0;
//            right = k - 1;
//        }
//        else if (target == nums[0])
//            return true;
//    }
//
//    while (left <= right)
//    {
//        if (target == nums[left])
//            return true;
//        else
//            left++;
//
//        if (target == nums[right])
//            return true;
//        else
//            right--;
//        //printf("left = %d, right = %d\n", left, right);
//    }
//
//    return false;
//}
//
////941. 有效的山脉数组
//
//bool validMountainArray(int* arr, int arrSize)
//{
//    int peak = 0;
//    for (int i = 0; i < arrSize - 1; i++)
//    {
//        if (arr[i] == arr[i + 1])
//            return false;
//        else if (arr[i] > arr[i + 1])
//        {
//            peak = i;
//            break;
//        }
//    }
//    //printf("peak = %d\n", peak);
//    if (!peak)
//        return false;
//
//    for (int i = peak + 1; i < arrSize - 1; i++)
//    {
//        if (arr[i] <= arr[i + 1])
//            return false;
//    }
//
//    return true;
//}
//
////944.删列造序
//
//int minDeletionSize(char** strs, int strsSize)
//{
//    int ret = 0;
//    int len = strlen(strs[0]);
//    for (int j = 0; j < len; j++)
//    {
//        for (int i = 0; i < strsSize - 1; i++)
//        {
//            if (strs[i][j] > strs[i + 1][j])
//            {
//                //printf("i = %d, j = %d\n", i, j);
//                ret++;
//                break;
//            }
//        }
//    }
//
//    return ret;
//}
//
//
////2586.统计范围内的元音字符串
//
//bool vowel(int n)
//{
//    if ('a' == n || 'e' == n || 'i' == n || 'o' == n || 'u' == n)
//        return true;
//    else
//        return false;
//}
//
//int vowelStrings(char** words, int wordsSize, int left, int right)
//{
//    int ret = 0;
//    for (int i = left; i <= right; i++)
//    {
//        if (vowel(words[i][0]))
//        {
//            int len = strlen(words[i]);
//            if (vowel(words[i][len - 1]))
//                ret++;
//        }
//    }
//
//    return ret;
//}
//
//
////961.在长度2N的数组中找出重复N次的元素
//
//int repeatedNTimes(int* nums, int numsSize)
//{
//    int hash[10001] = { 0 };
//
//    int ret = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (hash[nums[i]])
//        {
//            ret = nums[i];
//            break;
//        }
//        else
//            hash[nums[i]]++;
//    }
//
//    return ret;
//}
//
//
////953.验证外星语词典
//
//bool isAlienSorted(char** words, int wordsSize, char* order)
//{
//    int revise[26] = { 0 };
//    for (int i = 0; i < 26; i++)
//    {
//        revise[order[i] - 'a'] = i;
//    }
//
//
//    for (int i = 0; i < wordsSize - 1; i++)
//    {
//        int len1 = strlen(words[i]);
//        int len2 = strlen(words[i + 1]);
//        int len = len1 < len2 ? len1 : len2;
//        int flag = 1;
//        for (int j = 0; j < len; j++)
//        {
//            if (revise[words[i][j] - 'a'] > revise[words[i + 1][j] - 'a'])
//                return false;
//            else if (revise[words[i][j] - 'a'] < revise[words[i + 1][j] - 'a'])
//            {
//                flag = 0;
//                break;
//            }
//        }
//
//        if (flag && len1 > len)
//            return false;
//    }
//
//    return true;
//}
//
//
////1217.玩筹码
//
//int minCostToMoveChips(int* position, int positionSize)
//{
//    int even = 0;
//    int odd = 0;
//    for (int i = 0; i < positionSize; i++)
//    {
//        if (position[i] % 2)
//            even++;
//        else
//            odd++;
//    }
//
//    return even > odd ? odd : even;
//}
//
////2578.最小和分割
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int splitNum(int num)
//{
//    int hash[10] = { 0 };
//    int n = 0;
//    while (num)
//    {
//        int m = num % 10;
//        if (m)
//        {
//            hash[n] = m;
//            n++;
//        }
//        num /= 10;
//    }
//    qsort(hash, n, sizeof(int), cmp);
//
//    int a = 0;
//    int b = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (i % 2)
//            a = a * 10 + hash[i];
//        else
//            b = b * 10 + hash[i];
//    }
//
//    return a + b;
//}
//33；81；941；944；2586；961；953；1217；2578；