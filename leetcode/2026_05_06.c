//// 面试题 02.05. 链表求和
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
//{
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = NULL;
//    struct ListNode* cur = dummy;
//    bool upgrade = 0;
//    while (l1 || l2)
//    {
//        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
//        node->next = NULL;
//        cur->next = node;
//        cur = cur->next;
//        int a = l1 ? l1->val : 0;
//        int b = l2 ? l2->val : 0;
//        int sum = a + b + upgrade;
//        cur->val = sum % 10;
//        upgrade = sum / 10;
//        if (l1)
//            l1 = l1->next;
//        if (l2)
//            l2 = l2->next;
//    }
//    if (upgrade)
//    {
//        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
//        node->next = NULL;
//        cur->next = node;
//        cur = cur->next;
//        cur->val = 1;
//    }
//    return dummy->next;
//}
//
//// 面试题 02.08. 环路检测    
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* detectCycle(struct ListNode* head)
//{
//    if (head == NULL || head->next == NULL)
//        return NULL;
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//        if (fast == slow)
//        {
//            struct ListNode* p = head;
//            while (p != slow)
//            {
//                p = p->next;
//                slow = slow->next;
//            }
//            return p;
//        }
//    }
//    return NULL;
//}
//
//// 面试题 03.01. 三合一
//
//typedef struct
//{
//    int* st;
//    int* top;
//    int size;
//} TripleInOne;
//
//
//TripleInOne* tripleInOneCreate(int stackSize)
//{
//    TripleInOne* obj = (TripleInOne*)malloc(sizeof(TripleInOne));
//    obj->st = (int*)malloc(sizeof(int) * stackSize * 3);
//    obj->top = (int*)calloc(sizeof(int), 3);
//    obj->size = stackSize;
//    return obj;
//}
//
//void tripleInOnePush(TripleInOne* obj, int stackNum, int value)
//{
//    if (obj->top[stackNum] == obj->size)
//        return;
//    obj->st[stackNum * obj->size + obj->top[stackNum]] = value;
//    obj->top[stackNum]++;
//}
//
//int tripleInOnePop(TripleInOne* obj, int stackNum)
//{
//    if (obj->top[stackNum] == 0)
//        return -1;
//
//    obj->top[stackNum]--;
//    return obj->st[stackNum * obj->size + obj->top[stackNum]];
//}
//
//int tripleInOnePeek(TripleInOne* obj, int stackNum)
//{
//    if (obj->top[stackNum] == 0)
//        return -1;
//
//    return obj->st[stackNum * obj->size + obj->top[stackNum] - 1];
//}
//
//bool tripleInOneIsEmpty(TripleInOne* obj, int stackNum)
//{
//    return obj->top[stackNum] == 0;
//}
//
//void tripleInOneFree(TripleInOne* obj)
//{
//    free(obj->st);
//    free(obj->top);
//    free(obj);
//}
//
///**
// * Your TripleInOne struct will be instantiated and called as such:
// * TripleInOne* obj = tripleInOneCreate(stackSize);
// * tripleInOnePush(obj, stackNum, value);
//
// * int param_2 = tripleInOnePop(obj, stackNum);
//
// * int param_3 = tripleInOnePeek(obj, stackNum);
//
// * bool param_4 = tripleInOneIsEmpty(obj, stackNum);
//
// * tripleInOneFree(obj);
//*/
//
//// 面试题 03.02. 栈的最小值
//
//typedef struct
//{
//    int* st;
//    int* min;
//    int top1;
//    int top2;
//} MinStack;
//
///** initialize your data structure here. */
//
//MinStack* minStackCreate()
//{
//    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
//    obj->st = (int*)malloc(sizeof(int) * 10000);
//    obj->min = (int*)malloc(sizeof(int) * 10000);
//    obj->top1 = 0;
//    obj->top2 = 0;
//    obj->st[obj->top1++] = INT_MAX;
//    obj->min[obj->top2++] = 0;
//    return obj;
//}
//
//void minStackPush(MinStack* obj, int x)
//{
//    if (x < obj->st[obj->min[obj->top2 - 1]])
//        obj->min[obj->top2++] = obj->top1;
//    obj->st[obj->top1++] = x;
//}
//
//void minStackPop(MinStack* obj)
//{
//    obj->top1--;
//    if (obj->min[obj->top2 - 1] == obj->top1)
//    {
//        obj->top2--;
//    }
//}
//
//int minStackTop(MinStack* obj)
//{
//    return obj->st[obj->top1 - 1];
//}
//
//int minStackGetMin(MinStack* obj)
//{
//    return obj->st[obj->min[obj->top2 - 1]];
//}
//
//void minStackFree(MinStack* obj)
//{
//    free(obj->st);
//    free(obj->min);
//}
//
///**
// * Your MinStack struct will be instantiated and called as such:
// * MinStack* obj = minStackCreate();
// * minStackPush(obj, x);
//
// * minStackPop(obj);
//
// * int param_3 = minStackTop(obj);
//
// * int param_4 = minStackGetMin(obj);
//
// * minStackFree(obj);
//*/
//
//
//typedef struct
//{
//    int* st;
//    int* min;
//    int top1;
//    int top2;
//    int capacity1;
//    int capacity2;
//} MinStack;
//
///** initialize your data structure here. */
//
//MinStack* minStackCreate()
//{
//    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
//    obj->capacity1 = 8;
//    obj->capacity2 = 8;
//    obj->st = (int*)malloc(sizeof(int) * obj->capacity1);
//    obj->min = (int*)malloc(sizeof(int) * obj->capacity2);
//    obj->top1 = 0;
//    obj->top2 = 0;
//    obj->st[obj->top1++] = INT_MAX;
//    obj->min[obj->top2++] = 0;
//    return obj;
//}
//
//void minStackPush(MinStack* obj, int x)
//{
//    if (x < obj->st[obj->min[obj->top2 - 1]])
//    {
//        obj->min[obj->top2++] = obj->top1;
//        if (obj->top2 >= obj->capacity2)
//        {
//            obj->capacity2 *= 2;
//            obj->min = (int*)realloc(obj->min, sizeof(int) * obj->capacity2);
//        }
//    }
//
//    obj->st[obj->top1++] = x;
//    if (obj->top1 >= obj->capacity1)
//    {
//        obj->capacity1 *= 2;
//        obj->st = (int*)realloc(obj->st, sizeof(int) * obj->capacity1);
//    }
//}
//
//void minStackPop(MinStack* obj)
//{
//    obj->top1--;
//    if (obj->min[obj->top2 - 1] == obj->top1)
//    {
//        obj->top2--;
//    }
//}
//
//int minStackTop(MinStack* obj)
//{
//    return obj->st[obj->top1 - 1];
//}
//
//int minStackGetMin(MinStack* obj)
//{
//    return obj->st[obj->min[obj->top2 - 1]];
//}
//
//void minStackFree(MinStack* obj)
//{
//    free(obj->st);
//    free(obj->min);
//}
//
///**
// * Your MinStack struct will be instantiated and called as such:
// * MinStack* obj = minStackCreate();
// * minStackPush(obj, x);
//
// * minStackPop(obj);
//
// * int param_3 = minStackTop(obj);
//
// * int param_4 = minStackGetMin(obj);
//
// * minStackFree(obj);
//*/
//
