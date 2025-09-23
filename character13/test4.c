#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// calloc();
// 不仅可以分配内存，还可以将所有位置设置为0

typedef struct Employee {
	char *name;
	int *taskList;
	int taskCount;
} Employee;

Employee *create_employee(const char *name, int taskCount);
void free_employee(Employee *employee);

int main(void) {

	Employee *developer = create_employee("jade", 5);

	if (developer == NULL) {
		return EXIT_FAILURE;
	}

	developer->taskList[0] = 101;

	printf("assigned task id for %s : %d\n", developer->name, developer->taskList[0]);

	free_employee(developer);

	return EXIT_SUCCESS;
}

Employee *create_employee(const char *name, int taskCount) {
	Employee *new_employee = (Employee *)malloc(sizeof(Employee));

	if (new_employee == NULL) {
		perror("Failed to allocate memory for new employee");
		return NULL;
	}

	new_employee->name = (char *)malloc(strlen(name) + 1);
	if (new_employee->name == NULL) {
		perror("Failed to allocate memory for new employee name");
		free(new_employee);
		return NULL;
	}

	strcpy(new_employee->name, name);

	new_employee->taskCount = taskCount;
	new_employee->taskList = calloc(taskCount, sizeof(int));
	if (new_employee->taskList == NULL) {
		perror("Failed to allocate memory for task list");
		free(new_employee->name);
		free(new_employee);
		return NULL;
	}

	return new_employee;
}

void free_employee(Employee *employee) {
	if (employee != NULL) {
		free(employee->name);
		free(employee->taskList);
		free(employee);
	}
}
