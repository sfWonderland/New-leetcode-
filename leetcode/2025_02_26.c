////LCR 173. 点名
//
//int takeAttendance(int* records, int recordsSize)
//{
//    int left = 0;
//    int right = recordsSize;
//    while (left < right)
//    {
//        int mid = ((right - left) >> 1) + left;
//        if (records[mid] > mid)
//            right = mid;
//        else
//            left = mid + 1;
//    }
//    return left;
//}
//
////LCR 120.寻找文件副本
//
//// int cmp(const void* e1, const void* e2)
//// {
////     return *(int*)e1 - *(int*)e2;
//// }
//// int findRepeatDocument(int* documents, int documentsSize) 
//// {
////     qsort(documents, documentsSize, sizeof(int), cmp);
////     for(int i = 0; i < documentsSize - 1; i++)
////     {
////         if(documents[i] == documents[i + 1])
////         return documents[i];
////     }
////     return -1;
//// }
//
//int findRepeatDocument(int* documents, int documentsSize)
//// {
////     int h[documentsSize];
////     memset(h, 0, sizeof(int) * documentsSize);
////     for(int i = 0; i < documentsSize; i++)
////     {
////         if(h[documents[i]])
////         return documents[i];
////         else
////         h[documents[i]]++;
////     }
////     return -1;
//// }
//
//void swap(int* a, int* b)
//{
//    int t = *a;
//    *a = *b;
//    *b = t;
//}
//int findRepeatDocument(int* documents, int documentsSize)
//{
//    for (int i = 0; i < documentsSize; i++)
//    {
//        while (documents[i] != i)
//        {
//            if (documents[documents[i]] == documents[i])
//                return documents[i];
//
//            swap(&documents[i], &documents[documents[i]]);
//        }
//    }
//    return -1;
//}
//
////LCR 172. 统计目标成绩的出现次数
//
//// int countTarget(int* scores, int scoresSize, int target) 
//// {
////     if(!scoresSize)
////     return 0;
////     int left = 0;
////     int right = scoresSize - 1;
////     while(left <= right)
////     {
////         int mid = left + ((right - left) >> 1);
////         if(scores[mid] < target)
////         left = mid + 1;
////         else
////         right = mid - 1;
////     }
////     int n = 0;
////     while(left < scoresSize && scores[left++] == target)
////         n++; 
////     return n;
//// }
//
//int countTarget(int* scores, int scoresSize, int target)
//{
//    int left = 0;
//    int right = scoresSize - 1;
//    while (left <= right)
//    {
//        int mid = left + ((right - left) >> 1);
//        if (scores[mid] <= target)
//            left = mid + 1;
//        else
//            right = mid - 1;
//    }
//    int t = left;
//    left = 0;
//    right = scoresSize - 1;
//    while (left <= right)
//    {
//        int mid = left + ((right - left) >> 1);
//        if (scores[mid] < target)
//            left = mid + 1;
//        else
//            right = mid - 1;
//    }
//
//    return t - left;
//}
//
