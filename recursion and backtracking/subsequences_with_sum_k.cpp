// Given an array and an integer k, print all the subsequences
// of the array with sum k

#include<bits/stdc++.h>
#define ll long long
#define take_input(x, m) for(int i=0;i<x;i++) cin >> m[i]
#define _output(x,m) for(int i=0;i<x;i++) cout << m[i] <<" "; cout<< endl;
#define srt(a) sort(a.begin(), a.end())
using namespace std;

// arr is the given array and I will use ans to store subsequence
void print_subsq(int i, vector<int>&arr, vector<int>&ans, int sum, int k) {
    
    // if we reach the end, check if sum is equal to k. 
    // if it is, then print the subsequence stored in ans vector
    if(i == arr.size()) {
        if(sum == k) {
            _output(ans.size(), ans);
            return;
        }
        return;
    }

    // taking the i-th element from arr

    ans.push_back(arr[i]);
    sum += arr[i];
    print_subsq(i+1, arr, ans, sum ,k);

    // not taking the i-th element from arr

    ans.pop_back();
    sum -= arr[i];
    print_subsq(i+1, arr, ans, sum , k);
}
 
 
int main() {
    
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    take_input(n,arr);

    vector<int> ans;

    print_subsq(0, arr, ans, 0, k);
 
    return 0;
}