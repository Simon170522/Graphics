#include <gtest/gtest.h>
#ifndef included
#define included
#include "graphics.h"
#endif
int p = rand() % 100;
class CR_t : public ::testing::Test {};
TEST(CR_t, trueNumber) {
    Expression* s = new Number(p);
    EXPECT_EQ(s->graf(0), p);
}

TEST(CR_t, trueVar) {
    Expression* s = new Variable('x');
    EXPECT_EQ(s->graf(p), float(p) / t_c);
}

TEST(CR_t, trueAddition) {
    Expression* s = new Add(new Number(p), new Number(p + 1));
    EXPECT_EQ(s->graf(0), p + p + 1);
}

TEST(CR_t, trueSub) {
    Expression* s = new Sub(new Number(p + 98), new Number(p));
    EXPECT_EQ(s->graf(0), 98);
}
TEST(CR_t, trueMul) {
    Expression* s = new Mul(new Number(p), new Variable('x'));
    EXPECT_EQ(s->graf(4), p * 4);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}