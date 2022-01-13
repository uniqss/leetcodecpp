class FiniteStateMachine {
public:
    FiniteStateMachine() {
        state = "begin";
        bPositive = true;
        number = 0;
    }

private:
    string state;
    bool bPositive;
    int number;

    // begin, signed, number, end
    // " ", "+/-", "0-9", "other"
    unordered_map<string, vector<string>> mvs = {
        {"begin", {"begin", "signed", "number", "end"}},
        {"signed", {"end", "end", "number", "end"}},
        {"number", {"end", "end", "number", "end"}},
        {"end", {"end", "end", "end", "end"}},
    };

public:
    bool nextStep(char c) {
        int type = getType(c);
        state = mvs.find(state)->second[type];
        if (state == "number") {
            int curr = c - '0';
            if (bPositive && (number > 214748364 || number == 214748364 && curr > 7)) {
                number = 2147483647;
                return false;
            }
            if (!bPositive && (number > 214748364 || number == 214748364 && curr >= 8)) {
                number = -2147483648;
                return false;
            }
            number *= 10;
            number += c - '0';
        }
        return state != "end";
    }

    int getNumber() {
        if (number < 0) return number;
        if (bPositive)
        {
            return number;
        }
        return -number;
    }

private:
    int getType(char c) {
        if (c == ' ') {
            return 0;
        }
        else if (c == '+')
        {
            return 1;
        }
        else if (c == '-')
        {
            if (state == "begin")
            {
                bPositive = false;
            }
            return 1;
        }
        else if (c >= '0' && c <= '9')
        {
            return 2;
        }
        else {
            return 3;
        }
    }
};
class Solution {
public:
    int myAtoi(string str) {
        FiniteStateMachine fsm;
        for (auto c : str) {
            if (!fsm.nextStep(c))
                break;
        }
        return fsm.getNumber();
    }
};
