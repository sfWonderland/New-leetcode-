//// 1345. Ã¯‘æ”Œœ∑ IV
//
//typedef struct
//{
//    int key;
//    int capacity;
//    int* pos;
//    int m;
//    UT_hash_handle hh;
//}HashItem;
//int minJumps(int* arr, int arrSize)
//{
//    int n = arrSize;
//    if (arr[0] == arr[n - 1])
//        return n != 1;
//    HashItem* index = NULL;
//    for (int i = 0; i < n; i++)
//    {
//        HashItem* p1 = NULL;
//        HASH_FIND_INT(index, &arr[i], p1);
//        if (p1 == NULL)
//        {
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = arr[i];
//            p1->capacity = 8;
//            p1->pos = (int*)malloc(sizeof(int) * p1->capacity);
//            p1->m = 0;
//            HASH_ADD_INT(index, key, p1);
//        }
//        p1->pos[p1->m++] = i;
//        if (p1->m >= p1->capacity)
//        {
//            p1->capacity *= 2;
//            p1->pos = (int*)realloc(p1->pos, sizeof(int) * p1->capacity);
//        }
//    }
//    bool vis[arrSize];
//    memset(vis, 0, sizeof(vis));
//    int queue[n];
//    int rear = 0, front = 0, step = 0;
//    queue[rear++] = 0;
//    vis[0] = true;
//    bool flag = false;
//    while (rear > front && !flag)
//    {
//        int start = front;
//        front = rear;
//        for (int i = start; i < front && !flag; i++)
//        {
//            int j = queue[i];
//            if (j == n - 1)
//            {
//                flag = true;
//                step--;
//                break;
//            }
//            if (!vis[j + 1])
//            {
//                vis[j + 1] = true;
//                queue[rear++] = j + 1;
//            }
//            if (j > 0 && !vis[j - 1])
//            {
//                vis[j - 1] = true;
//                queue[rear++] = j - 1;
//            }
//            int x = arr[j];
//            HashItem* p2 = NULL;
//            HASH_FIND_INT(index, &x, p2);
//            if (p2 == NULL)
//                continue;
//            for (int k = 0; k < p2->m; k++)
//            {
//                int y = p2->pos[k];
//                if (!vis[y])
//                {
//                    vis[y] = true;
//                    queue[rear++] = y;
//                }
//            }
//            free(p2->pos);
//            HASH_DEL(index, p2);
//            free(p2);
//        }
//        step++;
//    }
//
//    return step;
//}
//
