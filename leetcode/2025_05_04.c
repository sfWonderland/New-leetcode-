//2779. ������������ֵ

int cmp(const void* e1, const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}
int maximumBeauty(int* nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = 0, left = 0;
    for (int right = 0; right < numsSize; ++right)
    {
        while (nums[right] - nums[left] > 2 * k)
        {
            ++left;
        }
        ans = fmax(ans, right - left + 1);
    }
    return ans;
}

//2730. �ҵ���İ��ظ����ַ���

int longestSemiRepetitiveSubstring(char* s)
{
    int ans = 1, left = 0, repeat = 0;
    for (int right = 1; s[right]; ++right)
    {
        if (s[right] == s[right - 1])
            ++repeat;

        while (repeat > 1)
        {
            if (s[left] == s[left + 1])
                --repeat;
            ++left;
        }
        ans = fmax(ans, right - left + 1);
    }
    return ans;
}

//1838. ���ƵԪ�ص�Ƶ��

int cmp(const void* e1, const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}
int maxFrequency(int* nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = 1, left = 0;
    long long t = 0;
    for (int right = 1; right < numsSize; ++right)
    {
        t += (long long)(nums[right] - nums[right - 1]) * (right - left);

        while (t > k)
        {
            t -= nums[right] - nums[left];
            ++left;
        }
        ans = fmax(ans, right - left + 1);
    }
    return ans;
}

//2516. ÿ���ַ�����ȡ K ��

int takeCharacters(char* s, int k)
{
    int n = strlen(s);
    int alpha[3] = { 0 };
    for (int i = 0; i < n; ++i)
    {
        ++alpha[s[i] - 'a'];
    }
    if (alpha[0] < k || alpha[1] < k || alpha[2] < k)
        return -1;
    int ans = 0, left = 0;
    for (int right = 0; right < n; ++right)
    {
        int t = s[right] - 'a';
        --alpha[t];

        while (alpha[t] < k)
        {
            ++alpha[s[left] - 'a'];
            ++left;
        }
        ans = fmax(ans, right - left + 1);
    }
    return n - ans;
}

