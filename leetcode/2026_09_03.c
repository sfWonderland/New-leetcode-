//// 1233. É¾³ý×ÓÎÄ¼þ¼Ð
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return strcmp(*(char**)e1, *(char**)e2);
//}
//
//char** removeSubfolders(char** folder, int folderSize, int* returnSize)
//{
//    int n = folderSize;
//    qsort(folder, n, sizeof(char*), cmp);
//    *returnSize = 1;
//    for (int i = 1; i < n; i++)
//    {
//        char* s = folder[i];
//        char* last = folder[*returnSize - 1];
//        int len = strlen(last);
//        if (strncmp(s, last, len) || s[len] != '/')
//            folder[(*returnSize)++] = s;
//    }
//    return folder;
//}
//
