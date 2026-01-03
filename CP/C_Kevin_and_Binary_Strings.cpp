#include <bits/stdc++.h>
using namespace std;

#define int long long

string binaryXOR(const string &a, const string &b) {
    // ensure a is the longer (or equal) one
    if (a.size() < b.size()) return binaryXOR(b, a);

    int n = a.size();
    int m = b.size();
    string padded = string(n - m, '0') + b; // O(n)
    string res;
    res.reserve(n);
    for (int i = 0; i < n; ++i)
        res.push_back(a[i] == padded[i] ? '0' : '1');
    return res;
}


int32_t main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin>>s;
        int n = s.length();
        vector<int>v;
        int j = -1;
        for(int i=0 ; i<n ;i++ ){
            if(s[i]=='1') v.push_back(i);
            if(s[i]=='0' && j==-1){
                j=i;
                break;
            }
        }
        if(j==-1){
            cout<<1<<" "<<n<<" "<<1<<" "<<1<<endl;
            continue;
        }
        int x = n-j;
        int k = 0;
        // int mx = INT_MIN;
        // int mx = '0';
        string mx = string(n, '0'); 
        int ansi=0;
        int ansj=0;
        while(k<v.size()){
            // for(int i=v[k]+x-1 ; i<n ; i++){
                string s2 = s.substr(v[k],v[k]+x-1-v[k]+1);
                string s3 =  binaryXOR(s, s2);
                // int decimalValue = stoll(s3, nullptr, 2);
                if(s3>mx){
                    mx = s3;
                    ansi = v[k];
                    ansj=v[k]+x-1;
                }
            // }
            k++;

        }

        cout<<1<<" "<<n<<" "<<ansi+1<<" "<<ansj+1<<endl;
        
    }
    return 0;
}