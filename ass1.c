/***********************************/
/* Find Longest Common Sequence ****/
/* Name: CMPUT201_Ass_1.c **********/
/* Author: Ketong Shen *************/
/* September 28, 2019 **************/

#include <stdio.h>

int check_input(char seq1[], char seq2[], int length[]);
void getLCS(char seq1[], char seq2[], int length[]);

int main() {

    char seq1[1000]; /* sequence1 								 */
    char seq2[1000]; /* sequence2								 */
    int length[2];   /* record the length of sequence: [0] for sequence 1; [1] for sequence 2	 */
    int right = 1;   /* boolean variable for deciding if the input is correct			 */

    /* 1.Deciding if the input is correct							 */							 
    /* 1.1 call the function check_input to check each element					 */
    /* 1.2 if there is no error, make right = 0 to end the loop					 */

    while (right) {
        printf("To compute an LCS,\nenter the first sequence: \n");
        printf("enter the second sequence: ");
        scanf("%s %s", seq1, seq2);
        right = check_input(seq1, seq2, length);
        printf("\n%d\n", right);

    }

    /* 2.Compute the longest common sequence between sequences				 	 */
    /* 2.1*/
    getLCS(seq1, seq2, length);


    return 0;
}

    /* 1.1 call the function check_input to check each element					 */
    /* 1.1.1  Use while loop to check every element in the input, if there is some characters not*/
    /* between '1' and '9', then it must not be number. So make check = 1 and return to right	 */
    /* 1.1.2  Record the number of check as length, and give the number to the length		 */ 

int check_input(char seq1[], char seq2[], int length[]){

    int check = 0;
    int i = 0;
    int j = 0;

    while (seq1[i] != '\0') {
        if (seq1[i] < '0' || seq1[i] > '9') {
            printf("%c", seq1[i]);
            check = 1;
            break;
        }
        i++;

    }

    while (seq2[j] != '\0') {
        if (seq2[j] < '0' || seq2[j] > '9') {
            printf("%c", seq1[j]);
            check = 1;
            break;
        }
        j++;
    }
    length[0] = i;
    length[1] = j;

    return check;
}

    /* 2.Compute the longest common sequence between sequences                                   */
    /* 2.1 give 0 to every element of 2-dim array						 */
    /* 2.2 recorde the direction and number of common sequence in lcs1 and lcs2			 */



void getLCS(char seq1[], char seq2[], int length[]) {

    int lcs1[length[0] + 1][length[1] + 1]; /* 2-dim array to record the direction of number	 */
    int lcs2[length[0] + 1][length[1] + 1]; /* 2-dim array to record the # of common char	 */ 
    char result[length[0]];                 /* array to record the final common sequence	 */
    int count = 0;                          /* record the length of final longest common sequence*/


    /* 2.1 give 0 to every element of 2-dim array						 */

    for (int i = 0; i <= length[0]; i++) {
        for (int j = 0; j <= length[1]; j++) {
            lcs1[i][j] = 0;
            lcs2[i][j] = 0;
        }
    }

    /* 2.2 recorde the direction and number of common sequence in lcs1 and lcs2			 */
    /* 2.2.1 '7' means from (-1, -1); '8' means from (-1, 0); '4' means from (0, -1).		 */
    /*      (the direction setting rules from 3*3 number keyboard)				 */
    /* 2. lcs2 record the same charaters from the sequence */
    /* 2.1 when there is same character, plus 1, and then, go to (+1, +1). (the next characters in two sequence). */
    /* 2.2 when there is not same, check until now, which subsequence checked has more same character in record. */




    for (int i = 1; i <= length[0]; i++) {
        for (int j = 1; j <= length[1]; j++) {
            if (seq1[i - 1] == seq2[j - 1]) {

                lcs2[i][j] = lcs2[i - 1][j - 1] + 1;
                printf("%d ", lcs2[i][j]);
                lcs1[i][j] = 7;
            } else if (lcs2[i - 1][j] >= lcs2[i][j - 1]) {
                lcs2[i][j] = lcs2[i - 1][j];
                lcs1[i][j] = 8;
            } else {
                lcs2[i][j] = lcs2[i][j - 1];
                lcs1[i][j] = 4;
            }

        }
    }
    printf("\n");

    printf("\n");
    for (int i = 0; i <= length[0]; i++) {
        printf("\n");
        for (int j = 0; j <= length[1]; j++) {

            printf("%d ", lcs2[i][j]);
        }
    }

    int row = length[0];
    int col = length[1];
    while (row != 0 && col != 0){
            if (lcs1[row][col] == 7){
                result[count] = seq2[col - 1];
                count = count + 1;

                row--;
                col--;

            }else if (lcs1[row][col] == 8){
                row--;
            }else {
                col--;
        }
    }


    for (int i = count - 1; i >= 0; i--){
        printf("%c", result[i]);
    }
    printf("\nrsult : %d", (result[count] == '\0'));



    printf("\n");
    for (int i = 0; i <= length[0]; i++) {
        printf("\n");
        for (int j = 0; j <= length[1]; j++) {

            printf("%d ", lcs2[i][j]);
        }
    }


    printf("\n%d\n", count);

    for (int i = 0; i <= length[0]; i++) {
        printf("\n");
        for (int j = 0; j <= length[1]; j++) {
            printf("%d ", lcs1[i][j]);

        }
    }

    printf("\n");
    for (int i = 0; i <= length[0]; i++) {
        printf("\n");
        for (int j = 0; j <= length[1]; j++) {

            printf("%d ", lcs2[i][j]);
        }
    }
}
