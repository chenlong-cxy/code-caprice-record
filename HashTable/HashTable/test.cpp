//1����Ч����ĸ��λ��

////��Ч����ĸ��λ��
//class Solution {
//public:
//    bool isAnagram(string s, string t) {
//        if (s.size() != t.size())
//            return false;
//        int record[26] = { 0 }; //��ϣ��
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


////�����
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
//            if (record[ch - 'a'] < 0) //ʹ�ø��ַ��Ĵ����������ַ���magazine�г��ֵĴ���
//                return false;
//        }
//        return true;
//    }
//};


////��ĸ��λ�ʷ���
//
///* ��ϣ��+���� */
//class Solution {
//public:
//    vector<vector<string>> groupAnagrams(vector<string>& strs) {
//        unordered_map<string, vector<string>> um;
//        for (const string& str : strs) {
//            string key = str;
//            sort(key.begin(), key.end()); //��ĸ��λ��������ֵ��ͬ
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
///* ��ϣ��+���ù�ϣ���� */
//class Solution {
//public:
//    vector<vector<string>> groupAnagrams(vector<string>& strs) {
//        auto getKey = [](const string& s)->string { //����Ϊ��ĸ��λ�ʵ��ַ���תΪ��ͬ��keyֵ
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
//        unordered_map<string, vector<string>> um; //���������һ����ϣ�������ܹ�����Ϊ��ĸ��λ�ʵ��ַ���ת������ͬ����
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


//�ҵ��ַ����е�������ĸ��λ��
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
        int diff = 0; //��¼������������p��������ͬ���ַ��ĸ���
        for (const int& count : record) {
            if (count != 0)
                diff++;
        }
        vector<int> result;
        if (diff == 0) {
            result.push_back(0);
        }
        for (int i = 0; i < sLen - pLen; i++) {
            if (record[s[i] - 'a'] == 1) //--���Ϊ0, ������ͬ���ַ�������һ
                diff--;
            else if (record[s[i] - 'a'] == 0) //--���Ϊ-1, ������ͬ���ַ�������һ
                diff++;
            record[s[i] - 'a']--; //�Ƴ�������������ַ�
            if (record[s[i + pLen] - 'a'] == -1) //++���Ϊ0, ������ͬ���ַ�������һ
                diff--;
            else if (record[s[i + pLen] - 'a'] == 0) //++���Ϊ1, ������ͬ���ַ�������һ
                diff++;
            record[s[i + pLen] - 'a']++; //�ƽ����������Ҳ��ַ�
            if (diff == 0) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};
