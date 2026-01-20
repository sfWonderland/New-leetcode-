////3507. 移除最小数对使数组有序 I
//
//int minimumPairRemoval(int* nums, int numsSize)
//{
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->val = -1; dummy->next = NULL;
//    struct ListNode* cur = dummy;
//    int diff = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
//        if (i > 0 && nums[i] < nums[i - 1])
//            diff++;
//        node->val = nums[i];
//        node->next = NULL;
//        cur->next = node;
//        cur = node;
//    }
//    int ans = 0;
//    while (diff)
//    {
//        diff = 0;
//        int min = INT_MAX;
//        struct ListNode* del = NULL;
//        cur = dummy->next;
//        while (cur->next)
//        {
//            //printf("%d ", cur -> val);
//            if (cur->val > cur->next->val)
//                diff++;
//            if (cur->val + cur->next->val < min)
//            {
//                min = cur->val + cur->next->val;
//                del = cur;
//            }
//            cur = cur->next;
//        }
//        //printf("%d ", cur -> val);
//        //printf("\n");
//        if (diff)
//        {
//            struct ListNode* node = del->next;
//            del->val += node->val;
//            del->next = node->next;
//            free(node);
//            ans++;
//        }
//    }
//    return ans;
//}
//
////2380. 二进制字符串重新安排顺序需要的时间    
//
//int secondsToRemoveOccurrences(char* s)
//{
//    int ans = 0, pre0 = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] == '0')
//            pre0++;
//        else if (pre0)
//            ans = fmax(ans + 1, pre0);
//    }
//    return ans;
//}
//
////
//
//typedef struct
//{
//    char* key;
//    char* val;
//    UT_hash_handle hh;
//}HashItem;
//char* evaluate(char* s, char*** knowledge, int knowledgeSize, int* knowledgeColSize)
//{
//    HashItem* dict = NULL;
//    HashItem* pEntry = NULL;
//    for (int i = 0; i < knowledgeSize; i++)
//    {
//        pEntry = (HashItem*)malloc(sizeof(HashItem));
//        pEntry->key = knowledge[i][0];
//        pEntry->val = knowledge[i][1];
//        HASH_ADD_STR(dict, key, pEntry);
//    }
//    int n = strlen(s);
//    bool addKey = false;
//    char key[16] = { 0 };
//    int keySize = 0;
//    char* ans = (char*)malloc(sizeof(char) * (n + 1));
//    int k = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (s[i] == '(')
//            addKey = true;
//        else if (s[i] == ')')
//        {
//            key[keySize] = '\0';
//            HASH_FIND_STR(dict, key, pEntry);
//            if (pEntry)
//                k += sprintf(ans + k, "%s", pEntry->val);
//            else
//                ans[k++] = '?';
//            addKey = false;
//            keySize = 0;
//        }
//        else
//        {
//            if (addKey)
//                key[keySize++] = s[i];
//            else
//                ans[k++] = s[i];
//        }
//    }
//    ans[k] = '\0';
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, dict, pEntry, tmp)
//    {
//        HASH_DEL(dict, pEntry);
//        free(pEntry);
//    }
//    return ans;
//}
//
////2904. 最短且字典序最小的美丽子字符串
//
//char* shortestBeautifulSubstring(char* s, int k)
//{
//    int n = strlen(s);
//    int cnt = 0, left = 0, min = n + 1, l = 0;
//    for (int i = 0; i < n; i++)
//    {
//        cnt += s[i] - '0';
//        while (cnt > k)
//        {
//            cnt -= s[left++] - '0';
//        }
//        while (s[left] == '0')
//            left++;
//        if (cnt < k)
//            continue;
//        int len = i - left + 1;
//        if (len < min)
//        {
//            l = left;
//            min = len;
//        }
//        else if (len == min && strncmp(s + left, s + l, len) < 0)
//            l = left;
//    }
//    if (min > n)
//        return "";
//    char* ans = (char*)malloc(sizeof(char) * (min + 1));
//    for (int i = l; i < l + min; i++)
//    {
//        ans[i - l] = s[i];
//    }
//    ans[min] = '\0';
//    return ans;
//}
//
