//// 20. ÓÐÐ§µÄÀ¨ºÅ
//
//bool isValid(char* s)
//{
//    int top = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
//            s[top++] = s[i];
//        else if (top > 0 && s[i] - s[top - 1] <= 2 && s[i] - s[top - 1] > 0)
//            top--;
//        else
//            return false;
//    }
//    return top == 0;
//}
//
