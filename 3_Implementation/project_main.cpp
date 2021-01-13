/**
* @file project_main.cpp
* main C++ file of the program.
* Flowchart of project_main.c
* \image html main.jpg
*/

#include <iostream> 
#include <string> 
#include <ios>
#include <limits>
#include<cstring>
#include <phoneheader.h>

using namespace std;

/// Global variable to store total no of contacts.Initially no contacts.
int no_of_contacts=0;

// Database to store contacts->array pointers of structure record.(extern)
 records *contact[MAX_CONTACTS];


//main function

/**
 * This is the main function \n
 * It will take the choice from the user to select the option in the Menu and proceeds to switch statement. \n
 * Switch statement selects the case according to the choice and calls the respective function.
*/
int main()
{
    int choice;
    string f_name;
	records r1("a","b","a","av",0);
    cout<<"\t\t\t\t-------------PHONEBOOK MANAGEMENT SYSTEM---------------\n\n\n\n";
first: cout<<"\t\t\t\tList of operations\n\n";
       cout<<"\t 1)LIST THE RECORDS \t 2)ADD A RECORD \t 3)DELETE A RECORD \n \t 4)MODIFY A RECORD \t 5)SEARCH A RECORD \t 6)EXIT";
       cout<<"\n\nEnter your choice:";
       cin>>choice;  //scanf("%d",&choice);
       switch(choice)
       {
          case 1: cout<<"-----------Listing the contacts-----------";
                  r1.listing(no_of_contacts);
                  break;
          case 2: cout<<"-----------Adding a contact-------------";
                  cout<<"\nEnter first name:";
                  cin>>f_name; //scanf("%29s",f_name);//input string
                  r1.string_upper(&f_name);
                  no_of_contacts=r1.adding(no_of_contacts,&f_name);
                  break;
          case 3: cout<<"-----------Deleting a contact--------------------";
                  cout<<"\nEnter the first name of the contact to be deleted:";
                  cin>>f_name; //scanf("%29s",f_name);
                  r1.string_upper(&f_name);
                  no_of_contacts=r1.deleting(no_of_contacts,&f_name);
                  break;
          case 4: cout<<"Modifying";
                  cout<<"\nEnter the first name of the contact to be modified:";
                  cin>>f_name; //scanf("%29s",f_name);
                  r1.string_upper(&f_name);
                  r1.modifying(no_of_contacts,&f_name);
                  break;
          case 5: cout<<"Searching";
                  cout<<"\nEnter the first name of the contact to be searched:";
                  cin>>f_name;//scanf("%29s",f_name);
                  r1.string_upper(&f_name);
                  r1.searching(no_of_contacts,&f_name);
                  break;
          case 6: cout<<"exit";
                  exit(0);
                  for(int i=0;i<no_of_contacts;i++)
                  {
                      delete contact[i];
                  }
                  return(0);
         default: cout<<"\n\nWrong choice!!!!->please enter between 1 to 6\n\n";
                  goto first;//return to enter choice
      }
	  cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout<<"\n\nPress any key to continue to Menu\n";
	  //fflush(stdin); //for windows
	  //__fpurge(stdin); //for linux
	  cin.get(); //getc; //getchar();
      goto first;
      return 1;
}
