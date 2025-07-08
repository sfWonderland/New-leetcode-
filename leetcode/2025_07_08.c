////17. �绰�������ĸ���
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char phoneMap[11][5] = { "\0","\0","abc\0","def\0","ghi\0","jkl\0","mno\0","pqrs\0","tuv\0","wxyz\0" };
//
//char* digits_tmp; //������ʱ�洢����������ַ�����
//int digits_size; //��¼���������ַ����ĳ��ȡ�
//
//char** combinations; //��ά�ַ�ָ�����飬���ڴ洢�������ɵ�������ĸ��ϡ�
//int combinations_size; //��¼ combinations �������Ѿ��洢�����������
//
//char* combination; //�ַ�ָ�룬������ʱ�洢��ǰ�������ɵ���ĸ��ϡ�
//int combination_size; //��¼��ǰ�������ɵ���ĸ��ϵĳ��ȡ�
//
//void backtrack(int index) //���ݺ���
//{
//    if (digits_size == index) //�ַ������������õ���һ���������������ֵ��ַ������
//    {
//        char* tmp = (char*)malloc(sizeof(char) * (combination_size + 1)); //combination�Ŀ���
//        memcpy(tmp, combination, sizeof(char) * (combination_size + 1));
//        combinations[combinations_size++] = tmp; //����ɵ��ַ������뼯��
//    }
//    else
//    {
//        char digit = digits_tmp[index]; //��ȡ����
//        char* letters = phoneMap[digit - '0']; //��ȡ�����Ӧ�ַ���
//        int len = strlen(letters); //��ȡ�ַ�������
//        for (int i = 0; i < len; i++) //��ÿ����֧���б���
//        {
//            combination[combination_size++] = letters[i]; // combination_sizeΪ��ǰ�ַ�������
//            combination[combination_size] = 0; //����β'\0'
//            backtrack(index + 1); //���Ƶ���һ���ַ��ķ�֧
//            combination[combination_size--] = 0; //��ԭ�ַ������ȣ�׼��������һ�ֱ���
//        }
//    }
//}
//
//
//char** letterCombinations(char* digits, int* returnSize)
//{
//    combination_size = 0; //��ʼ�������ַ������Ⱥ��ַ������ϳ���
//    combinations_size = 0;
//
//    digits_tmp = digits; //�������ַ���������ȫ�ֱ���
//    digits_size = strlen(digits);
//    if (digits_size == 0)
//    {
//        *returnSize = 0;
//        return combinations;
//    }
//    int num = 1; //�ַ���������
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
////78. �Ӽ�
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
////39. ����ܺ�
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
////40. ����ܺ� II
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
