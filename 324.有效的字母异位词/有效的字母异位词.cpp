#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<int, int> umap;
        for (char ch : s) {
            ++umap[ch];
        }
        for (char ch : t) {
            if (umap[ch] > 0) {
                --umap[ch];
            } else {
                return false;
            }
        }
        return true;
    }
};
static const auto io_speed_up=[]{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();