#include <bits/stdc++.h>

using namespace std ;

#define PI 3.1415926
#define R 300.0
#define PointNum 301
#define InterYNum 300
#define LogIntYAngOneLeft 264
#define LogIntYAngTwoLeft 140
#define LogIntYAngThrLeft 86
#define LogIntYAngOneRight 285
#define LogIntYAngTwoRight 160
#define LogIntYAngThrRight 107
#define secProOneNum 581
#define secProTwoAngOneNum 549
#define secProTwoAngTwoNum 300
#define secProTwoAngThrNum 193

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
long double logIntYOneLeft[LogIntYAngOneLeft] = {0.0} ;
long double logIntYTwoLeft[LogIntYAngTwoLeft] = {0.0} ; 
long double logIntYThrLeft[LogIntYAngThrLeft] = {0.0} ;
long double logIntYOneRight[LogIntYAngOneRight] = {0.0}; 
long double logIntYTwoRight[LogIntYAngTwoRight] = {0.0}; 
long double logIntYThrRight[LogIntYAngThrRight] = {0.0};

int countDesSectionIntYNum[3] = {0};
int countSecProAAngOne[secProOneNum] = {0};
int countSecProAAngTwo[secProOneNum] = {0};
int countSecProAAngThr[secProOneNum] = {0};
int countSecProBAngOne[secProTwoAngOneNum] = {0};
int countSecProBAngTwo[secProTwoAngTwoNum] = {0};
int countSecProBAngThr[secProTwoAngThrNum] = {0} ;

long double interAngleOne[secProTwoAngOneNum] = {0} ;
long double interAngleTwo[secProTwoAngTwoNum] = {0} ;
long double interAngleThr[secProTwoAngThrNum] = {0} ;

void getPointAndMidRight();
void getPointAndMidLeft();

void getIntYRight();
void getIntYLeft();
void getLogIntYLeft();
void getLogIntYRight();

void countDesSection();
void countSecProOne();
void countSecProTwo();
void setIntA();
int main()
{

    getPointAndMidLeft();
    getPointAndMidRight();
    getIntYLeft();
    getIntYRight();
    getLogIntYLeft();
    getLogIntYRight();
    countDesSection();
    countSecProOne();
    countSecProTwo();


}


void getPointAndMidRight(){

    pointRight[0][0] = 0 ;
	pointRight[0][1] = -300.0;
	int i = 0 ;
	while(i < 300){
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

void getLogIntYLeft(){
    
    int countOne = 0 , countTwo = 0 , countThr = 0 ;
    for( int j = 0 ; j < 300 ; j ++){
        if(intYAngOneLeft[j] + 300.0 >= 0 && intYAngOneLeft[j] - 300.0 <= 0 ){
            logIntYOneLeft[countOne++] = intYAngOneLeft[j] ;
        }
        if(intYAngTwoLeft[j] + 300.0 >= 0 && intYAngTwoLeft[j] - 300.0 <= 0 ){
            logIntYTwoLeft[countTwo++] = intYAngTwoLeft[j];
        }
        if(intYAngThrLeft[j] + 300.0 >= 0 && intYAngThrLeft[j] - 300.0 <= 0 ){
            logIntYThrLeft[countThr++] = intYAngThrLeft[j];
        }
    }
}

void getLogIntYRight(){

    int countOne = 0 , countTwo = 0 , countThr = 0 ;
    for( int j = 0 ; j < 300 ; j ++){
        if(intYAngOneRight[j] + 300.0 >= 0 && intYAngOneRight[j] - 300.0 <= 0 ){
            logIntYOneRight[countOne++] = intYAngOneRight[j] ;
        }
        if(intYAngTwoRight[j] + 300.0 >= 0 && intYAngTwoRight[j] - 300.0 <= 0 ){
            logIntYTwoRight[countTwo++] = intYAngTwoRight[j];
        }
        if(intYAngThrRight[j] + 300.0 >= 0 && intYAngThrRight[j] - 300.0 <= 0 ){
            logIntYThrRight[countThr++] = intYAngThrRight[j];
        }
    }
       for(int j = LogIntYAngOneRight - 1 ; j >= 0  ; j -- ){
        for(int k = 0 ; k < j ; k++){
            if(logIntYOneRight[k] - logIntYOneRight[k+1] > 0 ){
                long double tempData = logIntYOneRight[k] ;
                logIntYOneRight[k] = logIntYOneRight[k+1] ;
                logIntYOneRight[k+1] = tempData;
            }
        }
    }

       for(int j = LogIntYAngTwoRight - 1 ; j >= 0  ; j -- ){
        for(int k = 0 ; k < j ; k++){
            if(logIntYTwoRight[k] - logIntYTwoRight[k+1] > 0 ){
                long double tempData = logIntYTwoRight[k] ;
                logIntYTwoRight[k] = logIntYTwoRight[k+1] ;
                logIntYTwoRight[k+1] = tempData;
            }
        }
    }

       for(int j = LogIntYAngThrRight - 1 ; j >= 0  ; j -- ){
        for(int k = 0 ; k < j ; k++){
            if(logIntYThrRight[k] - logIntYThrRight[k+1] > 0 ){
                long double tempData = logIntYThrRight[k] ;
                logIntYThrRight[k] = logIntYThrRight[k+1] ;
                logIntYThrRight[k+1] = tempData;
            }
        }
    }
}

void countDesSection(){

    for(int i = 0 ; i < LogIntYAngOneLeft ; i++){
        if(logIntYOneLeft[i] + 200.0 >= 0 && logIntYOneLeft[i] + 180.0 <= 0 ){
            countDesSectionIntYNum[0] ++ ;
        }
    }

    for(int i = 0 ; i < LogIntYAngOneRight ; i++){
        if(logIntYOneRight[i] + 200.0 >= 0 && logIntYOneRight[i] + 180.0 <= 0 ){
            countDesSectionIntYNum[0] ++ ;
        }
    }

    for(int i = 0 ; i < LogIntYAngTwoLeft ; i++){
        if(logIntYTwoLeft[i] + 200.0 >= 0 && logIntYTwoLeft[i] + 180.0 <= 0 ){
            countDesSectionIntYNum[1] ++ ;
        }
    }

    for(int i = 0 ; i < LogIntYAngTwoRight ; i++){
        if(logIntYTwoRight[i] + 200.0 >= 0 && logIntYTwoRight[i] + 180.0 <= 0 ){
            countDesSectionIntYNum[1] ++ ;
        }
    }

    for(int i = 0 ; i < LogIntYAngThrLeft ; i++){
        if(logIntYThrLeft[i] + 200.0 >= 0 && logIntYThrLeft[i] + 180.0 <= 0 ){
            countDesSectionIntYNum[2] ++ ;
        }
    }

    for(int i = 0 ; i < LogIntYAngThrRight ; i++){
        if(logIntYThrRight[i] + 200.0 >= 0 && logIntYThrRight[i] + 180.0 <= 0 ){
            countDesSectionIntYNum[2] ++ ;
        }
    }
}

void setIntA(){
    for(int i = 0 ; i < secProTwoAngOneNum ; i ++){
        if(i < LogIntYAngOneLeft ){
            interAngleOne[i] = logIntYOneLeft[i] ;
        }
        else {
            interAngleOne[i] = logIntYOneRight[i-LogIntYAngOneLeft];
        }
    }

    for(int i = 0 ; i < secProTwoAngTwoNum ; i ++){
        if(i < LogIntYAngTwoLeft ){
            interAngleTwo[i] = logIntYTwoLeft[i] ;
        }
        else {
            interAngleTwo[i] = logIntYTwoRight[i-LogIntYAngTwoLeft];
        }
    }

    for(int i = 0 ; i < secProTwoAngThrNum ; i ++){
        if(i < LogIntYAngThrLeft ){
            interAngleThr[i] = logIntYThrLeft[i] ;
        }
        else {
            interAngleThr[i] = logIntYThrRight[i-LogIntYAngThrLeft];
        }
    }

    for(int i = secProTwoAngOneNum - 1 ; i >=0 ; i --){
        for(int j = 0 ; j < i ; j ++){
            if(interAngleOne[j]  - interAngleOne[j+1] > 0){
                long double tempData = interAngleOne[j] ;
                interAngleOne[j] = interAngleOne[j+1] ;
                interAngleOne[j+1] = tempData;
            }
        }
    }
    for(int i = secProTwoAngTwoNum - 1 ; i >=0 ; i --){
        for(int j = 0 ; j < i ; j ++){
            if(interAngleTwo[j] > interAngleTwo[j+1]){
                long double tempData = interAngleTwo[j] ;
                interAngleTwo[j] = interAngleTwo[j+1] ;
                interAngleTwo[j+1] = tempData;
            }
        }
    }
    for(int i = secProTwoAngThrNum - 1 ; i >=0 ; i --){
        for(int j = 0 ; j < i ; j ++){
            if(interAngleThr[j] > interAngleThr[j+1]){
                long double tempData = interAngleThr[j] ;
                interAngleThr[j] = interAngleThr[j+1] ;
                interAngleThr[j+1] = tempData;
            }
        }
    }

}

void countSecProOne(){
    setIntA();
    for(int section = -300 , count = 0; section <= 280 ; section ++ , count ++){
        //cout << '[' << section << ',' << section+20 << ']' <<endl;
        for(int i = 0 ; i < secProTwoAngOneNum ; i ++){
            if(interAngleOne[i] - section >= 0 && interAngleOne[i] - (section + 20) <= 0){
                countSecProAAngOne[count] ++ ;
            }
        }
        for(int i = 0 ; i < secProTwoAngTwoNum ; i ++){
            if(interAngleTwo[i] - section >= 0 && interAngleTwo[i] - (section + 20) <= 0){
                countSecProAAngTwo[count] ++ ;
            }
        }
        for(int i = 0 ; i < secProTwoAngThrNum ; i ++){
            if(interAngleThr[i] - section >= 0 && interAngleThr[i] - (section + 20) <= 0){
                countSecProAAngThr[count] ++ ;
            }
        }
        //cout << countSecProAAngThr[count] << endl;
    }
}

void countSecProTwo(){
    setIntA();

    for(int i = 0 ; i < secProTwoAngOneNum ; i ++){
        long double section = 0.0 ;
        if(interAngleOne[i] - 0.0 < 0 ){
            section = interAngleOne[i] ;
        }
        else {
            section = interAngleOne[i] - 20.0 ;
        }
        for( int j = 0 ; j < secProTwoAngOneNum ; j ++){
            if(interAngleOne[j] - section >= 0 && interAngleOne[j] - (section+20.0) <= 0){
                countSecProBAngOne[i] ++ ;
            }
        }
        //cout << countSecProBAngOne[i]<< endl;   
    }

     for(int i = 0 ; i < secProTwoAngTwoNum ; i ++){
        long double section = 0.0 ;
        if(interAngleTwo[i] - 0.0 < 0 ){
            section = interAngleTwo[i] ;
        }
        else {
            section = interAngleTwo[i] - 20.0 ;
        }
        for( int j = 0 ; j < secProTwoAngTwoNum ; j ++){
            if(interAngleTwo[j] - section >= 0 && interAngleTwo[j] - (section+20.0) <= 0){
                countSecProBAngTwo[i] ++ ;
            }
        }
        //cout << countSecProBAngTwo[i]<< endl;
        //cout <<'[' << section << ',' << section+20.0 << ']' << endl;   
    }

    for(int i = 0 ; i < secProTwoAngThrNum ; i ++){
        long double section = 0.0 ;
        if(interAngleThr[i] - 0.0 < 0 ){
            section = interAngleThr[i] ;
        }
        else {
            section = interAngleThr[i] - 20.0 ;
        }
        for( int j = 0 ; j < secProTwoAngThrNum ; j ++){
            if(interAngleThr[j] - section >= 0 && interAngleThr[j] - (section+20.0) <= 0){
                countSecProBAngThr[i] ++ ;
            }
        }
        //cout << countSecProBAngThr[i]<< endl;
        //cout <<'[' << section << ',' << section+20.0 << ']' << endl;   
    }
}
