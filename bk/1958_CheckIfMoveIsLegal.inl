class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        int rMax = board.size();
        int cMax = board[0].size();
        vector<vector<int>> diffs = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
        char op_color = color == 'W' ? 'B' : 'W';
        for (const auto& diff : diffs)
        {
            int dr = diff[0];
            int dc = diff[1];
            if (rMove + dr * 2 < 0 || rMove + dr * 2 >= rMax) continue;
            if (cMove + dc * 2 < 0 || cMove + dc * 2 >= cMax) continue;
            if (board[rMove + dr][cMove + dc] != op_color) continue;
            for (size_t i = 2;;i++)
            {
                int r = rMove + dr * i;
                if (r < 0 || r >= rMax) break;
                int c = cMove + dc * i;
                if (c < 0 || c >= cMax) break;
                if (board[r][c] == color)
                    return true;
                if (board[r][c] != op_color) break;
            }
        }

        return false;
    }
};
