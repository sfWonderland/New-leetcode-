//// 744. 寻找比目标字母大的最小字母
//
//char nextGreatestLetter(char* letters, int lettersSize, char target)
//{
//    if (target >= letters[lettersSize - 1]) return letters[0];
//    target++;
//    int left = 0, right = lettersSize - 1;
//    while (left <= right)
//    {
//        int mid = (left + right) / 2;
//        if (letters[mid] >= target)
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    return letters[left];
//}
//
