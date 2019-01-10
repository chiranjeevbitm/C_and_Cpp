// Basic methods are-
/*
1. clear() — to clear the stream
2. str() — to get and set string object whose content is present in stream.
3. operator << — add a string to the stringstream object.
4. operator >> — read something from the stringstream object,

*/

#include<iostream>
#include <string>
#include <sstream>
#include<map>
using namespace std;

int countword(string str){

  // breaking input into word using string stream
    stringstream s(str); // Used for breaking words
    string word; // to store individual words

    int count = 0;
    while(s >> word){
      count++;
    }
    return count;
}
int printfrequency(string str){
  ///each word it mapped to it's frequency
  map<string, int> FW;
  stringstream ss(str);
  string word;

  while(ss >> word) {
     FW[word]++;
  }
  map<string,int>::iterator m;
  for(m=FW.begin();m!=FW.end();m++){
    cout<< m->first<<"->"<<m->second<<"\n";
  }

}



int main(){
  string s = "my name is chiranjeev"
                "I live in MUZ";
  cout << "number of words are :"<<countword(s)<< '\n';
  printfrequency(s);
  return 0;
}
