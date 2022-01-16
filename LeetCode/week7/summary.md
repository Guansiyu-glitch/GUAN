### week7学习总结

#### （一）算法导论：

分治法基本思想：
将问题分解成多个子问题，并允许不断分解，使规模越来越小，最终可用已知的方法求解足够小的问题。
﻿
使用要求：
（1） 问题能够按照某种方式分解成若干个规模较小、相互独立且与原问题类型相同的子问题。
（2） 子问题足够小时可以直接求解。
（3） 能够将子问题的解组合成原问题的解。

贪心法：
基本思想：
总是选择当前最优解，并不考虑整体最优。
特点：
拥有最优子结构特性。当一个问题的最优解包含其子问题的最优解时，称此问题具有最优子结构性质。问题的最优子结构性质是该问题可用动态规划算法或贪心算法求解的关键特征。

动态规划法：
基本思想：将较大问题分解为较小的同类子问题，这一点上它与分治法和贪心法类似。动态规划法解决子问题重叠现象，利用最优子结构，自底向上从子问题的最优解逐步构造出整个问题的最优解。
﻿
适用动态规划法的要求：具有最优子结构特性和重叠子问题。
﻿
与贪心算法比较：
贪心算法：局部的最优性依赖于其前面各部分是否最优；且不能保证最终解的最优性。
动态规划：当前决策的最优性取决于其后续决策系列的是否最优。动态规划方法可以保证问题求解是全局最优的。

```

```

#### （二）力扣刷题：

###### 784字母大小写全排列

```
输入：S = "a1b2"
输出：["a1b2", "a1B2", "A1b2", "A1B2"]
```

思路：通过dfs遍历输入字符，对dfs中每一层有两种可能：（1）不改变 （2）是字母，改变大小写



    class Solution {
        public List<String> letterCasePermutation(String s) {
            List<String> ans = new LinkedList<>();
            backTrack(new StringBuilder(s), ans, 0);
            return ans;
        }
    private void backTrack(StringBuilder s, List<String> ans, int curIndex) {
        if(curIndex == s.length()) {
            ans.add(new String(s));
            return;
        }
    
        char c = s.charAt(curIndex);
        // 不做任何改变
        backTrack(s, ans, curIndex + 1);
    
        //改为大写或者小写(前提是字母)
        if((c >='A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            if(c <= 'Z') {
                s.setCharAt(curIndex, (char)(c + 32));
            } else {
                s.setCharAt(curIndex, (char)(c - 32));
            }
    
            backTrack(s, ans, curIndex + 1);
        }
    
    }


###### 70爬楼梯

假设你正在爬楼梯。需要 *n* 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

思路：类似于斐波那契数列  它意味着爬到第 x 级台阶的方案数是爬到第 x - 1*x*−1 级台阶的方案数和爬到第 x - 2*x*−2 级台阶的方案数的和。

动态数组实现

```
class Solution {
public:
    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i) {
            p = q; 
            q = r; 
            r = p + q;
        }
        return r;
    }
};
```



###### 198 打家劫舍

如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

 

```
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }
};
```

###### 120 三角形最小路径和

输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
输出：11
解释：如下面简图所示：
   2
  3 4
 6 5 7
4 1 8 3
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。



思路：从三角形最后一层开始向上遍历，每个数字的最小路径和是它下面两个数中min+本身

```
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.back());
        for(int i = triangle.size() - 2; i >= 0; i --)
            for(int j = 0; j <= i; j ++)
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
        return dp[0];
    }
};

```

###### 231 2的幂

给你一个整数 `n`，请你判断该整数是否是 2 的幂次方。如果是，返回 `true` ；否则，返回 `false` 。

```
class Solution {
    public boolean isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
}
```

###### 136.只出现一次的数字

给定一个**非空**整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

```
class Solution {
    public int singleNumber(int[] nums) {
        int single = 0;
        for (int num : nums) {//异或，如果出现重复，异或会为0消除
            single ^= num;
        }
        return single;
    }
}
```

###### 53，最大子数组和

```
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 
```

方法一：动态规划

```
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result = INT_MIN;
        int numsSize = int(nums.size());
        //因为只需要知道dp的前一项，我们用int代替一维数组
        int dp(nums[0]);
        result = dp;
        for (int i = 1; i < numsSize; i++)
        {
            dp = max(dp + nums[i], nums[i]);
            result = max(result, dp);
        }

        return result;
    }
};


```

方法二：贪心法

```
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result = INT_MIN;
        int numsSize = int(nums.size());
        int sum = 0;
        for (int i = 0; i < numsSize; i++)
        {
            sum += nums[i];
            result = max(result, sum);
            //如果sum < 0，重新开始找子序串
            if (sum < 0)
            {
                sum = 0;
            }
        }

        return result;
    }
};


```

##### 学习总结：

   本周主要刷的题还是简单和中等难度，学习使用动态数组，哈希表，回溯法等解决具体问题。如在解决136只出现一次的数字问题中，我刚开始能想到的最优的方法就是先排序，再遍历。而用异或运算真是太好了，解决起来十分简单代码也简洁。算法导论学习了分治法的基本思想，典型的例题有汉诺塔问题，将问题分解成多个子问题，并允许不断分解，使规模越来越小，最终可用已知的方法求解足够小的问题。 下周的安排是：继续按照模块学习力扣，算法导论跟着视频继续学习关于动态规划，矩阵连乘，最优二叉搜索树问题等。
﻿
