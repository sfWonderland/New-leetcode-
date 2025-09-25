////535. TinyURL 的加密与解密
//
///** Encodes a URL to a shortened URL. */
////随机生成数哈希表
//typedef struct
//{
//    int key;
//    char* val;
//    UT_hash_handle hh;
//}HashItem;
//
//HashItem* database = NULL;
//
//char* encode(char* longUrl)
//{
//    srand(time(0));
//    int key;
//    HashItem* pEntry = NULL;
//    while (1)
//    {
//        key = rand();
//        pEntry = NULL;
//        HASH_FIND_INT(database, &key, pEntry);
//        if (pEntry == NULL) //防止随机生成数字重复
//            break;
//    }
//    pEntry = (HashItem*)malloc(sizeof(HashItem));
//    pEntry->key = key;
//    pEntry->val = longUrl;
//    HASH_ADD_INT(database, key, pEntry);
//    char* res = (char*)malloc(sizeof(char) * 64);
//    sprintf(res, "%s%d", "http://tinyurl.com/", key);
//    return res;
//}
//
///** Decodes a shortened URL to its original URL. */
//char* decode(char* shortUrl)
//{
//    char* p = shortUrl;
//    char* last = shortUrl;
//    while (last = strchr(p, '/'))
//        p = last + 1; //找到最后一个‘/’
//    int key = atoi(p);
//    HashItem* pEntry = NULL;
//    HASH_FIND_INT(database, &key, pEntry);
//    return pEntry ? pEntry->val : NULL;
//}
//
//// Your functions will be called as such:
//// char* s = encode(s);
//// decode(s);
//
////1476. 子矩形查询
//
//typedef struct
//{
//    int** rectangle;
//    int row;
//    int col;
//} SubrectangleQueries;
//
//
//SubrectangleQueries* subrectangleQueriesCreate(int** rectangle, int rectangleSize, int* rectangleColSize)
//{
//    SubrectangleQueries* obj = (SubrectangleQueries*)malloc(sizeof(SubrectangleQueries));
//    obj->rectangle = (int**)malloc(sizeof(int*) * rectangleSize);
//    for (int i = 0; i < rectangleSize; i++)
//    {
//        obj->rectangle[i] = (int*)malloc(sizeof(int) * rectangleColSize[0]);
//        for (int j = 0; j < rectangleColSize[0]; j++)
//        {
//            obj->rectangle[i][j] = rectangle[i][j];
//        }
//    }
//    obj->row = rectangleSize;
//    obj->col = rectangleColSize[0];
//    return obj;
//}
//
//void subrectangleQueriesUpdateSubrectangle(SubrectangleQueries* obj, int row1, int col1, int row2, int col2, int newValue)
//{
//    for (int i = row1; i <= row2; i++)
//    {
//        for (int j = col1; j <= col2; j++)
//        {
//            obj->rectangle[i][j] = newValue;
//        }
//    }
//}
//
//int subrectangleQueriesGetValue(SubrectangleQueries* obj, int row, int col)
//{
//    return obj->rectangle[row][col];
//}
//
//void subrectangleQueriesFree(SubrectangleQueries* obj)
//{
//    free(obj->rectangle);
//    free(obj);
//}
//
///**
// * Your SubrectangleQueries struct will be instantiated and called as such:
// * SubrectangleQueries* obj = subrectangleQueriesCreate(rectangle, rectangleSize, rectangleColSize);
// * subrectangleQueriesUpdateSubrectangle(obj, row1, col1, row2, col2, newValue);
//
// * int param_2 = subrectangleQueriesGetValue(obj, row, col);
//
// * subrectangleQueriesFree(obj);
//*/
//
////3683. 完成一个任务的最早时间
//
//int earliestTime(int** tasks, int tasksSize, int* tasksColSize)
//{
//    int min = INT_MAX;
//    for (int i = 0; i < tasksSize; i++)
//    {
//        min = fmin(min, tasks[i][0] + tasks[i][1]);
//    }
//    return min;
//}
//
////LCP 67. 装饰树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//
//void dfs(struct TreeNode* node)
//{
//    if (node->left)
//    {
//        struct TreeNode* s = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//        s->val = -1;
//        s->left = node->left;
//        s->right = NULL;
//        node->left = s;
//        dfs(s->left);
//    }
//    if (node->right)
//    {
//        struct TreeNode* s = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//        s->val = -1;
//        s->left = NULL;
//        s->right = node->right;
//        node->right = s;
//        dfs(s->right);
//    }
//}
//
//struct TreeNode* expandBinaryTree(struct TreeNode* root)
//{
//    dfs(root);
//    return root;
//}
//
