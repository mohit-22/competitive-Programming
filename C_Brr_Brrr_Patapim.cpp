// #include <bits/stdc++.h>
// using namespace std;

// int n;  
// vector<vector<string>> solutions;  

// bool isSafe(vector<string> &board, int row, int col) {
    
//     for (int i = 0; i < row; i++)
//         if (board[i][col] == 'Q') return false;

    
//     for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
//         if (board[i][j] == 'Q') return false;

    
//     for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
//         if (board[i][j] == 'Q') return false;

//     return true;
// }

// void solve(int row, vector<string> &board) {
//     if (row == n) {  
//         solutions.push_back(board);
//         return;
//     }

//     for (int col = 0; col < n; col++) {
//         if (isSafe(board, row, col)) {
//             board[row][col] = 'Q';   
//             solve(row + 1, board);   
//             board[row][col] = '.';   
//         }
//     }
// }

// int main() {
//     cout << "Enter value of N: ";
//     cin >> n;

//     vector<string> board(n, string(n, '.'));  
//     solve(0, board);

//     cout << "\nTotal solutions found: " << solutions.size() << "\n\n";

//     for (int i = 0; i < solutions.size(); i++) {
//         cout << "Solution " << i + 1 << ":\n";
//         for (auto row : solutions[i])
//             cout << row << "\n";
//         cout << "\n";
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;


void mohit(map<int,int>mp,vector<int> a){
    for(int i=0 ; i<a.size() ; i++){
        if(mp[a[i]]==-1) cout<<0<<endl;;
    }
    // return;
}
 
void amit(vector<pair<int,int>>vp,vector<int> a){
    for(int i=0 ; i<a.size() ; i++){
        if( i<vp.size() &&  vp[i].first==-1) cout<<0<<endl;;
    }
}

void checkSegments(
    const vector<int>& posK,
    const vector<int>& A,
    int N,
    int K,
    bool &ok
) {
    int last = -1;

    for (int p : posK) {
        int l = last + 1, r = p - 1;
        if (l <= r) {
            unordered_set<int> local;
            local.reserve(min(r - l + 1, K));
            for (int i = l; i <= r && (int)local.size() < K; ++i) {
                int v = A[i];
                if (v >= 0 && v < K)
                    local.insert(v);
            }
            if ((int)local.size() == K) {
                ok = true;
                return;
            }
        }
        last = p;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        map<int,int>mp;
        vector<pair<int,int>>vp;
        for (int i = 0; i < N; ++i){
            cin>>A[i];
            mp[A[i]]++;
            vp.push_back({A[i],i});
            
        }

        if (K == 0) {
            auto it = find_if(A.begin(), A.end(), [](int x){ return x != 0; });
            cout << (it == A.end() ? 2 : 1) << '\n';
            continue;
        }

        amit(vp,A);

        vector<char> present(K, 0);
        int have = 0;

        for (int i = 0; i < N; ++i) {
            int val = A[i];
            if (val < K && val >= 0) {
                if (present[val] == 0) {
                    present[val] = 1;
                    ++have;
                }
            }
        }

         mohit(mp,A);

        int missing = K - have;
        if (missing != 0) {
            cout << missing + 1 << '\n';
            continue;
        }




        int cntK = 0;
        for (int i = 0; i < N; ++i)
            if (A[i] == K) ++cntK;

        if (cntK == 0) {
            cout << 1 << '\n';
            continue;
        }

         mohit(mp,A);

        vector<int> posK;
        posK.reserve(cntK);
        for (int i = 0; i < N; ++i)
            if (A[i] == K) posK.push_back(i);



        vector<int> seenTime(K, 0);
        int timer = 1;
        bool ok = false;
        int last = -1;

       

        checkSegments(posK, A, N, K, ok);



        if (!ok) {
            int need = K;
            for (int i = last + 1; i < N && need > 0; ++i) {
                int v = A[i];
                if (v >= 0 && v < K && seenTime[v] != timer) {
                    seenTime[v] = timer;
                    --need;
                }
            }
            ok = (need == 0);
        }

        cout << (ok ? 1 : 2) << '\n';

    }
    return 0;
}
