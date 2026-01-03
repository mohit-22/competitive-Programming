#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        if(n==2){
            cout<<"NO"<<endl;
            continue;
        }
        
        string s="";
        while(n>0){
            s = char('0' + (n%2))+s;
            n=n/2;
        }

        

        if(s.length()%2!=0){
            int x = s[s.length()/2];
            if(x!='0'){
                s = char('0')+s;
            }
        }else{
            int x = s[s.length()/2];
            int y = s[(s.length()/2)-1];

            if(x!=y){
                s = char('0')+s;
            }
        }

        cout<<s<<endl;


        int i=0;
        int j = s.length()-1;
        bool flag = true;
        while(i<=j){
            if(s[i]!=s[j]){
                flag=false;
                break;
            }
            i++;
            j--;

        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}