////101026. 双端字符匹配
//
//int firstMatchingIndex(char* s)
//{
//    int n = strlen(s);
//    int m = n / 2;
//    for (int i = 0; i <= m; i++)
//    {
//        if (s[i] == s[n - 1 - i])
//            return i;
//    }
//    return -1;
//}
//
////101029. 设计事件管理器   
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//typedef struct
//{
//    int** events;
//    int n;
//    HashItem* eventsID;
//} EventManager;
//
//void up(int** heap, int i, HashItem** eventsID)
//{
//    HashItem* ev = *eventsID;
//    HashItem* p = NULL;
//    int event = heap[i][0], priority = heap[i][1];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j][1] > priority ||
//            (heap[j][1] == priority && heap[j][0] < event))
//            break;
//        heap[i][0] = heap[j][0];
//        heap[i][1] = heap[j][1];
//        HASH_FIND_INT(ev, &heap[i][0], p);
//        p->val = i;
//        i = j;
//        if (j == 0)
//            break;
//    }
//    heap[i][0] = event;
//    heap[i][1] = priority;
//    // for(int j = 0; j <= i; j++)
//    // {
//    //     printf("%d %d\n", heap[j][0], heap[j][1]);
//    // }
//    // printf("\n");
//    HASH_FIND_INT(ev, &heap[i][0], p);
//    p->val = i;
//}
//void down(int** heap, int i, int n, HashItem** eventsID)
//{
//
//    HashItem* ev = *eventsID;
//    HashItem* p = NULL;
//    int event = heap[i][0], priority = heap[i][1];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1
//            && (heap[j][1] < heap[j + 1][1]
//                || (heap[j][1] == heap[j + 1][1] && heap[j + 1][0] < heap[j][0])
//                )
//            )
//            j++;
//        if (heap[j][1] < priority ||
//            (heap[j][1] == priority && heap[j][0] > event))
//            break;
//        heap[i][0] = heap[j][0];
//        heap[i][1] = heap[j][1];
//        HASH_FIND_INT(ev, &heap[i][0], p);
//        p->val = i;
//        i = j;
//    }
//    heap[i][0] = event;
//    heap[i][1] = priority;
//    //printf("||\n");
//    // for(int j = 0; j < n; j++)
//    // {
//    //     printf("%d %d\n", heap[j][0], heap[j][1]);
//    // }
//    //printf("||\n");
//    HASH_FIND_INT(ev, &heap[i][0], p);
//    //printf("!!%d\n", event);
//    p->val = i;
//}
//
//EventManager* eventManagerCreate(int** events, int eventsSize, int* eventsColSize)
//{
//    EventManager* obj = (EventManager*)malloc(sizeof(EventManager));
//    obj->events = (int**)malloc(sizeof(int*) * eventsSize);
//    obj->eventsID = NULL;
//    HashItem* p = NULL;
//    for (int i = 0; i < eventsSize; i++)
//    {
//        p = (HashItem*)malloc(sizeof(HashItem));
//        p->key = events[i][0];
//        p->val = i;
//        HASH_ADD_INT(obj->eventsID, key, p);
//    }
//    for (int i = 0; i < eventsSize; i++)
//    {
//        obj->events[i] = (int*)malloc(sizeof(int) * 2);
//        obj->events[i][0] = events[i][0];
//        obj->events[i][1] = events[i][1];
//        up(obj->events, i, &obj->eventsID);
//    }
//    obj->n = eventsSize;
//    return obj;
//}
//
//void eventManagerUpdatePriority(EventManager* obj, int eventId, int newPriority)
//{
//    HashItem* p = NULL;
//    HASH_FIND_INT(obj->eventsID, &eventId, p);
//    int k = p->val;
//    int priority = obj->events[k][1];
//    obj->events[k][1] = newPriority;
//    if (newPriority > priority)
//        up(obj->events, k, &obj->eventsID);
//    else if (newPriority < priority)
//        down(obj->events, k, obj->n, &obj->eventsID);
//}
//
//int eventManagerPollHighest(EventManager* obj)
//{
//    int m = obj->n;
//    if (m == 0)
//        return -1;
//    int res = obj->events[0][0];
//    //printf("res = %d\n", res);
//    HashItem* p = NULL;
//    HASH_FIND_INT(obj->eventsID, &res, p);
//    HASH_DEL(obj->eventsID, p);
//    free(p);
//    obj->events[0][0] = obj->events[--m][0];
//    obj->events[0][1] = obj->events[m][1];
//    if (m)
//        down(obj->events, 0, m, &obj->eventsID);
//    obj->n = m;
//    return res;
//}
//
//void eventManagerFree(EventManager* obj)
//{
//    HashItem* p = NULL, * tmp = NULL;
//    HASH_ITER(hh, obj -> eventsID, p, tmp)
//    {
//        HASH_DEL(obj->eventsID, p);
//        free(p);
//    }
//    for (int i = 0; i < obj->n; i++)
//    {
//        free(obj->events[i]);
//    }
//    free(obj->events);
//}
//
///**
// * Your EventManager struct will be instantiated and called as such:
// * EventManager* obj = eventManagerCreate(events, eventsSize, eventsColSize);
// * eventManagerUpdatePriority(obj, eventId, newPriority);
//
// * int param_2 = eventManagerPollHighest(obj);
//
// * eventManagerFree(obj);
//*/
//
////3222. 求出硬币游戏的赢家
//
//char* winningPlayer(int x, int y)
//{
//    int turn = fmin(x, y / 4);
//    return turn & 1 ? "Alice" : "Bob";
//}
//
////3238. 求出胜利玩家的数目
//
//int winningPlayerCount(int n, int** pick, int pickSize, int* pickColSize)
//{
//    int cnt[n][12];
//    memset(cnt, 0, sizeof(cnt));
//    int ans = 0;
//    for (int i = 0; i < pickSize; i++)
//    {
//        int x = pick[i][0], y = pick[i][1];
//        if (cnt[x][11])
//            continue;
//        cnt[x][y]++;
//        if (cnt[x][y] > x)
//        {
//            cnt[x][11] = 1;
//            ans++;
//        }
//    }
//    return ans;
//}
//
