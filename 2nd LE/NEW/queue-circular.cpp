class queue{
private:
	int size,front,rear;
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
	front = 0;
	rear = -1;
}

bool queue::enqueue(int x){
	if(size==MAX)
		return false;
	rear = (rear+1)%MAX;
	items[rear] = x;
	size++;
	return true;
}

bool queue::dequeue(){
	if(size==0)
		return false;
	front = (front + 1)%MAX;
	size--;
	return true;
}

int queue::front(){
	return items[front];
}

int queue::rear(){
	return items[rear];
}