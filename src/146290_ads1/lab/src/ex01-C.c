#include <stdio.h>
#include <stdlib.h>

const int MAX_SIZE = 20;

struct student{unsigned int score, studentId;};

struct student* student_array_new(int n){return (struct student*)malloc(MAX_SIZE * sizeof(struct student));}

void insert(struct student* S, int p, int s, int ID){
    S[p].score = s;
    S[p].studentId = ID;
}

void read(struct student* S, int p){
    printf("- score:    %d\n", S[p].score);
    printf("- ID:       %d\n", S[p].studentId);
}

int main(){
    char choice;
    struct student* S = student_array_new(MAX_SIZE);
    while(1){
        printf("Please choose:\n- i: insert\n- r: read\n- q: quit\nPlease input your choice: ");
        scanf("%s", &choice);

        switch(choice){
            case 'i':{
                int p, s, ID;
                printf("Insert:\n- position: ");
                scanf("%d", &p);
                printf("- score:    ");
                scanf("%d", &s);
                printf("- ID:       ");
                scanf("%d", &ID);

                insert(S, p, s, ID);

                break;
            }
            case 'r':{
                int p;
                printf("Insert:\n- position: ");
                scanf("%d", &p);

                read(S, p);

                break;
            }
            case 'q': return 0;
        }
    }

    return 0;
}