//// 457. 环形数组是否存在循环
//
//bool circularArrayLoop(int* nums, int numsSize)
//{
//    int n = numsSize;
//    bool check(int start)
//    {
//        int cur = start;
//        int k = 1;
//        bool flag = nums[start] > 0;
//        // 不符合要求的循环：单循环，该元素在循环外，循环内符号不一致
//        // 符合要求的循环：循环回初始点，且不是单循环，循环内符号一致
//        while (k <= n)
//        {
//            int next = ((cur + nums[cur]) % n + n) % n;
//            if (flag && nums[next] < 0) return false;
//            if (!flag && nums[next] > 0) return false;
//            if (next == start) return k > 1;
//            k++;
//            cur = next;
//        }
//        return false;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        if (check(i))
//            return true;
//    }
//    return false;
//}
//
//bool circularArrayLoop(int* nums, int numsSize)
//{
//    int n = numsSize, idx = 1;
//    int vis[n];
//    memset(vis, 0, sizeof(vis));
//    bool check(int start)
//    {
//        if (vis[start] != 0)
//            return false;
//        int cur = start;
//        bool flag = nums[start] > 0;
//        // 不符合要求的循环：单循环，该元素在循环外，循环内符号不一致
//        // 符合要求的循环：循环回初始点，且不是单循环，循环内符号一致
//        while (1)
//        {
//            int next = ((cur + nums[cur]) % n + n) % n;
//            if (next == cur) return false; // 单循环
//            // 如果 next 点已经被标记过，并且不是在本轮被标记，那么往后的通路必然都被标记，且无环，跳出
//            // 如果 next 点已被标记，并且是本来被标记，说明找到了环
//            if (vis[next] != 0) return vis[next] == idx;
//            // 循环中异号
//            if (flag && nums[next] < 0) return false;
//            if (!flag && nums[next] > 0) return false;
//            vis[next] = idx;
//            cur = next;
//        }
//        return false;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        if (check(i))
//            return true;
//        idx++;
//    }
//    return false;
//}
//
//bool circularArrayLoop(int* nums, int numsSize)
//{
//    int n = numsSize, OFFSET = 100010;
//    bool check(int start)
//    {
//        if (nums[start] >= OFFSET)
//            return false;
//        int cur = start, tag = OFFSET + start, last = -1;
//        bool flag = nums[start] > 0;
//        // 不符合要求的循环：单循环，该元素在循环外，循环内符号不一致
//        // 符合要求的循环：循环回初始点，且不是单循环，循环内符号一致
//        while (1)
//        {
//            int next = ((cur + nums[cur]) % n + n) % n;
//            last = nums[cur];
//            nums[cur] = tag;
//            if (cur == next) return false;
//            cur = next;
//            if (start == cur) return true; // 循环
//            // 如果 next 点已经被标记过，并且不是在本轮被标记，那么往后的通路必然都被标记，且无环，跳出
//            // 如果 next 点已被标记，并且是本来被标记，说明找到了环
//            if (nums[cur] >= OFFSET) return nums[cur] == tag;
//            // 循环中异号
//            if (flag && nums[cur] < 0) return false;
//            if (!flag && nums[cur] > 0) return false;
//        }
//        return false;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        if (check(i))
//            return true;
//    }
//    return false;
//}
//
