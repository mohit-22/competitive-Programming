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
        int ts;
        bool flag=true;
        for(int i=0 ;i<n ; i++){
            cin>>arr[i];
            ts+=arr[i];
            if(arr[i]<=0){
                flag=false;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
            continue;
        }
        vector<int>v;
        for(int i=0 ; i<n ;){
            int s=0;
            bool flag1=false;
            bool flag2=false;
            while(i<n && arr[i]>=0){
                s+=arr[i];
                i++;
                flag1=true;
            }
            if(flag1) v.push_back(s);
            s=0;
            while(i<n && arr[i]<0){
                s+=arr[i];
                // v.push_back(s);
                i++;
                flag2=true;
            }
            if(flag2) v.push_back(s);

            
        }
        int i=0;
        while(i<n && v[i]<0){
            i++;
        }
        int j=v.size()-1;
        while(j>=0 && v[j]<0){
            j--;
        }

        // for(auto it : v){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // cout<<i<<" "<<j<<endl;

        if((i>j)){
            cout<<"NO"<<endl;
            continue;
        }
        // else if(i==0 && j==v.size()-1){
        //     cout<<"YES"<<endl;
        //     continue;
        // }
        int s=0;
        for(int k=i ; k<=j ; k+=2){
            if(k+1<=j &&  v[k]+v[k+1]>=0){
                s+=(v[k]+v[k+1]);
            }
            else if(k+1<=j && v[k]+v[k+1]<0){
                s=0;
            }

            
        }
        if((j-i+1)%2!=0){
                s+=v[j];
        }
        // cout<<s<<" "<<ts<<endl;
        if(s>=ts) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        
        
    }
    return 0;
}