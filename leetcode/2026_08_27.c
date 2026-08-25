//// 208. ÊµÏÖ Trie (Ç°×ºÊ÷)
//
//#define ALPHABET_SIZE 26
//typedef struct Node
//{
//    struct Node* son[ALPHABET_SIZE];
//    bool end;
//}Node;
//
//typedef struct
//{
//    Node* root;
//} Trie;
//
//
//Trie* trieCreate()
//{
//    Trie* obj = (Trie*)malloc(sizeof(Trie));
//    obj->root = calloc(1, sizeof(Node));
//    return obj;
//}
//
//void trieInsert(Trie* obj, char* word)
//{
//    Node* cur = obj->root;
//    for (int i = 0; word[i]; i++)
//    {
//        int c = word[i] - 'a';
//        if (cur->son[c] == NULL)
//            cur->son[c] = (Node*)calloc(1, sizeof(Node));
//        cur = cur->son[c];
//    }
//    cur->end = true;
//}
//
//int trieFind(Trie* obj, char* word)
//{
//    Node* cur = obj->root;
//    for (int i = 0; word[i]; i++)
//    {
//        int c = word[i] - 'a';
//        if (cur->son[c] == NULL)
//            return 0;
//        cur = cur->son[c];
//    }
//    return cur->end ? 2 : 1;
//}
//bool trieSearch(Trie* obj, char* word)
//{
//    return trieFind(obj, word) == 2;
//}
//
//bool trieStartsWith(Trie* obj, char* prefix)
//{
//    return trieFind(obj, prefix);
//}
//
//void trieNodeFree(Node* node)
//{
//    if (node == NULL) return;
//    for (int i = 0; i < ALPHABET_SIZE; i++)
//    {
//        trieNodeFree(node->son[i]);
//    }
//    free(node);
//}
//
//void trieFree(Trie* obj)
//{
//    trieNodeFree(obj->root);
//    free(obj);
//}
//
///**
// * Your Trie struct will be instantiated and called as such:
// * Trie* obj = trieCreate();
// * trieInsert(obj, word);
//
// * bool param_2 = trieSearch(obj, word);
//
// * bool param_3 = trieStartsWith(obj, prefix);
//
// * trieFree(obj);
//*/
//
