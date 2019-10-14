#include<stdio.h>
#include<iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "stdc++.h"
#include <string.h>

using namespace std;

 long int alphabet_array[27] = {0,63543,119315,220001,285496,330315,372427,403862,439973,488263,496900,504852,533867,589670,614784,644477,727844,733139,800065,912947,963557,999050,1015833,1039738,1039738,1042474};


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

void append(Node*& p, string d){
    Node* temp = new Node();
    temp->data=d;
    if(p == NULL) p = temp;
    else append(p->next, d);
}

int main()
{
  clock_t start, end;
  double cpu_time_used;
  FILE *dictionary;
  long int n =0;
  long int total_lines=0, flag = 0,i = 0, k =0;
  char ct = '`';
  char *line = NULL;
  size_t len = 0;
  long int offset = 2;
  int counter=0;

  //ssize_t nread;
  string search = "banana";
  string copied;
   long int temp=0, nread;

////////////////////////////////////////////////////////////////
  
  //Initializing linked List
  Node* head = NULL;
  Node* second = NULL;
  Node* base = NULL;
  
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


/////////////////////////////////////////////////////////////////  
  for(int m=0;search[m]!='\0';m++)
  {
    counter++;
  }
  dictionary = fopen("english_words.txt", "r");
  if(dictionary == NULL)
  {
     perror ("Error opening file.");
  }


  start = clock();
  int result;
  int initial_letter = search[0];
  int value = (int)search[0]-97;
  nread = 0;
  long int jump = alphabet_array[value];
  fseek(dictionary,jump,SEEK_SET);
  nread = getline(&line, &len, dictionary);
  temp=0;
  temp = temp+nread;
   while(line[0] == initial_letter)
  { 
    
    result=search.compare(line);
    if (result == -1)
    {
      copied=line;
      append(head, copied);
    }
    if (result < -1)
    {
	break;      
    }

    //cout<<"The result is: "<<result<<"\n";
    fseek(dictionary,jump+temp,SEEK_SET);
    nread = getline(&line, &len, dictionary);
    temp = temp+nread; 
  }
  free(line); 
  fclose(dictionary);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  cout<<"Second is : "<<cpu_time_used<<"\n";
  printList(head);
  deleteList(&head);
  cout<<"After deleting: ";
  printList(head);
  return 0;
}
