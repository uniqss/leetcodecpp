#include "../inc.h"

// 搞定了，但是会超出时间限制，必须优化时间
class Solution {
   public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.count(endWord) == 0) return {};
        int n = beginWord.size();
        vector<vector<string>> ret;
        unordered_set<string> vis = {beginWord};
        int mindepth = INT_MAX;
        vector<string> road = {beginWord};
        function<void(int, string)> dfs = [&](int depth, string curr) {
            if (depth >= mindepth) return;
            for (int i = 0; i < n; ++i) {
                char before = curr[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == before) continue;
                    curr[i] = c;
                    if (dict.count(curr) == 0) continue;
                    if (vis.count(curr) > 0) continue;
                    vis.insert(curr);
                    road.emplace_back(curr);
                    if (curr == endWord) {
                        mindepth = min(depth, mindepth);
                        ret.emplace_back(road);
                    } else {
                        dfs(depth + 1, curr);
                    }
                    road.pop_back();
                    vis.erase(curr);
                }
                curr[i] = before;
            }
        };
        dfs(1, beginWord);
        vector<vector<string>> ret_md;
        for (const auto& ri : ret) {
            if (ri.size() == mindepth + 1) ret_md.push_back(ri);
        }
        return ret_md;
    }
};

void test(string&& beginWord, string&& endWord, vector<string>&& wordList,
          vector<vector<string>>&& expect) {
    save4print(beginWord, endWord, wordList);
    assert_eq_ret(expect, Solution().findLadders(beginWord, endWord, wordList));
}

int main() {
    test("a", "c", {"a", "b", "c"}, {{"a", "c"}});
    test("cet", "ism",
         {"kid", "tag", "pup", "ail", "tun", "woo", "erg", "luz", "brr", "gay", "sip", "kay", "per",
          "val", "mes", "ohs", "now", "boa", "cet", "pal", "bar", "die", "war", "hay", "eco", "pub",
          "lob", "rue", "fry", "lit", "rex", "jan", "cot", "bid", "ali", "pay", "col", "gum", "ger",
          "row", "won", "dan", "rum", "fad", "tut", "sag", "yip", "sui", "ark", "has", "zip", "fez",
          "own", "ump", "dis", "ads", "max", "jaw", "out", "btu", "ana", "gap", "cry", "led", "abe",
          "box", "ore", "pig", "fie", "toy", "fat", "cal", "lie", "noh", "sew", "ono", "tam", "flu",
          "mgm", "ply", "awe", "pry", "tit", "tie", "yet", "too", "tax", "jim", "san", "pan", "map",
          "ski", "ova", "wed", "non", "wac", "nut", "why", "bye", "lye", "oct", "old", "fin", "feb",
          "chi", "sap", "owl", "log", "tod", "dot", "bow", "fob", "for", "joe", "ivy", "fan", "age",
          "fax", "hip", "jib", "mel", "hus", "sob", "ifs", "tab", "ara", "dab", "jag", "jar", "arm",
          "lot", "tom", "sax", "tex", "yum", "pei", "wen", "wry", "ire", "irk", "far", "mew", "wit",
          "doe", "gas", "rte", "ian", "pot", "ask", "wag", "hag", "amy", "nag", "ron", "soy", "gin",
          "don", "tug", "fay", "vic", "boo", "nam", "ave", "buy", "sop", "but", "orb", "fen", "paw",
          "his", "sub", "bob", "yea", "oft", "inn", "rod", "yam", "pew", "web", "hod", "hun", "gyp",
          "wei", "wis", "rob", "gad", "pie", "mon", "dog", "bib", "rub", "ere", "dig", "era", "cat",
          "fox", "bee", "mod", "day", "apr", "vie", "nev", "jam", "pam", "new", "aye", "ani", "and",
          "ibm", "yap", "can", "pyx", "tar", "kin", "fog", "hum", "pip", "cup", "dye", "lyx", "jog",
          "nun", "par", "wan", "fey", "bus", "oak", "bad", "ats", "set", "qom", "vat", "eat", "pus",
          "rev", "axe", "ion", "six", "ila", "lao", "mom", "mas", "pro", "few", "opt", "poe", "art",
          "ash", "oar", "cap", "lop", "may", "shy", "rid", "bat", "sum", "rim", "fee", "bmw", "sky",
          "maj", "hue", "thy", "ava", "rap", "den", "fla", "auk", "cox", "ibo", "hey", "saw", "vim",
          "sec", "ltd", "you", "its", "tat", "dew", "eva", "tog", "ram", "let", "see", "zit", "maw",
          "nix", "ate", "gig", "rep", "owe", "ind", "hog", "eve", "sam", "zoo", "any", "dow", "cod",
          "bed", "vet", "ham", "sis", "hex", "via", "fir", "nod", "mao", "aug", "mum", "hoe", "bah",
          "hal", "keg", "hew", "zed", "tow", "gog", "ass", "dem", "who", "bet", "gos", "son", "ear",
          "spy", "kit", "boy", "due", "sen", "oaf", "mix", "hep", "fur", "ada", "bin", "nil", "mia",
          "ewe", "hit", "fix", "sad", "rib", "eye", "hop", "haw", "wax", "mid", "tad", "ken", "wad",
          "rye", "pap", "bog", "gut", "ito", "woe", "our", "ado", "sin", "mad", "ray", "hon", "roy",
          "dip", "hen", "iva", "lug", "asp", "hui", "yak", "bay", "poi", "yep", "bun", "try", "lad",
          "elm", "nat", "wyo", "gym", "dug", "toe", "dee", "wig", "sly", "rip", "geo", "cog", "pas",
          "zen", "odd", "nan", "lay", "pod", "fit", "hem", "joy", "bum", "rio", "yon", "dec", "leg",
          "put", "sue", "dim", "pet", "yaw", "nub", "bit", "bur", "sid", "sun", "oil", "red", "doc",
          "moe", "caw", "eel", "dix", "cub", "end", "gem", "off", "yew", "hug", "pop", "tub", "sgt",
          "lid", "pun", "ton", "sol", "din", "yup", "jab", "pea", "bug", "gag", "mil", "jig", "hub",
          "low", "did", "tin", "get", "gte", "sox", "lei", "mig", "fig", "lon", "use", "ban", "flo",
          "nov", "jut", "bag", "mir", "sty", "lap", "two", "ins", "con", "ant", "net", "tux", "ode",
          "stu", "mug", "cad", "nap", "gun", "fop", "tot", "sow", "sal", "sic", "ted", "wot", "del",
          "imp", "cob", "way", "ann", "tan", "mci", "job", "wet", "ism", "err", "him", "all", "pad",
          "hah", "hie", "aim"},
         {{"cet", "cat", "can", "ian", "inn", "ins", "its", "ito", "ibo", "ibm", "ism"},
          {"cet", "cot", "con", "ion", "inn", "ins", "its", "ito", "ibo", "ibm", "ism"}});
    test("qa", "sq",
         {"si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le",
          "av", "sm", "ar", "ci", "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn",
          "ya", "cr", "po", "fe", "ho", "ma", "re", "or", "rn", "au", "ur", "rh", "sr", "tc",
          "lt", "lo", "as", "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb", "sh", "co",
          "ga", "li", "ha", "hz", "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an",
          "me", "mo", "na", "la", "st", "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io",
          "be", "fm", "ta", "tb", "ni", "mr", "pa", "he", "lr", "sq", "ye"},
         {{"qa", "ba", "be", "se", "sq"}, {"qa", "ba", "bi", "si", "sq"},
          {"qa", "ba", "br", "sr", "sq"}, {"qa", "ca", "ci", "si", "sq"},
          {"qa", "ca", "cm", "sm", "sq"}, {"qa", "ca", "co", "so", "sq"},
          {"qa", "ca", "cr", "sr", "sq"}, {"qa", "fa", "fe", "se", "sq"},
          {"qa", "fa", "fm", "sm", "sq"}, {"qa", "fa", "fr", "sr", "sq"},
          {"qa", "ga", "ge", "se", "sq"}, {"qa", "ga", "go", "so", "sq"},
          {"qa", "ha", "he", "se", "sq"}, {"qa", "ha", "hi", "si", "sq"},
          {"qa", "ha", "ho", "so", "sq"}, {"qa", "la", "le", "se", "sq"},
          {"qa", "la", "li", "si", "sq"}, {"qa", "la", "ln", "sn", "sq"},
          {"qa", "la", "lo", "so", "sq"}, {"qa", "la", "lr", "sr", "sq"},
          {"qa", "la", "lt", "st", "sq"}, {"qa", "ma", "mb", "sb", "sq"},
          {"qa", "ma", "me", "se", "sq"}, {"qa", "ma", "mi", "si", "sq"},
          {"qa", "ma", "mn", "sn", "sq"}, {"qa", "ma", "mo", "so", "sq"},
          {"qa", "ma", "mr", "sr", "sq"}, {"qa", "ma", "mt", "st", "sq"},
          {"qa", "na", "nb", "sb", "sq"}, {"qa", "na", "ne", "se", "sq"},
          {"qa", "na", "ni", "si", "sq"}, {"qa", "na", "no", "so", "sq"},
          {"qa", "pa", "pb", "sb", "sq"}, {"qa", "pa", "ph", "sh", "sq"},
          {"qa", "pa", "pi", "si", "sq"}, {"qa", "pa", "pm", "sm", "sq"},
          {"qa", "pa", "po", "so", "sq"}, {"qa", "pa", "pt", "st", "sq"},
          {"qa", "ra", "rb", "sb", "sq"}, {"qa", "ra", "re", "se", "sq"},
          {"qa", "ra", "rh", "sh", "sq"}, {"qa", "ra", "rn", "sn", "sq"},
          {"qa", "ta", "tb", "sb", "sq"}, {"qa", "ta", "tc", "sc", "sq"},
          {"qa", "ta", "th", "sh", "sq"}, {"qa", "ta", "ti", "si", "sq"},
          {"qa", "ta", "tm", "sm", "sq"}, {"qa", "ta", "to", "so", "sq"},
          {"qa", "ya", "yb", "sb", "sq"}, {"qa", "ya", "ye", "se", "sq"},
          {"qa", "ya", "yo", "so", "sq"}});
    test(
        "red", "tax", {"ted", "tex", "red", "tax", "tad", "den", "rex", "pee"},
        {{"red", "ted", "tad", "tax"}, {"red", "ted", "tex", "tax"}, {"red", "rex", "tex", "tax"}});
    test("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"},
         {{"hit", "hot", "dot", "dog", "cog"}, {"hit", "hot", "lot", "log", "cog"}});
    test("hit", "cog", {"hot", "dot", "dog", "lot", "log"}, {});
    return 0;
}
