//// LCR 029. 循环有序列表的插入
//
///**
// * Definition for a Node.
// * struct Node {
// *     int val;
// *     struct TreeNode *next;
// * };
// */
//
//struct Node* insert(struct Node* head, int insertVal)
//{
//    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
//    node->val = insertVal;
//    node->next = node;
//    if (!head) return node;
//    if (head->next == head)
//    {
//        node->next = head;
//        head->next = node;
//        return head;
//    }
//    struct Node* cur = head;
//    // 记录起始结点
//    struct Node* start = head;
//    // 头节点值比插入值大，先找到最小值所在的结点
//    if (head->val > insertVal)
//    {
//        // 沿着有序链表找到最小结点
//        while (cur->next != head && cur->next->val >= cur->val)
//        {
//            cur = cur->next;
//        }
//        // cur -> next == head说明整个链表的结点值相等，且大于插入值，直接将新节点插入，返回头节点
//        if (cur->next != head && cur->next->val < insertVal)
//        {
//            cur = cur->next;
//            // 更新起始结点
//            start = cur;
//            // 按序找到第一个值大于等于插入值的后续结点
//            while (cur->next->val <= insertVal && cur->next != start)
//            {
//                cur = cur->next;
//            }
//        }
//    }
//    // 头节点值比插入值小，按序比较
//    // 直到找到第一个大于等于插入的后续节点或者后续节点回到起点或来到最小值的结点
//    else
//    {
//        while (cur->next->val <= insertVal && cur->next->val >= cur->val && cur->next != head)
//        {
//            cur = cur->next;
//        }
//    }
//    node->next = cur->next;
//    cur->next = node;
//    return head;
//}
//
