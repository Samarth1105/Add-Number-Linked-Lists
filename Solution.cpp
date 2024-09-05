struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* reverseLL(Node* head){
        Node* curr=head;
        Node* prev=NULL;
        Node* next=NULL;
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    int countNodes(Node* head) {
        int len = 0;
        Node* temp = head;
      
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }
    
    Node* addTwoLists(Node* num1, Node* num2) {
        int len1= countNodes(num1);
        int len2 = countNodes(num2);
        
        if(len2>len1) return addTwoLists(num2, num1);
        
        Node* revNum1= reverseLL(num1);
        Node* revNum2= reverseLL(num2);
        
        Node* res1=revNum1; 
        Node* res2= revNum2;
        Node* prev = NULL;
        
        int carry=0;
        while(res1 != NULL || res2!=NULL || carry!=0){
            int sum = carry + (res1 ? res1->data : 0);
            
            if(res2!=NULL){
                sum += res2->data;
                res2=res2->next;
            }
            
            carry= sum/10;
            sum=sum%10;
            
            if(res1!=NULL){
                res1->data= sum;
                prev=res1;
                res1=res1->next;
            }
            else{
                prev->next=new Node(sum);
                prev=prev->next;
            }
        }
        return reverseLL(revNum1);
    }
};
