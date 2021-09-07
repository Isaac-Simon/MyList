#include "ListCommon.h"

class SolutionADDT {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		static int in = 0;
		if (l1 == nullptr && l2 != nullptr)
		{
			int orginal = in + l2->val;
			in = orginal / 10;
			int g = orginal - in * 10;
			if (in > 0)
			{
				if (l2->next == nullptr)
				{
					ListNode* inNode = new ListNode(0);
					l2->next = inNode;
				}
			}
			l2->val = g;
			l2->next = addTwoNumbers(l1, l2->next);   //µÝ¹é £¡£¡
			return l2;
		}
		if (l2 == nullptr&& l1 != nullptr)
		{
			int orginal = in + l1->val;
			in = orginal / 10;
			int g = orginal - in * 10;
			if (in > 0)
			{
				if (l1->next == nullptr)
				{
					ListNode* inNode = new ListNode(0);
					l1->next = addTwoNumbers(inNode, nullptr);
				}
			}
			l1->val = g;
			l1->next = addTwoNumbers(l1->next, l2);
			return l1;
		}

		if (l2 == nullptr&& l1 == nullptr)
		{
			in = 0;
			return nullptr;
		}
		
		if (l2 != nullptr&& l1 != nullptr)
		{
			int orginal = (l1->val + l2->val + in);
			in = orginal / 10;
			int g = orginal - in * 10;
			l1->val = g;

			if (l2->next == nullptr&& l1->next == nullptr && in > 0)
			{
				ListNode* inNode = new ListNode(0);
				l1->next = addTwoNumbers(nullptr, inNode);
				return l1;
			}
			else
			{
				l1->next = addTwoNumbers(l1->next, l2->next);
				return l1;
			}
		}
		return nullptr;
	}
};

void main()
{

	std::vector<int> v1 = { 9 };
	std::vector<int> v2 = { 9 };
	auto l1 = inputList(v1);
	auto l2 = inputList(v2);

	auto l3 = inputList(v1);
	auto l4 = inputList(v2);
	SolutionADDT obj;
	ListNode* l = obj.addTwoNumbers(l1, l2);

	printLinkList(l);
	ListNode* ll = obj.addTwoNumbers(l3, l4);
	printLinkList(ll);
}