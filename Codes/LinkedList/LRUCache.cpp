class LRUCache
{
    private:
    class Node{
        public:
        int key;
        int val;
        Node *prev, *next;
        Node(int k, int v){
            key=k;
            val=v;
        }
    };
    Node *head=new Node(-1, -1);
    Node *tail=new Node(-1, -1);
    unordered_map<int, Node*> mp;
    int size;
    
    void addNode(Node *ptr){
        ptr->prev= head;
        ptr->next=head->next;
        head->next->prev=ptr;
        head->next=ptr;
    }
    
    void deleteNode(Node *ptr){
        Node *next_ptr=ptr->next;
        Node *prev_ptr=ptr->prev;
        prev_ptr->next=next_ptr;
        next_ptr->prev=prev_ptr;
        
        delete ptr;
    }

    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        size=cap;
        head->next=tail;
        tail->prev=head;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        if(mp.find(key)!=mp.end()){
            Node *resNode=mp[key];
            int res=resNode->val;
            deleteNode(resNode);
            
            Node *newNode= new Node(key, res);
            addNode(newNode);
            mp[key]=newNode;
            
            return res;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here 
        if(mp.find(key)!=mp.end()){
            Node *resNode=mp[key];
            deleteNode(resNode);
        }else if(mp.size()==size){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node *newNode= new Node(key, value);
        addNode(newNode);
        mp[key]=newNode;
    }
};
