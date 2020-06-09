class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() == 0) return -1;
        int left = 0, right = nums.size() - 1;
        
        while(true){
            int pivot = partition(left, right, nums);
            if (pivot == k - 1) return nums[pivot];
            else if(pivot > k - 1) right = pivot - 1;
            else left = pivot + 1;
        }
        
        return -1;
    } 
    
    int partition(int left, int right, vector<int> &nums){
        int pivot = nums[left];
        int l = left + 1;
        int r = right;
        while(l <= r){
            if(nums[l] < pivot && nums[r] > pivot){
                swap(nums[l], nums[r]);
                ++l;--r;
            }
            
            if(nums[l] >= pivot) ++l;
            if(nums[r] <= pivot) --r;
        }
        swap(nums[left], nums[r]);
        
        return r;
    }
};