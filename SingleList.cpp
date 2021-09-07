#include <iostream>

//get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回 - 1。
//addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
//addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
//addAtIndex(index, val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
//deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。


class MyLinkedList {
public:
	struct SingleListNode {
		int var;
		SingleListNode* next;
		SingleListNode() :var(0), next(nullptr) {}
	};
	/** Initialize your data structure here. */
	MyLinkedList()
	{
		m_size = 0;
		//伪头节点
		m_head = new SingleListNode();
	}
	void printLinkList()
	{
		auto t = m_head->next;
		while (t != nullptr)
		{
			std::cout << t->var << " ";
			t = t->next;
		}
		std::cout << std::endl;
	}
	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index < 0 || index >= m_size)
		{
			return -1;
		}
		auto t = m_head;
		while (index--)
		{
			t = t->next;
		}
		return t->next->var;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {

			SingleListNode* cur = new SingleListNode();
			cur->var = val;
			cur->next = m_head->next;
			m_head->next = cur;
			m_size++;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		auto t = m_head;
		while (t->next != nullptr)
		{
			t = t->next;
		}

		SingleListNode* cur = new SingleListNode();
		cur->var = val;
		t->next = cur;
		m_size++;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index < 0)
		{
			addAtHead(val);
			return;
		}
		if (index == m_size)
		{
			addAtTail(val);
		}else if (index > m_size)
		{
			return;
		}else {
			auto t = m_head;
			while (index--)
			{
				t = t->next;
			}
			SingleListNode* cur = new SingleListNode();
			cur->var = val;
			cur->next = t->next;
			t->next = cur;
			m_size++;
		}
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index < 0 || index >= m_size)
		{
			return;
		}
		auto t = m_head;
		while (index--){
			t = t->next;
		}
		SingleListNode* del = nullptr;
		del = t->next;
		t->next = del->next;
		delete del;
		m_size--;
	}
private:
	int m_size;
	SingleListNode *m_head;
};

//int main()
//{
//	MyLinkedList* obj = new MyLinkedList();
//	obj->addAtHead(1);
//	obj->printLinkList();
//	obj->addAtTail(3);
//	obj->printLinkList();
//	obj->addAtIndex(1,2);
//	obj->printLinkList();
//	std::cout << obj->get(1)<<std::endl;
//	obj->deleteAtIndex(0);
//	obj->printLinkList();
//	std::cout << obj->get(0) << std::endl;
//}


