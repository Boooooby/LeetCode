class Solution {
public:
    void tryCombination(vector<vector<int>>& res, vector<int>& candidates, vector<int> curSet, int curSum, int target, int beginIdx) {
        if (curSum == target) {
            res.push_back(curSet);
            return;
        }
        
        for (int i = beginIdx; i < candidates.size() && candidates[beginIdx] <= target - curSum; i++) {
            curSet.push_back(candidates[i]);
            tryCombination(res, candidates, curSet, curSum + candidates[i], target, i);
            curSet.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if (candidates.size() == 0) 
            return res;
        vector<int> curSet;
        
        sort(candidates.begin(), candidates.end());
        
        tryCombination(res, candidates, curSet, 0, target, 0);
        
        return res;
    }
};