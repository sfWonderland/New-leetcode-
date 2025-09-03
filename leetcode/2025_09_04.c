////1441. 用栈操作构建数组
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** buildArray(int* target, int targetSize, int n, int* returnSize)
//{
//    char* operation[2] = { "Push", "Pop" };
//    char** ans = (char**)malloc(sizeof(char*) * n * 2);
//    int idx = 0, t = 0;
//    for (int i = 1; i <= target[targetSize - 1]; i++)
//    {
//        ans[idx] = (char*)malloc(sizeof(char) * 5);
//        ans[idx++] = operation[0];
//        if (target[t] != i)
//        {
//            ans[idx] = (char*)malloc(sizeof(char) * 4);
//            ans[idx++] = operation[1];
//        }
//        else
//            t++;
//    }
//    *returnSize = idx;
//    return ans;
//}
//
////1472. 设计浏览器历史记录
//
//typedef struct
//{
//    char** st;
//    int top;
//    int cur;
//} BrowserHistory;
//
//
//BrowserHistory* browserHistoryCreate(char* homepage)
//{
//    BrowserHistory* obj = (BrowserHistory*)malloc(sizeof(BrowserHistory));
//    obj->st = (char**)malloc(sizeof(char*) * 5000);
//    obj->top = 1;
//    obj->cur = 0;
//    obj->st[0] = strdup(homepage);
//    return obj;
//}
//
//void browserHistoryVisit(BrowserHistory* obj, char* url)
//{
//    while (obj->top > obj->cur + 1)
//    {
//        free(obj->st[--(obj->top)]);
//    }
//    obj->st[(obj->top)++] = strdup(url);
//    (obj->cur)++;
//}
//
//char* browserHistoryBack(BrowserHistory* obj, int steps)
//{
//    obj->cur = fmax(0, obj->cur - steps);
//    return obj->st[obj->cur];
//}
//
//char* browserHistoryForward(BrowserHistory* obj, int steps)
//{
//    obj->cur = fmin(obj->top - 1, obj->cur + steps);
//    return obj->st[obj->cur];
//}
//
//void browserHistoryFree(BrowserHistory* obj)
//{
//    for (int i = 0; i < obj->top; i++)
//    {
//        free(obj->st[i]);
//    }
//    free(obj->st);
//    free(obj);
//}
//
///**
// * Your BrowserHistory struct will be instantiated and called as such:
// * BrowserHistory* obj = browserHistoryCreate(homepage);
// * browserHistoryVisit(obj, url);
//
// * char* param_2 = browserHistoryBack(obj, steps);
//
// * char* param_3 = browserHistoryForward(obj, steps);
//
// * browserHistoryFree(obj);
//*/
//
////946. 验证栈序列
//
//bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize)
//{
//    int n = poppedSize;
//    int* st = (int*)malloc(sizeof(int) * n);
//    int idx = 0, top = -1;
//    for (int i = 0; i < n; i++)
//    {
//        st[++top] = pushed[i];
//        while (top >= 0 && st[top] == popped[idx])
//        {
//            top--;
//            idx++;
//        }
//    }
//    return top < 0;
//}
//
////3412. 计算字符串的镜像分数
//
//long long calculateScore(char* s)
//{
//    int n = strlen(s);
//    int** st = (int**)malloc(sizeof(int*) * 26);
//    for (int i = 0; i < 26; i++)
//    {
//        st[i] = (int*)malloc(sizeof(int) * n);
//    }
//    int* tops = (int*)calloc(sizeof(int), 26);
//    long long ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int top = tops['z' - s[i]];
//        if (top)
//        {
//            tops['z' - s[i]]--;
//            ans += i - st['z' - s[i]][top - 1];
//        }
//        else
//        {
//            st[s[i] - 'a'][tops[s[i] - 'a']++] = i;
//        }
//    }
//    for (int i = 0; i < 26; i++)
//    {
//        free(st[i]);
//    }
//    free(st);
//    free(tops);
//    return ans;
//}
//
