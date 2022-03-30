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
#include <stdlib.h>

#include "miner.h"

#define MAX_PERCENTAGE  100
#define MAX_SELFISH_PERCENTAGE  50
#define ARGC_NUM        (1 + 1)
#define NET_DELAY_MAX   1000
#define NUM_TRANSACTION 100


void generate_chart();

int main(int argc, char *argv[])
{
    // Format of running application
    // ./Selfish_Simulating 120000 35 50 
    int arg_count = argc;
    unsigned long runs;
    unsigned int alpha; // same as pi in the question
    unsigned int gamma;
    unsigned int lamta[6] = {500, 200, 50 ,20, 5, 2}; // "lam"da * del"ta"

    int rand_num = 0;
    int transaction = NUM_TRANSACTION;
    int selfish_hash_power = 0;

    if (argc != ARGC_NUM) {
	    cout << "Need 1 integers as simulation runs \n"; 
	    cout << "Use: <runs of simulation> \n"; 
	    exit(0);
    }
    cout << "argc: " << arg_count << "\n";
    runs = atol(argv[--arg_count]);
    cout << "runs: " << runs << "\n";

    // if ((alpha = atoi(argv[--arg_count])) > MAX_SELFISH_PERCENTAGE) {
	//     cout << "Incorrect format in alpha:\n" ;
	//     exit(0);
    // }; 
    // cout << "argc: " << arg_count << "\n";
    // if ((gamma = atoi(argv[--arg_count])) > MAX_PERCENTAGE) {
	//     cout << "Incorrect format in gamma:\n" ;
	//     exit(0);
    // }; 

    Miner_Pool miner_pool_sim0(0, lamta[0]);
    // Miner_Pool miner_pool_sim1(1, lamta[1]);
    // Miner_Pool miner_pool_sim2(2, lamta[2]);
    // Miner_Pool miner_pool_sim3(3, lamta[3]);
    // Miner_Pool miner_pool_sim4(4, lamta[4]);
    // Miner_Pool miner_pool_sim5(5, lamta[5]);

    while (selfish_hash_power < MAX_SELFISH_PERCENTAGE)
    {
        selfish_hash_power++;
        miner_pool_sim0.Set_Selfish_Hash_Power(selfish_hash_power);
        // miner_pool_sim1.Set_Selfish_Hash_Power  (selfish_hash_power);
        // miner_pool_sim2.Set_Selfish_Hash_Power  (selfish_hash_power);
        // miner_pool_sim3.Set_Selfish_Hash_Power  (selfish_hash_power);
        // miner_pool_sim4.Set_Selfish_Hash_Power  (selfish_hash_power);
        // miner_pool_sim5.Set_Selfish_Hash_Power   (selfish_hash_power);
        while (runs > 0)
        {   
            transaction = NUM_TRANSACTION;

            miner_pool_sim0.On_Mining(transaction);
            // miner_pool_sim1.On_Mining(transaction);
            // miner_pool_sim2.On_Mining(transaction);
            // miner_pool_sim3.On_Mining(transaction);
            // miner_pool_sim4.On_Mining(transaction);
            // miner_pool_sim5.On_Mining(transaction);
    
            // miner_pool_sim0.Report_Chain_Data(0);
            // miner_pool_sim1.Report_Chain_Data(0);
            // miner_pool_sim2.Report_Chain_Data(0);
            // miner_pool_sim3.Report_Chain_Data(0);
            // miner_pool_sim4.Report_Chain_Data(0);
            // miner_pool_sim5.Report_Chain_Data(0);
        
            miner_pool_sim0.Reset_Data();
            // miner_pool_sim1.Reset_Data();
            // miner_pool_sim2.Reset_Data();
            // miner_pool_sim3.Reset_Data();
            // miner_pool_sim4.Reset_Data();
            // miner_pool_sim5.Reset_Data();
    
            runs --;
        }
        miner_pool_sim0.Save_Data();
        // miner_pool_sim1.Save_Data();
        // miner_pool_sim2.Save_Data();
        // miner_pool_sim3.Save_Data();
        // miner_pool_sim4.Save_Data();
        // miner_pool_sim5.Save_Data();
    }
    


    cout << "Please enter an integer value: ";
    cout << "Alpha is " << alpha << "\n";
    cout << "Gamma is " << gamma << "\n";

    return 0;
}

void generate_chart()
{

}