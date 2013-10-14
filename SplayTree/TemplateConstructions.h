//
// Created by  Vladimir Skipor on 10/5/13.
// Copyright (c) 2013 ___FULLUSERNAME___. All rights reserved.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef __NewCppClass_H_
#define __NewCppClass_H_

#include <iostream>


template <bool condition, typename Then, typename Else>
struct IF {
};

template <typename Then, typename Else>
struct IF<true, Then, Else> {
    typedef Then result;
};

template <typename Then, typename Else>
struct IF<false, Then, Else> {
    typedef Else result;
};



//////////////////

template <typename A, typename B>
struct is_same {
    static bool const value = false;
};

template <typename T>
struct is_same  <T, T> {
    static bool const value = true;
};
////////////


template <typename A, typename B, typename Then, typename Else>
struct IF_same {
    typedef IF<is_same<A, B>::value, Then, Else> result;
};

/////////////////
template <typename Type, Type value>
struct Constant {
};





///////////////

template <typename T>
struct print_type {

    static void print() {
        std::cout << typeid(T).name() << std::endl;
    }

};

template <typename T, T value>
struct print_type< Constant<T, value> > {

    static void print() {
        std::cout << value << std::endl;
    }

};

/////////


template <typename A, typename B>
struct cmp {
    static const bool value = false;
//    static_assert(false, "compare different types");
};

//template <typename T>
//struct cmp <T, T> {
//    static bool const value = true;
//};

template <typename T, T valueL, T valueR>
struct cmp<Constant<T, valueL>, Constant<T, valueR> > {
    static const bool value = valueL < valueR;
};
 ///    /   /   /   //      /   /   //
template <typename T>
struct Error {
     typedef typename T::error_field result;
};



#endif //__NewCppClass_H_
