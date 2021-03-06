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
bool kiemTraSNT(int nX);
void outputSNT(linkedList l);
void deleteHead(linkedList &l);
void deleteHeadKtime(linkedList &l, int nK);
int size(linkedList l);
Node *doAdvance(linkedList l, int nViTri);
void doErase(linkedList &l, int nViTri);
void deleteRepeat(linkedList &l);
int countTimeAppear(linkedList l, int nX);
Node *doAdvanceOpposite(linkedList l, int nViTri);
void insertSortedList(linkedList &l, int nX);
void swapList(linkedList &l);
bool compareList(linkedList l1, linkedList l2);

//Ham main
int main() {
	//int iN;
	//cout << "Input amount: ";
	//cin >> iN;

	//linkedList l;
	//inputTail(l, iN);

	//output(l);

	//outputSNT(l);

	//deleteHeadKtime(l, 3);

	//cout << "\n- Before: \n";
	//output(l);

	//cout << "Size: " << size(l) << endl;

	//deleteRepeat(l);

	//Node *p = doAdvanceOpposite(l, 2);
	//cout << "Data: " << p->nData << endl;

	//doErase(l, 0);

	//cout << countTimeAppear(l, 2) << endl;

	//insertSortedList(l, 4);

	//swapList(l);

	//cout << "\n- After: \n";
	//output(l);
	//cout << "Tail: " << l.pTail->nData << endl;

	linkedList l1;
	linkedList l2;

	int iN;
	cout << "Input amount l1: ";
	cin >> iN;

	inputTail(l1, iN);

	cout << "Input amount l2: ";
	cin >> iN;

	inputTail(l2, iN);

	cout << compareList(l1, l2) << endl;

	system("pause");
	return 0;
}

bool compareList(linkedList l1, linkedList l2) {
	if (size(l1) != size(l2)) return 0;
	Node *j = l2.pHead;
	for (Node *i = l1.pHead; i != NULL; i = i->pNext) {
		if (i->nData != j->nData) {
			return 0;
		}
		j = j->pNext;
	}
	return 1;
}

void swapList(linkedList &l) {
	for (Node *i = l.pHead; i != NULL && i->pNext != NULL; i = i->pNext->pNext) {
		swap(i->nData, i->pNext->nData);
	}
}

void insertSortedList(linkedList &l, int nX) {
	Node *pNew = createNode(nX);
	if (nX < l.pHead->nData) {
		pNew->pNext = l.pHead;
		l.pHead = pNew;
		return;
	}
	if (nX > l.pTail->nData) {
		l.pTail->pNext = pNew;
		l.pTail = pNew;
		return;
	}
	int i = 1;
	for (Node *p = l.pHead; p != NULL;) {
		if (nX > p->nData) {
			i++;
			p = p->pNext;	
		}
		else {
			Node *q = doAdvance(l, i - 1);
			pNew->pNext = q->pNext;
			q->pNext = pNew;
			break;
		}
	}
}

Node *doAdvanceOpposite(linkedList l, int nViTri) {
	if (nViTri < 1 || nViTri > size(l)) return NULL;

	Node *p = l.pHead;
	int i = size(l);
	while (i > nViTri) {
		p = p->pNext;
		i--;
	}

	return p;
}

int countTimeAppear(linkedList l, int nX) {
	int count = 0;

	for (Node *i = l.pHead; i != NULL; i = i->pNext) {
		if (i->nData == nX) count++;
	}

	return count;
}

void deleteRepeat(linkedList &l) {
	for (Node *i = l.pHead; i != NULL; i = i->pNext) {
		Node *q = i;
		while (q != NULL && q->pNext != NULL) {
			if (q->pNext->nData == i->nData) {
				Node *p = q->pNext;
				q->pNext = p->pNext;
				if (p == l.pTail) l.pTail = q;
				delete p;
			}
			else {
				q = q->pNext;
			}
		}

	}
}

void doErase(linkedList &l, int nViTri) {
	if (l.pHead == NULL) return;
	if (nViTri < 1 || nViTri > size(l)) return;

	if (nViTri == 1) {
		Node *p = l.pHead;
		l.pHead = p->pNext;

		if(l.pHead == NULL) l.pTail = NULL;

		delete p;
	} else {
		Node *q = doAdvance(l, nViTri - 1);
		Node *p = doAdvance(l, nViTri);

		q->pNext = p->pNext;

		if (p == l.pTail) l.pTail = q;

		delete p;
	}
}

Node *doAdvance(linkedList l, int nViTri) {
	if (nViTri < 1 || nViTri > size(l)) return NULL;

	Node *p = l.pHead;
	int i = 1;
	while (i < nViTri) {
		p = p->pNext;
		i++;
	}

	return p;
}

int size(linkedList l) {
	Node *p = l.pHead;
	int count = 0;

	while(p != NULL) {
		count++;
		p = p->pNext;
	}

	return count;
}

void deleteHeadKtime(linkedList &l, int nK) {
	while (nK--) {
		deleteHead(l);
	}
}

void deleteHead(linkedList &l) {
	if (l.pHead == NULL) return;

	Node *p = l.pHead;

	l.pHead = p->pNext;

	if (l.pHead == NULL) l.pTail = NULL;

	delete p;
}

void outputSNT(linkedList l) {

	for (Node *i = l.pHead; i != NULL; i = i->pNext) {

		if (kiemTraSNT(i->nData)) {
			cout << i->nData << " ";
		}		

	}

	cout << endl;
}

bool kiemTraSNT(int nX) {
	int count = 0;
	for (int i = 1; i <= nX; i++) {
		if (nX % i == 0) {
			count++;
		}
	}
	if (count == 2) {
		return 1;
	}
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
