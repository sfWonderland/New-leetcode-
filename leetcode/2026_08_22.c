//// 133. ¿ËÂ¡Í¼
//
///**
// * Definition for a Node.
// * struct Node {
// *     int val;
// *     int numNeighbors;
// *     struct Node** neighbors;
// * };
// */
//int cmp(const void* e1, const void* e2)
//{
//    return (*(struct Node**)e1)->val - (*(struct Node**)e2)->val;
//}
//struct Node* cloneGraph(struct Node* s)
//{
//    if (s == NULL) return NULL;
//    struct Node* queue[100];
//    int rear = 0, front = 0;
//    queue[rear++] = s;
//    bool vis[101] = { 0 };
//    vis[1] = true;
//    while (rear > front)
//    {
//        struct Node* t = queue[front++];
//        for (int i = 0; i < t->numNeighbors; i++)
//        {
//            struct Node* neigh = t->neighbors[i];
//            if (vis[neigh->val]) continue;
//            vis[neigh->val] = true;
//            queue[rear++] = neigh;
//        }
//    }
//    qsort(queue, rear, sizeof(struct Node*), cmp);
//    struct Node** new_s = (struct Node**)malloc(sizeof(struct Node*) * rear);
//    for (int i = 0; i < rear; i++)
//    {
//        new_s[i] = (struct Node*)malloc(sizeof(struct Node));
//        new_s[i]->val = queue[i]->val;
//        new_s[i]->numNeighbors = queue[i]->numNeighbors;
//        new_s[i]->neighbors = (struct Node**)malloc(sizeof(struct Node*) * queue[i]->numNeighbors);
//    }
//    for (int i = 0; i < rear; i++)
//    {
//        for (int j = 0; j < new_s[i]->numNeighbors; j++)
//        {
//            int x = queue[i]->neighbors[j]->val - 1;
//            new_s[i]->neighbors[j] = new_s[x];
//        }
//    }
//    return new_s[s->val - 1];
//}
//
///**
// * Definition for a Node.
// * struct Node {
// *     int val;
// *     int numNeighbors;
// *     struct Node** neighbors;
// * };
// */
//void create(struct Node* s, struct Node* t)
//{
//    s->val = t->val;
//    s->numNeighbors = 0;
//    s->neighbors = (struct Node**)malloc(sizeof(struct Node*) * t->numNeighbors);
//}
//struct Node* cloneGraph(struct Node* s)
//{
//    if (s == NULL) return NULL;
//    struct Node* queue[101];
//    int rear = 0, front = 0;
//    queue[rear++] = s;
//    bool vis[100] = { 1 };
//    struct Node** new_s = (struct Node**)malloc(sizeof(struct Node*) * 100);
//    new_s[0] = (struct Node*)malloc(sizeof(struct Node));
//    create(new_s[0], queue[0]);
//    while (rear > front)
//    {
//        struct Node* t = queue[front++];
//        int x = t->val - 1;
//        for (int i = 0; i < t->numNeighbors; i++)
//        {
//            struct Node* neigh = t->neighbors[i];
//            int y = neigh->val - 1;
//            if (!vis[y])
//            {
//                new_s[y] = (struct Node*)malloc(sizeof(struct Node));
//                create(new_s[y], neigh);
//                vis[y] = true;
//                queue[rear++] = neigh;
//            }
//            new_s[x]->neighbors[(new_s[x]->numNeighbors)++] = new_s[y];
//        }
//    }
//    return new_s[s->val - 1];
//}
//
