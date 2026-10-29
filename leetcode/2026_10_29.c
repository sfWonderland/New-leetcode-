//// 1003. 检查替换后的词是否有效
//
//bool isValid(char* s)
//{
//    int top = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        s[top++] = s[i];
//        if (s[top - 1] == 'c')
//        {
//            top--;
//            if (top > 1 && s[top - 1] == 'b')
//                top--;
//            else
//                return false;
//            if (top > 0 && s[top - 1] == 'a')
//                top--;
//            else
//                return false;
//        }
//    }
//    return top == 0;
//}
//
