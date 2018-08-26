#include <iostream>
using namespace std;

/*****get two list the first common node*******/
//when the length of two lists is equal , the first circulation can get result
// when the length of two list is not equal, after first circulation pointer p1 and p2 point to the location
//that has same distance to the end of both lists
/*
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(!(pHead1 && pHead2))
            return NULL;
        ListNode *p1, *p2;
        p1 = pHead1;
        p2 = pHead2;
        while(p1 != p2)
        {
            p1 = (p1 == NULL ? pHead2 : p1->next);
            p2 = (p2 == NULL ? pHead1 : p2->next);
        }
        return p1;
    }
};
*/
