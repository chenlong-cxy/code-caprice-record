//1、数组

////移除元素
///* 快慢指针（保证元素的相对位置不变） */
//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val) {
//        //快指针: 寻找不等于val的元素
//        //慢指针: 标记下一个不等于val的元素的放入位置
//        int slowPointer = 0, fastPointer = 0;
//        for (fastPointer = 0; fastPointer < nums.size(); fastPointer++) {
//            if (nums[fastPointer] != val) {
//                nums[slowPointer] = nums[fastPointer];
//                slowPointer++;
//            }
//        }
//        return slowPointer;
//    }
//};
//
///* 双向指针（确保移动最少的元素） */
//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val) {
//        int leftPointer = 0, rightPointer = nums.size() - 1;
//        while (leftPointer <= rightPointer) {
//            //leftPointer从左到右找到一个等于val的位置
//            while (leftPointer <= rightPointer && nums[leftPointer] != val) {
//                leftPointer++;
//            }
//            //rightPointer从右到左找到一个不等于val的位置
//            while (leftPointer <= rightPointer && nums[rightPointer] == val) {
//                rightPointer--;
//            }
//            //用不等于val的元素覆盖等于val的元素
//            if (leftPointer < rightPointer) {
//                swap(nums[leftPointer], nums[rightPointer]);
//                leftPointer++;
//                rightPointer--;
//            }
//        }
//        return leftPointer; //最终leftPointer指向新数组末尾的下一个元素
//    }
//};


////删除有序数组中的重复项
///* 快慢指针 */
//class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {
//        int slowPointer = 1, fastPointer = 1; //第0个元素不用操作
//        for (fastPointer = 1; fastPointer < nums.size(); fastPointer++) {
//            if (nums[fastPointer - 1] != nums[fastPointer]) {
//                nums[slowPointer] = nums[fastPointer];
//                slowPointer++;
//            }
//        }
//        return slowPointer;
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
