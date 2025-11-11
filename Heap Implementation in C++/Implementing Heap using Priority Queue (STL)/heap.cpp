#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    //<-----------------------------------Implementing Max Heap------------------------------------------------->      

    priority_queue<int>maxheap;                              // default max heap hota hai

    maxheap.push(5);
    maxheap.push(25);
    maxheap.push(20);
    maxheap.push(35);
    maxheap.push(50);
    cout<<"MaxHeap is " << endl;
    while(!maxheap.empty()){
        cout<<maxheap.top()<<" ";
        maxheap.pop();
    }
    cout<<endl;

    //<-----------------------------------Implementing Min Heap----------------------------------------------------->

    priority_queue<int , vector<int>,greater<int>>minheap;
    
    minheap.push(5);
    minheap.push(25);
    minheap.push(20);
    minheap.push(35);
    minheap.push(50);
    cout<<endl<<"MinHeap is " << endl;
    while(!minheap.empty()){
        cout<<minheap.top()<<" ";
        minheap.pop();
    }
    cout<<endl;

    return 0;
}
