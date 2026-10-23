//// 3412. 计算字符串的镜像分数
//
//long long calculateScore(char* s)
//{
//    int n = strlen(s);
//    int** alpha_st = (int**)malloc(sizeof(int*) * 26);
//    for (int i = 0; i < 26; i++)
//    {
//        alpha_st[i] = (int*)malloc(sizeof(int) * n);
//    }
//    int* tops = (int*)calloc(sizeof(int), 26);
//    long long ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int x = s[i] - 'a';
//        int mirror = 25 - x;
//        if (tops[mirror])
//        {
//            tops[mirror]--;
//            int top = tops[mirror];
//            int* st = alpha_st[mirror];
//            ans += i - st[top];
//        }
//        else
//            alpha_st[x][tops[x]++] = i;
//    }
//    for (int i = 0; i < 26; i++)
//    {
//        free(alpha_st[i]);
//    }
//    free(alpha_st);
//    return ans;
//}
//
