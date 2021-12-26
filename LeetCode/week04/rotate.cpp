//给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
//输入: nums = [1,2,3,4,5,6,7], k = 3
//输出: [5,6,7,1,2,3,4]
//解释:
//向右轮转 1 步: [7,1,2,3,4,5,6]
//向右轮转 2 步: [6,7,1,2,3,4,5]
//向右轮转 3 步: [5,6,7,1,2,3,4]
//使用额外的数组
//我们可以使用额外的数组来将每个元素放至正确的位置。用 nn 表示数组的长度，我们遍历原数组，将原数组下标为 ii 的元素放至新数组下标为 (i+k)\bmod n(i+k)modn 的位置，最后将新数组拷贝至原数组即可。
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> newArr(n);
        for (int i = 0; i < n; ++i) {
            newArr[(i + k) % n] = nums[i];
        }
        nums.assign(newArr.begin(), newArr.end());
    }
};
