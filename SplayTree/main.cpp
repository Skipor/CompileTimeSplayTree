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
typedef Constant <int, 1> Const1;
typedef Constant <int, 2> Const2;
typedef Constant<int, 3> Const3;
typedef Constant<int, 4> Const4;
typedef Constant<int, 5> Const5;
typedef Constant<int, 6> Const6;
typedef Constant<int, 7> Const7;
typedef Constant<int, 8> Const8;
typedef Constant<int, 9> Const9;
typedef Constant<int, 10> Const10;
typedef Constant<int, 11> Const11;
typedef Constant<int, 12> Const12;
typedef Constant<int, 13> Const13;
typedef Constant<int, 14> Const14;
typedef Constant<int, 15> Const15;
typedef Constant<int, 16> Const16;
typedef Constant<int, 17> Const17;
typedef Constant<int, 18> Const18;
typedef Constant<int, 19> Const19;
typedef Constant<int, 20> Const20;

typedef node<nil, nil, Const1> Tree1;
typedef node< Tree1 , node< nil, nil, Const3 >, Const2 > Tree3;
typedef node< Tree3 , node< nil, nil, Const5 >, Const4 > Tree5;
typedef node< Tree5 , node< nil, nil, Const7 >, Const6 > Tree7;
typedef node< Tree7, node< nil, nil, Const9 >, Const8 > Tree9;
typedef node< Tree9 , node< nil, nil, Const11 >, Const10 > Tree11;
typedef node< Tree11 , node< nil, nil, Const13 >, Const12 > Tree13;
typedef node< Tree13 , node< nil, nil, Const15 >, Const14 > Tree15;
typedef node< Tree15 , node< nil, nil, Const17 >, Const16 > Tree17;
typedef node< Tree17 , node< nil, nil, Const19 >, Const18 > Tree19;



typedef node<node<nil, nil, Const2>,node<nil, nil, Const5>, Const3 > node235;

typedef node<nil, nil, Const3> node3;
typedef node<node3, node<nil, nil, Const5>, Const3> node335;







int main(int argc, const char * argv[])

{

    // insert code here...
    std::cout << "Hello, World!\n";




//    std::cout << (is_less< Constant<int, 3>, Constant<int, 4> >::value) << std::endl;
//    std::cout << (is_more< Constant<int, 3>, Constant<int, 4> >::value) << std::endl;
//    std::cout << (is_same< Constant<int, 4>, Constant<int, 4> >::value) << std::endl;
//    std::cout << (is_same< Constant<int, 3>, Constant<int, 4> >::value) << std::endl;



//    std::cout << node_data_is_same< node<nil, nil, Constant<int, 3> >, Constant<int, 3> >::value << std::endl;
//    std::cout << node_data_is_same< nil, Constant<int, 3> >::value << std::endl;


//    print_type<node335>();
//    std::cout << std::endl;

//
//    debug_print_tree<node335>::print();
////    print_tree<nil>::print();
////    print_tree<int>::print();
//    std::cout << std::endl;
//    debug_print_tree<typename right_rotate<node335> :: result>::print();
//    std::cout << std::endl;
//
//    print_type<typename right_rotate<node335> ::result::data >::print();
//    std::cout << std::endl;
//
//
//    debug_print_tree<typename splay<node335, Const5>::result>::print();
//    std::cout << std::endl;
//
////
////    print_tree<typename splay<node335, Const3>::result>::print();
////    std::cout << std::endl;
//
//    debug_print_tree<typename splay<node235, Const5>::result>::print();
//    std::cout << std::endl;
//
//
//    debug_print_tree<typename splay<node235, Const3>::result>::print();
//    std::cout << std::endl;
//    debug_print_tree<typename splay<node235, Const2>::result>::print();
//    std::cout << std::endl;
//
//    debug_print_tree<typename splay<node235, Const1>::result>::print();
//    std::cout << std::endl;
    debug_print_tree<Tree19>::print();
    std::cout << std::endl;

    debug_print_tree<typename splay<Tree19, Const3>::result>::print();
    std::cout << std::endl;

    debug_print_tree<typename splay<Tree19, Const5>::result>::print();
    std::cout << std::endl;

    debug_print_tree<typename splay<Tree19, Const6>::result>::print();
    std::cout << std::endl;

    debug_print_tree<typename splay<Tree19, Const9>::result>::print();
    std::cout << std::endl;

    debug_print_tree<typename splay<Tree19, Const11>::result>::print();
    std::cout << std::endl;

    debug_print_tree<typename splay<Tree19, Const13>::result>::print();
    std::cout << std::endl;

    debug_print_tree<typename splay<Tree19, Const12>::result>::print();
    std::cout << std::endl;

    structured_print_tree<typename splay<Tree19, Const18>::result>::print();
    std::cout << std::endl;

    debug_print_tree<nil>::print();
    std::cout << std::endl;

    print_type<typename get_next<typename splay<Tree19, Const3>::result, Constant<int, -10> >::result>::print();
    std::cout << std::endl;

    print_type<typename get_next<typename splay<Tree19, Const3>::result, Constant<int, 19> >::result>::print();
    std::cout << std::endl;





//



    return 0;
}
