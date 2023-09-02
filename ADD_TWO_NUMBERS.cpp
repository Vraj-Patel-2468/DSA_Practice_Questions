class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *I1=l1, *I2=l2, *I3, *new_list=nullptr;
        int carry=0;
        while(true) {
            if(I1==nullptr && I2==nullptr && carry==0) break;
            else if(I1==nullptr && I2!=nullptr) {
                ListNode* temp=new ListNode();
                temp->val=(I2->val+carry)%10;
                temp->next=nullptr;
                carry=(I2->val+carry)/10;
                I2=I2->next;
                if(new_list==nullptr) {new_list=temp;I3=temp;}
                else {I3->next=temp; I3=I3->next;}
            }
            else if(I2==nullptr && I1!=nullptr) {
                ListNode* temp=new ListNode();
                temp->val=(I1->val+carry)%10;
                temp->next=nullptr;
                carry=(I1->val+carry)/10;
                I1=I1->next;
                if(new_list==nullptr) {new_list=temp;I3=temp;}
                else {I3->next=temp; I3=I3->next;}
            }
            else if(I2!=nullptr && I1!=nullptr) {
                ListNode* temp=new ListNode();
                temp->val=(I1->val+I2->val+carry)%10;
                temp->next=nullptr;
                carry=(I1->val+I2->val+carry)/10;
                I1=I1->next; I2=I2->next;
                if(new_list==nullptr) {new_list=temp;I3=temp;}
                else {I3->next=temp; I3=I3->next;}
            }
            else if(I2==nullptr && I1==nullptr && carry!=0) {
                ListNode* temp=new ListNode();
                temp->val=(carry)%10;
                temp->next=nullptr;
                carry=(carry)/10;
                if(new_list==nullptr) {new_list=temp;I3=temp;}
                else {I3->next=temp; I3=I3->next;}
            }
        } 
        return new_list;
    }
};