//// 684. ÈßÓàÁ¬½Ó
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int Find(int* parent, int index)
//{
//    if (parent[index] != index)
//        parent[index] = Find(parent, parent[index]);
//
//    return parent[index];
//}
//void Union(int* parent, int index1, int index2)
//{
//    parent[Find(parent, index1)] = Find(parent, index2);
//}
//int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize)
//{
//    int n = edgesSize;
//    int parent[n + 1];
//    for (int i = 0; i <= n; i++)
//    {
//        parent[i] = i;
//    }
//    *returnSize = 2;
//    for (int i = 0; i < n; i++)
//    {
//        int node1 = edges[i][0];
//        int node2 = edges[i][1];
//        if (Find(parent, node1) != Find(parent, node2))
//            Union(parent, node1, node2);
//        else
//            return edges[i];
//    }
//    *returnSize = 0;
//    return NULL;
//}
//
