// @before-stub-for-debug-begin

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "commoncppproblem1.h"
#include <unordered_map>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        // mp.insert(pair<int, int>(nums[0], 0));
        // mp.insert(map<int, int>::value_type(nums[0], 0));
        mp[nums[0]] = 0;
        for (int j = 1;; j++) {
            // 在map中查找,也就是在数组的左边去进行查找nums[i],满足nums[i]=target-nums[j]
            auto it = mp.find(target - nums[j]);
            if (it != mp.end()) {
                return {it->second, j};
            }
            mp[nums[j]] = j;
        }
        // return {mp[nums[0]], mp[nums[nums.size() - 1]]};
    }
};
// @lc code=end
