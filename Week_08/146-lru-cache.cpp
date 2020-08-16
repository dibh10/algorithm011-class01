struct DoubleList
{
    int key;
    int val;
    DoubleList *pre, *next;
    DoubleList(int _key, int _val, DoubleList *_pre, DoubleList *_next):key(_key),val(_val),pre(_pre),next(_next){}
};

class LRUCache {
public:
    int cap = 0;
    int cnt = 0;
    unordered_map<int, DoubleList *> map;
    DoubleList *head, *tail;

    LRUCache(int capacity) {
        cap = capacity;
        cnt = 0;

        head = new DoubleList(0, 0, NULL, NULL);
        tail = new DoubleList(0, 0, NULL, NULL);
        head->next = tail;
        tail->pre  = head;
    }

    int get(int key) {
        if (!isExit(key))
        {
            return -1;
        }

        int val = removeKey(key);
        addLast(key, val);

        return val;
    }

    void put(int key, int value) {
        if (isExit(key))
        {
            removeKey(key);
        }
        else
        {
            if (cnt >= cap)
            {
                removeKey(head->next->key);
            }
        }
        addLast(key, value);
    }

private:
    void addFirst(int key, int value)
    {
        DoubleList *node = new DoubleList(key, value, NULL, NULL);
        node->next = head->next;
        node->pre  = head;
        head->next = node;

        map[key]  = node;
        cnt++;
    }
    void addLast(int key, int value)
    {
        DoubleList *node = new DoubleList(key, value, NULL, NULL);
        node->next = tail;
        node->pre  = tail->pre;
        tail->pre->next = node;
        tail->pre  = node;

        map[key] = node;
        cnt++;
    }
    int removeKey(int key)
    {
        DoubleList *node = map[key];
        int val = node->val;

        node->pre->next = node->next;
        node->next->pre = node->pre;

        delete node;
        map.erase(key);
        cnt--;

        return val;
    }
    bool isExit(int key)
    {
        return (map.count(key) != 0);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
