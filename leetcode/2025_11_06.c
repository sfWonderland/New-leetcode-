////3659. 数组元素分组
//
//bool partitionArray(int* nums, int numsSize, int k)
//{
//    if (numsSize % k)
//        return false;
//
//    int cnt[100001] = { 0 };
//    int max = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        max = fmax(max, ++cnt[nums[i]]);
//    }
//    return max <= numsSize / k;
//}
//
////767. 重构字符串
//
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e2)[1] - (*(int**)e1)[1];
//}
//char* reorganizeString(char* s)
//{
//    int n = strlen(s);
//    int** cnt = (int**)malloc(sizeof(int*) * 26);
//    for (int i = 0; i < 26; i++)
//    {
//        cnt[i] = (int*)malloc(sizeof(int) * 2);
//        cnt[i][0] = i; //ch
//        cnt[i][1] = 0; //n
//    }
//    for (int i = 0; i < n; i++)
//    {
//        ++cnt[s[i] - 'a'][1];
//    }
//    qsort(cnt, 26, sizeof(int*), cmp);
//    if (cnt[0][1] > (n + 1) / 2)
//        return "";
//    int t = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        if (cnt[i][1] == 0)
//            break;
//
//        while (cnt[i][1]--)
//        {
//            s[t] = cnt[i][0] + 'a';
//            t += 2;
//            if (t >= n)
//                t = 1;
//        }
//    }
//    return s;
//}
//
////1881. 插入后的最大值
//
//char* maxValue(char* n, int x)
//{
//    int num = strlen(n);
//    int i = 0;
//    if (n[0] == '-')
//    {
//        i++;
//        while (i < num && n[i] <= x + '0')
//            i++;
//    }
//    else
//    {
//        while (i < num && n[i] >= x + '0')
//            i++;
//    }
//    char* ans = (char*)malloc(sizeof(char) * (num + 2));
//    for (int j = 0; j < i; j++)
//    {
//        ans[j] = n[j];
//    }
//    ans[i] = x + '0';
//    for (int j = i + 1; j <= num; j++)
//    {
//        ans[j] = n[j - 1];
//    }
//    ans[num + 1] = '\0';
//    return ans;
//}
//
////2734. 执行子串操作后的字典序最小字符串
//
//char* smallestString(char* s)
//{
//    int n = strlen(s), i = 0;
//    while (i < n && s[i] == 'a')
//        i++;
//    if (i == n)
//    {
//        s[n - 1] = 'z';
//        return s;
//    }
//    while (i < n && s[i] != 'a')
//        s[i++]--;
//    return s;
//}
//
