#include<bits/stdc++.h>
using namespace std;

class MaxHeap{                                                                                    
    public:
    vector<int> arr;
    int size;
    MaxHeap(){
        size = 0;
    }

    void insert(int val){
        arr.push_back(val);
        size++;
        int index = size - 1;
        while(index > 0){
            int parent  = (index -1) / 2;
            if(arr[parent] < arr[index]){
                swap(arr[parent] , arr[index]);
                index = parent;      // parent ke bhi parent ko check karna padega
            }
            else return;
        }
    }

    void deleteFromheap(){
        if(size == 0) return;
        arr[0] = arr[size-1];
        arr.pop_back();
        size--;
        int index = 0;
        while(index < size){
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;
            if(left < size && arr[left] > arr[largest]){
                largest = left;
            }
            if(right < size && arr[right] > arr[largest]){
                largest = right;
            }
            if(largest != index){
                swap(arr[largest] , arr[index]);
                index = largest;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i = 0 ; i < size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

void Heapify(vector<int> &arr , int n , int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest] , arr[i]);
        Heapify(arr , n , largest);
    }
}

int main(){
    MaxHeap h;
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(15);
    h.insert(30);
    h.insert(25);
    h.print();
    h.deleteFromheap();
    h.print();
    h.deleteFromheap();
    h.print();


    //build heap from array
    vector<int> arr = {10,20,5,15,30,25};
    int n = arr.size();
    for(int i = n/2 - 1 ; i >= 0 ; i--){
        Heapify(arr , n , i);
    }
    cout<<"Heap built from array is : ";
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
}
