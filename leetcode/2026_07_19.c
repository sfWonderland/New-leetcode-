//// 2531. 使字符串中不同字符的数目相等
//
//bool isItPossible(char* word1, char* word2)
//{
//    int* cnt1 = (int*)calloc(sizeof(int), 26);
//    int* cnt2 = (int*)calloc(sizeof(int), 26);
//    for (int i = 0; word1[i]; i++)  cnt1[word1[i] - 'a']++;
//    for (int i = 0; word2[i]; i++)  cnt2[word2[i] - 'a']++;
//    int diff1 = 0, diff2 = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        diff1 += cnt1[i] > 0;
//        diff2 += cnt2[i] > 0;
//    }
//    if (abs(diff1 - diff2) > 2)  return false;
//    for (int i = 0; i < 26; i++)
//    {
//        if (cnt1[i] == 0) continue;
//        for (int j = 0; j < 26; j++)
//        {
//            if (cnt2[j] == 0) continue;
//            int d1 = diff1;
//            if (i != j && cnt1[i] == 1) d1--;
//            if (cnt1[j] == 0) d1++;
//            int d2 = diff2;
//            if (cnt2[i] == 0) d2++;
//            if (i != j && cnt2[j] == 1) d2--;
//            if (d1 == d2) return true;
//        }
//    }
//
//    return false;
//}
//
