////2744. 最大字符串配对数目
//
//int maximumNumberOfStringPairs(char** words, int wordsSize)
//{
//    int ans = 0;
//    for (int i = 0; i < wordsSize - 1; i++)
//    {
//        for (int j = i + 1; j < wordsSize; j++)
//        {
//            if (words[i][0] == words[j][1] && words[i][1] == words[j][0])
//                ans++;
//        }
//    }
//    return ans;
//}
//
////2079. 给植物浇水
//
//int wateringPlants(int* plants, int plantsSize, int capacity)
//{
//    int steps = 0, val = capacity;
//    for (int i = 0; i < plantsSize; i++)
//    {
//        if (val >= plants[i])
//        {
//            val -= plants[i];
//            steps++;
//        }
//        else
//        {
//            val = capacity - plants[i];
//            steps += 2 * i + 1;
//        }
//        //printf("%d ", steps);
//    }
//    return steps;
//}
//
////3452. 好数字之和
//
//int sumOfGoodNumbers(int* nums, int numsSize, int k)
//{
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if ((i < k || nums[i] > nums[i - k]) && (i > numsSize - 1 - k || nums[i] > nums[i + k]))
//            ans += nums[i];
//    }
//    return ans;
//}
//
////3190. 使所有元素都可以被 3 整除的最少操作数
//
//int minimumOperations(int* nums, int numsSize)
//{
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] % 3)
//            ans++;
//    }
//    return ans;
//}
//
