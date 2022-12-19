//https://leetcode.com/problems/lfu-cache/description/

class Node {
public:
    int key ;
    int val ; 
    int freq ;
    Node*next ; 
    Node*prev ;  

    Node(int _key, int _val){
        key = _key, val = _val, freq = 1 ; 
        next = prev = NULL ; 
    }
};

class LFUCache {
public:

    int size , cap ; 
    int minFreq = 0; 
    unordered_map< int, pair<Node*, Node*> > freqToDLL; 
    unordered_map< int, Node*> keyToNode ;

    LFUCache(int capacity) {
        size = 0, cap = capacity ; 
        minFreq = 1; 
    }
    
    int get(int key) {
        if(cap==0) return -1 ; 
        if(keyToNode[key] != NULL){
            // put in increased arr
            //  if it is only one element in that arr and its freq == minFreq then increase minFreq
            Node*n = keyToNode[key] ; 
            removeFromFreq(n); 
            if(n->freq == minFreq && isNoElementPresent(n->freq)){
                minFreq++ ;
            }
            Insert(n, n->freq + 1);
            return keyToNode[key]->val ; 
        }
        return -1; 
    }
    
    void put(int key, int value) {
        if(cap==0) return ;  
        else if(keyToNode[key] != NULL){
            // already present
            Node*n = keyToNode[key] ; 
            n->val = value ; 
            // remove from that freq
            removeFromFreq(n); 
            // if it was only element in minfreq -> then increment minFreq 
            if(n->freq == minFreq && isNoElementPresent(n->freq)){
                minFreq++ ;
            }
            // add to increased freq
            Insert(n, n->freq + 1);
            return ; 
        }
        // delete lfu if capacity reached -> minFreq = 1 
        else if(size == cap){
            //delete lfu(lru)
            Node*n = freqToDLL[minFreq].second->prev ; 
            removeFromFreq(n);
            keyToNode[n->key] = NULL ; 
            minFreq = 1; 
            Node*n1 = new Node(key, value); 
            keyToNode[key] = n1 ; 
            Insert(n1, 1);
            return ;  
        }
        // just insert -> minFreq = 1
        minFreq = 1; 
        size++ ; 
        Node*n = new Node(key, value);
        keyToNode[key] = n; 
        Insert(n,1);
    }

    void Insert(Node*n, int freq){
        if( freqToDLL[freq].first == NULL ){
            // in case this freq did not have entry yet 
            // then initialise head and tail and connect them
            freqToDLL[freq].first = new Node(-1, -1); 
            freqToDLL[freq].second = new Node(-1, -1);
            freqToDLL[freq].first->next = freqToDLL[freq].second ; 
            freqToDLL[freq].second->prev = freqToDLL[freq].first ; 
        }
        n->next = freqToDLL[freq].first->next ; 
        freqToDLL[freq].first->next = n ; 
        n->next->prev = n ; 
        n->prev = freqToDLL[freq].first ;
        //increase frequency of node
        n->freq = freq; 
    }

    void removeFromFreq(Node*n){
        (n->prev)->next = n->next ; 
        (n->next)->prev = n->prev ; 
    }
    bool isNoElementPresent(int freq){
        // check if that freq does not have any elements in it 
        return freqToDLL[freq].first->next == freqToDLL[freq].second ; 
    }

};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
