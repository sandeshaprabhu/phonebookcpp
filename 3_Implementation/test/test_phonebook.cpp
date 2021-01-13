/**
* @file test_phonebook.cpp
* phonebook application with 5 operations for testing
*
*/
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <iostream>
#include<cstring>
/* Modify these two lines according to the project */
#include <phoneheader.h>
#define PROJECT_NAME    "phonebook"

// Database to store contacts->array pointers of structure record.(extern)
records *contact[MAX_CONTACTS];
records r1;



/* Prototypes for all the test functions */
void test_listing(void);
void test_adding(void);
void test_deleting(void);
void test_modifying(void);
void test_searching(void);

/* Start of the application test */
int main() {
/* Note: Do not edit START*/
  /*Initialize and setup the Test Framework */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();
  CU_pSuite suite = CU_add_suite(PROJECT_NAME, 0, 0);
/* Note: Do not edit END */
  
  
  /* Add your test functions in this format for testing*/
  CU_add_test(suite, "listing", test_listing);
  CU_add_test(suite, "adding", test_adding);
  CU_add_test(suite, "deleting", test_deleting);
  CU_add_test(suite, "modifying", test_modifying);
  CU_add_test(suite, "searching", test_searching);


/* Note: Do not edit START*/
  /* Setup Test Framework to output the result to Screen */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  
  /* run the unit test framework*/
  CU_basic_run_tests();
  
  /* Cleaning the Resources used by Unit test framework */
  CU_cleanup_registry();
/* Note: Do not edit END */
  return 0;
}

/* Write all the test functions */ 
//test listing without adding a contact
void test_listing(void) 
{
   int no=0;
  CU_ASSERT(-1 == r1.listing(no));
  
  //* Dummy fail*/
  CU_ASSERT(-1 == r1.listing(0));
}

//testing adding with same name
void test_adding(void) 
{
   int no=3;
   contact[0]=new records("RAM","K","m","ramk@gmail.com",9876543210);
   contact[1]=new records("sham","r","m","shamr@gmail.com",9456780123);
   contact[2]=new records("bham","s","m","bhams@gmail.com",9873216540);
   /*for(int i=0;i<no;i++)
   {
       contact[i]= new records;
   }
   //first contact
   strcpy(contact[0]->first_name,"ram");
   strcpy(contact[0]->last_name,"k");
   strcpy(contact[0]->gender,"m");
   contact[0]->phone_number=9876543210;
   strcpy(contact[0]->email_id,"ramk@gmail.com");

   //second contact
   strcpy(contact[1]->first_name,"sham");
   strcpy(contact[1]->last_name,"r");
   strcpy(contact[1]->gender,"m");
   contact[1]->phone_number=9874563210;
   strcpy(contact[1]->email_id,"shamr@gmail.com");

   //third contact
   strcpy(contact[2]->first_name,"bham");
   strcpy(contact[2]->last_name,"s");
   strcpy(contact[2]->gender,"m");
   contact[2]->phone_number=9873216540;
   strcpy(contact[2]->email_id,"bhams@gmail.com");*/
	
	std::string st("RAM");
	
  CU_ASSERT(3 == r1.adding(no,&st));
  
  st="bham";
  //* Dummy fail*/
  CU_ASSERT(3 == r1.adding(no,&st));
  //freed allocated space
  for(int i=0;i<no;i++)
   {
       delete contact[i];
   }
}

void test_deleting(void)
{
	int no=3;
   contact[0]=new records("ram","k","m","ramk@gmail.com",9876543210);
   contact[1]=new records("sham","r","m","shamr@gmail.com",9456780123);
   contact[2]=new records("bham","s","m","bhams@gmail.com",9873216540);
   /*for(int i=0;i<no;i++)
   {
       contact[i]= new records;
   }
   //first contact
   strcpy(contact[0]->first_name,"ram");
   strcpy(contact[0]->last_name,"k");
   strcpy(contact[0]->gender,"m");
   contact[0]->phone_number=9876543210;
   strcpy(contact[0]->email_id,"ramk@gmail.com");

   //second contact
   strcpy(contact[1]->first_name,"sham");
   strcpy(contact[1]->last_name,"r");
   strcpy(contact[1]->gender,"m");
   contact[1]->phone_number=9874563210;
   strcpy(contact[1]->email_id,"shamr@gmail.com");

   //third contact
   strcpy(contact[2]->first_name,"bham");
   strcpy(contact[2]->last_name,"s");
   strcpy(contact[2]->gender,"m");
   contact[2]->phone_number=9873216540;
   strcpy(contact[2]->email_id,"bhams@gmail.com");*/
   
   std::string st("sham");
   
  CU_ASSERT(2 == r1.deleting(no,&st));
  
  //* Dummy fail*/
  st="laxman";
  CU_ASSERT(2 == r1.deleting(2,&st));
  delete contact[0];
  delete contact[1];
}

void test_modifying(void) 
{
	int no=3;
   contact[0]=new records("ram","k","m","ramk@gmail.com",9876543210);
   contact[1]=new records("sham","r","m","shamr@gmail.com",9456780123);
   contact[2]=new records("bham","s","m","bhams@gmail.com",9873216540);
   /*int no=3;
   for(int i=0;i<no;i++)
   {
       contact[i]= new records;
   }
   //first contact
   strcpy(contact[0]->first_name,"ram");
   strcpy(contact[0]->last_name,"k");
   strcpy(contact[0]->gender,"m");
   contact[0]->phone_number=9876543210;
   strcpy(contact[0]->email_id,"ramk@gmail.com");

   //second contact
   strcpy(contact[1]->first_name,"sham");
   strcpy(contact[1]->last_name,"r");
   strcpy(contact[1]->gender,"m");
   contact[1]->phone_number=9874563210;
   strcpy(contact[1]->email_id,"shamr@gmail.com");

   //third contact
   strcpy(contact[2]->first_name,"bham");
   strcpy(contact[2]->last_name,"s");
   strcpy(contact[2]->gender,"m");
   contact[2]->phone_number=9873216540;
   strcpy(contact[2]->email_id,"bhams@gmail.com");*/
    std::string st("laxman");
   
  CU_ASSERT(0 == r1.modifying(no,&st));
  
  //* Dummy fail*/
  st="bharath";
  CU_ASSERT(0 == r1.modifying(3,&st));
  
  for(int i=0;i<no;i++)
   {
       delete contact[i];
   }
}

void test_searching(void) 
{
   int no=3;
   contact[0]=new records("ram","k","m","ramk@gmail.com",9876543210);
   contact[1]=new records("sham","r","m","shamr@gmail.com",9456780123);
   contact[2]=new records("bham","s","m","bhams@gmail.com",9873216540);
   /*int no=3;
   for(int i=0;i<no;i++)
   {
       contact[i]=new records;
   }
   //first contact
   strcpy(contact[0]->first_name,"ram");
   strcpy(contact[0]->last_name,"k");
   strcpy(contact[0]->gender,"m");
   contact[0]->phone_number=9876543210;
   strcpy(contact[0]->email_id,"ramk@gmail.com");

   //second contact
   strcpy(contact[1]->first_name,"sham");
   strcpy(contact[1]->last_name,"r");
   strcpy(contact[1]->gender,"m");
   contact[1]->phone_number=9874563210;
   strcpy(contact[1]->email_id,"shamr@gmail.com");

   //third contact
   strcpy(contact[2]->first_name,"bham");
   strcpy(contact[2]->last_name,"s");
   strcpy(contact[2]->gender,"m");
   contact[2]->phone_number=9873216540;
   strcpy(contact[2]->email_id,"bhams@gmail.com");*/
   
    std::string st("ram");
  CU_ASSERT(1 == r1.searching(no,&st));
  
  //* Dummy fail*/
  st="laxman";
  CU_ASSERT(0 == r1.searching(no,&st));
  
  for(int i=0;i<no;i++)
   {
       delete contact[i];
   }
}