class MyLinkedList {
public:
	struct DoublyListNode
	{
		int val;
		DoublyListNode *prev, *next;
		DoublyListNode() :val(0), prev(nullptr), next(nullptr) {}
		DoublyListNode(int val):val(val), prev(nullptr), next(nullptr) {}
	};
	/** Initialize your data structure here. */
	MyLinkedList() {
		m_size = 0;
		m_vHead = new DoublyListNode();
		m_vTail = new DoublyListNode();
		m_vHead->next = m_vTail;
		m_vTail->prev = m_vHead;
	}
	~MyLinkedList() {
		DoublyListNode* ptr = m_vHead;
		DoublyListNode* ptrTmp = nullptr;
		while (ptr !=nullptr)
		{
			ptrTmp = ptr->next;
			delete ptr;
			ptr = ptrTmp;
		}
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index < 0 || index >= m_size) return -1;
		DoublyListNode* node = m_vHead;
		while (index--)
		{
			node = node->next;
		}
		return node->next->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		DoublyListNode* cur = new DoublyListNode(val);
		cur->next = m_vHead->next;
		cur->prev = m_vHead;
		m_vHead->next->prev = cur;
		m_vHead->next = cur;
		m_size++;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		DoublyListNode* cur = new DoublyListNode(val);
		cur->next = m_vTail;
		cur->prev = m_vTail->prev;
		m_vTail->prev->next = cur;
		m_vTail->prev = cur;
		m_size++;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index < 0) {
			addAtHead(val);
		}
		else if(index >m_size)
		{
			return;
		}else {
			DoublyListNode* node = m_vHead;
			while (index--)
			{
				node = node->next;
			}
			DoublyListNode* cur = new DoublyListNode(val);
			cur->next = node->next;
			cur->prev = node;
			node->next->prev = cur;
			node->next = cur;
			m_size++;
		}
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index < 0 || index >= m_size) return;
		else {
			DoublyListNode* node = m_vHead;
			while (index--)
			{
				node = node->next;
			}
			DoublyListNode* del = node->next;
			node->next->next->prev = node;
			node->next = node->next->next;
			delete del;
			m_size--;
		}
	}
	DoublyListNode* m_vHead;
	DoublyListNode* m_vTail;
	int m_size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */