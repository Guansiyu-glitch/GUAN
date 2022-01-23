class Solution {
    public List<List<Integer>> generate(int numRows) {
		List<List<Integer>> result=new ArrayList<List<Integer>>();
		int[][] dp=new int[numRows][numRows];
		dp[0][0]=1;
		for (int i = 1; i < numRows; i++) {
			for (int j = 0; j <=i; j++) {
				if(j==0)dp[i][j]=1;
				else dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
			}
		}
		for (int i = 0; i < dp.length; i++) {
			List<Integer> tmp=new ArrayList<>();
			for (int j = 0; j < dp.length; j++) {
				if(dp[i][j]==0) break;
				tmp.add(dp[i][j]);
			}
			result.add(new ArrayList<>(tmp));
		}
		
		return result;
    }
}
