////1578. 使绳子变成彩色的最短时间
//
//int minCost(char* colors, int* neededTime, int neededTimeSize)
//{
//    int ans = 0;
//    int sum = neededTime[0];
//    int max = neededTime[0];
//    for (int i = 1; i < neededTimeSize; i++)
//    {
//        if (colors[i] == colors[i - 1])
//        {
//            sum += neededTime[i];
//            max = fmax(max, neededTime[i]);
//        }
//        else
//        {
//            ans += sum - max;
//            sum = neededTime[i];
//            max = neededTime[i];
//        }
//    }
//    ans += sum - max;
//    return ans;
//}
//
////1963. 使字符串平衡的最小交换次数
//
//int minSwaps(char* s)
//{
//    int n = strlen(s);
//    int j = n - 1;
//    int ans = 0, c = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (s[i] == '[')
//            c++;
//        else if (c > 0)
//            c--;
//        else
//        {
//            while (s[j] == ']')
//                j--;
//
//            s[j] = ']';
//            c++;
//            ans++;
//        }
//    }
//    return ans;
//}
////提示 1遍历字符串，在每次迭代中记录开括号和闭括号的数量。
////提示 2若闭括号数量超过开括号数量，则需进行交换操作。
////提示 3将其与s字符串末尾最近的开括号进行交换。
//
////678. 有效的括号字符串
//
//bool checkValidString(char* s)
//{
//    int n = strlen(s);
//    int st1[n];
//    int st2[n];
//    int idx1 = 0, idx2 = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (s[i] == '(')
//            st1[idx1++] = i;
//        else if (s[i] == '*')
//            st2[idx2++] = i;
//        else
//        {
//            if (idx1 > 0)
//                idx1--;
//            else if (idx2 > 0)
//                idx2--;
//            else
//                return false;
//        }
//    }
//    while (idx1 > 0)
//    {
//        if (idx2 == 0 || st2[--idx2] < st1[--idx1])
//            return false;
//    }
//    return true;
//}
//
////1111. 有效括号的嵌套深度
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* maxDepthAfterSplit(char* seq, int* returnSize)
//{
//    int n = strlen(seq);
//    *returnSize = n;
//    int* ret = (int*)malloc(sizeof(int) * n);
//    int sum = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (seq[i] == '(')
//        {
//            sum++;
//            ret[i] = sum % 2;
//        }
//        else
//        {
//            ret[i] = sum % 2;
//            --sum;
//        }
//    }
//    return ret;
//}
//
