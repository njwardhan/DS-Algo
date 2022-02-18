// Problem Link: https://www.codingninjas.com/codestudio/contests/love-babbar-contest-5/problems/17603

/************************************************
   
   Following is the linkedList class structure:

   class List {
      public:
          int data;
          List *next;

          List(int val) {
              this->data = val;
              next = NULL;
          }
          ~List() {
              if (next != NULL) {
                  delete next;
              }
          }
   };

*************************************************/

List* foldAndMerge(List *head) {
	
    int c = 0;
    List* help_head = head;
    while((head->next)->data != -1)
    {
        c++;
        head = head->next;
    }
    
    List *first = help_head;
 
    int i = 1;
    while(i <= c/2)
    {
        help_head = help_head->next;
        i++;
    }
    
    List *second = help_head->next;
    help_head->next = NULL;
    
    List *prev = NULL;
    List *current;
    
    while(first != NULL)
    {
        current = first->next;
        first->next = prev;
        prev = first;
        first = current;
    }
    List* answer = second;
    while(second != NULL && prev != NULL)
    {
        second->data *= prev->data;
        second = second->next;
        prev = prev->next;
    }
    List(-1);
    //(second->next)->data = -1;
    
    return answer;
}