bool cmp(pair<int, int> &s1, pair<int, int> &s2)
{
    return s1.second < s2.second;
}

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> fre_count;
        for(int i = 0; i < nums.size(); i++){
            fre_count[nums[i]]++;
        }
        
        vector<pair<int, int>> heap(fre_count.begin(), fre_count.end());
        make_heap(heap.begin(), heap.end(), cmp);
        
        vector<int> ans(k);
        for(int i = 0; i < k; i++){
            ans[i] = heap.front().first;
            pop_heap(heap.begin(), heap.end() - i, cmp);
        }
        
        return ans;
    }
};