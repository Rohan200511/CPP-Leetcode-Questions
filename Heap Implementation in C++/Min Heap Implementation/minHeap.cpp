#include<iostream>
#include<vector>
using namespace std;

class MinHeap{
public:
    vector<int>arr;
    int size;
    MinHeap(){
        size = 0;
    }

    void insert(int val){
        arr.push_back(val);
        size++;
        int index = size - 1;

        while(index > 0){
            int parent = (index - 1) / 2;
            if(arr[parent] > arr[index]){
                swap(arr[parent] , arr[index]);
                index = parent;
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

            int smallest = index;

            if(left < size && arr[left] < arr[smallest]){
                smallest = left;
            }

            if(right < size && arr[right] < arr[smallest]){
                smallest = right;
            }

            if(smallest != index){
                swap(arr[smallest] , arr[index]);
                index = smallest;
            }
            else return;
        }
    }

    void print(){
        for(int i = 0 ; i < size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};


void heapify(vector<int>& arr , int n , int i){
    if(n == 0) return;
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] < arr[smallest]) smallest = left;
    if(right < n && arr[right] < arr[smallest]) smallest = right;

    if(smallest != i){
        swap(arr[i] , arr[smallest]);
        heapify(arr,n,smallest);
    }
}

int main(){
    MinHeap h;
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(15);
    h.insert(30);
    h.insert(25);
    h.print();
    h.deleteFromheap();
    h.print();


    // Build heap from Array

    vector<int>arr = {10,20,5,15,30,25};
    int n = arr.size();
    for(int i = n/2 ; i >= 0 ; i--){
        heapify(arr,n,i);
    }
    cout<<"Heap Built from Array -> ";
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
