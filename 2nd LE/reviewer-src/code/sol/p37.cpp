// The span of today's price is the number of consecutive days, ending
// today, on which the price was <= today's price.
// Two stacks in step: a price, and how many days that price "covers".
class StockSpanner {
public:
    stack<int> prices;
    stack<int> spans;

    int next(int price) {
        int span = 1;                    // today itself
        while (!prices.empty() && prices.top() <= price) {
            span = span + spans.top();   // a cheaper day is absorbed, together
            prices.pop();                // with all the days it already covered
            spans.pop();
        }
        prices.push(price);
        spans.push(span);
        return span;
    }
};
