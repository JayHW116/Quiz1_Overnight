#include <stdio.h>
#include <string.h>

#define SIZE 5

typedef struct {
    int IDnumber;
    char name[50];
    char phoneNumber[15];
    double salary;
} Employee;

void searchEmployees(Employee[], int, int (*compare)(Employee, void*), void*);

int searchByID(Employee emp, void* key) {
    return emp.IDnumber == *(int*)key;
}

int searchByName(Employee emp, void* key) {
    return strcmp(emp.name, (char*)key) == 0;
}

int searchByPhoneNumber(Employee emp, void* key) {
    return strcmp(emp.phoneNumber, (char*)key) == 0;
}

int searchBySalary(Employee emp, void* key) {
    return emp.salary == *(double*)key;
}

void searchEmployees(Employee employees[], int size, int (*compare)(Employee, void*), void* key) {
	int found = 0;
	for (int i = 0; i < size; i++) {
	    if (compare(employees[i], key)) {
		   printf("Employee Found: ID: %d, Name: %s, Phone: %s, Salary: %.2f\n",
				employees[i].IDnumber, employees[i].name, employees[i].phoneNumber, employees[i].salary);
		   found = 1;
	    }
	}
	if (!found) {
	    printf("No employee matched the criteria.\n");
	}
 }
 
 int main() {
	Employee employees[SIZE] = {
	    {1001, "Candice", "555-1234", 60000},
	    {1002, "Bob", "555-5678", 75000},
	    {1003, "Charlie", "555-9999", 50000},
	    {1004, "David", "555-0000", 65000},
	    {1005, "Evelyn", "555-2222", 80000}
	};
 
	int idSearch = 1002;
	char nameSearch[] = "Charlie";
	char phoneSearch[] = "555-0000";
	double salarySearch = 65000;
 
	printf("\nSearching by ID:\n");
	searchEmployees(employees, SIZE, searchByID, &idSearch);
 
	printf("\nSearching by Name:\n");
	searchEmployees(employees, SIZE, searchByName, nameSearch);
 
	printf("\nSearching by Phone Number:\n");
	searchEmployees(employees, SIZE, searchByPhoneNumber, phoneSearch);
 
	printf("\nSearching by Salary:\n");
	searchEmployees(employees, SIZE, searchBySalary, &salarySearch);
 
	return 0;
 }
 


 