//// 面试题 10.11. 峰与谷
//
//void swap(int* nums, int i, int j)
//{
//    nums[i] ^= nums[j];
//    nums[j] ^= nums[i];
//    nums[i] ^= nums[j];
//}
//void wiggleSort(int* nums, int numsSize)
//{
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (i & 1)
//        {
//            if (nums[i] < nums[i - 1])
//                swap(nums, i, i - 1);
//        }
//        else
//        {
//            if (nums[i] > nums[i - 1])
//                swap(nums, i, i - 1);
//        }
//    }
//}
//
//// 面试题 16.04. 井字游戏  
//
//char* tictactoe(char** board, int boardSize)
//{
//    bool blank = 0;
//    int n = boardSize;
//    for (int i = 0; i < n; i++)
//    {
//        bool b = false;
//        int x = 0, o = 0;
//        for (int j = 0; j < n && !b; j++)
//        {
//            if (board[i][j] == 'X')
//                x++;
//            else if (board[i][j] == 'O')
//                o++;
//            else
//                b = true;
//        }
//        if (!b)
//        {
//            if (x == n)
//                return "X";
//            else if (o == n)
//                return "O";
//        }
//    }
//    for (int i = 0; i < n; i++)
//    {
//        bool b = false;
//        int x = 0, o = 0;
//        for (int j = 0; j < n && !b; j++)
//        {
//            if (board[j][i] == 'X')
//                x++;
//            else if (board[j][i] == 'O')
//                o++;
//            else
//                b = true;
//        }
//        if (!b)
//        {
//            if (x == n)
//                return "X";
//            else if (o == n)
//                return "O";
//        }
//        else
//            blank = true;
//    }
//    bool b = false;
//    int x = 0, o = 0;
//    for (int i = 0; i < n && !b; i++)
//    {
//        if (board[i][n - 1 - i] == 'X')
//            x++;
//        else if (board[i][n - 1 - i] == 'O')
//            o++;
//        else
//            b = true;
//
//        if (!b)
//        {
//            if (x == n)
//                return "X";
//            else if (o == n)
//                return "O";
//        }
//        else
//            blank = true;
//    }
//    b = false;
//    x = 0; o = 0;
//    for (int i = 0; i < n && !b; i++)
//    {
//        if (board[i][i] == 'X')
//            x++;
//        else if (board[i][i] == 'O')
//            o++;
//        else
//            b = true;
//
//        if (!b)
//        {
//            if (x == n)
//                return "X";
//            else if (o == n)
//                return "O";
//        }
//        else
//            blank = true;
//    }
//
//    return blank ? "Pending" : "Draw";
//}
//
//// 面试题 16.05. 阶乘尾数
//
//int trailingZeroes(int n)
//{
//    int ans = 0;
//    while (n >= 5)
//    {
//        ans += n / 5;
//        n /= 5;
//    }
//    return ans;
//}
//
//// 面试题 16.07. 最大数值
//
//int maximum(int a, int b)
//{
//    long long x = 1ll * a - b;
//    int k = (int)(x >> 63);
//    return (k + 1) * a - k * b;
//}
//
