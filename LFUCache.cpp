#include <bits/stdc++.h> 
struct Node {
    int key, value, cnt;
    Node *next; 
    Node *prev;
    Node(int _key, int _value) {
        key = _key;
        value = _value; 
        cnt = 1; 
    }
}; 
struct List {
    int size; 
    Node *head; 
    Node *tail; 
    List() {
        head = new Node(0, 0); 
        tail = new Node(0,0); 
        head->next = tail;
        tail->prev = head; 
        size = 0;
    }
    
    void addFront(Node *node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++; 
    }
    
    void removeNode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--; 
    }
    
    
    
};
class LFUCache {
    map<int, Node*> keyNode; 
    map<int, List*> freqListMap; 
    int maxSizeCache;
    int minFreq; 
    int curSize; 
public:
    LFUCache(int capacity) {
        maxSizeCache = capacity; 
        minFreq = 0;
        curSize = 0; 
    }
    void updateFreqListMap(Node *node) {
        keyNode.erase(node->key); 
        freqListMap[node->cnt]->removeNode(node); 
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++; 
        }
        
        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        } 
        node->cnt += 1; 
        nextHigherFreqList->addFront(node); 
        freqListMap[node->cnt] = nextHigherFreqList; 
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key]; 
            int val = node->value; 
            updateFreqListMap(node); 
            return val; 
        }
        return -1; 
    }
    
    void put(int key, int value) {
        if (maxSizeCache == 0) {
            return;
        }
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key]; 
            node->value = value; 
            updateFreqListMap(node); 
        }
        else {
            if(curSize == maxSizeCache) {
                List* list = freqListMap[minFreq]; 
                keyNode.erase(list->tail->prev->key); 
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--; 
            }
            curSize++; 
            // new value has to be added who is not there previously 
            minFreq = 1; 
            List* listFreq = new List(); 
            if(freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq]; 
            }
            Node* node = new Node(key, value); 
            listFreq->addFront(node);
            keyNode[key] = node; 
            freqListMap[minFreq] = listFreq; 
        }
    }
};
// class Node{
//     public:
//     Node* next;
//     Node* prev;
//     int count,val,key;
//     Node(int v,int k){
//         val=v;
//         key=k;
//         count=1;
//         next=NULL;
//         prev=NULL;
//     }
// };
// class List{
//     public:
//     Node* head;
//     Node* tail;
//     int size;
//     List(){
//         head=new Node(0,0);
//         tail=new Node(0,0);
//         head->next=tail;
//         tail->prev=head;
//         size=0;
//     }
//     void removeNode(Node* node){
//         Node* prev=node->prev;
//         Node* nxt=node->next;
//         prev->next=nxt;
//         nxt->prev=prev;
//         size--;
//     }
//     void addNode(Node* node){
//         Node* nxt=head->next;
//         head->next=node;
//         node->prev=head;
//         node->next=nxt;
//         nxt->prev=node;
//         size++;
//     }
// };
// class LFUCache{
// public:
//     map<int,Node*> keyNode;
//     map<int,List*> listMap;
//     int minFreq=0;
//     int currFreq=0;
//     int cacheSize=0;
//     LFUCache(int capacity){
//         keyNode.clear();
//         minFreq=0;
//         currFreq=0;
//         cacheSize=capacity;   
//     }
//     void updateList(Node* node){
//         keyNode.erase(node->key);
//         listMap[node->count]->removeNode(node);
//         if(node->count==minFreq and listMap[node->count]->size==0){
//             minFreq++;
//         }
//         List* nxt=new List();
//         if(listMap.find(node->count+1)!=listMap.end()){
//             nxt=listMap[node->count+1];
//         }
//         node->count+=1;
//         nxt->addNode(node);
//         listMap[node->count]=nxt;
//         keyNode[node->key]=node;

//     }
//     int get(int key){
//         if(keyNode.find(key)!=keyNode.end()){
//             Node* n=keyNode[key];
//             int val=n->val;
//             updateList(n);
//             return val;
//         }
//         return -1;
//     }

//     void put(int key, int value){
//         if(cacheSize==0){
//             return;
//         }
//         if(keyNode.find(key) != keyNode.end()) {
//             Node* node = keyNode[key]; 
//             node->val = value; 
//             updateList(node); 
//         }
//         else{
//             if(currFreq==cacheSize) {
//                 List* list = listMap[minFreq]; 
//                 keyNode.erase(list->tail->prev->key); 
//                 listMap[minFreq]->removeNode(list->tail->prev);
//                 currFreq--; 
//             }
//             currFreq++; 
//             minFreq=1; 
//             List* listFreq = new List(); 
//             if(listMap.find(minFreq)!=listMap.end()) {
//                 listFreq = listMap[minFreq]; 
//             }
//             Node* node = new Node(key, value); 
//             listFreq->addNode(node);
//             keyNode[key] = node; 
//             listMap[minFreq] = listFreq; 
//         }
//     }
// };
