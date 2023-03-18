//Chapter 11 - Project 2
#include<stdio.h>

//Function Prototype(s)
void find_closest_flight(int desired_time, int * departure_time, int * arrival_time);

int main(void) {

    int hours = 0, minutes = 0;

    //This does not check for invalid inputs. Remember that!
    printf("Please enter a time using 24h format with a colon in the middle: ");
    scanf("%d:%d", &hours, &minutes);

    int desired_time = (hours * 60) + minutes;
    int departure_time;
    int arrival_time;

    find_closest_flight(desired_time, &departure_time, &arrival_time);

    printf("The closest departure time is: %02d:%02d. It will arrive at %02d:%02d.", departure_time / 60, departure_time % 60, arrival_time / 60, arrival_time % 60);

    return 0;

}

void find_closest_flight(int desired_time, int * departure_time, int * arrival_time) {

    /*  ---Departure/Arrival Timetable---
    Departure       Arrival     Converted Dep / Arr Times (minutes)
    ---------------------------------------------------------------
    08:00           10:16       480     /       616          
    09:43           11:52       583     /       712
    11:19           13:31       679     /       811
    12:47           15:00       767     /       900
    14:00           16:08       840     /       978
    15:45           17:55       945     /       1075
    19:00           21:20       1140    /       1280
    21:45           23:58       1305    /       1438
    */

    //These declarations have the provided time table converted into minutes. Could use a multi-dimensional array but decided to keep close to original project from Ch. 5.
    int departure_1 = 480, departure_2 = 583, departure_3 = 679, departure_4 = 767, departure_5 = 840, departure_6 = 945, departure_7 = 1140, departure_8 = 1305;
    int arrival_1 = 616, arrival_2 = 712, arrival_3 = 811, arrival_4 = 900, arrival_5 = 978, arrival_6 = 1075, arrival_7 = 1280, arrival_8 = 1438;

    //Cannot use switch because these are not constant conditions.
    if (desired_time <= departure_1) {
        *departure_time = departure_1;
        *arrival_time = arrival_1;
    } else if (desired_time > departure_1 && desired_time <= departure_2) {
        *departure_time = departure_2;
        *arrival_time = arrival_2;
    } else if (desired_time > departure_2 && desired_time <= departure_3) {
        *departure_time = departure_3;
        *arrival_time = arrival_3;
    } else if (desired_time > departure_3 && desired_time <= departure_4) {
        *departure_time = departure_4;
        *arrival_time = arrival_4;
    } else if (desired_time > departure_4 && desired_time <= departure_5) {
        *departure_time = departure_5;
        *arrival_time = arrival_5;
    } else if (desired_time > departure_5 && desired_time <= departure_6) {
        *departure_time = departure_6;
        *arrival_time = arrival_6;
    } else if (desired_time > departure_6 && desired_time <= departure_7) {
        *departure_time = departure_7;
        *arrival_time = arrival_7;
    } else if (desired_time > departure_7 && desired_time <= departure_8) {
        *departure_time = departure_8;
        *arrival_time = arrival_8;
    }  else {
        *departure_time = departure_1;
        *arrival_time = arrival_1;
    }

}

