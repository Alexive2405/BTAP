#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x , y , z;

    //quá tải 
    friend istream & operator >> ( istream & IN , Point & p){
        IN >> p.x >> p.y >> p.z;
        return IN;
    }
};

bool check( Point A , Point B , Point C ){
    long long ABx = B.x - A.x;
    long long ABy = B.y - A.y;
    long long ABz = B.z - A.z;
    
    long long ACx = C.x - A.x;
    long long ACy = C.y - A.y;
    long long ACz = C.z - A.z;

    if (  (ABx * ACy == ABy * ACx)  && (ABx * ACz == ABz * ACx)  ){
        return true;
    }
    return false; 
    }

int main(){
    int dem = 0;

    ifstream fin ("InpPoints.txt");
    ofstream fout ("OutPoints.txt");
    Point * ds = new Point [4];
    for ( int i = 0 ; i < 4 ; i++ ){
        fin >> ds[i];
    }
    for ( int i = 0 ; i < 4 ; i++ ){
        for ( int j = i + 1 ; j < 4 ; j++){
            for ( int k = j + 1 ; k < 4 ;k++){
                if ( check( ds[i] , ds[j] , ds[k] ) ){
                    dem++;
                }
            }
        }
    }
    fout << dem;
}
