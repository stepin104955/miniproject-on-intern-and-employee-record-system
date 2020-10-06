#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

#include <intern_and_employee_record_system_operations.h>
#define PROJECT_NAME    "intern_and_employee_record_system"

/* Prototypes for all the test functions */
void test_EmployeeData(void);
void test_Addemployee(void);
void test_Viewallemployees(void);
void test_Modifyemployee(void);
void test_Deleteemployee(void);
void test_InternData(void);
void test_Addintern(void);
void test_Viewallinterns(void);
void test_Modifyintern(void);
void test_Deleteintern(void);
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
  CU_add_test(suite, "Employee Data", test_EmployeeData);
  CU_add_test(suite, "Add employee", test_Addemployee);
  CU_add_test(suite, "View all employees", test_Viewallemployees);
  CU_add_test(suite, "Modify employee", test_Modifyemployee);
  CU_add_test(suite, "Delete employee", test_Deleteemployee);
  CU_add_test(suite, "Intern Data", test_InternData);
  CU_add_test(suite, "Add intern", test_Addintern);
  CU_add_test(suite, "View all interns", test_viewallinterns);
  CU_add_test(suite, "Modify Intern", test_Modifyintern);
  CU_add_test(suite, "Delete Intern", test_Deleteintern);
  CU_add_test(suite, "Exit", test_Exit);

  CU_basic_set_mode(CU_BRM_VERBOSE);
  
  CU_basic_run_tests();
  
  CU_cleanup_registry();

  return 0;
}

/* Write all the test functions */ 
void test_EmployeeData(void) {
  CU_ASSERT(30 == EmployeeData(10, 20));
  
  /* Dummy fail*/
  CU_ASSERT(1500 == EmployeeData(750, 7500));
}

void test_Addemployee(void){
  CU_ASSERT(-3 == Addemployee(0,3));
  
  /* Dummy fail*/
  CU_ASSERT(1 == Addemployee(1000,900));
}

void test_viewallemployees(void){
  CU_ASSERT(0 ==viewallemployees(0,1));
  
  /* Dummy fail*/
  CU_ASSERT(0 ==viewallemployees(2,5));
}

void test_Modifyemployee(void) {
  CU_ASSERT(0 == Modifyemployee(1, 0));
  
  /* Dummy fail*/
  CU_ASSERT(3 == Modifyemployee(2, 2));
}

void test_Deleteemployee(void) {
  CU_ASSERT(0 == Deleteemployee(1, 0));
  
  /* Dummy fail*/
  CU_ASSERT(3 == Deleteemployee(2, 2));
}

void test_InternData(void) {
  CU_ASSERT(0 ==InternData(1, 0));
  
  /* Dummy fail*/
  CU_ASSERT(3 == InternData(2, 2));
}

void test_Addintern(void) {
  CU_ASSERT(0 == Addintern(1, 0));
  
  /* Dummy fail*/
  CU_ASSERT(3 == Addintern(2, 2));
}

void test_viewallinterns(void){
  CU_ASSERT(0 ==viewallinterns(1,0));
  
  /* Dummy fail*/
  CU_ASSERT(0 ==viewallinterns(1,0));
}

void test_Modifyintern(void) {
  CU_ASSERT(0 == Modifyintern(1, 0));
  
  /* Dummy fail*/
  CU_ASSERT(3 == Modifyintern(2, 2));
}

void test_Deleteintern(void) {
  CU_ASSERT(0 == Deleteintern(1, 0));
  
  /* Dummy fail*/
  CU_ASSERT(3 == Deleteintern(2, 2));
}

void test_Exit(void) {
  CU_ASSERT(0 == Exit(1, 0));
  
  /* Dummy fail*/
  CU_ASSERT(3 == Exit(2, 2));
}

