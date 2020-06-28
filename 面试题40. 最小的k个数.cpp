class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int size = arr.size();
        vector<int> ans;
        if(size == 0 || k == 0) return ans;
        int left = 0;
        int right = size - 1;

        while(true){
            int pivot = partition(arr, left, right);

            if(pivot == k - 1){
                ans.insert(ans.begin(), arr.begin(), arr.begin() + k);
                break;
            }
            else if(pivot > k - 1){
                right = pivot - 1;
            }else if(pivot < k - 1){
                left = pivot + 1;
            }
        }

        return ans;
    }

    int partition(vector<int>& arr, int left, int right)
    {
        int pivot_val = arr[left];
        int l = left + 1;
        int r = right;
        while(l <= r){
            if(arr[l] > pivot_val && arr[r] < pivot_val){
                swap(arr[l], arr[r]);
                l++;r--;
            }
            else if(arr[l] <= pivot_val){
                l++;
            }
            else if(arr[r] >= pivot_val){
                r--;
            }
        }

        swap(arr[left], arr[r]);

        return r;
    }
};