//#define _CRT_SECURE_NO_WARNINGS
//
////892.三维形体的表面积
//
//int surfaceArea(int** grid, int gridSize, int* gridColSize)
//{
//    int surface[gridSize + 2][*gridColSize + 2];
//    for (int i = 0; i < gridSize + 2; i++)
//    {
//        for (int j = 0; j < *gridColSize + 2; j++)
//        {
//            if (0 == i || 0 == j || gridSize + 1 == i || *gridColSize + 1 == j)
//                surface[i][j] = 0;
//            else
//                surface[i][j] = grid[i - 1][j - 1];
//        }
//    }
//
//    int sum = 0;
//    for (int x = 1; x < gridSize + 1; x++)
//    {
//        for (int y = 1; y < *gridColSize + 1; y++)
//        {
//            if (surface[x][y] != 0)
//            {
//                //top
//                sum += 2;
//                //side
//                if (surface[x][y] > surface[x + 1][y])
//                    sum += surface[x][y] - surface[x + 1][y];
//                if (surface[x][y] > surface[x - 1][y])
//                    sum += surface[x][y] - surface[x - 1][y];
//                //front
//                if (surface[x][y] > surface[x][y + 1])
//                    sum += surface[x][y] - surface[x][y + 1];
//                if (surface[x][y] > surface[x][y - 1])
//                    sum += surface[x][y] - surface[x][y - 1];
//            }
//        }
//    }
//
//    return sum;
//}
//
////896.单调数列
//
//bool isMonotonic(int* nums, int numsSize)
//{
//    int d = nums[numsSize - 1] - nums[0];
//    if (d < 0)
//        d = -1;
//    else if (d > 0)
//        d = 1;
//    if (d)
//    {
//        for (int i = 1; i < numsSize; i++)
//        {
//            if ((nums[i] - nums[i - 1]) * d < 0)
//                return false;
//        }
//    }
//    else
//    {
//        for (int i = 1; i < numsSize; i++)
//        {
//            if (nums[i] != nums[0])
//                return false;
//        }
//    }
//
//    return true;
//}
//
////2210.统计数组中峰和谷的数量
//
//int countHillValley(int* nums, int numsSize)
//{
//    int sum = 0;
//    for (int i = 1; i < numsSize - 1; i++)
//    {
//        int left = i - 1;
//        int right = i + 1;
//
//        while (left >= 0 && nums[i] == nums[left])
//            left--;
//        if (left == -1)
//            continue;
//
//        while (right <= numsSize - 1 && nums[i] == nums[right])
//            right++;
//        if (right == numsSize)
//            continue;
//
//        //printf("left = %d, right = %d\n", left, right);
//        if ((nums[i] - nums[left]) < 0 && (nums[right] - nums[i]) > 0)
//            sum++;
//        else if ((nums[i] - nums[left]) > 0 && (nums[right] - nums[i]) < 0)
//            sum++;
//        if (i < right - 1)
//            i = right - 1;
//    }
//
//    return sum;
//}
//
////914.卡牌分组
//
//int gcd(int a, int b)
//{
//    while (a % b)
//    {
//        int tmp = a;
//        a = b;
//        b = tmp % b;
//    }
//    printf("b = %d\n", b);
//    return b;
//}
//bool hasGroupsSizeX(int* deck, int deckSize)
//{
//    int cnt[10000] = { 0 };
//    for (int i = 0; i < deckSize; i++)
//    {
//        cnt[deck[i]]++;
//    }
//
//    int g = -1;
//    for (int i = 0; i < 10000; i++)
//    {
//        if (cnt[i])
//        {
//            if (~g)
//                g = gcd(g, cnt[i]);
//            else
//                g = cnt[i];
//
//        }
//    }
//
//    return g >= 2;
//}
//
////1486.数组异或操作
//
//int xorOperation(int n, int start)
//{
//    int ret = 0;
//    for (int i = start; i < start + n * 2; i += 2)
//    {
//        ret ^= i;
//    }
//
//    return ret;
//}
//
////925.长按输入
//
//bool isLongPressedName(char* name, char* typed)
//{
//    int len1 = strlen(name);
//    int len2 = strlen(typed);
//    int left1 = 0;
//    int right1 = len1 - 1;
//    int left2 = 0;
//    int right2 = len2 - 1;
//
//    if (name[left1] != typed[left2] || name[right1] != typed[right2])
//        return false;
//    else
//    {
//        left1++; left2++; right1--; right2--;
//    }
//    while (left1 < len1 && right1 > 0 && left2 <= right2)
//    {
//        if (name[left1] == typed[left2])
//            left1++;
//        else if (typed[left2] != name[left1 - 1])
//            return false;
//        left2++;
//        if (name[right1] == typed[right2])
//            right1--;
//        else if (typed[right2] != name[right1 + 1])
//            return false;
//        right2--;
//        //printf("%c %c\n", name[left1], name[right1]);
//        //printf("%c %c\n", typed[left2], typed[right2]);
//    }
//    return left1 > right1;
//}