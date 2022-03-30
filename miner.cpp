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

Miner_Pool::Miner_Pool(unsigned long _id, unsigned int _network_delay)
{
    id = _id;
    selfish_hash_power = 0;
    network_delay = _network_delay;
    private_selfish_chain_length = 0;
    public_chain_length = 0;
    total_blocks_num = 0;
    revenue_avg = 0;
    sim_id = 0;

    result_file_name = "result_" + to_string(id) + ".txt";
}

void Miner_Pool::Set_Selfish_Hash_Power(unsigned int _selfish_hash_power) 
{
    selfish_hash_power = _selfish_hash_power;
    honest_hash_power = (HUNDREAD_PERSENT - selfish_hash_power) / (HUNDREAD_PERSENT + (HUNDREAD_PERSENT - selfish_hash_power) * network_delay);
    selfish_hash_power = HUNDREAD_PERSENT - honest_hash_power;
}

unsigned long Miner_Pool::On_Mining(int transactions)
{
    unsigned int i = 0;
    unsigned int rand_num = 0;
    /* initialize random seed: */
    srand (time(NULL));

    while (i < transactions)
    {
        rand_num = rand() % 100 + 1;
        if (rand_num > selfish_hash_power)
        {
            // Honest mining
            public_chain_length ++;
            if ( public_chain_length - private_selfish_chain_length == 0 )
            {
                honest_blocks_num += 1;
            }
        }
        else
        {
            // Selfish mining
            private_selfish_chain_length ++;
            if ( (public_chain_length - private_selfish_chain_length == 0) &&   private_selfish_chain_length == 2)
            {
                private_selfish_chain_length = 0;
                public_chain_length = 0;
                selfish_blocks_num += 2;
            }
        }
        i++;
    }
    
    
    total_blocks_num = honest_blocks_num + selfish_blocks_num;
    if (sim_id < SIM_MAX)
    {
        revenue[sim_id] = 100.0 * selfish_blocks_num / total_blocks_num;
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

unsigned long Miner_Pool::Req_Chain_Len()
{
    return 0;
}

void Miner_Pool::Report_Chain_Data(char mode)
{
    switch (mode)
    {
        case 0: // Normal display
            cout << "==================================\n";
            cout << "Simulator Id: " << id << "\n";
            cout << "Simulation run: " << sim_id << "\n";
            cout << "Block validate by honest miner: " << honest_blocks_num << "\n";
            cout << "Block validate by selfish miner: " << selfish_blocks_num << "\n";
            cout << "Expected honests : " << honest_hash_power * public_chain_length << "\n";
			cout << "Number of total blocks mined : " << public_chain_length << "\n";
			cout << "Revenue ratio = PoolBlocks / TotalBlocks : " << revenue << "\n";
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
    total_blocks_num = 0;
    // preventing overflow 
    cout << "revenue_avg: " << revenue_avg << ", sim_id: " << sim_id << ", revenue[sim_id]: " << revenue[sim_id] << "\n";
    revenue_avg += (revenue[sim_id] - revenue_avg) / (sim_id + 1);
    sim_id++;
    cout << "revenue_avg: " << revenue_avg << ", sim_id: " << sim_id << "\n";
}

void Miner_Pool::Save_Data()
{
    result_file.open (result_file_name, ios_base::app);
    result_file << network_delay << " " << revenue_avg << "\n";
    result_file.close();
}