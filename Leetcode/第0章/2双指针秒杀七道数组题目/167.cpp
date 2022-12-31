class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0,right = nums.size()-1;
        vector<int> res = {-1,-1};
        while(left<right){
            int sum = nums[left]+nums[right];
            if(sum==target){
                res[0]=left+1,res[1]=right+1;
                return res;
            }else if(sum<target)left++;
            else right--;
        }
        return res;
    }
};