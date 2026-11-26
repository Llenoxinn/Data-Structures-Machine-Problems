#include <iostream>
#define MAX 20
using namespace std;

bool isHeap(int[],int);

int main(){
    int arr[MAX];
    int n;
    cin >> n;
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    if(isHeap(arr, n)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

bool isHeap(int A[], int n){
    // let i be 0-indexed
    for(int i = 0; i<=(n/2)-1; i++) {
        int left = 2*i+1;
        int right = 2*i+2;
       
        if(left<n && A[i] > A[left]) {
            return false;
        }
        if(right<n && A[i] > A[right]) {
            return false;
        }
    }
    return true;
}
