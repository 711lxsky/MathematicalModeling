#include <bits/stdc++.h>

using namespace std;
#define A 0.0024
#define B -316.04014

long double pointCouple[301][2] = {0.0};
long double medX[301] = {0.0} , medY[301]={0.0};
long double resInterY[301] = {0.0} ;
void getPoint();
void getMedAndInt();
int main()
{   
   getPoint();
   getMedAndInt();
    return 0 ;
}

void getPoint(){
    long double endPointX = -249.31;
    pointCouple[0][0] = endPointX;
    pointCouple[0][1] = A * endPointX * endPointX + B ;
    int i = 0 ;
    while(i <= 300){
        long double tempX = pointCouple[i][0];
        long double testX = tempX + 0.01;
        while (true)
        {
        long double judNum = (testX - tempX)*(testX - tempX)*(A*A*(testX+tempX)*(testX+tempX) + 1.0) - 1.0;
        if ( abs(judNum) - 0.014965<= 0   ){
            pointCouple[i+1][0] = testX;
            pointCouple[i+1][1] = A * testX * testX + B ; 
            break;
        }
        testX += 0.01;
        }
        //cout << "ok++    " << pointCouple[i][0] << endl;
        i++;
    }
    
}

void getMedAndInt(){
    for(int j = 0 ; j < 300 ; j ++){
        medX[j] = (pointCouple[j][0] + pointCouple[j+1][0]) / 2.0 ;
        medY[j] = (pointCouple[j][1] + pointCouple[j+1][1]) / 2.0 ;
        resInterY[j] = medY[j] + (1.0 - 4.0 *A*A*medX[j]*medX[j]) / (4.0 * A) ;
        //cout << medX[j] << "   " << medY[j] << endl;
        //cout << '(' << pointCouple[j][0] << "," << pointCouple[j][1] << ')' << endl ;
        printf("%.5LF\n" ,resInterY[j]) ;
    }
    
}

