//#define _CRT_SECURE_NO_WARNINGS
//
////1588.������������������ĺ�
//
//// 1. ����
//// int sumOddLengthSubarrays(int* arr, int arrSize) 
//// {
////     int sum = 0;
////     //����㿪ʼ����
////     for(int start = 0; start < arrSize; start++)
////     {
////         //���������鳤��
////         for(int len = 1; start + len <= arrSize; len += 2)
////         {
////             //��ÿ���������Ԫ�ؽ��мӺ�
////             int end = start + len - 1;
////             for(int j = i; j <= end; j++)
////             {
////                 sum += arr[j];
////             }
////         }
////     }
////     return sum;
//// }
//// 2.ǰ׺��
//// int sumOddLengthSubarrays(int* arr, int arrSize) 
//// {
////     //����ǰ׺������
////     int* prefixSums = (int*)malloc(sizeof(int) * (arrSize + 1));
////     memset(prefixSums, 0, sizeof(int) * (arrSize + 1));
////     for(int i = 0; i < arrSize; i++)
////     {
////         //����ǰ׺��, �±�Ϊǰ׺����
////         prefixSums[i + 1] = prefixSums[i] + arr[i]; 
////     }
////     int sum = 0;
////     //����㿪ʼ����
////     for(int start = 0; start < arrSize; start++)
////     {
//
////         //���������鳤��
////         for(int len = 1; start + len <= arrSize; len += 2)
////         {
////             //(end + 1)��Ԫ�غͼ�ȥ start ��Ԫ�صĺͣ�����start��ʼ��len���������鳤��
////             int end = start + len - 1;
////             sum += prefixSums[end + 1] - prefixSums[start];
////         }
////     }
////     free(prefixSums);
////     return sum;
//// }
//// 3.��ѧ����
//int sumOddLengthSubarrays(int* arr, int arrSize)
//{
//    int sum = 0;
//    for (int i = 0; i < arrSize; i++)
//    {
//        //��ǰԪ����������Ԫ�ظ���
//        int leftCount = i;
//        int rightCount = arrSize - 1 - i;
//        //��ǰԪ��������������������Ԫ��Ϊ������
//        int leftOdd = (leftCount + 1) >> 1;
//        int rightOdd = (rightCount + 1) >> 1;
//        //��ǰԪ��������������������Ԫ��Ϊż����
//        int leftEven = 1 + (leftCount >> 1);
//        int rightEven = 1 + (rightCount >> 1);
//
//        sum += arr[i] * (leftOdd * rightOdd + leftEven * rightEven);
//    }
//    return sum;
//}
//
////2778.����Ԫ��ƽ����
//
//int sumOfSquares(int* nums, int numsSize)
//{
//    int sum = 0;
//    for (int i = 1; i * i <= numsSize; i++)
//    {
//        if (0 == numsSize % i)
//        {
//            sum += nums[i - 1] * nums[i - 1];
//            //�Ӷ�Ӧ����������ֹ�ظ�����ȫƽ����
//            if (i * i < numsSize)
//                sum += nums[numsSize / i - 1] * nums[numsSize / i - 1];
//        }
//    }
//    return sum;
//}
//
////633.ƽ����֮��
//
//bool judgeSquareSum(int c)
//{
//    int right = (int)sqrt(c);
//    int left = (int)sqrt(c - right * right);
//    //printf("left = %d, right = %d\n", left, right);
//    while (left <= right)
//    {
//        long long num = (long long)left * left + right * right;
//        if (c == num)
//            return true;
//        else if (num < c)
//            left++;
//        else
//            right--;
//        //printf("left = %d, right = %d\n", left, right);
//    }
//    return false;
//}
//
////1592.�������е��ʼ�Ŀո�
//
//char* reorderSpaces(char* text)
//{
//    int len = strlen(text);
//    char* ret = (char*)malloc(sizeof(char) * (len + 1));
//    memset(ret, ' ', sizeof(char) * len);
//    ret[len] = '\0';
//    int blanks = 0;
//    int words = 0;
//    if (text[0] != ' ')
//        words++;
//    for (int i = 0; i < len; i++)
//    {
//        if (text[i] == ' ')
//            blanks++;
//        else
//        {
//            if (i > 0 && text[i - 1] == ' ')
//                words++;
//        }
//    }
//    printf("blanks = %d, words = %d\n", blanks, words);
//    int division = 0;
//    int j = 0;
//    if (words > 1)
//        division = blanks / (words - 1);
//
//    for (int i = 0; i < len; i++)
//    {
//        if (text[i] != ' ')
//            ret[j++] = text[i];
//        else if (i > 0 && text[i - 1] != ' ')
//            j += division;
//    }
//
//    return ret;
//}
//
////1608.�������������ֵ
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int specialArray(int* nums, int numsSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    for (int i = 1; i <= numsSize; i++)
//    {
//        if (nums[i - 1] >= i && (i == numsSize || nums[i] < i))
//            return i;
//    }
//    return -1;
//}
//
////1619.ɾ��ĳЩԪ�غ�������ֵ
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//double trimMean(int* arr, int arrSize)
//{
//    qsort(arr, arrSize, sizeof(int), cmp);
//    int delete = arrSize / 20;
//    double sum = 0;
//    for (int i = delete; i < arrSize - delete; i++)
//    {
//        sum += arr[i];
//    }
//    return sum / (arrSize - 2 * delete);
//}
