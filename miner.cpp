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

Miner::Miner(unsigned long _id, unsigned int _hash_power)
{
    id = _id;
    hash_power = _hash_power;
}
int Miner::On_Selfish_Mine()
{
    return 0;
}
int Miner::On_Honest_Mine()
{
    return 0;
}
