class MyLinkedList {
    struct Node {
        int val;
        Node* next;
        Node(int v) : val(v), next(nullptr) {}
    };

    Node* dummy;   // sits before the real head
    int size;

public:
    MyLinkedList() {
        dummy = new Node(0);
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* cur = dummy->next;
        while (index--) cur = cur->next;
        return cur->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        Node* prev = dummy;
        while (index--) prev = prev->next;   // stop just before the insert spot
        Node* node = new Node(val);
        node->next = prev->next;
        prev->next = node;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        Node* prev = dummy;
        while (index--) prev = prev->next;   // stop just before the target
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        size--;
    }
};
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
