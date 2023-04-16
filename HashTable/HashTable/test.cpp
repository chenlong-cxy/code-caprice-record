//1、数组作为哈希表

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


////找到字符串中的所有字母异位词
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
//        int diff = 0; //记录滑动窗口中与p中数量不同的字符的个数
//        for (const int& count : record) {
//            if (count != 0)
//                diff++;
//        }
//        vector<int> result;
//        if (diff == 0) {
//            result.push_back(0);
//        }
//        for (int i = 0; i < sLen - pLen; i++) {
//            if (record[s[i] - 'a'] == 1) //--后变为0, 数量不同的字符个数减一
//                diff--;
//            else if (record[s[i] - 'a'] == 0) //--后变为-1, 数量不同的字符个数加一
//                diff++;
//            record[s[i] - 'a']--; //移出滑动窗口左侧字符
//            if (record[s[i + pLen] - 'a'] == -1) //++后变为0, 数量不同的字符个数减一
//                diff--;
//            else if (record[s[i + pLen] - 'a'] == 0) //++后变为1, 数量不同的字符个数加一
//                diff++;
//            record[s[i + pLen] - 'a']++; //移进滑动窗口右侧字符
//            if (diff == 0) {
//                result.push_back(i + 1);
//            }
//        }
//        return result;
//    }
//};

//2、set作为哈希表
// 
////两个数组的交集
//class Solution {
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        unordered_set<int> numSet(nums1.begin(), nums1.end()); //加锁查找+去重
//        unordered_set<int> result;
//        for (const int& num : nums2) {
//            if (numSet.count(num)) {
//                result.insert(num); //交集去重
//            }
//        }
//        return vector<int>(result.begin(), result.end());
//    }
//};

////快乐数
//class Solution {
//public:
//    bool isHappy(int n) {
//        unordered_set<int> record; //记录得到过的数
//        while (n != 1) {
//            int squareSum = 0;
//            while (n) {
//                int num = n % 10;
//                squareSum += (num * num);
//                n /= 10;
//            }
//            if (record.count(squareSum)) //会无限循环
//                return false;
//            record.insert(squareSum); //记录
//            n = squareSum; //将n替换为每个位置上的数字的平方和
//        }
//        return true;
//    }
//};


////3、map作为哈希表
//
////两个数组的交集II
//class Solution {
//public:
//    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//        if (nums1.size() > nums2.size()) { //将元素个数较少的数组放入哈希表，降低空间复杂度
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
//                if (iter->second == 0) { //当元素出现次数减为0时，将其从哈希表中移出
//                    numSet.erase(iter);
//                }
//            }
//        }
//        return result;
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

////两数之和
//
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        unordered_map<int, int> numToIndex; //记录遍历过的值及其下标
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
//元素值作为key: 因为需要快速判断是否已经出现过某个数
//下标值作为value: 当某个出现过的数与当前遍历到的数和为target时，需要得到这个数的下标
//*/


////四数相加II
//
///* 分组+哈希表 */
//class Solution {
//public:
//    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
//        unordered_map<int, int> sumCount; //记录nums1和nums2中两数之和与其对应出现的次数
//        for (const int& a : nums1) {
//            for (const int& b : nums2) {
//                sumCount[a + b]++;
//            }
//        }
//        int count = 0; //记录四数相加为0的次数
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


////4、双指针法
//
////三数之和
//
///* 排序+双指针 */
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        int n = nums.size();
//        vector<vector<int>> result;
//        for (int i = 0; i < n; i++) {
//            if (nums[i] > 0)
//                break;
//            if (i > 0 && nums[i] == nums[i - 1]) //不能写成nums[i]==nums[i+1]，例如[-1,-1,2]
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
//                else { //找到一个三元组时再进行去重
//                    result.push_back({ nums[i], nums[left], nums[right] });
//                    left++;
//                    while (left < right && nums[left] == nums[left - 1]) { //去重时应该和之前用过的比
//                        left++;
//                    }
//                }
//            }
//        }
//        return result;
//    }
//};


////四数之和
//
///* 排序+双指针 */
//class Solution {
//public:
//    vector<vector<int>> fourSum(vector<int>& nums, int target) {
//        sort(nums.begin(), nums.end());
//        int n = nums.size();
//        vector<vector<int>> result;
//        for (int i = 0; i < n; i++) {
//            if (nums[i] >= 0 && nums[i] > target) //剪枝
//                break;
//            if (i > 0 && nums[i] == nums[i - 1]) //去重
//                continue;
//            for (int j = i + 1; j < n; j++) {
//                if (nums[i] + nums[j] >= 0 && nums[i] + nums[j] > target) //剪枝
//                    break;
//                if (j > i + 1 && nums[j] == nums[j - 1]) //去重
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
//                        while (left < right && nums[left] == nums[left - 1]) { //去重
//                            left++;
//                        }
//                    }
//                }
//            }
//        }
//        return result;
//    }
//};
