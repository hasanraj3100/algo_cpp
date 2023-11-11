// Given an array, find any subsequence that has sum K 

#include<bits/stdc++.h>
#define ll long long
#define take_input(x, m) for(int i=0;i<x;i++) cin >> m[i]
#define _output(x,m) for(int i=0;i<x;i++) cout << m[i] <<" "; cout<< endl;
#define srt(a) sort(a.begin(), a.end())
using namespace std;

bool findSubsq(int i, vector<int>&arr, vector<int>&ans, int sum, int k) {

    if(i == arr.size()) {
        if(sum == k) {
            _output(ans.size(), ans);
            return true;
        }

        return false;
    }


    ans.push_back(arr[i]);
    sum += arr[i];
    if( findSubsq(i+1, arr, ans, sum, k) == true) return true;

    ans.pop_back();
    sum -= arr[i];

    if( findSubsq(i+1, arr, ans, sum, k) == true) return true;

    return false;


}
 
 
int main() {
    
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    take_input(n, arr);

    vector<int> ans;
    findSubsq(0, arr, ans, 0, k);


    return 0;
}