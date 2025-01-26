//#define _CRT_SECURE_NO_WARNINGS
//
////744.寻找比目标字母大的最小字母
//
//char nextGreatestLetter(char* letters, int lettersSize, char target) 
//{
//    int ret = INT_MAX;
//    for(int i = 0; i < lettersSize; i++)
//    {
//        if(letters[i] > target && letters[i] < ret)
//        ret = letters[i];
//    }
//    if(INT_MAX == ret)
//    return letters[0];
//    else
//    return ret;
//}
//
////2148.元素计数
//
//int countElements(int* nums, int numsSize) 
//{
//    int min = INT_MAX;
//    int max = INT_MIN;
//    for(int i = 0; i < numsSize; i++)
//    {
//        if(min > nums[i])
//        min = nums[i];
//        if(max < nums[i])
//        max = nums[i];
//    }
//
//    int n = numsSize;
//    for(int i = 0; i < numsSize; i++)
//    {
//        if(nums[i] == min || nums[i] == max)
//        n--;
//    }
//
//    return n;
//}
//
////747.至少是其他数字两倍的最大数
//
//int dominantIndex(int* nums, int numsSize) 
//{
//    int max = INT_MIN;
//    int index = 0;
//    for(int i = 0; i < numsSize; i++)
//    {
//        if(max < nums[i])
//        {
//            max = nums[i];
//            index = i;
//        }
//    }
//
//    for(int i = 0; i < numsSize; i++)
//    {
//        if(nums[i] != max && 2 * nums[i] > max)
//        return -1;
//    }
//
//    return index;
//}
//
////2154.将找到的值乘以2
//
//int findFinalValue(int* nums, int numsSize, int original) 
//{
//    for(int i = 0; i < numsSize; i++)
//    {
//        if(nums[i] == original)
//        {
//            original *= 2;
//            return findFinalValue(nums, numsSize, original);
//        }
//    }
//    return original;
//}
//
////1346.检查整数及其二倍数是否存在
//
//bool checkIfExist(int* arr, int arrSize) 
//{
//    int hash[2001] = {0};
//    for(int i = 0; i < arrSize; i++)
//    {
//        hash[arr[i] + 1000]++;
//    }
//    //printf("hash[1000] = %d\n", hash[1000]);
//    for(int i = 0; i < arrSize; i++)
//    {
//
//        if(arr[i] > -500 &&arr[i] < 501 && hash[(arr[i] * 2) + 1000])
//        {
//            if(arr[i] != 0)
//            return true;
//            else if(0 == arr[i] && hash[1000] > 1)
//            return true;
//            else
//            continue;
//        }
//        if(0 == arr[i] % 2 && hash[(arr[i] / 2) + 1000])
//        return true;
//    }
//
//    return false;
//}
//
////748.最短补全词
//
//bool is_alpha(char c)
//{
//    if(c >= 65 && c <= 90)
//    return true;
//    else if(c >= 97 && c <= 122)
//    return true;
//    else
//    return false;
//}
//char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) 
//{
//    //make hashtable of licensePlate
//    int hashl[26] = {0};
//    int lenl = strlen(licensePlate);
//    for(int i = 0; i < lenl; i++)
//    {
//        if(is_alpha(licensePlate[i]))
//        {
//            if(licensePlate[i] >= 'a')
//            hashl[licensePlate[i] - 97]++;
//            else
//            hashl[licensePlate[i] - 65]++;
//        }
//    }
//
//    //compare
//    int ret = 0;
//    int len = INT_MAX;
//    for(int row = 0; row < wordsSize; row++)
//    {
//        int hashw[26] = {0};
//        int lenc = strlen(words[row]);
//        for(int col = 0; col < lenc; col++)
//        {
//            if(is_alpha(words[row][col]))
//            {
//                if(words[row][col] >= 'a')
//                hashw[words[row][col] - 97]++;
//                else
//                hashw[words[row][col] - 65]++;
//            }
//        }
//
//        int i = 0;
//        for(i = 0; i < 26; i++)
//        {
//            if(hashw[i] < hashl[i])
//            break;
//        }
//        if(i == 26 && len > lenc)
//        {
//            len = lenc;
//            ret = row;
//        }
//    }
//
//    return words[ret];
//}
//
////3046.分割数组
//
////1.HashTable
//// bool isPossibleToSplit(int* nums, int numsSize) 
//// {
////     int hash[100] = {0};
////     for(int i = 0; i < numsSize; i++)
////     {
////         hash[nums[i] - 1]++;
////     }
//
////     for(int i = 0; i < 100; i++)
////     {
////         if(hash[i] > 2)
////         return false;
////     }
//
////     return true;
//// }
//
////2.Double Points
//bool isPossibleToSplit(int* nums, int numsSize) 
//{
//    int left = 0;
//    int right = 1;
//    while(left < numsSize)
//    {
//        if(nums[left])
//        {
//            int n = 1;
//            while(right < numsSize)
//            {
//                if(!(nums[right] ^ nums[left]))
//                {
//                    nums[right] = 0;
//                    n++;
//                }
//                right++;
//            }
//            if(n > 2)
//            return false;
//        }
//        left++;
//        right = left + 1;
//    }
//
//    return true;
//}
//
////3206.交替组
//
//// 1.Add the first two to the last
//// int numberOfAlternatingGroups(int* colors, int colorsSize) 
//// {
////     int colorsLoop[colorsSize + 2];
////     for(int i = 0; i < colorsSize; i++)
////     {
////         colorsLoop[i] = colors[i];
////     }
////     colorsLoop[colorsSize] = colors[0];
////     colorsLoop[colorsSize + 1] = colors[1];
//
////     int i = 0;
////     int sum = 0;
////     while(i < colorsSize)
////     {
////         if(!(colorsLoop[i] ^ colorsLoop[i + 2]) && (colorsLoop[i] ^ colorsLoop[i + 1]))
////         sum++;
////         i++;
////     }
////     return sum;
//// }
////
////2. Except the last two
//int numberOfAlternatingGroups(int* colors, int colorsSize) 
//{
//    int i = 0;
//    int sum = 0;
//    while(i < colorsSize - 2)
//    {
//        if(!(colors[i] ^ colors[i + 2]) && (colors[i] ^ colors[i + 1]))
//        sum++;
//        i++;
//    }
//    if(!(colors[colorsSize - 2] ^ colors[0]) && (colors[colorsSize - 2] ^ colors[colorsSize - 1]))
//        sum++;
//    if(!(colors[colorsSize - 1] ^ colors[1]) && (colors[colorsSize - 1] ^ colors[0]))
//        sum++;
//    return sum;
//}
//
