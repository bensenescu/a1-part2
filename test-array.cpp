#include "Array.h"
#include "string.h"

void FAIL() { exit(1); }
void OK(const char *m)
{ /** print m */
}
void t_true(bool p)
{
    if (!p)
        FAIL();
}
void t_false(bool p)
{
    if (p)
        FAIL();
}

class Integer : public Object
{
public:
    int val;

    Integer()
    {
        this->val = 0;
    }
    Integer(int val)
    {
        this->val = val;
    }
    ~Integer() {}

    int get()
    {
        return this->val;
    }

    void set(int val)
    {
        this->val = val;
    }

    size_t hash() {
        return this->val;
    }

    bool equals(Object* other) { 
        return this->hash() == other->hash(); 
    } 
};

class Boolean : public Object
{
public:
    bool val;

    Boolean()
    {
        this->val = 0;
    }

    Boolean(bool val)
    {
        this->val = val;
    }

    ~Boolean() {}

    bool get()
    {
        return this->val;
    }
    void set(bool val)
    {
        this->val = val;
    }

    size_t hash() {
        return this->val;
    }

    bool equals(Object* other) { 
        return this->hash() == other->hash(); 
    } 
};

class FloatingNumber : public Object
{
public:
    float val;

    FloatingNumber()
    {
        this->val = 0;
    }
    FloatingNumber(float val)
    {
        this->val = val;
    }
    ~FloatingNumber() {}

    float get()
    {
        return this->val;
    }
    void set(float val)
    {
        this->val = val;
    }

    size_t hash() {
        return static_cast<size_t>(this->val*100000.0);
    }

    bool equals(Object* other) { 
        return this->hash() == other->hash(); 
    } 
};

void test1()
{
    String *s = new String("Hello");
    String *t = new String("World");
    String *u = s->concat(t);
    Array *arr = new Array();
    t_true(arr->size() == 0);
    arr->add(s);
    arr->add(t);
    arr->add(u);
    t_true(arr->size() == 3);
}

// testing At function
void test2()
{
    Array *arr = new Array();
    String *a = new String("Apple");
    String *b = new String("Banana");
    String *c = new String("Chocolate");
    arr->add(a);
    arr->add(b);
    arr->add(c);
    t_true(arr->at(0)->equals(a));
    t_true(arr->at(1)->equals(b));
    t_true(arr->at(2)->equals(c));
}

// testing Back function
void test3()
{
    Array *arr = new Array();
    String *a = new String("Apple");
    String *b = new String("Banana");
    String *c = new String("Chocolate");
    arr->add(a);
    arr->add(b);
    t_true(arr->back()->equals(b));
    arr->add(c);
    t_true(arr->back()->equals(c));
}

// testing Begin function
void test4()
{
    Array *arr = new Array();
    String *a = new String("Apple");
    String *b = new String("Banana");
    String *c = new String("Chocolate");
    arr->add(a);
    arr->add(b);
    t_true(arr->begin()->equals(a));
    arr->add(c);
    t_true(arr->begin()->equals(a));
}

// testing Size function
void test5()
{
    Array *arr = new Array();
    String *a = new String("Apple");
    String *b = new String("Banana");
    String *d = new String("Dessert");
    t_true(arr->size() == 0);
    arr->add(a);
    arr->add(b);
    arr->add(d);
    t_true(arr->size() == 3);
}

// testing Empty function
void test6()
{
    Array *arr = new Array();
    t_true(arr->empty());
    String *a = new String("Apple");
    String *b = new String("Banana");
    arr->add(a);
    arr->add(b);
    t_false(arr->empty());
}

// testing Add with Index function
void test7()
{
    Array *arr = new Array();
    String *a = new String("Apple");
    String *b = new String("Banana");
    String *c = new String("Caramel");
    String *d = new String("Dessert");
    arr->add(a);
    arr->add(b);
    arr->add(d);
    arr->add(2, c);
    t_true(arr->at(2) == c);
    t_true(arr->at(1) == b);
    t_true(arr->at(3) == d);
}

// testing Remove function
void test8()
{
    Array *arr = new Array();
    String *a = new String("Apple");
    String *b = new String("Banana");
    String *c = new String("Cherry");
    String *d = new String("Dark Chocolate");
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
void test9()
{
    Array *arr = new Array();
    String *a = new String("Apple");
    String *b = new String("Banana");
    String *c = new String("Cherry");
    String *d = new String("Dark Chocolate");
    arr->add(a);
    arr->add(b);
    arr->add(c);
    arr->add(d);
    t_true(arr->size() == 4);
    arr->clear();
    t_true(arr->size() == 0);
}

// Tests Only a single element in an Array
void test10()
{
    String *t = new String("World");
    Array *arr = new Array();
    arr->add(t);
    t_true(arr->back()->equals(arr->begin()));
    t_true(arr->at(0)->equals(new String("World")));
    t_true(!arr->at(0)->equals(new String("NOT WORLD")));
    t_true(arr->at(1) == nullptr);
}

void test11()
{
    String *t = new String("Hello");
    String *k = new String("World");
    String *l = new String("Hi");
    Array *arr = new Array();
    t_true(arr->at(0) == nullptr);
    arr->add(t);
    t_true(arr->index_of(t) == 0);
    t_true(arr->size() == 1);
    arr->add(0, k);
    t_true(arr->index_of(t) != 0);
    t_true(arr->index_of(t) == 1);
    t_true(arr->index_of(k) == 0);
    arr->add(1, l);
    t_true(arr->index_of(t) != 1);
    t_true(arr->index_of(t) == 2);
    t_true(arr->index_of(k) == 0);
    t_true(arr->index_of(l) == 1);
    arr->clear();
    t_true(arr->size() == 0);
    
}

void testWithIntegers()
{
    Integer *zero = new Integer();
    Integer *one = new Integer(1);
    Integer *two = new Integer(2);
    Integer *three = new Integer(3);
    Array *arr = new Array();
    t_true(arr->size() == 0);
    arr->add(zero);
    t_true(!arr->empty());
    arr->add(one);
    arr->add(two);
    arr->add(three);
    t_true(arr->size() == 4);

    t_true(arr->index_of(zero) == 0);
    t_true(arr->index_of(one) == 1);

    t_true(dynamic_cast<Integer *>(arr->at(0))->get() == 0);
    t_true(dynamic_cast<Integer *>(arr->at(3))->get() == 3);
    t_true(dynamic_cast<Integer *>(arr->at(3))->equals(new Integer(3)));

    t_true(arr->remove(0)->equals(zero));
    t_true(arr->remove(3) == nullptr);
}

void testWithFloatingNumbers()
{
    FloatingNumber *ex1 = new FloatingNumber(2.0);
    FloatingNumber *ex2 = new FloatingNumber(3.5);
    FloatingNumber *ex3 = new FloatingNumber(3.5);
    Array *arr = new Array();
    t_true(arr->size() == 0);
    t_true(arr->empty());
    arr->add(ex1);
    t_true(!arr->empty());
    arr->add(ex2);
    arr->add(ex3);
    t_true(arr->size() == 3);
    t_true(!arr->empty());

    t_true(arr->index_of(ex1) == 0);
    t_true(arr->index_of(ex3) == 2);

    t_true(dynamic_cast<FloatingNumber *>(arr->at(0))->get() == 2.0);
    t_true(dynamic_cast<FloatingNumber *>(arr->at(1))->get() +
               dynamic_cast<FloatingNumber *>(arr->at(2))->get() ==
           7.0);

    t_true(arr->remove(0)->equals(ex1));
    t_true(arr->remove(2) == nullptr);
}

void testWithBooleans()
{
    Boolean *ex1 = new Boolean(true);
    Boolean *ex2 = new Boolean(false);
    Boolean *ex3 = new Boolean(false);
    t_true(ex2->equals(ex3));

    Array *arr = new Array();
    t_true(arr->size() == 0);
    arr->add(ex1);
    arr->add(ex2);
    arr->add(ex3);
    t_true(arr->back()->equals(new Boolean(false)));

    t_true(arr->index_of(ex1) == 0);
    t_true(arr->index_of(ex3) == 2);

    t_true(dynamic_cast<Boolean *>(arr->at(0))->get());
    t_true(!dynamic_cast<Boolean *>(arr->at(1))->get());
    t_true(arr->size() == 3);

    t_true(arr->remove(0)->equals(ex1));
    t_true(arr->remove(2) == nullptr);
}

int main()
{
    OK("Testing other types!\n");
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


    OK("Testing other types!\n");
    testWithIntegers();
    OK("test int");
    testWithFloatingNumbers();
    OK("test float");
    testWithBooleans();
    OK("test bool");

    OK("WOOOHOOO YOU PASSED ALL THE TESTS :)!\n");

    return 0;
}