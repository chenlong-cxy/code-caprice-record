////1���Ƴ�����Ԫ��
//
///* ����������ͷ��� */
//class Solution {
//public:
//    ListNode* removeElements(ListNode* head, int val) {
//        while (head != nullptr && head->val == val) {
//            ListNode* tmp = head;
//            head = head->next;
//            delete tmp;
//        }
//        ListNode* cur = head;
//        while (cur != nullptr && cur->next != nullptr) {
//            if (cur->next->val == val) {
//                ListNode* tmp = cur->next;
//                cur->next = cur->next->next;
//                delete tmp;
//            }
//            else {
//                cur = cur->next;
//            }
//        }
//        return head;
//    }
//};
//
///* ��������ͷ��� */
//class Solution {
//public:
//    ListNode* removeElements(ListNode* head, int val) {
//        ListNode* dummyHead = new ListNode(0); //����ͷ���
//        dummyHead->next = head;
//        ListNode* cur = dummyHead;
//        while (cur->next != nullptr) {
//            if (cur->next->val == val) {
//                ListNode* tmp = cur->next;
//                cur->next = cur->next->next;
//                delete tmp;
//            }
//            else {
//                cur = cur->next;
//            }
//        }
//        head = dummyHead->next;
//        delete dummyHead;
//        return head;
//    }
//};


////2���������
//
//class MyLinkedList {
//    struct LinkedNode {
//        int val;
//        LinkedNode* next;
//        LinkedNode(int x) :val(x), next(nullptr) {}
//    };
//public:
//    MyLinkedList() {
//        dummyHead = new LinkedNode(0); //����ͷ���
//        size = 0; //�����еĽ�����
//    }
//
//    int get(int index) {
//        if (index < 0 || index >= size) {
//            return -1;
//        }
//        LinkedNode* cur = dummyHead->next; //Ѱ��Ŀ����
//        while (index--) {
//            cur = cur->next;
//        }
//        return cur->val;
//    }
//
//    void addAtHead(int val) {
//        LinkedNode* newNode = new LinkedNode(val);
//        newNode->next = dummyHead->next;
//        dummyHead->next = newNode;
//        size++;
//    }
//
//    void addAtTail(int val) {
//        LinkedNode* newNode = new LinkedNode(val);
//        LinkedNode* cur = dummyHead; //Ѱ�����һ�����
//        while (cur->next != nullptr) {
//            cur = cur->next;
//        }
//        cur->next = newNode;
//        size++;
//    }
//
//    void addAtIndex(int index, int val) {
//        if (index < 0 || index > size) {
//            return;
//        }
//        LinkedNode* newNode = new LinkedNode(val);
//        LinkedNode* cur = dummyHead; //Ѱ���±�Ϊindex�Ľ���ǰһ�����
//        while (index--) {
//            cur = cur->next;
//        }
//        newNode->next = cur->next;
//        cur->next = newNode;
//        size++;
//    }
//
//    void deleteAtIndex(int index) {
//        if (index < 0 || index >= size) {
//            return;
//        }
//        LinkedNode* cur = dummyHead; //Ѱ��ɾ������ǰһ�����
//        while (index--) {
//            cur = cur->next;
//        }
//        LinkedNode* tmp = cur->next;
//        cur->next = cur->next->next;
//        delete tmp;
//        size--;
//    }
//private:
//    LinkedNode* dummyHead;
//    int size;
//};


////3����ת����
//
///* ˫ָ�뷨 */
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        ListNode* prev = nullptr;
//        ListNode* cur = head;
//        while (cur != nullptr) {
//            ListNode* nextNode = cur->next; //������һ�����
//            cur->next = prev; //��תnextָ��ָ��
//            //׼����ת��һ�����
//            prev = cur;
//            cur = nextNode;
//        }
//        return prev;
//    }
//};
//
///* �ݹ鷨1 */
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        return reverseListHelper(nullptr, head);
//    }
//    ListNode* reverseListHelper(ListNode* prev, ListNode* cur) {
//        if (cur == nullptr)
//            return prev;
//        ListNode* nextNode = cur->next;
//        cur->next = prev;
//        return reverseListHelper(cur, nextNode);
//    }
//};
//
///* �ݹ鷨2 */
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        if (head == nullptr || head->next == nullptr) //�������ֻ��һ������������Ҫ��ת
//            return head;
//        ListNode* subHead = reverseList(head->next); //��ת��head->nextΪͷ����������
//        head->next->next = head; //������ת��head->next����Ϊ��β��㣬����ָ��head���
//        head->next = nullptr; //��headΪͷ��������ת��head�����Ϊβ��㣬next��Ҫ�ÿ�
//        return subHead;
//    }
//};
//
///* ����ͷ���+ͷ�巨 */
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        ListNode* dummyHead = new ListNode(0); //����ͷ���
//        ListNode* cur = head;
//        while (cur != nullptr) {
//            ListNode* nextNode = cur->next;
//            cur->next = dummyHead->next;
//            dummyHead->next = cur;
//            cur = nextNode;
//        }
//        ListNode* tmp = dummyHead->next;
//        delete dummyHead;
//        return tmp;
//    }
//};
//
///* ����ͷ���+ջ */
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        if (head == nullptr)
//            return nullptr;
//        //�����ջ
//        stack<ListNode*> st;
//        ListNode* cur = head;
//        while (cur != nullptr) {
//            st.push(cur);
//            cur = cur->next;
//        }
//        ListNode* newHead = new ListNode(0); //����ͷ���
//        //����ջ
//        cur = newHead;
//        while (!st.empty()) {
//            ListNode* node = st.top();
//            st.pop();
//            cur->next = node;
//            cur = cur->next;
//        }
//        cur->next = nullptr; //��β�ÿ�
//        ListNode* tmp = newHead->next;
//        delete newHead;
//        return tmp;
//    }
//};


////4���������������еĽڵ�
//
//class Solution {
//public:
//    ListNode* swapPairs(ListNode* head) {
//        ListNode* dummyHead = new ListNode(0); //����ͷ���
//        dummyHead->next = head;
//        ListNode* cur = dummyHead;
//        while (cur->next != nullptr && cur->next->next != nullptr) {
//            ListNode* node1 = cur->next, * node2 = node1->next;
//            ListNode* node3 = node2->next;
//            cur->next = node2; //����1
//            node2->next = node1; //����2
//            node1->next = node3; //����3
//            cur = node1;
//        }
//        ListNode* tmp = dummyHead->next;
//        delete dummyHead;
//        return tmp;
//    }
//};


////5��ɾ������ĵ�����N���ڵ�
//
//class Solution {
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        ListNode* dummyHead = new ListNode(0); //����ͷ���
//        dummyHead->next = head;
//        ListNode* slowPointer = dummyHead, * fastPointer = dummyHead;
//        while (n--) {
//            fastPointer = fastPointer->next;
//        }
//        fastPointer = fastPointer->next; //fastPointer�ٶ���һ������slowPointerָ���ɾ������ǰһ�����
//        while (fastPointer != nullptr) {
//            fastPointer = fastPointer->next;
//            slowPointer = slowPointer->next;
//        }
//        ListNode* tmp = slowPointer->next;
//        slowPointer->next = slowPointer->next->next;
//        delete tmp;
//        tmp = dummyHead->next;
//        delete dummyHead;
//        return tmp;
//    }
//};


////6�������ཻ
//
///* �������߲�ֵ������һ���� */
//class Solution {
//public:
//    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//        ListNode* cur1 = headA, * cur2 = headB;
//        int lenA = 0, lenB = 0;
//        while (cur1 != nullptr) {
//            cur1 = cur1->next;
//            lenA++;
//        }
//        while (cur2 != nullptr) {
//            cur2 = cur2->next;
//            lenB++;
//        }
//        ListNode* longHead = headA, * shortHead = headB;
//        int diff = lenA - lenB;
//        if (diff < 0) {
//            longHead = headB;
//            shortHead = headA;
//            diff = -diff;
//        }
//        while (diff--) { //ָ��ϳ������ָ�����߲�ֵ��
//            longHead = longHead->next;
//        }
//        while (longHead != shortHead) { //����ָ����һ���ߣ�ֱ����ȣ������ཻ����ͬʱΪnullptr��
//            longHead = longHead->next;
//            shortHead = shortHead->next;
//        }
//        return longHead;
//    }
//};
//
///* �������·�������ҵ�·�����Ǿ������� */
//class Solution {
//public:
//    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//        ListNode* cur1 = headA, * cur2 = headB;
//        while (cur1 != cur2) { //���㲻�ཻ����Ҳ��ͬʱ�ߵ�nullptr�˳�ѭ��
//            cur1 = cur1 == nullptr ? headB : cur1->next; //a+c+b
//            cur2 = cur2 == nullptr ? headA : cur2->next; //b+c+a
//        }
//        return cur1;
//    }
//};


////7����������II
//
//class Solution {
//public:
//    ListNode* detectCycle(ListNode* head) {
//        ListNode* slow = head, * fast = head;
//        while (fast != nullptr && fast->next != nullptr) {
//            fast = fast->next->next; //��ָ��һ��������
//            slow = slow->next; //��ָ��һ����һ��
//            if (fast == slow) { //����
//                fast = head; //һ��ָ���ͷ��ʼ�ߣ�һ��ָ�������������ߣ�����ʱ��Ϊ�뻷���
//                while (fast != slow) {
//                    //����ָ�붼��һ����һ��
//                    fast = fast->next;
//                    slow = slow->next;
//                }
//                return fast;
//            }
//        }
//        return nullptr;
//    }
//};
///*
//slow: a+b
//fast: a+b+n(b+c)
//
//a+b+n(b+c)=2(a+b)
//a+b=n(b+c)
//a=n(b+c)-b
//a=(n-1)(b+c)+c
//
//��n=1ʱ, a=c
//��n>1ʱ, a=circle+c
//n����С��1, ��Ϊ��ָ���һȦ����׷�Ͽ�ָ��
//
//����ʱslow�Ĳ���������a+b+(b+c), ��Ϊslow�뻷��, fastһ���ܹ���slow����һȦ֮ǰ׷����(����)
//*/

