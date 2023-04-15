//1、有效的字母异位词

////有效的字母异位词
//class Solution {
//public:
//    bool isAnagram(string s, string t) {
//        if (s.size() != t.size())
//            return false;
//        int record[26] = { 0 }; //哈希表
//        for (const char& ch : s) {
//            record[ch - 'a']++;
//        }
//        for (const char& ch : t) {
//            record[ch - 'a']--;
//        }
//        for (const int& count : record) {
//            if (count != 0)
//                return false;
//        }
//        return true;
//    }
//};


////赎金信
//class Solution {
//public:
//    bool canConstruct(string ransomNote, string magazine) {
//        if (ransomNote.size() > magazine.size())
//            return false;
//        int record[26] = { 0 };
//        for (const char& ch : magazine) {
//            record[ch - 'a']++;
//        }
//        for (const char& ch : ransomNote) {
//            record[ch - 'a']--;
//            if (record[ch - 'a'] < 0) //使用该字符的次数超过该字符在magazine中出现的次数
//                return false;
//        }
//        return true;
//    }
//};


////字母异位词分组
//
///* 哈希表+排序 */
//class Solution {
//public:
//    vector<vector<string>> groupAnagrams(vector<string>& strs) {
//        unordered_map<string, vector<string>> um;
//        for (const string& str : strs) {
//            string key = str;
//            sort(key.begin(), key.end()); //字母异位词排序后的值相同
//            um[key].push_back(str);
//        }
//        vector<vector<string>> result;
//        for (auto iter = um.begin(); iter != um.end(); iter++) {
//            result.push_back(iter->second);
//        }
//        return result;
//    }
//};
//
///* 哈希表+设置哈希函数 */
//class Solution {
//public:
//    vector<vector<string>> groupAnagrams(vector<string>& strs) {
//        auto getKey = [](const string& s)->string { //将互为字母异位词的字符串转为相同的key值
//            int record[26] = { 0 };
//            for (const char& ch : s) {
//                record[ch - 'a']++;
//            }
//            string key;
//            for (int i = 0; i < 26; i++) {
//                if (record[i] != 0) {
//                    key += ('a' + i);
//                    key += to_string(record[i]);
//                }
//            }
//            return key;
//        };
//        unordered_map<string, vector<string>> um; //最好是设置一个哈希函数，能够将互为字母异位词的字符串转换成相同整数
//        for (const string& str : strs) {
//            string key = getKey(str);
//            um[key].push_back(str);
//        }
//        vector<vector<string>> result;
//        for (auto iter = um.begin(); iter != um.end(); iter++) {
//            result.push_back(iter->second);
//        }
//        return result;
//    }
//};


//找到字符串中的所有字母异位词
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        if (sLen < pLen)
            return vector<int>();
        int record[26] = { 0 };
        for (int i = 0; i < pLen; i++) {
            record[s[i] - 'a']++;
            record[p[i] - 'a']--;
        }
        int diff = 0; //记录滑动窗口中与p中数量不同的字符的个数
        for (const int& count : record) {
            if (count != 0)
                diff++;
        }
        vector<int> result;
        if (diff == 0) {
            result.push_back(0);
        }
        for (int i = 0; i < sLen - pLen; i++) {
            if (record[s[i] - 'a'] == 1) //--后变为0, 数量不同的字符个数减一
                diff--;
            else if (record[s[i] - 'a'] == 0) //--后变为-1, 数量不同的字符个数加一
                diff++;
            record[s[i] - 'a']--; //移出滑动窗口左侧字符
            if (record[s[i + pLen] - 'a'] == -1) //++后变为0, 数量不同的字符个数减一
                diff--;
            else if (record[s[i + pLen] - 'a'] == 0) //++后变为1, 数量不同的字符个数加一
                diff++;
            record[s[i + pLen] - 'a']++; //移进滑动窗口右侧字符
            if (diff == 0) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};
