# Stack & Queue ADT: Summary of Prof's Notes

Source: `adt - stack.pdf`, `adt - queue.pdf`, `queue-array.cpp`, `queue-circular.cpp`, `queue-inherit.cpp`.
All code below follows the prof's style (`int` items, `MAX`, `bool` return for "did it work?"). Every version was compiled and tested.

> The prof's slides only list these operations: stack has **push / pop / top**, and queue has **enqueue / dequeue / front / rear**.
> I added `empty()` to the classes so the sample problems can use it. It is just `size==0` or `top==NULL`.

---

## 0. Big picture

| | **Stack** | **Queue** |
|---|---|---|
| Rule | **LIFO**: last in, first out | **FIFO**: first in, first out |
| Add | `push` at the **top** | `enqueue` at the **rear** |
| Remove | `pop` from the **top** | `dequeue` from the **front** |
| Peek | `top` | `front`, `rear` |
| Real-life (from slides) | stack of plates in a buffet, layoffs (last hired, first fired), backtracking from a dead end in a maze, barbecue/banana cue skewer, tennis ball can, one-car-wide garage | line at the cashier, line for relief goods, line at a bus station |
| Implementations | array, vector, SLL, DLL | array (regular, circular), vector, SLL, DLL |

**ADT idea:** the ADT says *what* the operations do. Each implementation is a different *how* that solves the same problem.

**Why have them at all?** Some problems need a list but only touch the ends. A queue uses the first and last element. A stack uses only the top.

---

## 1. STACK

### 1a. Array implementation

Slide trace: push 45, -3, 17, 1, 29, 94, 57, so `size = 7` and the top is index 6.

- **Initial values:** `size = 0`. The top would be `-1`.
- **Do we need `top`?** **No.** `top == size-1` always, so `size` alone is enough.
- **Pop just does `size--`.** The old values (the "worrisome 94 and 57") stay in the array. That is fine because they are outside `0..size-1`, and the next push **overwrites** them. Example: pop twice, then push 35 → `45 -3 17 1 29 35 57`, then push 68 → `... 35 68`.

```cpp
class stack{
private:
	int size;
	int items[MAX];
public:
	stack(){ size = 0; }
	bool push(int x){
		if(size==MAX) return false;     // full
		items[size++] = x;
		return true;
	}
	bool pop(){
		if(size==0) return false;       // empty
		size--;                         // no need to erase the value
		return true;
	}
	int top(){ return items[size-1]; }
};
```

| op | push | pop | top |
|---|---|---|---|
| array | O(1) | O(1) | O(1) |

The problem is that **space is fixed** (MAX). The next options use dynamic memory: a vector (like an array, but growing means copying into a bigger array) or a linked list.

### 1b. SLL with top at the TAIL (the prof's first try, which is SLOW)

The list keeps `head` and `top`. Push links the new node after `top`, so push is O(1).
**Pop has a traversal problem.** A node has no `prev`, so pop must walk from `head` to find the node *before* `top`.

Pop steps (slides): **traverse** with `tmp` → **save node to delete** (`del = top`) → **set new top** (`top = tmp`) → **disconnect top from del** (`top->next = NULL`) → **delete del**.

```cpp
struct node{ int item; node* next; };

class stack{
private:
	node *head, *tp;                    // tp = top (the tail)
public:
	stack(){ head = tp = NULL; }
	bool push(int x){
		node* n = new node; n->item = x; n->next = NULL;
		if(head==NULL) head = n;
		else tp->next = n;
		tp = n;
		return true;
	}
	bool pop(){
		if(head==NULL) return false;
		node* del = tp;                         // save node to delete
		if(head==tp){ head = tp = NULL; }       // only 1 node
		else{
			node* tmp = head;
			while(tmp->next!=tp) tmp = tmp->next;   // traverse  O(n)
			tp = tmp;                               // set new top
			tp->next = NULL;                        // disconnect top from del
		}
		delete del;
		return true;
	}
	int top(){ return tp->item; }
};
```

| op | push | pop | top |
|---|---|---|---|
| SLL (top = tail) | O(1) | **O(n)** | O(1) |

### 1c. DLL fix

Give each node a `prev` pointer. Then the new top is just `top->prev`, with no traversal.
Pop steps: **save node to delete** → **new top = del->prev** → **disconnect top from del** (`top->next = NULL`) → **delete del**.

```cpp
struct node{ int item; node *prev, *next; };

class stack{
private:
	node* tp;
public:
	stack(){ tp = NULL; }
	bool push(int x){
		node* n = new node; n->item = x; n->next = NULL; n->prev = tp;
		if(tp!=NULL) tp->next = n;
		tp = n;
		return true;
	}
	bool pop(){
		if(tp==NULL) return false;
		node* del = tp;                 // save node to delete
		tp = tp->prev;                  // new top
		if(tp!=NULL) tp->next = NULL;   // disconnect top from del
		delete del;
		return true;
	}
	int top(){ return tp->item; }
};
```
The DLL makes everything O(1), but it costs an extra pointer per node.

### 1d. "Do we really need a DLL?" **No.** Use an SLL with top at the HEAD (the final answer)

Push at the **front** of the list, so the list reads `top → -7 → 9 → 5 → 3 → ||`.
Pop steps: **save node to delete** → **set new top** (`top = top->next`) → **disconnect del from top** (`del->next = NULL`) → **delete del**.

```cpp
struct node{ int item; node* next; };

class stack{
private:
	node* tp;
public:
	stack(){ tp = NULL; }
	~stack(){ while(pop()); }
	bool push(int x){
		node* n = new node;
		n->item = x;
		n->next = tp;          // new node points to old top
		tp = n;                // new node is the top
		return true;
	}
	bool pop(){
		if(tp==NULL) return false;
		node* del = tp;        // save node to delete
		tp = tp->next;         // set new top
		del->next = NULL;      // disconnect del from top
		delete del;
		return true;
	}
	int top(){ return tp->item; }
};
```

### Stack complexity summary

| op | array | SLL (top=tail) | DLL | **SLL (top=head)** |
|---|---|---|---|---|
| push | O(1) | O(1) | O(1) | **O(1)** |
| pop | O(1) | **O(n)** | O(1) | **O(1)** |
| top | O(1) | O(1) | O(1) | **O(1)** |
| space | fixed MAX | dynamic | dynamic + prev ptr | **dynamic** |

---

## 2. QUEUE

### 2a. Regular array (`queue-array.cpp`)

Front is always index 0 and rear is `size-1`.
**Dequeue shifts everything left by 1**, which is O(n). Slide trace: dequeue from `45 -3 17 1 29 94 57` gives `-3 17 1 29 94 57 57`.
**"Two 57s?"** That is fine. `size` became 6, so the last 57 is garbage and the next enqueue (49) overwrites it.

- **Do we need `front`?** No, it is always 0.  **Do we need `rear`?** No, it is `size-1`.

```cpp
class queue{
private:
	int size;
	int items[MAX];
public:
	queue(){ size = 0; }
	bool enqueue(int x){
		if(size==MAX) return false;
		items[size++] = x;
		return true;
	}
	bool dequeue(){
		if(size==0) return false;
		for(int i=0; i<size-1; i++)     // shift left: O(n)
			items[i] = items[i+1];
		size--;
		return true;
	}
	int front(){ return items[0]; }
	int rear(){ return items[size-1]; }
};
```

| op | enqueue | dequeue | front | rear |
|---|---|---|---|---|
| array | O(1) | **O(n)** | O(1) | O(1) |

### 2b. Circular array (`queue-circular.cpp`): the fix for the O(n) dequeue

Idea ("addressing linear dequeue"): **don't shift. Move `front` forward instead.**
When `rear` reaches the last index, it **wraps around** to 0 using `% MAX`.

- Initial: `size = 0, front = 0, rear = -1`
- enqueue: `rear = (rear+1) % MAX; items[rear] = x; size++;`
- dequeue: `front = (front+1) % MAX; size--;`
- **How to know if full?** `size == MAX`. Empty: `size == 0`. You keep `size` because `front`/`rear` alone look the same when full and when empty.
- Useful formula: the k-th element from the front (0-based) is `items[(front+k) % MAX]`, and `rear == (front+size-1) % MAX`.

Slide trace (MAX = 13): front = 5, rear = 12, size = 8. Then enqueue 13 → **rear = 0** (wrapped) and size = 9. Enqueue 49 → rear = 1, and so on.

```cpp
class queue{
private:
	int size, f, r;          // see BUG NOTE below
	int items[MAX];
public:
	queue(){ size = 0; f = 0; r = -1; }
	bool enqueue(int x){
		if(size==MAX) return false;
		r = (r+1)%MAX;
		items[r] = x;
		size++;
		return true;
	}
	bool dequeue(){
		if(size==0) return false;
		f = (f+1)%MAX;
		size--;
		return true;
	}
	int front(){ return items[f]; }
	int rear(){ return items[r]; }
};
```

> **BUG NOTE (the prof's file won't compile as-is):** `queue-circular.cpp` has data members named `front` and `rear` **and** methods `front()` and `rear()`. C++ does not allow a data member and a member function with the same name. Renaming the data members (`f`, `r`) fixes it. This makes a good "spot the error" exam question.

| op | enqueue | dequeue | front | rear |
|---|---|---|---|---|
| circular array | O(1) | **O(1)** | O(1) | O(1) |

Space is still fixed, though. The next options are a vector (copying on growth is tricky because the data wraps around) or a linked list.

### 2c. SLL with `front` (head) and `rear` (tail)

**Enqueue at the rear (tail)** and **dequeue at the front (head)**. Both are O(1), with no traversal.
(Dequeuing at the tail would need the previous node, which is the same traversal problem as the stack.)

Dequeue steps: **del = front** → **front = front->next** → **delete del**. If the queue becomes empty, also set `rear = NULL`.

```cpp
struct node{ int item; node* next; };

class queue{
private:
	node *f, *r;
public:
	queue(){ f = r = NULL; }
	~queue(){ while(dequeue()); }
	bool enqueue(int x){
		node* n = new node; n->item = x; n->next = NULL;
		if(r==NULL) f = n;      // empty: new node is also the front
		else r->next = n;       // link after old rear
		r = n;
		return true;
	}
	bool dequeue(){
		if(f==NULL) return false;
		node* del = f;
		f = f->next;
		if(f==NULL) r = NULL;   // became empty (don't forget this!)
		delete del;
		return true;
	}
	int front(){ return f->item; }
	int rear(){ return r->item; }
};
```

DLL? It is not needed. An SLL already gives O(1) for everything, as long as you take out from the head.

### 2d. Queue via private inheritance (`queue-inherit.cpp`)

Reuse an existing `list` class. Inheriting **privately** hides all of list's methods from the outside world, so users can only call the queue operations.

```cpp
class queue : private list{
public:
	bool enqueue(int x){ return list::push_back(x); }
	bool dequeue(){      return list::erase(0); }
	int rear(){          return list::getItem(size-1); }
	int front(){         return list::getItem(0); }
};

int main(){
	queue q;
	q.push_front(5);          // ERROR: push_front is private in queue
	q.erase(0);               // ERROR
	cout<<q.getItem(0)<<endl; // ERROR
}
```
**Point of the demo:** the `main` is *supposed* to fail to compile. Private inheritance gives a queue that cannot be misused like a general list (no inserting in the middle, no `push_front`). With `public` inheritance those calls would compile and break FIFO.

### Queue complexity summary

| op | regular array | circular array | SLL (front=head, rear=tail) |
|---|---|---|---|
| enqueue | O(1) | O(1) | O(1) |
| dequeue | **O(n)** (shift) | O(1) | O(1) |
| front | O(1) | O(1) | O(1) |
| rear | O(1) | O(1) | O(1) |
| space | fixed | fixed | dynamic |

---

## 3. Cheat sheet (memorize)

- Stack array: `items[size++] = x` / `size--` / `items[size-1]`
- Stack SLL (best): push at head (`n->next = top; top = n`), pop at head.
- Queue regular array: dequeue = **shift left**, O(n).
- Queue circular: `r = (r+1)%MAX`, `f = (f+1)%MAX`, full ⇔ `size==MAX`, init `f=0, r=-1, size=0`.
- Queue SLL: enqueue at **tail**, dequeue at **head**. When it becomes empty, set `rear = NULL`.
- In an array, a "pop"/"dequeue" never erases the value. It is just outside the valid range and gets overwritten later.
- In an SLL, deleting the **last** node needs a traversal (O(n)). Deleting the **first** node is O(1).
