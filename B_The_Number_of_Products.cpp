#include <bits/stdc++.h>
using namespace std;

#define int long long
int dpNeg[200005][2][2];
int dpPos[200005][2][2];
int N;
int solve1(int i,int num,int t,int arr[]){
    if(i==N) return  (num==0 && t==1);
    if(dpNeg[i][num][t]!=-1) return   dpNeg[i][num][t];
    int ans=0;
    if(arr[i]<0){
        ans+= (num==0 && t==1) + solve1(i+1,1-num,1,arr);  
        if(t==0) ans+= (num==0 && t==1) + solve1(i+1,num,0,arr);
    }
    else{
        ans+= (num==0 && t==1) + solve1(i+1,num,1,arr);
        if(t==0) ans+= (num==0 && t==1) + solve1(i+1,num,0,arr);
    }

    return dpNeg[i][num][t] =  ans;

}

int solve2(int i,int num,int t,int arr[]){
    if(i==N) return (num==1 && t==1);
    if( dpPos[i][num][t]!=-1) return  dpPos[i][num][t];
    int ans=0;
    if(arr[i]<0){
        ans+= (num==1 && t==1) + solve2(i+1,1-num,1,arr);  
        if(t==0) ans+= (num==1 && t==1) + solve2(i+1,num,0,arr);
    }
    else{
        ans+= (num==1 && t==1) + solve2(i+1,num,1,arr);
        if(t==0) ans+= (num==1 && t==1) + solve2(i+1,num,0,arr);
    }

    return  dpPos[i][num][t] = ans;

}

int32_t main(){
    
    int n;
    cin>>n;
    N=n;
    
    memset(dpNeg,-1,sizeof(dpNeg));
    memset(dpPos,-1,sizeof(dpPos));
    int arr[n];
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    int ans1 = solve1(0,1,0,arr);
    int ans2 =  solve2(0,1,0,arr);
    cout<<ans1<<" "<<ans2<<endl;


    return 0;
}  