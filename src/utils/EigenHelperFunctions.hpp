/*
 * EigenHelperFunctions.hpp
 *
 *  Created on: Dec 7, 2015
 *      Author: scheufks
 */

#ifndef EIGENHELPERFUNCTIONS_HPP_
#define EIGENHELPERFUNCTIONS_HPP_

#include "Eigen/Dense"
#include "Globals.hpp"

namespace precice {
namespace utils {


void shiftSetFirst(Eigen::MatrixXd& A, Eigen::VectorXd& v);

void appendFront(Eigen::MatrixXd& A, Eigen::VectorXd& v);

void removeColumnFromMatrix(Eigen::MatrixXd& A, int col);

void append(Eigen::VectorXd& v, double value);

template<typename Derived1>
void append(
    Eigen::MatrixXd& A,
    const Eigen::PlainObjectBase<Derived1>& B)
{
  int n = A.rows(), m = A.cols();
  if (n <= 0 && m <= 0) {
    A = B;
  } else {
    assertion2(B.rows() == n, B.rows(), A.rows());
    A.conservativeResize(n, m + B.cols());
    for(auto i = m; i < m + B.cols(); i++)
      A.col(i) = B.col(i-m);
  }
}

template<typename Derived1>
void append(
    Eigen::VectorXd& v,
    const Eigen::PlainObjectBase<Derived1>& app)
{
  int n = v.size();
  if(n <= 0){
    v = app;
  }else{
    assertion(app.cols() == 1 && app.rows() == n);
    v.conservativeResize(n + app.size());
    for(int i = 0; i < app.size(); i++)
      v(n+i) = app(i);
  }
}

}}
#endif /* EIGENHELPERFUNCTIONS_HPP_ */
