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
#include <fstream>
#include <stdlib.h>

#include "miner.h"

#define MAX_PERCENTAGE  100
#define MAX_SELFISH_PERCENTAGE  50
#define ARGC_NUM        (1 + 1)
#define NET_DELAY_MAX   1000
#define NUM_TRANSACTION 100


void generate_chart();
void save_to_file(string file_name, double id, double data);

int main(int argc, char *argv[])
{
    // Format of running application
    // ./Selfish_Simulating 120000 35 50 
    int arg_count = argc;
    int i = 0;
    unsigned long runs;
    unsigned int alpha; // same as pi in the question
    unsigned int gamma;
    double lamta[6] = {5, 2, 0.5 ,0.2, 0.05, 0.02}; // "lam"da * del"ta"

    int rand_num = 0;
    int transaction = NUM_TRANSACTION;
    int selfish_hash_power = 0;

    if (argc != ARGC_NUM) {
	    cout << "Need 1 integers as simulation runs \n"; 
	    cout << "Use: <runs of simulation> \n"; 
	    exit(0);
    }
    cout << "argc: " << arg_count << endl;
    runs = atol(argv[--arg_count]);
    cout << "runs: " << runs << endl;

    if (runs > SIM_MAX)
    {
        // out of simulation runs limit
        cout << "Out of range for runs: " << runs << endl;
        return 0;
    }
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
    Miner_Pool miner_pool_sim1(1, lamta[1]);
    Miner_Pool miner_pool_sim2(2, lamta[2]);
    Miner_Pool miner_pool_sim3(3, lamta[3]);
    Miner_Pool miner_pool_sim4(4, lamta[4]);
    Miner_Pool miner_pool_sim5(5, lamta[5]);

    double revenue_0[MAX_SELFISH_PERCENTAGE];
    double revenue_1[MAX_SELFISH_PERCENTAGE];
    double revenue_2[MAX_SELFISH_PERCENTAGE];
    double revenue_3[MAX_SELFISH_PERCENTAGE];
    double revenue_4[MAX_SELFISH_PERCENTAGE];
    double revenue_5[MAX_SELFISH_PERCENTAGE];

    string result_0 = "result_0.txt";
    string result_1 = "result_1.txt";
    string result_2 = "result_2.txt";
    string result_3 = "result_3.txt";
    string result_4 = "result_4.txt";
    string result_5 = "result_5.txt";



    while (selfish_hash_power < MAX_SELFISH_PERCENTAGE)
    {
        selfish_hash_power++;
        i = 0;
        while (i < runs)
        {
            miner_pool_sim0.Set_Selfish_Hash_Power(selfish_hash_power * 0.01);
            miner_pool_sim1.Set_Selfish_Hash_Power(selfish_hash_power * 1.0);
            miner_pool_sim2.Set_Selfish_Hash_Power(selfish_hash_power * 1.0);
            miner_pool_sim3.Set_Selfish_Hash_Power(selfish_hash_power * 1.0);
            miner_pool_sim4.Set_Selfish_Hash_Power(selfish_hash_power * 1.0);
            miner_pool_sim5.Set_Selfish_Hash_Power(selfish_hash_power * 1.0);
            miner_pool_sim0.On_Mining(NUM_TRANSACTION, selfish_hash_power, i);
            miner_pool_sim1.On_Mining(NUM_TRANSACTION, selfish_hash_power, i);
            miner_pool_sim2.On_Mining(NUM_TRANSACTION, selfish_hash_power, i);
            miner_pool_sim3.On_Mining(NUM_TRANSACTION, selfish_hash_power, i);
            miner_pool_sim4.On_Mining(NUM_TRANSACTION, selfish_hash_power, i);
            miner_pool_sim5.On_Mining(NUM_TRANSACTION, selfish_hash_power, i);

            miner_pool_sim0.Reset_Data();
            miner_pool_sim1.Reset_Data();
            miner_pool_sim2.Reset_Data();
            miner_pool_sim3.Reset_Data();
            miner_pool_sim4.Reset_Data();
            miner_pool_sim5.Reset_Data();
            i++;
        }

        revenue_0[selfish_hash_power] = miner_pool_sim0.Req_Revenue_Avg(selfish_hash_power);
        revenue_1[selfish_hash_power] = miner_pool_sim0.Req_Revenue_Avg(selfish_hash_power);
        revenue_2[selfish_hash_power] = miner_pool_sim0.Req_Revenue_Avg(selfish_hash_power);
        revenue_3[selfish_hash_power] = miner_pool_sim0.Req_Revenue_Avg(selfish_hash_power);
        revenue_4[selfish_hash_power] = miner_pool_sim0.Req_Revenue_Avg(selfish_hash_power);
        revenue_5[selfish_hash_power] = miner_pool_sim0.Req_Revenue_Avg(selfish_hash_power);

        save_to_file(result_0, selfish_hash_power, revenue_0[selfish_hash_power]);
        save_to_file(result_1, selfish_hash_power, revenue_1[selfish_hash_power]);
        save_to_file(result_2, selfish_hash_power, revenue_2[selfish_hash_power]);
        save_to_file(result_3, selfish_hash_power, revenue_3[selfish_hash_power]);
        save_to_file(result_4, selfish_hash_power, revenue_4[selfish_hash_power]);
        save_to_file(result_5, selfish_hash_power, revenue_5[selfish_hash_power]);
    }

    return 0;
}

void save_to_file(string file_name, double id, double data)
{
    ofstream result_file;
    result_file.open (file_name, ios_base::app);
    result_file << id << " " << data << endl;
    result_file.close();
}

void generate_chart()
{

}