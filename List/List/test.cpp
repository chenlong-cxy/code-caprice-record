////1、移除链表元素
//
///* 不设置虚拟头结点 */
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
///* 设置虚拟头结点 */
//class Solution {
//public:
//    ListNode* removeElements(ListNode* head, int val) {
//        ListNode* dummyHead = new ListNode(0); //虚拟头结点
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


////2、设计链表
//
//class MyLinkedList {
//    struct LinkedNode {
//        int val;
//        LinkedNode* next;
//        LinkedNode(int x) :val(x), next(nullptr) {}
//    };
//public:
//    MyLinkedList() {
//        dummyHead = new LinkedNode(0); //虚拟头结点
//        size = 0; //链表中的结点个数
//    }
//
//    int get(int index) {
//        if (index < 0 || index >= size) {
//            return -1;
//        }
//        LinkedNode* cur = dummyHead->next; //寻找目标结点
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
//        LinkedNode* cur = dummyHead; //寻找最后一个结点
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
//        LinkedNode* cur = dummyHead; //寻找下标为index的结点的前一个结点
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
//        LinkedNode* cur = dummyHead; //寻找删除结点的前一个结点
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


////3、翻转链表
//
///* 双指针法 */
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        ListNode* prev = nullptr;
//        ListNode* cur = head;
//        while (cur != nullptr) {
//            ListNode* nextNode = cur->next; //保存下一个结点
//            cur->next = prev; //翻转next指针指向
//            //准备翻转下一个结点
//            prev = cur;
//            cur = nextNode;
//        }
//        return prev;
//    }
//};
//
///* 递归法1 */
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
///* 递归法2 */
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        if (head == nullptr || head->next == nullptr) //空链表和只有一个结点的链表不需要翻转
//            return head;
//        ListNode* subHead = reverseList(head->next); //翻转以head->next为头结点的子链表
//        head->next->next = head; //子链表翻转后，head->next结点变为了尾结点，让其指向head结点
//        head->next = nullptr; //以head为头结点的链表翻转后，head结点作为尾结点，next需要置空
//        return subHead;
//    }
//};
//
///* 虚拟头结点+头插法 */
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        ListNode* dummyHead = new ListNode(0); //虚拟头结点
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
///* 虚拟头结点+栈 */
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        if (head == nullptr)
//            return nullptr;
//        //结点入栈
//        stack<ListNode*> st;
//        ListNode* cur = head;
//        while (cur != nullptr) {
//            st.push(cur);
//            cur = cur->next;
//        }
//        ListNode* newHead = new ListNode(0); //虚拟头结点
//        //结点出栈
//        cur = newHead;
//        while (!st.empty()) {
//            ListNode* node = st.top();
//            st.pop();
//            cur->next = node;
//            cur = cur->next;
//        }
//        cur->next = nullptr; //表尾置空
//        ListNode* tmp = newHead->next;
//        delete newHead;
//        return tmp;
//    }
//};


////4、两两交换链表中的节点
//
//class Solution {
//public:
//    ListNode* swapPairs(ListNode* head) {
//        ListNode* dummyHead = new ListNode(0); //虚拟头结点
//        dummyHead->next = head;
//        ListNode* cur = dummyHead;
//        while (cur->next != nullptr && cur->next->next != nullptr) {
//            ListNode* node1 = cur->next, * node2 = node1->next;
//            ListNode* node3 = node2->next;
//            cur->next = node2; //步骤1
//            node2->next = node1; //步骤2
//            node1->next = node3; //步骤3
//            cur = node1;
//        }
//        ListNode* tmp = dummyHead->next;
//        delete dummyHead;
//        return tmp;
//    }
//};


////5、删除链表的倒数第N个节点
//
//class Solution {
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        ListNode* dummyHead = new ListNode(0); //虚拟头结点
//        dummyHead->next = head;
//        ListNode* slowPointer = dummyHead, * fastPointer = dummyHead;
//        while (n--) {
//            fastPointer = fastPointer->next;
//        }
//        fastPointer = fastPointer->next; //fastPointer再多走一步，让slowPointer指向待删除结点的前一个结点
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


////6、链表相交
//
///* 长的先走差值步，再一起走 */
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
//        while (diff--) { //指向较长链表的指针先走差值步
//            longHead = longHead->next;
//        }
//        while (longHead != shortHead) { //两个指针再一起走，直到相等（遇到相交结点或同时为nullptr）
//            longHead = longHead->next;
//            shortHead = shortHead->next;
//        }
//        return longHead;
//    }
//};
//
///* 走完你的路再来走我的路，我们就能相遇 */
//class Solution {
//public:
//    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//        ListNode* cur1 = headA, * cur2 = headB;
//        while (cur1 != cur2) { //就算不相交最终也会同时走到nullptr退出循环
//            cur1 = cur1 == nullptr ? headB : cur1->next; //a+c+b
//            cur2 = cur2 == nullptr ? headA : cur2->next; //b+c+a
//        }
//        return cur1;
//    }
//};


////7、环形链表II
//
//class Solution {
//public:
//    ListNode* detectCycle(ListNode* head) {
//        ListNode* slow = head, * fast = head;
//        while (fast != nullptr && fast->next != nullptr) {
//            fast = fast->next->next; //快指针一次走两步
//            slow = slow->next; //慢指针一次走一步
//            if (fast == slow) { //相遇
//                fast = head; //一个指针从头开始走，一个指针从相遇点继续走，相遇时即为入环结点
//                while (fast != slow) {
//                    //两个指针都是一次走一步
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
//当n=1时, a=c
//当n>1时, a=circle+c
//n不会小于1, 因为慢指针第一圈不会追上快指针
//
//相遇时slow的步数不会是a+b+(b+c), 因为slow入环后, fast一定能够在slow走完一圈之前追上他(相遇)
//*/

