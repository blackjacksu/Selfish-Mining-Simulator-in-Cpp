/*
    File: main.cpp

    Author: Tingwei Su
            Department of Electrical and Computer Engineering
            Texas A&M University
    Date  : 
    Update: 

    Description: 
*/

#include <iostream>

#define MAX_PERCENTAGE  100
#define ARGC_NUM        5
#define NET_DELAY_MAX   1000

using namespace std;

int init_pool();
void generate_chart();
void result_out();

int main(int argc, char *argv[])
{
    // Format of running application
    // ./Selfish_Simulating 120000 35 50
    unsigned long runs;
    unsigned int alpha;
    unsigned int gamma;
    unsigned int lamta; // "lam"da * del"ta"

    if (argc != ARGC_NUM) {
	    cout << "Need three integers as input \n"; 
	    cout << "Use: <runs of simulation> <alpha (%)> <gamma (%)>\n"; 
	    exit(0);
    }
    cout << "argc: " << argc << "\n";

    runs = atol(argv[ARGC_NUM - 4]);
    
    if ((alpha = atoi(argv[ARGC_NUM - 3])) > MAX_PERCENTAGE) {
	    cout << "Incorrect format in alpha:\n" ;
	    exit(0);
    }; 

    if ((gamma = atoi(argv[ARGC_NUM - 2])) > MAX_PERCENTAGE) {
	    cout << "Incorrect format in gamma:\n" ;
	    exit(0);
    }; 

    if ((lamta = atoi(argv[ARGC_NUM - 1])) > NET_DELAY_MAX) {
	    cout << "Incorrect format in Lamda * Delta, Assuming your input is x, please input in terms of 100 * x\n" ;
	    exit(0);
    }; 

    int i;
    cout << "Please enter an integer value: ";
    cout << "Alpha is " << alpha << "\n";
    cout << "Gamma is " << gamma << "\n";
    cout << "Lamta is " << lamta << "\n";

    return 0;
}

int init_pool()
{
    return 0;
}


void generate_chart()
{

}

void result_out()
{

}