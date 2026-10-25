//// 946. —È÷§’ª–Ú¡–
//
//bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize)
//{
//    int top = 0, n = pushedSize, j = 0;
//    for (int i = 0; i < n; i++)
//    {
//        pushed[top++] = pushed[i];
//        while (top > 0 && pushed[top - 1] == popped[j])
//        {
//            j++;
//            top--;
//        }
//    }
//    return top == 0;
//}
//
