//// 398. Ëæ»úÊýË÷Òý
//
//typedef struct
//{
//    int key;
//    int* list;
//    int capacity;
//    int n;
//    UT_hash_handle hh;
//} Solution;
//
//
//Solution* solutionCreate(int* nums, int numsSize)
//{
//    Solution* obj = NULL;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = nums[i];
//        Solution* p1 = NULL;
//        HASH_FIND_INT(obj, &x, p1);
//        if (p1 == NULL)
//        {
//            p1 = (Solution*)malloc(sizeof(Solution));
//            p1->key = x;
//            p1->capacity = 8;
//            p1->list = (int*)malloc(sizeof(int) * p1->capacity);
//            p1->n = 0;
//            HASH_ADD_INT(obj, key, p1);
//        }
//        p1->list[p1->n++] = i;
//        if (p1->n >= p1->capacity)
//        {
//            p1->capacity *= 2;
//            p1->list = (int*)realloc(p1->list, sizeof(int) * p1->capacity);
//        }
//    }
//    return obj;
//}
//
//int solutionPick(Solution* obj, int target)
//{
//    Solution* p1 = NULL;
//    HASH_FIND_INT(obj, &target, p1);
//    if (p1 == NULL)
//        return -1;
//    int y = rand() % p1->n;
//    return p1->list[y];
//}
//
//void solutionFree(Solution* obj)
//{
//    Solution* p1 = NULL, * tmp = NULL;
//    HASH_ITER(hh, obj, p1, tmp)
//    {
//        HASH_DEL(obj, p1);
//        free(p1->list);
//        free(p1);
//    }
//}
//
///**
// * Your Solution struct will be instantiated and called as such:
// * Solution* obj = solutionCreate(nums, numsSize);
// * int param_1 = solutionPick(obj, target);
//
// * solutionFree(obj);
//*/
//
