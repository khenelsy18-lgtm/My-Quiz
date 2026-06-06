#include <stdio.h>

#define TEAMS 12

struct Team{
    char name[40];
    int matchesPlayed;
    int wins;
    int draws;
    int losses;
    int goalsScored;
    int goalsConceded;
    int points;
};

int main()
{
    printf("===============================================\n");
    printf(" NATIONAL FOOTBALL TOURNAMENT MANAGEMENT SYSTEM\n");
    printf("===============================================\n");

    struct Team teams[TEAMS];
    int i, j;


    for (i = 0; i < TEAMS; i++)
    {
        printf("\nEnter details for Team %d\n", i + 1);

        printf("Team name: ");
        scanf("%s", teams[i].name);

        printf("Number of Matches played: ");
        scanf("%d", &teams[i].matchesPlayed);

        printf("Number of Wins: ");
        scanf("%d", &teams[i].wins);

        printf("Number of Draws: ");
        scanf("%d", &teams[i].draws);

        printf("Number of Losses: ");
        scanf("%d", &teams[i].losses);

        printf("GoalS Scored in Tournament: ");
        scanf("%d", &teams[i].goalsScored);

        printf("Goals Conceded in Tournament: ");
        scanf("%d", &teams[i].goalsConceded);

        teams[i].points = (teams[i].wins * 3) + teams[i].draws;
    }

    for (i = 0; i < TEAMS - 1; i++)
    {
        for (j = i + 1; j < TEAMS; j++)
        {
            if (teams[j].points > teams[i].points)
            {
                struct Team temp = teams[i];
                teams[i] = teams[j];
                teams[j] = temp;
            }
        }
    }

    printf("\n\n===== LEAGUE TABLE =====\n");

    printf("%-15s %-5s %-5s %-5s %-5s %-5s %-5s %-7s\n",
           "Name", "MP", "W", "D", "L", "GF", "GA", "Pts");

    for (i = 0; i < TEAMS; i++)
    {
        printf("%-15s %-5d %-5d %-5d %-5d %-5d %-5d %-7d\n",
               teams[i].name,
               teams[i].matchesPlayed,
               teams[i].wins,
               teams[i].draws,
               teams[i].losses,
               teams[i].goalsScored,
               teams[i].goalsConceded,
               teams[i].points);
    }

    printf("\nCHAMPION: %s (%d points)\n",
           teams[0].name, teams[0].points);

    printf("\nTOP 3 TEAMS:\n");
    for (i = 0; i < 3; i++)
    {
        printf("%d. %s (%d points)\n", i + 1, teams[i].name, teams[i].points);
    }

    printf("\n BOTTOM 3 TEAMS:\n");
    for (i = TEAMS - 3; i < TEAMS; i++)
    {
        printf("%d. %s (%d points)\n", i + 1, teams[i].name, teams[i].points);
    }

    int totalGoals = 0;
    for (i = 0; i < TEAMS; i++)
    {
        totalGoals += teams[i].goalsScored;
    }
    printf("\nTOTAL GOALS SCORED: %d\n", totalGoals);

    float averageGoals = (float)totalGoals / TEAMS;
    printf("AVERAGE GOALS PER TEAM: %.2f\n", averageGoals);

    return 0;
}
