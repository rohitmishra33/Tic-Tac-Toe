/** Tic-Tac-Toe **/

using namespace std;
#include<iostream>
#include<stdlib.h>

char ch,user,pc,xo[3][3]={'-','-','-','-','-','-','-','-','-'};
int noofmoves=2,flag=0;
void print() 		/// Prints the tic-tac-toe maze
{
	int i,j;
	system("clear");
	cout<<"\n\n";
	cout<<"\n---------------";
	for(i=0;i<3;i++)
	{
		cout<<"\n";
		for(j=0;j<3;j++)
			cout<<"   "<<xo[i][j];
		cout<<"\n---------------";
	}
	cout<<"\n\n";
}
inline void winner(char w)	///Prints the winner of the game
{
	if(w==user)
		cout<<"Congratulations !!! You Win !!!"<<endl;
	else if(w==pc)
		cout<<"Computer Wins !!!"<<endl;
}
void check() /// Checks the winner of the game
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
void checktostop() /// Computer plays a move to stop the player from winning
{
	int i;
	for(i=0;i<3;i++)
	{
		if(xo[1][1]=='-')
			{xo[1][1]=pc;flag=1;return;}
		if(xo[1][1]==user && xo[0][0]=='-')
			{xo[0][0]=pc;flag=1;return;}
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
}
void checktowin() /// Computer plays a move to win by completing three in a row/column/dioganally
{
	int i;
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
	checktostop();
}
void computer() // computer's move
{
	int i,j;
	flag=0;
	if(noofmoves>9)
	{
		cout<<"\nGAME DRAW !!!\n";
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
void player() /// player's move
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
	computer();
	print();
	check();
}
int main()
{
	int i,j,cnt;
	enter:
	cnt=1;
	system("clear");
	cout<<"------------------WELCOME TO THE GAME OF TIC-TAC-TOE------------------";
	cout<<"\n\n\nUSE THE FOLLOWING NUMBERS TO PLAY YOUR MOVE IN THE RESPECTIVE POSITION\n";
	cout<<"\n---------------";
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
	cout<<"\n\n\n";
	cout<<"Loading Maze\n";
	for(i=0;i<50;i++)
	{
		for(j=0;j<10000000;j++);
			cout<<".";
	}
	print();
	for(;;)
	{
		player();
		noofmoves+=2;
	}
	return 0;
}