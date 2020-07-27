#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for(int i = 0; i<candidate_count; i++)
    {
        if(!strcmp(candidates[i], name))
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for(int i = 0; i<candidate_count; i++)
    {
        for(int j = i+1; j<candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    /*
    for(int i = 0; i<candidate_count; i++)
    {
        for(int j = 0; j<candidate_count; j++)
        {
            printf("%d ", preferences[i][j]);
        }
        printf("\n");
    }
    */
    for(int i = 0; i<candidate_count; i++)
    {
        for(int j = 0; j<i; j++)
        {
            if(preferences[i][j]>preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count++].loser= j;
            }
            else if(preferences[i][j]<preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count++].loser= i;
            }
            else
            {
                //no need to add
            }
        }
    }
    /*
    for(int i = 0; i<pair_count; i++)
    {
        printf("%s -> %s : %d\n", candidates[pairs[i].winner], candidates[pairs[i].loser], preferences[pairs[i].winner][pairs[i].loser]);
    }
    */
    return;
}

int comparePairs(const void *a, const void *b)
{
    const pair *A = (pair*) a;
    const pair *B = (pair*) b;
    return (preferences[B->winner][B->loser] - preferences[A->winner][A->loser]);
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    qsort(pairs, pair_count, sizeof(pair), comparePairs);
    /*
    for(int i = 0; i<pair_count; i++)
    {
        printf("%s -> %s : %d\n", candidates[pairs[i].winner], candidates[pairs[i].loser], preferences[pairs[i].winner][pairs[i].loser]);
    }
    */
    return;
}

bool hasCycle(int src, bool vis[], bool inPath[])
{
    vis[src] = true;
    inPath[src] = true;
    for(int i = 0; i<candidate_count; i++)
    {
        if(locked[src][i])
        {
            if(inPath[i])
            {
                return true;
            }
            else if(!vis[i])
            {
                return hasCycle(i, vis, inPath);
            }
        }
    }
    inPath[src] = false;
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for(int i = 0; i<pair_count; i++)
    {
        bool vis[MAX] = {false};
        bool inPath[MAX] = {false};
        //printf("%d -> %d\n", pairs[i].winner, pairs[i].loser);
        locked[pairs[i].winner][pairs[i].loser] = true;
        if(hasCycle(pairs[i].winner, vis, inPath)||hasCycle(pairs[i].loser, vis, inPath))
        {
            locked[pairs[i].winner][pairs[i].loser] = false;
        }
        /*
        for(int j = 0; j<candidate_count; j++)
        {
            for(int k = 0; k<candidate_count; k++)
            {
                printf("%d ", locked[j][k]);
            }
            printf("\n");
        }
        */
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    for(int i = 0; i<candidate_count; i++)
    {
        bool notWinner = false;
        for(int j = 0; j<candidate_count; j++)
        {
            if(locked[j][i])
            {
                notWinner = true;
                break;
            }
        }
        if(notWinner)
        {
            continue;
        }
        printf("%s\n", candidates[i]);
    }
    return;
}

