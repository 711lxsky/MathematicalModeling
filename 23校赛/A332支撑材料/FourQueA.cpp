#include <bits/stdc++.h>

using namespace std ;

#define PI 3.1415926
#define R 300.0
#define PointNum 301
#define InterYNum 300

long double pointRight[PointNum][2] = {0.0} ;
long double pointLeft[PointNum][2] = {0.0} ;
long double midXRight[PointNum] = {0.0};
long double midYRight[PointNum] = {0.0};
long double midXLeft[PointNum] = {0.0};
long double midYLeft[PointNum] = {0.0} ;

long double angleOne = PI/18.0;
long double valueAngOne = tan(angleOne);
long double angleTwo = PI/4.0;
long double valueAngTwo = tan(angleTwo);
long double angleThree = PI/3.0;
long double valueAngThr = tan(angleThree);

long double intYAngOneRight[InterYNum] = {0.0};
long double intYAngTwoRight[InterYNum] = {0.0};
long double intYAngThrRight[InterYNum] = {0.0};
long double intYAngOneLeft[InterYNum] = {0.0};
long double intYAngTwoLeft[InterYNum] = {0.0};
long double intYAngThrLeft[InterYNum] = {0.0};

long double interYOne[InterYNum*2] = {0.0};
long double interYTwo[InterYNum*2] = {0.0};
long double interYThr[InterYNum*2] = {0.0};

long double changeXY[InterYNum*2][2] = {0.0};

long double disAngOne[InterYNum*2] = {0.0};
long double disAngTwo[InterYNum*2] = {0.0};
long double disAngThr[InterYNum*2] = {0.0};

long double sectionOne[InterYNum*2][2] = {0.0};
long double sectionTwo[InterYNum*2][2] = {0.0};
long double sectionThr[InterYNum*2][2] = {0.0};

long double lenInSecOne[InterYNum*2] = {0.0};
long double lenInSecTwo[InterYNum*2] = {0.0};
long double lenInSecThr[InterYNum*2] = {0.0};

long double scaLenOne[InterYNum*2] = {0.0};
long double scaLenTwo[InterYNum*2] = {0.0};
long double scaLenThr[InterYNum*2] = {0.0};

void getPointAndMidRight();
void getPointAndMidLeft();

void getIntYRight();
void getIntYLeft();

void getInterY();
void getChangeXY();
void getDis();
void getSections();
void getLensInSec();
void getScasLen();
int main(void){

    getPointAndMidLeft();
    getPointAndMidRight();
    getIntYRight();
    getIntYLeft();
    getInterY();
    getChangeXY();
    getDis();
    getSections();
    getLensInSec();
    getScasLen();

}



void getPointAndMidRight(){

    pointRight[0][0] = 0 ;
	pointRight[0][1] = -300.0;
	int i = 0 ;
	while(i <300){
		long double x = pointRight[i][0] + 0.01;
		while(true){
			long double y =(-1) *sqrt(300*300 - x * x);
			long double tempX = (x - pointRight[i][0] ) * (x - pointRight[i][0]);
			long double tempY = (y - pointRight[i][1]) * (y - pointRight[i][1]) ;
			long double temp_pointLeftRight = tempX + tempY - 1.0;
			if(abs(temp_pointLeftRight) - 0.05 <= 0 ){
				pointRight[i+1][0] = x ;
				pointRight[i+1][1] = y ;
				break;
			}
			x += 0.01 ;
		}
	++ i ;
    }
    i = 0 ;
    while(i < 300 ){
        midXRight[i] = (pointRight[i][0] + pointRight[i+1][0]) / 2.0 ;
        midYRight[i] = (pointRight[i][1] + pointRight[i+1][1]) / 2.0 ;
        i ++;
    }
}

void getPointAndMidLeft(){
    
    pointLeft[0][0] = 0 ;
	pointLeft[0][1] = -300.0;
	int i = 0 ;
	while(i < 300){
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

void getIntYRight(){
        
    int i = 0 ;
    while(i < 300){
        long double tempMedX = midXRight[i];
        long double tempMedY = midYRight[i];
        long double molOne = (tempMedX-valueAngOne*tempMedY)*(R*R-0.25);
        long double denOne = (2*tempMedX*tempMedY)+valueAngOne*(tempMedX*tempMedX-tempMedY*tempMedY);
        intYAngOneRight[i] = molOne/denOne;
        long double molTwo = (tempMedX-valueAngTwo*tempMedY)*(R*R-0.25);
        long double denTwo = (2*tempMedX*tempMedY)+valueAngTwo*(tempMedX*tempMedX-tempMedY*tempMedY);
        intYAngTwoRight[i] = molTwo/denTwo;
        long double molThr = (tempMedX-valueAngThr*tempMedY)*(R*R-0.25);
        long double denThr = (2*tempMedX*tempMedY)+valueAngThr*(tempMedX*tempMedX-tempMedY*tempMedY);
        intYAngThrRight[i] = molThr/denThr;
        i++;
    }
}

void getIntYLeft(){
        
    int i = 0 ;
    while(i < 300){
        long double tempMedX = midXLeft[i];
        long double tempMedY = midYLeft[i];
        long double molOne = (tempMedX-valueAngOne*tempMedY)*(R*R-0.25);
        long double denOne = (2*tempMedX*tempMedY)+valueAngOne*(tempMedX*tempMedX-tempMedY*tempMedY);
        intYAngOneLeft[i] = molOne/denOne;
        long double molTwo = (tempMedX-valueAngTwo*tempMedY)*(R*R-0.25);
        long double denTwo = (2*tempMedX*tempMedY)+valueAngTwo*(tempMedX*tempMedX-tempMedY*tempMedY);
        intYAngTwoLeft[i] = molTwo/denTwo;
        long double molThr = (tempMedX-valueAngThr*tempMedY)*(R*R-0.25);
        long double denThr = (2*tempMedX*tempMedY)+valueAngThr*(tempMedX*tempMedX-tempMedY*tempMedY);
        intYAngThrLeft[i] = molThr/denThr;
        i++;
    }
}

void getInterY(){
    for(int i = 0 ; i < InterYNum ; i ++){
        interYOne[i] = intYAngOneLeft[i] ;
    }
    for(int i = 0 ; i < InterYNum ; i ++){
        interYOne[i+InterYNum] = intYAngOneRight[i] ;
    }

    for(int i = 0 ; i < InterYNum ; i ++){
        interYTwo[i] = intYAngTwoLeft[i] ;
    }
    for(int i = 0 ; i < InterYNum ; i ++){
        interYTwo[i+InterYNum] = intYAngTwoRight[i] ;
    }

    for(int i = 0 ; i < InterYNum ; i ++){
        interYThr[i] = intYAngThrLeft[i] ;
    }
    for(int i = 0 ; i < InterYNum ; i ++){
        interYThr[i+InterYNum] = intYAngThrRight[i] ;
    }

    
}

void getChangeXY(){
    for(int i = 0 ; i < InterYNum ; i ++){
        changeXY[i][0] = pointLeft[i+1][0] - pointLeft[i][0] ;
        changeXY[i][1] = pointLeft[i+1][1] - pointLeft[i][1] ;
    }
    for(int i = 0 ; i < InterYNum ; i ++){
        changeXY[i+InterYNum][0] = pointRight[i+1][0] - pointRight[i][0] ;
        changeXY[i+InterYNum][1] = pointRight[i+1][1] - pointRight[i][1] ;
    }
}

void getDis(){
    for(int i = 0 ; i < InterYNum * 2 ; i ++){
        long double changeX = changeXY[i][0] ;
        long double changeY = changeXY[i][1] ;
        long double tempMole = changeY*changeX*(changeY-valueAngOne*changeX)+(changeX*changeX*changeX-valueAngOne*changeY*changeY*changeY);
        long double tempDeno = 2.0*changeX*changeY+valueAngOne*(changeX*changeX-changeY*changeY);
        disAngOne[i] = abs(tempMole / tempDeno) ;
    }

    for(int i = 0 ; i < InterYNum * 2 ; i ++){
        long double changeX = changeXY[i][0] ;
        long double changeY = changeXY[i][1] ;
        long double tempMole = changeY*changeX*(changeY-valueAngTwo*changeX)+(changeX*changeX*changeX-valueAngTwo*changeY*changeY*changeY);
        long double tempDeno = 2.0*changeX*changeY+valueAngTwo*(changeX*changeX-changeY*changeY);
        disAngTwo[i] = abs(tempMole / tempDeno) ;
    }

    for(int i = 0 ; i < InterYNum * 2 ; i ++){
        long double changeX = changeXY[i][0] ;
        long double changeY = changeXY[i][1] ;
        long double tempMole = changeY*changeX*(changeY-valueAngThr*changeX)+(changeX*changeX*changeX-valueAngThr*changeY*changeY*changeY);
        long double tempDeno = 2.0*changeX*changeY+valueAngThr*(changeX*changeX-changeY*changeY);
        disAngThr[i] = abs(tempMole / tempDeno) ;
    }

    
}

void getSections(){
    for(int i = 0 ; i < InterYNum *2 ; i ++){
        sectionOne[i][0] = interYOne[i] - disAngOne[i] / 2.0 ;
        sectionOne[i][1] = interYOne[i] + disAngOne[i] / 2.0 ; 
    }

    for(int i = 0 ; i < InterYNum *2 ; i ++){
        sectionTwo[i][0] = interYTwo[i] - disAngTwo[i] / 2.0 ;
        sectionTwo[i][1] = interYTwo[i] + disAngTwo[i] / 2.0 ; 
    }

    for(int i = 0 ; i < InterYNum *2 ; i ++){
        sectionThr[i][0] = interYThr[i] - disAngThr[i] / 2.0 ;
        sectionThr[i][1] = interYThr[i] + disAngThr[i] / 2.0 ; 
    }

}

void getLensInSec(){
    for(int i = 0 ; i < InterYNum * 2 ; i ++){
        long double length = disAngOne[i] ;
        long double secL = sectionOne[i][0] ;
        long double secR = sectionOne[i][1] ;
         if(secL + 150.0 >= 0 || secR + 170.0 <= 0 ){
                lenInSecOne[i] = 0.0 ;
            }    
            else if(secL + 170.0 >= 0 && secR + 150.0 >= 0){
                lenInSecOne[i] = -150.0 - secL ;
            }
            else if(secL + 170.0 <= 0 && secR + 150.0 <= 0){
                lenInSecOne[i] = secR + 170.0 ; 
            }
            else if (secL + 170.0 >= 0 && secR + 150.0 <= 0){
                lenInSecOne[i] = length;
            }
            else {
                lenInSecOne[i] = 20.0 ;
            }          
    }

    for(int i = 0 ; i < InterYNum * 2 ; i ++){
        long double length = disAngTwo[i] ;
        long double secL = sectionTwo[i][0] ;
        long double secR = sectionTwo[i][1] ;
         if(secL + 150.0 >= 0 || secR + 170.0 <= 0 ){
                lenInSecTwo[i] = 0.0 ;
            }    
            else if(secL + 170.0 >= 0 && secR + 150.0 >= 0){
                lenInSecTwo[i] = -150.0 - secL ;
            }
            else if(secL + 170.0 <= 0 && secR + 150.0 <= 0){
                lenInSecTwo[i] = secR + 170.0 ; 
            }
            else if (secL + 170.0 >= 0 && secR + 150.0 <= 0){
                lenInSecTwo[i] = length;
            }
            else {
                lenInSecTwo[i] = 20.0 ;
            }          
    }

    for(int i = 0 ; i < InterYNum * 2 ; i ++){
        long double length = disAngThr[i] ;
        long double secL = sectionOne[i][0] ;
        long double secR = sectionOne[i][1] ;
         if(secL + 150.0 >= 0 || secR + 170.0 <= 0 ){
                lenInSecThr[i] = 0.0 ;
            }    
            else if(secL + 170.0 >= 0 && secR + 150.0 >= 0){
                lenInSecThr[i] = -150.0 - secL ;
            }
            else if(secL + 170.0 <= 0 && secR + 150.0 <= 0){
                lenInSecThr[i] = secR + 170.0 ; 
            }
            else if (secL + 170.0 >= 0 && secR + 150.0 <= 0){
                lenInSecThr[i] = length;
            }
            else {
                lenInSecThr[i] = 20.0 ;
            }          
    }
}

void getScasLen(){
    for(int i = 0 ; i <InterYNum *2 ; i ++){
        scaLenOne[i] = lenInSecOne[i] / disAngOne[i] ;
    }

    for(int i = 0 ; i <InterYNum *2 ; i ++){
        scaLenTwo[i] = lenInSecTwo[i] / disAngTwo[i] ;
    }

    for(int i = 0 ; i <InterYNum *2 ; i ++){
        scaLenThr[i] = lenInSecThr[i] / disAngThr[i] ;
    }

     for(int i = 0 ; i < InterYNum * 2 ; i ++){
        cout<<scaLenThr[i]<<endl;
    }
}

