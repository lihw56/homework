#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

#define SNAKE_MAX_LENGTH 100
#define SNAKE_HEAD 'H'      // H�����ߵ�ͷ�� 
#define SNAKE_BODY 'X'      //X���ߵ����� 
#define BLANK_CELL ' '		
#define SNAKE_FOOD '$'		//$��ʳ��߳��˻�߳� 
#define WALL_CELL '*'		//*���ϰ����ײ���˻����� 

char map[12][13]={ //�Ƚ���һ��12X12�ĵ�ͼ 
	"************",//�����ڵ�ͼ������һЩ�ϰ�������������ڱ߿� 
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

int snakeHeadX = 1, snakeHeadY = 1; //��ʼ����ͷ������ 
int snakeX[SNAKE_MAX_LENGTH] = {1};
int snakeY[SNAKE_MAX_LENGTH] = {1}; 
int snakeLen = 1;					//��ʼ���ߵĳ���Ϊ1 
int FoodX = 0, FoodY = 0;			//��ʼ��ʳ���λ�� 
int gameRunning = 1;

void snakeMove(void);		//�����ߵ��ƶ� 
void put_money(void);		//����ʳ���λ�� 
void output(void);			//�����Ϸ���� 
void gameover(void);		//������Ϸ 

int main(){
	put_money();			//�����׸�ʳ�� 
	output();				//�Ȳ�����һ����Ϸ���� 
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
	srand(time(NULL));			//�����ڵ�ϵͳʱ����Ϊ���������������������� 
	
	//�������ʳ������� 
	FoodX = rand() % 10 + 1;
	FoodY = rand() % 10 + 1;	
	while(map[FoodX][FoodY]!=BLANK_CELL){
		FoodX = rand() % 10 + 1;
		FoodY = rand() % 10 + 1;
	}
	map[FoodX][FoodY] = SNAKE_FOOD;
}

void snakeMove(void){
	char control = getch();		//�޻��Ե�ȡ��һ���ַ�
	
	//Ԥ����ͷλ�� 
	int preSnakeHeadX = snakeHeadX;	
    int preSnakeHeadY = snakeHeadY; 
    
    //��w,s,a,d������ͷ���� 
    switch(control){
    	case 'w' : snakeHeadX--; break;
    	case 's' : snakeHeadX++; break;
    	case 'a' : snakeHeadY--; break;
    	case 'd' : snakeHeadY++; break;
	}
	
	//������������������ײǽ����ײ���Լ����壩 
	if (map[snakeHeadX][snakeHeadY] == WALL_CELL||map[snakeHeadX][snakeHeadY]==SNAKE_BODY)
        gameover();
    
	//����ͷ������������һ�����꣬����ԭ��λ����ʱ����Ϊ�հ�    
    map[snakeHeadX][snakeHeadY] = SNAKE_HEAD;
    map[preSnakeHeadX][preSnakeHeadY] = BLANK_CELL;
    
    //�����߳Ե�ʳ���ı仯 
    if (snakeHeadX==FoodX&&snakeHeadY==FoodY){
        //����������� 
		snakeX[snakeLen] = preSnakeHeadX;
        snakeY[snakeLen] = preSnakeHeadY;
        snakeLen++;			//�߳�+1 
        map[preSnakeHeadX][preSnakeHeadY] =SNAKE_BODY;//�������������ΪX 
        put_money();		//�ٴ�����ʳ�� 
        return;
    }
    
    //��������������ͷ�ƶ� 
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
	system("cls");		//ʹ��Ϸ���汣��Ϊһ���������Ϸ���� 
	for(int i=0 ; i<12 ; i++)
		printf("%s\n", map[i]);
}
