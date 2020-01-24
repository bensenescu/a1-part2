#include "Array.h"
#include "string.h"

void FAIL() {   exit(1);    }
void OK(const char* m) { /** print m */ }
void t_true(bool p) { if (!p) FAIL(); }
void t_false(bool p) { if (p) FAIL(); }

// testing String constructors and functions
void test1() {
    String * s = new String("Hello");
    String * t = new String("World");
    String * u = s->concat(t);
    Array * arr = new Array();
    arr->add(s);
    arr->add(t);
    arr->add(u);
    t_true(arr->size() == 3);
    // OK("1");
}

int main() {
    test1();
    return 0;
}
