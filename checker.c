#include <stdio.h>
#include <assert.h>

#define MaxTemp 45.0
#define MinTemp 0.0
#define MaxSoc 80.0
#define MinSoc 20.0
#define MaxChargeRate 0.8
#define MinChargeRate 0.0
#define threshold 4.99

int checkTemperature;
int checkChargeRate;
int checkSoc;

char error[15];

int ValidateMeasure(float value, float Max, float Min)
{
    int high_delta, low_delta;
    
    high_delta = abs(value - Max);
    low_delta = abs(Min - value);
   
    if((high_delta | low_delta) > threshold)
    {
        printf("ERROR: Invalid meassuremnts, check the sensors.\n");
        return 1;
    }
    
    
    else
    {
        printf("WARNING: meassuremnts exceed the max and min levels, but are in threshold range\n");
        return 0;
    }
}

int batteryIsOk(int checkChargeRate, int checkSoc, int checkTemperature) {
  if(checkChargeRate && checkSoc && checkTemperature)
  {
    printf("The battery is OK\n");
    return 1;
  }
  else
  {
    printf("The battery is NOT_OK\n");
    return 0;
  }
  
}

void printError( char error[])
{
  printf("Error in parameter: %s\n", error);
}

int CheckRangeForEverything( float value, float Max, float Min, char Testedparameter[])
{
  if( value > Min && value < Max)
  {
    printf("Passed parameter: %s\n", Testedparameter);
    return 1;
  }
  else
  {
    ValidateMeasure(value, Max, Min);
    printError(Testedparameter);
    return 0;
   }

}

int main() {
  checkChargeRate = CheckRangeForEverything(25,MaxChargeRate, MinChargeRate, "ChargeRate");
  checkSoc = CheckRangeForEverything(50, MaxSoc, MinSoc, "Soc");
  checkTemperature = CheckRangeForEverything(15, MaxTemp, MinTemp, "Temperature");
}
