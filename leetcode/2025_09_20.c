////������ 16.24. ���Ժ�
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    int key;
//    UT_hash_handle hh;
//}Hash;
//int** pairSums(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) 
//{
//    Hash* hash = NULL;
//    Hash* s = NULL;
//    int** ans = (int**)malloc(sizeof(int*) * (numsSize / 2));
//    *returnColumnSizes = (int*)malloc(sizeof(int) * (numsSize / 2));
//    int idx = 0;
//    for(int i = 0; i < numsSize; i++)
//    {
//        int tmp = target - nums[i];
//        HASH_FIND_INT(hash, &tmp, s);
//        if(s == NULL)
//        {
//            s = (Hash*)malloc(sizeof(Hash));
//            s -> key = nums[i];
//            HASH_ADD_INT(hash, key, s);
//        }
//        else
//        {
//            ans[idx] = (int*)malloc(sizeof(int) * 2);
//            ans[idx][0] = s -> key;
//            ans[idx][1] = nums[i];
//            (*returnColumnSizes)[idx++] = 2;
//            HASH_DEL(hash, s);
//            free(s);
//        }
//    }
//    *returnSize = idx;
//    return ans;
//}
//
////3623. ͳ�����ε���Ŀ I
//
//// ��ϣ��ڵ�ṹ
//typedef struct HashNode {
//    int key;           // �洢y����
//    int count;         // ��y�����ϵĵ�����
//    struct HashNode* next;  // �����ϣ��ͻ������
//} HashNode;
//
//// ��ϣ��ṹ
//typedef struct {
//    HashNode** buckets;  // Ͱ����
//    int size;            // Ͱ������
//} HashTable;
//
//// ������ϣ��
//HashTable* createHashTable(int size) {
//    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
//    ht->size = size;
//    ht->buckets = (HashNode**)calloc(size, sizeof(HashNode*));
//    return ht;
//}
//
//// ��ϣ����
//int hashFunction(int key, int size) {
//    // �򵥵Ĺ�ϣ������ȷ������ֵΪ�Ǹ���
//    return (key % size + size) % size;
//}
//
//// �������¹�ϣ��
//void insertOrUpdate(HashTable* ht, int key) {
//    int index = hashFunction(key, ht->size);
//    HashNode* current = ht->buckets[index];
//    
//    // �����Ƿ��Ѵ��ڸ�key
//    while (current != NULL) {
//        if (current->key == key) {
//            current->count++;  // �ҵ��������1
//            return;
//        }
//        current = current->next;
//    }
//    
//    // �������򴴽��½ڵ�
//    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
//    newNode->key = key;
//    newNode->count = 1;
//    newNode->next = ht->buckets[index];  // ͷ�巨
//    ht->buckets[index] = newNode;
//}
//
//// �ͷŹ�ϣ���ڴ�
//void freeHashTable(HashTable* ht) {
//    for (int i = 0; i < ht->size; i++) {
//        HashNode* current = ht->buckets[i];
//        while (current != NULL) {
//            HashNode* temp = current;
//            current = current->next;
//            free(temp);
//        }
//    }
//    free(ht->buckets);
//    free(ht);
//}
//
//int countTrapezoids(int**points, int pointsSize, int* pointsColSize) {
//    const int MOD = 1000000007;
//  HashTable* ht = createHashTable(pointsSize*2);
//  for(int i=0;i<pointsSize;i++){
//    int u=points[i][1];
//    insertOrUpdate(ht,u);
//  }
//  long long ans=0,s=0;
//
//  for(int i=0;i<ht->size;i++){
//    HashNode* current = ht->buckets[i];
//    while(current){
//        int c=current->count;
//        long long k=(long long)c*(c-1)/2;
//        ans += k*s;
//        s+=k;
//        current = current->next;
//    }
//  }
//  return (int)(ans%MOD);
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}Hash;
//int countTrapezoids(int** points, int pointsSize, int* pointsColSize) 
//{
//    Hash* hash = NULL;
//    Hash* s = NULL;
//    for(int i = 0; i < pointsSize; i++)
//    {
//        int tmp = points[i][1];
//        HASH_FIND_INT(hash, &tmp, s);
//        if(s == NULL)
//        {
//            s = (Hash*)malloc(sizeof(Hash));
//            s -> key = tmp;
//            s -> val = 1;
//            HASH_ADD_INT(hash, key, s);
//        }
//        else
//        s -> val++;
//    }
//    long long ans = 0, pre = 0;
//    s = NULL;
//    Hash* tmp = NULL;
//    HASH_ITER(hh, hash, s, tmp)
//    {
//        long long cnt = s -> val;
//        long long combinations = cnt * (cnt - 1) / 2;
//        ans += combinations * pre;
//        pre += combinations;
//    }
//    HASH_ITER(hh, hash, s, tmp)
//    {
//        HASH_DEL(hash, s);
//        free(s);
//    }
//    int mod = 1e9 + 7;
//    return ans % mod;
//}
//
////3371. ʶ�������е�����쳣ֵ
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}Hash;
//int getLargestOutlier(int* nums, int numsSize) 
//{
//    Hash* hash = NULL;
//    Hash* s = NULL;
//    int total = 0;
//    for(int i = 0; i < numsSize; i++)
//    {
//        HASH_FIND_INT(hash, &nums[i], s);
//        if(s == NULL)
//        {
//            s = (Hash*)malloc(sizeof(Hash));
//            s -> key = nums[i];
//            s -> val = 1;
//            HASH_ADD_INT(hash, key, s);
//        }
//        else
//        s -> val++;
//
//        total += nums[i];
//    }
//    s = NULL;
//    Hash* tmp = NULL;
//    int ans = INT_MIN;
//    HASH_ITER(hh, hash, s, tmp)
//    {
//        int x = s -> key;
//        if((total - x) % 2 == 0)
//        {
//            int y = (total - x) / 2;
//            if(x == y)
//            {
//                if(s -> val > 1)
//                ans = fmax(x, ans);
//                continue;
//            }
//            Hash* get_y = NULL;
//            HASH_FIND_INT(hash, &y, get_y);
//            if(get_y) 
//            ans = fmax(x, ans);
//        }
//    }
//    HASH_ITER(hh, hash, s, tmp)
//    {
//        HASH_DEL(hash, s);
//        free(s);
//    }
//    return ans;
//}
//
////624. �����б��е�������
//
//int maxDistance(int** arrays, int arraysSize, int* arraysColSize) 
//{
//    int min = 10001, max = -10001;
//    int ans = 0;
//    for(int i = 0; i < arraysSize; i++)
//    {
//        int x = arrays[i][0];
//        int y = arrays[i][arraysColSize[i] - 1];
//        ans = fmax(ans, y - min);
//        ans = fmax(ans, max - x);
//        min = fmin(min, x);
//        max = fmax(max, y);
//    }    
//    return ans;
//}
//
