#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int>& arr , int size , int i){
    if(size == 0) return;
    int largest = i;
    
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && arr[left] > arr[largest]) largest = left;
    if(right < size && arr[right] > arr[largest]) largest = right;

    if(largest != i){
        swap(arr[largest] , arr[i]);
        heapify(arr,size,largest);
    }
}

void heapSort(vector<int>& arr , int n){
    if(n <= 0) return;

    for(int i = n/2-1 ; i >= 0 ; i--)              //Bhaiya mere liye jra max heap bna do
            heapify(arr,n,i);

    for(int i = n-1 ; i >= 0 ; i--){
        swap(arr[0],arr[i]);                      //recursively last mein largest element aa jayega😁 and heapify apne aap max heap maintain krega
        heapify(arr,i,0);                         // i isliye likha hai kyuki array shrink kregi and i will be at the size imagine from right
    }

    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    vector<int>arr = {2,5,11,8,10,1};
    int n = arr.size();
    heapSort(arr,n);
    return 0;
}
