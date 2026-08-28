//// 3597. ·Ö¸î×Ö·û´®
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct Node
//{
//    struct Node* son[26];
//}Node;
//char** partitionString(char* s, int* returnSize)
//{
//    int n = strlen(s);
//    char** ans = (char**)malloc(sizeof(char*) * n);
//    *returnSize = 0;
//    Node* root = (Node*)calloc(1, sizeof(Node));
//    Node* cur = root;
//    int left = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int c = s[i] - 'a';
//        if (cur->son[c] == NULL)
//        {
//            cur->son[c] = (Node*)calloc(1, sizeof(Node));
//            int len = i - left + 1;
//            ans[*returnSize] = (char*)malloc(sizeof(char) * (len + 1));
//            for (int j = 0; j < len; j++)
//            {
//                ans[*returnSize][j] = s[left + j];
//            }
//            ans[(*returnSize)++][len] = '\0';
//            left = i + 1;
//            cur = root; // reset
//        }
//        else
//            cur = cur->son[c];
//    }
//    return ans;
//}
//
//// 648. µ¥´ÊÌæ»»   
//
//typedef struct Node
//{
//    struct Node* son[26];
//    bool end;
//}Node;
//char* replaceWords(char** dictionary, int dictionarySize, char* sentence)
//{
//    Node* root = (Node*)calloc(1, sizeof(Node));
//    for (int i = 0; i < dictionarySize; i++)
//    {
//        Node* cur = root;
//        char* s = dictionary[i];
//        for (int j = 0; s[j]; j++)
//        {
//            int c = s[j] - 'a';
//            if (cur->son[c] == NULL)
//            {
//                cur->son[c] = (Node*)calloc(1, sizeof(Node));
//            }
//            cur = cur->son[c];
//        }
//        cur->end = true;
//    }
//    int m = strlen(sentence);
//    char* ans = (char*)malloc(sizeof(char) * (m + 1));
//    char* t = (char*)malloc(sizeof(char) * (m + 1));
//    ans[0] = '\0';
//    int offset = 0;
//    for (char* s = strtok(sentence, " "); s; s = strtok(NULL, " "))
//    {
//        bool exist = false;
//        Node* cur = root;
//        int len = strlen(s), j = 0;
//        for (; j < len; j++)
//        {
//            int c = s[j] - 'a';
//            if (cur->son[c] == NULL)
//                break;
//            cur = cur->son[c];
//            t[j] = s[j];
//            if (cur->end)
//            {
//                t[++j] = '\0';
//                exist = true;
//                break;
//            }
//        }
//        if (exist)
//            sprintf(ans + offset, "%s", t);
//        else
//            sprintf(ans + offset, "%s", s);
//
//        offset += exist ? j : len;
//        ans[offset++] = ' ';
//    }
//    ans[--offset] = '\0';
//    return ans;
//}
//
//typedef struct Node
//{
//    struct Node* son[26];
//    bool end;
//}Node;
//
//void insertTrie(Node* root, char* s)
//{
//    Node* cur = root;
//    for (int j = 0; s[j]; j++)
//    {
//        int c = s[j] - 'a';
//        if (cur->son[c] == NULL)
//        {
//            cur->son[c] = (Node*)calloc(1, sizeof(Node));
//        }
//        cur = cur->son[c];
//    }
//    cur->end = true;
//}
//
//int getString(Node* root, char* s, char* t)
//{
//    Node* cur = root;
//    for (int j = 0; s[j]; j++)
//    {
//        if (cur->end)
//        {
//            t[j] = '\0';
//            return j;
//        }
//        int c = s[j] - 'a';
//        if (cur->son[c] == NULL)
//            break;
//        cur = cur->son[c];
//        t[j] = s[j];
//    }
//    return 0;
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
//char* replaceWords(char** dictionary, int dictionarySize, char* sentence)
//{
//    Node* root = (Node*)calloc(1, sizeof(Node));
//    for (int i = 0; i < dictionarySize; i++)
//    {
//        insertTrie(root, dictionary[i]);
//    }
//    int m = strlen(sentence);
//    char* ans = (char*)malloc(sizeof(char) * (m + 1));
//    char* t = (char*)malloc(sizeof(char) * (m + 1));
//    ans[0] = '\0';
//    int offset = 0;
//    for (char* s = strtok(sentence, " "); s; s = strtok(NULL, " "))
//    {
//        bool exist = false;
//        Node* cur = root;
//        int lenS = strlen(s);
//        int lenJ = getString(root, s, t);
//
//        if (lenJ)
//            sprintf(ans + offset, "%s", t);
//        else
//            sprintf(ans + offset, "%s", s);
//
//        offset += lenJ ? lenJ : lenS;
//        ans[offset++] = ' ';
//    }
//    ans[--offset] = '\0';
//    freeTrie(root);
//    return ans;
//}
//
