#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 9
int preferences[MAX][MAX];
typedef struct
{
    int winner;
    int loser;
}pair;
pair pairs[MAX];
//pair pairs[MAX * (MAX - 1) / 2];
bool locked[MAX][MAX];
typedef struct
{
    string name;
    int votes;
}
candidate;
candidate candidates[MAX];

bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

//公用的~~
int pair_count=0;
int candidate_count=0;

int main(int c,string a[])
{
    if (c < 2)
    {
        printf("Usage:...\n");
        return 1;
    }
    candidate_count = c - 1;
    for (int i = 1; i<=c-1 ; i++)
    {
        candidates[i-1].name=a[i];
    }
    int VOTERS = get_int("Number of voters:");
    for (int VOTER = 0; VOTER<=VOTERS-1 ; VOTER++)
    {
        for (int rank = 0; rank<=CANDIDATES-1 ; rank++)
        {
            string name = get_string("Rank %i:",rank+1);
            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 1;
            }
        }
        record_preferences(ranks);
        printf("\n");
    }
}
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i<=candidate_count-1 ; i++)
    {
        if(strcmp(name,candidates[i].name)==0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

