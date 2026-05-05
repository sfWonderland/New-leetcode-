//// 面试题 03.04. 化栈为队
//
//typedef struct
//{
//    int* input;
//    int top1;
//    int* output;
//    int top2;
//} MyQueue;
//
///** Initialize your data structure here. */
//
//MyQueue* myQueueCreate()
//{
//    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
//    obj->input = (int*)malloc(sizeof(int) * 100);
//    obj->top1 = 0;
//    obj->output = (int*)malloc(sizeof(int) * 100);
//    obj->top2 = 0;
//    return obj;
//}
//
///** Push element x to the back of queue. */
//void myQueuePush(MyQueue* obj, int x)
//{
//    obj->input[obj->top1++] = x;
//}
//
///** Removes the element from in front of queue and returns that element. */
//int myQueuePop(MyQueue* obj)
//{
//    if (obj->top2 == 0)
//    {
//        while (obj->top1)
//        {
//            obj->output[obj->top2++] = obj->input[--obj->top1];
//        }
//    }
//    return obj->output[--obj->top2];
//}
//
///** Get the front element. */
//int myQueuePeek(MyQueue* obj)
//{
//    if (obj->top2 == 0)
//    {
//        while (obj->top1)
//        {
//            obj->output[obj->top2++] = obj->input[--obj->top1];
//        }
//    }
//    return obj->output[obj->top2 - 1];
//}
//
///** Returns whether the queue is empty. */
//bool myQueueEmpty(MyQueue* obj)
//{
//    return !obj->top1 && !obj->top2;
//}
//
//void myQueueFree(MyQueue* obj)
//{
//    free(obj->input);
//    free(obj->output);
//}
//
///**
// * Your MyQueue struct will be instantiated and called as such:
// * MyQueue* obj = myQueueCreate();
// * myQueuePush(obj, x);
//
// * int param_2 = myQueuePop(obj);
//
// * int param_3 = myQueuePeek(obj);
//
// * bool param_4 = myQueueEmpty(obj);
//
// * myQueueFree(obj);
//*/
//
//// 面试题 03.06. 动物收容所
//
//typedef struct
//{
//    int* queue[3];
//    int bottom[3];
//    int top[3];
//} AnimalShelf;
//
//
//AnimalShelf* animalShelfCreate()
//{
//    AnimalShelf* obj = (AnimalShelf*)malloc(sizeof(AnimalShelf));
//    obj->queue[0] = (int*)malloc(sizeof(int) * 20000);
//    obj->queue[1] = (int*)malloc(sizeof(int) * 20000);
//    obj->bottom[0] = obj->bottom[1] = 0;
//    obj->top[0] = obj->top[1] = 0;
//    return obj;
//}
//
//void animalShelfEnqueue(AnimalShelf* obj, int* animal, int animalSize)
//{
//    int id = animal[0], type = animal[1];
//    obj->queue[type][obj->top[type]++] = id;
//
//}
//
//int* animalShelfDequeueAny(AnimalShelf* obj, int* retSize)
//{
//    int* ret = (int*)malloc(sizeof(int) * 2);
//    ret[0] = -1, ret[1] = -1;
//    *retSize = 2;
//    int head_cat = INT_MAX, head_dog = INT_MAX;
//    if (obj->top[0] > obj->bottom[0])
//        head_cat = obj->queue[0][obj->bottom[0]];
//    if (obj->top[1] > obj->bottom[1])
//        head_dog = obj->queue[1][obj->bottom[1]];
//
//    if (head_cat <= head_dog)
//    {
//        if (head_cat == INT_MAX)
//            return ret;
//        ret[0] = head_cat;
//        ret[1] = 0;
//        obj->bottom[0]++;
//    }
//    else
//    {
//        ret[0] = head_dog;
//        ret[1] = 1;
//        obj->bottom[1]++;
//    }
//    return ret;
//}
//
//int* animalShelfDequeueDog(AnimalShelf* obj, int* retSize)
//{
//    int* ret = (int*)malloc(sizeof(int) * 2);
//    ret[0] = -1, ret[1] = -1;
//    if (obj->top[1] > obj->bottom[1])
//    {
//        ret[0] = obj->queue[1][obj->bottom[1]++];
//        ret[1] = 1;
//    }
//
//    *retSize = 2;
//    return ret;
//}
//
//int* animalShelfDequeueCat(AnimalShelf* obj, int* retSize)
//{
//    int* ret = (int*)malloc(sizeof(int) * 2);
//    ret[0] = -1, ret[1] = -1;
//    if (obj->top[0] > obj->bottom[0])
//    {
//        ret[0] = obj->queue[0][obj->bottom[0]++];
//        ret[1] = 0;
//    }
//
//    *retSize = 2;
//    return ret;
//}
//
//void animalShelfFree(AnimalShelf* obj)
//{
//    free(obj->queue[0]);
//    free(obj->queue[1]);
//}
//
///**
// * Your AnimalShelf struct will be instantiated and called as such:
// * AnimalShelf* obj = animalShelfCreate();
// * animalShelfEnqueue(obj, animal, animalSize);
//
// * int* param_2 = animalShelfDequeueAny(obj, retSize);
//
// * int* param_3 = animalShelfDequeueDog(obj, retSize);
//
// * int* param_4 = animalShelfDequeueCat(obj, retSize);
//
// * animalShelfFree(obj);
//*/
//
//// 面试题 04.01. 节点间通路
//
//bool findWhetherExistsPath(int n, int** graph, int graphSize, int* graphColSize, int start, int target)
//{
//    bool vis[graphSize];
//    memset(vis, 0, sizeof(vis));
//    bool helper(int left, int right)
//    {
//        for (int i = 0; i < graphSize; i++)
//        {
//            if (vis[i])
//                continue;
//
//            int src = graph[i][0], dest = graph[i][1];
//            if (src == left && dest == right)
//                return true;
//
//            vis[i] = true;
//            if (dest == right && helper(left, src))
//                return true;
//            vis[i] = false;
//        }
//        return false;
//    }
//    return helper(start, target);
//}
//
//// 面试题 04.04. 检查平衡性
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* node)
//{
//    if (node == NULL)
//        return 0;
//
//    return fmax(dfs(node->left), dfs(node->right)) + 1;
//}
//bool isBalanced(struct TreeNode* root)
//{
//    if (root == NULL)
//        return true;
//
//    return isBalanced(root->left) && isBalanced(root->right) && abs(dfs(root->left) - dfs(root->right)) <= 1;
//}
//
