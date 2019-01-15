#include<iostream>
using namespace std;
#include<string.h>
#include<stack>
int precidence(char c)
{
    if(c=='^')
    return 3;
    else if(c=='*'|| c=='/')
    return 2;
    else if(c=='+'||c=='-')
    return 1;
    else
    return -1;
}
void InfixToPostfix(string s)
{
    std::stack<char> st;
    st.push('N');
    int l = s.length();
    std::string ns;
    for(int i=0;i<l;i++)
    {
      // If the scanned character is an operand, add it to output string.
        if((s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z'))
        ns +=s[i];

        else if(s[i]=='(')
        st.push('(');


  // If the scanned character is an ‘)’, pop and to output string from the stack
  // until an ‘(‘ is encountered
        else if(s[i]==')')
        {
            while(st.top()!='N' && st.top()!='(')
            {
                char c = st.top();
                st.pop();
                ns+=c;

            }
            if(st.top()=='(')
            {
              char c = st.top();
              st.pop();
            }
        }
        //if operator is scanned
        else
        {
            while(st.top()!='N'&& precidence(s[i])<=precidence(st.top()))
            {
              char c = st.top();
              st.pop();
              ns+=c;
              }
              st.push(s[i]);
            }
          }
            while(st.top()!='N')
            {
                char c = st.top();
                st.pop();
                ns +=c;

            }

          cout << ns << '\n';
}

int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    InfixToPostfix(exp);
    return 0;
}
