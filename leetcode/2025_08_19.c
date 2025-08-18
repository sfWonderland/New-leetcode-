////2348. 全 0 子数组的数目
//
//long long zeroFilledSubarray(int* nums, int numsSize)
//{
//	long long ans = 0;
//	int cnt0 = 0;
//	for (int i = 0; i < numsSize; i++)
//	{
//		if (nums[i])
//			cnt0 = 0;
//		else
//		{
//			cnt0++;
//			ans += cnt0;
//		}
//	}
//	return ans;
//}
//
////73. 矩阵置零
//
//void setZeroes(int** matrix, int matrixSize, int* matrixColSize)
//{
//	int m = matrixSize, n = matrixColSize[0];
//	bool col0 = false;
//	for (int i = 0; i < m; i++)
//	{
//		if (!matrix[i][0]) col0 = true;
//		for (int j = 1; j < n; j++)
//		{
//			if (!matrix[i][j])
//				matrix[i][0] = matrix[0][j] = 0;
//		}
//	}
//	for (int i = 1; i < m; i++)
//	{
//		for (int j = 1; j < n; j++)
//		{
//			if (!matrix[i][0] || !matrix[0][j])
//				matrix[i][j] = 0;
//		}
//	}
//	if (!matrix[0][0])
//	{
//		for (int j = 1; j < n; j++)
//			matrix[0][j] = 0;
//	}
//	if (col0)
//	{
//		for (int i = 0; i < m; i++)
//			matrix[i][0] = 0;
//	}
//}
//
////76. 最小覆盖子串
//
//bool check_valid(int* cntS, int* cntT)
//{
//	for (int i = 'A'; i <= 'Z'; i++)
//	{
//		if (cntS[i] < cntT[i])
//			return false;
//	}
//	for (int i = 'a'; i <= 'z'; i++)
//	{
//		if (cntS[i] < cntT[i])
//			return false;
//	}
//	return true;
//}
//char* minWindow(char* s, char* t)
//{
//	int cntT[123] = { 0 };
//	for (int i = 0; t[i]; i++)
//	{
//		cntT[t[i]]++;
//	}
//	int n = strlen(s);
//	int cntS[123] = { 0 };
//	int ansLeft = -1, ansRight = n;
//	int left = 0;
//	for (int i = 0; s[i]; i++)
//	{
//		cntS[s[i]]++;
//		while (check_valid(cntS, cntT))
//		{
//			if (i - left < ansRight - ansLeft)
//			{
//				ansLeft = left;
//				ansRight = i;
//			}
//			cntS[s[left]]--;
//			left++;
//		}
//	}
//	if (ansLeft < 0)
//		return "";
//	else
//	{
//		s[ansRight + 1] = '\0';
//		return s + ansLeft;
//	}
//}
//
//char* minWindow(char* s, char* t)
//{
//	int cnt[123] = { 0 }, less = 0;
//	for (int i = 0; t[i]; i++)
//	{
//		if (cnt[t[i]] == 0)
//			less++;
//
//		cnt[t[i]]++;
//	}
//	int n = strlen(s);
//	int ansLeft = -1, ansRight = n;
//	int left = 0;
//	for (int i = 0; s[i]; i++)
//	{
//		cnt[s[i]]--;
//		if (cnt[s[i]] == 0) less--;
//		while (less == 0)
//		{
//			if (i - left < ansRight - ansLeft)
//			{
//				ansLeft = left;
//				ansRight = i;
//			}
//			cnt[s[left]]++;
//			if (cnt[s[left]] > 0) less++;
//			left++;
//		}
//	}
//	if (ansLeft < 0)
//		return "";
//	else
//	{
//		s[ansRight + 1] = '\0';
//		return s + ansLeft;
//	}
//}
//
////2861. 最大合金数
//
//bool check(int n, int budget, int* composition, int* stock, int* cost, int num)
//{
//	long long money = 0;
//	for (int i = 0; i < n; i++)
//	{
//		long long gap = 1ll * num * composition[i] - stock[i];
//		if (gap > 0)
//			money += gap * cost[i];
//		if (1ll * budget < money) return false;
//	}
//	return true;
//}
//int maxNumberOfAlloys(int n, int k, int budget, int** composition, int compositionSize, int* compositionColSize, int* stock, int stockSize, int* cost, int costSize)
//{
//	int ans = 0, mx = budget;
//	int min_st = INT_MAX;
//	for (int i = 0; i < n; i++)
//	{
//		min_st = fmin(min_st, stock[i]);
//	}
//	mx += min_st;
//	for (int i = 0; i < k; i++)
//	{
//		int left = 0, right = mx + 1;
//		while (left + 1 < right) //开区间
//		{
//			int mid = left + (right - left) / 2;
//			if (check(n, budget, composition[i], stock, cost, mid)) left = mid;
//			else right = mid;
//		}
//		ans = fmax(ans, left);
//	}
//	return ans;
//}
//
