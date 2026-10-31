/*

HONOR CODE:

I declare, upon my honor, that I did this machine problem assignment by myself
using references from the lecture notes and MPs.


*/


#include <stdio.h>

void linear(int A[], int n, bool &foundYah, int &count) {
    foundYah = false;
    count = 0;
    
    for(int i = 0; i < n; i++) {
        count++;
        if(A[i]==i) {
            foundYah=true;
            return;
        }
        
        if(A[i] > i) return;
    }
}

void subLinear(int A[], int n, bool &foundYah, int &count) {
    
    foundYah=false;
    count=0;
    
    int left = 0;
    int right = n-1;    
    while(left <= right) {
        int middle = left + (right-left)/2;
        count++;
        if(A[middle] == middle) {
            foundYah=true;
            return;
        } else if (A[middle] < middle){
            left=middle+1;
        } else {
            right=middle-1;
        }
    }
}

int main() {
    
    int A[20];
    int n, t;
    scanf("%i", &t);
    while(t--) {
        bool foundYah=false;
        int count=0;
        scanf("%i", &n);
        for(int j=0; j<n; j++) {
            scanf("%i", &A[j]);
        }
        
        linear(A, n, foundYah, count);
        if(foundYah)  {
            printf("YES %i\n", count);
        } else {
            printf("NO %i\n", count);
        }
        
        subLinear(A, n, foundYah, count);
        if(foundYah)  {
            printf("YES %i\n", count);
        } else {
            printf("NO %i\n", count);
        }
    }
    return 0;
}