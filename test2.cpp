#include<stdio.h>
#include<iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "stdc++.h"

using namespace std;


class Node  
{  
    public: 
    string data;  
    Node *next;  
};  


void printList(Node* n) 
{ 
    while (n != NULL) 
    { 
        cout << n->data << " "; 
        n = n->next; 
    } 
} 

void deleteList(Node** head_ref)  
{  
      
/* deref head_ref to get the real head */
Node* current = *head_ref;  
Node* next;  
  
while (current != NULL)  
{  
    next = current->next;  
    free(current);  
    current = next;  
}  
      
/* deref head_ref to affect the real head back  
    in the caller. */
*head_ref = NULL;  
}

/*void append(Node*& reference, string str_data) 
{ 
   Node* new_node = new Node();
   //Node* last_node = new Node();

   new_node->data = str_data;

   if(*reference->next != NULL)
   { 
	//new_node = reference->next;
	append(&(reference->next), str_data);
   }
   else
   {
       	reference->next = new_node;
   }	
   return;  
}*/


void append(Node*& p, string d){
    Node* temp = new Node();
    temp->data=d;
    if(p == NULL) p = temp;
    else append(p->next, d);
}




int main()
{
  FILE *dictionary;
  long int n =0;
  long int total_lines=0, flag = 0,i = 0, k =0;
  char ct = ' ';
  char *line = NULL;
  size_t len = 0;
  long int offset = 2;
  //ssize_t nread;
  dictionary = fopen("copy.txt", "r");
  string search = "cred";
  string copied;
  long int alphabet_array[27];
  long int temp=0, nread;
  
  //Initializing linked List
  Node* head = NULL;
  Node* second = NULL;
  Node* base = NULL;
  ///
  head = new Node();
  second = new Node();
  base = new Node();
  //connecting head and base
  head->data = "Kartikey";
  head->next = second;
  
  second->data = "Ashish";
  second->next = base;
  
  base->data= "Deepraj";
  base->next = NULL;


  //making a ifunction to add the elements in a linked list!
  //printList(head);
  if(dictionary == NULL)
  {
     perror ("Error opening file.");
  }
  else
  {  
    while((nread = getline(&line, &len, dictionary)) != -1)
    {
	cout<<"The nread value is: "<<nread<<"\n";
        temp = temp + nread;
        printf("length = %ld: \n total length = %ld\n\n\n", nread, temp);
        if(ct != line[0])
        {
		flag = 1;
		alphabet_array[i++] = temp;
        }
	ct = line[0];
        if(flag == 1)
	{
	   cout<<"The number of elements of "<<(char)((int)ct-1)<<" are: "<<alphabet_array[i-1]<<"\n";
	   flag = 0;
	}
        //cout<<"Print this: "<<"";
        //k = fseek(dictionary,offset,alphabet_array[i-1] );
        //cout<<"The alphabet is :"<<
        //printf("%ld", ftell(dictionary));
        //cout<<","<<k<<",";
        cout<<len<<"\n";
        ++total_lines;

     int counter=0;
     for(i=0;search[i]!='\0';i++)
     {
	counter++;
	cout<<search[i]<<","<<counter<<"\n";
     }
     cout<<line<<"\n";
       i=0;
       int flg = 1;
       int diff = 0, clt=0;
       for(int j=0;j<nread;j++)
       { 
	 clt = (j-i);
      	 if(search[i] == line[j])
	 {
	    if(diff != clt){i=0;}
	    diff = clt;
            if(flg)i++;
       	    cout<<counter<<" and "<<i<<"\n";
            if(counter == i)
     	    {
	      flg = 0;
	      cout<<"found!!\n";
              copied = line;
              //cout<<"The copied line is: "<<copied<<"\n";
	      append(head, copied);
	      i = 0;
            }
	 } 
       }

     }   
    cout<<"The total number of line: "<<total_lines<<'\n';

    if (feof(dictionary))
    {
      puts ("End-of-File reached.");
      printf ("Total number of bytes read: %ld\n", n);
      printf ("Total number of lines read: %ld\n", total_lines);
    }
   else
   { 
     puts("End-of-File was not reached.");
   }
     free(line);
     fclose(dictionary);
  }
  printList(head);
  deleteList(&head);
  cout<<"After deleting: ";
  printList(head);
  return 0;
}
