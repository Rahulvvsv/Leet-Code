#include<map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> Answer;
        map <int,int> omap;
        for(int i =0;i<nums.size();i++){
            if(omap.find(nums[i]) != omap.end() ){
                Answer.push_back(omap[nums[i]]);
                Answer.push_back(i);
                break;
            }
            else{
                omap[target-nums[i]] = i;
               
            }
        }
        return Answer;
        
    }
};
