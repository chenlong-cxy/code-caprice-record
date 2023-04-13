//1、二分查找（两种写法，坚持循环不变量）

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


//在排序数组中查找元素的第一个和最后一个位置
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftBorder = getLeftBorder(nums, target); //找最后一个小于target的位置
        int rightBorder = getRightBorder(nums, target); //找第一个大于target的位置
        if (leftBorder == -2 || rightBorder == -2) //全都小于target或全都大于target
            return vector<int>{-1, -1};
        else if (rightBorder - leftBorder > 1) //保证区间有数据
            return vector<int>{leftBorder + 1, rightBorder - 1};
        else //区间内无数据
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