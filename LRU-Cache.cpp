#include<bits/stdc++.h>
class Node{
    public:
    Node* next;
    Node* prev;
    int key;
    int val;
    Node(int x,int y){
        key=x;
        val=y;
        next=NULL;
        prev=NULL;
    }
};
class LRUCache{
public:
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    map<int,Node*> mp;
    int sz=0;
    LRUCache(int capacity){
        head->next=tail;
        tail->prev=head;
        sz=capacity;
        mp.clear();
        // Write your code here
    }
    void delNode(Node* node){
        Node* prev=node->prev;
        Node* nxt=node->next;
        prev->next=nxt;
        nxt->prev=prev;
    }
    void addNode(Node* node){
        Node* nxt=head->next;
        head->next=node;
        node->prev=head;
        node->next=nxt;
        nxt->prev=node;
    }

    int get(int key){
        if(mp.find(key)!=mp.end()){
            Node* add=mp[key];
            int val=add->val;
            mp.erase(key);
            delNode(add);
            addNode(add);
            mp[key]=head->next;
            return val;
        }
        else return -1;
    }

    void put(int key, int value){
        if(mp.find(key)!=mp.end()){
            Node* add=mp[key];
            mp.erase(key);
            delNode(add);
            Node* to_add=new Node(key,value);
            addNode(to_add);
            mp[key]=head->next;
        }
        else{
            Node* to_add=new Node(key,value);
            addNode(to_add);
            mp[key]=head->next;
        }
        if(mp.size()>sz){
            Node* del=tail->prev;
            mp.erase(del->key);
            delNode(tail->prev);
        }
    }
};
