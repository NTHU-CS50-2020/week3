#include <stdio.h>
#include <cs50.h>
#include <string.h>
#define MAX_CANDIDATES 9
#define MAX_VOTERS

typedef struct
{
    string name;
    int votes;
    bool involve;
}candidate;

candidate candidates[MAX_CANDIDATES];

int preference[MAX_VOTERS][MAX_CANDIDATES]={};

int ntname(string name)
{
    for (int i = 0; i<=MAX_CANDIDATES-1 ; i++)
    {
        if(strcmp(name,candidates[i].name)==0)
        {
            return i;
        }
    }
    return -1;
}
int find_min(int CANDIDATES)
{
    int k=candidates[CANDIDATES-1].votes;
    for (int i = 0; i<=CANDIDATES-1 ; i++)
    {
        if(k>=candidates[i].votes)k=candidates[i].votes;
    }
    return k;
}

int main(int rr,string a[])
{
    int CANDIDATES=rr-1;
    for (int i = 1; i<=CANDIDATES ; i++)
    {
        candidates[i-1].name=a[i];
    }
    int VOTERS = get_int("Number of voters:");
    for (int VOTER = 0; VOTER<=VOTERS-1 ; VOTER++)
    {
        for (int rank = 0; rank<=CANDIDATES-1 ; rank++)
        {
            string name = get_string("Rank %i:",rank+1);
            if(ntname(name)==-1)
            {printf("Invalid vote.\n");rank--;}
            else preference[VOTER][rank]=ntname(name);
        }
        printf("\n");
    }
    int y=VOTERS;
    do{
        int nowrank=0;

        for (int VOTER = 0; VOTER<=VOTERS-1 ; VOTER++)
        {
            candidates[preference[VOTER][nowrank]].votes++;
            if(candidates[preference[VOTER][nowrank]].votes>=CANDIDATES/2)
            {
                printf("%s",candidates[VOTER].name);
                return 0;
            }
        }
        for (int VOTER = 0; VOTER<=VOTERS-1 ; VOTER++)
        {
            if(preference[VOTER][nowrank]==find_min(CANDIDATES))
            {
                preference[VOTER][nowrank]=preference[VOTER][nowrank+1];
            }
        }
        y--;
    }while(y>=0);
}