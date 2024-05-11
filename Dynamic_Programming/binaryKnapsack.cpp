// bottom-up dynamic approach

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<int> dp(w + 1,0), dpTemp(w + 1, 0);
	for(int i = 0; i < weights.size(); ++i) {
		dpTemp = dp;
		for(int j = 1; j <= w; ++j)  {
			if(j >= weights[i]) {
				dp[j] = max(dpTemp[j], dpTemp[j - weights[i]] + values[i]);
			} else {
				dp[j] = dpTemp[j];
			}
    }
	}
	return dp[w];
}
