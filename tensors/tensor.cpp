//
//  tensor.cpp
//  autograd_implementation
//
//  Created by Nithin Vijayakumar on 7/22/20.
//  Copyright © 2020 Nithin Vijayakumar. All rights reserved.
//

#include "tensor.h"

Tensor::Tensor(int a){
    value = a;
}

int Tensor::sum(Tensor *t1, Tensor *t2){
    return (*t1).value + (*t2).value;
}
