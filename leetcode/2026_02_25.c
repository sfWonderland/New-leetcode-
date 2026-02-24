////1726. 同积元组
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int tupleSameProduct(int* nums, int numsSize)
//{
//    HashItem* cnt = NULL;
//    HashItem* p1 = NULL;
//    for (int i = 0; i < numsSize - 1; i++)
//    {
//        for (int j = i + 1; j < numsSize; j++)
//        {
//            int x = nums[i] * nums[j];
//            HASH_FIND_INT(cnt, &x, p1);
//            if (p1 == NULL)
//            {
//                p1 = (HashItem*)malloc(sizeof(HashItem));
//                p1->key = x;
//                p1->val = 0;
//                HASH_ADD_INT(cnt, key, p1);
//            }
//            p1->val++;
//        }
//    }
//    HashItem* tmp = NULL;
//    int ans = 0;
//    HASH_ITER(hh, cnt, p1, tmp)
//    {
//        ans += p1->val * (p1->val - 1) * 4;
//        HASH_DEL(cnt, p1);
//        free(p1);
//    }
//    return ans;
//}
//
////1752. 检查数组是否经排序和轮转得到    
//
//bool check(int* nums, int numsSize)
//{
//    bool flag = false;
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (!flag)
//        {
//            if (nums[i] >= nums[i - 1])
//                continue;
//            else if (nums[i] <= nums[0])
//                flag = true;
//            else
//                return false;
//        }
//        else
//        {
//            if (nums[i] > nums[0] || nums[i] < nums[i - 1])
//                return false;
//        }
//    }
//    return true;
//}
//
////1763. 最长的美好子字符串
//
//char* longestNiceSubstring(char* s)
//{
//    int idx = -1, len = 0, n = strlen(s);
//    for (int i = 0; i < n; i++)
//    {
//        int mask[2] = { 0 };
//        for (int j = i; j < n; j++)
//        {
//            if (s[j] >= 'a')
//                mask[1] |= (1 << (s[j] - 'a'));
//            else
//                mask[0] |= (1 << (s[j] - 'A'));
//
//            if (mask[0] == mask[1] && j - i + 1 > len)
//            {
//                len = j - i + 1;
//                idx = i;
//            }
//        }
//    }
//    if (!len)
//        return "";
//    else
//        s[idx + len] = '\0';
//    return s + idx;
//}
//
////1764. 通过连接另一个数组的子数组得到一个数组
//
//bool canChoose(int** groups, int groupsSize, int* groupsColSize, int* nums, int numsSize)
//{
//    int idx = 0;
//    bool check(int* nums, int* group, int i, int n, int m)
//    {
//        int j = 0;
//        for (; j < m && i + j < n; j++)
//        {
//            if (group[j] != nums[i + j])
//                return false;
//        }
//        return j == m;
//    }
//    for (int i = 0; i < numsSize && idx < groupsSize; )
//    {
//        if (check(nums, groups[idx], i, numsSize, groupsColSize[idx]))
//            i += groupsColSize[idx++];
//        else
//            i++;
//    }
//    return idx == groupsSize;
//}
//
