//// 720. 词典中最长的单词
//
//typedef struct Node
//{
//    struct Node* son[26];
//}Node;
//
//int cmp(const void* e1, const void* e2)
//{
//    return strlen(*(char**)e1) - strlen(*(char**)e2);
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
//char* longestWord(char** words, int wordsSize)
//{
//    int n = wordsSize;
//    qsort(words, n, sizeof(char*), cmp);
//    Node* root = (Node*)calloc(1, sizeof(Node));
//    int max = 0;
//    char* ans = NULL;
//    for (int i = 0; i < n; i++)
//    {
//        char* s = words[i];
//        Node* cur = root;
//        for (int j = 0; s[j]; j++)
//        {
//            int c = s[j] - 'a';
//            if (cur->son[c] == NULL)
//            {
//                if (s[j + 1])
//                    break;
//
//                cur->son[c] = (Node*)calloc(1, sizeof(Node));
//                if (max < j + 1)
//                {
//                    max = j + 1;
//                    ans = s;
//                }
//                else
//                    ans = strcmp(ans, s) > 0 ? s : ans;
//
//                break;
//            }
//            cur = cur->son[c];
//        }
//    }
//    freeTrie(root);
//    return ans ? ans : "";
//}
//
