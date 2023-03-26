#include<stdio.h>
#include<stdbool.h>

int main(void) {

    struct dialing_code {
        char * country;
        int code;
    };

    const struct dialing_code country_code[] = {
        {"Argentina", 54}, {"Bangladesh", 880},
        {"Brazil", 55},    {"Burma (Myanmar)", 95},
        {"China", 86},     {"Colombia", 57},
        {"Congo, Dem. Rep. of", 243}, {"Egypt", 20},
        {"Ethiopia", 251}, {"France", 33},
        {"Germany", 49},   {"India", 91},
        {"Indonesia", 62}, {"Iran", 98},
        {"Italy", 39},     {"Japan", 81},
        {"Pakistan", 92},  {"Phillipines", 63},
        {"Poland", 48},    {"Russia", 7},
        {"South Africa", 27}, {"South Korea", 82},
        {"Spain", 34},     {"Sudan", 249},
        {"Thailand", 66},  {"Turkey", 90},
        {"Ukraine", 180},  {"United Kingdom", 44},
        {"United States", 1}, {"Vietnam", 84}
    };

    //The first variable will store the code entered by the user. The second is used for the ending conditional
    //to print an error message if the code entered by the user does not exist in the structure.
    int code_entered;
    bool code_exists = false;


    printf("Please enter an international dialing code: ");
    scanf("%3d", &code_entered);

    //Iterate through the structure array.
    for (int i = 0; i < sizeof(country_code) / sizeof(country_code[0]); i++) {

        //Check to see if the current country code at the current index matches the one entered by the user.
        if (country_code[i].code == code_entered) {

            //Print the name of the country at that index if the code matches the one entered by the user.
            printf("The country listed under that code is: %s", country_code[i].country);

            //Set to true so that the error code for a missing country code is skipped.
            code_exists = true;
        }

    }

    //If the code entered by the user is not found in the previous loop, code_exists will be false and this
    //message will be printed.
    if (!code_exists) {
        printf("The international dialing code entered does not exist.");
    }

    return 0;

}