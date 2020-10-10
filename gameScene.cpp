/*
 * gameScene.cpp
 *
 *  Created on: May 22, 2020
 *      Author: rizwan
 */

#include "gameScene.h"

gameScene::gameScene():MainMenu() {
	// TODO Auto-generated constructor stub
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			arr[i][j]=0;
		}
	}
}
gameScene::gameScene(int m,int t,int o,int x):MainMenu(m/*,t,o,x*/){

}
void gameScene::setLevel(int l){
	p.setLevel(l);
}
void gameScene::CandiesGenerator(){
	if(l.getTime()>0&&getmoves()>0){
		int size=60, sx=140,sy=140;
		if(p.getF()==0){
			for (int i = 2; i < 10; ++i) {
				sx=140;
				for (int j = 2; j < 10; ++j) {
					int x=rand()%6+1;

					if(x==1){
						DrawCircle(sx+size/2,sy+size/2,size/2,colors[GREEN]);
						arr[i][j]=1;
					}
					else if(x==2){
						DrawSquare( sx , sy ,size,colors[RED]);
						arr[i][j]=2;
					}
					else if(x==3){
						DrawTriangle( sx, sy , sx+(size/2), sy+size , sx+size , sy, colors[MISTY_ROSE] );
						arr[i][j]=3;
					}
					else if(x==4){
						DrawRectangle(sx+20,  sy, size/3, size, colors[ORANGE]);
						arr[i][j]=4;
					}
					else if(x==5){
						DrawRoundRect(sx,sy+15,size,size/1.5,colors[YELLOW]);
						arr[i][j]=5;
					}
					else if(x==6){
						DrawTriangle( sx+(size/2), sy , sx, sy+size , sx+size , sy+size, colors[BLUE_VIOLET] );
						DrawTriangle( sx, sy , sx+size, sy , sx+size/2 , sy+size, colors[BLUE_VIOLET] );
						arr[i][j]=6;
					}
					sx+=size+10;
				}
				sy+=size+10;
			}
		}
		p.setF(1);
		sx=140,sy=140;
		for (int i = 2; i < 10; ++i) {
			sx=140;
			for (int j = 2; j < 10; ++j) {
				if(arr[i][j]==1){
					DrawCircle(sx+(size/2),sy+size/2,size/2,colors[GREEN]);
					arr[i][j]=1;
				}
				else if(arr[i][j]==2){
					DrawSquare( sx , sy ,size,colors[RED]);
					arr[i][j]=2;
				}
				else if(arr[i][j]==3){
					DrawTriangle( sx, sy , sx+(size/2), sy+size , sx+size , sy, colors[MISTY_ROSE] );
					arr[i][j]=3;
				}
				else if(arr[i][j]==4){
					DrawRectangle(sx+size/3,  sy, size/3, size, colors[ORANGE]);
					arr[i][j]=4;
				}
				else if(arr[i][j]==5){
					DrawRoundRect(sx,sy+15,size,size/1.5,colors[YELLOW]);
					arr[i][j]=5;
				}
				else if(arr[i][j]==6){

					// DrawRoundRect(i,j+15,size,size/1.5,colors[YELLOW]);
					DrawTriangle( sx+(size/2), sy , sx, sy+size , sx+size , sy+size, colors[BLUE_VIOLET] );
					DrawTriangle( sx, sy , sx+size, sy , sx+size/2 , sy+size, colors[BLUE_VIOLET] );
					arr[i][j]=6;
				}
				sx+=size+10;
			}
			sy+=size+10;

		}
		int m=140,n=100;
		DrawRectangle(135,95,570,30,colors[LIGHT_CYAN]);
		for (int i = 0; i < p.getProgress(); ++i) {
			DrawSquare(m,n,20,colors[GREEN]);
			m+=18;
		}
		DrawString(140,720,"Score "+Num2Str(p.getScore()),colors[GREEN]);
		DrawString(620,720,"Level "+Num2Str(p.getLevel()),colors[GREEN]);
		DrawString(350,50,"Lives : "+ Num2Str(p.getLives()) , colors[RED]);

		if(l.getOption()==1){
			DrawString(350,720,"Timer : "+ Num2Str(l.getTime()) , colors[LIGHT_CYAN]);
		}
		else{
			DrawString(350,720,"Moves : "+ Num2Str(l.getMoves()) , colors[LIGHT_CYAN]);
		}
	}
	else{
		p.setLives(p.getLives()-1);
		if(p.getLives()>0){
			l.setTime(100);
			l.setMoves(30);
			p.setF(0);
			p.setProgress(0);
			if(p.getLevel()==1){
				l.setTime(100);
				l.setMoves(30);
			}
			else if(p.getLevel()==2){
				l.setTime(80);
				l.setMoves(25);
			}
			else if(p.getLevel()==3){
				l.setTime(70);
				l.setMoves(22);
			}
			else if(p.getLevel()==4){
				l.setTime(65);
				l.setMoves(20);
			}
			else if(p.getLevel()==5){
				l.setTime(60);
				l.setMoves(18);
			}
			else if(p.getLevel()==6){
				l.setTime(55);
				l.setMoves(15);
			}
			else if(p.getLevel()==7){
				l.setTime(50);
				l.setMoves(14);
			}
			else if(p.getLevel()==8){
				l.setTime(45);
				l.setMoves(12);
			}
			else if(p.getLevel()==9){
				l.setTime(40);
				l.setMoves(10);
			}
			else if(p.getLevel()>=10){
				l.setTime(30);
				l.setMoves(8);
			}
		}
		else
			setMenuOption(6);
	}
}
//void gameScene::Hint(){
////	static int t=0;
//	for (int i = 2; i < 8; ++i) {//1
//		for (int j = 2; j < 9; ++j) {
//			if( (arr[i][j]==arr[i+1][j]&&arr[i][j]==arr[i+2][j+1]) ){
//
//			}
//		}
//	}
//	for (int i = 2; i < 7; ++i) {//2
//		for (int j = 2; j < 10; ++j) {
//			if( (arr[i][j]==arr[i+1][j]&&arr[i][j]==arr[i+3][j]) ){
////				DrawSquare(400,400,100,colors[WHITE]);
//				DrawLine( ( (i+3) * 70 ),((j)*70),/*((i+2)*70)-35,((j)*70)-35*/0,0,50,colors[WHITE]);
//			cout<<arr[i+1][j]<<"  "<<arr[i+3][j]<<"  "<<arr[i][j]<<endl;
//
//			}
//		}
//	}
//	for (int i = 2; i < 7; ++i) {//3
//		for (int j = 2; j < 10; ++j) {
//			if( (arr[i][j]==arr[i+2][j]&&arr[i][j]==arr[i+3][j]) ){
////				DrawSquare(400,400,100,colors[WHITE]);
//
//			}
//		}
//	}
//	for (int i = 2; i < 8; ++i) {//4
//		for (int j = 2; j < 9; ++j) {
//			if( (arr[i][j]==arr[i+1][j+1]&&arr[i][j]==arr[i+2][j]) ){
////				DrawSquare(400,400,100,colors[WHITE]);
//
//			}
//		}
//	}
//	for (int i = 2; i < 8; ++i) {//5
//		for (int j = 3; j < 10; ++j) {
//			if( (arr[i][j]==arr[i+1][j-1]&&arr[i][j]==arr[i+2][j]) ){
////				DrawSquare(400,400,100,colors[WHITE]);
//
//			}
//		}
//	}
//	for (int i = 2; i < 8; ++i) {//6
//		for (int j = 3; j < 10; ++j) {
//			if( (arr[i][j]==arr[i+1][j]&&arr[i][j]==arr[i+2][j-1]) ){
////				DrawSquare(400,400,100,colors[WHITE]);
//
//			}
//		}
//	}
//	for (int i = 2; i < 8; ++i) {//7
//		for (int j = 2; j < 9; ++j) {
//			if( (arr[i][j+1]==arr[i+1][j]&&arr[i][j]==arr[i+2][j]) ){
////				DrawSquare(400,400,100,colors[WHITE]);
//
//			}
//		}
//	}
//	for (int i = 2; i < 8; ++i) {//8
//		for (int j = 3; j < 10; ++j) {
//			if( (arr[i-1][j-1]==arr[i][j]&&arr[i][j]==arr[i+1][j]) ){
////				DrawSquare(400,400,100,colors[WHITE]);
//
//			}
//		}
//	}
//	//#######################################################################################
//	for (int i = 3; i < 10; ++i) {//9
//		for (int j = 2; j < 9; ++j) {
//			if( (arr[i-1][j-1]==arr[i][j]&&arr[i][j]==arr[i][j+1]) ){
////				DrawSquare(400,400,100,colors[WHITE]);
//
//			}
//		}
//	}
//	for (int i = 2; i < 9; ++i) {//10
//		for (int j = 2; j < 9; ++j) {
//			if( (arr[i+1][j-1]==arr[i][j]&&arr[i][j]==arr[i][j+1]) ){
////				DrawSquare(400,400,100,colors[WHITE]);
//
//			}
//		}
//	}
//	for (int i = 3; i < 10; ++i) {//11
//		for (int j = 2; j < 8; ++j) {
//			if( (arr[i-1][j+1]==arr[i][j]&&arr[i][j]==arr[i][j+2]) ){
////				DrawSquare(400,400,100,colors[WHITE]);
//
//			}
//		}
//	}
//	for (int i = 2; i < 9; ++i) {//12
//		for (int j = 2; j < 8; ++j) {
//			if( (arr[i+1][j+1]==arr[i][j]&&arr[i][j]==arr[i][j+2]) ){
////				DrawSquare(400,400,100,colors[WHITE]);
//
//			}
//		}
//	}
//	for (int i = 2; i < 10; ++i) {//13
//		for (int j = 2; j < 7; ++j) {
//			if( (arr[i][j]==arr[i][j+1]&&arr[i][j]==arr[i][j+3]) ){
////				DrawSquare(400,400,100,colors[WHITE]);
//
//			}
//		}
//	}
//	for (int i = 2; i < 10; ++i) {//14
//		for (int j = 2; j < 7; ++j) {
//			if( (arr[i][j]==arr[i][j+2]&&arr[i][j]==arr[i][j+3]) ){
////				DrawSquare(400,400,100,colors[WHITE]);
//
//			}
//		}
//	}
//	for (int i = 3; i < 9; ++i) {//15
//		for (int j = 2; j < 8; ++j) {
//			if( (arr[i][j]==arr[i][j+1]&&arr[i][j]==arr[i+1][j+2]) ){
////				DrawSquare(400,400,100,colors[WHITE]);
//			}
//		}
//	}
//	for (int i = 3; i < 10; ++i) {//16
//		for (int j = 2; j < 8; ++j) {
//			if( (arr[i][j]==arr[i][j+1]&&arr[i][j]==arr[i-1][j+2]) ){
////				DrawSquare(400,400,100,colors[WHITE]);
//			}
//		}
//	}
//}
void gameScene::Swap(int sx_1,int sy_1,int sx_2,int sy_2){
			if(sx_1>1 &&sx_1<10 &&sy_1>1 &&sy_1<10 &&sx_2>1 &&sx_2<10 &&sy_2>1 &&sy_2<10){
				if ((sx_1-sx_2==1 || sx_1-sx_2==-1 ) && (sy_1-sy_2==0)){
					int temp=getArr(sy_1,sx_1);
					setArr(sy_1,sx_1,getArr(sy_2,sx_2));
					setArr(sy_2,sx_2,temp);

					if (isMatching()==0) {
						temp=getArr(sy_1,sx_1);
						setArr(sy_1,sx_1,getArr(sy_2,sx_2));
						setArr(sy_2,sx_2,temp);
					}
					if(l.getOption()==0){
						l.decMoves();
					}

				}
				if ((sy_1-sy_2==1 || sy_1-sy_2==-1 ) && (sx_1-sx_2==0)){
					int temp=getArr(sy_1,sx_1);
					setArr(sy_1,sx_1,getArr(sy_2,sx_2));
					setArr(sy_2,sx_2,temp);
					if (isMatching()==0) {
						temp=getArr(sy_1,sx_1);
						setArr(sy_1,sx_1,getArr(sy_2,sx_2));
						setArr(sy_2,sx_2,temp);
					}
					if(l.getOption()==0){
						l.decMoves();
					}


				}

			}
}
bool gameScene::isMatching(){
	bool flag=0;
	for(int i=2;i<10;i++)
		{
		for (int j=2;j<8;j++)
			{
				 if (arr[i][j]==arr[i][j+1] && arr[i][j]==arr[i][j+2] && arr[i][j]==arr[i][j+3] && arr[i][j]==arr[i][j+4] && j<6)
				 {
					 for (int k=2;k<8;k++)
					 {
							for (int l=2;l<10;l++)
							{
								if (arr[k][l]==arr[k+1][l] && arr[k][l]==arr[k+2][l] && arr[k][l]==arr[k+3][l] && arr[k][l]==arr[k+4][l] && k<6)
								{
									for (int m = 0; m < 5; ++m) {
										arr[k+m][l]=9;
										flag=1;
									}
								}
								else if (arr[k][l]==arr[k+1][l] && arr[k][l]==arr[k+2][l] && arr[k][l]==arr[k+3][l] && k<7)
								{
									for (int m = 0; m < 4; ++m) {
										arr[k+m][l]=9;
										flag=1;
									}
								}
								else if (arr[k][l]==arr[k+1][l] && arr[k][l]==arr[k+2][l])
								{
									for (int m = 0; m < 3; ++m) {
										arr[k+m][l]=9;
										flag=1;
									}
								}
							}
						}
					 	 for (int m = 0; m < 5; ++m) {
					 		 arr[i][j+m]=9;
					 		 flag=1;
					 	 }
					}
				 	else if (arr[i][j]==arr[i][j+1] && arr[i][j]==arr[i][j+2] && arr[i][j]==arr[i][j+3] && j<7)
				 	{
						for (int k=2;k<8;k++)
						{
							for (int l=2;l<10;l++)
							{
								 if (arr[k][l]==arr[k+1][l] && arr[k][l]==arr[k+2][l] && arr[k][l]==arr[k+3][l] && arr[k][l]==arr[k+4][l] && k<6)
								 {
									 for (int m = 0; m < 5; ++m) {
										arr[k+m][l]=9;
										flag=1;
									}
								 }
								 else if (arr[k][l]==arr[k+1][l] && arr[k][l]==arr[k+2][l] && arr[k][l]==arr[k+3][l] && k<7 )
								{
									 for (int m = 0; m < 4; ++m) {
										arr[k+m][l]=9;
										flag=1;
									}
								 }
   								else if (arr[k][l]==arr[k+1][l] && arr[k][l]==arr[k+2][l] )
								{
   									for (int m = 0; m < 3; ++m) {
										arr[k+m][l]=9;
										flag=1;
									}
								}
							}
						}
						for (int m = 0; m < 4; ++m) {
							arr[i][j+m]=9;
							flag=1;
						}
				 	}
				 	else	if (arr[i][j]==arr[i][j+1] && arr[i][j]==arr[i][j+2] )
					{
						for (int k=2;k<8;k++)
						{
							for (int l=2;l<10;l++)
							{
								if (arr[k][l]==arr[k+1][l] && arr[k][l]==arr[k+2][l] && arr[k][l]==arr[k+3][l] && arr[k][l]==arr[k+4][l] && k<6)
								{
									for (int m = 0; m < 5; ++m) {
										arr[k+m][l]=9;
										flag=1;
									}								}
								else if (arr[k][l]==arr[k+1][l] && arr[k][l]==arr[k+2][l] && arr[k][l]==arr[k+3][l] && k<7 )
								{
									for (int m = 0; m < 4; ++m) {
										arr[k+m][l]=9;
										flag=1;
									}
								}
								else if (arr[k][l]==arr[k+1][l] && arr[k][l]==arr[k+2][l] )
								{
									for (int m = 0; m < 3; ++m) {
										arr[k+m][l]=9;
										flag=1;
									}
								}
							}
						}
						for (int m = 0; m < 3; ++m) {
							arr[i][j+m]=9;
							flag=1;
						}
					}
			}
	}

	for (int k=2;k<8;k++)
	{
		for (int l=2;l<10;l++)
		{
			if (arr[k][l]==arr[k+1][l] && arr[k][l]==arr[k+2][l] && arr[k][l]==arr[k+3][l] && arr[k][l]==arr[k+4][l] && k<6)
			{
				for(int i=2;i<10;i++)
				{
					for (int j=2;j<8;j++)
					{
						if (arr[i][j]==arr[i][j+1] && arr[i][j]==arr[i][j+2] )
						{
							for (int m = 0; m < 3; ++m) {
								arr[i][j+m]=9;
								flag=1;
							}
						}
						else if (arr[i][j]==arr[i][j+1] && arr[i][j]==arr[i][j+2] && arr[i][j]==arr[i][j+3] && j<7)
						{
							for (int m = 0; m < 4; ++m) {
								arr[i][j+m]=9;
								flag=1;
							}
						}
						else if (arr[i][j]==arr[i][j+1] && arr[i][j]==arr[i][j+2] && arr[i][j]==arr[i][j+3] && arr[i][j]==arr[i][j+4]&&j<6)
						{
							for (int m = 0; m < 5; ++m) {
								arr[i][j+m]=9;
								flag=1;
							}
						}
					 }
				}
				for (int m = 0; m < 5; ++m) {
					arr[k+m][l]=9;
					flag=1;
				}

			}
			else if (arr[k][l]==arr[k+1][l] && arr[k][l]==arr[k+2][l] && arr[k][l]==arr[k+3][l] && k<7 )
				{
				for(int i=2;i<10;i++)
				{
					for (int j=0;j<8;j++)
					{
						if (arr[i][j]==arr[i][j+1] && arr[i][j]==arr[i][j+2] )
						{
							for (int m = 0; m < 3; ++m) {
								arr[i][j+m]=9;
								flag=1;
							}
						}

						else if (arr[i][j]==arr[i][j+1] && arr[i][j]==arr[i][j+2] && arr[i][j]==arr[i][j+3]&&j<7)
						{
							for (int m = 0; m < 4; ++m) {
								flag=1;
								arr[i][j+m]=9;
							}
						}
						else if (arr[i][j]==arr[i][j+1] && arr[i][j]==arr[i][j+2] && arr[i][j]==arr[i][j+3] && arr[i][j]==arr[i][j+4]&&j<6)
						{
							for (int m = 0; m < 5; ++m) {
								arr[i][j+m]=9;
								flag=1;
							}
						}
					}
				}
				for (int m = 0; m < 4; ++m) {
					arr[k+m][l]=9;
					flag=1;
				}
			}

			else if (arr[k][l]==arr[k+1][l] && arr[k][l]==arr[k+2][l] )
			{
				for(int i=2;i<10;i++)
				{
					for (int j=2;j<8;j++)
				{
						if (arr[i][j]==arr[i][j+1] && arr[i][j]==arr[i][j+2] )
						{
							for (int m = 0; m < 3; ++m) {
								flag=1;
								arr[i][j+m]=9;
							}
						}
						else if (arr[i][j]==arr[i][j+1] && arr[i][j]==arr[i][j+2] && arr[i][j]==arr[i][j+3]&&j<7)
						{
							for (int m = 0; m < 4; ++m) {
								flag=1;
								arr[i][j+m]=9;
							}
						}
						else if (arr[i][j]==arr[i][j+1] && arr[i][j]==arr[i][j+2] && arr[i][j]==arr[i][j+3] && arr[i][j]==arr[i][j+4]&&j<6)
						{
							for (int m = 0; m < 5; ++m) {
								arr[i][j+m]=9;
								flag=1;
							}
						}
					}
				}
				for (int m = 0; m < 3; ++m) {
					arr[k+m][l]=9;
					flag=1;
				}
			}
		}
	}
	glutPostRedisplay();
return flag;
}
void gameScene::newCandiesGenerator(){
	int flag=0;
	for(int i=0;i<10;i++)
	{
		for (int j=0;j<10;j++)
			{
				if (arr[i][j]==9)
				{
					for(int k=i;k<9;k++)//k<9 because at position 10 new candy will formed
					{
						int temp=getArr(k,j);
						setArr(k,j,getArr(k+1,j));
						setArr(k+1,j,temp);
					}
				}
			}
	}
	for(int j=0;j<10;j++)
	{
		for (int i=0;i<10;i++)
		{
			if (arr[i][j]==9)
			{
				for(int k=i;k<9;k++)
				{
					int temp=getArr(k,j);
					setArr(k,j,getArr(k+1,j));
					setArr(k+1,j,temp);
				}
			}
		}
	}

	for (int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
				if (arr[i][j]==9)
				{
					flag=1;
					p.incScore();
					if(p.incLevel()==1){
						if(p.getLevel()==1){
							l.setTime(100);
							l.setMoves(30);
						}
						else if(p.getLevel()==2){
							l.setTime(80);
							l.setMoves(25);
						}
						else if(p.getLevel()==3){
							l.setTime(70);
							l.setMoves(22);
						}
						else if(p.getLevel()==4){
							l.setTime(65);
							l.setMoves(20);
						}
						else if(p.getLevel()==5){
							l.setTime(60);
							l.setMoves(18);
						}
						else if(p.getLevel()==6){
							l.setTime(55);
							l.setMoves(15);
						}
						else if(p.getLevel()==7){
							l.setTime(50);
							l.setMoves(14);
						}
						else if(p.getLevel()==8){
							l.setTime(45);
							l.setMoves(12);
						}
						else if(p.getLevel()==9){
							l.setTime(40);
							l.setMoves(10);
						}
						else if(p.getLevel()>=10){
							l.setTime(30);
							l.setMoves(8);
						}
					}
					arr[i][j]=rand()%6+1;
				}
		}
	}
	if (flag==1) {
		p.incProgress();
	}
}
void gameScene::setArr(int x1,int y1,int a){
	arr[x1][y1]=a;
}
int gameScene::getArr(int x1,int y1){
	return arr[x1][y1];
}
gameScene::~gameScene() {
	// TODO Auto-generated destructor stub
}

