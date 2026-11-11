class queue{
private:
	int size;
	int items[MAX];
public:
	queue();
	bool enqueue(int);
	bool dequeue();
	int front();
	int rear();
};

queue::queue(){
	size = 0;
}

bool queue::enqueue(int x){
	if(size==MAX)
		return false;
	items[size++] = x;
	return true;
}

bool queue::dequeue(){
	if(size==0)
		return false;
	for(int i=0; i<size-1; i++)
		items[i] = items[i+1];
	size--;
	return true;
}

int queue::front(){
	return items[0];
}

int queue::rear(){
	return items[size-1];
}