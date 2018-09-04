/*
    There are n number of persons stood to form a circle. 
    The person at position 1 killed the person at position 2 and 
    gave knife to the person at position 3.
    The person at position 3 killed the person at position 4 and 
    gave knife to the person at position 5.
    At the end of the game only one person alived and what's his position ? 
*/

#include<stdio.h>
#include<math.h>
int startGame(int);

int main()
{
    int num;
    printf("Enter number of persons : ");
    scanf("%d", &num);
    startGame(num);
    return 0;
}

int startGame(int decimal){

    int binaryNum[1000], complementedArray[1000];
    int decimalNum = 0, digits, j, k;
    int originalNum = decimal;

    /* 
        convert given decimal to binary
    */
    for (digits = 0; decimal != 0; digits++){
        binaryNum[digits] = decimal % 2;    
        decimal /= 2;
    }
    
    /* 
        reverse the array to get correct binary number
        and also do complement of each binary digit  
    */
    for (j = digits - 1, k=0; j >= 0; j--, k++){
        if(binaryNum[j]==1){
            complementedArray[k] = 0;
        }
        else{
            complementedArray[k] = 1;
        }
    }

    /*
        convert the complemented binary number to decimal
    */
    for (k = digits - 1, j = 0; k >= 0; k--, j++){
        decimalNum += complementedArray[k] * (int)pow(2, j);
    }

    /* 
        then subtract it from original number to get the answer ! 
    */
    printf("The persone alived is at position : %d\n", originalNum - decimalNum);

    return 0;
}
