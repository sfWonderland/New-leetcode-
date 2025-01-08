#define _CRT_SECURE_NO_WARNINGS

//205.Í¬¹¹×Ö·û´®

//bool isIsomorphic(char* s, char* t)
//{
//    int len = strlen(s);
//    int arr1[len];
//    int arr2[len];
//
//    for (int i = 0; i < len; i++)
//    {
//        arr1[i] = 0;
//        arr2[i] = 0;
//    }
//    int flag = 1;
//    for (int i = 0; i < len; i++)
//    {
//        if (arr1[i] == 0)
//        {
//            arr1[i] = i + 1;
//            for (int j = i + 1; j < len; j++)
//            {
//                if (0 == arr1[j] && s[j] == s[i])
//                    arr1[j] = arr1[i];
//            }
//        }
//        if (arr2[i] == 0)
//        {
//            arr2[i] = i + 1;
//            for (int j = i + 1; j < len; j++)
//            {
//                if (0 == arr2[j] && t[j] == t[i])
//                    arr2[j] = arr2[i];
//            }
//        }
//        if (arr1[i] != arr2[i])
//        {
//            printf("arr1[%d] = %d, arr2[%d] = %d\n", i, arr1[i], i, arr2[i]);
//            flag = 0;
//            break;
//        }
//    }
//    if (flag)
//        return true;
//    else
//        return false;
//}