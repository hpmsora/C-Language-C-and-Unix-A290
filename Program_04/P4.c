/*Filename: P4.c *
 *Part of: Fourth A290 program *
 *Created by: Won Yong Ha *
 *Created on: 6/13/2016 *
 *Last Modified by: Won Yong Ha *
 *Last Modified on: 6/13/2016 *
 */

/*Importing Libraries*/
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

/*Major Function Prototype*/
int SecondStruct();
int Linked1();

/*----------------------------------------------------------------------*/
//First Question

/*Function Prototype*/
int demo_function(); /*Declare function prototype*/
void DisplayStats (); /*Declare function prototype */

struct person { /* "person" is name for structure type */
  char first[32]; /* first field of structure is array of char */
  char last[32]; /* second field is array of char */
  int year; /* third field is int */
  double ppg; /* fourth field is double */
}; /* ending ; means end of structure type definition */

int demo_function() {

  /*Declare structure*/
  struct person class[54]; /* array of "person" structs */

  /*Declare variables*/
  int i;

  /*Storing the variables in Array of Structrue*/
  //1
  class[0].year=2004; /* notice where array index/subscript goes */
  class[0].ppg=5.2;
  strcpy(class[0].first,"Jane");
  strcpy(class[0].last,"Doe");
  //2
  class[1].year=2005;
  class[1].ppg=4.9;
  strcpy(class[1].first,"Brian");
  strcpy(class[1].last,"Smith");
  //3
  class[2].year=2001;
  class[2].ppg=3.3;
  strcpy(class[2].first,"James");
  strcpy(class[2].last,"Bill");
  //4
  class[3].year=2008;
  class[3].ppg=4.2;
  strcpy(class[3].first,"Shao");
  strcpy(class[3].last,"John");
  //5
  class[4].year=2011;
  class[4].ppg=6.3;
  strcpy(class[4].first,"Chris");
  strcpy(class[4].last,"Mathew");
  //6
  class[5].year=1999;
  class[5].ppg=9.9;
  strcpy(class[5].first,"Simon");
  strcpy(class[5].last,"Yong");

  /*for loop*/
  /*Displaying all values*/
  for(i = 0; i < 6; i++)
    DisplayStats(class[i]); //Calling DisplayStats Function
}

/*DisplayStats Function*/
void DisplayStats(struct person Input) {
  printf("%s,\t%s:\t%lf\tPPG in %d\n", Input.last, Input.first, Input.ppg, Input.year); //Printing all values
}

/*SecondStruct Function*/
int SecondStruct() {

  struct person teacher;
  int i;
  /*Initializing the values in the struct with the
    "." syntax to get to each element of the struct*/
  teacher.year=2005;
  teacher.ppg=10.4;
  strcpy(teacher.first,"Adam");
  strcpy(teacher.last,"Hoover");
  demo_function();

  /*Finishing the Function*/
  return (0);

}


/*----------------------------------------------------------------------*/
//Second Question

/*Basic linked list example .. interactive*/
struct NODE {
  int number;
  struct NODE *next;
};

/*Declaring the prototypes for the functions we will use */
void append_node(struct NODE *llist, int num);
void delete_node(struct NODE *llist, int num);
int search_value(struct NODE *llist, int num);
void display_list(struct NODE *llist);

/*Linked1 Function*/
int Linked1() {

  int num = 0;
  int input = 1;
  int retval = 0;
  struct NODE *llist;

  /*Initializing the list using malloc and make sure we have one node
    and a pointer to the next node */
  /*NOTE: The "->" operator is how we address the two parts of our linked
    list "struct". This is called a structure dereference, but works like a pointer
    dereference. Remember, we are using “malloc” and a pointer to allocate more memory.
    It allows us to get "into" or reference any element within the structure.
    Below we are initializing the "number" component to "0" and the
    second component, which is the pointer to the next struct, is set to NULL.*/
  
  llist = (struct NODE *)malloc(sizeof(struct NODE));
  llist->number = 0;
  llist->next = NULL;
  /*Setup our menu system so we can make some basic changes to the nodes
    in our linked list*/
  while(input != 0) {
    printf("\n-- Menu Selection --\n");
    printf("0) Quit\n");
    printf("1) Insert\n");
    printf("2) Delete\n");
    printf("3) Search\n");
    printf("4) Display\n");
    scanf("%d", &input);
    switch(input) {
      /*Exit the menu gracefully */
    case 0:
      printf("Goodbye ...\n");
      input = 0;
      break;
      /*Insert a value by creating a node at the end of the list */
    case 1:
      printf("Your choice: 'Insertion'\n");
      printf("Enter the value which should be inserted: ");
      scanf("%d", &num);
      append_node(llist, num);
      break;
      /*Remove a value by removing the node with that value */
    case 2:
      printf("Your choice: 'Deletion'\n");
      printf("Enter the value which should be deleted: ");
      scanf("%d", &num);
      if((retval = search_value(llist, num)) == -1)
	printf("Value '%d' not found\n", num);
      else
	delete_node(llist, num);
      break;
      /*Search for a value, if not found, notify, if found
	state what node "position" it has in the list */
    case 3:
      printf("Your choice: 'Search'\n");
      printf("Enter the value you want to find: ");
      scanf("%d", &num);
      if((retval = search_value(llist, num)) == -1)
	printf("Value '%d' not found\n", num);
      else
	printf("Value '%d' located at position '%d'\n", num, retval);
      break;
      /*Display the current contents of the list */
    case 4:
      printf("You choice: 'Display'\n");
      display_list(llist);
      break;
      /*Catch all unmanaged input and return to menu */
    default:
      printf("That is not a valid menu option\n");
      break;
    } /*end of switch-case */
  } /*end of while loop */
  free(llist); /*BE SURE YOU FREE UP YOUR MALLOC when you are done!!! */
  
  /*Finishing the Function*/
  return(0);

}

/*All the functions that we proto-typed and then called from within our menu */
/*Add/append a node. Have to use malloc and have to "move" pointers */
void append_node(struct NODE *llist, int num) {
  while(llist->next != NULL)
    llist = llist->next;
  llist->next = (struct NODE *)malloc(sizeof(struct NODE));
  llist->next->number = num;
  llist->next->next = NULL;
}
/*Remove a node. Have to use a temp to store pointer if we find the node,
and have to "move" pointers. Note we have to deal with a node in the "middle"
differently than a node at the "end" DON'T FORGET TO "FREE" */
void delete_node(struct NODE *llist, int num) {
  struct NODE *temp;
  temp = (struct NODE *)malloc(sizeof(struct NODE));
  if(llist->number == num) {
    /* remove the node */
    temp = llist->next;
    free(llist); /*FREE UP THAT MEMORY!! */
    llist = temp;
  } else {
    while(llist->next->number != num)
      llist = llist->next;
    temp = llist->next->next;
    free(llist->next); /*FREE UP THAT MEMORY!! */
    llist->next = temp;
  }
}

/*Search for a node with a value using basic “while” loop and increments.*/
int search_value(struct NODE *llist, int num) {
  int retval = -1;
  int i = 1;
  while(llist->next != NULL) {
    if(llist->next->number == num)
      return i;
    else
      i++;
    llist = llist->next;
  }
  return retval;
}
/*Display the current contents of the list */
void display_list(struct NODE *llist) {
  while(llist->next != NULL) {
    printf("%d ", llist->number);
    llist = llist->next;
  }
  printf("%d", llist->number);
}


/*----------------------------------------------------------------------*/
//Main Function

/*main Function*/
int main() {

  /*Calling Functions*/
  SecondStruct(); //Calling SecondStruct Function
  Linked1(); //Calling Linked1 Function

  return 0;

}
