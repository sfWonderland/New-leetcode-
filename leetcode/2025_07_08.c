////17. 电话号码的字母组合
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char phoneMap[11][5] = { "\0","\0","abc\0","def\0","ghi\0","jkl\0","mno\0","pqrs\0","tuv\0","wxyz\0" };
//
//char* digits_tmp; //用于临时存储输入的数字字符串。
//int digits_size; //记录输入数字字符串的长度。
//
//char** combinations; //二维字符指针数组，用于存储最终生成的所有字母组合。
//int combinations_size; //记录 combinations 数组中已经存储的组合数量。
//
//char* combination; //字符指针，用于临时存储当前正在生成的字母组合。
//int combination_size; //记录当前正在生成的字母组合的长度。
//
//void backtrack(int index) //回溯函数
//{
//    if (digits_size == index) //字符串够长，即得到了一个遍历过所有数字的字符串组合
//    {
//        char* tmp = (char*)malloc(sizeof(char) * (combination_size + 1)); //combination的拷贝
//        memcpy(tmp, combination, sizeof(char) * (combination_size + 1));
//        combinations[combinations_size++] = tmp; //将完成的字符串加入集合
//    }
//    else
//    {
//        char digit = digits_tmp[index]; //读取号码
//        char* letters = phoneMap[digit - '0']; //读取号码对应字符串
//        int len = strlen(letters); //获取字符串长度
//        for (int i = 0; i < len; i++) //对每个分支进行遍历
//        {
//            combination[combination_size++] = letters[i]; // combination_size为当前字符串长度
//            combination[combination_size] = 0; //即结尾'\0'
//            backtrack(index + 1); //递推到下一个字符的分支
//            combination[combination_size--] = 0; //还原字符串长度，准备进行下一轮遍历
//        }
//    }
//}
//
//
//char** letterCombinations(char* digits, int* returnSize)
//{
//    combination_size = 0; //初始化单个字符串长度和字符串集合长度
//    combinations_size = 0;
//
//    digits_tmp = digits; //将号码字符串拷贝到全局变量
//    digits_size = strlen(digits);
//    if (digits_size == 0)
//    {
//        *returnSize = 0;
//        return combinations;
//    }
//    int num = 1; //字符串的数量
//    for (int i = 0; i < digits_size; i++)
//        num *= 4;
//
//    combinations = (char**)malloc(sizeof(char*) * num);
//    combination = (char*)malloc(sizeof(char) * (digits_size + 1));
//    backtrack(0);
//    *returnSize = combinations_size;
//    return combinations;
//}
//
////78. 子集
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
//{
//    int n = 1 << numsSize;
//    int** ans = (int**)malloc(sizeof(int*) * n);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
//    *returnSize = n;
//    int t[numsSize];
//    for (int i = 0; i < n; i++)
//    {
//        int m = 0;
//        for (int j = 0; j < numsSize; j++)
//        {
//            if (i & (1 << j))
//                t[m++] = nums[j];
//        }
//
//        int* tmp = (int*)malloc(sizeof(int) * m);
//        memcpy(tmp, t, sizeof(int) * m);
//        (*returnColumnSizes)[i] = m;
//        ans[i] = tmp;
//    }
//    return ans;
//}
//
////39. 组合总和
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int* path;
//int pathSize;
//
//int** ans;
//int ansSize;
//
//int* len;
//int sum;
//
//void backtrack(int* candidates, int candidatesSize, int target, int index)
//{
//    if (sum > target)
//        return;
//
//    if (sum == target)
//    {
//        int* tmp = (int*)malloc(sizeof(int) * pathSize);
//        for (int i = 0; i < pathSize; i++)
//        {
//            tmp[i] = path[i];
//        }
//        ans[ansSize] = tmp;
//        len[ansSize++] = pathSize;
//        return;
//    }
//
//    for (int i = index; i < candidatesSize; i++)
//    {
//        sum += candidates[i];
//        path[pathSize++] = candidates[i];
//        backtrack(candidates, candidatesSize, target, i);
//        sum -= candidates[i];
//        pathSize--;
//    }
//}
//int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
//{
//    pathSize = 0;
//    ansSize = 0;
//    sum = 0;
//    path = (int*)malloc(sizeof(int) * 21);
//    len = (int*)malloc(sizeof(int) * 150);
//    ans = (int**)malloc(sizeof(int*) * 150);
//    backtrack(candidates, candidatesSize, target, 0);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * ansSize);
//    for (int i = 0; i < ansSize; i++)
//    {
//        (*returnColumnSizes)[i] = len[i];
//    }
//    *returnSize = ansSize;
//    return ans;
//}
//
////40. 组合总和 II
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int* path;
//int pathSize;
//
//int** ans;
//int ansSize;
//
//int* len;
//int sum;
//
//void backtrack(int* candidates, int candidatesSize, int target, int index)
//{
//    if (sum > target)
//        return;
//
//    if (sum == target)
//    {
//        int* tmp = (int*)malloc(sizeof(int) * pathSize);
//        for (int i = 0; i < pathSize; i++)
//        {
//            tmp[i] = path[i];
//        }
//        ans[ansSize] = tmp;
//        len[ansSize++] = pathSize;
//        return;
//    }
//
//    for (int i = index; i < candidatesSize; )
//    {
//        int x = candidates[i];
//        sum += x;
//        path[pathSize++] = x;
//        backtrack(candidates, candidatesSize, target, i + 1);
//        sum -= x;
//        pathSize--;
//        i++;
//        while (i < candidatesSize && candidates[i] == x)
//            i++;
//    }
//}
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
//{
//    qsort(candidates, candidatesSize, sizeof(int), cmp);
//    pathSize = ansSize = sum = 0;
//    path = (int*)malloc(sizeof(int) * 100);
//    len = (int*)malloc(sizeof(int) * 500);
//    ans = (int**)malloc(sizeof(int*) * 500);
//    backtrack(candidates, candidatesSize, target, 0);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * ansSize);
//    for (int i = 0; i < ansSize; i++)
//    {
//        (*returnColumnSizes)[i] = len[i];
//    }
//    *returnSize = ansSize;
//    return ans;
//}
//
