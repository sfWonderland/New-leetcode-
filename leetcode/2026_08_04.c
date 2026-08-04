//// 394. ×Ö·û´®½âÂë
//
//char* decodeString(char* s)
//{
//    int capacity = 8;
//    char* st = (char*)malloc(sizeof(char) * capacity);
//    int idx1 = 0;
//    int* num = (int*)calloc(sizeof(int), 28);
//    int idx2 = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] <= '9')
//        {
//            if (i > 0 && s[i - 1] <= '9')
//            {
//                num[idx2 - 1] *= 10;
//                num[idx2 - 1] += s[i] - '0';
//            }
//            else
//                num[idx2++] = s[i] - '0';
//        }
//        else
//        {
//            if (s[i] != ']')
//            {
//                st[idx1++] = s[i];
//                if (idx1 >= capacity)
//                {
//                    capacity *= 2;
//                    st = (char*)realloc(st, sizeof(char) * capacity);
//                }
//            }
//            else
//            {
//                st[idx1] = '\0';
//                char* copy = (char*)malloc(sizeof(char) * idx1);
//                int m = 0;
//                while (st[--idx1] != '[')
//                {
//                    copy[m++] = st[idx1];
//                }
//                copy[m] = '\0';
//                int x = num[--idx2];
//                for (int i = 0; i < x; i++)
//                {
//                    for (int j = m - 1; j >= 0; j--)
//                    {
//                        st[idx1++] = copy[j];
//                        if (idx1 >= capacity)
//                        {
//                            capacity *= 2;
//                            st = (char*)realloc(st, sizeof(char) * capacity);
//                        }
//                    }
//                }
//                free(copy);
//            }
//        }
//    }
//    st[idx1] = '\0';
//    free(num);
//    return st;
//}
//
