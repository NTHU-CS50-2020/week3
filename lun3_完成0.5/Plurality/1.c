#include <stdio.h>
#include <cs50.h>
#include <string.h>
#define MAX 9

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX];

//An election with any number of candidate (up to the MAX of 9)

bool vote(string name,int n)
{

    for (int i = 0; i<=n ; i++)
    {
        if(strcmp(name,candidates[i].name)==0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(int n)
{
    int k=candidates[n].votes;
    for (int i = 0; i<=n ; i++)
    {
        if(k<=candidates[i].votes)k=candidates[i].votes;
    }
    for (int i = 0; i<=n ; i++)
    {
        if(candidates[i].votes==k)printf("%s\n",candidates[i].name);
    }

}

int main(int c,string a[])
{
    if (c < 2)
    {
        printf("Usage:...\n");
        return 1;
    }
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
    print_winner(c-2);
}