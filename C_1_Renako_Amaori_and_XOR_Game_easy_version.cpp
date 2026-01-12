#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>a(n),b(n);
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	     for(int i=0;i<n;i++){
	        cin>>b[i];
	    }
	    int xori=0,last=0;
	    for(int i=0;i<n;i++){
	        xori^=a[i];
	        xori^=b[i];
	        if(a[i]!=b[i]){
	        last=i;
	        }
	    }
	    if(xori==0){
	        cout<<"Tie"<<endl;
	    }
	    else if(last%2==0){
	        cout<<"Ajisai"<<endl;
	    }
	    else{
	        cout<<"Mai"<<endl;
	    }
	    
	   
	  
	    
	    
	    
	    
	}

}