class Node{
    public:
    Node* links[26];
    bool flag=false;
    
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag=true;
    }
    
    bool isEnd(){
        return flag;
    }
};


class Trie{
    
    private: Node* root;
    public:
    
    Trie(){
        root=new Node();
    }
    
    
    void insert(string word){
        Node* node=root;
        
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            
            node=node->get(word[i]);
        }
        
        node->setEnd();
    }
    
    
    bool search(string word){
        
        Node* node=root;
        
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            
            node=node->get(word[i]);
        }
        return true;
    }
    
        bool startsWith(string prefix) {
        Node* node=root;
        
        for(int i=0;i<prefix.length();i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;
    }
    
    
    string findPrefix(string word){
        Node* node=root;
        string prefix;
        
        for(int i=0;i<word.length();i++){
            if(node->get(word[i])==NULL)return word;
            
            node=node->get(word[i]);
            prefix+=word[i];
            
            if(node->isEnd())return prefix;
        }
        return word;
    }
};


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        Trie trie;
        for(string word: dictionary){
            trie.insert(word);
        }
        
        string ans="";
        string word="";
        
        for(char ch: sentence){
            if(ch!=' ')word+=ch;
            else{
                ans+=trie.findPrefix(word)+' ';
                word="";
            }
        }
        
        ans+=trie.findPrefix(word);
        return ans;
    }
};