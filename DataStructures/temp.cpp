#include <stdio.h>
#include <stdlib.h>

void printArr(float *arr, int size){
    for (int i = 0; i < size; i++){
        printf("\nSTUDENT %2d GRADE: %2.2f", i, arr[i]);
    }
}

void setGrades(float *arr, int size){
    int grade = 0;
    for (int i = 0; i < size; i++){
        printf("\nINSERT THE GRADE OF STUDENT %2d: ", i);
        scanf("%d", &grade);
        arr[i] = grade;
    }
}

int main(){

    int numStudents = 0;
    int grade       = 0;
    int higher      = 0;
    int lower       = 0;
    int sum         = 0;
    int stay        = 0;
    int pass        = 0;
    float average   = 0;
    
    float *arr = nullptr;

    printf("INSERT THE AMOUNT OF STUDENTS: ");
    scanf("%d", &numStudents);
    
    arr = (float*)malloc(sizeof(float) * numStudents); 
    
    setGrades(arr, numStudents);   
    printArr (arr, numStudents); 

    lower = arr[0];
    
    for (int i = 0; i < numStudents; i++){
        sum += arr[i];

        if (arr[i] > higher) higher = arr[i];
        if (arr[i] < lower ) lower  = arr[i];

        if (arr[i] > 11.5f) pass++;
        else stay++;
    }
    
    average = (float)sum / (float)numStudents;
    
    printf("\n\nAVERAGE: %2.2f\nHIGHER : %2d\nLOWER  : %2d\nPASS   : %2d\nSTAY   : %2d\n", average, higher, lower, pass, stay);

    free(arr);
    return 0;
}
