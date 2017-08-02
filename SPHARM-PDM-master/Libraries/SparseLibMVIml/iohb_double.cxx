/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*             ********   ***                                 SparseLib++    */
/*          *******  **  ***       ***      ***                              */
/*           *****      ***     ******** ********                            */
/*            *****    ***     ******** ********              R. Pozo        */
/*       **  *******  ***   **   ***      ***                 K. Remington   */
/*        ********   ********                                 A. Lumsdaine   */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*                                                                           */
/*                                                                           */
/*                     SparseLib++ : Sparse Matrix Library                   */
/*                                                                           */
/*               National Institute of Standards and Technology              */
/*                        University of Notre Dame                           */
/*              Authors: R. Pozo, K. Remington, A. Lumsdaine                 */
/*                                                                           */
/*                                 NOTICE                                    */
/*                                                                           */
/* Permission to use, copy, modify, and distribute this software and         */
/* its documentation for any purpose and without fee is hereby granted       */
/* provided that the above notice appear in all copies and supporting        */
/* documentation.                                                            */
/*                                                                           */
/* Neither the Institutions (National Institute of Standards and Technology, */
/* University of Notre Dame) nor the Authors make any representations about  */
/* the suitability of this software for any purpose.  This software is       */
/* provided ``as is'' without expressed or implied warranty.                 */
/*                                                                           */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*      I/O for Harwell-Boeing files                                     */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <stdio.h>
#include "vecdefs.h"
#include VECTOR_H
#include MATRIX_H
#include "compcol_double.h"
#include "comprow_double.h"
#include "coord_double.h"
#include "iohb_double.h"

CompCol_Mat_double & readHB_mat(const char *filename, CompCol_Mat_double *A)
{
  int M = 0, N = 0, nz = 0, nrhs = 0;

  readHB_info(filename, &M, &N, &nz, &nrhs);
  CompCol_Mat_double & T = *A;

  T.newsize(M, N, nz);
  readHB_mat_double(filename, &T.col_ptr(0), &T.row_ind(0), &T.val(0) );
  return T;
}

CompRow_Mat_double & readHB_mat(const char *filename, CompRow_Mat_double *A)
{
  CompCol_Mat_double B;

  readHB_mat(filename, &B);
  *A = B;
  return *A;
}

Coord_Mat_double & readHB_mat(const char *filename, Coord_Mat_double *A)
{
  CompCol_Mat_double B;

  readHB_mat(filename, &B);
  *A = B;
  return *A;
}

const CompCol_Mat_double & writeHB_mat(const char *filename,
                                       const CompCol_Mat_double & A, int nrhs, const double* rhs, const char
                                       *title, const char *key)
{
  const char *title_ = (title == 0 ? "Generated by SparseLib++" : title);
  const char *key_ = (key == 0 ? "SL++" : key);

  writeHB_mat_double(filename, A.dim(0), A.dim(1), A.NumNonzeros(),
                     &(A.col_ptr(0) ), &(A.row_ind(0) ), &(A.val(0) ), nrhs, rhs, title_, key_);
  return A;
}

const CompRow_Mat_double & writeHB_mat(const char *filename,
                                       const CompRow_Mat_double & A, int nrhs, const double* rhs, const char *title,
                                       const char *key)
{
  const char *title_ = (title == 0 ? "Generated by SparseLib++" : title);
  const char *key_ = (key == 0 ? "SL++" : key);

  CompCol_Mat_double B(A);

  writeHB_mat_double(filename, B.dim(0), B.dim(1), B.NumNonzeros(),
                     &(B.col_ptr(0) ), &(B.row_ind(0) ), &(B.val(0) ), nrhs, rhs, title_, key_);
  return A;
}

const Coord_Mat_double & writeHB_mat(const char *filename,
                                     const Coord_Mat_double & A, int nrhs, const double *rhs, const char *title,
                                     const char *key)
{
  const char *title_ = (title == 0 ? "Generated by SparseLib++" : title);
  const char *key_ = (key == 0 ? "SL++" : key);

  CompCol_Mat_double B(A);

  writeHB_mat_double(filename, B.dim(0), B.dim(1), B.NumNonzeros(),
                     &(B.col_ptr(0) ), &(B.row_ind(0) ), &(B.val(0) ), nrhs, rhs, title_, key_);
  return A;
}

VECTOR_double & readHB_rhs(const char *filename, VECTOR_double *b, int j)
{
  int M;
  int N;
  int nrhs;
  int nz;

  readHB_info(filename, &M, &N, &nz, &nrhs);
  VECTOR_double T(N);

  if( j >= 0 && j < nrhs )
    {
    readHB_rhs_double(filename, &T(0), j);
    }
  else
    {
    printf(
      "Error: HB file right-hand-size vector #%d in file '%s' not found.\n",
      j, filename);
    exit(1);
    }
  return *b = T;
}
