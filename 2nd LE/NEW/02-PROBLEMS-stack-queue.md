# Stack & Queue: Sample Problems + Solutions

Uses the classes from `01-SUMMARY-stack-queue.md`: `stack` (push/pop/top/empty) and `queue` (enqueue/dequeue/front/rear/empty).
All answers were checked by compiling and running them.

Try each problem first, then scroll to its **Solution**.

---

## PART A: Tracing

### Problem 1: Stack trace
Starting with an empty stack, run:
`push 4, push 7, pop, push 2, push 9, top, pop, pop, push 6`
(a) What does `top` print? (b) What are the final contents, bottom → top?

**Solution**
| op | stack (bottom → top) |
|---|---|
| push 4 | 4 |
| push 7 | 4 7 |
| pop | 4 |
| push 2 | 4 2 |
| push 9 | 4 2 9 |
| top | prints **9** |
| pop | 4 2 |
| pop | 4 |
| push 6 | 4 6 |

(a) **9**  (b) **4 6** (top = 6)

---

### Problem 2: Regular array queue (MAX = 5), show the actual array
`enqueue 8, enqueue 1, enqueue 6, dequeue, enqueue 3, enqueue 5, dequeue`
Give the **raw** array contents (including leftovers), `size`, `front()`, and `rear()`.

**Solution** (dequeue shifts left, and the last cell keeps its old value)
| op | items[0..4] | size |
|---|---|---|
| enq 8,1,6 | 8 1 6 ? ? | 3 |
| dequeue | 1 6 **6** ? ? | 2 |
| enq 3 | 1 6 3 ? ? | 3 |
| enq 5 | 1 6 3 5 ? | 4 |
| dequeue | 6 3 5 **5** ? | 3 |

Final: `6 3 5 5 ?`, **size = 3, front() = 6, rear() = 5**. The second 5 is garbage because it is outside `0..size-1`.

---

### Problem 3: Circular queue (MAX = 5, init front=0, rear=-1, size=0)
`enqueue 10, 20, 30, 40` → `dequeue, dequeue` → `enqueue 50, 60, 70` → `enqueue 80`
(a) Give the raw array, front, rear, and size. (b) Does enqueue 80 succeed? (c) Then do `dequeue ×3`. What are front, rear, size, and front()?

**Solution**
| op | items[0..4] | front | rear | size |
|---|---|---|---|---|
| enq 10,20,30,40 | 10 20 30 40 ? | 0 | 3 | 4 |
| deq, deq | 10 20 30 40 ? | 2 | 3 | 2 |
| enq 50 | 10 20 30 40 50 | 2 | 4 | 3 |
| enq 60 | **60** 20 30 40 50 | 2 | **0** (wrap) | 4 |
| enq 70 | 60 **70** 30 40 50 | 2 | 1 | 5 |
| enq 80 | **fails**, size==MAX | 2 | 1 | 5 |

(a) `60 70 30 40 50`, **front = 2, rear = 1, size = 5**, front() = 30, rear() = 70
(b) **No**, the queue is full and `enqueue` returns `false`.
(c) front = (2+3)%5 = **0**, rear = **1**, size = **2**, front() = **60**

---

### Problem 4: Stack array leftovers
MAX = 6. `push 1,2,3,4`, `pop, pop`, `push 9`. Give the raw array and `size`.

**Solution**
`1 2 3 4 ? ?` → pop twice → size = 2 (array unchanged) → push 9 writes `items[2]`:
**`1 2 9 4 ? ?`, size = 3**. The 4 is garbage and top() = 9.

---

## PART B: Theory / Complexity

### Problem 5: Fill in the table

| | push/enqueue | pop/dequeue |
|---|---|---|
| stack: array | | |
| stack: SLL, top at tail | | |
| stack: SLL, top at head | | |
| queue: regular array | | |
| queue: circular array | | |
| queue: SLL front=head, rear=tail | | |

**Solution**: O(1)/O(1), O(1)/**O(n)**, O(1)/O(1), O(1)/**O(n)**, O(1)/O(1), O(1)/O(1)

### Problem 6: Short answers
1. In the stack array implementation, why don't we need a `top` data member?
2. Why does SLL pop with top at the tail take O(n)?
3. "Do we really need a DLL for a stack?" Explain.
4. Circular queue: why keep `size` instead of only `front` and `rear`?
5. Why must SLL-queue `dequeue` set `rear = NULL` when the last node is removed?
6. In `queue-inherit.cpp`, why does `q.push_front(5)` fail to compile?
7. In `queue-circular.cpp`, why does the file fail to compile?

**Solution**
1. `top` is always `size-1`, so storing it is redundant.
2. There is no `prev` pointer, so you must traverse from head to find the node before the top in order to make it the new top.
3. No. Push and pop at the **head** of an SLL, and both are O(1) with no extra `prev` pointer.
4. With only `front` and `rear`, a full queue and an empty queue can have the same front/rear relationship. `size==0` vs `size==MAX` tells them apart.
5. Otherwise `rear` is a dangling pointer to deleted memory, and the next `enqueue` would do `rear->next = n` on freed memory.
6. Private inheritance makes all of `list`'s public members **private** inside `queue`, so only enqueue/dequeue/front/rear are accessible.
7. The data members `front`/`rear` have the same names as the methods `front()`/`rear()`, and C++ does not allow that. Rename the data members (e.g. `f`, `r`).

---

## PART C: Write the code

### Problem 7: Write the circular-queue member `int get(int k)` (k-th from front, 0-based) and `bool full()`

**Solution**
```cpp
int queue::get(int k){ return items[(f+k)%MAX]; }
bool queue::full(){ return size==MAX; }
```
(Using Problem 3's state: `get(3)` = items[(2+3)%5] = items[0] = **60**.)

---

### Problem 8: Balanced brackets
Return `true` if every `( [ {` is closed in the right order. `"{[()()]}"` → true, `"([)]"` → false, `"(("` → false.

**Solution**
```cpp
bool balanced(string s){
	stack st;
	for(char c : s){
		if(c=='(' || c=='[' || c=='{') st.push(c);
		else if(c==')' || c==']' || c=='}'){
			if(st.empty()) return false;          // closer with no opener
			char o = st.top(); st.pop();
			if((c==')'&&o!='(') || (c==']'&&o!='[') || (c=='}'&&o!='{'))
				return false;                     // wrong type
		}
	}
	return st.empty();                            // leftover openers?
}
```

---

### Problem 9: Reverse a queue using a stack
`[1 2 3 4]` (front→rear) becomes `[4 3 2 1]`.

**Solution**
```cpp
void reverseQueue(queue &q){
	stack st;
	while(!q.empty()){ st.push(q.front()); q.dequeue(); }
	while(!st.empty()){ q.enqueue(st.top()); st.pop(); }
}
```
O(n).

---

### Problem 10: Queue using two stacks
**Solution**: `in` takes the pushes. When `out` is empty, pour all of `in` into `out`, which reverses the order so the oldest item ends up on top.
```cpp
class queue2{
private:
	stack in, out;
	void move(){
		if(out.empty())
			while(!in.empty()){ out.push(in.top()); in.pop(); }
	}
public:
	bool enqueue(int x){ return in.push(x); }
	bool dequeue(){ move(); return out.pop(); }
	int front(){ move(); return out.top(); }
	bool empty(){ return in.empty() && out.empty(); }
};
```
Each item moves at most once, so the cost is amortized O(1) per operation.

---

### Problem 11: Stack using one queue
**Solution**: after enqueuing the new item, rotate the older `n` items behind it so the newest is at the front.
```cpp
class stackQ{
private:
	queue q; int n = 0;
public:
	bool push(int x){
		q.enqueue(x);
		for(int i=0; i<n; i++){ q.enqueue(q.front()); q.dequeue(); }
		n++; return true;
	}
	bool pop(){ if(n==0) return false; n--; return q.dequeue(); }
	int top(){ return q.front(); }
	bool empty(){ return n==0; }
};
```
push O(n), pop/top O(1).

---

### Problem 12: Evaluate postfix (single digits)
`"23*54*+9-"` → (2·3)+(5·4)−9 = **17**

**Solution**: push digits. On an operator, pop **b first, then a**, and push `a op b`.
```cpp
int evalPostfix(string s){
	stack st;
	for(char c : s){
		if(c>='0' && c<='9') st.push(c-'0');
		else{
			int b = st.top(); st.pop();
			int a = st.top(); st.pop();
			if(c=='+') st.push(a+b);
			else if(c=='-') st.push(a-b);
			else if(c=='*') st.push(a*b);
			else if(c=='/') st.push(a/b);
		}
	}
	return st.top();
}
```
Trace: 2 → 2 3 → **6** → 6 5 → 6 5 4 → 6 **20** → **26** → 26 9 → **17**.

---

### Problem 13: Palindrome with a stack AND a queue
**Solution**: the stack gives the characters reversed and the queue gives them in order, so compare them one by one.
```cpp
bool isPalindrome(string s){
	stack st; queue q;
	for(char c : s){ st.push(c); q.enqueue(c); }
	while(!st.empty()){
		if(st.top()!=q.front()) return false;
		st.pop(); q.dequeue();
	}
	return true;
}
```
`"racecar"` → true, `"stack"` → false.

---

### Problem 14: Decimal to binary using a stack
13 → `"1101"`

**Solution**
```cpp
string toBinary(int n){
	if(n==0) return "0";
	stack st; string r;
	while(n>0){ st.push(n%2); n/=2; }       // remainders come out reversed...
	while(!st.empty()){ r += char('0'+st.top()); st.pop(); }  // ...stack fixes it
	return r;
}
```

---

### Problem 15: Sort a stack using one extra stack (smallest ends on top)
`[5 1 4 2 3]` (bottom→top) → popping gives 1 2 3 4 5.

**Solution**: keep `tmp` sorted with the largest on top. Before placing `x`, move every bigger item back into `s`.
```cpp
void sortStack(stack &s){
	stack tmp;
	while(!s.empty()){
		int x = s.top(); s.pop();
		while(!tmp.empty() && tmp.top() > x){ s.push(tmp.top()); tmp.pop(); }
		tmp.push(x);
	}
	while(!tmp.empty()){ s.push(tmp.top()); tmp.pop(); }   // flip so smallest is on top
}
```
O(n²).

---

### Problem 16: Write SLL stack pop the prof's way (top at TAIL, with `head`)
**Solution** (traverse → set new top → disconnect → delete):
```cpp
bool stack::pop(){
	if(head==NULL) return false;
	node* del = tp;
	if(head==tp){ head = tp = NULL; }
	else{
		node* tmp = head;
		while(tmp->next!=tp) tmp = tmp->next;
		tp = tmp;
		tp->next = NULL;
	}
	delete del;
	return true;
}
```
Common mistakes: forgetting the 1-node case (`head` must become NULL too), and forgetting `tp->next = NULL` (which leaves a dangling pointer).
