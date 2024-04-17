#include <iostream>

class Base {

public:
  
  void f1() {
    
    std::cout << "public wala function \n";  

  }

private:

  void f2() {

    std::cout << "private wala function \n";

  };

protected:

  void f3() {

    std::cout << "protected wala function \n";  

  }

};

class Child : Base {


public:

  void show() {

    Base::f1(); // f1 can be used as it's public
    Base::f3(); // f3 can be used as it's protected and Child is a part of Base family

  }

};

int main (int argc, char *argv[]) {
  
  Child child;

  child.show();  

  Base base;

  base.f1(); // only public fuctions can be used

  return 0;

}
