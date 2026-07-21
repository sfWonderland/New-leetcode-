//// 2512. 奖励最顶尖的 K 名学生
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    char* key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//typedef struct
//{
//    int id;
//    int score;
//}Identity;
//int cmp(const void* e1, const void* e2)
//{
//    return (*(Identity*)e1).score == (*(Identity*)e2).score ? (*(Identity*)e1).id - (*(Identity*)e2).id : (*(Identity*)e2).score - (*(Identity*)e1).score;
//}
//int* topStudents(char** positive_feedback, int positive_feedbackSize, char** negative_feedback, int negative_feedbackSize, char** report, int reportSize, int* student_id, int student_idSize, int k, int* returnSize)
//{
//    HashItem* words = NULL;
//    HashItem* p = NULL;
//    for (int i = 0; i < positive_feedbackSize; i++)
//    {
//        p = (HashItem*)malloc(sizeof(HashItem));
//        p->key = positive_feedback[i];
//        p->val = 3;
//        HASH_ADD_STR(words, key, p);
//    }
//    for (int i = 0; i < negative_feedbackSize; i++)
//    {
//        p = (HashItem*)malloc(sizeof(HashItem));
//        p->key = negative_feedback[i];
//        p->val = -1;
//        HASH_ADD_STR(words, key, p);
//    }
//    int n = student_idSize;
//    Identity* scores = (Identity*)malloc(sizeof(Identity) * n);
//    for (int i = 0; i < n; i++)
//    {
//        scores[i].id = student_id[i];
//        int score0 = 0;
//        for (char* s = strtok(report[i], " "); s; s = strtok(NULL, " "))
//        {
//            HashItem* p1 = NULL;
//            HASH_FIND_STR(words, s, p1);
//            if (p1)
//                score0 += p1->val;
//        }
//        scores[i].score = score0;
//    }
//    qsort(scores, n, sizeof(Identity), cmp);
//    int* ans = (int*)malloc(sizeof(int) * k);
//    for (int i = 0; i < k; i++)
//    {
//        ans[i] = scores[i].id;
//    }
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, words, p, tmp)
//    {
//        HASH_DEL(words, p);
//        free(p);
//    }
//    free(scores);
//    *returnSize = k;
//    return ans;
//}
//
