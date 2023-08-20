#include <vector>
#include <iostream>

struct Point {
    double x = 0;
    double y = 0;
};
class Solution {
   public:
    void CalcDistance(const std::vector<Point>& points, std::vector<std::tuple<Point, Point, double>>& dis,
                      double& min_dis) {
        return;
    }
};

void test(const std::vector<Point>& points, const std::vector<std::tuple<Point, Point, double>>& dis_expect,
          double min_dis_expect) {
    Solution so;
    std::vector<std::tuple<Point, Point, double>> dis;
    double min_dis = 0;
    so.CalcDistance(points, dis, min_dis);
    if (dis_expect != dis) {
        std::cout << "dis_expect not equal" << std::endl;
    } else if (min_dis != min_dis_expect) {
        std::cout << "min_dis not equal" << std::endl;
    } else {
        std::cout << "ok" << std::endl;
    }
}

int main() {
    test({{0.0, 0.0}, {0.0, 1.0}}, {{{0.0, 0.0}, {0.0, 1.0}, 1.0}}, 1.0);
    test({{0.0, 0.0}, {0.0, 1.0}, {1.0, 1.0}},
         {{{0.0, 1.0}, {0.0, 1.0}, 1.0}, {{0.0, 0.0}, {0.0, 1.0}, 1.0}, {{0, 0}, {1, 1}, 1.4142135}}, 1.4142135);
    return 0;
}
