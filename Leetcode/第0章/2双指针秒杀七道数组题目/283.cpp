class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //相当于把零给删除，然后再把后面的元素都改成0,力扣第27题
        int start = removeElement(nums,0);
        for(int i = start;i<nums.size();i++)nums[i]=0;
    }
    int removeElement(vector<int>& nums, int val) {
        int a{0},b{0};
        for(;b<nums.size();b++){
            if(nums[b]!=val){
                nums[a++]=nums[b];
            }
        }
        return a;
    }    
};