#include <stdio.h>
#include <cs50.h>
#include <string.h>
#define MAX 9

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
    for (int i = 0; i<=rank ; i++)
    {
        if(strcmp(name,candidates[i].name)==0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}


//candidates[name];
int preferences[MAX][MAX];
typedef struct
{
    int winner;
    int loser;
}pair;
pair pairs[MAX];
//boolean locked[][];



int main(int c,string a[])
{
    for (int i = 1; i<=c-1 ; i++)
    {
        candidates[i-1].name=a[i];
    }
    int candidate_count = get_int("Number of voters:");
    for (int i = 1; i<=candidate_count ; i++)
    {
        string name = get_string("Vote:");
        if(!vote(name,c-2))
        {
            printf("Invalid vote.\n");
        }
    }
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