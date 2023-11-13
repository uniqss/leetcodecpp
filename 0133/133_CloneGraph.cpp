#include "../helpers/stl.h"
#include "../helpers/uassert.h"
#include "../helpers/UnDirectedGraphHelper.h"

class Solution {
   public:
    Node* cloneGraph(Node* node) {}
};

void test(const vector<vector<int>>& adjlist, const vector<vector<int>> expect) {
    save4print(adjlist);
    Node* node = ConstructUnDirectedGraph(adjlist);
    auto ret = Solution().cloneGraph(node);
    auto retvals = node2vals(ret);
    NodeAutoReleaser _(node, ret);
    assert_eq_ret(expect, retvals);
}

int main() {
    test({{2, 4}, {1, 3}, {2, 4}, {1, 3}}, {{2, 4}, {1, 3}, {2, 4}, {1, 3}});
    test({{}}, {{}});
    test({}, {});
    return 0;
}
