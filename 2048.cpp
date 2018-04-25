#include <stdio.h>  
#include <stdlib.h>  
#include <ctype.h>  
#include <string.h>  
#include <time.h>  
// put any extra includes here, but don't delete the ones above  
  
#define SIZE    4  
  
/* 
    题目的意思是这样的，需要‘严格’判断能否移动，我用flag标示移动的时候在第二个判断的时候出错了！ 
 
    拿下移为例，if(cell==0)的时候直接判断可以移动是错误的，当下移的时候，如果只有 
 
    上面第一行的某一个元素为0，下面所有行不出现合并的情况下是不能下移的。 
 
        所以在上下左右移动的过程中，当if(cell==0)即当前元素为0时要使得能够移动，就必须限制这个为0的 
 
    元素不是上面第一行（下移时）、左侧第一列（右移）、右侧第一列（左移）、下面第一行（上移）、 
 
        所以修改每个move函数中判断if(cell==0)代码的i或者j的循环条件，以避开判断时0所在的特殊行位置 
 
        具体修改看下面部分注释（修改的只有每个move函数中第二个for循环中的i或者j的循环条件） 
 
*/  
  
int moveLeft(int board[SIZE][SIZE]) {  
    int i,j,score=0,flag=-1;  
    for(i=0;i<SIZE;i++)  
    {  
        for(j=0;j<SIZE;j++)  
        {  
            int cell=board[i][j];//cell单词用的不太恰当，表示当前元素，你可以采用更有意义的命名  
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
                            flag=0;//相邻两个元素相同，就说明能移动，所以改变flag的值  
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
  
    //修改部分：for循环中的i或者j的循环条件  
  
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
  
     //修改部分：for循环中的i或者j的循环条件  
  
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
                        flag=0;//当前元素为0，说明能移动，改变flag的值  
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
  
     //修改部分：for循环中的i或者j的循环条件  
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
  
     //修改部分：for循环中的i或者j的循环条件  
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
    /*为了避免直接把board[][]传进move函数判断的时候改变board，所以把board复制给 
    另一个数组,然后判断，这样就不会改变board数组了 
 
    */  
    for(i=0;i<SIZE;i++)  
    {  
        for(j=0;j<SIZE;j++)  
        {  
            copy_board[i][j]=board[i][j];  
        }  
    }  
    if(moveDown(copy_board)==-1&&moveUp(copy_board)==-1&&moveLeft(copy_board)==-1&&moveRight(copy_board)==-1)//如果四个移动函数都返回-1即不能移动GameOver  
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
  
  
// readBoard()函数用来从键盘读取SIZE*SIZE个整数以初始化游戏  
// 为避免每次运行程序都要输入数字，此处把直接给board数组赋初值。2017-2-16  
int readBoard(int board[SIZE][SIZE]) {  
    /*
	printf("输入 %d 数字以初始化游戏:\n", SIZE * SIZE);
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
        printf("警告：只读取了 %d 数字\n", numbersRead);  
    }  
  
    //printf("Repeat game by running: %s %u\n", argv[0], seed);  
    printHelp();  
    score = 0;  
    gameWon = 0;  
    while (gameOver(board) == 0) {  
        printf("\n");  
        printBoard(board);  
        printf("你的分数是：%d.\n", score);  
        if (gameWon == 0 && boardContains2048(board)) {  
            gameWon = 1;  
            printf("胜利了，恭喜你!按q键退出或继续运行\n");  
        }  
        printf("> ");  
  
        c = getchar();  
        while (c != EOF && isspace(c)) {  
            c = getchar();  
        }  
  
        printf("\n");  
  
        if (c == EOF || c == 'q' || c == 'Q') {  
            printf("你最终的分数是 %d.\n", score);  
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
                printf("警告：此状态无法向"); 
					 switch(c){
					 	case 'a':
					 	case 'A': printf("左移动.\n");break;
					 	case 's':
					 	case 'S': printf("下移动.\n");break;
					 	case 'w':
					 	case 'W': printf("上移动.\n");break;
						case 'd':
					 	case 'D': printf("右移动.\n");break;		
					 } 
            } else {  
                insertNewNumber(board);  
                score = score + moveScore;  
            }  
        }  
    }  
    printBoard(board);  
    printf("游戏结束，你的分数是： %d.\n", score);  
    return 0;  
}  
  
  
void  printHelp(void) { 
	printf("******************************************\n");
	printf("*          欢迎进入2048游戏界面！        *\n");
    printf("*    a/w/s/d分别表示向左/上/下/移右动    *\n");
	printf("*              q 键退出                  *\n"); 
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
