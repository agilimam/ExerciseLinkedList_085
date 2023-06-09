#include<iostream>
#include<string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;

public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** imam, Node** agil);
	bool listEmpety();
	bool delNode();
	void traverse();
};

void CircularLinkedList::addNode() {
	Node* newNode = new Node();
	cout << "enter roll number: ";
	cin >> newNode->rollNumber;
	cout << "enter the name: ";
	cin >> newNode->name;

	if (listEmpety()) {
		newNode->next = newNode;
		LAST = newNode;
	}
	else {
		Node* imam = LAST;
		Node* agil = LAST->next;

		while (agil != LAST && agil->rollNumber < newNode->rollNumber) {
			imam = agil;
			agil = agil->next;
		}
		if (agil == LAST && agil->rollNumber < newNode->rollNumber) {
			newNode->next = LAST->next;
			LAST->next = newNode;
			LAST = newNode;
		}
		else {
			newNode->next = agil;
			imam->next = newNode;
		}
	}
	cout << "Record added succesfully!" << endl;

}

bool CircularLinkedList::search(int rollno, Node** imam, Node** agil) {
	*imam = LAST->next;
	*agil = LAST->next;

	while (*agil != LAST) {
		if (rollno == (*agil)->rollNumber) {
			return true;
		}
		*imam = *agil;
		*agil = (*agil)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpety() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode() {
	if (listEmpety()) {
		cout << "List is empety , Delation failed!" << endl;
		return false;
	}
	int rollno;
	cout << "enter the roll number to delete: ";
	cin >> rollno;

	Node* imam = NULL;
	Node* agil = NULL;

	if (search(rollno, &imam, &agil)) {
		if (agil == LAST) {
			if (LAST->next == LAST) {
				delete LAST;
				LAST = NULL;
				cout << "record deleted succesfully!" << endl;
				return true;
			}
			else {
				LAST->next = agil->next;
				LAST = LAST->next;
				delete agil;
				cout << "record deleted succesfully!" << endl;
				return true;
			}
		}
		else {
			imam->next = agil->next;
			delete agil;
			cout << "record deleted succesfully!" << endl;
			return true;
		}

	}
	else {
		cout << "record not found. deleted failed!" << endl;
		return false;
	}

}

void CircularLinkedList::traverse() {
	if (listEmpety()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n;";
		Node* agilNode = LAST->next;
		while (agilNode != LAST) {
			cout << agilNode->rollNumber << " " << agilNode->name << endl;
			agilNode = agilNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\Menu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the record in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5):";

			char ch;
			cin >> ch;
			
			switch (ch) {
			case '1': {
				obj.addNode();
			}
			case '2': {
				obj.delNode();
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}

