////1700. 无法吃午餐的学生数量
//
//int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize)
//{
//    int s1 = 0;
//    for (int i = 0; i < studentsSize; i++)
//    {
//        s1 += students[i];
//    }
//    int s0 = studentsSize - s1;
//    for (int i = 0; i < sandwichesSize; i++)
//    {
//        if (sandwiches[i] == 0 && s0 > 0)
//            s0--;
//        else if (sandwiches[i] == 1 && s1 > 0)
//            s1--;
//        else
//            break;
//    }
//    return s0 + s1;
//}
//
////2073. 买票需要的时间
//
//int timeRequiredToBuy(int* tickets, int ticketsSize, int k)
//{
//    int sum = 0;
//    for (int i = 0; i < ticketsSize; i++)
//    {
//        sum += tickets[i] >= tickets[k] ? tickets[k] - (i > k) : tickets[i];
//    }
//    return sum;
//}
//
////1614. 括号的最大嵌套深度
//
//int maxDepth(char* s)
//{
//    int max = 0;
//    int sum = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] == '(')
//        {
//            sum++;
//            max = fmax(max, sum);
//        }
//        else if (s[i] == ')')
//            sum--;
//    }
//    return max;
//}
//
////1637. 两点之间不包含任何点的最宽垂直区域
//
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e1)[0] - (*(int**)e2)[0];
//}
//int maxWidthOfVerticalArea(int** points, int pointsSize, int* pointsColSize)
//{
//    qsort(points, pointsSize, sizeof(int) * 2, cmp);
//    int max = 0;
//    for (int i = 1; i < pointsSize; i++)
//    {
//        max = fmax(max, points[i][0] - points[i - 1][0]);
//    }
//    return max;
//}
//
