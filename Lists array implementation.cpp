#include <iostream>
#define MAXLIST 10
#define ListEntry int 
using namespace std;
typedef struct List {
	ListEntry entry[MAXLIST];
	int size;
}List;
void createlist(List* pl) {
	pl->size = 0;
}
int listempty(List* pl) {
	return (pl->size == 0);
}
int listfull(List* pl) {
	return(pl->size == MAXLIST);
}
int listsize(List* pl) {
	return pl->size;
}
void destorylist(List* pl) {
	pl->size = 0;
}
void insertlist(int p,ListEntry e, List* pl) {
	int i;
	for (i = pl->size - 1;i >= p;i--) {
		pl->entry[i + 1] = pl->entry[i];
	}
	pl->entry[p] = e;
	pl->size++;
}
void deletelist(int p, ListEntry* pe, List* pl) {
	*pe = pl->entry[p];
	for (int i = p + 1;i <= pl->size - 1;i++) {
		pl->entry[i - 1] = pl->entry[i];
	}
	pl->size--;
}
void retrievelist(int p, ListEntry* pe, List* pl) {
	*pe = pl->entry[p];
}
void replacelist(int p, ListEntry e, List* pl) {
	pl->entry[p] = e;
}
void traverselist(List* pl, void(*pf)(ListEntry)) {
	for (int i = 0;i <= pl->size - 1;i++) {
		(*pf)(pl->entry[i]);
	}
}
void display(int e) {
	cout << e << " ";
}
int main()
{
	List l;
	ListEntry e;
	createlist(&l);
	for (int i = 0;i < 9;i++) {
		if (!listfull(&l))
			cin >> e;
		else break;
		insertlist(i,e, &l);
	}
	insertlist(5, 20, &l);
	deletelist(6, &e, &l);
	cout << e << endl;
	replacelist(5, 0, &l);
	//deletelist(9, &e, &l);
	//cout << e;
	traverselist(&l, &display);
	cout << endl<<listsize(&l);
}

