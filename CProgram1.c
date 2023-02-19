/*
 * CProgram1.c
 *
 *  Created on: Feb 17, 2023
 *      Author: c950c102
 */

#include <stdio.h>

#include <stdlib.h>

int dept[5][5];

int prog[5][5];

int top[5] = {0, 0, 0, 0, 0};

int matching[5] = {0, 0, 0, 0, 0};

char userFile[100]="";

FILE *textfile;

char line[10];

int pchoice, count;

int main(){

	printf("%s","Enter your input file(Make sure you add the extension):\n");

	scanf("%s", &userFile);

	textfile = fopen(userFile, "r");

	for (int i = 0; i < 5; i++){

		fscanf(textfile, "%d %d %d %d %d", &dept[0][i], &dept[1][i], &dept[2][i], &dept[3][i], &dept[4][i]);

	}

	for (int i = 0; i < 5; i++){

		fscanf(textfile, "%d %d %d %d %d", &prog[0][i], &prog[1][i], &prog[2][i], &prog[3][i], &prog[4][i]);

	}

	fclose(textfile);

	printf("\n%s\n", "Programmers and Their Preferences:");

	printf("%s\n","Programmer #1\tProgrammer #2\tProgrammer #3\tProgrammer #4\tProgrammer #5");

	for (int i = 0; i < 5; i++){

		printf("      %d \t      %d \t      %d \t      %d \t      %d\n", prog[0][i], prog[1][i], prog[2][i], prog[3][i], prog[4][i]);

	}

	printf("\n%s\n", "Departments and Their Preferences:");

	printf("%s\n","Department #1\tDepartment #2\tDepartment #3\tDepartment #4\tDepartment #5");

	for (int i = 0; i < 5; i++){

		printf("      %d \t      %d \t      %d \t      %d \t      %d\n", dept[0][i], dept[1][i], dept[2][i], dept[3][i], dept[4][i]);

	}

    for(int i = 0; i< 5; i++){

        for(int j = 0; j<5; j++){

            for(int k=0; k<5; k++){

                if ((j != k)&&(matching[j] == 0)){

                    if ((dept[j][top[j]] == dept[k][i]) && (matching[k] == 0)){

                        pchoice = dept[j][top[j]];

                        count = 0;

                        for (int l = 0; l < 5; l++){

                            if (matching[l] == pchoice){

                                count = 1;
                            }
                        }

                        if (count == 0){

                            for (int l = 0; l < 5; l++){

                                if ((prog[pchoice-1][l] == (j+1))&&(count == 0)){

                                    matching[j] = pchoice;

                                    top[k] = top[k] + 1;

                                    count = 1;

                                }

                                if ((prog[pchoice-1][l] == (k+1))&&(count==0)){

                                    matching[k] = pchoice;

                                    top[j] = top[j] + 1;

                                    count = 1;

                                }

                            }

                        }
                    }

                }

            }

        }
    }

    for (int i = 0; i < 5; i++){

        if (matching[i] == 0){

            while (top[i] < 5){

                count = 0;

                for (int j = 0; j < 5; j++){

                    if(matching[j] == dept[i][top[i]]){

                        count = 1;

                    }

                }

                if ((count == 0)&&(matching[i] == 0)){

                    matching[i] = dept[i][top[i]];

                }

                top[i] = top[i] + 1;
            }

        }

    }

    printf("\n%s\n", "Departments with their Assigned Programmers:");

	for (int i = 0; i < 5; i++){

		printf("Department #%d will get Programmer #%d \n", i+1,matching[i]);

	}

	return 0;
}
