//1�����ַ�������д�������ѭ����������

////���ֲ���
///* [left, right] -> left==right������ */
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
///* [left, right) -> left==right������ */
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


////��������λ��
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
//        //��Ϊ���ұ����䣬���û�е���target��Ԫ�أ���ôright+1���ǵ�һ������target��Ԫ��
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
//        //��Ϊ���ҿ����䣬���û�е���target��Ԫ�أ���ôright���ǵ�һ������target��Ԫ��
//        return right;
//    }
//};


////�����������в���Ԫ�صĵ�һ�������һ��λ��
//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target) {
//        int leftBorder = getLeftBorder(nums, target); //Ѱ��target����߽�
//        int rightBorder = getRightBorder(nums, target); //Ѱ��target���ұ߽�
//        if (leftBorder == -2 || rightBorder == -2) //û���ҵ���߽���ұ߽�
//            return { -1, -1 };
//        else if (rightBorder - leftBorder > 1) //��������ֵ
//            return { leftBorder + 1, rightBorder - 1 };
//        else //��������ֵ
//            return { -1, -1 };
//    }
//    int getLeftBorder(vector<int>& nums, int target) {
//        int left = 0, right = nums.size() - 1;
//        int leftBorder = -2;
//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] >= target) { //��nums[mid]==target��ʱ�����leftBorder���ܵõ���߽�
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
//            if (nums[mid] > target) { //��nums[mid]==target��ʱ�����rightBorder���ܵõ��ұ߽�
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


////x��ƽ����
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


////��Ч����ȫƽ����
//class Solution {
//public:
//    bool isPerfectSquare(int num) {
//        int left = 1, right = num;
//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//            long square = (long)mid * mid; //leetcode��long��long long��Ϊ8�ֽ�
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


//2��˫ָ�뷨

////�Ƴ�Ԫ��
///* ����ָ�� */
//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val) {
//        //��ָ��: Ѱ��ֵ������val��Ԫ��
//        //��ָ��: ָ�����Ԫ�ص�λ��
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
///* ˫��ָ�� -> ȷ���ƶ�����Ԫ�� */
//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val) {
//        int leftIndex = 0, rightIndex = nums.size() - 1;
//        while (leftIndex <= rightIndex) {
//            //leftIndex�������ҵ�һ������val��Ԫ��
//            while (leftIndex <= rightIndex && nums[leftIndex] != val) {
//                leftIndex++;
//            }
//            //rightIndex���ҵ����ҵ�һ��������val��Ԫ��
//            while (leftIndex <= rightIndex && nums[rightIndex] == val) {
//                rightIndex--;
//            }
//            //�ò�����val��Ԫ�������ǵ���val��Ԫ��
//            if (leftIndex <= rightIndex) {
//                nums[leftIndex++] = nums[rightIndex--];
//            }
//        }
//        return leftIndex; //����leftIndexָ�����������ĩβ����һ��Ԫ��
//    }
//};


////ɾ�����������е��ظ���
//class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {
//        int slowIndex = 1, fastIndex = 1; //��0��Ԫ�ز��ò���
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


////�ƶ���
//class Solution {
//public:
//    void moveZeroes(vector<int>& nums) {
//        //��ָ��: Ѱ�Ҳ�Ϊ0��Ԫ��
//        //��ָ��: ָ�����Ԫ�ص�λ��
//        int slowIndex = 0, fastIndex = 0;
//        while (fastIndex < nums.size()) {
//            if (nums[fastIndex] != 0) {
//                nums[slowIndex] = nums[fastIndex];
//                slowIndex++;
//            }
//            fastIndex++;
//        }
//        //����ָ�������Ԫ������Ϊ0
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
//        //leftIndex: ָ�����Ԫ�ص�λ��
//        //rightIndex: Ѱ�Ҳ�Ϊ0��Ԫ��
//        int leftIndex = 0, rightIndex = 0;
//        while (rightIndex < nums.size()) {
//            if (nums[rightIndex] != 0) {
//                swap(nums[leftIndex], nums[rightIndex]); //����Ϊ0��Ԫ���뽻��������Ԫ�ص�λ��
//                leftIndex++;
//            }
//            rightIndex++;
//        }
//    }
//};


////�ȽϺ��˸���ַ���
///* ����ָ�� */
//class Solution {
//public:
//    bool backspaceCompare(string s, string t) {
//        return getString(s) == getString(t);
//    }
//    string getString(string& s) {
//        //��ָ��: �����ַ���
//        //��ָ��: ��¼�������λ��
//        int slowIndex = 0, fastIndex = 0;
//        while (fastIndex < s.size()) {
//            if (s[fastIndex] != '#') { //��ֵ+������
//                s[slowIndex] = s[fastIndex];
//                slowIndex++;
//            }
//            else { //���ǰ��
//                if (slowIndex != 0)
//                    slowIndex--;
//            }
//            fastIndex++;
//        }
//        return s.substr(0, slowIndex); //���ع��֮ǰ���ַ���
//    }
//};
//
///* ˫ָ�� */
//class Solution {
//public:
//    bool backspaceCompare(string s, string t) {
//        int cur1 = s.size() - 1, cur2 = t.size() - 1;
//        while (cur1 >= 0 || cur2 >= 0) {
//            //�Ӻ���ǰ����s���ҵ�һ�����ڵ��ַ�
//            int back1 = 0;
//            while (cur1 >= 0 && (s[cur1] == '#' || back1)) { //��ǰ�ַ���#�򻹿����˸�
//                if (s[cur1] == '#') {
//                    back1++;
//                    cur1--;
//                }
//                else if (back1) {
//                    back1--;
//                    cur1--;
//                }
//            }
//            //�Ӻ���ǰ����t���ҵ�һ�����ڵ��ַ�
//            int back2 = 0;
//            while (cur2 >= 0 && (t[cur2] == '#' || back2)) { //��ǰ�ַ���#�򻹿����˸�
//                if (t[cur2] == '#') {
//                    back2++;
//                    cur2--;
//                }
//                else if (back2) {
//                    back2--;
//                    cur2--;
//                }
//            }
//            if (cur1 >= 0 && cur2 >= 0) { //�����ַ�������
//                if (s[cur1] != t[cur2])
//                    return false;
//                cur1--;
//                cur2--;
//            }
//            else if (cur1 >= 0 || cur2 >= 0) //�����ַ�ֻ��һ������
//                return false;
//        }
//        return true;
//    }
//};


////���������ƽ��
//class Solution {
//public:
//    vector<int> sortedSquares(vector<int>& nums) {
//        //Ѱ�����һ���������±�
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
//        //���м俪ʼ���й鲢����ÿ��ѡ��ƽ����С�ĳ�������ǰ�����
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
//        //�����߿�ʼ���й鲢����ÿ��ѡ��ƽ���ϴ�ĳ������Ӻ���ǰ��
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


//3����������

////������С��������
//class Solution {
//public:
//    int minSubArrayLen(int target, vector<int>& nums) {
//        int result = INT_MAX;
//        int i = 0; //�������ڵ���ʼλ��
//        int sum = 0; //���������ڵ�Ԫ�غ�
//        for (int j = 0; j < nums.size(); j++) { //�������ڵĽ���λ��
//            sum += nums[j];
//            while (sum >= target) {
//                int subLen = j - i + 1;
//                result = min(result, subLen);
//                sum -= nums[i];
//                i++; //�ƶ���߽�
//            }
//        }
//        return result == INT_MAX ? 0 : result;
//    }
//};


////ˮ������
//class Solution {
//public:
//    int totalFruit(vector<int>& fruits) {
//        int result = 0;
//        int n = 0; //����������ˮ��������
//        pair<int, int> a, b; //���������ڵ�����ˮ�������Ӧ�Ľ����±�
//        int i = 0; //�������ڵ���ʼλ��
//        for (int j = 0; j < fruits.size(); j++) { //�������ڵĽ���λ��
//            if (n == 0) {
//                a = { fruits[j], j };
//                n++;
//            }
//            else if (n == 1) {
//                if (fruits[j] == a.first) {
//                    a.second = j; //���¸���ˮ���Ľ����±�
//                }
//                else {
//                    b = { fruits[j], j };
//                    n++;
//                }
//            }
//            else {
//                if (fruits[j] == a.first) {
//                    a.second = j; //���¸���ˮ���Ľ����±�
//                }
//                else if (fruits[j] == b.first) {
//                    b.second = j; //���¸���ˮ���Ľ����±�
//                }
//                else { //������ˮ��
//                    //�������±��С��ˮ���Ƴ�
//                    if (a.second < b.second) {
//                        i = a.second + 1; //����������ʼ�±����
//                        a = { fruits[j], j };
//                    }
//                    else {
//                        i = b.second + 1; //����������ʼ�±����
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
//        unordered_map<int, int> fruitCount; //ͳ�ƻ���������ÿ��ˮ�����ֵĴ���
//        int i = 0; //�������ڵ���ʼλ��
//        for (int j = 0; j < fruits.size(); j++) { //�������ڵĽ���λ��
//            fruitCount[fruits[j]]++; //��Ӧˮ������++
//            while (fruitCount.size() > 2) { //����������ˮ����������2
//                //�����Ƴ���߽��ˮ����ֱ�����������ڵ�ˮ����������Ҫ��
//                auto iter = fruitCount.find(fruits[i]);
//                iter->second--;
//                if (iter->second == 0) {
//                    fruitCount.erase(iter);
//                }
//                i++; //�ƶ���߽�
//            }
//            result = max(result, j - i + 1);
//        }
//        return result;
//    }
//};


////��С�����Ӵ�
//class Solution {
//public:
//    string minWindow(string s, string t) {
//        //ͳ��t�и����ַ����ֵĴ���
//        unordered_map<char, int> charCount;
//        for (const char& ch : t) {
//            charCount[ch]++;
//        }
//        int i = 0; //�������ڵ���ʼλ��
//        int start = 0, len = INT_MAX; //��¼��С���д��ڵ�start��len
//        for (int j = 0; j < s.size(); j++) { //�������ڵĽ���λ��
//            char ch = s[j];
//            if (charCount.count(ch)) { //���ַ���t�г��ֹ�
//                auto iter = charCount.find(ch);
//                iter->second--;
//                //���ϳ������ƻ������ڣ��жϴ����Ƿ����
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
//    //�жϵ�ǰ�����Ƿ����
//    bool judge(unordered_map<char, int>& charCount) {
//        for (const auto& e : charCount) {
//            if (e.second > 0) //���ĳ���ַ����ֵĴ���Ϊ������˵�����ַ���û�б�������
//                return false;
//        }
//        return true;
//    }
//};
//
//class Solution {
//public:
//    string minWindow(string s, string t) {
//        //ͳ��t�и����ַ����ֵĴ���
//        for (const char& ch : t) {
//            charCount[ch]++;
//        }
//        string shortS = handleString(s); //ѹ���ַ���s
//        int start = 0, len = INT_MAX; //��¼��С���д��ڵ�start��len
//        int i = 0; //�������ڵ���ʼλ��
//        for (int j = 0; j < shortS.size(); j++) { //�������ڵĽ���λ��
//            char ch = shortS[j];
//            charCount[ch]--;
//            //���ϳ������ƻ������ڣ��жϴ����Ƿ����
//            while (judge()) {
//                int strLen = indexMap[j] - indexMap[i] + 1; //���������ڵ���ʼ�ͽ����±�ת��Ϊs�е��±�
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
//    //���ַ���s����ѹ����ȥ��t�в����ڵ��ַ���
//    string handleString(string s) {
//        int slowIndex = 0, fastIndex = 0;
//        while (fastIndex < s.size()) {
//            if (charCount.count(s[fastIndex])) { //t�д��ڸ��ַ�
//                s[slowIndex] = s[fastIndex];
//                indexMap[slowIndex] = fastIndex; //����ӳ��
//                slowIndex++;
//            }
//            fastIndex++;
//        }
//        return s.substr(0, slowIndex);
//    }
//    //�жϵ�ǰ�����Ƿ����
//    bool judge() {
//        for (const auto& e : charCount) {
//            if (e.second > 0) //���ĳ���ַ����ִ���Ϊ������˵�����ַ���û�б�������
//                return false;
//        }
//        return true;
//    }
//private:
//    unordered_map<char, int> charCount; //ͳ��t�и����ַ����ֵĴ���
//    unordered_map<int, int> indexMap; //����shortS�и����ַ����±���s�е��±��ӳ��
//};


//4��ģ����Ϊ

////��������II
//class Solution {
//public:
//    vector<vector<int>> generateMatrix(int n) {
//        vector<vector<int>> matrix(n, vector<int>(n));
//        int num = 1;
//        for (int i = 0; i < n / 2; i++) { //��Ҫѭ������Ȧ��
//            //ѭ��������ԭ������ҿ���
//            for (int j = i; j < n - 1 - i; j++) { //�ϱ�->������
//                matrix[i][j] = num++;
//            }
//            for (int j = i; j < n - 1 - i; j++) { //�ұ�->���ϵ���
//                matrix[j][n - 1 - i] = num++;
//            }
//            for (int j = n - 1 - i; j > i; j--) { //�±�->���ҵ���
//                matrix[n - 1 - i][j] = num++;
//            }
//            for (int j = n - 1 - i; j > i; j--) { //���->���µ���
//                matrix[j][i] = num++;
//            }
//        }
//        if (n % 2) { //nΪ���������м������Ҫ������ֵ
//            matrix[n / 2][n / 2] = num;
//        }
//        return matrix;
//    }
//};


////��������
//class Solution {
//public:
//    vector<int> spiralOrder(vector<vector<int>>& matrix) {
//        int m = matrix.size(), n = matrix[0].size();
//        int leftBorder = 0, rightBorder = n - 1; //���ұ߽�
//        int topBorder = 0, bottomBorder = m - 1; //���±߽�
//        vector<int> nums;
//        while (true) {
//            for (int j = leftBorder; j <= rightBorder; j++) { //�ϱ�->������
//                nums.push_back(matrix[topBorder][j]);
//            }
//            if (++topBorder > bottomBorder) //�����ϱ߽�
//                break;
//            for (int i = topBorder; i <= bottomBorder; i++) { //�ұ�->���ϵ���
//                nums.push_back(matrix[i][rightBorder]);
//            }
//            if (--rightBorder < leftBorder) //�����ұ߽�
//                break;
//            for (int j = rightBorder; j >= leftBorder; j--) { //�±�->���ҵ���
//                nums.push_back(matrix[bottomBorder][j]);
//            }
//            if (--bottomBorder < topBorder) //�����±߽�
//                break;
//            for (int i = bottomBorder; i >= topBorder; i--) { //���->���µ���
//                nums.push_back(matrix[i][leftBorder]);
//            }
//            if (++leftBorder > rightBorder) //������߽�
//                break;
//        }
//        return nums;
//    }
//};


////˳ʱ���ӡ����
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

