#include <stdio.h>
#include <assert.h>

#define MaxTemp 45.0
#define MinTemp 0.0
#define MaxSoc 80.0
#define MinSoc 20.0
#define MaxChargeRate 0.8
#define MinChargeRate 0.0

int checkTemperature;
int checkChargeRate;
int checkSoc;

char error[15];

int batteryIsOk(int checkChargeRate, int checkSoc, int checkTemperature) {
  if(checkChargeRate && checkSoc && checkTemperature)
  {
    printf("The battery is OK");
    return 1;
  }
  else
  {
    printf("The battery is NOT_OK");
    return 0;
  }
  
}

void printError( char error[])
{
  printf("Error in parameter: %s, Value out of range", error);
}

int CheckRangeForEverything( float value, float Max, float Min, char Testedparameter[])
{
  if( value > Min && value < Max)
  {
    return 1;
  }
  else
  {
     printError(Testedparameter);
     return 0;
   }

}

int main() {

  assert(batteryIsOk(0, 1, 0) == 0);
  assert(batteryIsOk(1,1,1)== 1);
  assert(CheckRangeForEverything(25,MaxChargeRate, MinChargeRate, "ChargeRate"));
  assert(CheckRangeForEverything(50, MaxSoc, MinSoc, "Soc"));
  assert(CheckRangeForEverything(15, MaxTemp, MinTemp, "Temperature"));
  assert(CheckRangeForEverything(40, 40, 30, "Temperature"));
  
 
}
