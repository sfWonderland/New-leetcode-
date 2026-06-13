//// 640. 求解方程
//
//char* solveEquation(char* equation)
//{
//    int cntX = 0, sum = 0;
//    int flag = -1;
//    for (char* s = strtok(equation, "="); s; s = strtok(NULL, "="))
//    {
//        int sym = 1;
//        if (s[0] == '-')
//        {
//            sym = -1;
//            s++;
//        }
//        for (int i = 0; s[i]; i++)
//        {
//            int l = i;
//            // printf("%s\n", s + l);
//            while (s[i] && s[i] != '+' && s[i] != '-')
//                i++;
//            int r = s[i - 1] == 'x' ? i - 1 : i;
//            // printf("%d %d\n", l, r);
//            if (r > l)
//            {
//                char tmp = s[r];
//                s[r] = '\0';
//                int num = atoi(s + l);
//                s[r] = tmp;
//                if (r == i - 1)
//                    cntX -= sym * flag * num;
//                else
//                    sum += sym * flag * num;
//            }
//            else
//                cntX -= sym * flag;
//
//            sym = s[i] == '+' ? 1 : -1;
//            if (!s[i])
//                i--;
//            // printf("%d %d\n", cntX, sum);
//        }
//        // printf("%d %d\n", cntX, sum);
//        flag = -flag;
//    }
//    if (cntX == 0)
//        return sum ? "No solution" : "Infinite solutions";
//    else if (sum % cntX)
//        return "No solution";
//    char* ans = (char*)malloc(sizeof(char) * 7);
//    sprintf(ans, "x=%d", sum / cntX);
//    return ans;
//}
//
