////LCR 025. 两数相加 II
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
//
//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
//{
//    struct ListNode* pre = NULL;
//    while (l1)
//    {
//        struct ListNode* next = l1->next;
//        l1->next = pre;
//        pre = l1;
//        l1 = next;
//    }
//    l1 = pre;
//    pre = NULL;
//    while (l2)
//    {
//        struct ListNode* next = l2->next;
//        l2->next = pre;
//        pre = l2;
//        l2 = next;
//    }
//    l2 = pre;
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->val = -1;
//    dummy->next = NULL;
//    struct ListNode* cur = dummy;
//    int upgrade = 0;
//    while (l1 && l2)
//    {
//        // printf("%d %d\n", l1 -> val, l2 -> val);
//        int x = l1->val + l2->val + upgrade;
//        l1 = l1->next;
//        l2 = l2->next;
//        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
//        node->val = x % 10;
//        node->next = NULL;
//        upgrade = x / 10;
//        cur->next = node;
//        cur = node;
//    }
//    while (l1)
//    {
//        // printf("%d\n", l1 -> val);
//        int x = upgrade + l1->val;
//        l1 = l1->next;
//        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
//        node->val = x % 10;
//        node->next = NULL;
//        upgrade = x / 10;
//        cur->next = node;
//        cur = node;
//    }
//    while (l2)
//    {
//        // printf("%d\n", l2 -> val);
//        int x = upgrade + l2->val;
//        l2 = l2->next;
//        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
//        node->val = x % 10;
//        node->next = NULL;
//        upgrade = x / 10;
//        cur->next = node;
//        cur = node;
//    }
//    if (upgrade)
//    {
//        // printf("%d\n", upgrade);
//        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
//        node->val = upgrade;
//        node->next = NULL;
//        cur->next = node;
//        cur = node;
//    }
//    pre = NULL;
//    cur = dummy->next;
//    while (cur)
//    {
//        struct ListNode* next = cur->next;
//        cur->next = pre;
//        pre = cur;
//        cur = next;
//    }
//    cur = pre;
//    return cur;
//}
//
////LCR 030. O(1) 时间插入、删除和获取随机元素    
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//
//typedef struct
//{
//    HashItem* exist;
//    int* nums;
//    int capacity;
//    int n;
//} RandomizedSet;
//
///** Initialize your data structure here. */
//
//RandomizedSet* randomizedSetCreate()
//{
//    RandomizedSet* obj = (RandomizedSet*)malloc(sizeof(RandomizedSet));
//    obj->exist = NULL;
//    obj->capacity = 8;
//    obj->nums = (int*)malloc(sizeof(int) * obj->capacity);
//    obj->n = 0;
//    return obj;
//}
//
///** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
//bool randomizedSetInsert(RandomizedSet* obj, int val)
//{
//    HashItem* p = NULL;
//    HASH_FIND_INT(obj->exist, &val, p);
//    if (p)
//        return false;
//
//    p = (HashItem*)malloc(sizeof(HashItem));
//    p->key = val;
//    p->val = obj->n;
//    HASH_ADD_INT(obj->exist, key, p);
//    obj->nums[obj->n++] = val;
//    if (obj->n >= obj->capacity)
//    {
//        obj->capacity *= 2;
//        obj->nums = (int*)realloc(obj->nums, sizeof(int) * obj->capacity);
//    }
//    return true;
//}
//
///** Removes a value from the set. Returns true if the set contained the specified element. */
//bool randomizedSetRemove(RandomizedSet* obj, int val)
//{
//    HashItem* p = NULL;
//    HASH_FIND_INT(obj->exist, &val, p);
//    if (p == NULL)
//        return false;
//
//    int idx = p->val;
//    int x = obj->nums[--obj->n];
//    obj->nums[idx] = x;
//    HASH_DEL(obj->exist, p);
//    free(p);
//    HashItem* p2 = NULL;
//    HASH_FIND_INT(obj->exist, &x, p2);
//    if (p2)
//        p2->val = idx;
//
//    return true;
//}
//
///** Get a random element from the set. */
//int randomizedSetGetRandom(RandomizedSet* obj)
//{
//    int x = rand();
//    return obj->nums[x % obj->n];
//}
//
//void randomizedSetFree(RandomizedSet* obj)
//{
//    HashItem* p = NULL, * tmp = NULL;
//    HASH_ITER(hh, obj -> exist, p, tmp)
//    {
//        HASH_DEL(obj->exist, p);
//        free(p);
//    }
//    free(obj->nums);
//}
//
///**
// * Your RandomizedSet struct will be instantiated and called as such:
// * RandomizedSet* obj = randomizedSetCreate();
// * bool param_1 = randomizedSetInsert(obj, val);
//
// * bool param_2 = randomizedSetRemove(obj, val);
//
// * int param_3 = randomizedSetGetRandom(obj);
//
// * randomizedSetFree(obj);
//*/
//
////LCR 032. 有效的字母异位词
//
//bool isAnagram(char* s, char* t)
//{
//    int m = strlen(s), n = strlen(t);
//    if (m != n)
//        return false;
//    int cnt[26] = { 0 };
//    int diff = 0, same = 0;
//    for (int i = 0; i < n; i++)
//    {
//        diff += (cnt[s[i] - 'a'] == 0);
//        cnt[s[i] - 'a']--;
//        diff -= (cnt[s[i] - 'a'] == 0);
//
//        diff += (cnt[t[i] - 'a'] == 0);
//        cnt[t[i] - 'a']++;
//        diff -= (cnt[t[i] - 'a'] == 0);
//
//        same += s[i] == t[i];
//    }
//    return diff == 0 && same != n;
//}
//
//bool isAnagram(char* s, char* t)
//{
//    int m = strlen(s), n = strlen(t);
//    if (m != n)
//        return false;
//    int cnt[26] = { 0 };
//    int diff = 0, same = 0;
//    for (int i = 0; i < n; i++)
//    {
//        cnt[s[i] - 'a']--;
//        cnt[t[i] - 'a']++;
//        same += s[i] == t[i];
//    }
//    if (same == n)
//        return false;
//    for (int i = 0; i < 26; i++)
//    {
//        if (cnt[i])
//            return false;
//    }
//    return true;
//}
//
////LCR 034. 验证外星语词典
//
//bool isAlienSorted(char** words, int wordsSize, char* order)
//{
//    int alpha[26];
//    for (int i = 0; i < 26; i++)
//    {
//        alpha[order[i] - 'a'] = i;
//    }
//
//    int pre = strlen(words[0]);
//    for (int i = 1; i < wordsSize; i++)
//    {
//        int cur = strlen(words[i]);
//        int len = pre < cur ? pre : cur;
//        bool flag = true;
//        for (int j = 0; j < len; j++)
//        {
//            int x = words[i - 1][j] - 'a';
//            int y = words[i][j] - 'a';
//            if (alpha[x] > alpha[y])
//                return false;
//            else if (alpha[x] < alpha[y])
//            {
//                flag = false;
//                break;
//            }
//        }
//        if (flag && pre > cur)
//            return false;
//
//        pre = cur;
//    }
//    return true;
//}
//
