////3100. ��ˮ���� II
//
//int maxBottlesDrunk(int numBottles, int numExchange)
//{
//    // int sum = numBottles;
//    // while(numBottles >= numExchange)
//    // {
//    //     numBottles -= numExchange - 1;
//    //     numExchange++;
//    //     sum++;
//    // }    
//    // return sum;
//    int b = 2 * numExchange - 1;
//    int k = ((int)sqrt(b * b + (numBottles - numExchange) * 8) - b + 2) / 2;
//    return numBottles + k;
//}
//
////3689. �����������ֵ I
//
//long long maxTotalValue(int* nums, int numsSize, int k)
//{
//    int max = 0, min = INT_MAX;
//    for (int i = 0; i < numsSize; i++)
//    {
//        max = fmax(max, nums[i]);
//        min = fmin(min, nums[i]);
//    }
//    return 1ll * k * (max - min);
//}
//
////3692. ����Ƶ���ַ�
//
//char* majorityFrequencyGroup(char* s)
//{
//    int cnt[26] = { 0 };
//    int freq[101] = { 0 };
//    for (int i = 0; s[i]; i++)
//    {
//        cnt[s[i] - 'a']++;
//    }
//    int maxQ = 0, num = -1;
//    for (int i = 0; i < 26; i++)
//    {
//        if (!cnt[i])
//            continue;
//        freq[cnt[i]]++;
//        if (freq[cnt[i]] > maxQ)
//        {
//            num = cnt[i];
//            maxQ = freq[cnt[i]];
//        }
//        else if (freq[cnt[i]] == maxQ)
//            num = fmax(num, cnt[i]);
//    }
//    char* ans = (char*)malloc(sizeof(char) * (maxQ + 1));
//    ans[maxQ] = '\0';
//    for (int i = 0; i < 26; i++)
//    {
//        if (cnt[i] == num)
//            ans[--maxQ] = i + 'a';
//    }
//    return ans;
//}
//
////3688. ż���İ�λ������
//
//int evenNumberBitwiseORs(int* nums, int numsSize)
//{
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] & 1)
//            continue;
//        ans |= nums[i];
//    }
//    return ans;
//}
//
