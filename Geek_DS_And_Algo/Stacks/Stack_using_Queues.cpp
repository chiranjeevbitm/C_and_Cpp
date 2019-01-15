/*
Algorithm
push(s, x) // x is the element to be pushed and s is stack
  1) Enqueue x to q2
  2) One by one dequeue everything from q1 and enqueue to q2.
  3) Swap the names of q1 and q2
// Swapping of names is done to avoid one more movement of all elements
// from q2 to q1.

pop(s)
  1) Dequeue an item from q1 and return it.

*/
#include<iostream>
#include<queue>
using namespace std;
class stack
{
  // Two inbuilt queues
    queue<int> q1, q2;

    int cur_size;
  public:
    stack()
    {
      cur_size = 0;
    }
    void push(int x)
    {
      cur_size++;
      q2.push(x);
      while(!q1.empty())
      {
        q2.push(q1.front());
        q1.pop();

      }
      //swap the names of two queues
      queue<int> q = q1;
      q1 = q2;
      q2 = q;
    }
    void pop()
    {
      while(q1.empty())
      return;
      q1.pop();
      cur_size--;
    }
   int top()
   {
     while(q1.empty())
     return -1;
     return q1.front();
   }
   int size()
   {
     return cur_size;
   }

};

int main()
{
  stack s;
  s.push(1);
  s.push(2);
  s.push(10);
  std::cout << "cur_size is : " <<s.size()
  <<endl;
  std::cout << s.top() << '\n';
  s.pop();
  std::cout << s.top() << '\n';
  s.pop();
  std::cout << s.top() << '\n';
  std::cout << "cur_size is : " <<s.size() <<'\n';

}
