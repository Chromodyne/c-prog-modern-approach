#include<stdio.h>
#include<stdlib.h>
#include "readline.h"

#define NAME_LEN 25
#define INITIAL_PARTS 10

struct part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
};

int num_parts = 0;

//max_parts now will start at the same value as our initial_parts macro.
int max_parts = INITIAL_PARTS;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

//Create a new struct pointer of type part named inventory. This way we can allocate the necessary memory.
struct part *inventory;


int main(void) {
    
    char code;

    //Allocate memory for our initial inventory size.
    inventory = malloc(max_parts * sizeof(struct part));

    //Check if the memory allocation returns a null pointer. Terminate program if so.
    if (inventory == NULL) {
        printf("Memory allocation failed.");
        exit(EXIT_FAILURE);
    }

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')
            ;
        switch(code) {
            case 'i': insert();
                      break;
            case 's': search();
                      break;
            case 'u': update();
                      break;
            case 'p': print();
                      break;
            case 'q': return 0;
            default: printf("Illegal code\n");
        }
        printf("\n");

    }

}

int find_part(int number) {

    int i;

    for(i = 0; i < num_parts; i++) {
        if (inventory[i].number == number) {
            return i;
        }
    }

    return -1;

}

void insert(void) {
    int part_number;

    //Create a part type struct pointer to perform the realloc
    struct part *new_inventory;

    if (num_parts == max_parts) {
        //printf("Database is full; can't add more parts.\n");
        //return;

        //Double the size of max_parts using a bitshift to the left. We could also *= 2;
        max_parts << 1;

        //Remember that realloc requires a pointer and a size.
        new_inventory = realloc(inventory, max_parts * sizeof(struct part));

        //Check if realloc returned a null pointer. Terminate program if so.
        if (new_inventory == NULL) {
            printf("Memory reallocation returned null.");
            exit(EXIT_FAILURE);
        }

        //Set inventory to the new allocation performed above.
        inventory = new_inventory;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(part_number) >= 0) {
        printf("Part already exists.\n");
        return;
    }

    inventory[num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);
    num_parts++;

}

void search(void) {

    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        printf("Part Name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);

    } else {
        printf("Part not found.\n");
    }

}

void update(void) {

    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    } else {
        printf("Part not found.\n");
    }

}

void print(void) {

    int i;

    printf("Part Number    Part Name                "
            "Quantity on Hand\n");
    for (i = 0; i < num_parts; i++) {
        printf("%7d          %-25s%11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
    }

}