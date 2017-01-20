#include <stdio.h>
#include <math.h>

int ifLeap(int NOY){                  //if given year is leap year then return 1
                                      //else return 0
  if(NOY%400 == 0){
    return 1;
  }
  if(NOY%100 == 0){
    return 0;
  }
  if(NOY%4 == 0){
    return 1;
  }
  return 0;
} //ifLeap


int getStartingDate(int targetYear){            //get the day of the first day in the year
  int startingDate = 6;                         //provided
  int currentYear = 2000;
  if(targetYear > currentYear){
    while(currentYear < targetYear){
      if(ifLeap(currentYear)){
	startingDate = (startingDate + 366 % 7) % 7;
      }
      else{
	startingDate = (startingDate + 365 % 7) % 7;
      }
      currentYear++;
    }
  }
  else if(targetYear < currentYear){
    currentYear--;
    while(currentYear >= targetYear){
      if(ifLeap(currentYear)){
	startingDate = (startingDate - (366 % 7)) % 7;
      }
      else{
	startingDate = (startingDate - (365 % 7)) % 7;
      }
      currentYear--;
    }
    if(startingDate < 0){
      startingDate += 7;
    }
  }
  return startingDate;
}

void printDateName(void){                         //print the title of each day
  printf(" SUN MON TUE WED THR FRI SAT\n");
}//printDateName

int printMonthTitle(int targetYear, int whichMonth){    //print the title of each month 
  switch(whichMonth){                                   //and return the number of days in this month    
  case 0:
    printf("January %d\n", targetYear);
    printDateName();
    return 31;
  case 1:
    printf("Febuary %d\n", targetYear);
    printDateName();
    if(ifLeap(targetYear)){
      return 29;
    }
    return 28;
  case 2:
    printf("March %d\n", targetYear);
    printDateName();
    return 31;
  case 3:
    printf("April %d\n", targetYear);
    printDateName();
    return 30;
  case 4:
    printf("May %d\n", targetYear);
    printDateName();
    return 31;
  case 5:
    printf("June %d\n", targetYear);
    printDateName();
    return 30;
  case 6:
    printf("July %d\n", targetYear);
    printDateName();
    return 31;
  case 7:
    printf("August %d\n", targetYear);
    printDateName();
    return 31;
  case 8:
    printf("September %d\n", targetYear);
    printDateName();
    return 30;
  case 9:
    printf("October %d\n", targetYear);
    printDateName();
    return 31;
  case 10:
    printf("November %d\n", targetYear);
    printDateName();
    return 30;
  case 11:
    printf("December %d\n", targetYear);
    printDateName();
    return 31;
  default :
    break;
  }
  return 0;
}//printMonthTitle 

int printMonth(int numOfDays, int startingDate){                   //consider the number of days of this month and the starti
  int date = 1;                                                    //-ing postion of the first day and print the dates
  int currentDay = 0;                                              //finally return the starting position of next month

  //currentDay must be less than startingDate here
  while(currentDay < startingDate){
    //currentDay must be less than startingDate here
      printf("    ");
      currentDay = (currentDay + 1) % 7;
  }
  //currentDay must equals or is larger than startingDate here

  //date must be less than numOfDays here
  while(date <= numOfDays){
    //date must be less than numOfDays here
      printf("%4d", date);
      if(currentDay == 6){
	printf("\n");
      }
      currentDay = (currentDay + 1) % 7;
      date++;
  }
  //date must equals or is larger than numOfDays here
  printf("\n\n");
  return currentDay;
}//printMonth

void printCalendar(int targetYear){                               //consider the target year and calculate the starting date
  printf("\t*** CARLENDAR for %d ***\n", targetYear);             //of the target year
  int startingDate = getStartingDate(targetYear);                 //print 12 months using for-loop
  //use for-loop to loop through 12 months  
  for(int i = 0; i < 12; i++){
    //i must be less than 12 here
    startingDate = printMonth(printMonthTitle(targetYear, i), startingDate);
  }
}//printCarlendar



int main(void){
  int numOfYear;
  printf("\t\tMONTH CALENDAR\nPlease enter your year for this carlender: -");
  scanf("%d", &numOfYear);
  printCalendar(numOfYear);
  return 0;
}
