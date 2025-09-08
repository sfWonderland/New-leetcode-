////1317. 将整数转换为两个无零整数的和
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* getNoZeroIntegers(int n, int* returnSize)
//{
//    int* ans = (int*)calloc(sizeof(int), 2);
//    int base = 1;
//    for (int x = n; x > 1; x /= 10)
//    {
//        int d = x % 10;
//        if (d < 2)
//        {
//            d += 10;
//            x -= 10;
//        }
//        ans[0] += d / 2 * base;
//        base *= 10;
//    }
//    ans[1] = n - ans[0];
//    *returnSize = 2;
//    return ans;
//}
//
////921. 使括号有效的最少添加
//
//int minAddToMakeValid(char* s)
//{
//    int top = -1;
//    for (int i = 0; s[i]; i++)
//    {
//        if (top < 0 || s[top] == ')' || s[top] == s[i])
//            s[++top] = s[i];
//        else
//            top--;
//    }
//    return top + 1;
//}
//
////1190. 反转每对括号间的子串
//
//void reverse(char* s, int left, int right)
//{
//    while (left < right)
//    {
//        char tmp = s[left];
//        s[left++] = s[right];
//        s[right--] = tmp;
//    }
//}
//char* reverseParentheses(char* s)
//{
//    int n = strlen(s);
//    int* st = (int*)malloc(sizeof(int) * n);
//    int top = -1, idx = -1;
//    for (int i = 0; i < n; i++)
//    {
//        if (s[i] == '(')
//            st[++top] = idx + 1;
//        else if (s[i] == ')')
//            reverse(s, st[top--], idx);
//        else
//            s[++idx] = s[i];
//    }
//    s[++idx] = '\0';
//    return s;
//}
//
////856. 括号的分数
//
//int scoreOfParentheses(char* s)
//{
//    int n = strlen(s);
//    int* st = (int*)malloc(sizeof(int) * n);
//    int top = -1;
//    for (int i = 0; i < n; i++)
//    {
//        if (s[i] == '(')
//            st[++top] = 0;
//        else
//        {
//            int v = st[top--];
//            if (top < 0)
//                st[++top] = 0;
//            if (v)
//                st[top] += 2 * v;
//            else
//                st[top] += 1;
//        }
//    }
//    return st[top];
//}
//
