//
//  main.cpp
//  autograd_implementation
//
//  Created by Nithin Vijayakumar on 7/22/20.
//  Copyright © 2020 Nithin Vijayakumar. All rights reserved.
//

#include <iostream>
#include "tensor.h"
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    Tensor *t1 = new Tensor(5);
    Tensor *t2 = new Tensor(1);
    cout << Tensor::sum(t1, t2);
    return 0;
}
