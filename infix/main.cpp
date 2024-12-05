#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    return 0;
}

double applyOperation(double a, double b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    if (op == '%') return fmod(a, b);
    return 0;
}

string infixToPostfix(string s) {
    stack<char> st;
    string res = "";
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) res += s[i];
        else if (s[i] == '(') st.push(s[i]);
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && precedence(st.top()) >= precedence(s[i])) {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}

double evalPostfix(string postfix) {
    stack<double> stk;
    for (int i = 0; i < postfix.size(); i++) {
        if (isdigit(postfix[i])) {
            stk.push(postfix[i] - '0');
        } else {
            double val2 = stk.top(); stk.pop();
            double val1 = stk.top(); stk.pop();
            stk.push(applyOperation(val1, val2, postfix[i]));
        }
    }
    return stk.top();
}

int main() {
    string exp;
    cout << "Type your infix expression: ";
    cin >> exp;
    string postfix = infixToPostfix(exp);
    cout << "Converted Postfix string is: " << postfix << endl;
    cout << "Result is: " << evalPostfix(postfix) << endl;
    return 0;
}
