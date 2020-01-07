/*
Design your implementation of the linked list. 
You can choose to use the singly linked list or the doubly linked list.
 A node in a singly linked list should have two attributes: val and next. 
 val is the value of the current node, 
 and next is a pointer/reference to the next node. 
 If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. 
 Assume all nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:

get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
addAtTail(val) : Append a node of value val to the last element of the linked list.
addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.
 

Example:

Input: 
["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
[[],[1],[3],[1,2],[1],[1],[1]]
Output:  
[null,null,null,null,2,null,3]

Explanation:
MyLinkedList linkedList = new MyLinkedList(); // Initialize empty LinkedList
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
linkedList.get(1);            // returns 2
linkedList.deleteAtIndex(1);  // now the linked list is 1->3
linkedList.get(1);            // returns 3
*/

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

struct Node
{
	int val;
	Node *next;
};

class MyLinkedList
{
public:
	/** Initialize your data structure here. */
	MyLinkedList()
	{
		_head = new Node();
		_size = 0;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index)
	{
		if (index < 0 || index > _size - 1)
			return -1;
		auto cur = _head->next;
		for (int i = 0; i < index; ++i)
		{
			cur = cur->next;
		}
		return cur->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val)
	{
		auto tmp = _head->next;
		auto node = new Node();
		node->val = val;
		_head->next = node;
		node->next = tmp;
		_size++;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val)
	{
		auto cur = _head;
		while (cur->next != nullptr)
			cur = cur->next;
		cur->next = new Node();
		cur->next->val = val;
		_size++;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val)
	{
		if (index < 0 || index > _size)
			return;

		if (index == 0)
		{
			return addAtHead(val);
		}
		else
		{
			auto idx = 0;
			auto cur = _head->next;
			for (auto i = 0; i < index - 1; ++i)
				cur = cur->next;
			auto tmp = cur->next;
			cur->next = new Node();
			cur->next->val = val;
			cur->next->next = tmp;
			_size++;
		}
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index)
	{
		if (index < 0 || index >= _size)
			return;

		if (index == 0)
		{
			auto tmp = _head->next;
			_head->next = tmp->next;
			delete tmp;
			_size--;
			return;
		}

		auto idx = 0;
		auto cur = _head->next;
		for (auto i = 0; i < index - 1; ++i)
			cur = cur->next;
		auto tmp = cur->next;
		cur->next = cur->next->next;
		delete tmp;
		_size--;
	}

private:
	Node *_head;
	int _size;
};

int main()
{
	MyLinkedList *linkedList = new MyLinkedList(); // Initialize empty LinkedList
	linkedList->addAtHead(1);
	linkedList->addAtTail(3);
	linkedList->addAtIndex(1, 2);		// linked list becomes 1->2->3
	cout << linkedList->get(0) << endl; // returns 2
	linkedList->deleteAtIndex(1);		// now the linked list is 1->3
	cout << linkedList->get(1) << endl; // returns 3
}
