//// 676. 实现一个魔法字典
//
//typedef struct Node
//{
//    struct Node* son[26];
//    bool end;
//}Node;
//
//
//typedef struct
//{
//    Node* root;
//} MagicDictionary;
//
//MagicDictionary* magicDictionaryCreate()
//{
//    MagicDictionary* obj = (MagicDictionary*)malloc(sizeof(MagicDictionary));
//    obj->root = (Node*)calloc(1, sizeof(Node));
//    return obj;
//}
//
//void magicDictionaryBuildDict(MagicDictionary* obj, char** dictionary, int dictionarySize)
//{
//    for (int i = 0; i < dictionarySize; i++)
//    {
//        Node* cur = obj->root;
//        char* word = dictionary[i];
//        for (int i = 0; word[i]; i++)
//        {
//            int c = word[i] - 'a';
//            if (cur->son[c] == NULL)
//            {
//                cur->son[c] = (Node*)calloc(1, sizeof(Node));
//            }
//            cur = cur->son[c];
//        }
//        cur->end = true;
//    }
//}
//
//bool magicDictionaryFind(Node* root, char* word, int change)
//{
//    Node* cur = root;
//    for (int i = 0; word[i]; i++)
//    {
//        int c = word[i] - 'a';
//        if (i != change)
//        {
//            if (cur->son[c] == NULL)
//                return false;
//
//            cur = cur->son[c];
//        }
//        else
//        {
//            for (int j = 0; j < 26; j++)
//            {
//                if (j == c || cur->son[j] == NULL)
//                    continue;
//                if (magicDictionaryFind(cur->son[j], word + i + 1, -1))
//                    return true;
//            }
//            return false;
//        }
//    }
//    return cur->end;
//}
//
//bool magicDictionarySearch(MagicDictionary* obj, char* searchWord)
//{
//    for (int i = 0; searchWord[i]; i++)
//    {
//        if (magicDictionaryFind(obj->root, searchWord, i))
//            return true;
//    }
//    return false;
//}
//
//void freeTrie(Node* node)
//{
//    if (node == NULL) return;
//    for (int i = 0; i < 26; i++)
//    {
//        freeTrie(node->son[i]);
//    }
//    free(node);
//}
//
//void magicDictionaryFree(MagicDictionary* obj)
//{
//    freeTrie(obj->root);
//    free(obj);
//}
//
///**
// * Your MagicDictionary struct will be instantiated and called as such:
// * MagicDictionary* obj = magicDictionaryCreate();
// * magicDictionaryBuildDict(obj, dictionary, dictionarySize);
//
// * bool param_2 = magicDictionarySearch(obj, searchWord);
//
// * magicDictionaryFree(obj);
//*/
//
//// 211. 添加与搜索单词 - 数据结构设计
//
//typedef struct Node
//{
//    struct Node* son[26];
//    bool end;
//}Node;
//
//
//typedef struct
//{
//    Node* root;
//} WordDictionary;
//
//
//WordDictionary* wordDictionaryCreate()
//{
//    WordDictionary* obj = (WordDictionary*)malloc(sizeof(WordDictionary));
//    obj->root = (Node*)calloc(1, sizeof(Node));
//    return obj;
//}
//
//void wordDictionaryAddWord(WordDictionary* obj, char* word)
//{
//    Node* cur = obj->root;
//    for (int i = 0; word[i]; i++)
//    {
//        int c = word[i] - 'a';
//        if (cur->son[c] == NULL)
//        {
//            cur->son[c] = (Node*)calloc(1, sizeof(Node));
//        }
//        cur = cur->son[c];
//    }
//    cur->end = true;
//}
//
//bool wordDictionaryFind(Node* root, char* word)
//{
//    Node* cur = root;
//    for (int i = 0; word[i]; i++)
//    {
//        if (word[i] != '.')
//        {
//            int c = word[i] - 'a';
//            if (cur->son[c] == NULL)
//                return false;
//            cur = cur->son[c];
//        }
//        else
//        {
//            bool flag = false;
//            for (int j = 0; j < 26 && !flag; j++)
//            {
//                if (cur->son[j] == NULL)
//                    continue;
//                flag |= wordDictionaryFind(cur->son[j], word + i + 1);
//            }
//            return flag;
//        }
//    }
//    return cur->end;
//}
//
//bool wordDictionarySearch(WordDictionary* obj, char* word)
//{
//    return wordDictionaryFind(obj->root, word);
//}
//
//void freeTrie(Node* node)
//{
//    if (node == NULL) return;
//    for (int i = 0; i < 26; i++)
//    {
//        freeTrie(node->son[i]);
//    }
//    free(node);
//}
//
//void wordDictionaryFree(WordDictionary* obj)
//{
//    freeTrie(obj->root);
//}
//
///**
// * Your WordDictionary struct will be instantiated and called as such:
// * WordDictionary* obj = wordDictionaryCreate();
// * wordDictionaryAddWord(obj, word);
//
// * bool param_2 = wordDictionarySearch(obj, word);
//
// * wordDictionaryFree(obj);
//*/
//
