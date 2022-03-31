/*
    File: miner.h

    Author: Tingwei Su
            Department of Electrical and Computer Engineering
            Texas A&M University
    Date  : 
    Update: 

    Description: 
*/

#define SIM_MAX 1500
#define HUNDREAD_PERSENT 100

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;


class Miner_Pool{
    private:
        unsigned long id;
        double selfish_hash_power; // alpha
        double network_delay; // lamda * delta
        double honest_hash_power;
        unsigned int public_chain_length;
        unsigned int private_selfish_chain_length;
        unsigned int private_honest_chain_length;

        unsigned int honest_blocks_num;
        unsigned int selfish_blocks_num;
        unsigned int total_blocks_num;

        double sim_buffer[SIM_MAX];
        double revenue_avg[HUNDREAD_PERSENT];
        unsigned int sim_id; // max: 50 (50%)


        ofstream result_file;
        string result_file_name;

    public:
        Miner_Pool(unsigned long _id, double _network_delay);
        /* Initializes the data structures needed for the miner object 
        * _id is the identity of the miner pool.
        * _network_delay is the network delay that we will take into consideration
        * */
        void Set_Selfish_Hash_Power(double _selfish_hash_power);
        /* Method when the miner pool is mining
        * return: fail (1) or not (0)
        * _selfish_hash_power is the % of the hash power the selfish miner owned.
        * */
        unsigned long On_Mining(int transactions, int id, int runs);
        /* Method when the miner pool is mining
        * return: fail (1) or not (0)
        * 
        * */
       unsigned long Broadcast_Private_Chain();
        /* Method when the miner decide to broadcast the private chain to public
        * return: the private chain length
        * 
        * */
        void Add_Block_to_Chain(char _integrity);
        /* Methods to add block to the Chain 
        * _integrity is determined by whether the miner is honest or selfish 
        * */
        void Fork_Chain(unsigned long longest_length);
        /* Methods to fork chain to the longest Chain which will cause the length of 
        * the chain be reset to current longest chain
        * */
        double Req_Revenue_Avg(int id);
        /* Methods to request the length of the chain
        * 
        * */
        void Report_Chain_Data(char mode);
        /* Methods to report the Chain data
        * 
        * */
        void Reset_Data();
        /* Methods to reset the Chain data
        * 
        * */
        void Save_Data();
        /* Methods to reset the Chain data
        * 
        * */
       
};
