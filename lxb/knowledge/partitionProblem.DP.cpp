http://en.wikipedia.org/wiki/Partitioning_problem
/*Question:
In computer science, the partition problem is the task of deciding whether a given multiset S of positive integers can be partitioned into two subsets S1 and S2 such that the sum of the numbers in S1 equals the sum of the numbers in S2. Although the partition problem is NP-complete, there is a pseudo-polynomial time dynamic programming solution, and there are heuristics that solve the problem in many instances, either optimally or approximately. For this reason, it has been called "The Easiest Hard Problem".[1]

Example:
Given S = {3,1,1,2,2,1}, a valid solution to the partition problem is the two sets S1 = {1,1,1,2} and S2 = {2,3}. Both sets sum to 5, and they partition S. Note that this solution is not unique. S1 = {3,1,1} and S2 = {2,2,1} is another solution.
Not every multiset of positive integers has a partition into two halves with equal sum. An example of such a set is S = {2,5,1,11,3,5,10,24,555,123,985,1337,9,13,24,89,19,27}.

*/

bool balancedPartition(vector<int> S)
{
	int N = S.size();
	int sum = 0;

	for (auto x: S) sum+=x;

	//DP[sum,i]: true if there exists S[0..i-1], whose sum is sum.
	vector<vector<bool> > DP(sum/2+1,vector<int>(N+1,false));

	//init
	for (int i = 0; i <= N; i++) DP[0][i] = true;;
	for (int x = 1; x <= sum/2; x++) DP[x][0] = false;

	//DP.
	for (int i=1; i<= sum/2; i++)
	for (int j=1; j< =N; j++)
	{
		if (s[j-1] > i) {
			DP[i][j] = DP[i][j-1];
		}else{
			DP[i][j] = DP[i][j-1] || DP[i-s[j-1]][j-1];
		}
	}

	return DP[sum/2][N];
}
