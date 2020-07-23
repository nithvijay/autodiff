//
//  tensor.h
//  autograd_implementation
//
//  Created by Nithin Vijayakumar on 7/22/20.
//  Copyright © 2020 Nithin Vijayakumar. All rights reserved.
//

#ifndef tensor_h
#define tensor_h
class Tensor{
public:
    Tensor(int a);
    
    static int sum(Tensor *t1, Tensor *t2);
private:
    int value;
};

#endif /* tensor_h */
