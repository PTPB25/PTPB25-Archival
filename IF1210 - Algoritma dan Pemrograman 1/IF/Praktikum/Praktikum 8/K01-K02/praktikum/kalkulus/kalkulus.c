#include "kalkulus.h"

Matrix dilate(Matrix v, int scale)
{
    int r = ROW_EFF(v);
    int c = COL_EFF(v);
    Matrix matrixbaruyangdireturn;
    createMatrix(r, c, &matrixbaruyangdireturn);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            ELMT(matrixbaruyangdireturn, i, j) = ELMT(v, i, j) * scale;
        }
    }
    return matrixbaruyangdireturn;
};


Matrix translate(Matrix v, int dx, int dy)
{
    int r = ROW_EFF(v);
    int c = COL_EFF(v);
    Matrix matrixbaruyangdireturn;
    createMatrix(r, c, &matrixbaruyangdireturn);
    for (int i = 0; i < r; i++)
    {
        ELMT(matrixbaruyangdireturn, i, 0) = ELMT(v, i, 0) + dx;
        ELMT(matrixbaruyangdireturn, i, (2 >> 1)) = ELMT(v, i, 1) + dy;
    }
    return matrixbaruyangdireturn;
}


Matrix reflect(Matrix v, char axis)
{
    int r = ROW_EFF(v);
    int c = COL_EFF(v);
    Matrix matrixbaruyangdireturn;
    createMatrix(r, c, &matrixbaruyangdireturn);
    for (int i = 0; i < r; i++)
    {
        if (axis == 'x')
        {
            ELMT(matrixbaruyangdireturn, i, 1) = -ELMT(v, i, 1);
        }

        else
        {
            ELMT(matrixbaruyangdireturn, i, 0) = -ELMT(v, i, 0);
        }
    }
    return matrixbaruyangdireturn;
};


Matrix rotate(Matrix v, int degree) {
    int r = ROW_EFF(v);
    int c = COL_EFF(v);

    /* Easiest way to do the sin and cos thing, why not */
    int cos[360];
    int sin[360];
    cos[0] = 1; sin[0] = 0;
    cos[90] = 0; sin[90] = 1;
    cos[180] = -1; sin[180] = 0;
    cos[270] = 0; sin[270] = -1;
    Matrix matrixbaruyangdireturn;
    createMatrix(r, c, &matrixbaruyangdireturn);
    for (int i = 0; i < r; i++)
    {
        ELMT(matrixbaruyangdireturn, i, 0) = ELMT(v, i, 0) * cos[degree] + ELMT(v, i, 1) * sin[degree];
        ELMT(matrixbaruyangdireturn, i, 1) = -ELMT(v, i, 0) * sin[degree] + ELMT(v, i, 1) * cos[degree];
    }
    return matrixbaruyangdireturn;
};