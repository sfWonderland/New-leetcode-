//// 820. µ¥´ÊµÄÑ¹Ëõ±àÂë
//
//typedef struct Node
//{
//    struct Node* son[26];
//    int cnt;
//}Node;
//
//typedef struct
//{
//    Node* key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//
//int minimumLengthEncoding(char** words, int wordsSize)
//{
//    int n = wordsSize;
//    Node* root = (Node*)calloc(1, sizeof(Node));
//    // unordered_map<Node*, int> nodes;
//    int len[n];
//    HashItem* nodes = NULL;
//    for (int i = 0; i < n; ++i)
//    {
//        char* word = words[i];
//        len[i] = strlen(word);
//        Node* cur = root;
//        for (int j = len[i] - 1; j >= 0; --j)
//        {
//            int c = word[j] - 'a';
//            if (cur->son[c] == NULL)
//            {
//                cur->son[c] = (Node*)calloc(1, sizeof(Node));
//                cur->cnt++;
//            }
//            cur = cur->son[c];
//        }
//        HashItem* p1 = NULL;
//        HASH_FIND(hh, nodes, &cur, sizeof(Node*), p1);
//        if (p1 == NULL)
//        {
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = cur;
//            p1->val = i;
//            HASH_ADD(hh, nodes, key, sizeof(Node*), p1);
//        }
//        // nodes[cur] = i;
//    }
//
//    int ans = 0;
//    HashItem* p0 = NULL, * tmp = NULL;
//    HASH_ITER(hh, nodes, p0, tmp)
//    {
//        Node* node = p0->key;
//        int idx = p0->val;
//        if (node->cnt == 0)
//            ans += len[idx] + 1;
//
//        HASH_DEL(nodes, p0);
//        free(p0);
//    }
//    return ans;
//}
//
