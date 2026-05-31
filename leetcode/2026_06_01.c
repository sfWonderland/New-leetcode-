//// 2456. 最流行的视频创作者
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    char* key;
//    long long cnt;
//    int idx;
//    UT_hash_handle hh;
//}Creators;
//char*** mostPopularCreator(char** creators, int creatorsSize, char** ids, int idsSize, int* views, int viewsSize, int* returnSize, int** returnColumnSizes)
//{
//    int n = creatorsSize;
//    Creators* users = NULL;
//    int mems = 0;
//    long long max = 0;
//    for (int i = 0; i < n; i++)
//    {
//        char* name = creators[i];
//        char* id = ids[i];
//        int view = views[i];
//        Creators* p1 = NULL;
//        HASH_FIND_STR(users, name, p1);
//        if (p1 == NULL)
//        {
//            p1 = (Creators*)malloc(sizeof(Creators));
//            p1->key = name;
//            p1->cnt = view;
//            p1->idx = i;
//            HASH_ADD_STR(users, key, p1);
//            mems++;
//        }
//        else
//        {
//            p1->cnt += view;
//            int j = p1->idx;
//            if (views[j] < view || (views[j] == view && strcmp(ids[j], id) > 0))
//                p1->idx = i;
//        }
//        max = fmax(max, p1->cnt);
//    }
//    char*** ans = (char***)malloc(sizeof(char**) * mems);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * mems);
//    int k = 0;
//    Creators* tmp = NULL, * p2 = NULL;
//    HASH_ITER(hh, users, p2, tmp)
//    {
//        if (max == p2->cnt)
//        {
//            ans[k] = (char**)malloc(sizeof(char*) * 2);
//            ans[k][0] = creators[p2->idx];
//            ans[k][1] = ids[p2->idx];
//            (*returnColumnSizes)[k++] = 2;
//        }
//        HASH_DEL(users, p2);
//        free(p2);
//    }
//    *returnSize = k;
//    return ans;
//}
//
