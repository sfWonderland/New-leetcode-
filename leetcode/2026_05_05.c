//// 面试题 01.07. 旋转矩阵
//
//void rotate(int** matrix, int matrixSize, int* matrixColSize)
//{
//    int n = matrixSize;
//    for (int i = 0; i < n / 2; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            int tmp = matrix[i][j];
//            matrix[i][j] = matrix[n - 1 - i][j];
//            matrix[n - 1 - i][j] = tmp;
//        }
//    }
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j <= i; j++)
//        {
//            int tmp = matrix[i][j];
//            matrix[i][j] = matrix[j][i];
//            matrix[j][i] = tmp;
//        }
//    }
//}
//
//// 面试题 01.08. 零矩阵   
//
//void setZeroes(int** matrix, int matrixSize, int* matrixColSize)
//{
//    int m = matrixSize, n = matrixColSize[0];
//    bool row[m], col[n];
//    memset(row, 0, sizeof(row));
//    memset(col, 0, sizeof(col));
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (matrix[i][j] == 0)
//            {
//                row[i] = true;
//                col[j] = true;
//            }
//        }
//    }
//    for (int i = 0; i < m; i++)
//    {
//        if (row[i] == 0)
//            continue;
//
//        memset(matrix[i], 0, sizeof(int) * n);
//    }
//    for (int i = 0; i < n; i++)
//    {
//        if (col[i] == 0)
//            continue;
//
//        for (int j = 0; j < m; j++)
//        {
//            matrix[j][i] = 0;
//        }
//    }
//}
//
//// 面试题 01.09. 字符串轮转
//
//bool isFlipedString(char* s1, char* s2)
//{
//    int n = strlen(s1), m = strlen(s2);
//    if (m != n)
//        return false;
//
//    char* s = (char*)malloc(sizeof(char) * (2 * n + 1));
//    strcpy(s, s2);
//    strcat(s, s2);
//    s[2 * n] = '\0';
//    return strstr(s, s1);
//}
//
//// 面试题 02.04. 分割链表
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* partition(struct ListNode* head, int x)
//{
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = head;
//    struct ListNode* head2 = dummy;
//    struct ListNode* pre = dummy;
//    struct ListNode* cur = head;
//    while (cur && cur->val < x)
//    {
//        pre = cur;
//        cur = cur->next;
//    }
//    while (cur)
//    {
//        if (cur->val < x)
//        {
//            pre->next = cur->next;
//            cur->next = head2->next;
//            head2->next = cur;
//            cur = pre;
//        }
//        pre = cur;
//        cur = cur->next;
//    }
//    return dummy->next;
//}
//
