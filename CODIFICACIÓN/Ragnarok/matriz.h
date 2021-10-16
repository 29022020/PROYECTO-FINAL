#ifndef MATRIZ_H
#define MATRIZ_H

#include <cstdlib>
#include <time.h>
//#define diff 0.4

class matriz
{
public:
    matriz(int a,int b);
    void generar_mapa();
    int **get_matriz();
    int get_value(int fil, int col);
    void diff(float p);
    int aleatorio(int a, int b);
    bool aleatorio();
    int change_value(int fil,int col);
    ~matriz();

private:
    int **mat,fil, col;
    float diffi=0.5;
};

#endif // MATRIZ_H
