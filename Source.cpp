#include <iostream>
using namespace std;

//DN CTDL
struct Node {
	int iData;
	Node *pNext;
};

struct LinkedList {
	Node *pHead;
	Node *pTail;
	LinkedList() {
		pHead = NULL;
		pTail = NULL;
	}
};

bool isEmpty(LinkedList linkedList);
Node *creatNode(int nX);
void addHead(LinkedList &linkedList, int nX);
void addTail(LinkedList &linkedList, int nX);
void inputHead(LinkedList &linkedList, int iN);
void inputTail(LinkedList &linkedList, int iN);
void output(LinkedList linkedList);
int size(LinkedList linkedList);
Node *doAdvance(LinkedList linkedList, int nX);
void doInsert(LinkedList &linkedList, int nX, int nData);
void doInsertAfter(LinkedList &linkedList, int nX, int nData);
void deleteHead(LinkedList &linkedList);
void deleteTail(LinkedList &linkedList);
void doErase(LinkedList &linkedList, int nX);
void doErase2(LinkedList &linkedList, int nX);
void doRemove(LinkedList &linkedList, int nX);
void doRemove2(LinkedList &linkedList, int nX);
Node *doAdvance_X(LinkedList linkedList, int nX); //tra ve con tro tai nut dau tien co gia tri nX
void insertYAfterX(LinkedList &linkedList, int nX, int nY);
void deleteAfterX(LinkedList &linkedList, int nX);
int timKiemTuanTu(LinkedList linkedList, int nKey);
void interchangeSort(LinkedList &linkedList);
void selectionSort(LinkedList &linkedList);

int main() {
	LinkedList linkedList;
	int iN;
	cout << "Nhap n: ";
	cin >> iN;
	//inputHead(linkedList, iN);
	inputTail(linkedList, iN);

	//doInsertAfter(linkedList, 5, 600);

	//deleteHead(linkedList);

	output(linkedList);

	//deleteTail(linkedList);

	//doRemove2(linkedList, 2);

	//deleteAfterX(linkedList, 4);

	//insertYAfterX(linkedList, 3, 6);

	//cout << timKiemTuanTu(linkedList, 7) << endl;

	//interchangeSort(linkedList);

	selectionSort(linkedList);

	output(linkedList);
	cout << "Size: " << size(linkedList) << endl;
	system("pause");
	return 0;
}

void selectionSort(LinkedList &linkedList) {
	for (Node *i = linkedList.pHead; i->pNext != NULL; i=i->pNext) {
		Node *pMin = i;
		for (Node *j = i->pNext; j != NULL; j = j->pNext) {
			if (j->iData < pMin->iData) {
				pMin = j;
			}
		}
		swap(i->iData, pMin->iData);
	}
}

void interchangeSort(LinkedList &linkedList) {
	for (Node *i = linkedList.pHead; i->pNext != NULL; i = i->pNext) {
		for (Node *j = i->pNext; j != NULL; j = j->pNext) {
			if (i->iData > j->iData) {
				swap(i->iData, j->iData);
			}
		}
	}
}

int timKiemTuanTu(LinkedList linkedList, int nKey) {
	int j = 1;
	for (Node *i = linkedList.pHead; i != NULL; i = i->pNext) {
		if (i->iData == nKey) {
			return j;
		}
		j++;
	}
	return -1;
}

void deleteAfterX(LinkedList &linkedList, int nX) {
	Node *q = doAdvance_X(linkedList, nX);
	if (q != NULL) {
		Node *p = q->pNext;
		if (p != NULL) {
			q->pNext = p->pNext;
			if (p == linkedList.pTail) {
				linkedList.pTail = q;
			}
		}
		delete p;
	}
}

void insertYAfterX(LinkedList &linkedList, int nX, int nY) {
	Node *p = doAdvance_X(linkedList, nX);
	if (p != NULL) {
		Node *pNew = creatNode(nY);
		pNew->pNext = p->pNext;
		p->pNext = pNew;
		if (p == linkedList.pTail) {
			linkedList.pTail = pNew;
		}
	}
}

Node *doAdvance_X(LinkedList linkedList, int nX) {
	Node *p = linkedList.pHead;
	while (p != NULL && p->iData != nX) {
		p = p->pNext;
	}
	return p;
}

void doRemove2(LinkedList &linkedList, int nX) {
	int j = 1;
	for (Node *i = linkedList.pHead; i != NULL;) {
		if (i->iData == nX) {
			//doErase2(linkedList, j);
			cout << j << " ";
		}
		else {
			i = i->pNext;
			j++;
		}
	}
}

void doRemove(LinkedList &linkedList, int nX) {
	Node *p, *q;
	while (linkedList.pHead != NULL && linkedList.pHead->iData == nX) {
		p = linkedList.pHead;
		linkedList.pHead = p->pNext;
		if (linkedList.pHead == NULL) {
			linkedList.pTail = NULL;
			delete p;
		}
	}
	q = linkedList.pHead;
	while (q != NULL && q->pNext != NULL) {
		if (q->pNext->iData == nX) {
			p = q->pNext;
			q->pNext = p->pNext;
			if (p == linkedList.pTail) {
				linkedList.pTail = q;
			}
			delete p;
		}
		else {
			q = q->pNext;
		}
	}
}

void doErase2(LinkedList &linkedList, int nX) {
	Node *p;
	Node *q;
	if (linkedList.pHead != NULL) {
		if (nX == 1) {
			p = linkedList.pHead;
			linkedList.pHead = p->pNext;
			if (p == linkedList.pTail) {
				linkedList.pTail = NULL;
			}
		}
		else {
			q = doAdvance(linkedList, nX - 1);
			p = doAdvance(linkedList, nX);
			if (p != NULL) {
				q->pNext = p->pNext;
				if (p = linkedList.pTail) {
					linkedList.pTail = q;
				}
			}
		}
		delete p;
	}
}

void doErase(LinkedList &linkedList, int nX) {
	if (isEmpty(linkedList) == true) return;
	if (nX == 1) deleteHead(linkedList);
	else if (nX == size(linkedList)) deleteTail(linkedList);
	else {
		Node *q = doAdvance(linkedList, nX - 1);
		Node *p = q->pNext;
		q->pNext = p->pNext;
		delete p;
	}
}

void deleteTail(LinkedList &linkedList) {
	if (isEmpty(linkedList) == true) return;
	else if (linkedList.pHead->pNext == NULL) {
		Node *p = linkedList.pHead;
		linkedList.pHead = linkedList.pTail = NULL;
		delete p;
	}
	else {
		Node *q = doAdvance(linkedList, size(linkedList) - 1);
		Node *p = q->pNext;
		q->pNext = NULL;
		linkedList.pTail = q;
		delete p;
	}
}

void deleteHead(LinkedList &linkedList) {
	if (isEmpty(linkedList) == true) return;

	Node *p = linkedList.pHead;
	linkedList.pHead = p->pNext;

	if (linkedList.pHead == NULL) linkedList.pTail = NULL;
	delete p;
}

void doInsertAfter(LinkedList &linkedList, int nX, int nData) {
	Node *pNew = creatNode(nData);
	Node *q = doAdvance(linkedList, nX);
	if (q != NULL) {
		pNew->pNext = q->pNext;
		q->pNext = pNew;
		if (pNew->pNext == NULL) {
			linkedList.pTail = pNew;
		}
	}
}

void doInsert(LinkedList &linkedList, int nX, int nData) {
	Node *pNew = creatNode(nData);
	if (nX == 1) {
		if (linkedList.pHead == NULL)
			linkedList.pHead = linkedList.pTail = pNew;
		else
			pNew->pNext = linkedList.pHead;
		linkedList.pHead = pNew;
	}
	Node *q = doAdvance(linkedList, nX - 1);
	if (q != NULL) {
		pNew->pNext = q->pNext;
		q->pNext = pNew;
		if (pNew->pNext == NULL) {
			linkedList.pTail = pNew;
		}
	}
}

Node *doAdvance(LinkedList linkedList, int nX) {
	if (nX < 1 || nX > size(linkedList)) return NULL;
	Node *p = linkedList.pHead;
	int i = 1;
	while (i < nX && p != NULL) {
		p = p->pNext;
		i++;
	}
	return p;
}


int size(LinkedList linkedList) {
	int count = 0;
	for (Node *i = linkedList.pHead; i != NULL; i = i->pNext) {
		count++;
	}
	return count;
}

void output(LinkedList linkedList) {
	Node *p = linkedList.pHead;
	while (p != NULL) {
		cout << p->iData << " ";
		p = p->pNext;
	}
	cout << endl;
}

void inputTail(LinkedList &linkedList, int iN) {
	for (int i = 0; i < iN; i++) {
		int data;
		cout << "Nhap data: ";
		cin >> data;
		addTail(linkedList, data);
	}
}

void inputHead(LinkedList &linkedList, int iN) {
	for (int i = 0; i < iN; i++) {
		int data;
		cout << "Nhap data: ";
		cin >> data;
		addHead(linkedList, data);
	}
}

void addTail(LinkedList &linkedList, int nX) {
	Node *pNew = creatNode(nX);
	if (isEmpty(linkedList) == true) {
		linkedList.pHead = linkedList.pTail = pNew;
	}
	else {
		linkedList.pTail->pNext = pNew;
		linkedList.pTail = pNew;
	}
}

void addHead(LinkedList &linkedList, int nX) {
	Node *pNew = creatNode(nX);
	if (isEmpty(linkedList) == true) {
		linkedList.pHead = linkedList.pTail = pNew;
	}
	else {
		pNew->pNext = linkedList.pHead;
		linkedList.pHead = pNew;
	}
}

Node *creatNode(int nX) {
	Node *p = new Node;
	if (p == NULL) exit(1);
	p->iData = nX;
	p->pNext = NULL;
	return p;
}

bool isEmpty(LinkedList linkedList) {
	return linkedList.pHead == NULL;
}