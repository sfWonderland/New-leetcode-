////LCP 30. 魔塔游戏
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
//int magicTower(int* nums, int numsSize)
//{
//    long long sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//    }
//    if (sum < 0)
//        return -1;
//
//    int ans = 0;
//    long long hp = 1;
//    int* heap = (int*)malloc(sizeof(int) * numsSize);
//    int j = 0; // heapSize
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] < 0)
//        {
//            heap[j] = nums[i];
//            up(heap, j);
//            j++;
//        }
//
//        hp += nums[i];
//        if (hp < 1)
//        {
//            hp -= heap[0];
//            ans++;
//            heap[0] = heap[--j];
//            if (j > 0)
//                down(heap, j, 0);
//        }
//    }
//    return ans;
//}
//
////3557. 不相交子字符串的最大数量
//
//int maxSubstrings(char* word)
//{
//    int n = strlen(word);
//    int pos[26];
//    for (int i = 0; i < 26; i++)
//    {
//        pos[i] = -1;
//    }
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int t = word[i] - 'a';
//        if (pos[t] < 0)
//            pos[t] = i;
//        else if (i - pos[t] > 2)
//        {
//            ans++;
//            for (int j = 0; j < 26; j++)
//            {
//                pos[j] = -1;
//            }
//        }
//    }
//    return ans;
//}
//
//int maxSubstrings(char* word)
//{
//    int n = strlen(word);
//    int seen = 0, ans = 0;
//    for (int i = 3; i < n; i++)
//    {
//        seen |= 1 << (word[i - 3] - 'a');
//        if (seen >> (word[i] - 'a') & 1)
//        {
//            ans++;
//            seen = 0;
//            i += 3;
//        }
//    }
//    return ans;
//}
//
////1642. 可以到达的最远建筑
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
//int furthestBuilding(int* heights, int heightsSize, int bricks, int ladders)
//{
//    int ans = 0, sum = 0; // totalBricksSum
//    int* heap = (int*)malloc(sizeof(int) * (ladders + 1));
//    int j = 0; // heapSize;
//    for (int i = 1; i < heightsSize; i++, ans++)
//    {
//        int x = heights[i] - heights[i - 1];
//        if (x <= 0)
//            continue;
//
//        heap[j] = x;
//        up(heap, j);
//        j++;
//
//        if (j > ladders)
//        {
//            sum += heap[0];
//            if (sum > bricks)
//                break;
//
//            heap[0] = heap[j - 1];
//            down(heap, j, 0);
//            j--;
//        }
//    }
//    return ans;
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
//int furthestBuilding(int* heights, int heightsSize, int bricks, int ladders)
//{
//    int sum = 0; // totalBricksSum
//    int* heap = (int*)malloc(sizeof(int) * ladders);
//    int j = 0; // heapSize;
//    for (int i = 1; i < heightsSize; i++)
//    {
//        int x = heights[i] - heights[i - 1];
//        if (x <= 0)
//            continue;
//
//        if (j < ladders)
//        {
//            heap[j] = x;
//            up(heap, j);
//            j++;
//        }
//        else
//        {
//            if (ladders && x > heap[0])
//            {
//                int tmp = heap[0];
//                heap[0] = x;
//                down(heap, j, 0);
//                x = tmp;
//            }
//            sum += x;
//            if (sum > bricks)
//                return i - 1;
//        }
//    }
//    return heightsSize - 1;
//}
//
////630. 课程表 III
//
//void down(int* heap, int n, int i)
//{
//    int x = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1] > heap[j])
//            j++;
//
//        if (heap[j] <= x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//void up(int* heap, int i)
//{
//    int x = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j] >= x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//        if (j == 0)
//            break;
//    }
//    heap[i] = x;
//}
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e1)[1] - (*(int**)e2)[1];
//}
//int scheduleCourse(int** courses, int coursesSize, int* coursesColSize)
//{
//    qsort(courses, coursesSize, sizeof(int*), cmp);
//    int* heap = (int*)malloc(sizeof(int) * coursesSize);
//    int j = 0, day_cost = 0;
//    for (int i = 0; i < coursesSize; i++)
//    {
//        int duration = courses[i][0], last_day = courses[i][1];
//        if (day_cost + duration <= last_day)
//        {
//            heap[j++] = duration;
//            up(heap, j - 1);
//            day_cost += duration;
//        }
//        else if (j > 0 && duration < heap[0])
//        {
//            day_cost -= heap[0] - duration;
//            heap[0] = duration;
//            down(heap, j, 0);
//        }
//    }
//    return j;
//}
//
