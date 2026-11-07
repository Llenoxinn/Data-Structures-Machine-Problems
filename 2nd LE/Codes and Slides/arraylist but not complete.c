#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct{
	int items[MAX];
	int size;
}list;

void init(list*);
int append(list*,int);
void display(list);
int insertFront(list*,int);
int isFull(list);
int removeLast(list*); 
int removeFirst(list*);
int itemAt(list,int);
int setItem(list*,int,int);

int main(){
	list l;
	int i;
	init(&l);

	for(i=8; i<1124;){
		if(append(&l,i))
			display(l);
		else{
			printf("My apologies. The List is full!\n");
			break;
		}
		i = i + 20;
	}
	removeFirst(&l);
	display(l);
	removeLast(&l);
	display(l);
	insertFront(&l,69);
	display(l);
	return 0;

}

void init(list *l){
	l->size = 0;
}

void display(list l){
	int i;

	for(i=0; i<l.size; i++)
		printf("%i ",l.items[i]);

	printf("\n");
}

int append(list *l, int x){
	if(l->size == MAX)
		return 0;
	else{
		l->items[l->size++] = x;
		//l->size++;
		return 1;
	}
}

int insertFront(list* l,int x){
	int i;
	if(isFull(*l))
		return 0;
	else{
		for(i=l->size; i>0; i--)
			l->items[i] = l->items[i-1];
		l->items[i] = x;
		l->size++;
		return 1;
	}
}

int isFull(list l){
	return l.size==MAX;
}

int removeLast(list* l){
	if(l->size==0)
		return 0;
	else{
		l->size--;
		return 1;
	}
}

int removeFirst(list* l){
	int i;
	if(l->size==0)
		return 0;
	else{
		for(i=0; i<l->size-1; i++)
			l->items[i] = l->items[i+1];
		l->size--;
		return 1;
	}
}

int setItem(list *l, int x, int p){
	if(p<1 || p>l->size)
		return 0;
	else{
		l->items[p-1] = x;
		return 1;
	}
}

int itemAt(list l, int p){
	return l.items[p-1];
}