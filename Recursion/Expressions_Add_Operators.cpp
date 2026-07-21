/*
Problem: 282. Expression Add Operators
Platform: LeetCode
Difficulty: Hard

Approach:
- Backtracking
- Generate all possible numbers from the string.
- Try '+', '-', and '*' operators.
- Keep track of:
  1. Current evaluated value.
  2. Previous operand (to handle multiplication precedence).

Time Complexity: O(4^n)
Space Complexity: O(n) (excluding the output)
*/

// Code :-

class Solution {
public:
    vector<string> ans;

    void solve(string &num, int target, int index, long long value,
               long long prev, string expr) {

        if (index == num.size()) {
            if (value == target)
                ans.push_back(expr);
            return;
        }

        long long curr = 0;

        for (int i = index; i < num.size(); i++) {
            if (i > index && num[index] == '0')
                break;

            curr = curr * 10 + (num[i] - '0');

            string part = num.substr(index, i - index + 1);

            if (index == 0) {
                solve(num, target, i + 1, curr, curr, part);
            } else {
                solve(num, target, i + 1,
                      value + curr,
                      curr,
                      expr + "+" + part);
                solve(num, target, i + 1,
                      value - curr,
                      -curr,
                      expr + "-" + part);
                solve(num, target, i + 1,
                      value - prev + prev * curr,
                      prev * curr,
                      expr + "*" + part);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        ans.clear();
        solve(num, target, 0, 0, 0, "");
        return ans;
    }
};