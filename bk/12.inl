class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, char> > vi{ {1000, 'M'}, {500, 'D'}, {100, 'C'}, {50, 'L'}, {10, 'X'}, {5, 'V'}, {1, 'I'} };
        string ret;
        for (int i = 0; i < vi.size(); i++) {
            while (num >= vi[i].first) {
                ret += vi[i].second;
                num -= vi[i].first;
            }
            int post = i + (i + 1) % 2 + 1;
            if (post < vi.size()) {
                if (num >= (vi[i].first - vi[post].first)) {
                    ret += vi[post].second; ret += vi[i].second;
                    num -= (vi[i].first - vi[post].first);
                }
            }
        }
        return ret;
        while (num >= 1000) {
            ret += "M";
            num -= 1000;
        }
        while (num >= 1000 - 100) {
            ret += "CM";
            num -= (1000 - 100);
        }
        while (num >= 500) {
            ret += "D";
            num -= 500;
        }
        while (num >= 500 - 100) {
            ret += "CD";
            num -= (500 - 100);
        }
        while (num >= 100) {
            ret += "C";
            num -= 100;
        }
        while (num >= 100 - 10) {
            ret += "XC";
            num -= (100 - 10);
        }
        while (num >= 50) {
            ret += "L";
            num -= 50;
        }
        while (num >= 50 - 10) {
            ret += "XL";
            num -= (50 - 10);
        }
        while (num >= 10) {
            ret += "X";
            num -= 10;
        }
        while (num >= 10 - 1) {
            ret += "IX";
            num -= (10 - 1);
        }
        while (num >= 5) {
            ret += "V";
            num -= 5;
        }
        while (num >= 5 - 1) {
            ret += "IV";
            num -= (5 - 1);
        }
        while (num >= 1) {
            ret += "I";
            num -= 1;
        }
        return ret;
    }
};