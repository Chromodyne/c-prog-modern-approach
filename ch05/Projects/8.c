//Chapter 5 - Project 8
#include<stdio.h>

//Function Prototype(s)
int minutesSinceMidnight(int hours, int minutes);

int main(void) {

    int hours = 0, minutes = 0;

    //This does not check for invalid inputs. Remember that!
    printf("Please enter a time using 24h format with a colon in the middle: ");
    scanf("%d:%d", &hours, &minutes);

    /*  ---Departure/Arrival Chart---
    Departure       Arrival     Converted(minutes)
    ----------------------------------------------
    08:00           10:16       480                
    09:43           11:52       583
    11:19           13:31       679
    12:47           15:00       767
    14:00           16:08       840
    15:45           17:55       945
    19:00           21:20       1140
    21:45           23:58       1305
    */

    int closestHours = 0, closestMinutes;

    //Gets the time entered by the user converted to minutes.
    int converted = minutesSinceMidnight(hours, minutes);

    //This conditional block checks the time input by the user after being converted into minutes and compares it to the provided timetable.
    if (converted <= 480) {
        closestHours = 8;
        closestMinutes = 0;
    } else if (converted > 480 && converted <= 583) {
        closestHours = 9;
        closestMinutes = 43;
    } else if (converted > 583 && converted <= 679) {
        closestHours = 11;
        closestMinutes = 19;
    } else if (converted > 679 && converted <= 767) {
        closestHours = 12;
        closestMinutes = 47;
    } else if (converted > 767 && converted <= 840) {
        closestHours = 14;
        closestMinutes = 0;
    } else if (converted > 840 && converted <= 945) {
        closestHours = 15;
        closestMinutes = 45;
    } else if (converted > 945 && converted <= 1140) {
        closestHours = 19;
        closestMinutes = 0;
    } else if (converted > 1140 && converted <= 1305) {
        closestHours = 9;
        closestMinutes = 45;
    } else {
        closestHours = 8;
        closestMinutes = 0;
    }

    //Remember to print two digits so that leading/trailing zeroes are added as necessary.
    printf("The closest departure time is: %02d:%02d", closestHours, closestMinutes);

    return 0;

}

//This function receives the time input by the user as parameters and then converts it into minutes.
int minutesSinceMidnight(int hours, int minutes) {

    int totalMinutes = 0, convertedHours = 0;

    totalMinutes += ((hours * 60) + minutes);

    return totalMinutes;

}