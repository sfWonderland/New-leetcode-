//// 101057. 统计下标的相反奇偶性得分
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* countOppositeParity(int* nums, int numsSize, int* returnSize)
//{
//    int n = numsSize;
//    int parity[2] = { 0 };
//    for (int i = 0; i < n; i++)
//    {
//        parity[nums[i] & 1]++;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        bool x = nums[i] & 1;
//        parity[x]--;
//        nums[i] = parity[x ^ 1];
//    }
//    *returnSize = n;
//    return nums;
//}
//
//// 101059. 区间内的质数和   
//
//const int prime[170] = { 0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1001 };
//int reverse(int x)
//{
//    int res = 0;
//    while (x)
//    {
//        res *= 10;
//        res += x % 10;
//        x /= 10;
//    }
//    return res;
//}
//int binary_search(int x)
//{
//    int left = 0, right = 169;
//    while (left <= right)
//    {
//        int mid = (left + right) / 2;
//        // printf("%d ", mid);
//        if (prime[mid] >= x)
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    // printf("%d %d\n", left, prime[left]);
//    return left;
//}
//int sumOfPrimesInRange(int n)
//{
//    int m = reverse(n);
//    if (m > n)
//    {
//        int tmp = m;
//        m = n;
//        n = tmp;
//    }
//    if (m == n)
//        return prime[binary_search(m)] == m ? m : 0;
//    int a = binary_search(m);
//    int b = binary_search(n);
//    if (prime[b] > n)
//        b--;
//    int sum = 0;
//    for (int i = a; i <= b; i++)
//    {
//        sum += prime[i];
//    }
//    return sum;
//}
//
//// 101053. 在下标间移动的最小代价
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* minCost(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
//{
//    int n = numsSize;
//    int l_r[n], r_l[n];
//    l_r[0] = 0, r_l[0] = 0;
//    l_r[1] = 1;
//    for (int i = 1; i < n - 1; i++)
//    {
//        int r = nums[i] - nums[i - 1];
//        int l = nums[i + 1] - nums[i];
//        if (l >= r)
//        {
//            l_r[i + 1] = l + l_r[i];
//            r_l[i] = 1 + r_l[i - 1];
//        }
//        else
//        {
//            l_r[i + 1] = 1 + l_r[i];
//            r_l[i] = r + r_l[i - 1];
//        }
//    }
//    r_l[n - 1] = 1 + r_l[n - 2];
//
//    int m = queriesSize;
//    int* ans = (int*)malloc(sizeof(int) * m);
//    for (int i = 0; i < m; i++)
//    {
//        int x = queries[i][0];
//        int y = queries[i][1];
//        if (x <= y)
//        {
//            // printf("%d %d %d %d\n", y, l_r[y], x, l_r[x]);
//            ans[i] = l_r[y] - l_r[x];
//        }
//        else
//        {
//            // printf("%d %d %d %d\n", x, r_l[x], y, r_l[y]);
//            ans[i] = r_l[x] - r_l[y];
//        }
//    }
//    *returnSize = m;
//    return ans;
//}
//
//// 面试题 01.02. 判定是否互为字符重排
//
//bool CheckPermutation(char* s1, char* s2)
//{
//    int n = strlen(s1);
//    int m = strlen(s2);
//    if (n != m)
//        return false;
//    int cnt[26] = { 0 };
//    for (int i = 0; i < n; i++)
//    {
//        cnt[s1[i] - 'a']++;
//        cnt[s2[i] - 'a']--;
//    }
//    for (int i = 0; i < 26; i++)
//    {
//        if (cnt[i])
//            return false;
//    }
//    return true;
//}
//
