#include <stdio.h>
#include <stdlib.h>

#define MAX 4//must be even numbers 

struct team
{
	char *name;
	int scheduled;
};

static struct team teams[MAX] = {
	{"Chelsea",0},
	{"Liverpool",0},
	{"Mancity",0},
	{"Manchester",0}
};

static int map[MAX][MAX];//let us to know whether this match has been scheduled

int init_teams()
{
	int i=0;
	for(i=0;i<MAX;i++)
		teams[i].scheduled=0;
	return 0;
}

int main()
{
	int i,j;
	int home,away;
	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++)
			map[i][j]=0;

	printf("Press any key to start schedule...");
	getchar();
	
	srand(time(0));
	i=0;
	while( i<(MAX-1)*2 )
	{
		printf("%d round:",i+1);
		j=0;
		while( j<MAX/2 )
		{	
			home = rand()%MAX;		

			away = home;
			while(away==home)
				away = rand()%MAX;
			if(map[home][away] | teams[home].scheduled | teams[away].scheduled) //if scheduled
			{
				continue;//re-schedule
			}
			else
			{
				map[home][away]=1;
				teams[home].scheduled=1;
				teams[away].scheduled=1;
				j++;//next match in this round
				printf("#<%s,%s>",teams[home].name,teams[away].name);
			}
		}
		init_teams();
		printf("#\n");

		i++;//next round
	}

	return 0;
}
