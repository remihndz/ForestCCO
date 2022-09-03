/**
 * @file ConstrainedConstructiveOptimization.h
 *
 *  Copyright 2022 Luiz C. M. de Aquino.
 *
 *  This file is part of CCOLab.
 *
 *  CCOLab is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  CCOLab is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with CCOLab.  If not, see <https://www.gnu.org/licenses/>
 *
 */

/**
 * @author Luiz Cláudio Mesquita de Aquino (luiz.aquino@ufvjm.edu.br)
 * @brief Implements the algorithm Constrained Constructive Optimization [1].
 *
 *  [1] R Karch, F Neumann, M Neumann, and W Schreiner. A three-dimensional model
 *  for arterial tree representation, generated by constrained constructive
 *  optimization. Computers in Biology and Medicine, 29(1):19–38, 1999.
 * @version 1.0
 * @date 2022-05-18
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

#include "ClassicDistanceCriterion.h"
#include "Connection.h"
#include "ConnectionEvaluationTable.h"
#include "domain/interface/Domain.h"
#include "interface/GeometricOptimization.h"
#include "interface/TargetFunction.h"
#include "interface/TerminalFlowFunction.h"
#include "progress/Progress.h"
#include "tree/TreeConnectionSearch.h"
#include "tree/interface/TreeModel.h"

using std::string;
using std::invalid_argument;
using std::cout;
using std::endl;

#ifndef _CCOLAB_CCO_CONSTRAINEDCONSTRUCTIVEOPTIMIZATION_H
#define _CCOLAB_CCO_CONSTRAINEDCONSTRUCTIVEOPTIMIZATION_H
class ConstrainedConstructiveOptimization {
 private:
  int _numberOfTerminals = 0;
  int _numberOfConnections = 20;
  int _maximumNumberOfAttempts = 10;
  double _radiusExpoent = 0.0;
  double _lengthExpoent = 0.0;
  TargetFunction *_targetFunction;
  TerminalFlowFunction *_terminalFlowFunction;
  GeometricOptimization *_geometricOptimization;
  Domain *_domain;
  TreeModel *_tree;
  DistanceCriterion *_distanceCriterion;

 public:
  ConstrainedConstructiveOptimization(Domain *domain, TreeModel *tree,
                                      int numberOfTerminals,
                                      double radiusExpoent,
                                      double lengthExpoent,
                                      int numberOfConnections,
                                      int maximumNumberOfAttempts);
  ~ConstrainedConstructiveOptimization() {}
  Domain *domain();
  void setDomain(Domain *domain);
  TreeModel *tree();
  void setTree(TreeModel *tree);
  DistanceCriterion *distanceCriterion();
  void setDistanceCriterion(DistanceCriterion *distanceCriterion);
  double radiusExpoent();
  void setRadiusExpoent(double radius);
  double lengthExpoent();
  void setLengthExpoent(double length);
  int maximumNumberOfAttempts();
  void setMaximumNumberOfAttempts(int maximumNumberOfAttempts);
  TargetFunction *targetFunction();
  void setTargetFunction(TargetFunction *targetFunction);
  TerminalFlowFunction *terminalFlowFunction();
  void setTerminalFlowFunction(TerminalFlowFunction *terminalFlowFunction);
  GeometricOptimization *geometricOptimization();
  void setGeometricOptimization(GeometricOptimization *geometricOptimization);
  void growRoot();
  void grow();
};
#endif  //_CCOLAB_CCO_CONSTRAINEDCONSTRUCTIVEOPTIMIZATION_H