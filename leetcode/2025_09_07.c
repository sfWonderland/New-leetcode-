////1003. 检查替换后的词是否有效
//
//bool isValid(char* s)
//{
//    int top = -1;
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] > 'a')
//        {
//            if (top < 0 || s[i] - s[top--] != 1)
//                return false;
//        }
//        if (s[i] < 'c')
//            s[++top] = s[i];
//    }
//    return top < 0;
//}
//
//bool isValid(char* s)
//{
//    int n = strlen(s);
//    char* st = (char*)malloc(sizeof(char) * n);
//    int top = -1;
//    for (int i = 0; i < n; i++)
//    {
//        if (s[i] == 'c')
//        {
//            if (top < 1 || st[top] != 'b' || st[top - 1] != 'a')
//                return false;
//            else
//                top -= 2;
//        }
//        else
//            st[++top] = s[i];
//    }
//    free(st);
//    return top < 0;
//}
//
////2216. 美化数组的最少删除数
//
//int minDeletion(int* nums, int numsSize)
//{
//    int* st = (int*)malloc(sizeof(int) * numsSize);
//    int top = -1, ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (top & 1 || nums[i] != st[top])
//            st[++top] = nums[i];
//        else
//            ans++;
//    }
//    return ans + ((top + 1) & 1);
//}
//
//int minDeletion(int* nums, int numsSize)
//{
//    int flag = 1, last = nums[0], ans = 0;
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (!flag || nums[i] != last)
//        {
//            last = nums[i];
//            flag ^= 1;
//        }
//        else
//            ans++;
//    }
//    return ans + (numsSize - ans) % 2;
//}
//
////1209. 删除字符串中的所有相邻重复项 II
//
//char* removeDuplicates(char* s, int k)
//{
//    int n = strlen(s);
//    int* count = (int*)malloc(sizeof(int) * n);
//    int top = -1;
//    for (int i = 0; i < n; i++)
//    {
//        if (top < 0 || s[top] != s[i])
//        {
//            s[++top] = s[i];
//            count[top] = 1;
//        }
//        else
//        {
//            s[++top] = s[i];
//            count[top] = count[top - 1] + 1;
//            if (count[top] == k)
//                top -= k;
//        }
//    }
//    s[++top] = '\0';
//    return s;
//}
//
////735. 小行星碰撞
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize)
//{
//    int top = -1;
//    for (int i = 0; i < asteroidsSize; i++)
//    {
//        if (top < 0 || asteroids[top] < 0 || asteroids[i] > 0)
//            asteroids[++top] = asteroids[i];
//        else
//        {
//            while (top >= 0)
//            {
//                int x = asteroids[top];
//                if (x < 0)
//                {
//                    asteroids[++top] = asteroids[i];
//                    break;
//                }
//                else if (x + asteroids[i] > 0)
//                    break;
//                top--;
//                if (x + asteroids[i] == 0)
//                    break;
//            }
//            if (top < 0 && asteroids[0] + asteroids[i])
//                asteroids[++top] = asteroids[i];
//        }
//    }
//    *returnSize = top + 1;
//    return asteroids;
//}
//
