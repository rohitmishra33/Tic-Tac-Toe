// X and O
#include<stdio.h>
#include<stdlib.h>
char ch,user,pc,xo[3][3]={'-','-','-','-','-','-','-','-','-'};
int noofmoves=2,flag=0,level;
void print() // prints the tic-tac-toe maze
{
	int i,j;
	system("cls");
	printf("\n\n");
	printf("\n---------------");
	for(i=0;i<3;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
			printf("   %c",xo[i][j]);
		printf("\n---------------");
	}
	printf("\n\n");
}
inline void winner(char w)
{
	if(w==user)
		printf("Congratulations !!! You Win !!!");
	else if(w==pc)
		printf("Computer Wins !!!");
}
void check() // checks the winner of the game
{
	int i;
	for(i=0;i<3;i++)
	{
		if(xo[i][0]==xo[i][1] && xo[i][1]==xo[i][2])
		{
			if(xo[i][0]=='-')
				return;
			winner(xo[i][0]);
			exit(0);
		}
		else if(xo[0][i]==xo[1][i] && xo[1][i]==xo[2][i])
		{
			if(xo[0][i]=='-')
				return;
			winner(xo[0][i]);
			exit(0);
		}
		else if( (xo[0][0]==xo[1][1] && xo[1][1]==xo[2][2]) || (xo[0][2]==xo[1][1] && xo[1][1]==xo[2][0]) )
		{
			if(xo[1][1]=='-')
				return;
			winner(xo[1][1]);
			exit(0);
		}
	}
}
void checktostop() // smart move
{
	int i;
	if(xo[1][1]=='-')
		{xo[1][1]=pc;flag=1;return;}
	for(i=0;i<3;i++)
	{
		if(xo[i][0]==xo[i][1] || xo[i][1]==xo[i][2] || xo[i][0]==xo[i][2])
		{
			if(xo[i][0]=='-' && xo[i][1]==user && xo[i][2]==user)
				{xo[i][0]=pc;flag=1;return;}
			if(xo[i][1]=='-' && xo[i][0]==user && xo[i][2]==user)
				{xo[i][1]=pc;flag=1;return;}
			if(xo[i][2]=='-' && xo[i][0]==user && xo[i][1]==user)
				{xo[i][2]=pc;flag=1;return;}
		}
		if(xo[0][i]==xo[1][i] || xo[1][i]==xo[2][i] || xo[0][i]==xo[2][i])
		{
			if(xo[0][i]=='-' && xo[1][i]==user && xo[2][i]==user)
				{xo[0][i]=pc;flag=1;return;}
			if(xo[1][i]=='-' && xo[0][i]==user && xo[2][i]==user)
				{xo[1][i]=pc;flag=1;return;}
			if(xo[2][i]=='-' && xo[0][i]==user && xo[1][i]==user)
				{xo[2][i]=pc;flag=1;return;}
		}
		if( (xo[0][0]==xo[1][1] || xo[1][1]==xo[2][2] || xo[0][0]==xo[2][2]) || (xo[0][2]==xo[1][1] || xo[1][1]==xo[2][0] || xo[0][2]==xo[2][0]) )
		{
			if(xo[0][0]=='-' && xo[1][1]==user && xo[2][2]==user)
				{xo[0][0]=pc;flag=1;return;}
			if(xo[1][1]=='-' && ( (xo[0][0]==user && xo[2][2]==user) || (xo[0][2]==user && xo[2][0]==user) ) )
				{xo[1][1]=pc;flag=1;return;}
			if(xo[2][2]=='-' && xo[0][0]==user && xo[1][1]==user)
				{xo[2][2]=pc;flag=1;return;}
			if(xo[0][2]=='-' && xo[1][1]==user && xo[2][0]==user)
				{xo[0][2]=pc;flag=1;return;}
			if(xo[2][0]=='-' && xo[1][1]==user && xo[0][2]==user)
				{xo[2][0]=pc;flag=1;return;}
		}
	}
	if(xo[2][0]!='-')
		return;
	else if(xo[1][1]!='-' && xo[0][0]!='-' && xo[2][2]!='-')
		{xo[2][0]=pc;flag=1;return;}
	else if(xo[0][2]!='-')
		return;
	else if(xo[0][2]!='-' && xo[1][1]!='-' && xo[2][0]!='-')
		{xo[2][2]=pc;flag=1;return;}
}
void checktowin() // smarter move
{
	int i;
	if(level==2)
		goto level2;
	for(i=0;i<3;i++)
	{
		if(xo[i][0]==xo[i][1] || xo[i][1]==xo[i][2] || xo[i][0]==xo[i][2])
		{
			if(xo[i][0]=='-' && xo[i][1]==pc && xo[i][2]==pc)
				{xo[i][0]=pc;flag=1;return;}
			if(xo[i][1]=='-' && xo[i][0]==pc && xo[i][2]==pc)
				{xo[i][1]=pc;flag=1;return;}
			if(xo[i][2]=='-' && xo[i][0]==pc && xo[i][1]==pc)
				{xo[i][2]=pc;flag=1;return;}
		}
		if(xo[0][i]==xo[1][i] || xo[1][i]==xo[2][i] || xo[0][i]==xo[2][i])
		{
			if(xo[0][i]=='-' && xo[1][i]==pc && xo[2][i]==pc)
				{xo[0][i]=pc;flag=1;return;}
			if(xo[1][i]=='-' && xo[0][i]==pc && xo[2][i]==pc)
				{xo[1][i]=pc;flag=1;return;}
			if(xo[2][i]=='-' && xo[0][i]==pc && xo[1][i]==pc)
				{xo[2][i]=pc;flag=1;return;}
		}
		if( (xo[0][0]==xo[1][1] || xo[1][1]==xo[2][2] || xo[0][0]==xo[2][2]) || (xo[0][2]==xo[1][1] || xo[1][1]==xo[2][0] || xo[0][2]==xo[2][0]) )
		{
			if(xo[0][0]=='-' && xo[1][1]==pc && xo[2][2]==pc)
				{xo[0][0]=pc;flag=1;return;}
			if(xo[1][1]=='-' && ( (xo[0][0]==pc && xo[2][2]==pc) || (xo[0][2]==pc && xo[2][0]==pc) ) )
				{xo[1][1]=pc;flag=1;return;}
			if(xo[2][2]=='-' && xo[0][0]==pc && xo[1][1]==pc)
				{xo[2][2]=pc;flag=1;return;}
			if(xo[0][2]=='-' && xo[1][1]==pc && xo[2][0]==pc)
				{xo[0][2]=pc;flag=1;return;}
			if(xo[2][0]=='-' && xo[1][1]==pc && xo[0][2]==pc)
				{xo[2][0]=pc;flag=1;return;}
		}
	}
	level2:
	checktostop();
}
void computer() // computer's move
{
	int i,j;
	flag=0;
	if(level==1)
		goto random;
	if(noofmoves>9)
	{
		printf("\nGAME DRAW !!!");
		exit(0);
	}
	checktowin();
	if(flag==1)
		return;
	random:
	i=rand()%3;
	j=rand()%3;
	if(xo[i][j]=='-')
		xo[i][j]=pc;
	else
		goto random;
}
void player() // player's move
{
	int x,y,ch;
	coordinates:
	printf("\nEnter your desired place: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: x=0;y=0;break;
		case 2: x=0;y=1;break;
		case 3: x=0;y=2;break;
		case 4: x=1;y=0;break;
		case 5: x=1;y=1;break;
		case 6: x=1;y=2;break;
		case 7: x=2;y=0;break;
		case 8: x=2;y=1;break;
		case 9: x=2;y=2;break;
		default:
			printf("\nPlease Enter Valid Values !!!");
			goto coordinates;
	}
	if(xo[x][y]=='-')
		xo[x][y]=user;
	else
	{
		printf("\nPlease Enter Vaild Values !!!");
		goto coordinates;
	}
	print();
	check();
	computer();
	print();
	check();
}
void main()
{
	int i,j,cnt;
	enter:
	cnt=1;
	system("cls");
	printf("------------------WELCOME TO THE GAME OF TIC-TAC-TOE------------------");
	printf("\n\n\nUSE THE FOLLOWING NUMBERS TO PLAY YOUR MOVE IN THE RESPECTIVE POSITION\n");
	printf("\n---------------");
	for(i=0;i<3;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
		{
			printf("   %d",cnt);
			cnt++;
		}
		printf("\n---------------");
	}
	printf("\n\nSelect Difficulty Level");
	printf("\n\n1. Easy");
	printf("\n2. Medium");
	printf("\n3. Hard");
	printf("\n\nEnter Difficulty Level: ");
	scanf("%d",&level);
	printf("\nSelect Your Mark (X or O): ");
	scanf("\n");
	scanf("%c",&ch);
	switch(ch)
	{
		case 'o':
		case 'O':
		case '0':
			user='O';
			pc='X';
			break;
		case 'x':
		case 'X':
			user='X';
			pc='O';
			break;
		default:
			printf("\n\nPlease Enter a Valid Choice !!!\n");
			for(i=0;i<10;i++)
				for(j=0;j<10000000;j++);
			goto enter;
	}
	printf("\n\n\n");
	printf("Loading Maze\n");
	for(i=0;i<50;i++)
	{
		for(j=0;j<10000000;j++);
		printf(".");
	}
	print();
	for(;;)
	{
		player();
		noofmoves+=2;
	}
}