// Given an array and an integer k, find the number of subsequences in the array
// that has the sum equal to k

#include<bits/stdc++.h>
#define ll long long
#define take_input(x, m) for(int i=0;i<x;i++) cin >> m[i]
#define _output(x,m) for(int i=0;i<x;i++) cout << m[i] <<" "; cout<< endl;
#define srt(a) sort(a.begin(), a.end())
using namespace std;

int totalSubsq(int i, vector<int>&arr, int sum, int k) {
    if(i == arr.size()) {
        if(sum == k) return 1; // we found one subsequence, so return 1
        return 0; // we didn't find any subsequendes with sum k
    }

    // take the i-th element 
    sum += arr[i];
    int l = totalSubsq(i+1, arr, sum , k);

    // not taking the i-th element 

    sum-= arr[i];
    int r = totalSubsq(i+1, arr, sum, k);

    return l + r;
}
 
 
int main() {
    
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    take_input(n,arr);

    cout << totalSubsq(0, arr, 0, k);
 
    return 0;
}