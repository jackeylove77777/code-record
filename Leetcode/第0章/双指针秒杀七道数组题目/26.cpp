class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int a{0},b{0};
        for(int b=0;b<nums.size();b++){
            if(nums[b]!=nums[a]){
                nums[++a]=nums[b];
            }
        }
        return a+1;
    }
};