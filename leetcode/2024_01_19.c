#define _CRT_SECURE_NO_WARNINGS


//383.赎金信
bool canConstruct(char* ransomNote, char* magazine)
{
    int len1 = strlen(magazine);
    int len2 = strlen(ransomNote);
    if (len2 > len1)
        return false;
    int s[26] = { 0 };
    for (int i = 0; i < len1; i++)
    {
        s[(magazine[i] - 'a')]++;
    }
    for (int j = 0; j < len2; j++)
    {
        if (s[ransomNote[j] - 'a'] != 0)
        {
            s[ransomNote[j] - 'a']--;
        }
        else
            return false;
    }
    return true;
}

//1160.拼写单词
void RestoreCopy(int* copy, int* s, int n)
{
    for (int i = 0; i < n; i++)
    {
        copy[i] = s[i];
    }
}
int countCharacters(char** words, int wordsSize, char* chars)
{
    //printf("wordsSize = %d\n", wordsSize);//row
    //build hash 
    int len1 = strlen(chars);
    int s[26] = { 0 };
    int copy[26] = { 0 };
    for (int i = 0; i < len1; i++)
    {
        s[chars[i] - 'a']++;
        copy[chars[i] - 'a']++;
    }
    //calulate
    int ret = 0;
    for (int i = 0; i < wordsSize; i++)
    {
        int len2 = strlen(words[i]);
        if (len2 <= len1)
        {
            int flag = 1;
            for (int j = 0; j < len2; j++)
            {
                if (copy[words[i][j] - 'a'] != 0)
                    copy[words[i][j] - 'a']--;
                else
                {
                    flag = 0;
                    break;
                }
            }
            //be able to spell or not
            if (flag)
                ret += len2;
        }
        //restore the copy to enter the next loop
        RestoreCopy(copy, s, 26);
    }
    return ret;
}

//2287.重排字符形成目标字符串
int rearrangeCharacters(char* s, char* target)
{
    //build hash 
    int len1 = strlen(s);
    int hashs[26] = { 0 };
    for (int i = 0; i < len1; i++)
    {
        hashs[s[i] - 'a']++;
    }

    int len2 = strlen(target);
    int hasht[26] = { 0 };
    for (int i = 0; i < len2; i++)
    {
        hasht[target[i] - 'a']++;
    }

    //compare
    int ret = INT_MAX;
    for (int i = 0; i < 26; i++)
    {
        if (hasht[i] != 0)
        {
            int tmp = hashs[i] / hasht[i];
            if (tmp < ret)
                ret = tmp;
        }
    }
    return (ret != INT_MAX) ? ret : 0;
}

//387.字符串中的第一个唯一字符
int firstUniqChar(char* s)
{
    int len = strlen(s);
    int hash[26] = { 0 };
    for (int i = 0; i < len; i++)
    {
        hash[s[i] - 'a']++;
    }

    for (int i = 0; i < len; i++)
    {
        if (1 == hash[s[i] - 'a'])
            return i;
    }
    return -1;
}

//2351.第一个出现两次的字母
char repeatedCharacter(char* s)
{
    int len = strlen(s);
    int hash[26] = { 0 };
    for (int i = 0; i < len; i++)
    {
        hash[s[i] - 'a']++;
    }

    int ret = len;
    for (int i = 0; i < len; i++)
    {
        if (hash[s[i] - 'a'] >= 2)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (s[j] == s[i] && j < ret)
                {
                    ret = j;
                    hash[s[i] - 'a'] = 0;
                }
            }
        }
    }
    return s[ret];
}

