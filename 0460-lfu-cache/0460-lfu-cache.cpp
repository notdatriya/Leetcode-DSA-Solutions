 class node{
     public:
      int key;
      int val;
      int count;
        node*next;
        node*prev;
        
        
        node(int _key,int _val){
            key=_key;
            val=_val;
            count=1;
        }
    };
    
  class List{
      public:
    int size;
      node* head;
      node* tail;
      public:
      List(){
          head=new node(0,0);
          tail=new node(0,0);
          head->next=tail;
          tail->prev=head;
          size=0;
      }
    
      void addnode(node* newnode){
          node*temp=head->next;
          newnode->next=temp;
          newnode->prev=head;
          head->next=newnode;
          temp->prev=newnode;
          size++;
      }
      
      void deletenode(node* delnode){
          node* delprev=delnode->prev;
          node* delnext=delnode->next;
          delnext->prev=delprev;
          delprev->next=delnext;
          size--;   
      }
  };
    

class LFUCache {
   
    map<int,node*>keymap;
    map<int,List*>freqmap;
        int maxsize;
        int minfreq;
        int currsize;
    
public:
    LFUCache(int capacity) {
     maxsize=capacity;
        minfreq=0;
        currsize=0;  
    }
    
    void updatefreqmap(node* currnode){
        keymap.erase(currnode->key);
        freqmap[currnode->count]->deletenode(currnode);
        if(currnode->count==minfreq && freqmap[currnode->count]->size==0){
            minfreq+=1;
        }
        List* higherfreqlist=new List();
        if(freqmap.find(currnode->count+1)!=freqmap.end()){
            higherfreqlist=freqmap[currnode->count+1];
        }
        currnode->count+=1;
        higherfreqlist->addnode(currnode);
        freqmap[currnode->count]=higherfreqlist;
        keymap[currnode->key]=currnode;
        
    }
    
    int get(int key) {
        if(keymap.find(key)!=keymap.end()){
            node* resnode=keymap[key];
            int res=resnode->val;
            updatefreqmap(resnode);
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxsize==0){
            return;
        }
        if(keymap.find(key)!=keymap.end()){
            node* resnode=keymap[key];
            resnode->val=value;
            updatefreqmap(resnode);
        }
        else{
            if(currsize==maxsize){
                List* listt=freqmap[minfreq];
                keymap.erase(listt->tail->prev->key);
                freqmap[minfreq]->deletenode(listt->tail->prev);
                currsize--;
            }
                currsize++;
                minfreq=1;
                List* newlist=new List();
                if(freqmap.find(minfreq)!=freqmap.end()){
                    newlist=freqmap[minfreq];
                }
                node* newnode=new node(key,value);
                newlist->addnode(newnode);
                keymap[key]=newnode;
                freqmap[minfreq]=newlist;
                
        }
    }
};




// /**
//  * Your LFUCache object will be instantiated and called as such:
//  * LFUCache* obj = new LFUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */