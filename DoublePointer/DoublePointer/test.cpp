//1������

////�Ƴ�Ԫ��
///* ����ָ�루��֤Ԫ�ص����λ�ò��䣩 */
//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val) {
//        //��ָ��: Ѱ�Ҳ�����val��Ԫ��
//        //��ָ��: �����һ��������val��Ԫ�صķ���λ��
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
///* ˫��ָ�루ȷ���ƶ����ٵ�Ԫ�أ� */
//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val) {
//        int leftPointer = 0, rightPointer = nums.size() - 1;
//        while (leftPointer <= rightPointer) {
//            //leftPointer�������ҵ�һ������val��λ��
//            while (leftPointer <= rightPointer && nums[leftPointer] != val) {
//                leftPointer++;
//            }
//            //rightPointer���ҵ����ҵ�һ��������val��λ��
//            while (leftPointer <= rightPointer && nums[rightPointer] == val) {
//                rightPointer--;
//            }
//            //�ò�����val��Ԫ�ظ��ǵ���val��Ԫ��
//            if (leftPointer < rightPointer) {
//                swap(nums[leftPointer], nums[rightPointer]);
//                leftPointer++;
//                rightPointer--;
//            }
//        }
//        return leftPointer; //����leftPointerָ��������ĩβ����һ��Ԫ��
//    }
//};


////ɾ�����������е��ظ���
///* ����ָ�� */
//class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {
//        int slowPointer = 1, fastPointer = 1; //��0��Ԫ�ز��ò���
//        for (fastPointer = 1; fastPointer < nums.size(); fastPointer++) {
//            if (nums[fastPointer - 1] != nums[fastPointer]) {
//                nums[slowPointer] = nums[fastPointer];
//                slowPointer++;
//            }
//        }
//        return slowPointer;
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
