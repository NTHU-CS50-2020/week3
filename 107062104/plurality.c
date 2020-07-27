#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Add max votes
    //candidates[candidate_count].name = "MAX_VOTES";
    //candidates[candidate_count].votes = 0;

    // Find votee
    for(int i = 0; i<candidate_count; i++)
    {
        if(!strcmp(candidates[i].name, name))
        {
            candidates[i].votes++;

            //record the max votes
            //if(candidates[i].votes>candidates[candidate_count].votes)
            //{
            //    candidates[candidate_count].votes = candidates[i].votes;
            //}

            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int max_votes = 0, winner_count = 0;
    int winners[candidate_count];

    for(int i = 0; i<candidate_count; i++)
    {
        if(candidates[i].votes>max_votes)
        {
            winner_count = 0;
            max_votes = candidates[i].votes;
            winners[winner_count++] = i;
        }else if(candidates[i].votes == max_votes){
            winners[winner_count++] = i;
        }
        //if(candidates[i].votes == candidates[candidate_count].votes)
        //{
        //    printf("%s\n", candidates[i].name);
        //}
    }
    for(int i = 0; i<winner_count;i++)
    {
        printf("%s\n", (candidates[winners[i]]).name);
    }
    return;
}

