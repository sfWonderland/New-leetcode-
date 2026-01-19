////3813. 元音辅音得分
//
//const bool vow[26] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
//int vowelConsonantScore(char* s) 
//{
//    int v = 0, c = 0;
//    for(int i = 0; s[i]; i++)
//    {
//        if(s[i] >= 'a')
//        {
//            v += vow[s[i] - 'a'];
//            c += 1 - vow[s[i] - 'a'];
//        }
//    }
//    return c ? v / c : 0;
//}
//
////3814. 预算下的最大总容量    
//
//int* arr;
//int cmp(const void* e1, const void* e2)
//{
//    int a = *(int*)e1, b = *(int*)e2;
//    return arr[a] - arr[b];
//}
//int binary_search(int* nums, int* idx, int n, int x)
//{
//    int left = 0, right = n - 1;
//    while(left <= right)
//    {
//        int mid = (left + right) / 2;
//        if(nums[idx[mid]] >= x)
//            right--;
//        else
//            left++;
//    }
//    return left;
//}
//int maxCapacity(int* costs, int costsSize, int* capacity, int capacitySize, int budget) {
//    arr = costs;
//    int* idx = (int*)malloc(sizeof(int) * costsSize);
//    int n = 0;
//    for(int i = 0; i < costsSize; i++)
//    {
//        if(costs[i] < budget)
//        idx[n++] = i;
//    }
//    if(n < 1)
//        return 0;
//    qsort(idx, n, sizeof(int), cmp);
//    int ans = 0;
//    int* st = (int*)malloc(sizeof(int) * n);
//    int m = -1;
//    for (int i = 0; i < n; i++) 
//    {
//        int x = capacity[idx[i]], y = costs[idx[i]];
//        while(m >= 0 && y + costs[st[m]] >= budget)
//        m--;
//
//        int sum = m >= 0 ? x + capacity[st[m]] : x;
//        ans = fmax(ans, sum); // j == 0单选机器
//        if(m < 0 || x > capacity[st[m]])
//        st[++m] = idx[i];
//    }
//    return ans;
//}
//
////1895. 最大的幻方
//
//int largestMagicSquare(int** grid, int gridSize, int* gridColSize) {
//    int m = gridSize, n = gridColSize[0];
//
//    int** rowSum = (int**)malloc(sizeof(int*) * m);
//    int** colSum = (int**)malloc(sizeof(int*) * (m + 1));
//    int** diagSum = (int**)malloc(sizeof(int*) * (m + 1));
//    int** antiSum = (int**)malloc(sizeof(int*) * (m + 1));
//    for(int i = 0; i < m; i++){
//        rowSum[i] = (int*)calloc(sizeof(int), n + 1);
//        colSum[i] = (int*)calloc(sizeof(int), n);
//        diagSum[i] = (int*)calloc(sizeof(int),n + 1);
//        antiSum[i] = (int*)calloc(sizeof(int), n + 1);
//    }
//    colSum[m] = (int*)calloc(sizeof(int), n);
//    diagSum[m] = (int*)calloc(sizeof(int), (n + 1));
//    antiSum[m] = (int*)calloc(sizeof(int), (n + 1));
//
//    for(int i = 0; i < m; i++){
//        for(int j = 0; j < n; j++){
//            rowSum[i][j + 1] = rowSum[i][j] + grid[i][j];
//            colSum[i + 1][j] = colSum[i][j] + grid[i][j];
//            diagSum[i + 1][j + 1] = diagSum[i][j] + grid[i][j];
//            antiSum[i + 1][j] = antiSum[i][j + 1] + grid[i][j];
//        }
//    }
//
//    for(int k = fmin(m, n); k >= 0; k--){
//        for(int i = k; i <= m; i++){
//            for(int j = k; j <= n; j++){
//                int sum = diagSum[i][j] - diagSum[i - k][j - k];
//                if(sum != antiSum[i][j - k] - antiSum[i - k][j])
//                continue;
//                bool flag = true;
//                for(int r = i - k; r < i && flag; r++){
//                    if(rowSum[r][j] - rowSum[r][j - k] != sum)
//                    flag = false;
//                }
//                if(!flag) continue;
//                for(int c = j - k; c < j && flag; c++){
//                    if(colSum[i][c] - colSum[i - k][c] != sum)
//                    flag = false;
//                }
//                if(flag) return k;
//            }
//        }
//    }
//    return 0;
//}
//
////3200. 三角形的最大高度
//
//int getMax(int x, int a0)
//{
//    int left = 1, right = 10;
//    while(left <= right)
//    {
//        int mid = (left + right) / 2;
//        if((mid - 1 + a0) * mid > x)
//        right = mid - 1;
//        else
//        left = mid + 1;
//    }
//    return left;
//}
//int getDepth(int fir, int sec)
//{
//    int n = getMax(fir, 1) - 1;
//    int m = getMax(sec, 2) - 1;
//    return m >= n ? 2 * n : 2 * m + 1;
//}
//int maxHeightOfTriangle(int red, int blue) 
//{
//    return fmax(getDepth(red, blue), getDepth(blue, red));    
//}
//
//int getDepth(int fir, int sec)
//{
//    int n = sqrt(fir);
//    int m = (sqrt(4 * sec + 1) - 1) / 2;
//    return m >= n ? 2 * n : 2 * m + 1;
//}
//int maxHeightOfTriangle(int red, int blue) 
//{
//    return fmax(getDepth(red, blue), getDepth(blue, red));    
//}
//
