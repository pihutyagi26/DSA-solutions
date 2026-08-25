class LRUCache {
public:
    class Node{
    public:
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v){
            key = k;
            value = v;
            prev = next = nullptr;
        }
        
       

    };
     void addNode(Node* newNode){
           Node* oldNext = head->next;

           head->next= newNode;
           oldNext->prev = newNode;

           newNode->next= oldNext;
           newNode->prev = head;
        }

        void delNode(Node* oldNode){
            Node* oldprev = oldNode->prev;
            Node* oldnext = oldNode->next;

            oldprev->next = oldnext;
            oldnext->prev = oldprev;
        }

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*>m;
    int limit; 

    LRUCache(int capacity) {
        limit = capacity;
        head->next= tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()){
            return -1;
        }
        Node* ansNode=m[key];
        int ans = ansNode->value;

        m.erase(key);
        delNode(ansNode);

        addNode(ansNode);
        m[key] = ansNode;

        return ans;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
        }

        if(m.size() == limit){
            m.erase(tail->prev->key);
            delNode(tail->prev);

        }
        Node* newNode = new Node(key , value);
        addNode(newNode);
        m[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */