////3818. 移除前缀使数组严格递增
//
//int minimumPrefixLength(int* nums, int numsSize)
//{
//    int ans = 0;
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (nums[i] <= nums[i - 1])
//            ans = i;
//    }
//    return ans;
//}
//
////3819. 非负元素轮替    
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* rotateElements(int* nums, int numsSize, int k, int* returnSize)
//{
//    *returnSize = numsSize;
//    int n = 0;
//    long long* arr = (long long*)malloc(sizeof(long long) * numsSize);
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] >= 0)
//            arr[n++] = (1ll * nums[i] << 17) | i;
//    }
//    if (n == 0)
//        return nums;
//    k %= n;
//    for (int i = 0; i < n; i++)
//    {
//        int x = arr[i] >> 17;
//        int idx = arr[(i - k + n) % n] & 0x1ffff;
//        nums[idx] = x;
//    }
//    return nums;
//}
//
////3820. 树上的勾股距离节点
//
//int specialNodes(int n, int** edges, int edgesSize, int* edgesColSize, int x, int y, int z)
//{
//    int neighbors[2 * n];
//    int next[2 * n];
//    int head[n];
//    int edge_cnt = 0;
//    memset(head, -1, sizeof(head));
//
//    void add_neighbor(int u, int v)
//    {
//        neighbors[edge_cnt] = v;
//        next[edge_cnt] = head[u];
//        head[u] = edge_cnt++;
//    }
//
//    void bfs(int start, int* dist, int n)
//    {
//        memset(dist, -1, sizeof(int) * n);
//        int queue[n], front = 0, rear = 0;
//
//        queue[rear++] = start;
//        dist[start] = 0;
//
//        while (front < rear)
//        {
//            int u = queue[front++];
//            for (int p = head[u]; p != -1; p = next[p])
//            {
//                int v = neighbors[p];
//                if (dist[v] == -1)
//                {
//                    dist[v] = dist[u] + 1;
//                    queue[rear++] = v;
//                }
//            }
//        }
//    }
//
//    for (int i = 0; i < edgesSize; i++)
//    {
//        add_neighbor(edges[i][0], edges[i][1]);
//        add_neighbor(edges[i][1], edges[i][0]);
//    }
//
//    int* dist_x = (int*)malloc(sizeof(int) * n);
//    int* dist_y = (int*)malloc(sizeof(int) * n);
//    int* dist_z = (int*)malloc(sizeof(int) * n);
//
//    bfs(x, dist_x, n);
//    bfs(y, dist_y, n);
//    bfs(z, dist_z, n);
//
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int a = dist_x[i], b = dist_y[i], c = dist_z[i];
//        long long dists[3] = { 1ll * a * a, 1ll * b * b, 1ll * c * c };
//        for (int j = 0; j < 2; j++)
//        {
//            for (int k = j + 1; k < 3; k++)
//            {
//                if (dists[j] > dists[k])
//                {
//                    long long tmp = dists[j];
//                    dists[j] = dists[k];
//                    dists[k] = tmp;
//                }
//            }
//        }
//
//        if (dists[0] + dists[1] == dists[2])
//            ans++;
//    }
//
//    free(dist_x);
//    free(dist_y);
//    free(dist_z);
//
//    return ans;
//}
//
////3815. 设计拍卖系统
//
//typedef struct {
//    long long key;
//    int val;
//    UT_hash_handle hh;
//} HashItem;
//
//typedef struct {
//    int key;
//    int capacity;
//    long long* heap; // (bidAmount + userId * 1e10);
//    int heapSize;
//    UT_hash_handle hh;
//} LazyHeaps;
//
//typedef struct {
//    HashItem* amount; // (userId << 16 + itemId) -> bidAmount
//    LazyHeaps* bid;  // itemId -> [(bidAmount, userId)]  
//} AuctionSystem;
//
//#define N 10000000000
//
//void up(long long* heap, int i) {
//    long long x = heap[i];
//    int n = x % N;
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2) {
//        int m = heap[j] % N;
//        if (m > n || (m == n && heap[j] >= x))
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//        if (j == 0)
//            break;
//    }
//    heap[i] = x;
//}
//
//void down(long long* heap, int n, int i) {
//    long long x = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1) {
//        if (j < n - 1) {
//            int a = heap[j + 1] % N;
//            int b = heap[j] % N;
//            if (a > b || (a == b && heap[j + 1] > heap[j]))
//                j++;
//        }
//        int m = heap[j] % N;
//        int n_val = x % N;
//        if (m < n_val || (m == n_val && heap[j] <= heap[i]))
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//
//AuctionSystem* auctionSystemCreate() {
//    AuctionSystem* obj = (AuctionSystem*)malloc(sizeof(AuctionSystem));
//    obj->amount = NULL;
//    obj->bid = NULL;
//    return obj;
//}
//
//void auctionSystemAddBid(AuctionSystem* obj, int userId, int itemId, int bidAmount) {
//    long long key = 1ll * userId << 16 | itemId;
//    HashItem* p1 = NULL;
//    HASH_FIND(hh, obj->amount, &key, sizeof(long long), p1);
//
//    if (p1 != NULL) {
//        // 如果已存在，更新金额
//        p1->val = bidAmount;
//    }
//    else {
//        // 添加新的出价记录
//        p1 = (HashItem*)malloc(sizeof(HashItem));
//        p1->key = key;
//        p1->val = bidAmount;
//        HASH_ADD(hh, obj->amount, key, sizeof(long long), p1);
//    }
//
//    LazyHeaps* p2 = NULL;
//    HASH_FIND_INT(obj->bid, &itemId, p2);
//    if (p2 == NULL) {
//        p2 = (LazyHeaps*)malloc(sizeof(LazyHeaps));
//        p2->key = itemId;
//        p2->capacity = 50;
//        p2->heap = (long long*)malloc(sizeof(long long) * p2->capacity);
//        p2->heapSize = 0;
//        HASH_ADD_INT(obj->bid, key, p2);
//    }
//
//    // 添加新出价到堆中
//    p2->heap[p2->heapSize++] = 1ll * bidAmount + 1ll * userId * N;
//    up(p2->heap, p2->heapSize - 1);
//
//    if (p2->heapSize >= p2->capacity) {
//        p2->capacity *= 2;
//        p2->heap = (long long*)realloc(p2->heap, sizeof(long long) * p2->capacity);
//    }
//}
//
//void auctionSystemUpdateBid(AuctionSystem* obj, int userId, int itemId, int newAmount) {
//    // 直接调用 addBid，它会处理更新逻辑
//    auctionSystemAddBid(obj, userId, itemId, newAmount);
//}
//
//void auctionSystemRemoveBid(AuctionSystem* obj, int userId, int itemId) {
//    long long key = 1ll * userId << 16 | itemId;
//    HashItem* p1 = NULL;
//    HASH_FIND(hh, obj->amount, &key, sizeof(long long), p1);
//    if (p1 != NULL) {
//        HASH_DEL(obj->amount, p1);
//        free(p1);
//    }
//}
//
//int auctionSystemGetHighestBidder(AuctionSystem* obj, int itemId) {
//    LazyHeaps* p2 = NULL;
//    HASH_FIND_INT(obj->bid, &itemId, p2);
//    if (p2 == NULL || p2->heapSize == 0)
//        return -1;
//
//    // 清理无效的出价（已被删除或金额不匹配）
//    while (p2->heapSize > 0) {
//        int userId = p2->heap[0] / N;
//        long long key = 1ll * userId << 16 | itemId;
//        HashItem* p1 = NULL;
//        HASH_FIND(hh, obj->amount, &key, sizeof(long long), p1);
//
//        if (p1 == NULL || p1->val != (p2->heap[0] % N)) {
//            // 无效出价，从堆顶移除
//            p2->heap[0] = p2->heap[--p2->heapSize];
//            down(p2->heap, p2->heapSize, 0);
//        }
//        else
//            break;
//    }
//
//    if (p2->heapSize == 0)
//        return -1;
//
//    return p2->heap[0] / N;
//}
//
//void auctionSystemFree(AuctionSystem* obj) {
//    // 释放 amount 哈希表
//    HashItem* p1 = NULL;
//    HashItem* tmp1 = NULL;
//    HASH_ITER(hh, obj->amount, p1, tmp1) {
//        HASH_DEL(obj->amount, p1);
//        free(p1);
//    }
//
//    // 释放 bid 哈希表和对应的堆
//    LazyHeaps* p2 = NULL;
//    LazyHeaps* tmp2 = NULL;
//    HASH_ITER(hh, obj->bid, p2, tmp2) {
//        HASH_DEL(obj->bid, p2);
//        free(p2->heap);
//        free(p2);
//    }
//
//    free(obj);
//}
//
