#include <bits/stdc++.h>
using namespace std ;

#define max 100

void readMatrix( string filename , int &  N , int a[max][max] ){
    ifstream fin (filename);
    fin >> N;
    for ( int i = 0 ; i < N ; i++){
        for ( int j = 0 ; j < N ; j++){
            fin >> a[i][j];
        }
    }
}

void getMatrix (string filenmae , int N , int a[100][100] , int sum1 , int sum2 ){
    ofstream fout (filenmae);
    int s1 = 0;
    int s2 = 0;
    for ( int i = 0 ; i < N ; i++ ){
        for ( int j = 0 ; j < N ; j++ ){
            if ( i == j ){
                s1 += a[i][j]; 
            }
            else if ( (i + j) == (N - 1)  ){
                s2 += a[i][j];
            } 
        }
    }
    sum1 = s1;
    sum2 = s2;
    fout << sum1 << " ";
    fout <<sum2;
}

int main(){
    int N;
    int a[max][max];
    int sum1 , sum2;
    readMatrix ("Diag.inp.txt" , N , a );
    getMatrix ("Diag.out.txt" , N , a , sum1 , sum2);
}