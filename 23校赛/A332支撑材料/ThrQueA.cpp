#include <bits/stdc++.h>

using namespace std ;

#define PI 3.1415926
#define R 300.0
#define PointNum 301
#define InterYNum 300

long double pointLeft[PointNum][2] = {0.0};
long double midXLeft[PointNum] = {0.0};
long double midYLeft[PointNum] = {0.0};
long double interYLeft[InterYNum] = {0.0};
long double lenMapLeft[InterYNum] = {0.0};
long double sectionLeft[InterYNum][2] = {0.0};
long double lenInSectionLeft[InterYNum] = {0.0};
long double scaLenLeft[InterYNum] = {0.0};
long double scaSum = 0.0 ;
void getPointAndMidLeft();
void getInterYLeft();
void getLenLeft();
void getSection();
void getLenInSecLeft();
void getScaLenLeft();
int main()
{
    getPointAndMidLeft();
    getInterYLeft();
    getLenLeft();
    getSection();
    getLenInSecLeft();
    getScaLenLeft();
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
        //cout << '(' << pointLeft[i][0] <<','<< pointLeft[i][1] <<')' <<endl;
        //cout <<'('<<midXLeft[i-1]<<','<<midYLeft[i-1]<<')'<<endl;
    }
}

void getInterYLeft(){
    for(int i = 0 ; i < InterYNum ; i ++){
        interYLeft[i] = (R*R - 0.25 ) / (2.0) /(midYLeft[i]) ;
        //cout << interYLeft[i] <<endl;
    }
}

void getLenLeft(){

    for(int i = 0 ; i < InterYNum ; i ++){
        //cout << pointLeft[i+1][1] - pointLeft[i][1] << endl;
        lenMapLeft[i] = 0.5 / (pointLeft[i+1][1] - pointLeft[i][1] );
        //cout << lenMapLeft[i] << endl;
    }
}

void getSection(){
    for(int i = 0 ; i < InterYNum ; i ++){
        sectionLeft[i][0] = interYLeft[i] - lenMapLeft[i] / 2.0 ;
        sectionLeft[i][1] = interYLeft[i] + lenMapLeft[i] / 2.0 ;
        //cout << '[' <<sectionLeft[i][0] <<','<<sectionLeft[i][1]<<']' <<endl;
    }
}

void getLenInSecLeft(){
    for(int i = 0 ; i < InterYNum ; i ++){
        long double length = lenMapLeft[i] ;
        long double secSma = sectionLeft[i][0] ;
        long double secBig = sectionLeft[i][1] ;
            if(secSma + 150.0 >= 0 || secBig + 170.0 <= 0 ){
                lenInSectionLeft[i] = 0.0 ;
            }    
            else if(secSma + 170.0 >= 0 && secBig + 150.0 >= 0){
                lenInSectionLeft[i] = -150.0 - secSma ;
            }
            else if(secSma + 170.0 <= 0 && secBig + 150.0 <= 0){
                lenInSectionLeft[i] = secBig + 170.0 ; 
            }
            else if (secSma + 170.0 >= 0 && secBig + 150.0 <= 0){
                lenInSectionLeft[i] = length;
            }
            else {
                lenInSectionLeft[i] = 20.0 ;
            }          
    }
}

void getScaLenLeft(){
    for(int i = 0 ; i < InterYNum ; i ++){
        scaLenLeft[i] = lenInSectionLeft[i] / lenMapLeft[i] ;
        scaSum += scaLenLeft[i] ;
        //cout << lenInSectionLeft[i]<<endl;
        //cout << scaLenLeft[i] << endl;
        //cout << i <<"  ----  " << lenInSectionLeft[i] << "  ++++  " << lenMapLeft[i] << "   ****  "  << scaLenLeft[i] << endl; ;
    }
    //cout << scaSum;
}

