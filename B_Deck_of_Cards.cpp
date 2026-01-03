#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n>>k;
        string s;
        cin>>s;
        vector<string>st(n,"+");
        int ct2=0;
        for(int i=0 ; i<k ; i++){
            if(s[i]=='2') ct2++;
        }
        if(ct2==n){
            for(int i=0 ; i<n ; i++){
                cout<<"-";
            }
            cout<<endl;
            continue;
        }
        int sr=0;
        int en=n-1;
        for(int i=0 ; i<k ; ){
            if(s[i]=='0'){
                st[sr]="-";
                sr++;
                i++;
            }
            else if(s[i]=='1'){
                st[en]="-";
                en--;
                i++;
            }
            else{
                int sr1=sr;
                int en1=en;
                int ct=0;
                while(s[i]=='2'){
                    st[sr1]="?";
                    st[en1]="?";
                    sr1++;
                    en1--;
                    i++;
                    ct++;
                }
                int j = i;
                int x = 2*ct;
                while(x--){
                    if(s[j]=='0' ){
                        st[sr1]="?";
                        j++;
                        sr1++;
                    }
                    else if(s[j]=='1'){
                        st[en1]="?";
                        j++;
                        en1--;
                    }
                }

            }
        }
        for(auto i: st){
            cout<<i;
        }
        cout<<endl;
        
    }
    return 0;
}