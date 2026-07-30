/*
Approach:
- Use a monotonic decreasing stack to maintain previous stock prices.
- Store the span corresponding to each price.
- For every new price:
  1. Pop all previous prices that are less than or equal to the current price.
  2. Accumulate their spans.
  3. Push the current price and its span.
- The accumulated span is the answer for the current price.

Time Complexity: O(1) Amortized per query
Space Complexity: O(n)
*/

// Code :-

class StockSpanner {
public:
    stack<pair<int, int>> st; 

    StockSpanner() {
    }

    int next(int price) {
        int span = 1;

        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */