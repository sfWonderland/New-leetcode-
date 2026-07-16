//// 2059. 转化数字的最小运算数
//
//int minimumOperations(int* nums, int numsSize, int start, int goal)
//{
//    bool vis[1001] = { 0 };
//    int capacity = 8;
//    int* queue = (int*)malloc(sizeof(int) * capacity);
//    int rear = 0, front = 0;
//    queue[rear++] = start;
//    vis[start] = true;
//    int step = 0;
//    bool inQueue(int x)
//    {
//        if (x == goal)
//            return true;
//
//        if (x >= 0 && x <= 1000 && !vis[x])
//        {
//            vis[x] = true;
//            queue[rear++] = x;
//            if (rear >= capacity)
//            {
//                capacity *= 2;
//                queue = (int*)realloc(queue, sizeof(int) * capacity);
//            }
//        }
//        return false;
//    }
//    while (rear > front)
//    {
//        step++;
//        int start = front;
//        front = rear;
//        for (int i = start; i < front; i++)
//        {
//            int x = queue[i];
//            for (int j = 0; j < numsSize; j++)
//            {
//                if (inQueue(x + nums[j]) || inQueue(x - nums[j]) || inQueue(x ^ nums[j]))
//                    return step;
//            }
//        }
//    }
//    return -1;
//}
//
