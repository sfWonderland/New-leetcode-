////1925. 统计平方和三元组的数目
//
//int countTriples(int n)
//{
//    int ans = 0;
//    for (int i = 3; i < n - 1; i++)
//    {
//        int x = i * i;
//        for (int j = i + 1; j < n; j++)
//        {
//            int sum = x + j * j;
//            int k = sqrt(sum);
//            if (k > n)
//                break;
//
//            if (k * k == sum)
//                ans += 2;
//        }
//    }
//    return ans;
//}
//
//int gcd(int a, int b)
//{
//    while (b)
//    {
//        int tmp = a % b;
//        a = b;
//        b = tmp;
//    }
//    return a;
//}
//int countTriples(int n)
//{
//    int ans = 0;
//    // a * a = c * c - b * b = (c + b)(c - b);
//    // a = m * n, m, n are prime numbers so c + b = m * m, c - b = n * n;
//    // or not c + b = c - b, leading to b = 0; 
//    // u * u = c + b, v * v = c - b, gcd(u, v) = 1 = t;
//    // if t > 1, a * a = t * t * x * x, not the simplest type;
//    // u * v % 2 = 1, if not gcd(u, v) > 1 therefore u % 2 = 1, v % 2 = 1;
//    // therefore a % 2 = 1; 
//    // so a = uv, b = (u * u - v * v) / 2, c = (u * u + v * v) / 2
//    // and c <= n, so u * u + v * v <= 2 * n
//    // turning u, v around may double the result
//    for (int u = 3; u * u < 2 * n; u += 2)
//    {
//        for (int v = 1; v < u && u * u + v * v <= 2 * n; v += 2)
//        {
//            if (gcd(u, v) == 1)
//            {
//                ans += n * 2 / (u * u + v * v);
//            }
//        }
//    }
//    return ans * 2;
//}
//
////3186. 施咒的最大总伤害
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e1)[0] - (*(int**)e2)[0];
//}
//long long maximumTotalDamage(int* power, int powerSize)
//{
//    HashItem* spell = NULL;
//    HashItem* pEntry = NULL;
//    int n = 0;
//    for (int i = 0; i < powerSize; i++)
//    {
//        HASH_FIND_INT(spell, &power[i], pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = power[i];
//            pEntry->val = 1;
//            HASH_ADD_INT(spell, key, pEntry);
//            n++;
//        }
//        else
//            pEntry->val++;
//    }
//    int** cnt = (int**)malloc(sizeof(int*) * n);
//    int i = 0;
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, spell, pEntry, tmp)
//    {
//        cnt[i] = (int*)malloc(sizeof(int) * 2);
//        cnt[i][0] = pEntry->key;
//        cnt[i++][1] = pEntry->val;
//        free(pEntry);
//    }
//    qsort(cnt, n, sizeof(int*), cmp);
//    long long* res = (long long*)malloc(sizeof(long long) * n);
//    for (int i = 0; i < n; i++)
//    {
//        res[i] = -1;
//    }
//    long long dfs(int i)
//    {
//        if (i < 0)
//            return 0;
//
//        if (res[i] != -1)
//            return res[i];
//
//        int j = i;
//        while (j > 0 && cnt[j - 1][0] >= cnt[i][0] - 2)
//            j--;
//        res[i] = fmax(dfs(j - 1) + 1ll * cnt[i][0] * cnt[i][1], dfs(i - 1));
//        return res[i];
//    }
//    return dfs(n - 1);
//}
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e1)[0] - (*(int**)e2)[0];
//}
//long long maximumTotalDamage(int* power, int powerSize)
//{
//    HashItem* spell = NULL;
//    HashItem* pEntry = NULL;
//    int n = 0;
//    for (int i = 0; i < powerSize; i++)
//    {
//        HASH_FIND_INT(spell, &power[i], pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = power[i];
//            pEntry->val = 1;
//            HASH_ADD_INT(spell, key, pEntry);
//            n++;
//        }
//        else
//            pEntry->val++;
//    }
//    int** cnt = (int**)malloc(sizeof(int*) * n);
//    int i = 0;
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, spell, pEntry, tmp)
//    {
//        cnt[i] = (int*)malloc(sizeof(int) * 2);
//        cnt[i][0] = pEntry->key;
//        cnt[i++][1] = pEntry->val;
//        free(pEntry);
//    }
//    qsort(cnt, n, sizeof(int*), cmp);
//    long long f[n + 1];
//    f[0] = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int j = i;
//        while (j > 0 && cnt[j - 1][0] >= cnt[i][0] - 2)
//            j--;
//        f[i + 1] = fmax(f[i], f[j] + 1ll * cnt[i][0] * cnt[i][1]);
//    }
//    return f[n];
//}
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//long long maximumTotalDamage(int* power, int powerSize)
//{
//    qsort(power, powerSize, sizeof(int), cmp);
//    int capacity = 64;
//    int** cnt = (int**)malloc(sizeof(int*) * capacity);
//    int n = 0;
//    cnt[0] = (int*)malloc(sizeof(int) * 2);
//    cnt[0][0] = power[0];
//    cnt[0][1] = 1;
//    for (int i = 1; i < powerSize; i++)
//    {
//        if (power[i] == cnt[n][0])
//            cnt[n][1]++;
//        else
//        {
//            cnt[++n] = (int*)malloc(sizeof(int) * 2);
//            cnt[n][0] = power[i];
//            cnt[n][1] = 1;
//        }
//        if (n + 1 >= capacity)
//        {
//            capacity *= 2;
//            cnt = (int**)realloc(cnt, sizeof(int*) * capacity);
//        }
//    }
//    n++;
//    long long f[n + 1];
//    f[0] = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int j = i;
//        while (j > 0 && cnt[j - 1][0] >= cnt[i][0] - 2)
//            j--;
//        f[i + 1] = fmax(f[i], f[j] + 1ll * cnt[i][0] * cnt[i][1]);
//    }
//    return f[n];
//}
//
////3196. 最大化子数组的总成本
//
//long long maximumTotalCost(int* nums, int numsSize)
//{
//    int n = numsSize;
//    long long* res = (long long*)malloc(sizeof(long long) * n);
//    for (int i = 0; i < n; i++)
//    {
//        res[i] = LLONG_MIN;
//    }
//    long long dfs(int i)
//    {
//        if (i < 0)
//            return 0;
//
//        if (i == 0)
//            return nums[0];
//
//        if (res[i] != LLONG_MIN)
//            return res[i];
//
//        res[i] = fmax(dfs(i - 1) + nums[i], dfs(i - 2) + nums[i - 1] - nums[i]);
//        return res[i];
//    }
//    return dfs(n - 1);
//}
//
//long long maximumTotalCost(int* nums, int numsSize)
//{
//    int n = numsSize;
//    long long f[n + 1];
//    f[0] = 0; f[1] = nums[0];
//    for (int i = 1; i < n; i++)
//    {
//        f[i + 1] = fmax(f[i] + nums[i], f[i - 1] + nums[i - 1] - nums[i]);
//    }
//    return f[n];
//}
//
//long long maximumTotalCost(int* nums, int numsSize)
//{
//    int n = numsSize;
//    long long f0 = 0, f1 = nums[0];
//    for (int i = 1; i < n; i++)
//    {
//        long long tmp = f0;
//        f0 = f1;
//        f1 = fmax(f1 + nums[i], tmp + nums[i - 1] - nums[i]);
//    }
//    return f1;
//}
//
//long long maximumTotalCost(int* nums, int numsSize)
//{
//    int n = numsSize;
//    long long f[n + 1][2];
//    f[n][0] = f[n][1] = 0;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        f[i][0] = f[i + 1][1] + nums[i];
//        f[i][1] = fmax(f[i + 1][1] + nums[i], f[i + 1][0] - nums[i]);
//    }
//    return f[0][0];
//}
//
//long long maximumTotalCost(int* nums, int numsSize)
//{
//    int n = numsSize;
//    long long f0 = 0, f1 = 0;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        long long tmp = f0;
//        f0 = f1 + nums[i];
//        f1 = fmax(f1 + nums[i], tmp - nums[i]);
//    }
//    return f0;
//}
//
////2767. 将字符串分割为最少的美丽子字符串
//
//int minimumBeautifulSubstrings(char* s)
//{
//    int n = strlen(s);
//    int* res = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        res[i] = INT_MAX / 2;
//    }
//    int dfs(int i)
//    {
//        if (i == n)
//            return 0;
//
//        if (s[i] == '0')
//            return INT_MAX / 2;  //不能包含前导 0
//
//        if (res[i] != INT_MAX / 2)
//            return res[i];
//
//        int t = s[i] - '0';
//        for (int j = i; j < n; j++)
//        {
//            //printf("%d ", t);
//            if (t > 0 && 15625 % t == 0)
//                res[i] = fmin(res[i], dfs(j + 1) + 1);
//            t = t * 2 + s[j + 1] - '0';
//        }
//        return res[i];
//    }
//    int ans = dfs(0);
//    return ans < INT_MAX / 2 ? ans : -1;
//}
//
//int minimumBeautifulSubstrings(char* s)
//{
//    int n = strlen(s);
//    int f[n + 1];
//    f[n] = 0;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        f[i] = INT_MAX / 2;
//        if (s[i] == '0')
//            continue;
//
//        int t = s[i] - '0';
//        for (int j = i; j < n; j++)
//        {
//            if (t > 0 && 15625 % t == 0)
//                f[i] = fmin(f[i], f[j + 1] + 1);
//
//            t = t * 2 + s[j + 1] - '0';
//        }
//    }
//    return f[0] < INT_MAX / 2 ? f[0] : -1;
//}
//
