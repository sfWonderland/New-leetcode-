//#define _CRT_SECURE_NO_WARNINGS
//
////278.第一个错误版本
//
//// The API isBadVersion is defined for you.
//// bool isBadVersion(int version);
//
//int firstBadVersion(int n)
//{
//    int left = 1;
//    int right = n;
//    int mid = (right - left) / 2 + left;
//    while (left < right)
//    {
//        if (isBadVersion(mid))
//        {
//            if (isBadVersion(mid - 1))
//            {
//                right = mid - 1;
//                mid = (right - left) / 2 + left;
//            }
//            else
//                break;
//        }
//        else
//        {
//            left = mid + 1;
//            mid = (right - left) / 2 + left;
//        }
//    }
//    return mid;
//}
//
////374.猜数字大小
//
///**
// * Forward declaration of guess API.
// * @param  num   your guess
// * @return 	     -1 if num is higher than the picked number
// *			      1 if num is lower than the picked number
// *               otherwise return 0
// * int guess(int num);
// */
//
//int guess(int num);
//int guessNumber(int n)
//{
//    int left = 1;
//    int right = n;
//    int mid = (right - left) / 2 + left;
//    while (left < right)
//    {
//        if (guess(mid) == -1)
//        {
//            right = mid - 1;
//            mid = (right - left) / 2 + left;
//        }
//        else if (guess(mid) == 1)
//        {
//            left = mid + 1;
//            mid = (right - left) / 2 + left;
//        }
//        else
//        {
//            break;
//        }
//    }
//    return mid;
//}