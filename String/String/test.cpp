////反转字符串
//
///* 双指针+交换 */
//class Solution {
//public:
//    void reverseString(vector<char>& s) {
//        int left = 0, right = s.size() - 1;
//        while (left < right) {
//            swap(s[left], s[right]);
//            left++;
//            right--;
//        }
//    }
//};


////反转字符串II
//
///* 分组+双指针 */
//class Solution {
//public:
//    string reverseStr(string s, int k) {
//        int n = s.size();
//        for (int i = 0; i < n; i += 2 * k) { //以2*k个字符为一组
//            int left = i, right = min(left + k - 1, n - 1); //不够k个则有多少反转多少
//            while (left < right) {
//                swap(s[left], s[right]);
//                left++;
//                right--;
//            }
//        }
//        return s;
//    }
//};


////替换空格
//
//class Solution {
//public:
//    string replaceSpace(string s) {
//        string result;
//        for (int i = 0; i < s.size(); i++) {
//            if (s[i] == ' ') { //替换
//                result += "%20";
//            }
//            else {
//                result += s[i];
//            }
//        }
//        return result;
//    }
//};
//
///* 提前扩容+双指针 */
//class Solution {
//public:
//    string replaceSpace(string s) {
//        int spaceCount = 0; //统计s中空格的个数
//        for (const char& ch : s) {
//            if (ch == ' ')
//                spaceCount++;
//        }
//        int n = s.size();
//        s.resize(n + 2 * spaceCount); //对字符串进行扩容，使其能够容纳替换后的字符串
//        int index = s.size() - 1;
//        for (int i = n - 1; i >= 0; i--) { //从后向前进行替换
//            if (s[i] == ' ') {
//                s[index--] = '0';
//                s[index--] = '2';
//                s[index--] = '%';
//            }
//            else {
//                s[index--] = s[i];
//            }
//        }
//        return s;
//    }
//};


////反转字符串中的单词
//
//class Solution {
//public:
//    string reverseWords(string s) {
//        string result;
//        int end = s.size() - 1;
//        while (end >= 0) { //从后往前找单词
//            while (end >= 0 && s[end] == ' ') { //过滤空格
//                end--;
//            }
//            int start = end;
//            while (start - 1 >= 0 && s[start - 1] != ' ') { //找到当前单词的开头
//                start--;
//            }
//            if (start >= 0) {
//                result += s.substr(start, end - start + 1); //将单词+=到result中
//                result += " "; //单词间的空格
//                end = start - 1;
//            }
//        }
//        result.resize(result.size() - 1); //去除最后一个空格
//        return result;
//    }
//};
//
//
///* 整体反转+局部反转（双指针） */
//class Solution {
//public:
//    string reverseWords(string s) {
//        //移除字符串中的空格
//        int slow = 0;
//        for (int i = 0; i < s.size(); i++) {
//            if (s[i] != ' ') { //过滤掉空格
//                if (slow > 0) { //手动添加各个单词间的空格
//                    s[slow++] = ' ';
//                }
//                while (i < s.size() && s[i] != ' ') { //遍历完当前单词
//                    s[slow++] = s[i++];
//                }
//            }
//        }
//        s.resize(slow); //当前slow指向字符串的下一个位置，及字符串中的字符个数
//        reverseString(s, 0, s.size() - 1); //反转整个字符串
//        int start = 0;
//        for (int i = 0; i <= s.size(); i++) { //反转字符串中的每一个单词
//            if (i == s.size() || s[i] == ' ') { //到达字符串末尾或空字符，则找到一个单词末尾
//                reverseString(s, start, i - 1);
//                start = i + 1; //下一个单词的开始
//            }
//        }
//        return s;
//    }
//    void reverseString(string& s, int start, int end) {
//        while (start < end) {
//            swap(s[start], s[end]);
//            start++;
//            end--;
//        }
//    }
//};


////左旋转字符串
//
//class Solution {
//public:
//    string reverseLeftWords(string s, int n) {
//        string ds = s + s;
//        return ds.substr(n, s.size());
//    }
//};
//
///* 局部反转+整体反转 */
//class Solution {
//public:
//    string reverseLeftWords(string s, int n) {
//        reverse(s.begin(), s.begin() + n);
//        reverse(s.begin() + n, s.end());
//        reverse(s.begin(), s.end());
//        return s;
//    }
//};


////实现strstr函数
//
//class Solution {
//public:
//    int strStr(string haystack, string needle) {
//        int hLen = haystack.size(), nLen = needle.size();
//        if (hLen < nLen)
//            return -1;
//        for (int i = 0; i <= hLen - nLen; i++) {
//            if (haystack[i] == needle[0]) {
//                int hCur = i, nCur = 0;
//                while (hCur < hLen && nCur < nLen && haystack[hCur] == needle[nCur]) {
//                    hCur++;
//                    nCur++;
//                }
//                if (nCur == nLen)
//                    return i;
//            }
//        }
//        return -1;
//    }
//};
//
///* KMP算法: 当出现字符串不匹配时，避免从头再去做匹配 */
//class Solution {
//public:
//    int strStr(string haystack, string needle) {
//        //j: 遍历模式串
//        //i: 遍历文本串
//        int n = needle.size();
//        if (n == 0)
//            return 0;
//        vector<int> next = getNext(needle);
//        int j = 0;
//        for (int i = 0; i < haystack.size(); i++) {
//            while (j > 0 && needle[j] != haystack[i]) { //当前字符不匹配,j向前回退（重新寻找匹配位置）
//                j = next[j - 1];
//            }
//            if (needle[j] == haystack[i]) { //当前字符匹配,j后移
//                j++;
//                if (j == n) //j已经到达模式串末尾,匹配完毕
//                    return i - n + 1;
//            }
//        }
//        return -1;
//    }
//    //根据模式串生成前缀表
//    vector<int> getNext(const string& needle) {
//        //j: 指向前缀末尾位置（前缀的长度）
//        //i: 指向后缀末尾位置
//        int n = needle.size();
//        vector<int> next(n);
//        next[0] = 0; //以第0个字符结尾的字符串的相同前后缀长度为0
//        int j = 0; //前缀末尾位置
//        for (int i = 1; i < n; i++) { //
//            while (j > 0 && needle[j] != needle[i]) { //前后缀末尾不相同,前缀位置向前回退
//                j = next[j - 1]; //j回退到之前的子串的相同前后缀的前缀的下一个位置
//            }
//            if (needle[j] == needle[i]) { //前后缀末尾相同,前缀位置后移
//                j++; //j后移后的数值也是此时前缀的长度
//            }
//            next[i] = j; //以i为结尾的字符串的相同前后缀的长度（也是前缀的下一个位置的下标）
//        }
//        return next;
//    }
//};
////时间复杂度: O(n+m)
////next前缀表: 用来回退的,它记录了模式串与文本串不匹配的时候,模式串应该从哪里开始重新匹配
////next前缀表: 统计了以各个位置为终点的字符串的最长相同前后缀的长度


////重复的子字符串
//
///* 拼接+查找 */
//class Solution {
//public:
//    bool repeatedSubstringPattern(string s) {
//        string t = s + s;
//        t.erase(t.begin());
//        t.erase(t.end() - 1);
//        if (t.find(s) != string::npos)
//            return true;
//        return false;
//    }
//};
//
///* KMP算法: 最小重复子串长度 = 字符串长度 - 最长相同前后缀长度 */
//class Solution {
//public:
//    bool repeatedSubstringPattern(string s) {
//        int len = s.size();
//        vector<int> next = getNext(s);
//        if (next[len - 1] != 0 && len % (len - next[len - 1]) == 0) {
//            return true;
//        }
//        return false;
//    }
//    vector<int> getNext(const string& s) {
//        vector<int> next(s.size());
//        next[0] = 0;
//        int j = 0;
//        for (int i = 1; i < s.size(); i++) {
//            while (j > 0 && s[j] != s[i]) {
//                j = next[j - 1];
//            }
//            if (s[j] == s[i]) {
//                j++;
//            }
//            next[i] = j;
//        }
//        return next;
//    }
//};
////next[n - 1]: 最长相同前后缀的长度
////len - next[n - 1]: 最小重复子串的长度
///*
//         字符串s: a b a b a b a b
//     字符串s下标: 0 1 2 3 4 5 6 7
//最长相等前缀t下标: 0 1 2 3 4 5
//最长相等后缀k下标:     0 1 2 3 4 5
//
//  t[0]=k[0],t[1]=k[1]
//  t[0]=s[0],t[1]=s[1]
//  k[0]=s[2],k[1]=s[3]
//->s[0]=s[2],s[1]=s[3]
//以此类推
//->s[2]=s[4],s[3]=s[5]
//->s[4]=s[6],s[5]=s[7]
//所以字符串长度减去最长相同前后缀的长度即为最小重复子串的长度
//如果得到的不是最小重复子串，那么使用的也一定不是最长相同前后缀的长度，此时前后缀长度还可以更长
//*/
