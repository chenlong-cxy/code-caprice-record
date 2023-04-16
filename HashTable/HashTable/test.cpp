//1��������Ϊ��ϣ��

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


////�ҵ��ַ����е�������ĸ��λ��
//class Solution {
//public:
//    vector<int> findAnagrams(string s, string p) {
//        int sLen = s.size(), pLen = p.size();
//        if (sLen < pLen)
//            return vector<int>();
//        int record[26] = { 0 };
//        for (int i = 0; i < pLen; i++) {
//            record[s[i] - 'a']++;
//            record[p[i] - 'a']--;
//        }
//        int diff = 0; //��¼������������p��������ͬ���ַ��ĸ���
//        for (const int& count : record) {
//            if (count != 0)
//                diff++;
//        }
//        vector<int> result;
//        if (diff == 0) {
//            result.push_back(0);
//        }
//        for (int i = 0; i < sLen - pLen; i++) {
//            if (record[s[i] - 'a'] == 1) //--���Ϊ0, ������ͬ���ַ�������һ
//                diff--;
//            else if (record[s[i] - 'a'] == 0) //--���Ϊ-1, ������ͬ���ַ�������һ
//                diff++;
//            record[s[i] - 'a']--; //�Ƴ�������������ַ�
//            if (record[s[i + pLen] - 'a'] == -1) //++���Ϊ0, ������ͬ���ַ�������һ
//                diff--;
//            else if (record[s[i + pLen] - 'a'] == 0) //++���Ϊ1, ������ͬ���ַ�������һ
//                diff++;
//            record[s[i + pLen] - 'a']++; //�ƽ����������Ҳ��ַ�
//            if (diff == 0) {
//                result.push_back(i + 1);
//            }
//        }
//        return result;
//    }
//};

//2��set��Ϊ��ϣ��
// 
////��������Ľ���
//class Solution {
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        unordered_set<int> numSet(nums1.begin(), nums1.end()); //��������+ȥ��
//        unordered_set<int> result;
//        for (const int& num : nums2) {
//            if (numSet.count(num)) {
//                result.insert(num); //����ȥ��
//            }
//        }
//        return vector<int>(result.begin(), result.end());
//    }
//};

////������
//class Solution {
//public:
//    bool isHappy(int n) {
//        unordered_set<int> record; //��¼�õ�������
//        while (n != 1) {
//            int squareSum = 0;
//            while (n) {
//                int num = n % 10;
//                squareSum += (num * num);
//                n /= 10;
//            }
//            if (record.count(squareSum)) //������ѭ��
//                return false;
//            record.insert(squareSum); //��¼
//            n = squareSum; //��n�滻Ϊÿ��λ���ϵ����ֵ�ƽ����
//        }
//        return true;
//    }
//};


////3��map��Ϊ��ϣ��
//
////��������Ľ���II
//class Solution {
//public:
//    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//        if (nums1.size() > nums2.size()) { //��Ԫ�ظ������ٵ���������ϣ�����Ϳռ临�Ӷ�
//            intersect(nums2, nums1);
//        }
//        unordered_map<int, int> numSet;
//        for (const int& num : nums1) {
//            numSet[num]++;
//        }
//        vector<int> result;
//        for (const int& num : nums2) {
//            if (numSet.count(num)) {
//                result.push_back(num);
//                auto iter = numSet.find(num);
//                iter->second--;
//                if (iter->second == 0) { //��Ԫ�س��ִ�����Ϊ0ʱ������ӹ�ϣ�����Ƴ�
//                    numSet.erase(iter);
//                }
//            }
//        }
//        return result;
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

////����֮��
//
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        unordered_map<int, int> numToIndex; //��¼��������ֵ�����±�
//        for (int i = 0; i < nums.size(); i++) {
//            auto iter = numToIndex.find(target - nums[i]);
//            if (iter != numToIndex.end()) {
//                return { i, iter->second };
//            }
//            numToIndex[nums[i]] = i;
//        }
//        return { -1, -1 };
//    }
//};
///*
//Ԫ��ֵ��Ϊkey: ��Ϊ��Ҫ�����ж��Ƿ��Ѿ����ֹ�ĳ����
//�±�ֵ��Ϊvalue: ��ĳ�����ֹ������뵱ǰ������������Ϊtargetʱ����Ҫ�õ���������±�
//*/


////�������II
//
///* ����+��ϣ�� */
//class Solution {
//public:
//    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
//        unordered_map<int, int> sumCount; //��¼nums1��nums2������֮�������Ӧ���ֵĴ���
//        for (const int& a : nums1) {
//            for (const int& b : nums2) {
//                sumCount[a + b]++;
//            }
//        }
//        int count = 0; //��¼�������Ϊ0�Ĵ���
//        for (const int& c : nums3) {
//            for (const int& d : nums4) {
//                auto iter = sumCount.find(0 - (c + d));
//                if (iter != sumCount.end()) {
//                    count += iter->second;
//                }
//            }
//        }
//        return count;
//    }
//};


////4��˫ָ�뷨
//
////����֮��
//
///* ����+˫ָ�� */
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        int n = nums.size();
//        vector<vector<int>> result;
//        for (int i = 0; i < n; i++) {
//            if (nums[i] > 0)
//                break;
//            if (i > 0 && nums[i] == nums[i - 1]) //����д��nums[i]==nums[i+1]������[-1,-1,2]
//                continue;
//            int left = i + 1, right = n - 1;
//            while (left < right) {
//                int sum = nums[left] + nums[right];
//                if (sum > -nums[i]) {
//                    right--;
//                }
//                else if (sum < -nums[i]) {
//                    left++;
//                }
//                else { //�ҵ�һ����Ԫ��ʱ�ٽ���ȥ��
//                    result.push_back({ nums[i], nums[left], nums[right] });
//                    left++;
//                    while (left < right && nums[left] == nums[left - 1]) { //ȥ��ʱӦ�ú�֮ǰ�ù��ı�
//                        left++;
//                    }
//                }
//            }
//        }
//        return result;
//    }
//};


////����֮��
//
///* ����+˫ָ�� */
//class Solution {
//public:
//    vector<vector<int>> fourSum(vector<int>& nums, int target) {
//        sort(nums.begin(), nums.end());
//        int n = nums.size();
//        vector<vector<int>> result;
//        for (int i = 0; i < n; i++) {
//            if (nums[i] >= 0 && nums[i] > target) //��֦
//                break;
//            if (i > 0 && nums[i] == nums[i - 1]) //ȥ��
//                continue;
//            for (int j = i + 1; j < n; j++) {
//                if (nums[i] + nums[j] >= 0 && nums[i] + nums[j] > target) //��֦
//                    break;
//                if (j > i + 1 && nums[j] == nums[j - 1]) //ȥ��
//                    continue;
//                int left = j + 1, right = n - 1;
//                while (left < right) {
//                    long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
//                    if (sum > target) {
//                        right--;
//                    }
//                    else if (sum < target) {
//                        left++;
//                    }
//                    else {
//                        result.push_back({ nums[i], nums[j], nums[left], nums[right] });
//                        left++;
//                        while (left < right && nums[left] == nums[left - 1]) { //ȥ��
//                            left++;
//                        }
//                    }
//                }
//            }
//        }
//        return result;
//    }
//};
