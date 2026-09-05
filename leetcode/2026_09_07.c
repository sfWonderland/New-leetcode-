//// 212. µ¥´ÊËÑË÷ II
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//
//const int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//
//typedef struct
//{
//    char* key;
//    UT_hash_handle hh;
//}HashItem;
//
//typedef struct Node
//{
//    struct Node* son[26];
//    char* s;
//}Node;
//
//void insert(Node* root, char* word)
//{
//    Node* cur = root;
//    for (int i = 0; word[i]; i++)
//    {
//        int c = word[i] - 'a';
//        if (cur->son[c] == NULL)
//            cur->son[c] = (Node*)calloc(1, sizeof(Node));
//        cur = cur->son[c];
//    }
//    cur->s = word;
//}
//
//char** findWords(char** board, int boardSize, int* boardColSize, char** words, int wordsSize, int* returnSize)
//{
//    Node* root = (Node*)calloc(1, sizeof(Node));
//    HashItem* fWords = NULL;
//    int m = boardSize, n = boardColSize[0];
//    for (int i = 0; i < wordsSize; i++)
//    {
//        insert(root, words[i]);
//    }
//    bool vis[m][n];
//    memset(vis, 0, sizeof(vis));
//    int ansSize = 0;
//    void dfs(int x, int y, Node * node)
//    {
//        HashItem* p1 = NULL;
//        if (node->s != NULL)
//        {
//            HASH_FIND_STR(fWords, node->s, p1);
//            if (p1 == NULL)
//            {
//                p1 = (HashItem*)malloc(sizeof(HashItem));
//                p1->key = node->s;
//                HASH_ADD_STR(fWords, key, p1);
//                ansSize++;
//            }
//        }
//        for (int k = 0; k < 4; k++)
//        {
//            int mx = x + dir[k][0];
//            int my = y + dir[k][1];
//            if (mx < 0 || mx >= m || my < 0 || my >= n || vis[mx][my])
//                continue;
//            int c = board[mx][my] - 'a';
//            if (node->son[c] != NULL)
//            {
//                vis[mx][my] = true;
//                dfs(mx, my, node->son[c]);
//                vis[mx][my] = false;
//            }
//        }
//    }
//
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            int c = board[i][j] - 'a';
//            if (root->son[c] != NULL)
//            {
//                vis[i][j] = true;
//                dfs(i, j, root->son[c]);
//                vis[i][j] = false;
//            }
//        }
//    }
//    char** ans = (char**)malloc(sizeof(char*) * ansSize);
//    HashItem* p0 = NULL, * tmp = NULL;
//    *returnSize = 0;
//    HASH_ITER(hh, fWords, p0, tmp)
//    {
//        ans[(*returnSize)++] = p0->key;
//        HASH_DEL(fWords, p0);
//        free(p0);
//    }
//    return ans;
//}
//
