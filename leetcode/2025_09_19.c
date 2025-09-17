////3484. 设计电子表格
//
//typedef struct
//{
//    int** sheet;
//    int row;
//} Spreadsheet;
//
//int get_num(char* formula, int* i, char sym)
//{
//    int x = 0;
//    while (formula[*i] != sym)
//    {
//        x *= 10;
//        x += formula[*i] - '0';
//        (*i)++;
//    }
//    return x;
//}
//int get_blank(Spreadsheet* obj, char* formula, int* t, char sym)
//{
//    int x = 0;
//    if (formula[*t] >= 'A')
//    {
//        int j = formula[*t] - 'A';
//        (*t)++;
//        int i = get_num(formula, t, sym);
//        x = obj->sheet[i][j];
//    }
//    else
//        x = get_num(formula, t, sym);
//    return x;
//}
//Spreadsheet* spreadsheetCreate(int rows)
//{
//    Spreadsheet* obj = (Spreadsheet*)malloc(sizeof(Spreadsheet));
//    obj->row = rows;
//    obj->sheet = (int**)malloc(sizeof(int*) * (rows + 1));
//    for (int i = 0; i <= rows; i++)
//    {
//        obj->sheet[i] = (int*)calloc(sizeof(int), 26);
//    }
//    return obj;
//}
//
//void spreadsheetSetCell(Spreadsheet* obj, char* cell, int value)
//{
//    int j = cell[0] - 'A';
//    int t = 1;
//    int i = get_num(cell, &t, 0);
//
//    obj->sheet[i][j] = value;
//}
//
//void spreadsheetResetCell(Spreadsheet* obj, char* cell)
//{
//    int j = cell[0] - 'A';
//    int t = 1;
//    int i = get_num(cell, &t, 0);
//
//    obj->sheet[i][j] = 0;
//}
//
//int spreadsheetGetValue(Spreadsheet* obj, char* formula)
//{
//    int t = 1;
//    int x = get_blank(obj, formula, &t, '+');
//    t++;
//    int y = get_blank(obj, formula, &t, 0);
//    return x + y;
//}
//
//void spreadsheetFree(Spreadsheet* obj)
//{
//    for (int i = 0; i < obj->row; i++)
//    {
//        free(obj->sheet[i]);
//    }
//    free(obj->sheet);
//    free(obj);
//}
//
///**
// * Your Spreadsheet struct will be instantiated and called as such:
// * Spreadsheet* obj = spreadsheetCreate(rows);
// * spreadsheetSetCell(obj, cell, value);
//
// * spreadsheetResetCell(obj, cell);
//
// * int param_3 = spreadsheetGetValue(obj, formula);
//
// * spreadsheetFree(obj);
//*/
//
////2001. 可互换矩形的组数
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(double*)e1 > *(double*)e2;
//}
//long long interchangeableRectangles(int** rectangles, int rectanglesSize, int* rectanglesColSize)
//{
//    int n = rectanglesSize;
//    double* res = (double*)malloc(sizeof(double) * n);
//    for (int i = 0; i < n; i++)
//    {
//        res[i] = 1.0 * rectangles[i][0] / rectangles[i][1];
//    }
//    qsort(res, n, sizeof(double), cmp);
//    long long sum = 0, cnt = 0;
//    for (int i = 0; i < n - 1; i++)
//    {
//        if (res[i + 1] - res[i] < 1e-8)
//            cnt++;
//        else
//        {
//            sum += cnt * (cnt + 1) / 2;
//            cnt = 0;
//        }
//    }
//    if (cnt > 0)
//        sum += cnt * (cnt + 1) / 2;
//    return sum;
//}
//
////2260. 必须拿起的最小连续卡牌数
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}Map;
//Map* map;
//int minimumCardPickup(int* cards, int cardsSize)
//{
//    map = NULL;
//    Map* tmp = NULL;
//    int min = cardsSize + 1;
//    for (int i = 0; i < cardsSize; i++)
//    {
//        HASH_FIND_INT(map, &cards[i], tmp);
//        if (tmp == NULL)
//        {
//            tmp = (Map*)malloc(sizeof(Map));
//            tmp->key = cards[i];
//            tmp->val = i;
//            HASH_ADD_INT(map, key, tmp);
//        }
//        else
//        {
//            min = fmin(min, i - tmp->val + 1);
//            tmp->val = i;
//        }
//    }
//    return min > cardsSize ? -1 : min;
//}
//
////1679. K 和数对的最大数目
//
//typedef struct
//{
//    int key;
//    UT_hash_handle hh;
//}Map;
//int maxOperations(int* nums, int numsSize, int k)
//{
//    Map* map = NULL;
//    Map* tmp = NULL;
//    int times = 0;
//    int t = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        t = k - nums[i];
//        HASH_FIND_INT(map, &t, tmp);
//        if (tmp == NULL)
//        {
//            tmp = (Map*)malloc(sizeof(Map));
//            tmp->key = nums[i];
//            HASH_ADD_INT(map, key, tmp);
//        }
//        else
//        {
//            times++;
//            HASH_DEL(map, tmp);
//            free(tmp);
//        }
//    }
//    free(map);
//    return times;
//}
//
