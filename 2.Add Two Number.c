/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode Node;
int ListLen(Node* list)
{
    int listLen = 0;
    if(NULL == list)
    {
        return -1;
    }
    while(list!=NULL)
    {
        listLen++;
        list=list->next;
    }
    return listLen;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if(NULL == l1 || NULL == l2)
    {
        return NULL;
    }
    
    Node* resList = NULL;
    Node* tempList = NULL;
    Node* tempNode = NULL;
    Node *l1Temp=NULL;
    Node *l2Temp=NULL;
    int temp = 0;
    int sum = 0;
    int index = 1;
    int listLen = 0;

    resList = (Node*)malloc(sizeof(Node));
    resList->val = 0;
    resList->next = NULL;
    

    tempList = resList;
    l1Temp = l1;
    l2Temp = l2;
    listLen = (ListLen(l1)>ListLen(l2)?ListLen(l1):ListLen(l2));

    while(tempList)
    {
        sum = (l1Temp?l1Temp->val:0) + (l2Temp?l2Temp->val:0) + temp;
        tempList->val = sum%10;
        temp = sum/10;
        if(index<listLen || (index==listLen && sum>=10))
        {
            tempNode = (Node*)malloc(sizeof(Node));
            tempNode->val = 0;
            tempList->next = tempNode;
        }
        
        tempList=tempList->next;
        if(NULL!=l1Temp)
        {
            l1Temp = l1Temp->next;
        }
        if(NULL!=l2Temp)
        {
            l2Temp = l2Temp->next;
        }
        index++;
    }
    
    
    return resList;
}