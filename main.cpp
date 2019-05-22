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
void print_score(int i);
void print_all(int i);

typedef struct {
	char SID[LENGTH];
	int CID;
	char name[LENGTH];
	//chinese, math, englishm programming
	int score[4];
	int number;
}Student;

Student student_list[MAXN];
int count;
int length;
const char* subject[4] = { "Chinese", "Mathematics", "English", "Programming" };

int main() {
	int choice = 1;
	while (choice != 0) {
		printf("%s", subject[1]);
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
		//scanf_s("%d %d, %s %d %d %d %d", &student_list[count].SID, &student_list[count].CID, 
		//student_list[count].name, 20, &student_list[count].chinese, 
		//&student_list[count].math, &student_list[count].english, &student_list[count].programming);
		printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
		scanf_s("%s", student_list[count].SID, LENGTH);
		if (student_list[count].SID[0] == '0' && student_list[count].SID[1] == 0) {
			break;
		}
		scanf_s("%d", &student_list[count].CID);
		scanf_s("%s", student_list[count].name, LENGTH);
		scanf_s("%d", &student_list[count].score[0]);
		scanf_s("%d", &student_list[count].score[1]);
		scanf_s("%d", &student_list[count].score[2]);
		scanf_s("%d", &student_list[count].score[3]);
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
				if (strcmp(temp_name, student_list[index].name) == 0
					|| strcmp(temp_name, student_list[index].SID) == 0) {
					print_student(index);
				}
			}
		}
	} while (1);
}

void show_rank() {
	printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n");
}

void show_statistics() {
	int temp_class;
	printf("Please enter class ID, 0 for the whole statistics.\n");
	scanf_s("%d", &temp_class);
	print_score(temp_class);
	print_all(temp_class);
}

void print_student(int i) {
	Student student = student_list[i];
	printf("%d %s %s %d %d %d %d %d\n", student.number, student.SID, student.name, student.CID,
		student.score[0], student.score[1], student.score[2], student.score[3]);
}

void print_score(int i) {
	for (int p = 0; p < 4; p++) {
		printf("%s\n", subject[p]);
		int sum = 0;
		int avg_count = 0, number_passed = 0, number_failed = 0;
		for (int q = 0; q < count; q++) {
			if (student_list[q].CID == i) {
				sum += student_list[q].score[p];
				avg_count++;
				if (student_list[q].score[p] >= 60)
					number_passed++;
				else
					number_failed++;
			}
		}
		printf("Average Score: %.2f\n", sum * 1.0/avg_count);
		printf("Number of passed students: %d\n", number_passed);
		printf("Number of failed students: %d\n\n", number_failed);
	}
}

void print_all(int i) {
	int pass_number[5];
	memset(pass_number, 0, sizeof(pass_number));
	for (int x = 0; x < count; x++) {
		int pass_count = 0;
		for (int y = 0; y < 4; y++) {
			if (student_list[x].score[y] >= 60) {
				pass_count++;
			}
			
		}
		pass_number[pass_count]++;
	}
	printf("Overall:\n"
			"Number of students who passed all subjects: %d\n"
			"Number of students who passed 3 or more subjects: %d\n"
			"Number of students who passed 2 or more subjects: %d\n"
			"Number of students who passed 1 or more subjects: %d\n"
			"Number of students who failed all subjects: %d\n\n", pass_number[4], 
			pass_number[3]+pass_number[4], pass_number[2]+pass_number[3]+pass_number[4], 
			pass_number[1]+pass_number[2]+pass_number[3]+pass_number[4], pass_number[0]);
}