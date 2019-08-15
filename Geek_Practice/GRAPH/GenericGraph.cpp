#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>
using namespace std;
template <typename T>
class graph{
  map<T,list<T> >adlist;
public:
  graph(){

  }
  void addedge(T a,T b,bool bidr=true){
    adlist[a].push_back(b);
    if(bidr){
      adlist[b].push_back(a);
    }
  }
void printedge(){
  for(auto i:adlist){
    T key = i.first;
    cout<<key<<" -> ";
    for(T node:adlist[key]){
      cout<<node<<" ,";
    }
cout<<endl;
  }
}
void bfs(T src){
  queue<T> q;
  map<T,bool> vist;
  q.push(src);
  vist[src]=true;
  while(!q.empty()){
    T node = q.front();
cout<<node<<" ,";
    q.pop();
    for(T child:adlist[node]){
      if(!vist[child]){
        q.push(child);
        vist[child]=true;
      }
    }
  }
}
void sssp(T src){
  queue<T> q;
  map<T,int> dist;
  map<T,T> par;
  par[src]=src;

  for(auto node:dist){
    dist[node.first]=INT_MAX;
  }
  dist[src]=0;
  q.push(src);

  while(!q.empty()){
    T node = q.front();

    q.pop();
    for(T child:adlist[node]){
      if(dist[child]==INT_MAX){
        q.push(child);
        dist[child]=dist[node]+1;
        par[child]=node;
      }
    }
  }

for(auto node:adlist){
T i = node.first;
cout<<"dist from "<<i<<" to "<<src<<" is "<<dist[i]<<endl;
}
}
};
int main(){
graph<int> g;
g.addedge(0,1);
g.addedge(0,4);
g.addedge(2,4);
g.addedge(2,3);
g.addedge(4,3);
g.addedge(3,5);



// g.printedge();
g.sssp(0);


  return 0;
}
