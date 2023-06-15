#include <bits/stdc++.h> 
class Node{
    public:
    Node* node[26];
    bool isWord;
    Node(){
        for(int i=0;i<26;i++){
            node[i]=0;
        }
        isWord=0;
    }
};
int distinctSubstring(string &word) {
    int n=word.length();
    int count=0;
    Node* head=new Node();
    for(int i=0;i<n;i++){
        Node* temp=head;
        for(int j=i;j<n;j++){
            if(!temp->node[word[j]-'a']){
                temp->node[word[j]-'a']=new Node();
                count++;
            }
            temp=temp->node[word[j]-'a'];
        }
    }
    return count;
}
