/*
    File: miner.h

    Author: Tingwei Su
            Department of Electrical and Computer Engineering
            Texas A&M University
    Date  : 
    Update: 

    Description: 


*/

#include "miner.h"

Miner_Pool::Miner_Pool(unsigned long _id, double _network_delay)
{
    id = _id;
    selfish_hash_power = 0;
    network_delay = _network_delay;
    private_selfish_chain_length = 0;
    public_chain_length = 0;
    total_blocks_num = 0;
    for (int i = 0; i < SIM_MAX; i++)
    {
        sim_buffer[i] = 0;
    }
}

void Miner_Pool::Set_Selfish_Hash_Power(double _selfish_hash_power) 
{
    selfish_hash_power = _selfish_hash_power;
    honest_hash_power = 1 - _selfish_hash_power;
    cout << "[no network delay] selfish_hash_power: " << selfish_hash_power << ", honest_hash_power: " << honest_hash_power << endl;
    honest_hash_power = (1 - selfish_hash_power) / (1 + (1 - selfish_hash_power) * network_delay);
    honest_hash_power = honest_hash_power / (honest_hash_power + selfish_hash_power);
    selfish_hash_power = 1 - honest_hash_power;
    cout << "[network delay] selfish_hash_power: " << selfish_hash_power << ", honest_hash_power: " << honest_hash_power << endl;
}

unsigned long Miner_Pool::On_Mining(int transactions, int id, int runs)
{
    unsigned int i = 0;
    double rand_num = 0;
    sim_id = id;
    /* initialize random seed: */
    srand (time(NULL));

    while (i < transactions)
    {
        // Generate random number to who find the block
        rand_num = (rand() % 100 + 1) / 100.0;
        // cout << "rand_num: " << rand_num << endl;
        if (rand_num > selfish_hash_power)
        {
            // Honest miner find the block
            public_chain_length ++;

            if (private_selfish_chain_length < public_chain_length)
            {
                // Honest miner lead no branch
                honest_blocks_num += 1;
                public_chain_length = 0;
                private_selfish_chain_length = 0;
            }
            else if (private_selfish_chain_length - public_chain_length < 2)
            {
                // selfish miner publish the block
                public_chain_length = 0;
                private_selfish_chain_length = 0;
            }
        }
        else
        {
            // Selfish miner find the block
            private_selfish_chain_length ++;
            selfish_blocks_num++;

            if ( private_selfish_chain_length - public_chain_length >= 1)
            {
                // Selfish miner not publish the block
            }
            else if (private_selfish_chain_length == public_chain_length && private_selfish_chain_length == 1)
            {
                // Selfish miner pulish the 
            }
        }
        i++;
    }

            
    total_blocks_num = selfish_blocks_num + honest_blocks_num;
    cout << "total_blocks_num: " << total_blocks_num << ", selfish_blocks_num: " << selfish_blocks_num << ", honest_blocks_num: " << honest_blocks_num << ", runs: " << runs << endl;
    if (runs < SIM_MAX && total_blocks_num != 0)
    {
        sim_buffer[runs] = 1.0 * selfish_blocks_num / total_blocks_num;
        revenue_avg[sim_id] += (sim_buffer[runs] - revenue_avg[sim_id]) / (runs + 1);
        cout << "revenue_avg[sim_id]: " << revenue_avg[sim_id] << ", sim_id: " << sim_id << endl;
        cout << "sim_buffer[runs]: " << sim_buffer[runs] << ", runs: " << runs << endl;

    }

    return 0;
}

unsigned long Miner_Pool::Broadcast_Private_Chain()
{
    return 0;
}

void Miner_Pool::Add_Block_to_Chain(char _integrity)
{

}

void Miner_Pool::Fork_Chain(unsigned long longest_length)
{

}

double Miner_Pool::Req_Revenue_Avg(int id)
{
    return revenue_avg[id];
}

void Miner_Pool::Report_Chain_Data(char mode)
{
    switch (mode)
    {
        case 0: // Normal display
            cout << "==================================" << endl;
            cout << "Simulator Id: " << id << endl;
            cout << "Simulation run: " << sim_id << endl;
            cout << "Block validate by honest miner: " << honest_blocks_num << endl;
            cout << "Block validate by selfish miner: " << selfish_blocks_num << endl;
            cout << "Expected honests : " << honest_hash_power * public_chain_length << endl;
			cout << "Number of total blocks mined : " << public_chain_length << endl;
			cout << "Revenue ratio = PoolBlocks / TotalBlocks : " << revenue_avg[id] << endl;
            break;
        case 1: // Advanced display
            break;
        default: 
            break;
    }
}

void Miner_Pool::Reset_Data()
{
    private_selfish_chain_length = 0;
    public_chain_length = 0;
    selfish_blocks_num = 0;
    honest_blocks_num = 0;
    total_blocks_num = 0;

    for (int i = 0; i < SIM_MAX; i++)
    {
        sim_buffer[i] = 0;
    }
}

void Miner_Pool::Save_Data()
{
    // Save all simulation to the file: result.txt
    result_file.open (result_file_name, ios_base::app);
    result_file << "Lamda * Delta = " << network_delay <<  endl;
    for (int i = 0; i < sim_id + 1; i++)
    {
        result_file << i << " " << revenue_avg[i] << endl;
    }
    result_file.close();
}