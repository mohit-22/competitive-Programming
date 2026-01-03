
#include <bits/stdc++.h>
using namespace std;



bool cp(const string &t) {
    string rev = t;
    reverse(rev.begin(), rev.end());
    return t == rev;
}



bool ckplin(const string &s, const vector<char> &rmM){
    int L = 0, R = (int)s.size() - 1;
    while(L < R){
        while(L < R && rmM[L]) ++L;
        while(L < R && rmM[R]) --R;
        if(L < R && s[L] != s[R]) return false;
        ++L; --R;
    }
    return true;
}

void solveCase(const string &s, const vector<int> &zeroPos, const vector<int> &onePos){
    int len = (int)s.size();
    int zCount = (int)zeroPos.size();
    bool solved = false;
    vector<int> rid;

    function<void(int,int)> ez = [&](int zIndex, int lrz){
        if(solved) return;
        if(zIndex == zCount){
            vector<int> eligibleOnes;
            for(int idx : onePos) if(idx > lrz) eligibleOnes.push_back(idx);

            int eCount = (int)eligibleOnes.size();
            vector<char> rmM(len, 0);
            for(int idx : rid) rmM[idx] = 1;

            function<void(int)> backtrack = [&](int j) {
                if (solved) return;
                if (j == eCount) {
                    if (ckplin(s, rmM)) {
                        vector<int> output = rid;
                        for (int k = 0; k < eCount; ++k)
                            if (rmM[eligibleOnes[k]]) output.push_back(eligibleOnes[k]);

                        cout << output.size() << "\n";
                        for (size_t k = 0; k < output.size(); ++k) {
                            if (k) cout << ' ';
                            cout << (output[k] + 1);
                        }
                        cout << "\n";
                        solved = true;
                    }
                    return;
                }

                // Option 1: skip eligibleOnes[j]
                backtrack(j + 1);
                if (solved) return;

                // Option 2: include eligibleOnes[j]
                rmM[eligibleOnes[j]] = 1;
                backtrack(j + 1);
                rmM[eligibleOnes[j]] = 0; // backtrack
            };

            backtrack(0);

        }

        ez(zIndex + 1, lrz);
        if(solved) return;

        rid.push_back(zeroPos[zIndex]);
        ez(zIndex + 1, zeroPos[zIndex]);
        rid.pop_back();
    };

    ez(0, -1);

    if(!solved){
        cout << "-1\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC;
    if(!(cin >> TC)) return 0;
    while(TC--){
        int n; string s;
        cin >> n >> s;

        if(cp(s)){
            cout << 0 << "\n\n";
            continue;
        }

        vector<int> zeroPos, onePos;
        for(int i = 0; i < n; ++i){
            if(s[i] == '0') zeroPos.push_back(i);
            else onePos.push_back(i);
        }

        solveCase(s, zeroPos, onePos);
    }
    return 0;
}
