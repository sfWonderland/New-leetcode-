//// 2416. 字符串的前缀分数和
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//#define ALPHABET_SIZE 26
//
//typedef struct Node
//{
//    struct Node* son[ALPHABET_SIZE];
//    int cnt;
//}Node;
//
//void TrieInsert(Node* root, char* s)
//{
//    Node* cur = root;
//    for (int i = 0; s[i]; i++)
//    {
//        int c = s[i] - 'a';
//        if (cur->son[c] == NULL)
//        {
//            cur->son[c] = (Node*)calloc(1, sizeof(Node));
//            cur->son[c]->cnt = 0;
//        }
//        cur->son[c]->cnt++;
//        cur = cur->son[c];
//    }
//}
//
//int getScore(Node* root, char* s)
//{
//    Node* cur = root;
//    int res = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        int c = s[i] - 'a';
//        if (cur->son[c] == NULL)
//            break;
//        res += cur->son[c]->cnt;
//        cur = cur->son[c];
//    }
//    return res;
//}
//
//void TrieFree(Node* node)
//{
//    if (node == NULL) return;
//    for (int i = 0; i < ALPHABET_SIZE; i++)
//    {
//        TrieFree(node->son[i]);
//    }
//    free(node);
//}
//
//int* sumPrefixScores(char** words, int wordsSize, int* returnSize)
//{
//    Node* root = (Node*)calloc(1, sizeof(Node));
//    for (int i = 0; i < wordsSize; i++)
//    {
//        TrieInsert(root, words[i]);
//    }
//    int* ans = (int*)malloc(sizeof(int) * wordsSize);
//    for (int i = 0; i < wordsSize; i++)
//    {
//        ans[i] = getScore(root, words[i]);
//    }
//    TrieFree(root);
//    *returnSize = wordsSize;
//    return ans;
//}
//
