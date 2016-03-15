class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hash;
        hash[nums[0]] = 0;
        for (int i = 1; i < nums.size(); ++i) {
            map<int,int>::iterator it = hash.find(target - nums[i]) ;
            if (it != hash.end() && it->second != i) {
                vector<int> result(2,i);
                result[1] = (it->second);
                return result;
            } else {
                hash[nums[i]] = i;
            }
        }
    }
};
