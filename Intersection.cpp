#include "ListCommon.h"
 
class SolutionInt {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int i = 0;
        auto hA = headA;
        unordered_set<ListNode*> setNode;
        while(hA!=nullptr)
        {
            setNode.insert(hA);
            hA = hA->next;
        }
        auto hB = headB;
        bool hasInterSection = false;
        ListNode* interNode = nullptr;
        while(hB != nullptr)
        {
            if(setNode.count(hB))
            {
                hasInterSection = true;
                interNode = hB;
                break;
            }
            hB = hB->next;
        }
        return interNode;
    }
};