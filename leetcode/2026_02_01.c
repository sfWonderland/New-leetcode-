////3827. 统计单比特整数
//
//int countMonobit(int n)
//{
//    int bits = 0, tmp = n;
//    while (tmp)
//    {
//        bits++;
//        tmp >>= 1;
//    }
//    if (((n + 1) & n) == 0)
//        bits++;
//
//    return bits;
//}
//
////3828. 删除子数组后的最终元素    
//
//int finalElement(int* nums, int numsSize)
//{
//    return fmax(nums[0], nums[numsSize - 1]);
//}
//
////3829. 设计共享出行系统
//
//typedef struct
//{
//    struct ListNode* HeadR;
//    struct ListNode* TailR;
//    struct ListNode* HeadD;
//    struct ListNode* TailD;
//} RideSharingSystem;
//
//RideSharingSystem* rideSharingSystemCreate()
//{
//    RideSharingSystem* obj = (RideSharingSystem*)malloc(sizeof(RideSharingSystem));
//    obj->TailD = obj->TailR = obj->HeadD = obj->HeadR = NULL;
//
//    return obj;
//}
//
//void rideSharingSystemAddRider(RideSharingSystem* obj, int riderId)
//{
//    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
//    node->val = riderId;
//    node->next = NULL;
//
//    if (!obj->TailR)
//        obj->HeadR = node;
//    else
//        obj->TailR->next = node;
//
//    obj->TailR = node;
//}
//
//void rideSharingSystemAddDriver(RideSharingSystem* obj, int driverId)
//{
//    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
//    node->val = driverId;
//    node->next = NULL;
//
//    if (!obj->TailD)
//        obj->HeadD = node;
//    else
//        obj->TailD->next = node;
//
//    obj->TailD = node;
//}
//
//int* rideSharingSystemMatchDriverWithRider(RideSharingSystem* obj, int* retSize)
//{
//    int* ret = (int*)malloc(sizeof(int) * 2);
//    ret[0] = -1, ret[1] = -1;
//
//    if (obj->HeadD && obj->HeadR)
//    {
//        struct ListNode* rider = obj->HeadR;
//        struct ListNode* driver = obj->HeadD;
//        ret[0] = driver->val; ret[1] = rider->val;
//        obj->HeadD = driver->next;
//        obj->HeadR = rider->next;
//        if (obj->HeadD == NULL)
//            obj->TailD = NULL;
//        if (obj->HeadR == NULL)
//            obj->TailR = NULL;
//        free(rider);
//        free(driver);
//    }
//
//    *retSize = 2;
//    return ret;
//}
//
//void rideSharingSystemCancelRider(RideSharingSystem* obj, int riderId)
//{
//    struct ListNode* cur = obj->HeadR;
//    struct ListNode* pre = NULL;
//
//    while (cur)
//    {
//        if (cur->val == riderId)
//        {
//            if (!pre)
//                obj->HeadR = cur->next;
//            else
//                pre->next = cur->next;
//
//            if (cur->next == NULL)
//                obj->TailR = pre;
//
//            free(cur);
//            break;
//        }
//        pre = cur;
//        cur = cur->next;
//    }
//}
//
//void rideSharingSystemFree(RideSharingSystem* obj)
//{
//    while (obj->HeadD)
//    {
//        struct ListNode* driver = obj->HeadD;
//        obj->HeadD = driver->next;
//        free(driver);
//    }
//    while (obj->HeadR)
//    {
//        struct ListNode* rider = obj->HeadR;
//        obj->HeadR = rider->next;
//        free(rider);
//    }
//}
//
///**
// * Your RideSharingSystem struct will be instantiated and called as such:
// * RideSharingSystem* obj = rideSharingSystemCreate();
// * rideSharingSystemAddRider(obj, riderId);
//
// * rideSharingSystemAddDriver(obj, driverId);
//
// * int* param_3 = rideSharingSystemMatchDriverWithRider(obj, retSize);
//
// * rideSharingSystemCancelRider(obj, riderId);
//
// * rideSharingSystemFree(obj);
//*/
//
////3210. 找出加密后的字符串
//
//char* getEncryptedString(char* s, int k)
//{
//    int n = strlen(s);
//    char* ans = (char*)malloc(sizeof(char) * (n + 1));
//    ans[n] = '\0';
//    for (int i = 0; i < n; i++)
//    {
//        ans[i] = s[(i + k) % n];
//    }
//    return ans;
//}
//
