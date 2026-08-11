//// 273. 整数转换英文表示
//
//char* digits[20] = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
//char* tens[10] = { "Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
//char* transfer_10(int x)
//{
//    char* res = (char*)malloc(sizeof(char) * 15);
//    if (x >= 20)
//    {
//        if (x % 10)
//            sprintf(res, "%s %s", tens[x / 10], digits[x % 10]);
//        else
//            sprintf(res, "%s", tens[x / 10]);
//    }
//    else
//        sprintf(res, "%s", digits[x]);
//
//    return res;
//}
//char* transfer_100(int x)
//{
//    char* res = (char*)malloc(sizeof(char) * 30);
//    int hun = x / 100;
//    if (hun)
//    {
//        if (x % 100)
//            sprintf(res, "%s Hundred %s", digits[hun], transfer_10(x % 100));
//        else
//            sprintf(res, "%s Hundred", digits[hun]);
//    }
//    else
//        res = transfer_10(x);
//    return res;
//}
//char* transfer_1000(int x)
//{
//    char* res = (char*)malloc(sizeof(char) * 80);
//    int thou = x / 1000;
//    if (thou)
//    {
//        if (x % 1000)
//            sprintf(res, "%s Thousand %s", transfer_100(thou), transfer_100(x % 1000));
//        else
//            sprintf(res, "%s Thousand", transfer_100(thou));
//    }
//    else
//        res = transfer_100(x);
//    return res;
//}
//char* transfer_M(int x)
//{
//    char* res = (char*)malloc(sizeof(char) * 120);
//    int mill = x / 1000000;
//    if (mill)
//    {
//        if (x % 1000000)
//            sprintf(res, "%s Million %s", transfer_100(mill), transfer_1000(x % 1000000));
//        else
//            sprintf(res, "%s Million", transfer_100(mill));
//    }
//    else
//        res = transfer_1000(x);
//    return res;
//}
//char* transfer_B(int x)
//{
//    char* res = (char*)malloc(sizeof(char) * 170);
//    int bill = x / 1000000000;
//    if (bill)
//    {
//        if (x % 1000000000)
//            sprintf(res, "%s Billion %s", transfer_100(bill), transfer_M(x % 1000000000));
//        else
//            sprintf(res, "%s Billion", transfer_100(bill));
//    }
//    else
//        res = transfer_M(x);
//    return res;
//}
//char* numberToWords(int num)
//{
//    return transfer_B(num);
//}
//
//char* digits[20] = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
//char* tens[10] = { "Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
//char* thous[3] = { "Thousand", "Million", "Billion" };
//char* transfer_10(int x)
//{
//    char* res = (char*)malloc(sizeof(char) * 15);
//    if (x >= 20)
//    {
//        if (x % 10)
//            sprintf(res, "%s %s", tens[x / 10], digits[x % 10]);
//        else
//            sprintf(res, "%s", tens[x / 10]);
//    }
//    else
//        sprintf(res, "%s", digits[x]);
//
//    return res;
//}
//
//char* transfer_100(int x)
//{
//    char* res = (char*)malloc(sizeof(char) * 30);
//    int hun = x / 100;
//    if (hun)
//    {
//        if (x % 100)
//            sprintf(res, "%s Hundred %s", digits[hun], transfer_10(x % 100));
//        else
//            sprintf(res, "%s Hundred", digits[hun]);
//    }
//    else
//        res = transfer_10(x);
//    return res;
//}
//
//char* numberToWords(int num)
//{
//    char* s = (char*)malloc(sizeof(char) * 200);
//    char* ans = (char*)malloc(sizeof(char) * 200);
//    strcpy(ans, transfer_100(num % 1000));
//    num /= 1000;
//    int step = 0;
//    while (num)
//    {
//        int x = num % 1000;
//        if (x)
//        {
//            if (strcmp(ans, digits[0]))
//                sprintf(s, "%s %s %s", transfer_100(x), thous[step], ans);
//            else
//                sprintf(s, "%s %s", transfer_100(x), thous[step]);
//        }
//        else
//            strcpy(s, ans);
//
//        strcpy(ans, s);
//        num /= 1000;
//        step++;
//    }
//    free(s);
//    return ans;
//}
//
