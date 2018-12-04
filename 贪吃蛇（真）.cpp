#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

#define SNAKE_MAX_LENGTH 100
#define SNAKE_HEAD 'H'      // H代表蛇的头部 
#define SNAKE_BODY 'X'      //X是蛇的身体 
#define BLANK_CELL ' '		
#define SNAKE_FOOD '$'		//$是食物，蛇吃了会边长 
#define WALL_CELL '*'		//*是障碍物，蛇撞上了会死亡 

char map[12][13]={ //先建立一个12X12的地图 
	"************",//可以在地图中增加一些障碍物（包括但不限于边框） 
	"*H         *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"************"};

int snakeHeadX = 1, snakeHeadY = 1; //初始化蛇头的坐标 
int snakeX[SNAKE_MAX_LENGTH] = {1};
int snakeY[SNAKE_MAX_LENGTH] = {1}; 
int snakeLen = 1;					//初始化蛇的长度为1 
int FoodX = 0, FoodY = 0;			//初始化食物的位置 
int gameRunning = 1;

void snakeMove(void);		//控制蛇的移动 
void put_money(void);		//控制食物的位置 
void output(void);			//输出游戏界面 
void gameover(void);		//结束游戏 

int main(){
	put_money();			//生成首个食物 
	output();				//先产生第一个游戏界面 
	while(gameRunning){		
		snakeMove();
		output(); 
	}
	return 0;
}

void gameover(void){
	gameRunning = 0;
	printf("Game Over!");
}

void put_money(void){
	srand(time(NULL));			//以现在的系统时间作为随机数的种子来产生随机数 
	
	//随机产生食物的坐标 
	FoodX = rand() % 10 + 1;
	FoodY = rand() % 10 + 1;	
	while(map[FoodX][FoodY]!=BLANK_CELL){
		FoodX = rand() % 10 + 1;
		FoodY = rand() % 10 + 1;
	}
	map[FoodX][FoodY] = SNAKE_FOOD;
}

void snakeMove(void){
	char control = getch();		//无回显地取出一个字符
	
	//预置蛇头位置 
	int preSnakeHeadX = snakeHeadX;	
    int preSnakeHeadY = snakeHeadY; 
    
    //用w,s,a,d控制蛇头坐标 
    switch(control){
    	case 'w' : snakeHeadX--; break;
    	case 's' : snakeHeadX++; break;
    	case 'a' : snakeHeadY--; break;
    	case 'd' : snakeHeadY++; break;
	}
	
	//设置蛇死亡的条件（撞墙或者撞到自己身体） 
	if (map[snakeHeadX][snakeHeadY] == WALL_CELL||map[snakeHeadX][snakeHeadY]==SNAKE_BODY)
        gameover();
    
	//将蛇头按条件移至下一个坐标，并将原来位置暂时设置为空白    
    map[snakeHeadX][snakeHeadY] = SNAKE_HEAD;
    map[preSnakeHeadX][preSnakeHeadY] = BLANK_CELL;
    
    //设置蛇吃到食物后的变化 
    if (snakeHeadX==FoodX&&snakeHeadY==FoodY){
        //蛇身的新坐标 
		snakeX[snakeLen] = preSnakeHeadX;
        snakeY[snakeLen] = preSnakeHeadY;
        snakeLen++;			//蛇长+1 
        map[preSnakeHeadX][preSnakeHeadY] =SNAKE_BODY;//将此新坐标表现为X 
        put_money();		//再次生成食物 
        return;
    }
    
    //控制蛇身随着蛇头移动 
	for(int i=0 ; i<snakeLen-1 ; i++){
		snakeX[i] = snakeX[i+1];
		snakeY[i] = snakeY[i+1];
	}
	snakeX[snakeLen - 1] = preSnakeHeadX;
	snakeY[snakeLen - 1] = preSnakeHeadY;
	
	for(int j=0 ; j<snakeLen ; j++){
		map[snakeX[j]][snakeY[j]] = SNAKE_BODY;
	}
	map[snakeX[0]][snakeY[0]] = BLANK_CELL;
}

void output(void){
	system("cls");		//使游戏界面保持为一个，提高游戏体验 
	for(int i=0 ; i<12 ; i++)
		printf("%s\n", map[i]);
}
