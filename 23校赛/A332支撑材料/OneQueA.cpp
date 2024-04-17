#include <bits/stdc++.h>

using namespace std ;

#define PI 3.1415926
#define R 300.0
#define PointNum 301
#define InterYNum 300
#define secProOneNum 581

long double pointLeft[PointNum][2] = {0.0};
long double midXLeft[PointNum] = {0.0};
long double midYLeft[PointNum] = {0.0};
long double interYLeft[InterYNum] = {0.0};
int countDesSecIntYNum = 0 ;
int countSecProOne[secProOneNum] = {0} ;
int countSecProTwo[secProOneNum] = {0} ;

void getPointAndMidRight();
void getInterYLeft();
void getDesIntYNum();
void getNumSecProOne();
void getNumSecProTwo();

int main()
{
    getPointAndMidLeft();
    getInterYLeft();
    getDesIntYNum();
    getNumSecProOne();
    getNumSecProTwo();

    return 0 ;
}

void getPointAndMidLeft(){
    
    pointLeft[0][0] = 0 ;
	pointLeft[0][1] = -300.0;
	int i = 0 ;
	while(i <= 300){
		long double x = pointLeft[i][0] - 0.01;
		while(true){

			long double y =(-1) *sqrt(300*300 - x * x);
			long double tempX = (x - pointLeft[i][0] ) * (x - pointLeft[i][0]);
			long double tempY = (y - pointLeft[i][1]) * (y - pointLeft[i][1]) ;
			long double temp_pointLeft = tempX + tempY - 1.0;
			if(abs(temp_pointLeft) - 0.05 <= 0 ){
				pointLeft[i+1][0] = x ;
				pointLeft[i+1][1] = y ;
				break;
			}
			x -= 0.01 ;
		}
	++ i ;
	}
    i = 0 ;
    while(i < 300 ){
        midXLeft[i] = (pointLeft[i][0] + pointLeft[i+1][0]) / 2.0 ;
        midYLeft[i] = (pointLeft[i][1] + pointLeft[i+1][1]) / 2.0 ;
        i ++;
    }
}

void getInterYLeft(){
    for(int i = 0 ; i < InterYNum ; i ++){
        interYLeft[i] = (R*R - 0.25) / 2.0 / midYLeft[i] ;
    }
}

void getDesIntYNum(){
    long double section = -200.0 ;
    for(int i = 0 ; i < InterYNum ; i ++){
        if(interYLeft[i] + 200.0 >= 0 && interYLeft[i] + 180.0 <= 0){
            countDesSecIntYNum ++ ;
        }
    }
}

void getNumSecProOne(){
    for(int section = -300 , count = 0 ; section <= 280 ; section ++ , count ++){
        for(int i = 0 ; i < 300 ; i ++){
            if(interYLeft[i] - section >= 0 && interYLeft[i] - (section + 20.0) <= 0){
                countSecProOne[count]++ ;
            }
        }
    }
}

void getNumSecProTwo(){
    for(int i = 0 ; i < InterYNum ; i ++){
        long double section = interYLeft[i] ;
        for(int j = 0 ; j < InterYNum ; j ++){
            if(interYLeft[j] - section >= 0 && interYLeft[j] - (section + 20.0) <= 0 ){
                countSecProTwo[i] ++ ;
            }
        }
    }
}

