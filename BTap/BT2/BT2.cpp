#include <bits/stdc++.h>
using namespace std; 

#define max 100

bool check( int a[max][max] , int M , int N , int i , int j ){
    int v = a[i][j];
    //các giá trị lân cận 
    int di[]= { -1 , -1 , -1 , 0 , 0  , 1 , 1 , 1};
    int dj[]= { -1 , 0 , 1 , -1 , 1 , -1 , 0 , 1};

    for ( int k = 0 ; k < 8 ; k++ ){
        int ni = i + di[k];
        int nj = j + dj[k];
        if ( ni >= 0 && ni < N && nj >=0 && nj < M ){
            if ( v <= a[ni][nj] ){
                return false;
            }
        }
    }
    return true;
}

int main(){
    ifstream fin ("InpMax.txt");
    ofstream fout ("OutMax.txt");

    int M , N;
    int dem = 0;
    fin >> M >> N;


    int a[max][max];

    for ( int i = 0 ; i < M ; i++){
        for ( int j = 0 ; j < N ; j++){
            fin >> a[i][j];
        }
    }

    for ( int i = 0 ; i < M ; i++){
        for ( int j = 0 ; j < N ; j++){
            if ( check ( a , M , N , i , j ) ){
                dem++;
            } 
        }
    }

    fout << dem; 


}


