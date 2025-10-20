////395. 至少有 K 个重复字符的最长子串
//
//int longestSubstring(char* s, int k)
//{
//    int n = strlen(s), ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int cnt[26] = { 0 };
//        int alphas = 0;
//        for (int j = i; j < n; j++)
//        {
//            if (!cnt[s[j] - 'a'])
//            {
//                cnt[s[j] - 'a'] = 1;
//                alphas++;
//            }
//            else
//                cnt[s[j] - 'a']++;
//            int base = 0;
//            for (int l = 0; l < 26; l++)
//            {
//                if (!cnt[l])
//                    continue;
//                if (cnt[l] < k)
//                {
//                    base = -1;
//                    break;
//                }
//            }
//            if (base != -1)
//                ans = fmax(ans, j - i + 1);
//        }
//    }
//    return ans;
//}
//
////284. 窥视迭代器
//
///*
// *	struct Iterator {
// *		// Returns true if the iteration has more elements.
// *		bool (*hasNext)();
// *
// * 		// Returns the next element in the iteration.
// *		int (*next)();
// *	};
// */
//
//struct PeekingIterator
//{
//    int next;
//    struct Iterator* iterator;
//    bool hasPeeked;
//};
//
//struct PeekingIterator* Constructor(struct Iterator* iter)
//{
//    struct PeekingIterator* piter = malloc(sizeof(struct PeekingIterator));
//    piter->iterator = iter;
//    piter->hasPeeked = false;
//    return piter;
//}
//
//int peek(struct PeekingIterator* obj)
//{
//    if (obj->hasPeeked) return obj->next;
//
//    obj->hasPeeked = true;
//    obj->next = obj->iterator->next();
//    return obj->next;
//}
//
//int next(struct PeekingIterator* obj)
//{
//    if (obj->hasPeeked)
//    {
//        obj->hasPeeked = false;
//        return obj->next;
//    }
//    return obj->iterator->next();
//}
//
//bool hasNext(struct PeekingIterator* obj)
//{
//    if (obj->hasPeeked)
//        return true;
//
//    return obj->iterator->hasNext();
//}
//
///**
// * Your PeekingIterator struct will be instantiated and called as such:
// * PeekingIterator* obj = peekingIteratorCreate(arr, arrSize);
// * int param_1 = peek(obj);
// * int param_2 = next(obj);
// * bool param_3 = hasNext(obj);
// * peekingIteratorFree(obj);
//*/
//
////413. 等差数列划分
//
//int numberOfArithmeticSlices(int* nums, int numsSize)
//{
//    if (numsSize < 3)
//        return 0;
//    int ans = 0, left = 0, base = nums[1] - nums[0];
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (i - left < 2)
//            continue;
//        if (nums[i] - nums[i - 1] != base)
//        {
//            base = nums[i] - nums[i - 1];
//            ans += (i - left - 1) * (i - left - 2) / 2;
//            left = i - 1;
//        }
//    }
//    ans += (numsSize - left - 1) * (numsSize - left - 2) / 2;
//    return ans;
//}
//
////506. 相对名次
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    int key;
//    int val;
//} Score;
//char* prizes[3] = { "Gold Medal", "Silver Medal", "Bronze Medal" };
//int cmp(const void* a, const void* b)
//{
//    return (*(Score*)b).key - (*(Score*)a).key;
//}
//char** findRelativeRanks(int* score, int scoreSize, int* returnSize)
//{
//    char** ans = (char**)malloc(sizeof(char*) * scoreSize);
//    Score* tmp = (Score*)malloc(sizeof(Score) * scoreSize);
//    for (int i = 0; i < scoreSize; i++)
//    {
//        tmp[i].key = score[i];
//        tmp[i].val = i;
//    }
//    qsort(tmp, scoreSize, sizeof(Score), cmp);
//    for (int i = 0; i < scoreSize; i++)
//    {
//        if (i < 3)
//        {
//            ans[tmp[i].val] = (char*)malloc(sizeof(char) * 13);
//            strcpy(ans[tmp[i].val], prizes[i]);
//        }
//        else
//        {
//            ans[tmp[i].val] = (char*)malloc(sizeof(char) * 6);
//            sprintf(ans[tmp[i].val], "%d", i + 1);
//        }
//    }
//    returnSize[0] = scoreSize;
//    return ans;
//}
//
