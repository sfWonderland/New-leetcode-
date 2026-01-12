////2349. 设计数字容器系统
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//} HashIdx;
//
//typedef struct
//{
//    int key;
//    int capacity;
//    int* heap;
//    int heapSize;
//    UT_hash_handle hh;
//} HashHeap;
//
//typedef struct
//{
//    HashIdx* index_to_number;
//    HashHeap* number_to_indices;
//} NumberContainers;
//
//void up(int* heap, int i)
//{
//    int x = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j] <= x)
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
//void down(int* heap, int n, int i)
//{
//    int x = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1] < heap[j])
//            j++;
//
//        if (heap[j] >= x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//
//NumberContainers* numberContainersCreate()
//{
//    NumberContainers* obj = (NumberContainers*)malloc(sizeof(NumberContainers));
//    obj->index_to_number = NULL;
//    obj->number_to_indices = NULL;
//    return obj;
//}
//
//void numberContainersChange(NumberContainers* obj, int index, int number)
//{
//    HashIdx* p1 = NULL;
//    HASH_FIND_INT(obj->index_to_number, &index, p1);
//    if (p1 == NULL)
//    {
//        p1 = (HashIdx*)malloc(sizeof(HashIdx));
//        p1->key = index;
//        HASH_ADD_INT(obj->index_to_number, key, p1);
//    }
//    p1->val = number;
//    HashHeap* p2 = NULL;
//    HASH_FIND_INT(obj->number_to_indices, &number, p2);
//    if (p2 == NULL)
//    {
//        p2 = (HashHeap*)malloc(sizeof(HashHeap));
//        p2->key = number;
//        p2->capacity = 64;
//        p2->heap = (int*)malloc(sizeof(int) * p2->capacity);
//        p2->heapSize = 0;
//        HASH_ADD_INT(obj->number_to_indices, key, p2);
//    }
//    p2->heap[p2->heapSize++] = index;
//    up(p2->heap, p2->heapSize - 1);
//    // printf("%d | ", number);
//    // for(int i = 0; i < p2 -> heapSize; i++)
//    // {
//    //     printf("%d ", p2 -> heap[i]);
//    // }
//    // printf("\n");
//    if (p2->heapSize >= p2->capacity)
//    {
//        p2->capacity = 2 * p2->capacity;
//        p2->heap = (int*)realloc(p2->heap, sizeof(int) * p2->capacity);
//    }
//}
//
//int numberContainersFind(NumberContainers* obj, int number)
//{
//    HashHeap* p1 = NULL;
//    HASH_FIND_INT(obj->number_to_indices, &number, p1);
//    if (p1 == NULL)
//        return -1;
//
//    // printf("%d | ", p1 -> key);
//    // for(int i = 0; i < p1 -> heapSize; i++)
//    // {
//    //     printf("%d ", p1 -> heap[i]);
//    // }
//    // printf("\n");
//    HashIdx* p2 = NULL;
//    while (p1->heapSize > 0)
//    {
//        int idx = p1->heap[0];
//        HASH_FIND_INT(obj->index_to_number, &idx, p2);
//        if (p2 == NULL || p2->val != number)
//        {
//            p1->heap[0] = p1->heap[--p1->heapSize];
//            down(p1->heap, p1->heapSize, 0);
//        }
//        else
//            break;
//    }
//    return p1->heapSize > 0 ? p1->heap[0] : -1;
//}
//
//void numberContainersFree(NumberContainers* obj)
//{
//    HashIdx* p1 = NULL;
//    HashIdx* tmp1 = NULL;
//    HASH_ITER(hh, obj -> index_to_number, p1, tmp1)
//    {
//        free(p1);
//    }
//    HashHeap* p2 = NULL;
//    HashHeap* tmp2 = NULL;
//    HASH_ITER(hh, obj -> number_to_indices, p2, tmp2)
//    {
//        free(p2->heap);
//        free(p2);
//    }
//    free(obj);
//}
//
///**
// * Your NumberContainers struct will be instantiated and called as such:
// * NumberContainers* obj = numberContainersCreate();
// * numberContainersChange(obj, index, number);
//
// * int param_2 = numberContainersFind(obj, number);
//
// * numberContainersFree(obj);
//*/
//
////3607. 电网维护    
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//void up(int* heap, int i)
//{
//    int x = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j] <= x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//
//        if (j == 0)
//            break;
//    }
//    heap[i] = x;
//}
//
//void down(int* heap, int n, int i)
//{
//    int x = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1] < heap[j])
//            j++;
//
//        if (heap[j] >= x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//
//int* processQueries(int c, int** connections, int connectionsSize, int* connectionsColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
//{
//    bool* situation = (bool*)calloc(sizeof(bool), (c + 1));
//
//    struct ListNode** grid = (struct ListNode**)calloc(sizeof(struct ListNode*), c + 1);
//    for (int i = 0; i < connectionsSize; i++)
//    {
//        int x = connections[i][0], y = connections[i][1];
//        struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//        node1->val = y;
//        node1->next = grid[x];
//        grid[x] = node1;
//
//        struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//        node2->val = x;
//        node2->next = grid[y];
//        grid[y] = node2;
//    }
//    int* belong = (int*)malloc(sizeof(int) * (c + 1));
//    memset(belong, -1, sizeof(int) * (c + 1));
//    int** heaps = (int**)malloc(sizeof(int*) * (c + 1));
//    int heapsSize = 0;
//    int* len = (int*)malloc(sizeof(int) * (c + 1));
//    int* pq = (int*)malloc(sizeof(int) * c);
//    int pqSize = 0;
//    void dfs(int x)
//    {
//        belong[x] = heapsSize;
//        pq[pqSize++] = x;
//        up(pq, pqSize - 1);
//
//        struct ListNode* node = grid[x];
//        while (node)
//        {
//            if (belong[node->val] < 0)
//            {
//                dfs(node->val);
//            }
//            node = node->next;
//        }
//    }
//    for (int i = 1; i <= c; i++)
//    {
//        if (belong[i] < 0)
//        {
//            dfs(i);
//            heaps[heapsSize] = (int*)malloc(sizeof(int) * pqSize);
//            memcpy(heaps[heapsSize], pq, sizeof(int) * pqSize);
//            len[heapsSize++] = pqSize;
//            pqSize = 0;
//        }
//    }
//    //printf("%d\n", heapsSize);
//    int* ans = (int*)malloc(sizeof(int) * queriesSize);
//    *returnSize = 0;
//    for (int i = 0; i < queriesSize; i++)
//    {
//        int inst = queries[i][0], x = queries[i][1];
//        if (inst == 2)
//        {
//            situation[x] = 1;
//            continue;
//        }
//
//        if (x > c || !situation[x])
//            ans[(*returnSize)++] = x;
//        else
//        {
//            //printf("%d ", belong[x]);
//            int* heap = heaps[belong[x]];
//            int x1 = -1;
//            while (len[belong[x]] > 0)
//            {
//                int x2 = heap[0];
//                if (!situation[x2])
//                {
//                    x1 = x2;
//                    break;
//                }
//                heap[0] = heap[--len[belong[x]]];
//                down(heap, len[belong[x]], 0);
//            }
//
//            ans[(*returnSize)++] = x1;
//        }
//    }
//    return ans;
//}
//
////2295. 替换数组中的元素
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int* arrayChange(int* nums, int numsSize, int** operations, int operationsSize, int* operationsColSize, int* returnSize)
//{
//    HashItem* hash = NULL;
//    HashItem* p1 = NULL;
//    for (int i = 0; i < numsSize; i++)
//    {
//        p1 = (HashItem*)malloc(sizeof(HashItem));
//        p1->key = nums[i];
//        p1->val = i;
//        HASH_ADD_INT(hash, key, p1);
//    }
//    for (int i = 0; i < operationsSize; i++)
//    {
//        HASH_FIND_INT(hash, &operations[i][0], p1);
//        int idx = p1->val;
//        nums[idx] = operations[i][1];
//        HASH_DEL(hash, p1);
//        free(p1);
//        p1 = (HashItem*)malloc(sizeof(HashItem));
//        p1->key = operations[i][1];
//        p1->val = idx;
//        HASH_ADD_INT(hash, key, p1);
//    }
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, hash, p1, tmp)
//    {
//        free(p1);
//    }
//    *returnSize = numsSize;
//    return nums;
//}
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* arrayChange(int* nums, int numsSize, int** operations, int operationsSize, int* operationsColSize, int* returnSize)
//{
//    int pos[1000001];
//    for (int i = 0; i < numsSize; i++)
//    {
//        pos[nums[i]] = i;
//    }
//    for (int i = 0; i < operationsSize; i++)
//    {
//        int old = operations[i][0], new = operations[i][1];
//        int idx = pos[old];
//        nums[idx] = new;
//        pos[new] = idx;
//    }
//    *returnSize = numsSize;
//    return nums;
//}
//
////1333. 餐厅过滤器
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e1)[1] == (*(int**)e2)[1] ? (*(int**)e2)[0] - (*(int**)e1)[0] : (*(int**)e2)[1] - (*(int**)e1)[1];
//}
//int* filterRestaurants(int** restaurants, int restaurantsSize, int* restaurantsColSize, int veganFriendly, int maxPrice, int maxDistance, int* returnSize)
//{
//    int n = restaurantsSize;
//    int i = 0;
//    while (i < n)
//    {
//        if ((veganFriendly && !restaurants[i][2])
//            || restaurants[i][3] > maxPrice
//            || restaurants[i][4] > maxDistance)
//        {
//            int* tmp = restaurants[i];
//            restaurants[i] = restaurants[n - 1];
//            restaurants[--n] = tmp;
//        }
//        else
//            i++;
//    }
//    *returnSize = n;
//    if (n == 0)
//        return NULL;
//
//    qsort(restaurants, n, sizeof(int*), cmp);
//    int* ans = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        ans[i] = restaurants[i][0];
//    }
//    return ans;
//}
//
