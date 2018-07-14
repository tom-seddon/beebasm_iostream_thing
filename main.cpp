#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

template<class T>
static void test(const std::string &s) {
    printf("input line: ``%s''\n",s.c_str());
    T i;
    std::istringstream inp(s);
    printf("tellg before: %zu (0%zx)\n",(size_t)inp.tellg(),(size_t)inp.tellg());
    inp>>i;
    printf("result: %s\n",std::to_string(i).c_str());
    printf("tellg after: %zu (0%zx)\n",(size_t)inp.tellg(),(size_t)inp.tellg());
}

int main() {
    std::ios::sync_with_stdio();

    test<int>("123");
    test<double>("123");
    test<int>("123A");
    test<double>("123A");
}
