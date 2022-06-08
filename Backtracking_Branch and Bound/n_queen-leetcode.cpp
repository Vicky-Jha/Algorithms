bool valid(vector<string> pushme, int i, int j) {
        // up
        for(int up = i - 1; up >= 0; --up) {
            if(pushme[up][j] == 'Q') {
                return false;
            }
        }
        
        // diagonalRight
        for(int crossRight = i - 1, tempJ = j + 1; crossRight >= 0 && tempJ < pushme[0].size(); crossRight--, tempJ++) {
            if(pushme[crossRight][tempJ] == 'Q') {
                return false;
            }
        }
        
        // diagonalLeft
        for(int crossLeft = i - 1, tempJ = j - 1; crossLeft >= 0 && tempJ >= 0; --crossLeft, --tempJ) {
            if(pushme[crossLeft][tempJ] == 'Q') {
                return false;
            }
        }
        
        return true;
    }
    
    void backtrack(int i, int j, int n, vector<vector<string>>& sol, vector<string> pushme, string reuse) {
        
        if(i == n) {
            sol.push_back(pushme);
            return;
        }
        
        for(int k = 0; k < n; ++k) {
            if(valid(pushme, i, k)) {
                reuse[k] = 'Q';
                pushme.push_back(reuse);
                reuse[k] = '.';
                backtrack(i + 1, 0, n, sol, pushme, reuse);
                pushme.pop_back();
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sol;
        vector<string> pushme;
        string reuse(n, '.');
        
        backtrack(0, 0, n, sol, pushme, reuse);
        
        return sol;
    }
