#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin>>s;
        int n = s.size();
        for(int i=1 ; i<n; i++){
            int x = s[i];
            x--;
            int j=i-1;
            int p=x+1;
            int idx=i;
            int mx = INT_MIN;
            while(j>=0 && x>48){
                if(s[j]<x){
                    // // mx = max(mx,x-s[j]);
                    // // p=j;
                    // if(mx<x-s[j]){
                    //     mx = x-s[j];
                    //     p=x;
                    //     idx=j;
                    // }
                    p=x;
                    idx=j;
                }
                x--;
                j--;
            }
            // int temp = p;
            // s[i] = s[idx];
            // s[idx] = temp;
            char last = p;
            for(int j=i ; j>idx ; j--){
                s[j] = s[j-1];
            }
            s[idx] = last;


        }
        
        cout<<s<<endl;
    }
    return 0;
}