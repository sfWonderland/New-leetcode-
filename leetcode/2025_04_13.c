////2273. 移除字母异位词后的结果数组
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** removeAnagrams(char** words, int wordsSize, int* returnSize)
//{
//    int hash[wordsSize][26];
//    for (int i = 0; i < wordsSize; i++)
//    {
//        memset(hash[i], 0, sizeof(int) * 26);
//    }
//    for (int i = 0; i < wordsSize; i++)
//    {
//        for (int j = 0; words[i][j]; j++)
//        {
//            hash[i][words[i][j] - 'a']++;
//        }
//    }
//    char** ret = (char**)malloc(sizeof(char*) * wordsSize);
//    for (int i = 0; i < wordsSize; i++)
//    {
//        ret[i] = (char*)malloc(sizeof(char) * 11);
//    }
//    *returnSize = 0;
//    int n = 0;
//    for (int i = 0; i < wordsSize; i++)
//    {
//        if (i == 0 || memcmp(hash[n], hash[i], sizeof(int) * 26))
//        {
//            strcpy(ret[(*returnSize)++], words[i]);
//            n = i;
//        }
//    }
//    return ret;
//}
//
////2299. 强密码检验器 II
//
//bool strongPasswordCheckerII(char* password)
//{
//    int len = strlen(password);
//    if (len < 8)
//        return false;
//    int pass = 0;
//    for (int i = 0; password[i]; i++)
//    {
//        if (i > 0 && password[i] == password[i - 1])
//            return false;
//        if (isupper(password[i]))
//            pass |= 1;
//        else if (islower(password[i]))
//            pass |= 2;
//        else if (isdigit(password[i]))
//            pass |= 4;
//        else
//            pass |= 8;
//    }
//    return pass == 15;
//}
//
////2383. 赢得比赛需要的最少训练时长
//
//// int minNumberOfHours(int initialEnergy, int initialExperience, int* energy, int energySize, int* experience, int experienceSize) 
//// {
////     int Enmin = 1;
////     for(int i = 0; i < energySize; i++)
////     {
////         Enmin += energy[i];
////     }
////     int Expmin = 1 + experience[0];
////     int accu = experience[0];
////     for(int i = 1; i < experienceSize; i++)
////     {
////         Expmin = fmax(Expmin, experience[i] - accu + 1);
////         accu += experience[i];
////     }
////     Enmin = Enmin > initialEnergy ? Enmin - initialEnergy : 0;
////     Expmin = Expmin > initialExperience ? Expmin - initialExperience : 0;
////     return Enmin + Expmin;
//// }
//
//int minNumberOfHours(int initialEnergy, int initialExperience, int* energy, int energySize, int* experience, int experienceSize)
//{
//    int sum = 0;
//    for (int i = 0; i < energySize; i++)
//    {
//        sum += energy[i];
//    }
//    int trainingHours = sum >= initialEnergy ? sum - initialEnergy + 1 : 0;
//    for (int i = 0; i < experienceSize; i++)
//    {
//        if (initialExperience <= experience[i])
//        {
//            trainingHours += 1 + (experience[i] - initialExperience);
//            initialExperience = 2 * experience[i] + 1;
//        }
//        else
//            initialExperience += experience[i];
//    }
//    return trainingHours;
//}
//
////2418. 按身高排序
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return ((int*)e2)[0] - ((int*)e1)[0];
//}
//char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize)
//{
//    int indices[namesSize][2];
//    for (int i = 0; i < namesSize; i++)
//    {
//        indices[i][1] = i;
//        indices[i][0] = heights[i];
//    }
//    qsort(indices, namesSize, sizeof(int) * 2, cmp);
//    char** ret = (char**)malloc(sizeof(char*) * heightsSize);
//    for (int i = 0; i < heightsSize; i++)
//    {
//        ret[i] = names[indices[i][1]];
//    }
//    returnSize[0] = heightsSize;
//    return ret;
//}
//
