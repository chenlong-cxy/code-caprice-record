//1、二分法（两种写法，坚持循环不变量）

////二分查找
///* [left, right] -> left==right有意义 */
//class Solution {
//public:
//    int search(vector<int>& nums, int target) {
//        int left = 0, right = nums.size() - 1;
//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] > target) {
//                right = mid - 1;
//            }
//            else if (nums[mid] < target) {
//                left = mid + 1;
//            }
//            else {
//                return mid;
//            }
//        }
//        return -1;
//    }
//};
//
///* [left, right) -> left==right无意义 */
//class Solution {
//public:
//    int search(vector<int>& nums, int target) {
//        int left = 0, right = nums.size();
//        while (left < right) {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] > target) {
//                right = mid;
//            }
//            else if (nums[mid] < target) {
//                left = mid + 1;
//            }
//            else {
//                return mid;
//            }
//        }
//        return -1;
//    }
//};


////搜索插入位置
//class Solution {
//public:
//    int searchInsert(vector<int>& nums, int target) {
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] >= target)
//                return i;
//        }
//        return nums.size();
//    }
//};
//
//class Solution {
//public:
//    int searchInsert(vector<int>& nums, int target) {
//        int left = 0, right = nums.size() - 1;
//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] > target) {
//                right = mid - 1;
//            }
//            else if (nums[mid] < target) {
//                left = mid + 1;
//            }
//            else {
//                return mid;
//            }
//        }
//        //因为是右闭区间，如果没有等于target的元素，那么right+1便是第一个大于target的元素
//        return right + 1;
//    }
//};
//
//class Solution {
//public:
//    int searchInsert(vector<int>& nums, int target) {
//        int left = 0, right = nums.size();
//        while (left < right) {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] > target) {
//                right = mid;
//            }
//            else if (nums[mid] < target) {
//                left = mid + 1;
//            }
//            else {
//                return mid;
//            }
//        }
//        //因为是右开区间，如果没有等于target的元素，那么right便是第一个大于target的元素
//        return right;
//    }
//};


////在排序数组中查找元素的第一个和最后一个位置
//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target) {
//        int leftBorder = getLeftBorder(nums, target); //寻找target的左边界
//        int rightBorder = getRightBorder(nums, target); //寻找target的右边界
//        if (leftBorder == -2 || rightBorder == -2) //没有找到左边界或右边界
//            return { -1, -1 };
//        else if (rightBorder - leftBorder > 1) //区间内有值
//            return { leftBorder + 1, rightBorder - 1 };
//        else //区间内无值
//            return { -1, -1 };
//    }
//    int getLeftBorder(vector<int>& nums, int target) {
//        int left = 0, right = nums.size() - 1;
//        int leftBorder = -2;
//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] >= target) { //当nums[mid]==target的时候更新leftBorder才能得到左边界
//                right = mid - 1;
//                leftBorder = right;
//            }
//            else {
//                left = mid + 1;
//            }
//        }
//        return leftBorder;
//    }
//    int getRightBorder(vector<int>& nums, int target) {
//        int left = 0, right = nums.size() - 1;
//        int rightBorder = -2;
//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] > target) { //当nums[mid]==target的时候更新rightBorder才能得到右边界
//                right = mid - 1;
//            }
//            else {
//                left = mid + 1;
//                rightBorder = left;
//            }
//        }
//        return rightBorder;
//    }
//};


////x的平方根
//class Solution {
//public:
//    int mySqrt(int x) {
//        int left = 0, right = x;
//        int ans = 1;
//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//            if ((long long)mid * mid > x) {
//                right = mid - 1;
//            }
//            else {
//                left = mid + 1;
//                ans = mid;
//            }
//        }
//        return ans;
//    }
//};


////有效的完全平方数
//class Solution {
//public:
//    bool isPerfectSquare(int num) {
//        int left = 1, right = num;
//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//            long square = (long)mid * mid; //leetcode中long和long long均为8字节
//            if (square > num) {
//                right = mid - 1;
//            }
//            else if (square < num) {
//                left = mid + 1;
//            }
//            else {
//                return true;
//            }
//        }
//        return false;
//    }
//};


//2、双指针法

////移除元素
///* 快慢指针 */
//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val) {
//        //快指针: 寻找值不等于val的元素
//        //慢指针: 指向插入元素的位置
//        int slowIndex = 0, fastIndex = 0;
//        while (fastIndex < nums.size()) {
//            if (nums[fastIndex] != val) {
//                nums[slowIndex] = nums[fastIndex];
//                slowIndex++;
//            }
//            fastIndex++;
//        }
//        return slowIndex;
//    }
//};
//
///* 双向指针 -> 确保移动最少元素 */
//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val) {
//        int leftIndex = 0, rightIndex = nums.size() - 1;
//        while (leftIndex <= rightIndex) {
//            //leftIndex从左到右找到一个等于val的元素
//            while (leftIndex <= rightIndex && nums[leftIndex] != val) {
//                leftIndex++;
//            }
//            //rightIndex从右到左找到一个不等于val的元素
//            while (leftIndex <= rightIndex && nums[rightIndex] == val) {
//                rightIndex--;
//            }
//            //用不等于val的元素来覆盖等于val的元素
//            if (leftIndex <= rightIndex) {
//                nums[leftIndex++] = nums[rightIndex--];
//            }
//        }
//        return leftIndex; //最终leftIndex指向的是新数组末尾的下一个元素
//    }
//};


////删除有序数组中的重复项
//class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {
//        int slowIndex = 1, fastIndex = 1; //第0个元素不用操作
//        while (fastIndex < nums.size()) {
//            if (nums[fastIndex] != nums[fastIndex - 1]) {
//                nums[slowIndex] = nums[fastIndex];
//                slowIndex++;
//            }
//            fastIndex++;
//        }
//        return slowIndex;
//    }
//};


////移动零
//class Solution {
//public:
//    void moveZeroes(vector<int>& nums) {
//        //快指针: 寻找不为0的元素
//        //慢指针: 指向插入元素的位置
//        int slowIndex = 0, fastIndex = 0;
//        while (fastIndex < nums.size()) {
//            if (nums[fastIndex] != 0) {
//                nums[slowIndex] = nums[fastIndex];
//                slowIndex++;
//            }
//            fastIndex++;
//        }
//        //将慢指针后续的元素设置为0
//        while (slowIndex < nums.size()) {
//            nums[slowIndex] = 0;
//            slowIndex++;
//        }
//    }
//};
//
//class Solution {
//public:
//    void moveZeroes(vector<int>& nums) {
//        //leftIndex: 指向插入元素的位置
//        //rightIndex: 寻找不为0的元素
//        int leftIndex = 0, rightIndex = 0;
//        while (rightIndex < nums.size()) {
//            if (nums[rightIndex] != 0) {
//                swap(nums[leftIndex], nums[rightIndex]); //将不为0的元素与交换到插入元素的位置
//                leftIndex++;
//            }
//            rightIndex++;
//        }
//    }
//};


////比较含退格的字符串
///* 快慢指针 */
//class Solution {
//public:
//    bool backspaceCompare(string s, string t) {
//        return getString(s) == getString(t);
//    }
//    string getString(string& s) {
//        //快指针: 变量字符串
//        //慢指针: 记录光标所在位置
//        int slowIndex = 0, fastIndex = 0;
//        while (fastIndex < s.size()) {
//            if (s[fastIndex] != '#') { //赋值+光标后移
//                s[slowIndex] = s[fastIndex];
//                slowIndex++;
//            }
//            else { //光标前移
//                if (slowIndex != 0)
//                    slowIndex--;
//            }
//            fastIndex++;
//        }
//        return s.substr(0, slowIndex); //返回光标之前的字符串
//    }
//};
//
///* 双指针 */
//class Solution {
//public:
//    bool backspaceCompare(string s, string t) {
//        int cur1 = s.size() - 1, cur2 = t.size() - 1;
//        while (cur1 >= 0 || cur2 >= 0) {
//            //从后向前，在s中找到一个存在的字符
//            int back1 = 0;
//            while (cur1 >= 0 && (s[cur1] == '#' || back1)) { //当前字符是#或还可以退格
//                if (s[cur1] == '#') {
//                    back1++;
//                    cur1--;
//                }
//                else if (back1) {
//                    back1--;
//                    cur1--;
//                }
//            }
//            //从后向前，在t中找到一个存在的字符
//            int back2 = 0;
//            while (cur2 >= 0 && (t[cur2] == '#' || back2)) { //当前字符是#或还可以退格
//                if (t[cur2] == '#') {
//                    back2++;
//                    cur2--;
//                }
//                else if (back2) {
//                    back2--;
//                    cur2--;
//                }
//            }
//            if (cur1 >= 0 && cur2 >= 0) { //两个字符都存在
//                if (s[cur1] != t[cur2])
//                    return false;
//                cur1--;
//                cur2--;
//            }
//            else if (cur1 >= 0 || cur2 >= 0) //两个字符只有一个存在
//                return false;
//        }
//        return true;
//    }
//};


////有序数组的平方
//class Solution {
//public:
//    vector<int> sortedSquares(vector<int>& nums) {
//        //寻找最后一个负数的下标
//        int neg = -1;
//        int left = 0, right = nums.size() - 1;
//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] >= 0) {
//                right = mid - 1;
//            }
//            else {
//                left = mid + 1;
//                neg = mid;
//            }
//        }
//        //从中间开始进行归并排序，每次选出平方较小的出来，从前往后放
//        vector<int> ans;
//        int ptr1 = neg, ptr2 = neg + 1;
//        while (ptr1 >= 0 || ptr2 < nums.size()) {
//            if (ptr1 < 0) {
//                ans.push_back(nums[ptr2] * nums[ptr2]);
//                ptr2++;
//            }
//            else if (ptr2 == nums.size()) {
//                ans.push_back(nums[ptr1] * nums[ptr1]);
//                ptr1--;
//            }
//            else if (nums[ptr1] * nums[ptr1] < nums[ptr2] * nums[ptr2]) {
//                ans.push_back(nums[ptr1] * nums[ptr1]);
//                ptr1--;
//            }
//            else {
//                ans.push_back(nums[ptr2] * nums[ptr2]);
//                ptr2++;
//            }
//        }
//        return ans;
//    }
//};
//
//class Solution {
//public:
//    vector<int> sortedSquares(vector<int>& nums) {
//        //从两边开始进行归并排序，每次选出平方较大的出来，从后往前放
//        int n = nums.size();
//        vector<int> ans(n);
//        int left = 0, right = n - 1;
//        int pos = n - 1;
//        while (left <= right) {
//            int num1 = abs(nums[left]), num2 = abs(nums[right]);
//            if (num1 > num2) {
//                ans[pos] = num1 * num1;
//                left++;
//            }
//            else {
//                ans[pos] = num2 * num2;
//                right--;
//            }
//            pos--;
//        }
//        return ans;
//    }
//};


//3、滑动窗口

////长度最小的子数组
//class Solution {
//public:
//    int minSubArrayLen(int target, vector<int>& nums) {
//        int result = INT_MAX;
//        int i = 0; //滑动窗口的起始位置
//        int sum = 0; //滑动窗口内的元素和
//        for (int j = 0; j < nums.size(); j++) { //滑动窗口的结束位置
//            sum += nums[j];
//            while (sum >= target) {
//                int subLen = j - i + 1;
//                result = min(result, subLen);
//                sum -= nums[i];
//                i++; //移动左边界
//            }
//        }
//        return result == INT_MAX ? 0 : result;
//    }
//};


////水果成蓝
//class Solution {
//public:
//    int totalFruit(vector<int>& fruits) {
//        int result = 0;
//        int n = 0; //滑动窗口内水果的种数
//        pair<int, int> a, b; //滑动窗口内的两类水果及其对应的结束下标
//        int i = 0; //滑动窗口的起始位置
//        for (int j = 0; j < fruits.size(); j++) { //滑动窗口的结束位置
//            if (n == 0) {
//                a = { fruits[j], j };
//                n++;
//            }
//            else if (n == 1) {
//                if (fruits[j] == a.first) {
//                    a.second = j; //更新该类水果的结束下标
//                }
//                else {
//                    b = { fruits[j], j };
//                    n++;
//                }
//            }
//            else {
//                if (fruits[j] == a.first) {
//                    a.second = j; //更新该类水果的结束下标
//                }
//                else if (fruits[j] == b.first) {
//                    b.second = j; //更新该类水果的结束下标
//                }
//                else { //新种类水果
//                    //将结束下标较小的水果移除
//                    if (a.second < b.second) {
//                        i = a.second + 1; //滑动窗口起始下标更新
//                        a = { fruits[j], j };
//                    }
//                    else {
//                        i = b.second + 1; //滑动窗口起始下标更新
//                        b = { fruits[j], j };
//                    }
//                }
//            }
//            result = max(result, j - i + 1);
//        }
//        return result;
//    }
//};
//
//class Solution {
//public:
//    int totalFruit(vector<int>& fruits) {
//        int result = 0;
//        unordered_map<int, int> fruitCount; //统计滑动窗口中每种水果出现的次数
//        int i = 0; //滑动窗口的起始位置
//        for (int j = 0; j < fruits.size(); j++) { //滑动窗口的结束位置
//            fruitCount[fruits[j]]++; //对应水果计数++
//            while (fruitCount.size() > 2) { //滑动窗口内水果种数超过2
//                //不断移除左边界的水果，直到滑动窗口内的水果种数符合要求
//                auto iter = fruitCount.find(fruits[i]);
//                iter->second--;
//                if (iter->second == 0) {
//                    fruitCount.erase(iter);
//                }
//                i++; //移动左边界
//            }
//            result = max(result, j - i + 1);
//        }
//        return result;
//    }
//};


////最小覆盖子串
//class Solution {
//public:
//    string minWindow(string s, string t) {
//        //统计t中各个字符出现的次数
//        unordered_map<char, int> charCount;
//        for (const char& ch : t) {
//            charCount[ch]++;
//        }
//        int i = 0; //滑动窗口的起始位置
//        int start = 0, len = INT_MAX; //记录最小可行窗口的start和len
//        for (int j = 0; j < s.size(); j++) { //滑动窗口的结束位置
//            char ch = s[j];
//            if (charCount.count(ch)) { //该字符在t中出现过
//                auto iter = charCount.find(ch);
//                iter->second--;
//                //不断尝试左移滑动窗口，判断窗口是否可行
//                while (judge(charCount)) {
//                    if (j - i + 1 < len) {
//                        start = i;
//                        len = j - i + 1;
//                    }
//                    if (charCount.count(s[i])) {
//                        charCount[s[i]]++;
//                    }
//                    i++;
//                }
//            }
//        }
//        return len == INT_MAX ? "" : s.substr(start, len);
//    }
//    //判断当前窗口是否可行
//    bool judge(unordered_map<char, int>& charCount) {
//        for (const auto& e : charCount) {
//            if (e.second > 0) //如果某个字符出现的次数为正，则说明该字符还没有被抵消完
//                return false;
//        }
//        return true;
//    }
//};
//
//class Solution {
//public:
//    string minWindow(string s, string t) {
//        //统计t中各个字符出现的次数
//        for (const char& ch : t) {
//            charCount[ch]++;
//        }
//        string shortS = handleString(s); //压缩字符串s
//        int start = 0, len = INT_MAX; //记录最小可行窗口的start和len
//        int i = 0; //滑动窗口的起始位置
//        for (int j = 0; j < shortS.size(); j++) { //滑动窗口的结束位置
//            char ch = shortS[j];
//            charCount[ch]--;
//            //不断尝试左移滑动窗口，判断窗口是否可行
//            while (judge()) {
//                int strLen = indexMap[j] - indexMap[i] + 1; //将滑动窗口的起始和结束下标转换为s中的下标
//                if (strLen < len) {
//                    start = indexMap[i];
//                    len = strLen;
//                }
//                charCount[shortS[i]]++;
//                i++;
//            }
//        }
//        return len == INT_MAX ? "" : s.substr(start, len);
//    }
//    //将字符串s进行压缩（去掉t中不存在的字符）
//    string handleString(string s) {
//        int slowIndex = 0, fastIndex = 0;
//        while (fastIndex < s.size()) {
//            if (charCount.count(s[fastIndex])) { //t中存在该字符
//                s[slowIndex] = s[fastIndex];
//                indexMap[slowIndex] = fastIndex; //建立映射
//                slowIndex++;
//            }
//            fastIndex++;
//        }
//        return s.substr(0, slowIndex);
//    }
//    //判断当前窗口是否可行
//    bool judge() {
//        for (const auto& e : charCount) {
//            if (e.second > 0) //如果某个字符出现次数为正，则说明该字符还没有被抵消完
//                return false;
//        }
//        return true;
//    }
//private:
//    unordered_map<char, int> charCount; //统计t中各个字符出现的次数
//    unordered_map<int, int> indexMap; //建立shortS中各个字符的下标与s中的下标的映射
//};


//4、模拟行为

////螺旋矩阵II
//class Solution {
//public:
//    vector<vector<int>> generateMatrix(int n) {
//        vector<vector<int>> matrix(n, vector<int>(n));
//        int num = 1;
//        for (int i = 0; i < n / 2; i++) { //需要循环填充的圈数
//            //循环不变量原则（左闭右开）
//            for (int j = i; j < n - 1 - i; j++) { //上边->从左到右
//                matrix[i][j] = num++;
//            }
//            for (int j = i; j < n - 1 - i; j++) { //右边->从上到下
//                matrix[j][n - 1 - i] = num++;
//            }
//            for (int j = n - 1 - i; j > i; j--) { //下边->从右到左
//                matrix[n - 1 - i][j] = num++;
//            }
//            for (int j = n - 1 - i; j > i; j--) { //左边->从下到上
//                matrix[j][i] = num++;
//            }
//        }
//        if (n % 2) { //n为奇数，最中间的数需要单独赋值
//            matrix[n / 2][n / 2] = num;
//        }
//        return matrix;
//    }
//};


////螺旋数组
//class Solution {
//public:
//    vector<int> spiralOrder(vector<vector<int>>& matrix) {
//        int m = matrix.size(), n = matrix[0].size();
//        int leftBorder = 0, rightBorder = n - 1; //左右边界
//        int topBorder = 0, bottomBorder = m - 1; //上下边界
//        vector<int> nums;
//        while (true) {
//            for (int j = leftBorder; j <= rightBorder; j++) { //上边->从左到右
//                nums.push_back(matrix[topBorder][j]);
//            }
//            if (++topBorder > bottomBorder) //更新上边界
//                break;
//            for (int i = topBorder; i <= bottomBorder; i++) { //右边->从上到下
//                nums.push_back(matrix[i][rightBorder]);
//            }
//            if (--rightBorder < leftBorder) //更新右边界
//                break;
//            for (int j = rightBorder; j >= leftBorder; j--) { //下边->从右到左
//                nums.push_back(matrix[bottomBorder][j]);
//            }
//            if (--bottomBorder < topBorder) //更新下边界
//                break;
//            for (int i = bottomBorder; i >= topBorder; i--) { //左边->从下到上
//                nums.push_back(matrix[i][leftBorder]);
//            }
//            if (++leftBorder > rightBorder) //更新左边界
//                break;
//        }
//        return nums;
//    }
//};


////顺时针打印矩阵
//class Solution {
//public:
//    vector<int> spiralOrder(vector<vector<int>>& matrix) {
//        if (matrix.size() == 0)
//            return vector<int>();
//        int m = matrix.size(), n = matrix[0].size();
//        int leftBorder = 0, rightBorder = n - 1;
//        int topBorder = 0, bottomBorder = m - 1;
//        vector<int> nums;
//        while (true) {
//            for (int j = leftBorder; j <= rightBorder; j++) {
//                nums.push_back(matrix[topBorder][j]);
//            }
//            if (++topBorder > bottomBorder)
//                break;
//            for (int i = topBorder; i <= bottomBorder; i++) {
//                nums.push_back(matrix[i][rightBorder]);
//            }
//            if (--rightBorder < leftBorder)
//                break;
//            for (int j = rightBorder; j >= leftBorder; j--) {
//                nums.push_back(matrix[bottomBorder][j]);
//            }
//            if (--bottomBorder < topBorder)
//                break;
//            for (int i = bottomBorder; i >= topBorder; i--) {
//                nums.push_back(matrix[i][leftBorder]);
//            }
//            if (++leftBorder > rightBorder)
//                break;
//        }
//        return nums;
//    }
//};

