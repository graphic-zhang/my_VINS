//
//  main.cpp
//  MyTriangulation
//
//  Created by Yang Shuo on 18/3/15.
//  Copyright (c) 2015 Yang Shuo. All rights reserved.
//

#include <iostream>
#include <Eigen/Dense>

#include "Camera.h"
using namespace Eigen;

int main(int argc, const char * argv[]) {
    DistortCamera cam;
    cam.setImageSize(480, 752);
    cam.setIntrinsicMtx(365.07984, 365.12127, 381.0196, 254.4431);
    cam.setDistortionParam(-2.842958e-1,
                            8.7155025e-2,
                           -1.4602925e-4,
                           -6.149638e-4,
                           -1.218237e-2);
    
    Vector3f ptr;
    ptr << 3.5f, 3.35f, 6.0f;
    Vector2f z = cam.h(ptr);
    MatrixXf Jacob_h = cam.Jh(ptr);
    
    std::cout << "projected point is " << z << std::endl;
    std::cout << "Jacobian matrix is " << std::endl << Jacob_h << std::endl;
    return 0;
}