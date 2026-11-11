class queue : private list{
public:
	bool enqueue(int x){return list::push_back(x);}
	bool dequeue(){return list::erase(0);}
	int rear(){return list::getItem(size-1);}
	int front(){return list::getItem(0);}
};

int main(){
	queue q;
	q.push_front(5);
	q.erase(0);
	cout<<q.getItem(0)<<endl;
}