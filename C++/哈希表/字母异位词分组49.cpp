#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result; // 结果集
        map<string, vector<string>> anagram_map;

        for (const string& str : strs) {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            anagram_map[sorted_str].push_back(str);
        }

        for (const auto& pair : anagram_map) {
            result.push_back(pair.second);
        }

        //输出
        cout << "[";
        for (size_t i = 0; i < result.size(); ++i) {
            cout << "[";
            for (size_t j = 0; j < result[i].size(); ++j) {
                cout << "\"" << result[i][j] << "\"";
                if (j < result[i].size() - 1) {
                    cout << ",";
                }
            }
            cout << "]";
            if (i < result.size() - 1) {
                cout << ",";
            }
        }
        cout << "]" << endl;

        return result;
    }
};