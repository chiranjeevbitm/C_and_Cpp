 #include<iostream>

 #define MAX 1000

 class Stack{
   int top;
 public:
   int a[MAX];
   Stack() {top = -1;}
   bool push(int x);
   int pop();
   bool isEmpty();
 };

 bool Stack::push(int x){
   if(top>=MAX-1){
     std::cout << "Overflow" << '\n';
     return false;
   }else{
     a[++top] = x;
     std::cout << x << " pushed into stack " << '\n';
     return true;
   }

 }
 int Stack::pop(){
   if(top<0){
     std::cout << "Underflow" << '\n';
     return 0;
   }else{
    int x= a[top--];
     return x;
   }
 }
 bool Stack::isEmpty(){
   return (top<0);
 }
 int main()
{
    struct Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    std::cout<<s.pop() << " Popped from stack\n";

    return 0;
}
