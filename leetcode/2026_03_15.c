////101008. 统计范围内的逗号
//
//int countCommas(int n)
//{
//    return n >= 1000 ? n - 999 : 0;
//}
//
////101011. 统计范围内的逗号 II    
//
//long long countCommas(long long n)
//{
//    long long base = 1000;
//    long long t = 1;
//    long long ans = 0;
//    while (n >= base)
//    {
//        long long new_base = base * 1000;
//        if (n >= new_base)
//            ans += (new_base - base) * t;
//        else
//            ans += (n - base + 1) * t;
//        t++;
//        base = new_base;
//    }
//    return ans;
//}
//
////2186. 制造字母异位词的最小步骤数 II
//
//int minSteps(char* s, char* t)
//{
//    int cnt[26] = { 0 };
//    for (int i = 0; s[i]; i++)
//    {
//        cnt[s[i] - 'a']++;
//    }
//    for (int i = 0; t[i]; i++)
//    {
//        cnt[t[i] - 'a']--;
//    }
//    int ans = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        if (cnt[i])
//            ans += abs(cnt[i]);
//    }
//    return ans;
//}
//
////2201. 统计可以提取的工件
//
//typedef struct
//{
//    int key;
//    UT_hash_handle hh;
//}HashItem;
//int digArtifacts(int n, int** artifacts, int artifactsSize, int* artifactsColSize, int** dig, int digSize, int* digColSize)
//{
//    HashItem* digged = NULL;
//    HashItem* p = NULL;
//    for (int i = 0; i < digSize; i++)
//    {
//        p = (HashItem*)malloc(sizeof(HashItem));
//        p->key = dig[i][0] * 1000 + dig[i][1];
//        HASH_ADD_INT(digged, key, p);
//    }
//    int ans = 0;
//    for (int i = 0; i < artifactsSize; i++)
//    {
//        bool flag = true;
//        for (int j = artifacts[i][0]; j <= artifacts[i][2] && flag; j++)
//        {
//            for (int k = artifacts[i][1]; k <= artifacts[i][3] && flag; k++)
//            {
//                int key = j * 1000 + k;
//                HASH_FIND_INT(digged, &key, p);
//                if (p == NULL)
//                    flag = false;
//            }
//        }
//        ans += flag;
//    }
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, digged, p, tmp)
//    {
//        HASH_DEL(digged, p);
//        free(p);
//    }
//    return ans;
//}
//
//int digArtifacts(int n, int** artifacts, int artifactsSize, int* artifactsColSize, int** dig, int digSize, int* digColSize)
//{
//    bool grid[n][n];
//    memset(grid, 0, sizeof(grid));
//    for (int i = 0; i < digSize; i++)
//    {
//        int x = dig[i][0], y = dig[i][1];
//        grid[x][y] = true;
//    }
//    int ans = 0;
//    for (int i = 0; i < artifactsSize; i++)
//    {
//        bool flag = true;
//        for (int j = artifacts[i][0]; j <= artifacts[i][2] && flag; j++)
//        {
//            for (int k = artifacts[i][1]; k <= artifacts[i][3] && flag; k++)
//            {
//                flag = grid[j][k];
//            }
//        }
//        ans += flag;
//    }
//    return ans;
//}
//
