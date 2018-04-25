#include <stdio.h>  
#include <stdlib.h>  
#include <ctype.h>  
#include <string.h>  
#include <time.h>  
// put any extra includes here, but don't delete the ones above  
  
#define SIZE    4  
  
/* 
    ��Ŀ����˼�������ģ���Ҫ���ϸ��ж��ܷ��ƶ�������flag��ʾ�ƶ���ʱ���ڵڶ����жϵ�ʱ������ˣ� 
 
    ������Ϊ����if(cell==0)��ʱ��ֱ���жϿ����ƶ��Ǵ���ģ������Ƶ�ʱ�����ֻ�� 
 
    �����һ�е�ĳһ��Ԫ��Ϊ0�����������в����ֺϲ���������ǲ������Ƶġ� 
 
        ���������������ƶ��Ĺ����У���if(cell==0)����ǰԪ��Ϊ0ʱҪʹ���ܹ��ƶ����ͱ����������Ϊ0�� 
 
    Ԫ�ز��������һ�У�����ʱ��������һ�У����ƣ����Ҳ��һ�У����ƣ��������һ�У����ƣ��� 
 
        �����޸�ÿ��move�������ж�if(cell==0)�����i����j��ѭ���������Աܿ��ж�ʱ0���ڵ�������λ�� 
 
        �����޸Ŀ����沿��ע�ͣ��޸ĵ�ֻ��ÿ��move�����еڶ���forѭ���е�i����j��ѭ�������� 
 
*/  
  
int moveLeft(int board[SIZE][SIZE]) {  
    int i,j,score=0,flag=-1;  
    for(i=0;i<SIZE;i++)  
    {  
        for(j=0;j<SIZE;j++)  
        {  
            int cell=board[i][j];//cell�����õĲ�̫ǡ������ʾ��ǰԪ�أ�����Բ��ø������������  
            if(cell!=0)  
            {  
                int k=j+1;  
                while(k<SIZE)  
                {  
                    int nextcell=board[i][k];  
                    if(nextcell!=0)  
                    {  
                        if(cell==nextcell)  
                        {  
                            flag=0;//��������Ԫ����ͬ����˵�����ƶ������Ըı�flag��ֵ  
                            board[i][j]+=board[i][k];  
                            score+=board[i][j];  
                            board[i][k]=0;  
                        }  
                        k=SIZE;  
                        break;  
                    }  
                    k++;  
                }  
            }  
        }  
    }  
  
    //�޸Ĳ��֣�forѭ���е�i����j��ѭ������  
  
    for(i=0;i<SIZE;i++)  
    {  
        for(j=0;j<SIZE-1;j++)  
        {  
            int cell=board[i][j];  
            if(cell==0)  
            {  
                int k=j+1;  
                while(k<SIZE)  
                {  
                    int nextcell=board[i][k];  
                    if(nextcell!=0)  
                    {  
                        flag=0;//  
                        board[i][j]=nextcell;  
                        board[i][k]=0;  
                        k=SIZE;  
                    }  
                    k++;  
                }  
            }  
        }  
    }  
    if(flag!=-1)  
        return score;  
    else  
        return -1;  
}  
  
int moveRight(int board[SIZE][SIZE]) {  
    int i,j,score=0,flag=-1;  
    for(i=0;i<SIZE;i++)  
    {  
        for(j=SIZE-1;j>=0;j--)  
        {  
            int cell=board[i][j];  
            if(cell!=0)  
            {  
                int k=j-1;  
                while(k>=0)  
                {  
                    int nextcell=board[i][k];  
                    if(nextcell!=0)  
                    {  
                        if(cell==nextcell)  
                        {  
                            flag=0;  
                            board[i][j]+=board[i][k];  
                            score+=board[i][j];  
                            board[i][k]=0;  
                        }  
                        k=-1;  
                        break;  
                    }  
                    k--;  
                }  
            }  
        }  
    }  
  
     //�޸Ĳ��֣�forѭ���е�i����j��ѭ������  
  
    for(i=0;i<SIZE;i++)  
    {  
        for(j=SIZE-1;j>0;j--)  
        {  
            int cell=board[i][j];  
            if(cell==0)  
            {  
  
                int k=j-1;  
                while(k>=0)  
                {  
                    int nextcell=board[i][k];  
                    if(nextcell!=0)  
                    {  
                        flag=0;//��ǰԪ��Ϊ0��˵�����ƶ����ı�flag��ֵ  
                        board[i][j]=nextcell;  
                        board[i][k]=0;  
                        k=-1;  
                    }  
                    k--;  
                }  
            }  
        }  
    }  
    if(flag!=-1)  
        return score;  
    else  
        return -1;  
}  
  
int moveDown(int board[SIZE][SIZE]) {  
    int i,j,score=0,flag=-1;  
    for(i=SIZE-1;i>=0;i--)  
    {  
        for(j=0;j<SIZE;j++)  
        {  
            int cell=board[i][j];  
  
            if(cell!=0)  
            {  
                int k=i-1;  
                while(k>=0)  
                {  
                    int nextcell=board[k][j];  
                    if(nextcell!=0)  
                    {  
                        if(board[i][j]==board[k][j])  
                        {  
                            flag=0;  
                            board[i][j]+=board[k][j];  
                            score+=board[i][j];  
                            board[k][j]=0;  
                        }  
                        k=0;  
                        break;  
                    }  
                    k--;  
                }  
            }  
        }  
    }  
  
     //�޸Ĳ��֣�forѭ���е�i����j��ѭ������  
    for(i=SIZE-1;i>0;i--)  
    {  
        for(j=0;j<SIZE;j++)  
        {  
            int cell=board[i][j];  
            if(cell==0)  
            {  
                int k=i-1;  
                while(k>=0)  
                {  
                    int nextcell=board[k][j];  
                    if(nextcell!=0)  
                    {  
                        flag=0;  
                        board[i][j]=nextcell;  
                        board[k][j]=0;  
                        k=0;  
                    }  
                    k--;  
                }  
            }  
        }  
    }  
    if(flag!=-1)  
        return score;  
    else  
        return -1;  
}  
  
int moveUp(int board[SIZE][SIZE]) {  
   int i,j,score=0,flag=-1;  
    for(i=0;i<SIZE;i++)  
    {  
        for(j=0;j<SIZE;j++)  
        {  
            int cell=board[i][j];  
  
            if(cell!=0)  
            {  
                int k=i+1;  
                while(k<SIZE)  
                {  
                    int nextcell=board[k][j];  
                    if(nextcell!=0)  
                    {  
                        if(cell==nextcell)  
                        {  
                            flag=0;  
                            board[i][j]+=board[k][j];  
                            score+=board[i][j];  
                            board[k][j]=0;  
                        }  
                        k=SIZE;  
                        break;  
                    }  
                    k++;  
                }  
            }  
        }  
    }  
  
     //�޸Ĳ��֣�forѭ���е�i����j��ѭ������  
    for(i=0;i<SIZE-1;i++)  
    {  
        for(j=0;j<SIZE;j++)  
        {  
            int cell=board[i][j];  
            if(cell==0)  
            {  
  
                int k=i+1;  
                while(k<SIZE)  
                {  
                    int nextcell=board[k][j];  
                    if(nextcell!=0)  
                    {  
                        flag=0;  
                        board[i][j]=nextcell;  
                        board[k][j]=0;  
                        k=SIZE;  
                    }  
                    k++;  
                }  
            }  
        }  
    }  
    if(flag!=-1)  
        return score;  
    else  
        return -1;  
}  
  
// gameOver returns 0 iff it is possible to make a move on the board  
// It returns 1 otherwise.  
  
int gameOver(int board[SIZE][SIZE]) {  
    int copy_board[SIZE][SIZE],i,j;  
    /*Ϊ�˱���ֱ�Ӱ�board[][]����move�����жϵ�ʱ��ı�board�����԰�board���Ƹ� 
    ��һ������,Ȼ���жϣ������Ͳ���ı�board������ 
 
    */  
    for(i=0;i<SIZE;i++)  
    {  
        for(j=0;j<SIZE;j++)  
        {  
            copy_board[i][j]=board[i][j];  
        }  
    }  
    if(moveDown(copy_board)==-1&&moveUp(copy_board)==-1&&moveLeft(copy_board)==-1&&moveRight(copy_board)==-1)//����ĸ��ƶ�����������-1�������ƶ�GameOver  
        return 1;  
    else  
        return 0;  
  
}  
  
// boardContains2048 returns 1 iff the board contains 2048.  
// It returns 0 otherwise.  
  
int boardContains2048(int board[SIZE][SIZE]) {  
    int i,j;  
    for(i=0;i<SIZE;i++)  
    {  
        for(j=0;j<SIZE;j++)  
        {  
            if(board[i][j]==2048)  
                return 1;  
        }  
    }  
    return 0;  
}  
  
// printBoard displays the board.  
  
void printBoard(int board[SIZE][SIZE]) {  
    int i,j;  
  
    printf("+");  
    for(j=0;j<SIZE;j++)  
    {  
        printf("-----");  
    }  
    printf("+\n");  
  
    for(i=0;i<SIZE;i++)  
    {  
        printf("|");  
        for(j=0;j<SIZE;j++)  
        {  
            if(board[i][j]==0)  
            {  
                char a='.';  
               printf("%5c",a);  
            }  
            else  
            {  
                 printf("%5d",board[i][j]);  
            }  
        }  
        printf("|\n\n");  
    }  
  
    printf("+");  
    for(j=0;j<SIZE;j++)  
    {  
        printf("-----");  
    }  
    printf("+\n");  
}  
  
  
// readBoard()���������Ӽ��̶�ȡSIZE*SIZE�������Գ�ʼ����Ϸ  
// Ϊ����ÿ�����г���Ҫ�������֣��˴���ֱ�Ӹ�board���鸳��ֵ��2017-2-16  
int readBoard(int board[SIZE][SIZE]) {  
    /*
	printf("���� %d �����Գ�ʼ����Ϸ:\n", SIZE * SIZE);
	int i,j;  
    for(i=0;i<SIZE;i++)  
    {  
        for(j=0;j<SIZE;j++)  
            scanf("%d",&board[i][j]);  
    }  
    return i*j;  
	*/
	board[1][1]=2;
	board[2][2]=2;
	return SIZE*SIZE;
}  
  
//  
// add your functions here  
//  
  
//  
// You do not need to modify the code below here.  
//  
// If you wish to modify the code below, you have  
// misunderstood the assignment specification  
//  
  
void printHelp(void);  
void insertNewNumber(int board[SIZE][SIZE]);  
  
int main(int argc, char *argv[]) {  
    int board[SIZE][SIZE] = {{0}};  
    int c, score, moveScore, gameWon, numbersRead;  
    unsigned int seed;  
  
    // initialize random generator with command-line argument if provided  
    // or with current time  
    if (argc > 1){  
        seed = atoi(argv[1]);  
    } else {  
        seed = time(0);  
    }  
    srand(seed);  
	
    numbersRead = readBoard(board);  
    if (numbersRead != SIZE * SIZE) {  
        printf("���棺ֻ��ȡ�� %d ����\n", numbersRead);  
    }  
  
    //printf("Repeat game by running: %s %u\n", argv[0], seed);  
    printHelp();  
    score = 0;  
    gameWon = 0;  
    while (gameOver(board) == 0) {  
        printf("\n");  
        printBoard(board);  
        printf("��ķ����ǣ�%d.\n", score);  
        if (gameWon == 0 && boardContains2048(board)) {  
            gameWon = 1;  
            printf("ʤ���ˣ���ϲ��!��q���˳����������\n");  
        }  
        printf("> ");  
  
        c = getchar();  
        while (c != EOF && isspace(c)) {  
            c = getchar();  
        }  
  
        printf("\n");  
  
        if (c == EOF || c == 'q' || c == 'Q') {  
            printf("�����յķ����� %d.\n", score);  
            return 0;  
        }  
  
        c = tolower(c);  
        if (!strchr("aswd", c)) {  
            printHelp();  
        } else {  
            moveScore = 0;  
            if (c == 'A' || c == 'a') {  
                moveScore = moveLeft(board);  
            } else if (c == 'S' || c == 's') {  
                moveScore = moveDown(board);  
            } else if (c == 'W' || c == 'w') {  
                moveScore = moveUp(board);  
            } else if (c == 'D' || c == 'd') {  
                moveScore = moveRight(board);  
            }  
  
            if (moveScore == -1) {  
                printf("���棺��״̬�޷���"); 
					 switch(c){
					 	case 'a':
					 	case 'A': printf("���ƶ�.\n");break;
					 	case 's':
					 	case 'S': printf("���ƶ�.\n");break;
					 	case 'w':
					 	case 'W': printf("���ƶ�.\n");break;
						case 'd':
					 	case 'D': printf("���ƶ�.\n");break;		
					 } 
            } else {  
                insertNewNumber(board);  
                score = score + moveScore;  
            }  
        }  
    }  
    printBoard(board);  
    printf("��Ϸ��������ķ����ǣ� %d.\n", score);  
    return 0;  
}  
  
  
void  printHelp(void) { 
	printf("******************************************\n");
	printf("*          ��ӭ����2048��Ϸ���棡        *\n");
    printf("*    a/w/s/d�ֱ��ʾ����/��/��/���Ҷ�    *\n");
	printf("*              q ���˳�                  *\n"); 
	printf("******************************************\n");
}  
  
  
// add a new number to the board  
// it will either be a 2 (90% probability) or a 4 (10% probability)  
// do not change this function  
  
void insertNewNumber(int board[SIZE][SIZE]) {  
    int row, column;  
    int index, availableSquares = 0;  
  
    // count vacant squares  
    for (row = 0; row < SIZE; row = row + 1) {  
        for (column = 0; column < SIZE; column = column + 1) {  
            if (board[row][column] == 0) {  
                availableSquares = availableSquares + 1;  
            }  
        }  
    }  
  
    if (availableSquares == 0) {  
        printf("Internal error no available square\n");  
        exit(1);  
    }  
  
    // randomly pick a vacant square  
    index = rand() % availableSquares;  
    for (row = 0; row < SIZE; row = row + 1) {  
        for (column = 0; column < SIZE; column = column + 1) {  
            if (board[row][column] == 0) {  
                if (index == 0) {  
                    if (rand() % 10 == 0) {  
                        board[row][column] = 4;  
                    } else {  
                        board[row][column] = 2;  
                    }  
                    return;  
                }  
                index = index - 1;  
            }  
        }  
    }  
}  