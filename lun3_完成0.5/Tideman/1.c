#include <stdio.h>
#include <cs50.h>
#include <string.h>
#define MAX 9

//candidates[name];
int preferences[MAX][MAX];
typedef struct
{
    int winner;
    int loser;
}pair;
pair pairs[MAX];
//boolean locked[][];
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;
candidate candidates[MAX];

bool vote(int rank,string name,int ranks[])
{
    return true;
}
void record_preferences(int ranks[])
{

}
void add_pairs(void)
{

}
void sort_pairs(void)
{

}
void lock_pairs(void)
{

}
void print_winner(void)
{

}
int main(int c,string a[])
{

}