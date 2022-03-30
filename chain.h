/*
    File: chain.h

    Author: Tingwei Su
            Department of Electrical and Computer Engineering
            Texas A&M University
    Date  : 
    Update: 

    Description: 
*/

#include <iostream>

using namespace std;

enum mode { general, advanced};
enum integrity {honest, selfish};

struct block
{
    unsigned long transaction;
    unsigned long * block;
};

class Chain{
    private:
        unsigned long length;
        unsigned long honest_blocks_num;
        unsigned long selfish_blocks_num;
        struct block * head;

    public:
        Chain(unsigned long _length);
        /* Initializes the data structures needed for the Chain object 
        * id is the identity of the miner.
        * hash_power is the % of the hash power the miner owned.
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
       unsigned long Req_Chain_Len();
        /* Methods to request the length of the chain
        * 
        * */
       void Report_Chain_Data(char mode);
        /* Methods to report the Chain data
        * 
        * */
};