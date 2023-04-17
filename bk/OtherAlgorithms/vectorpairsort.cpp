#include "../../inc.h"

struct CItem {
    unsigned Valdword;
};
void SortItemsByGridPos(vector<CItem*>& vecItems) {
    int Attr_GridPos = 1024;
    std::sort(vecItems.begin(), vecItems.end(),
              [&](const CItem* item1, const CItem* item2) { return item1->Valdword < item2->Valdword; });
}

int main() {
    {
        vector<CItem*> vecItems;
        auto addItem = [](vector<CItem*>& vi, int i) {
            CItem* item = new CItem();
            item->Valdword = i;
            vi.push_back(item);
        };
        addItem(vecItems, 1);
        addItem(vecItems, 9);
        addItem(vecItems, 2);
        addItem(vecItems, 8);
        SortItemsByGridPos(vecItems);
        for (auto it : vecItems) {
            cout << it->Valdword << "\t";
        }
        cout << endl;
        for (auto it : vecItems) {
            delete it;
        }
    }
    {
        vector<pair<int, int>> vii;
        vii.push_back({1, 100});
        vii.push_back({1, 200});
        vii.push_back({10, 37});
        vii.push_back({10, 30});
        vii.push_back({2, 37});
        vii.push_back({9, 37});
        vii.push_back({3, 37});
        vii.push_back({8, 37});
        vii.push_back({4, 37});
        vii.push_back({6, 37});
        vii.push_back({5, 37});
        std::sort(vii.begin(), vii.end(), [](const auto& lhs, const auto& rhs) { return lhs.first < rhs.first; });
        print(vii);
    }
    {
        vector<tuple<int, int, int>> vii;
        vii.push_back({1, 1, 100});
        vii.push_back({1, 1, 200});
        vii.push_back({10, 1, 37});
        vii.push_back({10, 1, 30});
        vii.push_back({2, 1, 37});
        vii.push_back({9, 1, 37});
        vii.push_back({3, 1, 37});
        vii.push_back({8, 1, 37});
        vii.push_back({4, 1, 37});
        vii.push_back({6, 1, 37});
        vii.push_back({5, 1, 37});
        std::sort(vii.begin(), vii.end(),
                  [](const auto& lhs, const auto& rhs) { return std::get<0>(lhs) < std::get<0>(rhs); });
        // print(vii);
        for (auto it : vii) {
            cout << std::get<0>(it) << "|" << std::get<1>(it) << "|" << std::get<2>(it) << endl;
        }
    }

    return 0;
}
