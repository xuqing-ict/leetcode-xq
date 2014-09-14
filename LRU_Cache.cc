//LRU Cache, 双向链表 + hash map
class LRUCache{
private:
    struct DuListNode   //definition only for the data structure
    {
        DuListNode *prev;
        DuListNode *next;
        int key, value;
        DuListNode(int _key, int _value):key(_key),value(_value),prev(nullptr), next(nullptr){}
    };
    
    int size;
    int capacity;
    unordered_map<int, DuListNode *> myMap;
    DuListNode * head;
    
    void deleteNode(DuListNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        node = nullptr;
    }
    
    void moveToHead(DuListNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        insertHead(node);
    }
    
    void insertHead(DuListNode *node)
    {
        DuListNode *tmp = head->next;
        node->prev = head;
        head->next = node;
        node->next = tmp;
        tmp->prev = node;
    }
    
    void deleteTail()
    {
        unordered_map<int, DuListNode *>::iterator it = myMap.find(head->prev->key);
        myMap.erase(it);
        deleteNode(head->prev);
        --size;
    }
public:
    LRUCache(int capacity) {
        size = 0;
        this->capacity = capacity;
        head = new DuListNode(0,0);
        head->prev = head;
        head->next = head;
    }
    
    ~LRUCache()
    {
        DuListNode *p = head->next, *q = nullptr;
        while(p != head)
        {
            q = p->next;
            delete p;
            p = nullptr;
            p = q;
        }
        delete head;
        head = nullptr;
    }
    
    bool empty() const
    {
        return size == 0;
    }
    
    bool isFull() const
    {
        return size == capacity;
    }
    
    
    int get(int key) {
        unordered_map<int,  DuListNode*>::const_iterator it = myMap.find(key);
        if(it != myMap.end())
        {
            moveToHead(it->second);
            return (it->second)->value;
        }
        else
        {
            return -1;
        }
    }
    
    
    void set(int key, int value) {
        unordered_map<int, DuListNode*>::const_iterator it = myMap.find(key);
        if(it == myMap.end())
        {
            DuListNode *node =  new DuListNode(key,value);
            if(isFull()) deleteTail();
            myMap.insert(unordered_map<int,DuListNode*>::value_type(key,node));
            insertHead(node);
            ++size;
        }
        else
        {
            it->second->value = value;
            moveToHead(it->second);
        }
    }
};
