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
#include "SplayTree.h"

typedef Constant <int, 2> Const2;

typedef Constant<int, 3> Const3;
typedef Constant<int, 5> Const5;

typedef node<node<nil, nil, Const2>,node<nil, nil, Const5>, Const3 > node235;

typedef node<nil, nil, Const3> node3;
typedef node<node3, node<nil, nil, Const5>, Const3> node335;





int main(int argc, const char * argv[])

{

    // insert code here...
    std::cout << "Hello, World!\n";




    std::cout << (is_less< Constant<int, 3>, Constant<int, 4> >::value) << std::endl;
    std::cout << (is_more< Constant<int, 3>, Constant<int, 4> >::value) << std::endl;
    std::cout << (is_same< Constant<int, 4>, Constant<int, 4> >::value) << std::endl;
    std::cout << (is_same< Constant<int, 3>, Constant<int, 4> >::value) << std::endl;



    print_type<node335>();
    std::cout << std::endl;


    debug_print_tree<node335>::print();
//    print_tree<nil>::print();
//    print_tree<int>::print();
    std::cout << std::endl;
    debug_print_tree<typename right_rotate<node335> :: result>::print();
    std::cout << std::endl;

    print_type<typename right_rotate<node335> ::result::data >::print();
    std::cout << std::endl;


    print_tree<typename splay<node335, Const5>::result>::print();
    std::cout << std::endl;


    print_tree<typename splay<node335, Const3>::result>::print();
    std::cout << std::endl;

    print_tree<typename splay<node235, Const5>::result>::print();
    std::cout << std::endl;


    print_tree<typename splay<node235, Const3>::result>::print();
    std::cout << std::endl;
    print_tree<typename splay<node235, Const2>::result>::print();
    std::cout << std::endl;





    return 0;
}
