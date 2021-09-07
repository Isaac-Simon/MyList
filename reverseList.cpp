#include "ListCommon.h"
 
class SolutionRev {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* fHead = new ListNode(0); //定义伪头节点
        fHead->next = head;
        while(head->next != nullptr)
        {
            auto nextNode = head->next;
            head->next = nextNode->next;
            nextNode->next = fHead->next;
            fHead->next = nextNode;
        }
        return fHead->next;
    }
};