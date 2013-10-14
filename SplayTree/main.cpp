//
//  main.cpp
//  SplayTree
//
//  Created by  Vladimir Skipor on 10/5/13.
//  Copyright (c) 2013  Vladimir Skipor. All rights reserved.
//

#include <iostream>
#include "TemplateConstructions.h"
#include "BinaryTree.h"


typedef Constant<int, 3> Const3;
typedef node<nil, nil, Const3> node3;
typedef node<node3, node3, Constant<size_t, 5> >  node333;




int main(int argc, const char * argv[])

{

    // insert code here...
    std::cout << "Hello, World!\n";




    std::cout << (cmp<Constant<int, 3>, Constant<int, 4>>::value) << std::endl;


    print_type<node333>();

    print_tree<node333>::print();
    print_tree<nil>::print();
    print_tree<int>::print();



    return 0;
}
