// convert.cpp -- 스톤을 킬로그램으로 환산
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> ParseHouses(int n, const string& houses);

int MaxCollect(int n, const string& houses)
{
	auto c = ParseHouses(n, houses);
	vector<vector<int>> dp(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int c1 = i > 0 ? dp[i - 1][j] : 0;
			int c2 = j > 0 ? dp[i][j - 1] : 0;
			dp[i][j] = max(c1, c2) + c[i][j];
		}
	}
	return dp[n - 1][n - 1];
}


void Match(istream& iss, char c)
{
	char r = '\0';
	while (!iss.eof() && (r == ' ' || r == '\n' || r == '\r' || r == '\0')) iss >> r;
	if (r != c) throw "syntax error";
}

vector<vector<int>> ParseHouses(int n, const string& houses)
{
	vector<vector<int>> res(n, vector<int>(n, 0));
	stringbuf sb(houses);
	istream iss(&sb);

	for (int i = 0; i < n; i++)
	{
		Match(iss, '(');
		for (int j = 0; j < n; j++)
		{
			int c;
			iss >> res[i][j];
			if (j != n - 1) Match(iss, ',');
		}
		Match(iss, ')');
		if (i != n - 1) Match(iss, ',');
	}

	return res;
}



int main()
{
	int in;

	cout << MaxCollect(4, "(1,7,5,2),(5,12,3,6),(100,9,23,16),(16,4,5,9)");
	cin >> in;
}
