////��ת�ַ���
//
///* ˫ָ��+���� */
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


////��ת�ַ���II
//
///* ����+˫ָ�� */
//class Solution {
//public:
//    string reverseStr(string s, int k) {
//        int n = s.size();
//        for (int i = 0; i < n; i += 2 * k) { //��2*k���ַ�Ϊһ��
//            int left = i, right = min(left + k - 1, n - 1); //����k�����ж��ٷ�ת����
//            while (left < right) {
//                swap(s[left], s[right]);
//                left++;
//                right--;
//            }
//        }
//        return s;
//    }
//};


////�滻�ո�
//
//class Solution {
//public:
//    string replaceSpace(string s) {
//        string result;
//        for (int i = 0; i < s.size(); i++) {
//            if (s[i] == ' ') { //�滻
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
///* ��ǰ����+˫ָ�� */
//class Solution {
//public:
//    string replaceSpace(string s) {
//        int spaceCount = 0; //ͳ��s�пո�ĸ���
//        for (const char& ch : s) {
//            if (ch == ' ')
//                spaceCount++;
//        }
//        int n = s.size();
//        s.resize(n + 2 * spaceCount); //���ַ����������ݣ�ʹ���ܹ������滻����ַ���
//        int index = s.size() - 1;
//        for (int i = n - 1; i >= 0; i--) { //�Ӻ���ǰ�����滻
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


////��ת�ַ����еĵ���
//
//class Solution {
//public:
//    string reverseWords(string s) {
//        string result;
//        int end = s.size() - 1;
//        while (end >= 0) { //�Ӻ���ǰ�ҵ���
//            while (end >= 0 && s[end] == ' ') { //���˿ո�
//                end--;
//            }
//            int start = end;
//            while (start - 1 >= 0 && s[start - 1] != ' ') { //�ҵ���ǰ���ʵĿ�ͷ
//                start--;
//            }
//            if (start >= 0) {
//                result += s.substr(start, end - start + 1); //������+=��result��
//                result += " "; //���ʼ�Ŀո�
//                end = start - 1;
//            }
//        }
//        result.resize(result.size() - 1); //ȥ�����һ���ո�
//        return result;
//    }
//};
//
//
///* ���巴ת+�ֲ���ת��˫ָ�룩 */
//class Solution {
//public:
//    string reverseWords(string s) {
//        //�Ƴ��ַ����еĿո�
//        int slow = 0;
//        for (int i = 0; i < s.size(); i++) {
//            if (s[i] != ' ') { //���˵��ո�
//                if (slow > 0) { //�ֶ���Ӹ������ʼ�Ŀո�
//                    s[slow++] = ' ';
//                }
//                while (i < s.size() && s[i] != ' ') { //�����굱ǰ����
//                    s[slow++] = s[i++];
//                }
//            }
//        }
//        s.resize(slow); //��ǰslowָ���ַ�������һ��λ�ã����ַ����е��ַ�����
//        reverseString(s, 0, s.size() - 1); //��ת�����ַ���
//        int start = 0;
//        for (int i = 0; i <= s.size(); i++) { //��ת�ַ����е�ÿһ������
//            if (i == s.size() || s[i] == ' ') { //�����ַ���ĩβ����ַ������ҵ�һ������ĩβ
//                reverseString(s, start, i - 1);
//                start = i + 1; //��һ�����ʵĿ�ʼ
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


////����ת�ַ���
//
//class Solution {
//public:
//    string reverseLeftWords(string s, int n) {
//        string ds = s + s;
//        return ds.substr(n, s.size());
//    }
//};
//
///* �ֲ���ת+���巴ת */
//class Solution {
//public:
//    string reverseLeftWords(string s, int n) {
//        reverse(s.begin(), s.begin() + n);
//        reverse(s.begin() + n, s.end());
//        reverse(s.begin(), s.end());
//        return s;
//    }
//};


////ʵ��strstr����
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
///* KMP�㷨: �������ַ�����ƥ��ʱ�������ͷ��ȥ��ƥ�� */
//class Solution {
//public:
//    int strStr(string haystack, string needle) {
//        //j: ����ģʽ��
//        //i: �����ı���
//        int n = needle.size();
//        if (n == 0)
//            return 0;
//        vector<int> next = getNext(needle);
//        int j = 0;
//        for (int i = 0; i < haystack.size(); i++) {
//            while (j > 0 && needle[j] != haystack[i]) { //��ǰ�ַ���ƥ��,j��ǰ���ˣ�����Ѱ��ƥ��λ�ã�
//                j = next[j - 1];
//            }
//            if (needle[j] == haystack[i]) { //��ǰ�ַ�ƥ��,j����
//                j++;
//                if (j == n) //j�Ѿ�����ģʽ��ĩβ,ƥ�����
//                    return i - n + 1;
//            }
//        }
//        return -1;
//    }
//    //����ģʽ������ǰ׺��
//    vector<int> getNext(const string& needle) {
//        //j: ָ��ǰ׺ĩβλ�ã�ǰ׺�ĳ��ȣ�
//        //i: ָ���׺ĩβλ��
//        int n = needle.size();
//        vector<int> next(n);
//        next[0] = 0; //�Ե�0���ַ���β���ַ�������ͬǰ��׺����Ϊ0
//        int j = 0; //ǰ׺ĩβλ��
//        for (int i = 1; i < n; i++) { //
//            while (j > 0 && needle[j] != needle[i]) { //ǰ��׺ĩβ����ͬ,ǰ׺λ����ǰ����
//                j = next[j - 1]; //j���˵�֮ǰ���Ӵ�����ͬǰ��׺��ǰ׺����һ��λ��
//            }
//            if (needle[j] == needle[i]) { //ǰ��׺ĩβ��ͬ,ǰ׺λ�ú���
//                j++; //j���ƺ����ֵҲ�Ǵ�ʱǰ׺�ĳ���
//            }
//            next[i] = j; //��iΪ��β���ַ�������ͬǰ��׺�ĳ��ȣ�Ҳ��ǰ׺����һ��λ�õ��±꣩
//        }
//        return next;
//    }
//};
////ʱ�临�Ӷ�: O(n+m)
////nextǰ׺��: �������˵�,����¼��ģʽ�����ı�����ƥ���ʱ��,ģʽ��Ӧ�ô����￪ʼ����ƥ��
////nextǰ׺��: ͳ�����Ը���λ��Ϊ�յ���ַ��������ͬǰ��׺�ĳ���


////�ظ������ַ���
//
///* ƴ��+���� */
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
///* KMP�㷨: ��С�ظ��Ӵ����� = �ַ������� - ���ͬǰ��׺���� */
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
////next[n - 1]: ���ͬǰ��׺�ĳ���
////len - next[n - 1]: ��С�ظ��Ӵ��ĳ���
///*
//         �ַ���s: a b a b a b a b
//     �ַ���s�±�: 0 1 2 3 4 5 6 7
//����ǰ׺t�±�: 0 1 2 3 4 5
//���Ⱥ�׺k�±�:     0 1 2 3 4 5
//
//  t[0]=k[0],t[1]=k[1]
//  t[0]=s[0],t[1]=s[1]
//  k[0]=s[2],k[1]=s[3]
//->s[0]=s[2],s[1]=s[3]
//�Դ�����
//->s[2]=s[4],s[3]=s[5]
//->s[4]=s[6],s[5]=s[7]
//�����ַ������ȼ�ȥ���ͬǰ��׺�ĳ��ȼ�Ϊ��С�ظ��Ӵ��ĳ���
//����õ��Ĳ�����С�ظ��Ӵ�����ôʹ�õ�Ҳһ���������ͬǰ��׺�ĳ��ȣ���ʱǰ��׺���Ȼ����Ը���
//*/
