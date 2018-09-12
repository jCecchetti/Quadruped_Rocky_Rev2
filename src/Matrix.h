/*
 * Matrix.h
 *
 *  Created on: Sep 7, 2018
 *      Author: julia
 */

#ifndef MATRIX_H_
#define MATRIX_H_

namespace Matrix{
   // matrix-vector multiplication (y = A * x)
    void multiply(double a[3][3], const double x[3], double output[3]) {
        int m = 3;
        int n = 3;
        double y[3];
        for (int i = 0; i < m; i++){
        	for (int j = 0; j < n; j++){
        		y[i] += a[i][j] * x[j];
        	}
        output[i] = y[i];
        }

    }

 // return c = a * b
   /* void multiply(double[][] a, double[][] b) {
        int m1 = a.length;
        int n1 = a[0].length;
        int m2 = b.length;
        int n2 = b[0].length;
        if (n1 != m2) throw new RuntimeException("Illegal matrix dimensions.");
        double[][] c = new double[m1][n2];
        for (int i = 0; i < m1; i++)
            for (int j = 0; j < n2; j++)
                for (int k = 0; k < n1; k++)
                    c[i][j] += a[i][k] * b[k][j];
        return c;
    }*/

    double determinate(double x0, double y0, double x1, double y1){
    	return x0*y1 - x1*y0;
    }
}
#endif /* MATRIX_H_ */
