////1461. ���һ���ַ����Ƿ�������г���Ϊ K �Ķ������Ӵ�
//
//bool hasAllCodes(char* s, int k)
//{
//    int hash[1 << k];
//    memset(hash, 0, sizeof(hash));
//    int num = 0;
//    int t = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        t <<= 1;
//        t += s[i] - '0';
//        if (i < k - 1)
//            continue;
//
//        if (hash[t] == 0)
//        {
//            hash[t]++;
//            num++;
//        }
//        t -= (s[i - k + 1] - '0') << (k - 1);
//        //printf("%d %d\n", num, t);
//    }
//    return num == 1 << k;
//}
//
////3. ���ظ��ַ�����Ӵ�
//
//int lengthOfLongestSubstring(char* s)
//{
//    int ans = 0, left = 0;
//    int cnt[128] = { 0 };
//    for (int right = 0; s[right]; right++)
//    {
//        cnt[s[right]]++;
//
//        while (cnt[s[right]] > 1)
//        {
//            cnt[s[left]]--;
//            left++;
//        }
//        ans = fmax(ans, right - left + 1);
//    }
//    return ans;
//}
//
////2962. ͳ�����Ԫ�س������� K �ε�������
//
//long long countSubarrays(int* nums, int numsSize, int k)
//{
//    int max = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        max = fmax(nums[i], max);
//    }
//    long long ans = 0;
//    int cnt = 0, left = 0;
//    for (int right = 0; right < numsSize; right++)
//    {
//        cnt += (nums[right] == max);
//
//        while (cnt == k)
//        {
//            cnt -= nums[left] == max;
//            left++;
//        }
//        ans += left;
//    }
//    return ans;
//}
//
////3090. ÿ���ַ����������ε�����ַ���
//
//int maximumLengthSubstring(char* s)
//{
//    int hash[26] = { 0 };
//    int left = 0, ans = 0;
//    for (int right = 0; s[right]; right++)
//    {
//        hash[s[right] - 'a']++;
//
//        while (hash[s[right] - 'a'] == 3)
//        {
//            hash[s[left] - 'a']--;
//            left++;
//        }
//        ans = fmax(ans, right - left + 1);
//        //printf("%d %c %d %c\n", left, s[left], right, s[right]);
//    }
//    return ans;
//}
//
