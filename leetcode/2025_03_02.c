////LCR 133. λ 1 �ĸ���
//
//int hammingWeight(uint32_t n)
//{
//    int cnt = 0;
//    while (n)
//    {
//        n &= n - 1;
//        cnt++;
//    }
//    return cnt;
//}
//
////LCR 158. ������ II
//
////Ħ��ͶƱ�������������
//int inventoryManagement(int* stock, int stockSize)
//{
//    int vote = 0;
//    int x = 0;
//    for (int i = 0; i < stockSize; i++)
//    {
//        if (0 == vote)
//            x = stock[i];
//
//        vote += x == stock[i] ? 1 : -1;
//    }
//    return x;
//}
//
////LCR 161. ����������������۶�
//
//int maxSales(int* sales, int salesSize)
//{
//    int pre = 0;
//    int max = sales[0];
//    for (int i = 0; i < salesSize; i++)
//    {
//        pre = fmax(pre + sales[i], sales[i]);
//        max = fmax(pre, max);
//    }
//    return max;
//}
