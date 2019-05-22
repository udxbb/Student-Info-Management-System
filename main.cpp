#include<stdio.h>
#include<string.h>
#define MAXN 100
#define LENGTH 10

void add_student();
void remove_student();
void query();
void show_rank();
void show_statistics();
void print_student(int i);

typedef struct {
	char SID[LENGTH];
	int CID;
	char name[LENGTH];
	int chinese, math, english, programming;
	int number;
}Student;

Student student_list[MAXN];
int count;
int length;


int main() {
	int choice = 1;
	while (choice != 0) {
		printf("Welcome to Student Performance Management System (SPMS)\n\n"
			"1 - Add\n"
			"2 - Remove\n"
			"3 - Query\n"
			"4 - Show ranking\n"
			"5 - Show Statistics\n"
			"0 - Exit\n\n");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1: add_student(); break;
		case 2: remove_student(); break;
		case 3: query(); break;
		case 4: show_rank(); break;
		case 5:show_statistics(); break;
		default: break;
		}
	}
	return 0;
}


void add_student() {
	count = 0;
	do {
		//int SID, CID, chinese, math, english, programming;
		printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
		//scanf_s("%d %d, %s %d %d %d %d", &student_list[count].SID, &student_list[count].CID, student_list[count].name, 20, &student_list[count].chinese, 
		//		&student_list[count].math, &student_list[count].english, &student_list[count].programming);
		scanf_s("%s", student_list[count].SID, LENGTH);
		if (student_list[count].SID[0] == '0' && student_list[count].SID[1] == 0) {
			break;
		}
		scanf_s("%d", &student_list[count].CID);
		scanf_s("%s", student_list[count].name, LENGTH);
		scanf_s("%d", &student_list[count].chinese);
		scanf_s("%d", &student_list[count].math);
		scanf_s("%d", &student_list[count].english);
		scanf_s("%d", &student_list[count].programming);
		student_list[count].number = count + 1;
		for (int i = 0; i < count; i++) {
			if (student_list[i].SID == student_list[count].SID) {
				printf("Duplicated SID.\n");
				continue;
			}
		}
		count++;
	} while (1);
}

void remove_student() {
	
}

void query() {
	do {
		char temp_name[LENGTH] = {'\0'};
		printf("Please enter SID or name. Enter 0 to finish.\n");
		scanf_s("%s", temp_name, LENGTH);
		if (temp_name[0] == '0' && temp_name[1] == 0) {
			break;
		}
		else {
			for (int index = 0; index < count; index++) {
				if (strcmp(temp_name, student_list[index].name) == 0 || strcmp(temp_name, student_list[index].SID) == 0) {
					print_student(index);
				}
			}
		}
	} while (1);
}

void show_rank() {

}

void show_statistics() {
	do {
		printf("Please enter class ID, 0 for the whole statistics.\n");
	} while (1);
}

void print_student(int i) {
	Student student = student_list[i];
	printf("%d %s %s %d %d %d %d %d\n", student.number, student.SID, student.name, student.CID, student.chinese, student.math, student.english, student.programming);
}