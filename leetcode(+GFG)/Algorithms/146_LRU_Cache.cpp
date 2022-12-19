// https://leetcode.com/problems/lru-cache/description/

class DLLNode{
public:
    int key;
    int val; 
    DLLNode* next ; 
    DLLNode* prev ; 

    DLLNode(int _key, int _val){
        key = _key, val = _val ;
        next = prev = NULL  ;
    }
};

class LRUCache {
public:
    DLLNode* tail ; 
    DLLNode* head ; 
    int size ;
    int cnt ;  
    unordered_map < int, DLLNode* > mp ;

    LRUCache(int capacity) {
        cnt = 0; 
        size = capacity ; 
        head = new DLLNode(-1,-1); 
        tail = new DLLNode(-1,-1);
        head->next = tail ; 
        tail->prev = head ; 
    }
    int get(int key) {
        if(mp.count(key)){
            // push in front
            int x = mp[key]->val ; 
            mp[key]->prev->next = mp[key]->next ; 
            mp[key]->next->prev = mp[key]->prev ; 

            DLLNode* node = new DLLNode(key,x);
            head->next->prev = node; 
            node->next = head->next ; 
            head->next = node ; 
            node->prev = head ;
            mp[key] = node ; 
            return x ; 
        }   
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            mp[key]->val = value; 
            this->get(key);
            return ; 
        }
        if(cnt==size){
            DLLNode* n = tail->prev ; 
            tail->prev = n->prev ; 
            n->prev->next = tail ;
            mp.erase(n->key); 

            DLLNode* newnode = new DLLNode(key, value);
            head->next->prev = newnode; 
            newnode->next = head->next ; 
            head->next = newnode ; 
            newnode->prev = head ;
            mp[key] = newnode ; 
            return; 
        }
        else{
            DLLNode* newnode = new DLLNode(key, value);
            head->next->prev = newnode; 
            newnode->next = head->next ; 
            head->next = newnode ; 
            newnode->prev = head ;
            mp[key] = newnode ;
            cnt++ ; 
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
