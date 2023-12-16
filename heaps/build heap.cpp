
#include <bits/stdc++.h>
using namespace std;

class heap {
public:
    int arr[100];
    int size;
    
    heap() {
        arr[0] = -1;
        size = 0;
    }
    
    void insert(int val) {
        size++;
        int ind = size;
        arr[ind] = val;
        
        while(ind > 1) {
            int parent = ind/2;
            if(arr[parent] < arr[ind]) {
                swap(arr[parent],arr[ind]);
                ind = parent;
            }
            else {
                return;
            }
        }
    }
    
    void deletefromheap() {
        if(size == 0){
            cout<<"nothing to delete";
            return;
        } 
        arr[1] = arr[size];
        size--;
        
        int i = 1;
        while(i < size) {
            int leftind = 2*i;
            int rightind = 2*i+1;
            
            if(leftind < size && arr[i] < arr[leftind]) {
                swap(arr[i],arr[leftind]);
                i = leftind;
            }
            else if(rightind < size && arr[i] < arr[rightind]) {
                swap(arr[i],arr[rightind]);
                i = leftind;
            }
            else {
                return;
            }
        }
    }
    
    void heapify(int arr[], int n, int i) {
        int largest = i;
        int left = 2*i;
        int right = 2*i +1;
        
        if(left <n && arr[largest] < arr[left]) {
            largest = left;
        }   
        else if(right <n && arr[largest] < arr[right]) {
            largest = right;
        }
        if(largest != i) {
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    }
    
    void print() {
        for(int i=1; i<=size; i++) {
            cout<<arr[i]<<" ";
        }
    }
};

int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(57);
    h.deletefromheap();
    h.deletefromheap();
    h.insert(58);
    h.print();
}
