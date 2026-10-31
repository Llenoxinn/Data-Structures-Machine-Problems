//implement the merge function here

/*

I declare, upon my honor, that I did this machine problem assignment by myself
using references from the lecture notes and MPs.

*/

#include "merge.h"

int merge(string A[], string B[], string C[], int n, int m) {
    int a=0,b=0,c=0;
    int comparisons=0;
    // so akong unang buhaton kay icompare which is which ang mas mag una

    // note that it will run n+m times however different iyang number of comparisons!
     while(a<n && b<m) {
        if(A[a] <= B[b]) {
            C[c] = A[a];
            c++;
            a++;
            comparisons++;
        } else { 
            C[c] = B[b];
            c++;
            b++;
            comparisons++;
        }
    }
    // nahurot na here so why not just put all remaining
    while(a<n) {
        C[c]=A[a];
        c++;
        a++;
    }

    while(b<m) {
        C[c]=B[b];
        c++;
        b++;
    }


    return comparisons;
}