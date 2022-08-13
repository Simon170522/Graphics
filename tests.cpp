#include <gtest/gtest.h>

#include <cstdlib>

int p = rand() % 100;
TEST(Number, trueNumber) {
    Expression* s = new Number(p);
    EXPECT_EQ(s.graf(0), p);
}

TEST(Var, trueVar) {
    Expression* s = new Variable('x');
    EXPECT_EQ(s.graf(p), float(p) / t_c);
}

TEST(Add, trueAddition) {
    Expression* s = new Add(new Number(p), new Number(p + 1));
    EXPECT_EQ(s.graf(0), p + p + 1);
}

TEST(Sub, trueSub) {
    Expression* s = new Sub(new Number(p + 98), new Number(p));
    EXPECT_EQ(s.graf(0), 98);
}
TEST(Mul, trueMul) {
    Expression* s = new Mul(new Number(p), new Variable('x'));
    EXPECT_EQ(s.graf(4), p * 4);
}
