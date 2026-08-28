//// 677. ¼üÖµÓ³Éä
//
//typedef struct Node
//{
//    struct Node* son[26];
//    int val;
//}Node;
//
//typedef struct
//{
//    char* key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//
//typedef struct
//{
//    Node* root;
//    HashItem* exist;
//} MapSum;
//
//
//MapSum* mapSumCreate()
//{
//    MapSum* obj = (MapSum*)malloc(sizeof(MapSum));
//    obj->root = (Node*)calloc(1, sizeof(Node));
//    obj->exist = NULL;
//    return obj;
//}
//
//void mapSumInsert(MapSum* obj, char* key, int val)
//{
//    HashItem* p1 = NULL;
//    HASH_FIND_STR(obj->exist, key, p1);
//    if (p1)
//        val -= p1->val;
//    else
//    {
//        p1 = (HashItem*)malloc(sizeof(HashItem));
//        p1->key = key;
//        p1->val = 0;
//        HASH_ADD_STR(obj->exist, key, p1);
//    }
//    p1->val += val;
//
//    Node* cur = obj->root;
//    for (int i = 0; key[i]; i++)
//    {
//        int c = key[i] - 'a';
//        if (cur->son[c] == NULL)
//        {
//            cur->son[c] = (Node*)calloc(1, sizeof(Node));
//            cur->son[c]->val = 0;
//        }
//        cur->son[c]->val += val;
//        cur = cur->son[c];
//    }
//}
//
//int mapSumSum(MapSum* obj, char* prefix)
//{
//    Node* cur = obj->root;
//    for (int i = 0; prefix[i]; i++)
//    {
//        int c = prefix[i] - 'a';
//        if (cur->son[c] == NULL)
//            return 0;
//        cur = cur->son[c];
//    }
//    return cur->val;
//}
//
//void freeTrie(Node* node)
//{
//    if (node == NULL)
//        return;
//    for (int i = 0; i < 26; i++)
//    {
//        freeTrie(node->son[i]);
//    }
//    free(node);
//}
//
//void freeHash(HashItem* exist)
//{
//    HashItem* p1 = NULL, * tmp = NULL;
//    HASH_ITER(hh, exist, p1, tmp)
//    {
//        HASH_DEL(exist, p1);
//        free(p1);
//    }
//}
//
//void mapSumFree(MapSum* obj)
//{
//    freeTrie(obj->root);
//    freeHash(obj->exist);
//    free(obj);
//}
//
///**
// * Your MapSum struct will be instantiated and called as such:
// * MapSum* obj = mapSumCreate();
// * mapSumInsert(obj, key, val);
//
// * int param_2 = mapSumSum(obj, prefix);
//
// * mapSumFree(obj);
//*/
//
