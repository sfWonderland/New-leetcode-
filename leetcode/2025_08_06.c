////938. 二叉搜索树的范围和
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* s, int low, int high)
//{
//    if (s == NULL)
//        return 0;
//
//    int n = s->val;
//    int sum = dfs(s->left, low, high) + dfs(s->right, low, high);
//    return n >= low && n <= high ? n + sum : sum;
//}
//int rangeSumBST(struct TreeNode* root, int low, int high)
//{
//    return dfs(root, low, high);
//}
//
////1603. 设计停车系统
//
//typedef struct
//{
//    int b, m, s;
//} ParkingSystem;
//
//
//ParkingSystem* parkingSystemCreate(int big, int medium, int small)
//{
//    ParkingSystem* ret = (ParkingSystem*)malloc(sizeof(ParkingSystem));
//    ret->b = big;
//    ret->m = medium;
//    ret->s = small;
//    return ret;
//}
//
//bool parkingSystemAddCar(ParkingSystem* obj, int carType)
//{
//    switch (carType)
//    {
//    case 1: if (obj->b) { (obj->b)--; return true; } break;
//    case 2: if (obj->m) { (obj->m)--; return true; } break;
//    case 3: if (obj->s) { (obj->s)--; return true; } break;
//    }
//    return false;
//}
//
//void parkingSystemFree(ParkingSystem* obj)
//{
//    free(obj);
//}
//
///**
// * Your ParkingSystem struct will be instantiated and called as such:
// * ParkingSystem* obj = parkingSystemCreate(big, medium, small);
// * bool param_1 = parkingSystemAddCar(obj, carType);
//
// * parkingSystemFree(obj);
//*/
//
////1656. 设计有序流
//
//typedef struct
//{
//    int ptr;
//    int streamSize;
//    char** stream;
//} OrderedStream;
//
//
//OrderedStream* orderedStreamCreate(int n)
//{
//    OrderedStream* obj = (OrderedStream*)malloc(sizeof(OrderedStream));
//    obj->stream = (char**)malloc(sizeof(char*) * (n + 1));
//    for (int i = 0; i <= n; i++)
//    {
//        obj->stream[i] = NULL;
//    }
//    obj->streamSize = n + 1;
//    obj->ptr = 1;
//    return obj;
//}
//
//char** orderedStreamInsert(OrderedStream* obj, int idKey, char* value, int* retSize)
//{
//    obj->stream[idKey] = value;
//    int pos = 0;
//    char** ret = (char**)malloc(sizeof(char*) * obj->streamSize);
//    while (obj->ptr < obj->streamSize && obj->stream[obj->ptr])
//    {
//        ret[pos++] = obj->stream[obj->ptr++];
//    }
//    *retSize = pos;
//    return ret;
//}
//
//void orderedStreamFree(OrderedStream* obj)
//{
//    free(obj->stream);
//    free(obj);
//}
//
///**
// * Your OrderedStream struct will be instantiated and called as such:
// * OrderedStream* obj = orderedStreamCreate(n);
// * char** param_1 = orderedStreamInsert(obj, idKey, value, retSize);
//
// * orderedStreamFree(obj);
//*/
//
////1038. 从二叉搜索树到更大和树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//void dfs(struct TreeNode* s, int* n)
//{
//    if (s == NULL)
//        return;
//    dfs(s->right, n);
//    s->val += *n;
//    *n = s->val;
//    dfs(s->left, n);
//}
//struct TreeNode* bstToGst(struct TreeNode* root)
//{
//    int n = 0;
//    dfs(root, &n);
//    return root;
//}
//
