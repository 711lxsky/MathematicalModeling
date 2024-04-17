#include <bits/stdc++.h>

using namespace std;
#define A 0.00195
#define B -288.2355

long double pointCouple[301][2] = {0.0};
long double Y1[301] = {0.0} ;
long double Y2[301] = {0.0} ;

void getPoint();
void getY();

int main()
{
    getPoint();
    getY();
    
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
        //cout << '(' << pointCouple[i][0] << ',' << pointCouple[i][1] << ')' << endl;
        i++;
    }
    for( i = 1 ; i <= 300 ; i ++){
        //cout << '(' << pointCouple[i][0] << ',' << pointCouple[i][1] << ')' << endl;
    }
}

void getY(){
    for(int j = 0 ; j < 300 ; j ++){
        long resY = pointCouple[j][1] ;
        long double resX1 = pointCouple[j][0] , resX2 = pointCouple[j+1][0] ;
        long double resA = (1.0 - A*A*(resX1+resX2)*(resX1+resX2)) * resX1 ;
        long double resB = 2.0*A*(resX1+resX2) ;
        Y1[j] = resY + resA / resB ;
    }
    for( int j = 1  ; j <= 300 ; j ++){
        long resY = pointCouple[j][1] ;
        long double resX1 = pointCouple[j][0] , resX2 = pointCouple[j-1][0] ;
        long double resA = (1.0 - A*A*(resX1+resX2)*(resX1+resX2)) * resX1 ;
        long double resB = 2.0*A*(resX1+resX2) ;
        Y2[j-1] = resY + resA / resB ;
    }
    for(int k = 0 ; k < 300 ; k ++ ){
        cout << Y2[k] << endl ;
    //cout << k+1 << " ---  "  << Y1[k] << "  ***  " << Y2[k] << endl ;
    }
}
