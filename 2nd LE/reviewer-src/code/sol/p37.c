// The span of today's price is the number of consecutive days, ending
// today, on which the price was <= today's price.
// Two stacks in step: a price, and how many days that price "covers".
typedef struct {
    stack prices;
    stack spans;
} stockSpanner;

void ssInit(stockSpanner *s) {
    stInit(&s->prices);
    stInit(&s->spans);
}

int ssNext(stockSpanner *s, int price) {
    int span = 1;                    // today itself
    int p, d;
    while (stTop(&s->prices, &p) && p <= price) {
        stPop(&s->prices, &p);       // a cheaper day is absorbed, together
        stPop(&s->spans, &d);        // with all the days it already covered
        span = span + d;
    }
    stPush(&s->prices, price);
    stPush(&s->spans, span);
    return span;
}
