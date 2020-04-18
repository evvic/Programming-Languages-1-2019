// -----------------------------------------------------------------------
// monsterdb.c
// -----------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// -----------------------------------------------------------------------
// Some defines
#define NAME_MAX 64
#define BUFFER_MAX 256

// User instructions
const char *info[] = {
  "Enter a command:",
  "",
  "  ?  - print this list of commands",
  "  r  - read monster database (binary file)",
  "  w  - write monster database (binary file)",
  "  d  - display monsters",
  "  n  - sort monsters by name (ascending)",
  "  h  - sort monsters by hitpoints (descending)",
  "  q  - quit",
};
const int N_INFO = 9;


// -----------------------------------------------------------------------
// Structs

typedef struct Weapon_struct {
    char name[NAME_MAX];
    int damageModifier;
} Weapon;

typedef struct Stats_struct {
    int agility;
    int toughness;
    int hitpoints;
} Stats;

typedef struct Monster_struct {
    char name[NAME_MAX];
    Stats stats;
    Weapon weapon;
} Monster;

typedef struct MonsterList_struct {
    int size;
    Monster *list;
} MonsterList;


// -----------------------------------------------------------------------
// Function prototypes

void printInfo();
void displayMonster(Monster *m);
void displayMonsters(MonsterList *monsters);
int swapNeededName(Monster *a, Monster *b);
int swapNeededHitPoints(Monster *a, Monster *b);
void sortMonsters(MonsterList *monsters, char sortType);
void readDb(MonsterList *monsters, char *fileName);
void writeDb(MonsterList *monsters, char *fileName);

// -----------------------------------------------------------------------
// Main Program

int main() {
    MonsterList monsters = {0, NULL};
    char fileName[BUFFER_MAX];
    char userIn[BUFFER_MAX];
    char cmd;

    printInfo();

    int done = 0;
    while (!done) {
        printf("\n> ");
        scanf("%s", userIn);
        cmd = userIn[0];

        switch (cmd) {
        case '?':
            printInfo();
            break;
        case 'r': ///file -> program
            printf("DB file name (to read): ");
            scanf("%s", fileName);
            //printf("\n");
            readDb(&monsters, fileName);
            break;
        case 'w': ///program -> file
            if(monsters.size == 0) {
                printf("(no monsters loaded)");
                break;
            }
            else {
                printf("DB file name (to write): ");
                scanf("%s", fileName);
                //printf("\n");
                writeDb(&monsters, fileName);
                break;
            }
        case 'd':
            if(monsters.size == 0) {
                printf("(no monsters loaded)"); //removed \n
            }
            else {
                displayMonsters(&monsters);
            }
            break;
        case 'n':
            if(monsters.size == 0) {
                printf("(no monsters loaded)"); //removed \n
            }
            else { ///sort in ascending order
                sortMonsters(&monsters, 'n');
                displayMonsters(&monsters);            }
            break;
        case 'h':
            if(monsters.size == 0) {
                printf("(no monsters loaded)");
            }
            else { ///sort in ascending order
                sortMonsters(&monsters, 'h');
                displayMonsters(&monsters);
            }
            break;
        case 'q':
            return 1;
            break;
        default:
            printf("Unknown command `%c`", cmd);
            break;
        }
    }
    return 0;
}

// -----------------------------------------------------------------------
// Function implementations

void printInfo() {
    printf("\n");
    for(int i = 0; i < N_INFO; i++) {
        printf("%s\n", info[i]);
    }
}

void displayMonster(Monster *m) {
    printf("%10s [a:%d, t:%d, hp:%2d] <%-15s mod:%2d>\n",
    m->name, m->stats.agility, m->stats.toughness, m->stats.hitpoints, m->weapon.name, m->weapon.damageModifier);
}

void displayMonsters(MonsterList *monsters) {
    for(int i = 0; i < monsters->size ; i++) {
        displayMonster(&(monsters->list[i]));
    }
}
int swapNeededName(Monster *a, Monster *b) {
    if(/*a->name < b->name*/ strcmp(a->name, b->name) > 0) { ///FIXME which is smalloer
        /*strcpy(temp.name, a->name);
        strcpy(a->name, b->name);
        strcpy(b->name, temp.name);*/ ///must switch the entire monster
        /*temp = *a;
        *a = *b;
        *b = temp;*/

        return 1; ///true: a[i] is less than b[i - 1]
    }
    /*else if(strcpy(a->name, b->name) <= 0) {
        return 0; ///false:[i] is greater than b[i - 1]
    }*/
    else {
        //printf("    swapNeededName error came to else\n");
        return 0;
    }
}

int swapNeededHitPoints(Monster *a, Monster *b) {
    if(a->stats.hitpoints < b->stats.hitpoints) { ///FIXME which is smalloer
        /*temp.stats.hitpoints = a->stats.hitpoints;
        a->stats.hitpoints = b->stats.hitpoints;
        b->stats.hitpoints = temp.stats.hitpoints;  ///must switch the entire monster
        temp = *a;
        *a = *b;
        *b = temp; */


        return 1; ///true: a[i] is less than b[i - 1]
    }
    else if(a->stats.hitpoints > b->stats.hitpoints) {
        return 0; ///false: a[i] is greater than b[i - 1]
    }
    else {
        printf("    swapNeededHitpoints error came to else\n");
        return 0;
    }
}
void sortMonsters(MonsterList *monsters, char sortType) { ///must use the 2 int functions w/ respect to whats being swapped
    int j = 0;
    Monster temp;
    switch(sortType) {
    case 'n': ///name descending
        j = 0;
        for(int i = 0; i < monsters->size; i++) {
            j = i;
            while(j > 0 && swapNeededName(&monsters->list[j - 1], &monsters->list[j]) == 1 /*dynamic[j] < dynamic[j - 1]*/) {
                temp = monsters->list[j];
                monsters->list[j] = monsters->list[j - 1];
                monsters->list[j - 1] = temp;
                --j;
            }
        }
        break;
    case 'h': ///hit points descending
        j = 0;
        for(int i = 0; i < monsters->size; i++) {
            j = i;
            while(j > 0 && swapNeededHitPoints(&monsters->list[j - 1], &monsters->list[j]) == 1 /*dynamic[j] < dynamic[j - 1]*/) {
                temp = monsters->list[j];
                monsters->list[j] = monsters->list[j - 1];
                monsters->list[j - 1] = temp;
                --j;
            }
        }
        break;
    default:
        break;
    }

    /*for(int i = 0; i < monsters->size; i++) {
        j = i;
        while(j > 0 && dynamic[j] < dynamic[j - 1]) {
            temp = dynamic[j];
            dynamic[j] = dynamic[j - 1];
            dynamic[j - 1] = temp;
            --j;
        }
    }*/ ///insertion sort code
}

void readDb(MonsterList *monsters, char *fileName/*fileName is a char array*/){ ///file -> program
    int tempSize = 0;
    FILE* inFile = fopen(fileName, "rb");

    if(inFile == NULL) {
        printf("Failed to open '%s' for read\n",fileName);
        return;
    }

    fread(&monsters->size, sizeof(int), 1, inFile);
    printf("1 items read from \'%s\' (size header)\n", fileName);

    printf("Allocating heap for %d Monsters...", monsters->size);
    tempSize = monsters->size; //saving size of monsters array before mem is freed

    free(monsters->list);

    monsters->list = (Monster *)malloc(sizeof(Monster) * tempSize); ///use monsters.list
    printf("memory allocated\n");
    fread(monsters->list, sizeof(Monster), monsters->size, inFile);
    printf("%d items read from \'%s\' (monster array)\n", tempSize, fileName);

    fclose(inFile);///problem with fclose?
}
void writeDb(MonsterList *monsters, char *fileName) { ///program -> file
    FILE* outFile = fopen(fileName, "wb");

    if(outFile == NULL) {
        printf("Failed to open \'%s\' for write\n", fileName);
        return;
    }
    printf("Opened file %s\n", fileName);

    fwrite(&monsters->size, sizeof(int), 1, outFile);
    printf("1 items written to '%s' (size header)\n", fileName);

    fwrite(monsters->list, sizeof(Monster), monsters->size, outFile);
    printf("%d items written to '%s' (monster array)\n", monsters->size, fileName);

    fclose(outFile);
}

// -----------------------------------------------------------------------
