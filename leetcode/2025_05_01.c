////2958. ��� K ���ظ�Ԫ�ص��������
//
//int maxSubarrayLength(int* nums, int numsSize, int k)
//{
//    int max = 0;
//    for (int i = 0; i < numsSize; ++i)
//    {
//        max = fmax(nums[i], max);
//    }
//    int* hash = (int*)calloc((max + 1), sizeof(int));
//    int ans = 0, left = 0, sum = 0;
//    for (int right = 0; right < numsSize; ++right)
//    {
//        ++sum;
//        ++hash[nums[right]];
//
//        while (hash[nums[right]] > k)
//        {
//            --hash[nums[left]];
//            --sum;
//            ++left;
//        }
//        ans = fmax(ans, sum);
//    }
//    return ans;
//}
//
////2024. ���Ե�������Ŷ�
//
//int maxConsecutiveAnswers(char* answerKey, int k)
//{
//    int ans = 0, left = 0, answers[2] = { 0 };
//    for (int right = 0; answerKey[right]; ++right)
//    {
//        ++answers[answerKey[right] == 'T'];
//
//        while (answers[0] > k && answers[1] > k)
//        {
//            --answers[answerKey[left] == 'T'];
//            left++;
//        }
//        ans = fmax(ans, right - left + 1);
//    }
//    return ans;
//}
//
////1004. �������1�ĸ��� III
//
//int longestOnes(int* nums, int numsSize, int k)
//{
//    int ans = 0, left = 0, ones = 0;
//    for (int right = 0; right < numsSize; ++right)
//    {
//        ones += nums[right];
//
//        while (right - left + 1 - ones > k)
//        {
//            ones -= nums[left];
//            ++left;
//        }
//        ans = fmax(ans, right - left + 1);
//    }
//    return ans;
//}
//
////1658. �� x ���� 0 ����С������
//
//int minOperations(int* nums, int numsSize, int x)
//{
//    int total = 0;
//    for (int i = 0; i < numsSize; ++i)
//    {
//        total += nums[i];
//    }
//    if (total < x)
//        return -1;
//    int ans = -1, left = 0, sum = total - x;
//    for (int right = 0; right < numsSize; ++right)
//    {
//        sum -= nums[right];
//
//        while (sum < 0)
//        {
//            sum += nums[left];
//            left++;
//        }
//        ans = sum == 0 ? fmax(right - left + 1, ans) : ans;
//    }
//    return ans == -1 ? ans : numsSize - ans;
//}
//
