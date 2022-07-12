

#include <stack>
#include <string>
#include <cmath>
#include <iostream>

/**
 * Exercise 9.1 Calculator Reverse Polish Notation
 * @return
 */
bool isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
        return true;
    }
    return false;
}

bool isOperand(char ch){
    if(ch >= '0' && ch <= '9'){
        return true;
    }
    return false;
}

double operation(double a, double b, char op){
    switch (op) {
        case '+':
            return b+a;
        case '-':
            return b-a;
        case '*':
            return b*a;
        case '/':
            return b/a;
        default:
            return NAN;
    }
}

int main() {

   std::string rpn { "55*22*+"};
   double a;
   double b;
   std::stack<double> stack;
   std::string::iterator i;
   for(i = rpn.begin(); i != rpn.end(); ++i){
       if(isOperator(*i)){
           a = stack.top();
           stack.pop();
           b = stack.top();
           stack.pop();
           stack.push(operation(a,b, *i));
       }else if(isOperand(*i)){
           double temp = (*i) - '0';
           stack.push(temp);
       }
   }
   double result = stack.top();
   stack.pop();
   std::cout << result;



    return 0;
}
