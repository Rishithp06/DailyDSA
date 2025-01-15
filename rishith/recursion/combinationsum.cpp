class Solution {
public:

vector<int>temp;
    void solve(int target,vector<int>&candidates,vector<vector<int>>&ans,int index)
    {
       
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }

        for(int i=index;i<candidates.size();i++)
        {
            temp.push_back(candidates[i]);
            //hereif any number is pushed,it will get inside target-candidate loop 
            //and if its >=0 then recursive function is called.It goes to base condition
            //in base if target=0 then that temp is valid and pushed to ans. inspite of 
            //that number being valid/not , it is removed for checkign other numbers 
            //or combination.
            if(target-candidates[i]>=0)
            {
                // target=target-candidates[i]; if you do this then target gets changed forever
                solve(target-candidates[i],candidates,ans,i);
            }
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        
        solve(target,candidates,ans,0);
        return ans;
    }
};