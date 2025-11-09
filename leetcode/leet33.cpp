class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int ans = 0;
            if(nums.front() <= nums.back()) {
                auto it = lower_bound(nums.begin(), nums.end(), target);
                if(it != nums.end() && *it == target) ans = it - nums.begin();
                else ans = -1;
            }
            else {
                int div = 0;
                int l = 0, r = nums.size()-1;
                while(l <= r) {
                    int mid = (l + r) / 2;
                    cout<< mid << "\n";
                    if(nums[l] > nums[mid]) {
                        div = mid;
                        r = mid-1;
                    }
                    else if(nums[mid] > nums[r]) {
                        div = mid+1;
                        l = mid+1;
                    }
                    else {
                        break;
                    }
                }
    
                auto left = lower_bound(nums.begin(), nums.begin()+div, target);
                auto right = lower_bound(nums.begin()+div, nums.end(), target);
    
                if(*left == target) {
                    ans = left - nums.begin();
                }
                else if(right != nums.end() && *right == target) {
                    ans = right - nums.begin();
                }
                else {
                    ans = -1;
                }
            }
            return ans;
        }
    };