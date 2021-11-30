#include "stl.h"
#include "283_MoveZeros.inl"
void pvec1(const vector<int>& vi) {
	std::for_each(vi.begin(), vi.end(), [](int i){cout << i << " ";});
	cout << endl;
}
int main() {
	Solution s;
	vector<int> vi;
    vi = {1, 0, 2, 3, 0, 4};
	s.moveZeroes(vi);
	pvec1(vi);

    vi = {0, 1, 0, 0, 5, 0};
	s.moveZeroes(vi);
	pvec1(vi);
	return 0;
}

