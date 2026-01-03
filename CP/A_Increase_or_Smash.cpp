#include <bits/stdc++.h>
using namespace std;


int ctdist(vector<int>& arr){

    if (arr.empty()) return 0;
    sort(arr.begin(),arr.end());
    int ct=1;
    for(int i=1;i<arr.size();i++) {
        if(arr[i]!=arr[i-1]) {
            ct++;
        }
    }
    return ct;
}


int main() {
    int t; 
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++) 
        cin>>a[i];
        int dist = ctdist(a);
        int m = 2*dist;
        cout<<(m-1)<<endl;
    }
    return 0;
}
