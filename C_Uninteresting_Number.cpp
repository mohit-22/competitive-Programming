#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin>>s;
        int two=0,three=0;
        int sum=0;
        for(char it:s){
            if(it=='2'){
                two++;
            }
            else if(it=='3'){
                three++;
            }
            sum+=(it-'0');
        }
        bool flag = false;
        for(int i=0 ; i<=two ; i++){
            for(int j=0 ; j<=three ; j++){
                int sum2 = sum;
                sum2+=i*2+j*6;
                if(sum2%9==0){
                    flag = true;
                    break;
                }
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    return 0;
}