#include <iostream>
#include <unordered_set>
#include <random>

struct Node {
	int data = 0;
	Node *next = nullptr;
};

void appendAtBeginning(Node *&head, int value) {
	Node *newNode = new Node;
	newNode->data = value;
	newNode->next = head;
	head = newNode;
}

void freeList(Node *&head) {
	while(head) {
		Node *temp = head;
		head = head->next;
		delete temp;
	}
}

void printList(Node *head) {
	while(head) {
		std::cout << head->data << "-->";
		head = head->next;
	}
	std::cout << "nullptr\n\n";
}

int random_range(const int min, const int max) {
	static std::random_device rd;
	static std::mt19937 mt(rd());
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(mt);
}

void removeDuplicates(Node *head) {
	if (head == nullptr || head->next == nullptr) {
		return;
	}
	std::unordered_set<int> dataSet;
	dataSet.insert(head->data);
	while(head->next) {
		if(dataSet.find(head->next->data) == dataSet.end()) {
			head = head->next;
			dataSet.insert(head->data);
		} else {
			Node *temp = head->next;
			head->next = head->next->next;
			delete temp;
		}
	}
}


int main()
{
	Node *head = nullptr;
	for (int i = 0; i < 10; ++i) {
		appendAtBeginning(head, random_range(1,7));
	}
	printList(head);
	removeDuplicates(head);
	printList(head);
	freeList(head);
	return 0;
}

