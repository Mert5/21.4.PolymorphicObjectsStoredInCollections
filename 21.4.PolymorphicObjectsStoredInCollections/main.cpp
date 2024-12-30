#include <iostream>
#include <memory>
#include "shape.h"
#include "oval.h"
#include "circle.h"

//  Reference => https://www.youtube.com/watch?v=8jLOx1hD3_o

int main(){

    Circle circle1{6.2,"circle1"};
    Oval oval1{7.6,3.5,"oval1"};
    Circle circle2{4.8,"circle2"};
    Oval oval2{17.3,7.7,"oval2"};
    Circle circle3{9.3,"circle3"};
    Oval oval3{4.1,1.2,"oval3"};

    // If you store raw object data in an array set up to store base class objects
    // the data is going to be sliced off!

    /*
    std::cout << "sizeof (circle1) : " << sizeof(circle1) << std::endl;
    Shape shapes1[] {circle1,oval1,circle2,oval2,circle3,oval3};

    for (Shape& s : shapes1){
        std::cout << "sizeof (object) : " << sizeof(s) << std::endl;
        s.draw();
    }
    */


    // What if we store in references?
    // const Shape& shapes2[] {circle1,oval1,circle2,oval2,circle3,oval3};
    // they have to be left assignable and references are not left assignable, so compiler error!


    // Raw pointers => is going to work
    /*
    Shape* shapes3[] {&circle1,&oval1,&circle2,&oval2,&circle3,&oval3};

    for(Shape* shape_ptr : shapes3){
        std::cout << "Inside array, sizeof(*shape_ptr) : " << sizeof(*shape_ptr) << std::endl;
        shape_ptr->draw();
        std::cout << std::endl;
    }
    */


    // Smart/unique/shared pointers     => in here, we used base pointers
    std::shared_ptr<Shape> shapes4[] {std::make_shared<Circle>(12.2, "Circle4"),
                                    std::make_shared<Oval>(10.0,20.0,"Oval4")};
    
    for(auto& s : shapes4){
        s->draw();
    }

    return 0;
}