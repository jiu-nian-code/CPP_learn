#include "template_test.h"
// ÒþÊ½ÊµÀý»¯ MyTemplate<int>
void func2() {
    MyTemplate<int> t2;
    t2.print();
}
void func1();

int main() {
    func1();
    func2();
    return 0;
}