//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>
//static int DIR[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };//右下左上
//int main()
//{
//	int n = 0, m = 0;
//	scanf("%d %d", &m, &n);
//	int** square = (int**)malloc(sizeof(int*) * m);
//	for (int i = 0; i < n; i++)
//	{
//		square[i] = (int*)malloc(sizeof(int) * n);
//		memset(square[i], 0, n);
//	}
//	int row = m;
//	int col = n;
//	int size = m * n;
//	int num = 0;
//	int i = 0, j = -1;
//	for (int di = 0; num < size; di = (di + 1) % 4)
//	{
//		for (int t = 0; t < n; t++)
//		{
//			i += DIR[di][0];
//			j += DIR[di][1];
//			square[i][j] = ++num;
//		}
//		int tmp = n;
//		n = m - 1;
//		m = tmp;
//	}
//	for (int a = 0; a < row; a++)
//	{
//		for (int b = 0; b < col; b++)
//			printf("%d ", square[a][b]);
//		printf("\n");
//	}
//	free(square);
//	return 0;
//}
=========
////206. 反转链表
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = NULL;
//    struct ListNode* p = head;
//    while (p != NULL)
//    {
//        struct ListNode* next = p->next;
//        p->next = dummy->next;
//        dummy->next = p;
//        p = next;
//    }
//    return dummy->next;
//}
//
////876. 链表的中间结点
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* middleNode(struct ListNode* head)
//{
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    return slow;
//}
//
////.
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//bool isPalindrome(struct ListNode* head)
//{
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* p = slow;
//    while (p != NULL)
//    {
//        struct ListNode* next = p->next;
//        p->next = dummy->next;
//        dummy->next = p;
//        p = next;
//    }
//    p = dummy->next;
//    struct ListNode* q = head;
//    while (p != NULL)
//    {
//        if (q->val != p->val)
//            return false;
//        p = p->next;
//        q = q->next;
//    }
//    return true;
//}
//
////1290. 二进制链表转整数
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//int getDecimalValue(struct ListNode* head)
//{
//    int n = 0;
//    struct ListNode* p = head;
//    while (p)
//    {
//        n <<= 1;
//        n += p->val;
//        p = p->next;
//    }
//    return n;
//}
//
>>>>>>>>> Temporary merge branch 2
