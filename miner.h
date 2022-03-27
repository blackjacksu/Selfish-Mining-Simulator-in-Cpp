/*
    File: miner.h

    Author: Tingwei Su
            Department of Electrical and Computer Engineering
            Texas A&M University
    Date  : 
    Update: 

    Description: 
*/

#include <iostream>


class Miner{
    private:
        unsigned long id;
        unsigned int hash_power;
        unsigned int private_chain_length;

    public:
        Miner(unsigned long _id, unsigned int _hash_power);
        /* Initializes the data structures needed for the miner object 
        * id is the identity of the miner.
        * hash_power is the % of the hash power the miner owned.
        * 
        * */
        int On_Selfish_Mine();
        /* Method when the miner decide to selfish mine on its own chain without broadcast the public
        * 
        * 
        * */
        int On_Honest_Mine();
        /* Method when the miner decide to honest mine with the result broadcast to the public
        * 
        * 
        * */
};
