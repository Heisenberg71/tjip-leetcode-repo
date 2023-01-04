class MyLinkedList {
public:
    class node{
        public:
            int value;
            node* next;
            node(int _value, node* _next){
                value = _value;
                next = _next;
            }
    };

    const static int DUMMY_VALUE = -1;
    node* head;
    int len;

    MyLinkedList() {
        len = 0;
        head = new node(DUMMY_VALUE, NULL);
    }
    
    /// O(N) Here, N = size of linkList
    int get(int index) {
        if(index < 0 || len <= index) return -1;
        auto currentNode = head -> next;
        while(index--)
            currentNode = currentNode -> next;
        return currentNode -> value;
    }
    
    /// O(1)
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    /// O(N) Here, N = size of linkList
    void addAtTail(int val) {
        addAtIndex(len, val);
    }
    
    /// O(N) Here, N = size of linkList
    void addAtIndex(int index, int val) {
        if(index < 0 || len < index) return;

        len++;
        auto newNode = new node(val, NULL);
        auto currentNode = head;
        while(index--)
            currentNode = currentNode -> next;
        auto nextNode = currentNode -> next;
        currentNode -> next = newNode;
        newNode -> next = nextNode;
    }
    
    /// O(N) Here, N = size of linkList
    void deleteAtIndex(int index) {
        if(index < 0 || len <= index) return;

        len--;
        auto currentNode = head;
        while(index--)
            currentNode = currentNode -> next;
        auto deleteNode = currentNode -> next;
        currentNode -> next = deleteNode -> next;
        delete deleteNode;
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
