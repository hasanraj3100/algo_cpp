
// Given an array, print all the subsequences of an array using recursion 

#include<bits/stdc++.h>
#define ll long long
#define take_input(x, m) for(int i=0;i<x;i++) cin >> m[i]
#define _output(x,m) for(int i=0;i<x;i++) cout << m[i] <<" "; cout<< endl;
#define srt(a) sort(a.begin(), a.end())
using namespace std;

// arr is the given array, ans is the the one I will use to store subsequence
void print_subsequences(int i, vector<int>&arr, vector<int>&ans) {

    // if we reach the end, print the ans vector as a subsequence 
    if(i == arr.size()) {
        _output(ans.size(), ans); // _output is defined above 
        return ; // stop continueing further 
    }

    // take the i-th element and run the recursion
    ans.push_back(arr[i]);
    print_subsequences(i+1, arr, ans);

    // do not take the i-th element and run the recursion
    ans.pop_back();
    print_subsequences(i+1, arr, ans);
}
 
 
int main() {
    
    int n;  cin >> n; 
    vector<int> arr(n);
    take_input(n, arr);

    vector<int> ans;

    print_subsequences(0, arr, ans);
 
    return 0;
}