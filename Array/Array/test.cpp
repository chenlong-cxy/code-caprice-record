//1�����ֲ��ң�����д�������ѭ����������

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


//�����������в���Ԫ�صĵ�һ�������һ��λ��
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftBorder = getLeftBorder(nums, target); //�����һ��С��target��λ��
        int rightBorder = getRightBorder(nums, target); //�ҵ�һ������target��λ��
        if (leftBorder == -2 || rightBorder == -2) //ȫ��С��target��ȫ������target
            return vector<int>{-1, -1};
        else if (rightBorder - leftBorder > 1) //��֤����������
            return vector<int>{leftBorder + 1, rightBorder - 1};
        else //������������
            return vector<int>{-1, -1};
    }
    int getLeftBorder(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int leftBorder = -2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
                leftBorder = right;
            }
            else {
                left = mid + 1;
            }
        }
        return leftBorder;
    }
    int getRightBorder(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int rightBorder = -2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }
};