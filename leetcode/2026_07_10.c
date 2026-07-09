//// 990. 等式方程的可满足性
//
//bool equationsPossible(char** equations, int equationsSize)
//{
//    int alpha[26] = { 0 };
//    for (int i = 0; i < 26; i++)
//    {
//        alpha[i] = i;
//    }
//    int find(int alpha[], int x)
//    {
//        while (alpha[x] != x)
//        {
//            alpha[x] = alpha[alpha[x]];
//            x = alpha[x];
//        }
//        return x;
//    }
//    void unions(int alpha[], int x, int y)
//    {
//        alpha[find(alpha, x)] = find(alpha, y);
//    }
//    for (int i = 0; i < equationsSize; i++)
//    {
//        if (equations[i][1] == '=')
//        {
//            int x = equations[i][0] - 'a';
//            int y = equations[i][3] - 'a';
//            unions(alpha, x, y);
//        }
//    }
//    for (int i = 0; i < equationsSize; i++)
//    {
//        if (equations[i][1] == '!')
//        {
//            int x = equations[i][0] - 'a';
//            int y = equations[i][3] - 'a';
//            if (find(alpha, x) == find(alpha, y))
//                return false;
//        }
//    }
//    return true;
//}
//
