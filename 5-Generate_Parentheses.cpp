class Solution {
public:
    void solve(int n, string& paraCombo, vector<string>& ans, int paraOpen, int paraClose, int indx)
    {
        if(indx>=n*2)
        {
            ans.push_back(paraCombo);
            return;
        }

        if(paraOpen<n && indx<2*n-1)
        {
            paraCombo+="(";
            solve(n, paraCombo, ans, paraOpen+1, paraClose, indx+1);
            paraCombo.pop_back();
        }

        if(paraClose<paraOpen && indx>0)
        {
            paraCombo+=")";
            solve(n,paraCombo, ans, paraOpen, paraClose+1, indx+1);
            paraCombo.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string paraCombo = "";
        vector<string> ans;
        solve(n, paraCombo, ans, 0, 0, 0);
        return ans;
    }
};
