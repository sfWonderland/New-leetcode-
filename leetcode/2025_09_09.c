////2327. 知道秘密的人数
//
//#define MOD 1000000007
//int peopleAwareOfSecret(int n, int delay, int forget)
//{
//    int* sum = (int*)malloc(sizeof(int) * (n + 1));
//    sum[0] = 0; sum[1] = 1;
//    for (int i = 2; i <= n; i++)
//    {
//        int known = (sum[(int)fmax(i - delay, 0)] - sum[(int)fmax(i - forget, 0)]) % MOD;
//        sum[i] = (sum[i - 1] + known) % MOD;
//    }
//    int ans = sum[n] - sum[(int)fmax(n - forget, 0)];
//    free(sum);
//    return (ans % MOD + MOD) % MOD;
//}
//
////1249. 移除无效的括号
//
//char* minRemoveToMakeValid(char* s)
//{
//    int n = strlen(s);
//    int* st = (int*)malloc(sizeof(int) * n);
//    int bal = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] == '(')
//            st[bal++] = i;
//        else if (s[i] == ')')
//        {
//            if (bal == 0)
//                s[i] = '*';
//            else
//                bal--;
//        }
//    }
//    for (int i = 0; i < bal; i++)
//    {
//        s[st[i]] = '*';
//    }
//    int idx = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (s[i] != '*')
//            s[idx++] = s[i];
//    }
//    s[idx] = '\0';
//    return s;
//}
//
////1006. 笨阶乘
//
//int clumsy(int n)
//{
//    int* st = (int*)malloc(sizeof(int) * n);
//    int top = -1, idx = 0;
//    st[++top] = n;
//    for (int i = n - 1; i > 0; i--)
//    {
//        if (idx % 4 == 0)
//            st[top] *= i;
//        else if (idx % 4 == 1)
//            st[top] /= i;
//        else if (idx % 4 == 2)
//            st[++top] = i;
//        else
//            st[++top] = -i;
//
//        idx++;
//    }
//    int ans = 0;
//    while (top >= 0)
//    {
//        ans += st[top--];
//    }
//    free(st);
//    return ans;
//}
//
////933. 最近的请求次数
//
//typedef struct
//{
//    int* queue;
//    int top;
//    int bottom;
//} RecentCounter;
//
//
//RecentCounter* recentCounterCreate()
//{
//    RecentCounter* obj = (RecentCounter*)malloc(sizeof(RecentCounter));
//    obj->queue = (int*)malloc(sizeof(int) * 10000);
//    obj->top = -1;
//    obj->bottom = 0;
//    return obj;
//}
//
//int recentCounterPing(RecentCounter* obj, int t)
//{
//    obj->queue[++obj->top] = t;
//    while (obj->bottom <= obj->top && obj->queue[obj->bottom] < t - 3000)
//        obj->bottom++;
//
//    return obj->top - obj->bottom + 1;
//}
//
//void recentCounterFree(RecentCounter* obj)
//{
//    free(obj->queue);
//    free(obj);
//}
//
///**
// * Your RecentCounter struct will be instantiated and called as such:
// * RecentCounter* obj = recentCounterCreate();
// * int param_1 = recentCounterPing(obj, t);
//
// * recentCounterFree(obj);
//*/
//
