// C++ program to find number of pairs with  
// a given sum in a sorted and rotated array. 
#include<bits/stdc++.h> 
using namespace std; 
  
// This function returns count of number of pairs 
// with sum equals to x. 
int pairsInSortedRotated(int arr[], int n, int x) 
{ 
    // Find the pivot element. Pivot element 
    // is maximum element of array. 
    int i; 
    for (i = 0; i < n-1; i++) 
        if (arr[i] > arr[i+1]) 
            break; 
      
    // l is index of minimum element. 
    int l = (i + 1) % n;  
      
    // r is index of maximum element. 
    int r = i; 
      
    // Variable to store count of number 
    // of pairs. 
    int cnt = 0; 
  
    // Find sum of pair formed by arr[l] and 
    // and arr[r] and update l, r and cnt  
    // accordingly. 
    while (l != r) 
    { 
        // If we find a pair with sum x, then  
        // increment cnt, move l and r to  
        // next element. 
        if (arr[l] + arr[r] == x){ 
            cnt++; 
              
            // This condition is required to  
            // be checked, otherwise l and r 
            // will cross each other and loop 
            // will never terminate. 
            if(l == (r - 1 + n) % n){ 
                return cnt; 
            } 
              
            l = (l + 1) % n; 
            r = (r - 1 + n) % n; 
        } 
  
        // If current pair sum is less, move to  
        // the higher sum side. 
        else if (arr[l] + arr[r] < x) 
            l = (l + 1) % n; 
          
        // If current pair sum is greater, move  
        // to the lower sum side. 
        else 
            r = (n + r - 1)%n; 
    } 
      
    return cnt; 
} 
  
/* Driver program to test above function */
int main() 
{ 
    int arr[] = {11, 15, 6, 7, 9, 10}; 
    int sum = 16; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    cout << pairsInSortedRotated(arr, n, sum); 
      
    return 0; 
}  
