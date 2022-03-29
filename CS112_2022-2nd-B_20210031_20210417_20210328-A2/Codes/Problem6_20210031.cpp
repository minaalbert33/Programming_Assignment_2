// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: Problem6_20210031.cpp
// Program Description: 
	// In summary this problem required to calculate 6 taxes given salary
// Last Modification Date: 23/03/2022
// Author1 and ID and Group: 20210031 	Group :B
// Teaching Assistant: Dr. Mohammad El-Ramly
// Purpose: To solve Taxes problem #5

# include <iostream>
using namespace std;


// This function taking num and percentage tax like 15%, and return tax of this num
double calculate_tax(int num, double percentage)
{
    double ans = (num * percentage) / 100.0;
    return ans;
}

void calculator(int hours, int dependents)
{
	// Check if there is overtime hours so I take minumun value of 40 or worked hours
    int main_hours = min(hours, 40);
	// Maybe there is no overtime hours so (hours - 40) gonna be negative so I took maximum of it and 0
    int overtime_hours = max(hours - 40, 0);
	// Here calculate every Tax by calling calculate_tax function
    double gross_pay_without_overtime = main_hours * 16.78;
    double gross_pay_with_overtime = overtime_hours * (16.78 * 1.5);
    double total_gross_pay  = gross_pay_without_overtime + gross_pay_with_overtime;
    double social_security_tax = calculate_tax(total_gross_pay, 6);
    double federal_income_tax = calculate_tax(total_gross_pay, 14);
    double state_income_tax = calculate_tax(total_gross_pay, 5);
    int union_dues = 10;
    int extra_cost_of_health_insurance = 0;
	// Check if there is 3 or more dependents
    if(dependents >= 3)
    {
        extra_cost_of_health_insurance = 35;
    }
	// Calculate total_tax
    double total_tax = social_security_tax + federal_income_tax + state_income_tax + union_dues + extra_cost_of_health_insurance;
	// Calculate remaining gross pay after paying all taxes 
    double gross_pay_after_taxes = total_gross_pay - total_tax;
	// Print all taxes 
    cout<<"Total Gross pay = $"<<total_gross_pay<<endl;
    cout<<"Withhold amount for Social Security tax = $"<<social_security_tax<<endl;
    cout<<"Withhold amount for federal income tax = $"<<federal_income_tax<<endl;
    cout<<"Withhold amount for state income tax = $"<<state_income_tax<<endl;
    cout<<"Withhold amount for union dues = $"<<union_dues<<endl;
    cout<<"Withhold amount for extra cost of health insurance = $"<<extra_cost_of_health_insurance<<endl;
    cout<<"Net take-home pay for the week = $"<<gross_pay_after_taxes<<endl;

}
int main()
{
    int hours = 1, dependents;
	// Program Running untill choice is not 0	
    while (true) {
		// Take hours as input
        cout<<"Please enter number of hours worked in a week or 0 to exit"<<endl;
        cin>>hours;
		// Check if it zero to terminate
        if(hours == 0)
            return 0;
        cout<<"Please enter the number of dependents"<<endl;
        cin>>dependents;
		// Call main function
        calculator(hours, dependents);

    }
    return 0;
}
