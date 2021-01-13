/**
* @file phonebook_operations.cpp
* phonebook application with 5 operations
*
*/
#include <iostream> //<stdio.h>
#include <cstring> //<string.h>
#include <ios>
#include <limits>
#include <phoneheader.h>

using namespace std;

record::record(string f_name,string l_name,string gen,string email,long long phone)
{
		first_name=f_name;
		last_name=l_name;
		gender=gen;
		phone_number=phone;
		email_id=email;
}



//Listing the contact
int record::listing(int no)
{
    //Checking if contacts exist
    if(no==0)
    {
        cout<<"\n\nNO Contacts to display!!!\n\n";
        return(-1);
    }
    else
    {
        //Printing the contacts
        for(int i=0;i<no;i++)
        {
            cout<<"\n\nDetails of the contact \n"<<i+1;
            display(i);
        }
        return(1);
    }
}

//Adding a new contact
int record::adding(int no,string *f_name)
{
	if(no==MAX_CONTACTS)
	{
		cout<<"\nDatabase is full...!!\n";
		return(no);
	}
    int found_flag=searches(no,f_name);
    if(found_flag!=-1)
    {
        cout<<"Contact with first name"<<contact[found_flag]->first_name<<" already existed..!";
        cout<<"\nDetails of the contact with name "<<contact[found_flag]->first_name;
        display(found_flag);
        return(no);
    }
    contact[no]= new records;
    (contact[no]->first_name)=(*f_name);
    enter(no); // function to enter input
    no++;
    cout<<"\nContact added successfully.....";
    sort_contacts(no);
    return(no);
}

//deleting a contact
int record::deleting(int no,string *f_name)
{
    if(no==0)
    {
        cout<<"\n No contacts in the database....!!";
        return(no);
    }
    int found_flag=searches(no,f_name);
    if(found_flag!=-1)
    {
        cout<<"The contact details of "<<(*f_name);
        display(found_flag);
        //to prompt user to delete or not
        /*char s[1];
        cout<<"\nDo you want to delete this contact(Y/N):");
        scanf("%1s",s);
        string_upper(s);
        if(!(strcmp(s,"Y")==0))
        {
            cout<<"\nContact not deleted");
            return(no);
        }*/
        delete contact[found_flag];
        for(int i=found_flag;i<no-1;i++)
        {
            contact[i]=contact[i+1];
        }
        no--;
        cout<<"\nContact deleted successfully.....\n";
        return(no);
    }
    else
    {
        //if contact not found then program will print the below statement
        cout<<"\nContact with name "<<f_name<<" NOT found...!!!";
        return(no);
    }
}


//Modifying the contact
int record::modifying(int no,string *f_name)
{
    if(no==0)
    {
        cout<<"\n No contacts in the database....!!";
        return(-1);
    }

    int found_flag=searches(no,f_name);
    //if contact found then program will print the below statement
    if(found_flag!=-1)
    {
        cout<<"\nThe existing details of the contact:"<<(*f_name);
        display(found_flag);
        cout<<"\n--------------------\n";
        cout<<"\n\n---Enter the new details of the contact---";
        cout<<"\nEnter first name:";
        cin>>(contact[found_flag]->first_name);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string_upper(&(contact[found_flag]->first_name));
        enter(found_flag);
        cout<<"\nContact modified successfully.....";
        sort_contacts(no);
        return(1);
    }
    //if contact not found then program will print the below statement
    else
    {
        cout<<"\nContact with name "<<(*f_name)<<" NOT found...!!!";
        return(0);
    }
}

//Searching a contact
int record::searching(int no,string *f_name)
{
   if(no==0)
    {
        cout<<"\n No contacts in the database....!!";
        return(-1);
    }
    int found_flag=searches(no,f_name);
    if(found_flag!=-1)
    {
        cout<<"\nContact with first name "<<(*f_name)<<" is found at position "<<found_flag+1;
        display(found_flag);
        return(1);
    }
    else
    {
        //if contact not found then program will print the below statement
        cout<<"\nContact with name "<<(*f_name)<<" NOT found...!!!";
        return(0);
    }

}

//extra functions to optimize the code

//Searching a contact with name and returning index
int record::searches(int no,string *f_name)
{
    if(no==0)
    {
        return(-1);
    }
    for(int i=0;i<no;i++)
    {
        if((*f_name).compare(contact[i]->first_name)==0)
        {
            return(i);
        }
    }
    return(-1);
}

//displaying the contact information
void record::display(int n)
{
    cout<<"\nNAME: "<<contact[n]->first_name<<" "<<contact[n]->last_name;
    fflush(stdin);
    cout<<"\nPhone number: "<<contact[n]->phone_number;
    fflush(stdin);
    cout<<"\nGender:"<<contact[n]->gender;
    fflush(stdin);
    cout<<"\nEmail ID: "<<contact[n]->email_id;
    fflush(stdin);
}

//Enter the contact information
void record::enter(int n)
{
   cout<<"\nEnter last name:";
   cin>>(contact[n]->last_name);
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   string_upper(&(contact[n]->last_name));
   cout<<"\nEnter phone number:";
   cin>>(contact[n]->phone_number);
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   cout<<"\nEnter Gender(M/F):";
   cin>>(contact[n]->gender);
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   string_upper(&(contact[n]->gender));
   cout<<"\nEnter Email ID:";
   cin>>(contact[n]->email_id);
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// To convert string to upper case
void record::string_upper(string *str1)
{
    for(int i=0;(*str1)[i]!='\0';i++)
    {
        if( ((*str1)[i]>=97) && ((*str1)[i]<=122))
        {
            (*str1)[i]=(*str1)[i]-32;
        }
    }
}

///To sort the contacts in lexicographical order

void record::sort_contacts(int no)
{
    records *temp;
    for(int i=0;i<no-1;i++)
    {
        for(int j=i+1;j<no;j++)
        {
            if(( (contact[i]->first_name).compare(contact[j]->first_name)) >0)
            {
                temp=contact[i];
                contact[i]=contact[j];
                contact[j]=temp;
            }
        }
    }
}
