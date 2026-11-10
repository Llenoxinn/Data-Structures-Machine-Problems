// libs:
#include <stack>
#include <queue>
#include <deque>

int main() {
    stack<int> s;
    s.push(1); s.push(2);
    int t = s.top();             // read first ...
    s.pop();                     // ... then pop: pop() returns void
    queue<int> q;
    q.push(1); q.push(2);
    int f = q.front();
    q.pop();
    deque<int> d;
    d.push_front(1); d.push_back(2); d.push_front(0);
    int a = d.front(), b = d.back(), c = d[1];   // random access
    d.pop_front(); d.pop_back();
    if (!s.empty() && s.top() == 1) s.pop();     // test empty() first
    cout << t << " " << f << " " << a << " " << b << " " << c << " "
         << s.size() << " " << q.size() << " " << d.size() << endl;
    return 0;
}
