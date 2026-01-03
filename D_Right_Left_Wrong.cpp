#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n ; i++){
            cin>>arr[i];
        }
        string s;
        cin>>s;
        int sum=0;
        // bool flag = false;
        int a=-1;
        for(int i=1 ; i<=n-2 ; i++){
            if(s[i]=='L'){
                a=i;
                break;;
            }
        }
        int b=-1;
        for(int i=n-2 ; i>=1 ; i--){
            if(s[i]=='R'){
                b=i;
                break;;
            }
        }
        if(a!=-1 && b!=-1){
            for(int i=a ; i<=b ; i++){
                sum+=arr[i];
            }
        }


        if((s[0]=='L' && s[n-1]=='R')){
            for(int i=0 ; i<n ; i++){
                sum+=arr[i];
            }
            cout<<sum<<endl;
        }
        else if((s[0]=='L' && s[n-1]=='L')){
            // cout<<a<<" "<<b<<endl;
            if(a!=-1 && b!=-1){
                for(int i=0 ; i<=a-1 ; i++){
                    sum+=arr[i];
                }
            }
            else{
                if(b!=-1){
                    for(int i=0 ; i<=b ; i++){
                        sum+=arr[i];
                    }
                }
            }
            cout<<sum<<endl;
        }
        else if((s[0]=='R' && s[n-1]=='L')){
            cout<<sum<<endl;
        }
        else if((s[0]=='R' && s[n-1]=='R')){
            if(a!=-1 && b!=-1){
                for(int i=n-1 ; i>=b+1 ; i--){
                    sum+=arr[i];
                }
            }
            else{
                if(a!=-1){
                    for(int i=a ; i<n ; i++){
                        sum+=arr[i];
                    }
                }
            }
            cout<<sum<<endl;
        }

    }
    return 0;
}