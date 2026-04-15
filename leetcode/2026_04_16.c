////LCR 019. 验证回文串 II
//
//bool Palindrome(char* s, int left, int right)
//{
//    while (left < right)
//    {
//        if (s[left] != s[right])
//            return false;
//
//        left++;
//        right--;
//    }
//    return true;
//}
//bool validPalindrome(char* s)
//{
//    int n = strlen(s);
//    int left = 0, right = n - 1;
//    while (left < right)
//    {
//        if (s[left] != s[right])
//            return Palindrome(s, left + 1, right) | Palindrome(s, left, right - 1);
//
//        left++;
//        right--;
//    }
//    return true;
//}
//
//// 647. 回文子串    
//
//int countSubstrings(char* s)
//{
//    int n = strlen(s);
//    int m = 2 * n + 2;
//    char* t = (char*)malloc(sizeof(char) * (m + 1));
//    t[0] = '^';
//    for (int i = 0; i < n; i++)
//    {
//        t[i * 2 + 1] = '#';
//        t[i * 2 + 2] = s[i];
//    }
//    t[n * 2 + 1] = '#';
//    t[n * 2 + 2] = '$';
//
//    int ans = 0;
//    for (int i = 2; i <= 2 * n; i++)
//    {
//        int left = i, right = i;
//        while (t[left] == t[right])
//        {
//            left--;
//            right++;
//        }
//        ans += (i - left) / 2;
//    }
//    return ans;
//}
//
//int countSubstrings(char* s)
//{
//    int n = strlen(s);
//    int m = 2 * n + 2;
//    char* t = (char*)malloc(sizeof(char) * (m + 1));
//    t[0] = '^';
//    for (int i = 0; i < n; i++)
//    {
//        t[i * 2 + 1] = '#';
//        t[i * 2 + 2] = s[i];
//    }
//    t[n * 2 + 1] = '#';
//    t[n * 2 + 2] = '$';
//
//    int half_len[m];
//    half_len[1] = 1;
//
//    int ans = 0;
//    int box_m = 0, box_r = 0;
//    for (int i = 2; i <= 2 * n; i++)
//    {
//        int hl = 1;
//        if (i < box_r)
//            hl = fmin(half_len[2 * box_m - i], box_r - i);
//
//        while (t[i - hl] == t[i + hl])
//        {
//            hl++;
//        }
//        box_m = i;
//        box_r = i + hl;
//
//        half_len[i] = hl;
//        ans += hl / 2;
//    }
//    return ans;
//}
//
////LCR 020. 回文子串
//
//int countSubstrings(char* s)
//{
//    int n = strlen(s);
//    int m = 2 * n + 2;
//    char* t = (char*)malloc(sizeof(char) * (m + 1));
//    t[0] = '^'; t[1] = '#';
//    for (int i = 0; i < n; i++)
//    {
//        t[2 * i + 2] = s[i];
//        t[2 * i + 3] = '#';
//    }
//    t[2 * n + 2] = '$';
//
//    int half_len[m];
//    half_len[1] = 1;
//
//    int ans = 0;
//    int box_m = 0, box_r = 0;
//    for (int i = 2; i <= 2 * n; i++)
//    {
//        int hl = 1;
//        if (i < box_r)
//            hl = fmin(half_len[2 * box_m - i], box_r - i);
//
//        while (t[i - hl] == t[i + hl])
//            hl++;
//
//        box_m = i;
//        box_r = hl;
//
//        ans += hl / 2;
//    }
//    return ans;
//}
//
////LCR 026. 重排链表
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
//void reorderList(struct ListNode* head)
//{
//    struct ListNode* fast = head, * slow = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    struct ListNode* second = slow->next;
//    struct ListNode* pre = NULL;
//    while (second)
//    {
//        struct ListNode* next = second->next;
//        second->next = pre;
//        pre = second;
//        second = next;
//    }
//    second = pre;
//    slow->next = NULL;
//    struct ListNode* first = head;
//    while (second)
//    {
//        struct ListNode* next1 = first->next;
//        struct ListNode* next2 = second->next;
//        first->next = second;
//        second->next = next1;
//
//        first = next1;
//        second = next2;
//    }
//}
//
