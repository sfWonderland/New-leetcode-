////2749. 得到整数零需要执行的最少操作数
//
//int digitCount(long long x)
//{
//    int ret = 0;
//    while (x)
//    {
//        ret++;
//        x &= x - 1;
//    }
//    return ret;
//}
//int makeTheIntegerZero(int num1, int num2)
//{
//    for (long long k = 1; k <= num1 - k * num2; k++)
//    {
//        if (k >= digitCount(num1 - k * num2))
//            return k;
//    }
//    return -1;
//}
//
//int makeTheIntegerZero(int num1, int num2)
//{
//    for (long long k = 1; k <= num1 - k * num2; k++)
//    {
//        if (k >= __builtin_popcountll(num1 - k * num2))
//            return k;
//    }
//    return -1;
//}
//
////1381. 设计一个支持增量操作的栈
//
//typedef struct
//{
//    int* st;
//    int top;
//    int stSize;
//} CustomStack;
//
//
//CustomStack* customStackCreate(int maxSize)
//{
//    CustomStack* obj = (CustomStack*)malloc(sizeof(CustomStack));
//    obj->st = (int*)malloc(sizeof(int) * maxSize);
//    obj->top = -1;
//    obj->stSize = maxSize;
//    return obj;
//}
//
//void customStackPush(CustomStack* obj, int x)
//{
//    if (obj->top < obj->stSize - 1)
//        obj->st[++obj->top] = x;
//}
//
//int customStackPop(CustomStack* obj)
//{
//    return obj->top >= 0 ? obj->st[obj->top--] : -1;
//}
//
//void customStackIncrement(CustomStack* obj, int k, int val)
//{
//    for (int i = 0; i < fmin(obj->stSize, k); i++)
//    {
//        obj->st[i] += val;
//    }
//}
//
//void customStackFree(CustomStack* obj)
//{
//    free(obj->st);
//    free(obj);
//}
//
///**
// * Your CustomStack struct will be instantiated and called as such:
// * CustomStack* obj = customStackCreate(maxSize);
// * customStackPush(obj, x);
//
// * int param_2 = customStackPop(obj);
//
// * customStackIncrement(obj, k, val);
//
// * customStackFree(obj);
//*/
//
////155. 最小栈
//
//typedef struct
//{
//    int* st;
//    int* min;
//    int topS;
//    int topM;
//} MinStack;
//
//
//MinStack* minStackCreate()
//{
//    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
//    obj->st = (int*)malloc(sizeof(int) * 30000);
//    obj->min = (int*)malloc(sizeof(int) * 30000);
//    obj->topS = -1;
//    obj->topM = -1;
//    return obj;
//}
//
//void minStackPush(MinStack* obj, int val)
//{
//    obj->st[++obj->topS] = val;
//    if (obj->topM < 0 || val <= obj->min[obj->topM])
//        obj->min[++obj->topM] = val;
//}
//
//void minStackPop(MinStack* obj)
//{
//    int val = obj->st[obj->topS--];
//    if (obj->min[obj->topM] == val)
//        obj->topM--;
//}
//
//int minStackTop(MinStack* obj)
//{
//    return obj->st[obj->topS];
//}
//
//int minStackGetMin(MinStack* obj)
//{
//    return obj->min[obj->topM];
//}
//
//void minStackFree(MinStack* obj)
//{
//    free(obj->st);
//    free(obj->min);
//    free(obj);
//}
//
///**
// * Your MinStack struct will be instantiated and called as such:
// * MinStack* obj = minStackCreate();
// * minStackPush(obj, val);
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
////3170. 删除星号以后字典序最小的字符串
//
//char* clearStars(char* s)
//{
//    int n = strlen(s);
//    int** st = (int**)malloc(sizeof(int*) * 26);
//    int* top = (int*)malloc(sizeof(int) * 26);
//    for (int i = 0; i < 26; i++)
//    {
//        st[i] = (int*)malloc(sizeof(int) * n);
//        top[i] = -1;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        if (s[i] != '*')
//        {
//            st[s[i] - 'a'][++top[s[i] - 'a']] = i;
//        }
//        else
//        {
//            for (int j = 0; j < 26; j++)
//            {
//                if (top[j] >= 0)
//                {
//                    int index = st[j][top[j]--];
//                    s[index] = '*';
//                    break;
//                }
//            }
//        }
//    }
//    char* ans = (char*)malloc(sizeof(char) * (n + 1));
//    int idx = -1;
//    for (int i = 0; i < n; i++)
//    {
//        if (s[i] != '*')
//            ans[++idx] = s[i];
//    }
//    ans[++idx] = '\0';
//    return ans;
//}
//
