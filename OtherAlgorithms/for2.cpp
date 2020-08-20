#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int imax = 5;
const int jmax = 8;
const int ijmin = min(imax, jmax);
const int ijmax = max(imax, jmax);
vector<vector<int>> vi_reset(imax, vector<int>(jmax, 0));
int serial = 0;
void pv(const vector<vector<int>>& v)
{
	for (int i = 0;i < imax;i++)
	{
		for (int j = 0; j < jmax; j++)
		{
			cout << v[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl << endl;
}
int main()
{
	vector<vector<int>> vi;
#if 1
	vi = vi_reset;
	for (int i = 0;i < imax;i ++)
	{
		for (int j = 0;j < jmax;j++)
		{
			vi[i][j] = i * 10 + j;
		}
	}
	pv(vi);
#endif
#if 1
	vi = vi_reset;
	for (int i = 0;i < imax;i++)
	{
		for (int j = i; j < jmax;j++)
		{
			vi[i][j] = i * 10 + j;
		}
	}
	pv(vi);
#endif
#if 1
	vi = vi_reset;
	for (int i = 0; i < imax; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			vi[i][j] = i * 10 + j;
		}
	}
	pv(vi);
#endif
#if 1
	vi = vi_reset;
	for (int i = 0; i < imax; i++)
	{
		for (int j = 0; i + j < ijmin && j < jmax; j++)
		{
			vi[i][j] = i * 10 + j;
		}
	}
	pv(vi);
#endif
#if 1
	vi = vi_reset;
	for (int i = 0; i < imax; i++)
	{
		for (int j = 0; i + j < ijmax && j < jmax; j++)
		{
			vi[i][j] = i * 10 + j;
		}
	}
	pv(vi);
#endif
#if 1
	vi = vi_reset;
	for (int i = 0; i < imax; i++)
	{
		for (int j = ijmin - i - 1; j < jmax; j++)
		{
			vi[i][j] = i * 10 + j;
		}
	}
	pv(vi);
#endif
#if 1
	vi = vi_reset;
	for (int i = 0; i < imax; i++)
	{
		for (int j = ijmax - i - 1; j < jmax; j++)
		{
			vi[i][j] = i * 10 + j;
		}
	}
	pv(vi);
#endif
#if 1
	vi = vi_reset;
	serial = 0;
	for (int i = imax - 1; i >= 0; i--)
	{
		for (int j = jmax - 1; j >=0; j--)
		{
			//vi[i][j] = i * 10 + j;
			vi[i][j] = ++serial;
		}
	}
	pv(vi);
#endif
	return 0;
}