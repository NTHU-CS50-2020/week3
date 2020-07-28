#include <stdio.h>
#include <cs50.h>
#include <string.h>
#define MAX_CANDIDATES 9
#define MAX_VOTERS

bool vote(int voter,int rank, string name)
{
    int u=0;
    for (int i = 0; i<=rank ; i++)
    {
        if(strcmp(name,candidates[i].name)==0)
        {
            preference[voter][rank]=i;
            return true;
        }
    }
    return false;
}
void tabulate(int rank,int voter)
{
    for (int i = 0; i<=rank ; i++)
    {
        if(candidates[i].eliminated)
        {
            candidates[preference[voter][rank]].votes++;
        }
    }
}
//print_winner,find_min,is_tie,eliminate
bool print_winner(int n)
{
    for (int i = 0; i<=rank ; i++)
    {
        if(candidates[i].votes>=(n+1)/2)return true;
    }
    return false;
}

 two-dimensional array preferences
 voter number
 preferences[i][j] here will store the index of the candidate 
 who is the jth preference for voter i.
 
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

candidate candidates[MAX_CANDIDATES];

int preference[MAX_VOTERS][MAX_CANDIDATES];
//MAX_VOTERS for the maximum number of voters in the election.
//MAX_CANDIDATES for the maximum number of candidates in the election

voter_count
candidate_count

int main(int c,string a[])
{
    for (int i = 1; i<=c-1 ; i++)
    {
        candidates[i-1].name=a[i];
    }
    
    int MAX_VOTERS = get_int("Number of voters:");
    
    for (int i = 1; i<=MAX_VOTERS ; i++)
    {
        for (int r = 1; r<=c-1 ; r++)
        {
            string name = get_string("Rank %i:",r);
            if(!vote(i-1,r-1,name))
            {
                printf("Invalid vote.\n");
                r--;
            }
            printf("\n");
        }
    }
    int rank=c-2;
    do{
    tabulate(rank,int voter)
    
    }while(print_winner(c-2))

}