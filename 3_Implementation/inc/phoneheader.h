/**
* @file phoneheader.h
* Phonebook header file. This header file contains definitions of all the functions. \n Structure is defined to store contact deatils. \n Array pointers of structure is defined to store address of the each contact.
*
*/
#ifndef PHONEHEADER_H_INCLUDED
#define PHONEHEADER_H_INCLUDED
#include <iostream> 
#include<string>
#include <ios>
#include <limits>
#include<cstring>
///Maximum number of contacts that can be stored
#define MAX_CONTACTS 100

using namespace std;


///To store each contact,class is defined with required fields.

class record
{
	///To store first name
    string first_name;
    ///To store last name
    string last_name;
    ///To store gender
    string gender;
    ///To store email id
    string email_id;
    ///To store phone number
    long long phone_number;
	public:
			//constructer
			/**
			*  Constructor to initialize data members in the contact.\n
			*  @param[in] f_name First name of the contact.
			*  @param[in] l_name Last name of the contact.
			*  @param[in] gen Gender of the contact.
			*  @param[in] email Email id of the contact.
			*/
			 record(string f_name="",string l_name="",string gen="",string email="",long long phone=0);
			
			
			// functions declarations

			/**
			*  Lists all the contacts in the database.
			*  Lists all the contacts stored in the database with their respective contact details.
			*  @param[in] no -> Total no of contacts in the database.
			*  @return 1-> All contacts listed successfully. \n
			*          -1-> NO contacts in the database.
			* \n Flowchart of Listing function
			* \image html listing.jpg
			*/
			int listing(int no);
			/**
			*  Adds a contact to the database \n
			*  First it searches for the contact in the database using the name entered by the user.if it's not found then add it to the database.
			*  Add new contacts with information-> \n
			*  1)Name: First Name and Second Name \n
			*  2)Phone number \n
			*  3)Gender \n
			*  4)Email
			*  @param[in] no total no of contacts in the database
			*  @param[in] f_name First name of the contact to be added.
			*  @return Total no of contacts after adding.
			* \n Flowchart of Adding function
			* \image html adding.jpg
			*/
			 int adding(int no,string *f_name);

			/**
			*  Deletes a contact in the database.\n
			*  First it searches for the contact in the database using the name entered by the user.if it's found then delete it from the database.
			*  @param[in] no total no of contacts in the database
			*  @param[in] f_name First name of the contact to be deleted.
			*  @return Total no of contacts after deleting.
			* \n \b Flowchart \b of  \b Deleting \b function. 
			* \image html deleting.jpg
			*/
			 int deleting(int no,string *f_name);

			/**
			*  Modifies a contact in the database
			*  Edit the information given while adding the contacts -> \n
			*  1)Name: First Name and Second Name \n
			*  2)Phone number \n
			*  3)Gender \n
			*  4)Email
			*  @param[in] no ->Total no of contacts in the database
			*  @param[in] f_name ->First name of the contact to be modified.
			*  @return 1->if contact is successfully modified.\n  0->if contact with similar name not found
			*  @note returns -1 if no contacts in the database.
			* Flowchart of Modifying function
			* \image html modifying.jpg
			*/
			 int modifying(int no,string *f_name);

			/**
			*  searches a contact in the database
			* @param[in] no ->Total no of contacts in the database
			* @param[in] f_name ->first name of the contact
			* @return Index of the contact if it exists.
			* @note returns -1 if contact does not exist or NO contacts in the database.
			* \image html searches.jpg
			*/
			 int searches(int no,string *f_name);

			/**
			*  Searches a contact in the database \n
			*  @param[in] no -> Total no of contacts in the database
			*  @param[in] f_name -> First name of the contact to be searched.
			*  Inputs the first name and sent to searches function. \n
			*  If contact is found then print its details.
			*  @return 1->if contact exists.\n 0->if conatct does not exists.
			*  @note Returns -1 if NO contacts in the database.
			* Flowchart of Searching function
			* \image html searching.jpg
			*/
			 int searching(int no,string *f_name);

			/**
			*  prints the contact details at the index operand1.
			*  displays the following information of the contacts -> \n
			*  1)Name: First Name and Second Name \n
			*  2)Phone number \n
			*  3)Gender \n
			*  4)Email
			* @param[in] operand1 .
			* Flowchart of display function
			* \image html display.jpg
			*/
			 void display(int operand1);

			/**
			* Takes the inputs and store the contact at the index operand1.
			*It is used by adding and modifying function to take the input from user.
			* @param[in] operand1 .
			* Flowchart of Enter function
			* \image html enter.jpg
			*/
			 void enter(int operand1);

			/**
			* Converts all the alphabetical characters in the string st1  to uppercase.
			* @param[in] st1 string is converted to upper case.
			* \image html string_upper.jpg
			*/
			 void string_upper(string *st1);

			/**
			*  Sort the contacts in the database according to the name.
			*  Contacts are sorted in lexicographical order.
			*  @param[in] no Total no of contacts in the database
			* \image html sort_contacts.jpg
			*/
			 void sort_contacts(int no);
};


///Using typedef to create additional name to record structure.
typedef record records;

// Database to store contacts->array pointers of structure record.(extern)
extern records *contact[MAX_CONTACTS];



#endif // PHONEHEADER_H_INCLUDED /* #define __PHONE_H__ */
