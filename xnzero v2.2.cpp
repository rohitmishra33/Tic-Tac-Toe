/** This is a single player Tic-Tac-Toe game **/
using namespace std;
#include<iostream>
#include<stdlib.h>
char ch,user,pc,xo[3][3]={'-','-','-','-','-','-','-','-','-'};
int noofmoves=2,flag=0,draw=0,winlose=0,level;
void print() // prints the tic-tac-toe maze
{
	int i,j,cnt=1;
	system("cls");
	cout<<"\n\n\nUSE THE FOLLOWING NUMBERS TO PLAY YOUR MOVE IN THE RESPECTIVE POSITION\n\n---------------";
	for(i=0;i<3;i++)
	{
		cout<<"\n";
		for(j=0;j<3;j++)
		{
			cout<<"   "<<cnt;
			cnt++;
		}
		cout<<"\n---------------";
	}
	cout<<"\n\n\n---------------";
	for(i=0;i<3;i++)
	{
		cout<<"\n";
		for(j=0;j<3;j++)
			cout<<"   "<<xo[i][j];
		cout<<"\n---------------";
	}
	cout<<"\n\n";
}
inline void winner(char w) // checks whether the player or the computer has won the game
{
	if(w==user)
		cout<<"Congratulations !!! You Win !!!";
	else if(w==pc)
		cout<<"Computer Wins !!!";
}
void check() // checks if there is a winner of the game at a particular instance
{
	int i;
	for(i=0;i<3;i++)
	{
		if(xo[i][0]==xo[i][1] && xo[i][1]==xo[i][2])
		{
			if(xo[i][0]=='-')
				return;
			winner(xo[i][0]);winlose=1;
		}
		else if(xo[0][i]==xo[1][i] && xo[1][i]==xo[2][i])
		{
			if(xo[0][i]=='-')
				return;
			winner(xo[0][i]);winlose=1;
		}
		else if( (xo[0][0]==xo[1][1] && xo[1][1]==xo[2][2]) || (xo[0][2]==xo[1][1] && xo[1][1]==xo[2][0]) )
		{
			if(xo[1][1]=='-')
				return;
			winner(xo[1][1]);winlose=1;
		}
		if(winlose==1)
			return;
	}
}
void checktostop() // computer's move so as to stop the player from winning
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
	if(xo[2][1]!='-')
		return;
	else if(xo[1][1]!='-' && xo[0][0]!='-' && xo[2][2]!='-')
		{xo[2][1]=pc;flag=1;return;}
	else if(xo[0][1]!='-')
		return;
	else if(xo[0][2]!='-' && xo[1][1]!='-' && xo[2][0]!='-')
		{xo[0][1]=pc;flag=1;return;}
}
void checktowin() // computer's move so as to win the game itself if the player's not winning
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
void computer() // Decides the computer's moves
{
	int i,j;
	flag=0;
	if(level==1)
		goto random;
	if(noofmoves>9)
	{
		draw=1;
		return;
	}
	checktowin();
	if(flag==1)
		return;
random:
	i=rand()%3;j=rand()%3;
	if((i+j)%2==0 && xo[i][j]=='-')
		xo[i][j]=pc;
	else
		goto random;
}
void player() // player's move
{
	int x,y,ch;
coordinates:
	cout<<"\nEnter your desired place: ";
	cin>>ch;
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
			cout<<"\nPlease Enter Valid Values !!!";
			goto coordinates;
	}
	if(xo[x][y]=='-')
		xo[x][y]=user;
	else
	{
		cout<<"\nPlease Enter Vaild Values !!!";
		goto coordinates;
	}
	print();
	check();
	if(draw==1 || winlose==1)
		return;
	computer();
	print();
	check();
}
int main() // drives the program through a menu and makes all function calls as and when needed
{
enter:
	int i,j,cnt=1;
	char ch;
	system("cls");
	cout<<"------------------WELCOME TO THE GAME OF TIC-TAC-TOE------------------";
	cout<<"\n\n\nUSE THE FOLLOWING NUMBERS TO PLAY YOUR MOVE IN THE RESPECTIVE POSITION\n\n---------------";
	for(i=0;i<3;i++)
	{
		cout<<"\n";
		for(j=0;j<3;j++)
		{
			cout<<"   "<<cnt;
			cnt++;
		}
		cout<<"\n---------------";
	}
	cout<<"\n\nSelect Difficulty Level";
	cout<<"\n\n1. Easy";
	cout<<"\n2. Medium";
	cout<<"\n3. Hard";
	cout<<"\n\nEnter Difficulty Level: ";
level:
	cin>>level;
	if(level>3 || level<1)
	{
		cout<<"\n\nPlease Enter a Valid Choice !!! : ";
		goto level;
	}
	cout<<"\nSelect Your Mark (X or O): ";
	cin>>ch;
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
			cout<<"\n\nPlease Enter a Valid Choice !!!\n";
			for(i=0;i<10;i++)
				for(j=0;j<10000000;j++);
			goto enter;
	}
	cout<<"\n\n\nLoading Maze\n";
	for(i=0;i<50;i++)
	{
		for(j=0;j<10000000;j++);
			cout<<".";
	}
	print();
	for(;;)
	{
		player();
		if(draw==1)
		{
			cout<<"GAME DRAW !!!";
			break;
		}
		else if(winlose==1)
			break;
		noofmoves+=2;
	}
again:
	cout<<"\n\nDo you want to play again? (Y/N): ";
	cin>>ch;
	switch(ch)
	{
		case 'y':
		case 'Y':
			noofmoves=2,flag=0,draw=0,cnt=0,winlose=0;
			xo[0][0]='-';xo[0][1]='-';xo[0][2]='-';xo[1][0]='-';xo[1][1]='-';xo[1][2]='-';xo[2][0]='-';xo[2][1]='-';xo[2][2]='-';
			goto enter;
		case 'n':
		case 'N':
			cout<<"\n\nThank You for Playing !!!\n\n";
			cout<<"\n\n\nTHE GAME IS EXITING\n";
			for(i=0;i<50;i++)
			{
				for(j=0;j<10000000;j++);
				cout<<".";
			}
			cout<<endl;
			system("cls");
			exit(0);
		default:
			cout<<"\nPlease enter a valid choice !!!";
			goto again;
	}
	return 0;
}