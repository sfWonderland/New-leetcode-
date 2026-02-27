////1835. 所有数对按位与结果的异或和
//
//int getXORSum(int* arr1, int arr1Size, int* arr2, int arr2Size)
//{
//    // 我们只分析某一位的情况就够了，异或运算 = 不进位的加法
//    // 1.假设arr1中第一个数a1的这一位为0，
//    // 由于0 & n == 0，所以a1和arr2中每个数做AND运算之后，得到的该位的值都是0，异或之后结果也必然是0
//    // 2.假设arr1中第一个数a2的这一位为1，
//    // 由于1 & n == n，所以a1和arr2中每个数做AND运算之后，得到的该位的值都保持原样不变，
//    // 那么最终异或后的结果，就要看arr2中所有数的这一位的1的数量了
//    // 如果1的数量是偶数个，那么全部异或之后，结果为0，如果数量是奇数个，那么全部异或之后，结果为1
//    // 3.以上1和2的分析只针对arr1中的第一个数a1，其对于arr1中的其他数也同样适用，
//    // 于是我们对arr1的所有元素也进行异或操作，该位的结果同样与1的总数有关，偶数则为0，奇数则为1
//    // 4.偶数个1的异或和必定为0，只有两边的结果都是1的时候，该位的最终结果才是1
//    // 很显然，这是AND运算，稍微思考一下就会发现，两边做的是乘法运算，而乘法就是AND
//    // 5.对于该二进制位的分析，同样适用于每一个二进制位，于是我们把运算从某一位拓展到整个数字上
//    // 6.所以最终结果就是 arr1的异或和 AND arr2的异或和，也即reduce(xor, a, 0) & reduce(xor, b, 0)
//    int a = arr1[0];
//    for (int i = 1; i < arr1Size; i++)
//    {
//        a ^= arr1[i];
//    }
//    int b = arr2[0];
//    for (int i = 1; i < arr2Size; i++)
//    {
//        b ^= arr2[i];
//    }
//    return a & b;
//}
//
////100999. 移除尾部元音字母    
//
//char* trimTrailingVowels(char* s)
//{
//    int n = strlen(s), i;
//    for (i = n - 1; i >= 0; i--)
//    {
//        if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u')
//            break;
//    }
//    s[i + 1] = '\0';
//    return s;
//}
//
////3857. 拆分到 1 的最小总代价
//
//int minCost(int n)
//{
//    return n * (n - 1) / 2;
//}
//
////100936. 按位或的最小值
//
//int minimumOR(int** grid, int gridSize, int* gridColSize)
//{
//    int ans = 0;
//    // 逐位遍历，从高到低遍历，因为高位减一的1位数更多，匹配成功可能性更大
//    // 将允许通过的数设为返回值与当前位减一的按位或值，
//    // 如果遍历各行都能找到与该数按位或的值等于该数，说明当前位不用选
//    // 如果找不到那么必须选，把返回值与当前位按位或。
//    for (int bit = 17; bit >= 0; bit--)
//    {
//        int power = 1 << bit;
//        int allowed = ans | (power - 1);
//        bool valid = true;
//        for (int i = 0; i < gridSize; i++)
//        {
//            bool found = false;
//            for (int j = 0; j < gridColSize[0]; j++)
//            {
//                if ((grid[i][j] | allowed) == allowed)
//                {
//                    found = true;
//                    break;
//                }
//            }
//            if (!found)
//            {
//                valid = false;
//                break;
//            }
//        }
//        if (!valid)
//            ans |= power;
//    }
//    return ans;
//}
//
