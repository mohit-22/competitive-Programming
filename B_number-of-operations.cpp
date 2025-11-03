// int find(int x , vector<int>&par){
//     if(par[x]==x) return x;

//     return par[x] = find(par[x],par);
// }

// void unionn(int x ,int y,vector<int>&par){
//     int a = find(x,par);
//     int b = find(y,par);

//     if(a==b) return;

//     par[a] = b;
// }

// class Solution {
// public:
//     int makeConnected(int n, vector<vector<int>>& connections) {
//         int m = connections.size();
//         if(m+1<n){
//             return -1;
//         }

//         vector<int>par(n);
//         for(int i=0 ; i<n ; i++){
//             par[i] = i;
//         }

//         for(auto it:connections){
//             int x = it[0];
//             int y = it[1];
//             if(find(x,par)!=find(y,par)){
//                 unionn(x,y,par);
//                 n--;
//             }
//         }

//         for(auto it:par){
//             cout<<it<<" ";
//         }

//         return n-1;


//     }
// };



int find(int x , vector<int>&par){
    if(par[x]==x) return x;

    return par[x] = find(par[x],par);
}

void unionn(int x ,int y,vector<int>&par,vector<int>&rank){
    int a = find(x,par);
    int b = find(y,par);
    if(a==b) return;

    if(rank[a]==rank[b]){
        par[a] = b;
        rank[b]++;
    }
    else if(rank[a]>rank[b]){
        par[b] = a;
    }
    else par[a] = b;

    
}

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m+1<n){
            return -1;
        }

        vector<int>par(n);
        for(int i=0 ; i<n ; i++){
            par[i] = i;
        }

        vector<int>rank(n);

        for(auto it:connections){
            int x = it[0];
            int y = it[1];
            if(find(x,par)!=find(y,par)){
                unionn(x,y,par,rank);
                // n--;
            }
        }

        for(auto it:par){
            cout<<it<<" ";
        }
        cout<<endl;
        for(auto it:rank){
            cout<<it<<" ";
        }

        set<int>s;
        for(auto it:par){
            s.insert(find(it,par));
        }

        // return n-1;
        return s.size()-1;


    }
};