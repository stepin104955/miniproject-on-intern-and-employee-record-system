#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct _employee {
	int id;
	char name[50];
	char mailID[50];
	char phone[15];
	char Organization[50];
	float salary;
};

struct _intern {
	int id;
	char name[50];
	char mailID[50];
	char phone[15];
	char Organization[50];
	float salary;
};

typedef struct _employee EMPLOYEE;
typedef struct _intern INTERN;


void display_title (void);
void welcome (void);
void main_menu (void);
void error (const char* error_msg);

/* For employee*/
char* getstr (char* string, int size, FILE* file_ptr);
int no_of_records (FILE* file, int element_size);
char* strcase (char* string, int flag);
int emp_cmp (const void *e1, const void *e2);

/*For intern*/
char* getstr (char* string, int size, FILE* file_ptr1);
int no_of_records (FILE* file1, int element_size);
int intern_cmp (const void *in1, const void *in2);

void add_employee (void);  /*For employee*/
void search_employee_by_id (int id);
void modify_employee (int id);
void delete_employee (int id);
void view_employees (void);

void add_intern (void);   /*For intern*/
void search_intern_by_id (int id);
void modify_intern (int id);
void delete_intern (int id);
void view_interns (void);

int main (void)
{
	display_title();


	printf("\nPress [Enter] key to enter the program.\n");
	getchar();

	main_menu();

	return 0;
}

void display_title (void)
{
	printf("================================================================\n");
	printf("INTERN AND EMPLOYEE RECORD SYSTEM\n");
	printf("================================================================\n\n");
}


void main_menu (void) {
	char temp[100];
	int id, choice,choice1;

	display_title();

	printf("MAIN MENU\n"
           "-----------------------------\n"
           "   1.  Employee Data \n"
           "   2.  Intern Data \n"
           "   3.  Exit \n"
           "   Enter your choice \n");

    getstr(temp, 100, stdin);
	choice1 = strtol(temp, NULL, 10);
	printf("\n");

	switch(choice1){
           case 1:

                    printf("%s",
                                "\n"
                                "MAIN MENU \n"
                                "----------------------------- \n"
                                "   1.  View all employees \n"
                                "   2.  Add employee \n"
                                "   3.  Modify employee \n"
                                "   4.  Delete employee \n"
                                "   5.  Exit \n"
                                "\n"
                                "       Enter your choice: ");

                                getstr(temp, 100, stdin);
                                choice = strtol(temp, NULL, 10);
                                printf("\n");

                                switch (choice) {
                                    case 1: view_employees(); break;
                                    case 2: add_employee(); break;
                                    case 3:
                                            printf("Enter ID to modify: ");
                                            id = strtol(getstr(temp, 100, stdin), NULL, 10);
                                            modify_employee(id);
                                            break;
                                    case 4:
                                            printf("Enter ID to delete: ");
                                            id = strtol(getstr(temp, 100, stdin), NULL, 10);
                                            delete_employee(id);
                                            break;
                                            case 5: exit(0); break;
                                            default:  main_menu();
                                                }
            case 2:

                    printf("%s",
                                "\n"
                                "MAIN MENU \n"
                                "----------------------------- \n"
                                "   1.  View all interns \n"
                                "   2.  Add intern \n"
                                "   3.  Modify intern \n"
                                "   4.  Delete intern \n"
                                "   5.  Exit \n"
                                "\n"
                                "       Enter your choice: ");

                                getstr(temp, 100, stdin);
                                choice = strtol(temp, NULL, 10);
                                printf("\n");

                                switch (choice) {
                                    case 1: view_interns(); break;
                                    case 2: add_intern(); break;
                                    case 3:
                                            printf("Enter ID to modify: ");
                                            id = strtol(getstr(temp, 100, stdin), NULL, 10);
                                            modify_intern(id);
                                            break;
                                    case 4:
                                            printf("Enter ID to delete: ");
                                            id = strtol(getstr(temp, 100, stdin), NULL, 10);
                                            delete_intern(id);
                                            break;
                                            case 5: exit(0); break;
                                            default:  main_menu();
                                                }

        case 3:exit(0);break;

}
}
void error(const char* error_msg) {
	system("clear");
	display_title();

	printf("ERROR: %s \n", error_msg);
	printf("\n");
	printf("Press [Enter] to goto Main Menu\n");
	getchar();
	main_menu();
}

void add_employee (void)  /*For employee*/
{
	char temp[100];
	FILE* file = NULL;

	system("clear");
	display_title();

	EMPLOYEE e;

	printf("ID              : "); getstr(temp, 100, stdin);
	e.id = strtol(temp, NULL, 10);
	printf("Name            : "); getstr(e.name, 100, stdin);
	printf("MailID          : "); getstr(e.mailID, 100, stdin);
	printf("Phone No.       : "); getstr(e.phone, 100, stdin);
	printf("Organization    : "); getstr(e.Organization, 100, stdin);
	printf("Monthly Salary  : "); getstr(temp, 100, stdin);
	e.salary = strtof(temp, NULL);
	printf("\n");

	file = fopen("records.data", "ab+");
	if (!file) {
		error("Couldn't open the data file!");
	}

	EMPLOYEE e2;
	int same_id_found = 0;
	rewind(file);
	while (!feof(file)) {
		fread(&e2, sizeof(e2), 1, file);
		if (e.id == e2.id) {
			same_id_found = 1;
			break;
		}
	}

	if (same_id_found) {
		fclose(file);
		error("There's already a record with that ID!");
	}

	fseek(file, 0, SEEK_END);
	fwrite(&e, sizeof(e), 1, file);

	printf("Record added succesfully! \n");
	printf("\n");
	printf("Press [Enter] key to goto Main Menu \n");
	getchar();
	fclose(file);
	main_menu();
}


void add_intern (void)  /*For intern*/
{
	char temp[100];
	FILE* file1 = NULL;

	system("clear");
	display_title();

	INTERN in;

	printf("ID              : "); getstr(temp, 100, stdin);
	in.id = strtol(temp, NULL, 10);
	printf("Name            : "); getstr(in.name, 100, stdin);
	printf("MailID          : "); getstr(in.mailID, 100, stdin);
	printf("Phone No.       : "); getstr(in.phone, 100, stdin);
	printf("Organization    : "); getstr(in.Organization, 100, stdin);
	printf("Monthly Salary  : "); getstr(temp, 100, stdin);
	in.salary = strtof(temp, NULL);
	printf("\n");

	file1 = fopen("records1.data", "ab+");
	if (!file1) {
		error("Couldn't open the data file!");
	}

	INTERN i2;
	int same_id_found = 0;
	rewind(file1);
	while (!feof(file1)) {
		fread(&i2, sizeof(i2), 1, file1);
		if (in.id == i2.id) {
			same_id_found = 1;
			break;
		}
	}

	if (same_id_found) {
		fclose(file1);
		error("There's already a record with that ID!");
	}

	fseek(file1, 0, SEEK_END);
	fwrite(&in, sizeof(in), 1, file1);

	printf("Record added succesfully! \n");
	printf("\n");
	printf("Press [Enter] key to goto Main Menu \n");
	getchar();
	fclose(file1);
	main_menu();
}

void search_employee_by_id (int id) /*for employee*/
{
	system("clear");
	display_title();

	FILE* file = fopen("records.data", "rb");
	if (!file) {
		error("Couldn't open the data file!");
	}

	EMPLOYEE e;
	int n = no_of_records(file, sizeof(e));

	int i, found = 0;
	for (i=0; i<n; i++) {
		fread(&e, sizeof(e), 1, file);
		if (e.id == id) {
			found = 1;
			break;
		}
	}

	if (!found) {
		fclose(file);
		error("The given ID doesn't match any records!");
	}

	printf("   ID           : %d \n", e.id);
	printf("   Name         : %s \n", e.name);
	printf("   mailID       : %s \n", e.mailID);
	printf("   Phone no.    : %s \n", e.phone);
	printf("   Organization : %s \n", e.Organization);
	printf("   Salary       : %.2f per month \n", e.salary);
	printf("\n");
	printf("Press [Enter] to goto Main Menu\n");
	getchar();
	fclose(file);
	main_menu();
}

void search_intern_by_id (int id) /*for intern*/
{
	system("clear");
	display_title();

	FILE* file1 = fopen("records1.data", "rb");
	if (!file1) {
		error("Couldn't open the data file!");
	}

	INTERN in;
	int n = no_of_records(file1, sizeof(in));

	int i, found = 0;
	for (i=0; i<n; i++) {
		fread(&in, sizeof(in), 1, file1);
		if (in.id == id) {
			found = 1;
			break;
		}
	}

	if (!found) {
		fclose(file1);
		error("The given ID doesn't match any records!");
	}

	printf("   ID           : %d \n", in.id);
	printf("   Name         : %s \n", in.name);
	printf("   mailID       : %s \n", in.mailID);
	printf("   Phone no.    : %s \n", in.phone);
	printf("   Organization : %s \n", in.Organization);
	printf("   Salary       : %.2f per month \n", in.salary);
	printf("\n");
	printf("Press [Enter] to goto Main Menu\n");
	getchar();
	fclose(file1);
	main_menu();
}

void modify_employee (int id) /*For intern*/
{
	char temp[100];
	system("clear");
	display_title();

	FILE* file = fopen("records.data", "r");

	if (!file) {
		error("Couldn't open the data file!");
	}

	int n = no_of_records(file, sizeof(EMPLOYEE));
	EMPLOYEE *e_all = calloc(n, sizeof(EMPLOYEE));

	fread(e_all, sizeof(EMPLOYEE), n, file);

	fclose(file);



	int found=0, index, i;
	for (i=0; i<n; i++) {
		if (e_all[i].id == id) {
			found = 1;
			index = i;
			break;
		}
	}

	if (!found) {
		free(e_all);
		error("The given ID doesn't match any records!");
	}

	printf("CURRENT DETAILS: \n");
	printf("   ID           : %d \n", e_all[index].id);
	printf("   Name         : %s \n", e_all[index].name);
	printf("   mailID       : %s \n", e_all[index].mailID);
	printf("   Phone        : %s \n", e_all[index].phone);
	printf("   Organization : %s \n", e_all[index].Organization);
	printf("   Salary       : %.2f \n", e_all[index].salary);
	printf("\n");

	printf("NEW DETAILS: \n");
	printf("   ID           : %d \n", e_all[index].id);
	printf("   Name         : "); getstr(e_all[index].name, 100, stdin);
	printf("   mailID       : "); getstr(e_all[index].mailID, 100, stdin);
	printf("   Phone        : "); getstr(e_all[index].phone, 100, stdin);
	printf("   Organization : "); getstr(e_all[index].Organization, 100, stdin);
	printf("   Salary       : "); e_all[index].salary = strtof(getstr(temp, 100, stdin), NULL);

	file = fopen("records.data", "wb");
	fwrite(e_all, sizeof(EMPLOYEE), n, file);
	free(e_all);
	fclose(file);
	printf("\n");
	printf("Record successfully updated! \n");
	printf("\n");
	printf("Press [Enter] to goto Main Menu \n");
	getchar();
	main_menu();
}


void modify_intern (int id) /*For intern*/
{
	char temp[100];
	system("clear");
	display_title();

	FILE* file1 = fopen("records1.data", "r");

	if (!file1) {
		error("Couldn't open the data file!");
	}

	int n = no_of_records(file1, sizeof(INTERN));
	EMPLOYEE *in_all = calloc(n, sizeof(INTERN));

	fread(in_all, sizeof(INTERN), n, file1);

	fclose(file1);



	int found=0, index, i;
	for (i=0; i<n; i++) {
		if (in_all[i].id == id) {
			found = 1;
			index = i;
			break;
		}
	}

	if (!found) {
		free(in_all);
		error("The given ID doesn't match any records!");
	}

	printf("CURRENT DETAILS: \n");
	printf("   ID           : %d \n", in_all[index].id);
	printf("   Name         : %s \n", in_all[index].name);
	printf("   mailID       : %s \n", in_all[index].mailID);
	printf("   Phone        : %s \n", in_all[index].phone);
	printf("   Organization : %s \n", in_all[index].Organization);
	printf("   Salary       : %.2f \n", in_all[index].salary);
	printf("\n");

	printf("NEW DETAILS: \n");
	printf("   ID           : %d \n", in_all[index].id);
	printf("   Name         : "); getstr(in_all[index].name, 100, stdin);
	printf("   mailID       : "); getstr(in_all[index].mailID, 100, stdin);
	printf("   Phone        : "); getstr(in_all[index].phone, 100, stdin);
	printf("   Organization : "); getstr(in_all[index].Organization, 100, stdin);
	printf("   Salary       : "); in_all[index].salary = strtof(getstr(temp, 100, stdin), NULL);

	file1 = fopen("records1.data", "wb");
	fwrite(in_all, sizeof(INTERN), n, file1);
	free(in_all);
	fclose(file1);
	printf("\n");
	printf("Record successfully updated! \n");
	printf("\n");
	printf("Press [Enter] to goto Main Menu \n");
	getchar();
	main_menu();
}

void delete_employee (int id) /*for employee*/
{
	char temp[100];
	system("clear");
	display_title();

	printf("Are you sure you want to delete the record (y/n) ? "); getstr(temp, 100, stdin);
	printf("\n");

	char choice = temp[0];
	if (tolower(choice) != 'y') {
		printf("Deletion Aborted.\n\n");
		printf("Press [Enter] to goto Main Menu \n");
		getchar(); main_menu();
	}

	FILE* file = fopen("records.data", "rb");
	if (!file) error("Unable to open the data file!");
	int n = no_of_records(file, sizeof(EMPLOYEE));

	EMPLOYEE *emps = calloc(n, sizeof(EMPLOYEE));
	EMPLOYEE *emps_new = calloc(n-1, sizeof(EMPLOYEE));
	fread(emps, sizeof(EMPLOYEE), n, file);
	fclose(file);

	int i, found=0, count=0;
	for (i=0; i<n; i++) {
		if (emps[i].id == id) found=1;
		else emps_new[count++] = emps[i];
	}

	if (!found) {
		error("The given ID doesn't match any records.");
	}

	file = fopen("records.data", "wb");
	fwrite(emps_new, sizeof(EMPLOYEE), count, file);

	free(emps); free(emps_new);
	fclose(file);

	printf("Record successfully deleted.\n\n");
	printf("Press [Enter] to goto Main Menu\n");
	getchar(); main_menu();
}

void delete_intern (int id) /*for intern*/
{
	char temp[100];
	system("clear");
	display_title();

	printf("Are you sure you want to delete the record (y/n) ? "); getstr(temp, 100, stdin);
	printf("\n");

	char choice = temp[0];
	if (tolower(choice) != 'y') {
		printf("Deletion Aborted.\n\n");
		printf("Press [Enter] to goto Main Menu \n");
		getchar(); main_menu();
	}

	FILE* file1 = fopen("records1.data", "rb");
	if (!file1) error("Unable to open the data file!");
	int n = no_of_records(file1, sizeof(INTERN));

	INTERN *ints = calloc(n, sizeof(INTERN));
	INTERN *ints_new = calloc(n-1, sizeof(INTERN));
	fread(ints, sizeof(INTERN), n, file1);
	fclose(file1);

	int i, found=0, count=0;
	for (i=0; i<n; i++) {
		if (ints[i].id == id) found=1;
		else ints_new[count++] = ints[i];
	}

	if (!found) {
		error("The given ID doesn't match any records.");
	}

	file1 = fopen("records1.data", "wb");
	fwrite(ints_new, sizeof(INTERN), count, file1);

	free(ints); free(ints_new);
	fclose(file1);

	printf("Record successfully deleted.\n\n");
	printf("Press [Enter] to goto Main Menu\n");
	getchar(); main_menu();
}


void view_employees (void) /*for employee*/
{
	char temp[100];
	FILE* file = NULL;
	int n, i;

	system("clear");
	display_title();

	file = fopen("records.data", "rb");
	if (!file) {
		error("Couldn't open the data file!");
	}

	/* find out the no of records first */
	n = no_of_records(file, sizeof(EMPLOYEE));

	if (n<1) {
		fclose(file);
		error("There are no any records at the moment.");
	}

	EMPLOYEE* emps = calloc(n, sizeof(EMPLOYEE));

	fread(emps, sizeof(EMPLOYEE), n, file);

	qsort(emps, n, sizeof(EMPLOYEE), emp_cmp);

	printf("No of records: %d\n\n", n);

	/* display the table of records */
	printf("%5s  %-20s %15s \n", "ID", "NAME", "SALARY");
	printf("-------------------------------------------- \n");
	for (i=0; i<n; i++) {
		printf("%5d  %-20s %15.2f \n", emps[i].id, emps[i].name, emps[i].salary);
	}
	printf("-------------------------------------------- \n");

	free(emps);
	fclose(file);

	printf("\n");
	printf("Enter an ID to view detailed info (Press [Enter] to goto Main Menu): "); getstr(temp, 100, stdin);
	if (strlen(temp) < 1)
		main_menu();
	int id = strtol(temp, NULL, 10);
	search_employee_by_id(id);
}


void view_interns (void) /*for intern*/
{
	char temp[100];
	FILE* file1 = NULL;
	int n, i;

	system("clear");
	display_title();

	file1 = fopen("records1.data", "rb");
	if (!file1) {
		error("Couldn't open the data file!");
	}

	/* find out the no of records first */
	n = no_of_records(file1, sizeof(INTERN));

	if (n<1) {
		fclose(file1);
		error("There are no any records at the moment.");
	}

	INTERN* ints = calloc(n, sizeof(INTERN));

	fread(ints, sizeof(INTERN), n, file1);

	qsort(ints, n, sizeof(INTERN), intern_cmp);

	printf("No of records: %d\n\n", n);

	/* display the table of records */
	printf("%5s  %-20s %15s \n", "ID", "NAME", "SALARY");
	printf("-------------------------------------------- \n");
	for (i=0; i<n; i++) {
		printf("%5d  %-20s %15.2f \n", ints[i].id, ints[i].name, ints[i].salary);
	}
	printf("-------------------------------------------- \n");

	free(ints);
	fclose(file1);

	printf("\n");
	printf("Enter an ID to view detailed info (Press [Enter] to goto Main Menu): "); getstr(temp, 100, stdin);
	if (strlen(temp) < 1)
		main_menu();
	int id = strtol(temp, NULL, 10);
	search_intern_by_id(id);
}


char * getstr(char* string, int size, FILE* file_ptr)
{
	int len;

	fgets(string, size, file_ptr);
	len = strlen(string);

	if (len>0 && string[len-1]=='\n')
		string[len-1] = '\0';

	return string;
}


int no_of_records(FILE* file, int element_size) {
	rewind(file);
	int count = 0;
	char c;
	while (!feof(file)) {
		fread(&c, 1, 1, file);
		count++;
	}

	rewind(file); /* go back to the beginning of file */
	return count/element_size; /* return number of elements */
}

char* strcase(char* string, int flag) {

	int len = strlen(string);

	char newstring[100];

	int i;
	for (i=0; i<=len; i++) {
		if (flag)
			newstring[i] = toupper(string[i]);
		else
			newstring[i] = tolower(string[i]);
	}

	return newstring;
}

int emp_cmp (const void *e1, const void *e2) /*for employee*/
{
	if (((EMPLOYEE*)e1)->id < ((EMPLOYEE*)e2)->id) return -1;
	else if (((EMPLOYEE*)e1)->id == ((EMPLOYEE*)e2)->id) return 0;
	else return 1;
}

int intern_cmp (const void *in1, const void *in2) /*for employee*/
{
	if (((INTERN*)in1)->id < ((INTERN*)in2)->id) return -1;
	else if (((INTERN*)in1)->id == ((INTERN*)in2)->id) return 0;
	else return 1;
}

