/*
Ten: Nguyen Minh Triet
MSSV: 18211TT1631
Ngay: 12/04/2019
Chuong 4
*/
//Khai bao thu vien
#include <iostream>
using namespace std;

//Khai bao struct
struct Node {
	int nData;
	Node *pNext;
};

struct linkedList {
	Node *pHead;
	Node *pTail;
	linkedList() {
		pHead = pTail = NULL;
	}
};

//Khai bao nguyen ham
Node* createNode(int nX);
void addTail(linkedList &l, int nX);
void inputTail(linkedList &l, int iN);
void output(linkedList l);

//Ham main
int main() {
	int iN;
	cout << "Input amount: ";
	cin >> iN;

	linkedList l;
	inputTail(l, iN);

	output(l);

	system("pause");
	return 0;
}

void output(linkedList l) {
	for (Node *i = l.pHead; i != NULL; i = i->pNext) {
		cout << i->nData << " ";
	}
	cout << endl;
}

void inputTail(linkedList &l, int iN) {
	for (int i = 0; i < iN; i++) {
		int nX;
		cout << "Input data: ";
		cin >> nX;
		addTail(l, nX);
	}
}

void addTail(linkedList &l, int nX) {
	Node *pNew = createNode(nX);
	if (l.pHead == NULL) l.pHead = l.pTail = pNew;
	else {
		l.pTail->pNext = pNew;
		l.pTail = pNew;
	}
}

Node* createNode(int nX) {
	Node *p = new Node;
	if (p != NULL) {
		p->nData = nX;
		p->pNext = NULL;
	}
	return p;
}
