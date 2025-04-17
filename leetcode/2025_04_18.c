////150. 逆波兰表达式求值
//
//int evalRPN(char** tokens, int tokensSize)
//{
//    int stk[tokensSize];
//    memset(stk, 0, sizeof(int) * tokensSize);
//    int top = -1;
//    for (int i = 0; i < tokensSize; i++)
//    {
//        if (isdigit(tokens[i][0]))
//        {
//            stk[++top] = 0;
//            for (int j = 0; tokens[i][j]; j++)
//            {
//                stk[top] *= 10;
//                stk[top] += tokens[i][j] - '0';
//            }
//            //printf("%d\n", stk[top]);
//        }
//        else if (isdigit(tokens[i][1]))
//        {
//            stk[++top] = 0;
//            for (int j = 1; tokens[i][j]; j++)
//            {
//                stk[top] *= 10;
//                stk[top] += tokens[i][j] - '0';
//            }
//            stk[top] = -stk[top];
//            //printf("%d\n", stk[top]);
//        }
//        else
//        {
//            //printf("%d %d\n", stk[top], stk[top - 1]);
//            switch (tokens[i][0])
//            {
//            case '+': stk[top - 1] += stk[top]; top--; break;
//            case '-': stk[top - 1] -= stk[top]; top--; break;
//            case '*': stk[top - 1] *= stk[top]; top--; break;
//            case '/': stk[top - 1] /= stk[top]; top--; break;
//            }
//            //printf("%d\n", stk[top]);
//        }
//    }
//    return stk[0];
//}
//
////2500. 删除每行中的最大值
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int deleteGreatestValue(int** grid, int gridSize, int* gridColSize)
//{
//    for (int i = 0; i < gridSize; i++)
//    {
//        qsort(grid[i], gridColSize[0], sizeof(int), cmp);
//    }
//    int ret = 0;
//    for (int i = 0; i < gridColSize[0]; i++)
//    {
//        int max = 0;
//        for (int j = 0; j < gridSize; j++)
//        {
//            max = max >= grid[j][i] ? max : grid[j][i];
//        }
//        ret += max;
//    }
//    return ret;
//}
//
////2678. 老人的数目
//
//int countSeniors(char** details, int detailsSize)
//{
//    int num = 0;
//    for (int i = 0; i < detailsSize; i++)
//    {
//        num += strncmp(details[i] + 11, "60", 2) > 0;
//        //printf("%d %d\n", i, num);
//    }
//    return num;
//}
//
////2706. 购买两块巧克力
//
//int buyChoco(int* prices, int pricesSize, int money)
//{
//    int min1 = INT_MAX;
//    int min2 = INT_MAX;
//    for (int i = 0; i < pricesSize; i++)
//    {
//        if (min1 > prices[i])
//        {
//            min2 = min1;
//            min1 = prices[i];
//        }
//        else if (min2 > prices[i])
//            min2 = prices[i];
//    }
//    return money - min1 - min2 >= 0 ? money - min1 - min2 : money;
//}
//
