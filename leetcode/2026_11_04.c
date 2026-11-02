//// 2300. 咒语和药水的成功对数
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int binary_search(int* nums, int n, int times, long long target)
//{
//    int left = 0, right = n - 1;
//    while (left <= right)
//    {
//        int mid = (left + right) / 2;
//        if (1ll * nums[mid] * times >= target)
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    return n - left;
//}
//int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize)
//{
//    qsort(potions, potionsSize, sizeof(int), cmp);
//    for (int i = 0; i < spellsSize; i++)
//    {
//        spells[i] = binary_search(potions, potionsSize, spells[i], success);
//    }
//    *returnSize = spellsSize;
//    return spells;
//}
//
