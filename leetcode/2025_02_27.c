////LCR 169. 招式拆解II
//
//// char dismantlingAction(char* arr) 
//// {
////     int h[26] = {0};
////     for(int i = 0; arr[i]; i++)
////     {
////         h[arr[i] - 'a']++;
////     }
////     for(int i = 0; arr[i]; i++)
////     {
////         if(1 == h[arr[i] - 'a'])
////         return arr[i];
////     }
////     return ' ';
//// }
//
//char dismantlingAction(char* arr)
//{
//    if (arr == NULL || *arr == '\0')
//        return ' ';
//    int h[26] = { 0 };
//    int len = strlen(arr);
//    int queue[len];
//    int j = 0;
//    for (int i = 0; arr[i]; i++)
//    {
//        int t = arr[i] - 'a';
//        if (!h[t])
//            queue[j++] = t;
//        h[t]++;
//    }
//    for (int i = 0; i < j; i++)
//    {
//        if (1 == h[queue[i]])
//            return queue[i] + 'a';
//    }
//    return ' ';
//}
//
////153. 寻找旋转排序数组中的最小值
//
//int findMin(int* nums, int numsSize)
//{
//    int left = 0;
//    int right = numsSize - 1;
//    while (left < right)
//    {
//        int mid = left + ((right - left) >> 1);
//        if (nums[mid] < nums[right])
//            right = mid;
//        else
//            left = mid + 1;
//    }
//    return nums[left];
//}
//
////154. 寻找旋转排序数组中的最小值II
//
//int findMin(int* nums, int numsSize)
//{
//    int left = 0;
//    int right = numsSize - 1;
//    while (left < right)
//    {
//        int mid = left + ((right - left) >> 1);
//        if (nums[mid] < nums[right])
//            right = mid;
//        else if (nums[mid] > nums[right])
//            left = mid + 1;
//        else
//            right--;
//    }
//    return nums[left];
//}
//
////LCR 121. 寻找目标值
//
//bool findTargetIn2DPlants(int** plants, int plantsSize, int* plantsColSize, int target)
//{
//    if (NULL == plants || 0 == plantsSize)
//        return false;
//    int boundary = -1;
//    for (int i = 0; i < plantsSize; i++)
//    {
//        int cols = plantsColSize[i];
//        if (0 == cols)
//            continue;
//        if (cols > 0 && plants[i][0] > target)
//            break;
//        boundary = (-1 == boundary) ? (cols - 1) : ((boundary < cols - 1) ? boundary : cols - 1);
//        for (int j = boundary; j >= 0; j--)
//        {
//            if (target == plants[i][j])
//                return true;
//            else if (target > plants[i][j])
//            {
//                boundary = j;
//                break;
//            }
//        }
//    }
//    return false;
//}
//
