#include<iostream>
using namespace std;
int main()
{
  double base_fare = 3.20; //entering problem variables
  double fare_per_km =2.05;
  double fare_per_min =0.95;
  double x;
  double y;
  int z;
  cout<<"note:there is an extra 15 "<<'%'<<" charge from 11pm till 6am\n\n";        // note message to notify the user
  cout<<"enter the journey start time in 24-hours format ex:(6 pm is 1800,6 am is 0600) :";
  cin>>z;                                                                                   // inputing the start time
  cout<<"enter the journey duration in minutes :";
  cin>>x;                                                                                   // inputing duration
  cout<<"enter the journey distance in kilo meters :";
  cin>>y;                                                                                   // inputing distance
  if (z<2300&&z>600)                                                                      // if statment to apply the extra charge
  {
  cout<<"your ride fare is :"<<(base_fare+(x*fare_per_min)+(y*fare_per_km))<<" $";      // showing the ride fare
  }
  else{
  cout<<"your ride fare is :"<<(base_fare+(x*fare_per_min)+(y*fare_per_km))*0.15+(base_fare+(x*fare_per_min)+(y*fare_per_km))<<" $"; //showing the ride fare with the extra charge
  }
  return 0;
}
