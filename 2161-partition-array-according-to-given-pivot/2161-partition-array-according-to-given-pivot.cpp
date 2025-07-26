class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left, right;
        int q = 0;
        for(int i: nums){
            if(i<pivot) left.push_back(i);
            else if(i == pivot) q++;
            else right.push_back(i);
        }
        for(int i=0; i<left.size(); i++){
            nums[i] = left[i];
        }
        int k = left.size();
        while(q!=0){
            nums[k++] = pivot;
            q--;
        }
        for(int i=0; i<right.size(); i++){
            nums[i+k] = right[i];
        }
        return nums;
    }
};