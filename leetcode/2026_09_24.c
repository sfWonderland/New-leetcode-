//// 287. 寻找重复数
//
//// 修改
//void swap(int* nums, int i, int j)
//{
//    int tmp = nums[i];
//    nums[i] = nums[j];
//    nums[j] = tmp;
//}
//int findDuplicate(int* nums, int numsSize)
//{
//    int x = nums[0];
//    while (x != nums[x])
//    {
//        swap(nums, 0, x);
//        x = nums[0];
//    }
//    return x;
//}
//
//// 不修改
//int findDuplicate(int* nums, int numsSize)
//{
//    int fast = 0, slow = 0;
//    while (fast != slow || slow == 0)
//    {
//        fast = nums[nums[fast]];
//        slow = nums[slow];
//    }
//
//    int p = 0;
//    while (p != slow)
//    {
//        p = nums[p];
//        slow = nums[slow];
//    }
//    return p;
//}
//
//// 1015. 可被 K 整除的最小整数    
//
//int smallestRepunitDivByK(int k)
//{
//    if (k == 1) return 1;
//    int fast = 1, slow = 1;
//    int lenF = 1, lenS = 1;
//    do
//    {
//        fast = (10 * ((10 * fast + 1) % k) + 1) % k;
//        lenF += 2;
//        slow = (10 * slow + 1) % k;
//        lenS++;
//        if (fast == 0) return lenF;
//        if (slow == 0) return lenS;
//    } while (fast != slow);
//
//    return -1;
//}
//
//int smallestRepunitDivByK(int k)
//{
//    if (k == 1) return 1;
//    if (k % 2 == 0 || k % 5 == 0) return -1;
//    int x = 1;
//    for (int i = 1; ; i++)
//    {
//        if (x == 0) return i;
//        x = (10 * x + 1) % k;
//    }
//
//    return -1;
//}
//
//// 3790. 最小全 1 倍数
//
//int minAllOneMultiple(int k)
//{
//    if (k % 2 == 0 || k % 5 == 0) return -1;
//    int x = 1 % k;
//    for (int i = 1; ; i++)
//    {
//        if (x == 0) return i;
//        x = (10 * x + 1) % k;
//    }
//    return -1;
//}
//
//// 328. 奇偶链表
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* oddEvenList(struct ListNode* head)
//{
//    if (!head || !head->next) return head;
//
//    struct ListNode* list1 = head;
//    struct ListNode* list2 = head->next;
//
//    struct ListNode* cur1 = list1;
//    struct ListNode* cur2 = list2;
//    bool flag = false;
//    for (struct ListNode* p = list2->next; p; p = p->next)
//    {
//        if (flag)
//        {
//            cur2->next = p;
//            cur2 = p;
//        }
//        else
//        {
//            cur1->next = p;
//            cur1 = p;
//        }
//        flag ^= 1;
//    }
//    cur1->next = list2;
//    cur2->next = NULL;
//    return list1;
//}
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* oddEvenList(struct ListNode* head)
//{
//    if (!head || !head->next) return head;
//
//    struct ListNode* list2 = head->next;
//
//    struct ListNode* cur1 = head;
//    struct ListNode* cur2 = list2;
//    while (cur2 && cur2->next)
//    {
//        cur1->next = cur2->next;
//        cur1 = cur1->next;
//        cur2->next = cur1->next;
//        cur2 = cur2->next;
//    }
//    cur1->next = list2;
//    return head;
//}
//
