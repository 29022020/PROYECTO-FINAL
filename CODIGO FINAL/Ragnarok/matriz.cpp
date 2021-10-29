#include "matriz.h"

matriz::matriz(int a, int b)
{
    fil=a;
    col=b;
    mat = new int* [fil];
    for(int f=0;f<fil;f++) {
        mat[f]=new int[col];
    }
    srand(time(NULL));
}

void matriz::generar_mapa()
{
    for(int f=0;f<fil;f++){
        for(int c=0;c<col;c++){
           /* if(f*c==0 || f==fil-1 || c==col-1 || (f%2==0 && c%2==0)){
                mat[f][c] = 0;//bloque solido
            }*/
            //else if
             if(!aleatorio() || (c==1 && f==1) || (c==2 && f==1) || (c==1 && f==2)){
                mat[f][c]=8;//ladrillo -> fondo
             }
          //  }

             /*else{
                mat[f][c]=1;//fondo->ladrillo
            }*/
        }
    }
}

bool matriz::aleatorio()
{
   /* int n;
    float x;
    n=rand();
    x=diffi*(RAND_MAX+1)-1;

    return n<=x;*/
}

int **matriz::get_matriz()
{
    return mat;
}

int matriz::get_value(int fil,int col)
{
    return  mat[fil][col];
}

void matriz::diff(float p)
{
    diffi=p;
}

matriz::~matriz()
{
    delete mat;
}
int matriz::aleatorio(int a, int b){
    int num;
    num=a+rand()%((b+1)-a);
    return num;
}

int matriz::change_value(int fil,int col){

    mat[fil][col]=8;
}
