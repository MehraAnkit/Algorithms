/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* a, Node* b)  
{  
    // code here
    Node* temp=new Node(0);
        Node* res=temp;
        while(a && b){
            if(a->data<b->data){
                temp->next=a;
                temp=temp->next;
                a=a->next;
            }else{
                temp->next=b;
                temp=temp->next;
                b=b->next;
            }
        }
        if(a){
            temp->next=a;
        }else{
            temp->next=b;
        }
        return res->next;
}  