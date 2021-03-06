/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *Answer = new ListNode;
        ListNode * Temp;
        int count=0;
        int carry=0,once=0;
        int result1 =0;
        while(l1 != NULL || l2 != NULL || carry != 0){
          //  cout<<"coutn"<<count<<endl;
             if((l1 == NULL && l2 == NULL)  ){
                 result1 = carry;
                 carry=0;
                 once =0;
                 if(result1 ==0 ){
                     break;
                 }
                 
             }
             else if(l1 == NULL ){
                result1 = carry+l2->val;
                l2 = l2->next;
           
                 once++;
                 carry=0;
                
            }
             else if(l2 == NULL ){
                result1 = carry + l1->val;
                l1 = l1->next;
                 once++;
                 carry=0;
                
            }
            else{
                result1 = l1->val + l2->val + carry;
             //   cout<<result1<<endl;
                l1 = l1->next;
                l2 = l2->next;
                carry=0;
            }
            count++;
            if(result1>=20){
                result1 = result1-20;
                 carry = 2;
            }
            else if(result1>=10){
                result1 = result1-10;
                carry = 1;
            }
            
            if(count == 1){
                Answer->val = result1;
                Temp = Answer;
              
            }
            else{
                ListNode * newnode = new ListNode(result1);
                Temp->next = newnode;
                Temp = newnode;
                
            }
            
          
            
        }
        
        
            
            
        
        return Answer;
    }
};
