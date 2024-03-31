#include <stdio.h>
#include <string.h>

/*
** findJudge()  finds the "judge" in a given 2-D array 
** @param find[][2]  given 2-D array to find "judge" in
** @param row  given int for the amount of rows in find
** @param size  given int that acts as a range for possible numbers
** @return int  returns the "judge" or -1
*/


int findJudge (int find[][2], int row, int size) {
	int trusting[size];
	int trusted[size];

	for (int index = 0; index < size; index++) {
		trusting[index] = 0;
		trusted[index] = 0;
	}

	for (int rows = 0; rows < row; rows++) {
		trusting[find[rows][0]] += 1;
		trusted[find[rows][1]] += 1;
	}

	for (int index = 0; index < size; index++) {
		if (trusting[index] == 0 && trusted[index] == size-1) {
			return index;
		}
	}
	return -1;
}

int main (int argc, char* argv[]) {
	if (argc != 2) { // check correct amount of arguments
		printf("invalid arguments");
		return 0;
	}
	
	FILE* f = fopen(argv[1], "r");
	if (f == NULL) { // check file opened
		printf("invalid arguments");
		return 0;
	}

	int size, num, num2, index;
	fscanf(f, "%d", &size); // constraints
	int find[100][2];

	while (fscanf(f, "%d %d", &num, &num2) == 2) { // reads two variables into a 2-D array
		find[index][0] = num;
		find[index][1] = num2;
		index++;
	}
	
	fclose(f);

	printf("%d\n", findJudge(find, index, size));
	
}
