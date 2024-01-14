class Solution {
public:
    void combine(vector<int> candidates, int target, vector<int> currSet, vector<vector<int>>& ans, int sum, int currindx)
    {
        if(sum>target)
            return;
        if(sum==target)
        {
            ans.push_back(currSet);
            return;
        }

        for(int i=currindx; i<candidates.size(); i++)
        {
            currSet.push_back(candidates[i]);
            sum+=candidates[i];
            combine(candidates, target, currSet, ans, sum, i);
            currSet.pop_back();
            sum-=candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currSet;
        combine(candidates, target, currSet, ans, 0, 0);
        return ans;
    }
};
