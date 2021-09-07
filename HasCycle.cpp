// HasCycle.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "ListCommon.h"
 
class SolutionHas1 {
public:
	bool hasCycle(ListNode *head) {
		if (head == nullptr || head->next == nullptr)
		{
			return false;
		}
		ListNode* fast = head;
		ListNode* slow = head;
		do
		{
			fast = fast->next;
			if (fast == nullptr)
			{
				return false;
			}
			fast = fast->next;
			if (fast == nullptr)
			{
				return false;
			}
			slow = slow->next;
		} while (fast != slow);
		return true;
	}
};

class SolutionHasCycle {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == nullptr || head->next == nullptr)
		{
			return nullptr;
		}
		ListNode* fast = head;
		ListNode* slow = head;
		std::set<ListNode*> s;
		do
		{
			fast = fast->next;
			if (fast == nullptr)
			{
				return nullptr;
			}
			fast = fast->next;
			if (fast == nullptr)
			{
				return nullptr;
			}
			s.emplace(slow);
			slow = slow->next;
		} while (fast != slow);
		return slow;
	}
};
