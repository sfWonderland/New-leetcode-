//// 682. ∞Ù«Ú±»»¸
//
//int calPoints(char** operations, int operationsSize)
//{
//    int n = operationsSize;
//    int* points = (int*)malloc(sizeof(int) * n);
//    int top = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (operations[i][0] == '+')
//            points[top++] = points[top - 1] + points[top - 2];
//        else if (operations[i][0] <= '9') // 0 ~ 9 && -
//        {
//            bool minus = operations[i][0] == '-';
//            int x = 0;
//            for (int j = minus; operations[i][j]; j++)
//            {
//                x *= 10;
//                x += operations[i][j] & 15;
//            }
//            if (minus) x = -x;
//            points[top++] = x;
//        }
//        else
//        {
//            if (operations[i][0] == 'C')
//                top--;
//            else
//                points[top++] = 2 * points[top - 1];
//        }
//    }
//    int sum = 0;
//    for (int i = 0; i < top; i++)
//    {
//        sum += points[i];
//    }
//    return sum;
//}
//
