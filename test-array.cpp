#include "Array.h"
#include "string.h"

void FAIL() {   exit(1);    }
void OK(const char* m) { /** print m */ }
void t_true(bool p) { if (!p) FAIL(); }
void t_false(bool p) { if (p) FAIL(); }


void test1() {
    String * s = new String("Hello");
    String * t = new String("World");
    String * u = s->concat(t);
    Array * arr = new Array();
    t_true(arr->size() == 0);
    arr->add(s);
    arr->add(t);
    arr->add(u);
    t_true(arr->size() == 3);
}

    

// testing At function
void test2() {
    Array * arr = new Array();
    String * a = new String("Apple");
    String * b = new String("Banana");
    String * c = new String("Chocolate");
    arr->add(a);
    arr->add(b);
    arr->add(c);
    t_true(arr->at(0)->equals(a));
    t_true(arr->at(1)->equals(b));
    t_true(arr->at(2)->equals(c));

}

// testing Back function
void test3() {
    Array * arr = new Array();
    String * a = new String("Apple");
    String * b = new String("Banana");
    String * c = new String("Chocolate");
    arr->add(a);
    arr->add(b);
    t_true(arr->back()->equals(b));
    arr->add(c);
    t_true(arr->back()->equals(c));
}

// testing Begin function
void test4() {
    Array * arr = new Array();
    String * a = new String("Apple");
    String * b = new String("Banana");
    String * c = new String("Chocolate");
    arr->add(a);
    arr->add(b);
    t_true(arr->begin()->equals(a));
    arr->add(c);
    t_true(arr->begin()->equals(a));
}

// testing Size function
void test5() {
    Array * arr = new Array();
    String * a = new String("Apple");
    String * b = new String("Banana");
    String * d = new String("Dessert");
    t_true(arr->size() == 0);
    arr->add(a);
    arr->add(b);
    arr->add(d);
    t_true(arr->size() == 3);
}

// testing Empty function
void test6() {
    Array * arr = new Array();
    t_true(arr->empty());
    String * a = new String("Apple");
    String * b = new String("Banana");
    arr->add(a);
    arr->add(b);
    t_false(arr->empty());
}

// testing Add with Index function
void test7() {
    Array * arr = new Array();
    String * a = new String("Apple");
    String * b = new String("Banana");
    String * c = new String("Caramel");
    String * d = new String("Dessert");
    arr->add(a);
    arr->add(b);
    arr->add(d);
    arr->add(2, c);
    t_true(arr->at(2) == c);
    t_true(arr->at(1) == b);
    t_true(arr->at(3) == d);
}

// testing Remove function
void test8() {
    Array * arr = new Array();
    String * a = new String("Apple");
    String * b = new String("Banana");
    String * c = new String("Cherry");
    String * d = new String("Dark Chocolate");
    arr->add(a);
    arr->add(b);
    arr->add(c);
    arr->add(d);
    t_true(arr->size() == 4);
    size_t idx = arr->index_of(d);
    arr->remove(idx);
    t_true(arr->size() == 3);
}

// testing Clear function
void test9() {
    Array * arr = new Array();
    String * a = new String("Apple");
    String * b = new String("Banana");
    String * c = new String("Cherry");
    String * d = new String("Dark Chocolate");
    arr->add(a);
    arr->add(b);
    arr->add(c);
    arr->add(d);
    t_true(arr->size() == 4);
    arr->clear();
    t_true(arr->size() == 0);
}

// Tests Only a single element in an Array
void test10() {
    String * t = new String("World");
    Array * arr = new Array();
    arr->add(t);
    t_true(arr->back()->equals(arr->begin()));
    t_true(strcmp(
        dynamic_cast<String*>(arr->at(0))->val(),
        "World") == 0);
    t_true(arr->at(0)->equals(new String("World")));
    t_true(!arr->at(0)->equals(new String("NOT WORLD")));
    t_true(arr->at(1) == NULL);
    dynamic_cast<String*>(arr->at(0))->concat(new String("HELLO"));
}


int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();

    return 0;
}
