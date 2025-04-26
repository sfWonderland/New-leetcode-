////3502. ����ÿ��λ�õ���С����
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* minCosts(int* cost, int costSize, int* returnSize)
//{
//    int* ret = (int*)malloc(sizeof(int) * costSize);
//    int min = 0x7fffffff;
//    for (int i = 0; i < costSize; i++)
//    {
//        if (min > cost[i])
//        {
//            ret[i] = cost[i];
//            min = cost[i];
//        }
//        else
//            ret[i] = min;
//    }
//    *returnSize = costSize;
//    return ret;
//}
//
////3516. �ҵ��������
//
//int findClosest(int x, int y, int z)
//{
//    int a = abs(x - z);
//    int b = abs(y - z);
//    if (a == b)
//        return 0;
//    else if (a > b)
//        return 2;
//    else
//        return 1;
//}
//
////3226. ʹ����������ȵ�λ���Ĵ���
//
//int minChanges(int n, int k)
//{
//    //printf("%x", n|k);
//    if ((n | k) != n)
//        return -1;
//    int t = n ^ k;
//    int num = 0;
//    while (t)
//    {
//        t &= (t - 1);
//        num++;
//    }
//    return num;
//}
//
////3477. ��ˮ���������� II
//
//int numOfUnplacedFruits(int* fruits, int fruitsSize, int* baskets, int basketsSize)
//{
//    bool valid[basketsSize];
//    memset(valid, 0, sizeof(bool) * basketsSize);
//    int ans = fruitsSize;
//    for (int i = 0; i < fruitsSize; i++)
//    {
//        for (int j = 0; j < basketsSize; j++)
//        {
//            if (valid[j])
//                continue;
//            if (baskets[j] >= fruits[i])
//            {
//                //printf("%d %d\n", fruits[i], baskets[j]);
//                ans--;
//                valid[j] = true;
//                break;
//            }
//        }
//    }
//    return ans;
//}
//
////1356. �������ֶ������� 1 ����Ŀ����
//
//// ����һ�����������Ʊ�ʾ�� 1 �ĸ��� 
//int getDigit(int n) {
//    int num = 0;
//    while (n) {
//        num++;
//        n &= n - 1;
//    }
//    return num;
//}
//
//// ����һ���ṹ�����洢������������� 1 �ĸ��� 
//typedef struct {
//    int value;
//    int bitCount;
//} Number;
//
//// �ȽϺ������Ȱ������� 1 �ĸ�����������ͬ�����������С���� 
//int cmp(const void* e1, const void* e2) {
//    Number* num1 = (Number*)e1;
//    Number* num2 = (Number*)e2;
//    if (num1->bitCount != num2->bitCount) {
//        return num1->bitCount - num2->bitCount;
//    }
//    return num1->value - num2->value;
//}
//
//// ��������������������� 
//int* sortByBits(int* arr, int arrSize, int* returnSize) {
//    // ����洢�ṹ����ڴ� 
//    Number* numbers = (Number*)malloc(sizeof(Number) * arrSize);
//    if (numbers == NULL) {
//        return NULL;
//    }
//
//    // ���ṹ������ 
//    for (int i = 0; i < arrSize; i++) {
//        numbers[i].value = arr[i];
//        numbers[i].bitCount = getDigit(arr[i]);
//    }
//
//    // ʹ�� qsort �Խṹ������������� 
//    qsort(numbers, arrSize, sizeof(Number), cmp);
//
//    // ������������ڴ� 
//    int* ans = (int*)malloc(sizeof(int) * arrSize);
//    if (ans == NULL) {
//        free(numbers);
//        return NULL;
//    }
//
//    // ������õĽ�����Ƶ���������� 
//    for (int i = 0; i < arrSize; i++) {
//        ans[i] = numbers[i].value;
//    }
//
//    // �ͷŽṹ��������ڴ� 
//    free(numbers);
//
//    // ���÷�������Ĵ�С 
//    *returnSize = arrSize;
//    return ans;
//}
//
