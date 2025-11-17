#include<bits/stdc++.h>
using namespace std;

// Stack class for character data type (used for operators and parentheses)
class Stack{
  
   public :
       int top;           // Index of top element
       int capacity;      // Maximum size of stack
       char* arr;         // Dynamic array to store characters
      
       // Constructor to initialize stack with given size (default 100)
       Stack(int size = 100){
           capacity = size;
           arr = new char[capacity];
           top = -1;      // -1 indicates empty stack
       }

       // Push character onto stack
       void push(char x){
           if(isFull()){
               cout<<"Stack overflow";
               return;
           }
           arr[++top] = x;  // Increment top and add element
           return;
       }
       
       // Pop and return top character from stack
       char pop(){
           if(top==-1){
               cout<<"Stack underflow";
               return '\0';
           }
           return arr[top--];  // Return element and decrement top
       }

       // Return top character without removing it
       char getTop(){
           if(top==-1) return 0;
           return arr[top];
       }

       // Check if stack is empty
       bool isEmpty(){
           return top==-1;
       }

       // Check if stack is full
       bool isFull(){
           return top==capacity-1;
       }
};

// Stack class for integer data type (used for postfix evaluation)
class StackInt{
  
   public :
       int top;           // Index of top element
       int capacity;      // Maximum size of stack
       int* arr;          // Dynamic array to store integers

       // Constructor to initialize stack with given size (default 100)
       StackInt(int size = 100){
           capacity = size;
           arr = new int[capacity];
           top = -1;      // -1 indicates empty stack
       }

       // Push integer onto stack
       void push(int x){
           if(isFull()){
               cout<<"Stack overflow";
               return;
           }
           arr[++top] = x;  // Increment top and add element
           return;
       }

       // Pop and return top integer from stack
       int pop(){
           if(top==-1){
               cout<<"Stack underflow";
               return 0;
           }
           return arr[top--];  // Return element and decrement top
       }

       // Return top integer without removing it
       char getTop(){
           if(top==-1) return 0;
           return arr[top];
       }

       // Check if stack is empty
       bool isEmpty(){
           return top==-1;
       }

       // Check if stack is full
       bool isFull(){
           return top==capacity-1;
       }
};

// Function to return precedence of operators
// Higher value = higher precedence
int prec(char op){
   if(op == '^') return 3;                    // Exponentiation has highest precedence
   else if(op == '*' || op == '/') return 2;  // Multiplication and division
   else if(op == '+' || op == '-') return 1;  // Addition and subtraction have lowest precedence
   else return 0;                             // For parentheses and other characters
}

// Convert infix expression to postfix expression
void infixToPostfix(string s) {
   Stack st;              // Stack to store operators
   string result = "";    // String to build postfix expression

   // Iterate through each character in the infix expression
   for (int i = 0; i < s.length(); ++i) {
       char c = s[i];

       // If character is operand (letter or digit), add to result
       if (isalnum(c)) {
           result += c;
       } 
       // If character is '(', push to stack
       else if (c == '(') {
           st.push(c);
       } 
       // If character is ')', pop operators until '(' is found
       else if (c == ')') {
           while (!st.isEmpty() && st.getTop() != '(') {
               result += st.getTop();
               st.pop();
           }
           if (!st.isEmpty()) {
               st.pop();  // Remove '(' from stack
           }
       } 
       // If character is an operator
       else {
           // Pop operators with higher or equal precedence
           while (!st.isEmpty() && prec(s[i]) <= prec(st.getTop())) {
             result += st.getTop();
             st.pop();
           }
           st.push(c);  // Push current operator to stack
         }
       }     

   // Pop remaining operators from stack
   while (!st.isEmpty()) {
       result += st.getTop();
       st.pop();
   }

   cout << "Postfix expression: " << result << endl;
}

// Evaluate a postfix expression and return the result
int evaluatePostfix(string exp){
   StackInt st;  // Stack to store operands

   // Iterate through each character in postfix expression
   for(int i=0; i < exp.length(); ++i){
       char c = exp[i];

       // If character is a digit, push to stack
       if(isdigit(c)){
           st.push(c - '0');  // Convert char to int
       }
       // If character is an operator
       else {
           // Pop two operands
           int val1 = st.getTop();  // Second operand
           st.pop();
           int val2 = st.getTop();  // First operand
           st.pop();
          
           // Perform operation and push result back
           switch(c){
               case '+': st.push(val2 + val1); break;
               case '-': st.push(val2 - val1); break;
               case '*': st.push(val2 * val1); break;
               case '/': st.push(val2 / val1); break;
               case '^': st.push(pow(val2, val1)); break;
           }
       }
   }
   // Final result is the only element left in stack
   return st.getTop();
}

int main(){
   string expression;
   cout<<"Enter the expression to be converted.";
   cin>>expression;
   cout << "Infix expression: " << expression << endl;
   infixToPostfix(expression);  // Convert and display postfix expression
   return 0;
}
