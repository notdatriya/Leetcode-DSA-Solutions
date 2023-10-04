// class node{
//     int key;
//     int value;
//     node* next;
//     node(int key,int value){
//         key=key;
//         value=value;
//         next=NULL;
//     }
// };
class MyHashMap {
public:
    // vector<int>arr;
    vector<vector<pair<int,int>>>arr;
    int size;
    int hash(int key){
            return key%size;
        }
    MyHashMap() {
        // int size=1e6+1;
        // arr.resize(size);
        // fill(arr.begin(),arr.end(),-1);
        
         size=1000;
        
        arr.resize(size);
    }
    
    void put(int key, int value) {
      // arr[key]=value;
        
        int idx=hash(key);
        for(auto &it:arr[idx]){
            if(it.first==key){
                it.second=value;
                return;
            }
        }
        arr[idx].push_back({key,value});
        
        
    }
   
    int get(int key) {
// return arr[key];     
        
        int idx=hash(key);
        for(auto it:arr[idx]){
            if(it.first==key){
                return it.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        
        // arr[key]=-1;
        //  int idx=hash(key);
        // for(auto it=arr[idx].begin();it!=arr[idx].end();it++){
        //     if(it->first==key){
        //         arr.erase(it);
        //         return;
        //     }
        // }
        
         int idx = hash(key);
        auto &bucket = arr[idx];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it); // Remove the key-value pair if found
                return;
            }
        }
        
      
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */