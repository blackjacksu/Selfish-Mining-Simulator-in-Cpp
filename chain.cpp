/*
    File: chain.cpp

    Author: Tingwei Su
            Department of Electrical and Computer Engineering
            Texas A&M University
    Date  : 
    Update: 

    Description: 


*/

#include "chain.h"

Chain::Chain(unsigned long _length)
{
    length = _length;
    honest_blocks_num = 0;
    selfish_blocks_num = 0;
}

void Chain::Add_Block_to_Chain(char _integrity)
{
    if (_integrity == integrity::honest)
    {
        // increment the honest block length by 1
        honest_blocks_num++;
    }
    else
    {
        // increment the selfish block length by 1
        selfish_blocks_num++;
    }
    length++;
}

void Chain::Fork_Chain(unsigned long longest_length)
{
    length = longest_length;
}

unsigned long Chain::Req_Chain_Len()
{
    return length;
}

void Chain::Report_Chain_Data(char mode)
{
    switch (mode)
    {
        case mode::general:
            cout << "Please enter an integer value: ";
            cout << "Block validate by honest miner: " << honest_blocks_num << "\n";
            cout << "Block validate by selfish miner: " << selfish_blocks_num << "\n";
            break;
        case mode::advanced:
            break;
        default: 
            break;
    }
    return;
}
