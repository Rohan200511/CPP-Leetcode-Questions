#include<bits/stdc++.h>
using namespace std;

class Graph{                                                
    public:                                                   
        int V;                                               
        list<int> *l;                                      
                                                            
        Graph(int V){
            this->V = V;
            l = new list<int>[V];
        }

        void addEdges(int u , int v){
            l[u].push_back(v);                  // undirected Graph
            l[v].push_back(u);
        }

        void printList(){
            for(int i = 0 ; i < V ; i++){
                cout << i << ": ";
                for(int neighbour : l[i]){
                    cout << neighbour << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    Graph g(5);
    g.addEdges(0 , 1);
    g.addEdges(1 , 2);
    g.addEdges(1 , 3);
    g.addEdges(2 , 3);
    g.addEdges(2 , 4);

    g.printList();

    return 0; 
}