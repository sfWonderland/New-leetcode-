#define _CRT_SECURE_NO_WARNINGS

//561.数组拆分

int cmp_int(const void* e1, const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}
int arrayPairSum(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp_int);
    int ret = 0;
    for (int i = 0; i < numsSize; i += 2)
    {
        ret += nums[i];
    }
    return ret;
}

//1984.学生分数的最小差值

int cmp_int(const void* e1, const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}

int minimumDifference(int* nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), cmp_int);
    int ret = nums[numsSize - 1];
    for (int i = 0; i < numsSize - k + 1; i++)
    {
        //printf("i = %d\n", i);
        if (ret > nums[i + k - 1] - nums[i])
            ret = nums[i + k - 1] - nums[i];
    }
    return ret;
}

//2144.打折购买糖果的最小开销

int cmp_int(const void* e1, const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}

int minimumCost(int* cost, int costSize)
{
    qsort(cost, costSize, sizeof(int), cmp_int);
    int ret = 0;
    int i = 0;
    for (i = costSize - 1; i > 1; i -= 3)
    {
        //printf("i = %d\n", i);
        ret += cost[i] + cost[i - 1];
    }

    while (i >= 0)
    {
        ret += cost[i];
        i--;
    }
    return ret;
}

//575.分糖果

int distributeCandies(int* candyType, int candyTypeSize)
{
    int hash[200001] = { 0 };
    for (int i = 0; i < candyTypeSize; i++)
    {
        if (candyType[i] >= 0)
            hash[candyType[i]]++;
        else
            hash[candyType[i] + 200001]++;
    }

    int TypeNum = 0;
    for (int i = 0; i < 200001; i++)
    {
        if (hash[i])
            TypeNum++;
    }
    if (TypeNum > candyTypeSize / 2)
        return candyTypeSize / 2;
    else
        return TypeNum;
}

//3142.判断矩阵是否满足条件

bool satisfiesConditions(int** grid, int gridSize, int* gridColSize)
{
    //printf("grid[1][0] = %d\n", grid[1][0]);
    //printf("*gridColSize = %d\n", *gridColSize);
    //printf("gridSize = %d\n",gridSize);
    for (int i = 0; i < gridSize - 1; i++)
    {
        for (int j = 0; j <= (*gridColSize) - 1; j++)
        {
            if (grid[i][j] != grid[i + 1][j])
                return false;
        }
    }

    for (int j = 0; j < (*gridColSize) - 1; j++)
    {
        if (grid[0][j] == grid[0][j + 1])
            return false;
    }

    return true;
}


