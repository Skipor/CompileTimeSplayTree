//
// Created by  Vladimir Skipor on 10/5/13.
// Copyright (c) 2013 ___FULLUSERNAME___. All rights reserved.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef __NewCppClass_H_
#define __NewCppClass_H_

#include <iostream>

struct nil {
    typedef nil left;
    typedef nil right;
    typedef nil data;
};


// Error<T> compile failed if T != nil. Tree functions works well, and use that Error<nil> is nil, and nil have "node" typedefs.


template <typename T>
struct Invalid_argument {
    typedef typename T::error_type_result result;
    static const bool value = T::error_bool_value;

};
template <typename T>
struct Error {
    typedef typename T::error_type_result result;
    static const bool value = T::error_bool_value;

};

template <>
struct Error<nil> {
    typedef nil result;
    static const bool value = false;

};

//    /   /   /   //      /   /   //



//  /   /   /   /




template <typename T>
struct NOT_NIL {
    static bool const value = true;
};

template <>
struct NOT_NIL<nil> {
    static bool const value = false;
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
        std::cout << value;
    }

};
template <>
struct print_type< nil > {

    static void print() {
        std::cout << "nil";
    }

};

/////////

//template <typename T>
//struct cmp <T, T> {
//    static bool const value = true;
//};



template <typename A, typename B>
struct is_less {
    static bool const value = Error<A>::value;
};

template <typename T, T valueL, T valueR>
struct is_less<Constant<T, valueL>, Constant<T, valueR> > {
    static bool const value = valueL < valueR;
};


template <typename A, typename B>
struct is_more {
    static bool const value = Error<A>::value;
};


template <typename T, T valueL, T valueR>
struct is_more<Constant<T, valueL>, Constant<T, valueR> > {
    static bool const value = valueL > valueR;
};

/////// /   /   /   /   /   /   /


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
    typedef typename IF<is_same<A, B>::value, Then, Else>::result result;
};


#endif //__NewCppClass_H_
