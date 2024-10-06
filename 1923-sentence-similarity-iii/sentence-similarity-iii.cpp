class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        string temp = "";
        deque<string> a, b;
        for (char c : s1) {
            if (c == ' ')
                a.push_back(temp), temp = "";
            else
                temp += c;
        }
        a.push_back(temp), temp = "";
        for (char c : s2) {
            if (c == ' ')
                b.push_back(temp), temp = "";
            else
                temp += c;
        }
        b.push_back(temp), temp = "";

        while (a.size() && b.size() && (a.front() == b.front()))
            a.pop_front(), b.pop_front();

        while (a.size() && b.size() && (a.back() == b.back()))
            a.pop_back(), b.pop_back();
        if (!a.size() || !b.size())
            return true;
        return false;
    }
};