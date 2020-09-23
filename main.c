#include <stdio.h>
#include <stdlib.h>

struct El_Spiska {
    struct El_Spiska* next;  
    int data; };
typedef struct El_Spiska El_Spiska;

struct Spisok {
    El_Spiska* head; 
    int kol; 
};
typedef struct Spisok Spisok;

void Add_Spisok(Spisok* s, int i) {
    if (i == 1) {
        El_Spiska* s1 = (El_Spiska*) malloc( sizeof(El_Spiska) );
        printf("enter data\n");
        scanf("%d",&s1->data);
        s1->next = s->head;
        s->head = s1;
        s->kol++;
        return 0;
    }
    if(i != s->kol+1) {
        int j = 1;
        El_Spiska* s1 = s->head;
        while (j != i-1)
        {
            s1 = s1->next;
            j++;
        }

        El_Spiska* s2 = (El_Spiska*) malloc( sizeof(El_Spiska) );
        printf("enter data\n");
        scanf("%d",&s2->data);

        s2->next = s1->next;
        s1->next = s2;

        s->kol++;
    }
    else if(i == s->kol+1) {
        int j = 1;
        El_Spiska* s1 = s->head;
        while (j != s->kol) {
            s1 = s1->next;
            j++;
        }
        El_Spiska* s2 = (El_Spiska*) malloc( sizeof(El_Spiska) );
        printf("enter data\n");
        scanf("%d",&s2->data);

        s2->next = NULL;
        s1->next = s2;

        s->kol++;
    }

    return 0;

}

void Delete_Element(Spisok* s, int i) {
    if (i == 1) {
        El_Spiska* h = s->head;
        s->head = s->head->next;
        free(h);
        return 0;
    }
    int j = 1;
    El_Spiska* s1 = s->head;
    while (j != i-1) {
        s1 = s1->next;
        j++;
    }

    El_Spiska* sn = s1->next;
    s1->next = s1->next->next;

    free(sn);

    s->kol--;
    return 0;

}

void See_Spisok(Spisok* s) {
    El_Spiska* s1 = s->head;
    int i = 0;
    while (i!=s->kol) {
        printf("element %d: %d\n",i+1,s1->data);
        s1 = s1->next;
        i++;
    }
}


void Menu(Spisok** s) {
    printf("1 - add \n2 - delete \n3 - see spisok\n");
    int i;
    scanf("%d",&i);
    switch(i) {
        case 1:
            printf("Where to add the element?\n");
            int j;
            scanf("%d",&j);
            Add_Spisok(*s,j);
            Menu(s);

        case 2:
            printf("Where to delete the element?\n");
            int k;
            scanf("%d",&k);
            Delete_Element(*s,k);
            Menu(s);

        case 3:
            See_Spisok(*s);
            Menu(s);

        default:
                printf("you entered the wrong number\n");
                Menu(s);
    }
}

int main(void) {
    Spisok s;
    s.head = NULL;

    s.kol = 0;
    Spisok* s1 = &s;
    Menu(&s1);

    return 0;
}
