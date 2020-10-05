#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

/* Modify these two lines according to the project */
#include <intern and employee record system_operations.h>
#define PROJECT_NAME    "intern and employee record system"

/* Prototypes for all the test functions */
void test_Employee Data(void);
void test_Add Record(void);
void test_List Records(void);
void test_Modify Records(void);
void test_Delete Records(void);
void test_Intern Data(void);
void test_Add Record(void);
void test_List Records(void);
void test_Modify Records(void);
void test_Delete Records(void);
void test_Exit(void);
/* Start of the application test */
int main() {
/* Note: Do not edit START*/
  /*Initialize and setup the Test Framework */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();
  CU_pSuite suite = CU_add_suite(PROJECT_NAME, 0, 0);
/* Note: Do not edit END */
  
  
  /* Add your test functions in this format for testing*/
  CU_add_test(suite, "Employee Data", test_Employee Data);
  CU_add_test(suite, "Add Record", test_Add Record);
  CU_add_test(suite, "List Records", test_List Records);
  CU_add_test(suite, "Modify Records", test_Modify Records);
  CU_add_test(suite, "Delete Records", test_Modify Records);
  CU_add_test(suite, "Intern Data", test_Intern Data);
  CU_add_test(suite, "Add Record", test_Add Record);
  CU_add_test(suite, "List Records", test_List Records);
  CU_add_test(suite, "Modify Records", test_Modify Records);
  CU_add_test(suite, "Delete Records", test_Delete Records);
  CU_add_test(suite, "Exit", test_Exit);


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
void test_Employee Data(void) {
  CU_ASSERT(30 == Employee Data(10, 20));
  
  /* Dummy fail*/
  CU_ASSERT(1500 == Employee Data(750, 7500));
}

void test_Add Record(void) {
  CU_ASSERT(-3 == Add Record(0, 3));
  
  /* Dummy fail*/
  CU_ASSERT(1 == Add Record(1000, 900));
}

void test_List Records(void) {
  CU_ASSERT(0 == List Records(1, 0));
  
  /* Dummy fail*/
  CU_ASSERT(2 == List Records2, 5));
}

void test_Modify Records(void) {
  CU_ASSERT(0 == Modify Records(1, 0));
  
  /* Dummy fail*/
  CU_ASSERT(3 == Modify Records(2, 2));
}

void test_Delete Records(void) {
  CU_ASSERT(0 == Delete Records(1, 0));
  
  /* Dummy fail*/
  CU_ASSERT(3 == Delete Records(2, 2));
}

void test_Intern Data Records(void) {
  CU_ASSERT(0 ==Intern Data(1, 0));
  
  /* Dummy fail*/
  CU_ASSERT(3 == Intern Data(2, 2));
}

void test_Add Record(void) {
  CU_ASSERT(0 == Add Record(1, 0));
  
  /* Dummy fail*/
  CU_ASSERT(3 == Add Record(2, 2));
}

void test_List Records(void) {
  CU_ASSERT(0 == List Records(1, 0));
  
  /* Dummy fail*/
  CU_ASSERT(3 == List Records(2, 2));
}

void test_Modify Records(void) {
  CU_ASSERT(0 == Modify Records(1, 0));
  
  /* Dummy fail*/
  CU_ASSERT(3 == Modify Records(2, 2));
}

void test_Delete Records(void) {
  CU_ASSERT(0 == Delete Records(1, 0));
  
  /* Dummy fail*/
  CU_ASSERT(3 == Delete Records(2, 2));
}

void test_Exit Records(void) {
  CU_ASSERT(0 == Exit(1, 0));
  
  /* Dummy fail*/
  CU_ASSERT(3 == Exit(2, 2));
}

