#ifndef included
#define included
#include "graphics.h"
#endif

Number::Number(double value) { val = value; }
Expression* Number::diff() { return (new Number(0)); };
void Number::print() { cout << val; }
float Number::graf(float x) { return val; }

Variable::Variable(const char x_in) { x = x_in; }
Expression* Variable::diff() { return new Number(1); }
void Variable::print() { cout << x; }
float Variable::graf(float x) { return x / t_c; }

Add::Add(Expression* left_in, Expression* right_in) {
    left = left_in;
    right = right_in;
}
Expression* Add::diff() { return new Add(left->diff(), right->diff()); }
void Add::print() {
    cout << '(';
    left->print();
    cout << '+';
    right->print();
    cout << ')';
}
float Add::graf(float x) { return left->graf(x) + right->graf(x); }

Sub::Sub(Expression* left_in, Expression* right_in) {
    left = left_in;
    right = right_in;
}
Expression* Sub::diff() { return new Sub(left->diff(), right->diff()); }
void Sub::print() {
    cout << '(';
    left->print();
    cout << '-';
    right->print();
    cout << ')';
}
float Sub::graf(float x) { return left->graf(x) - right->graf(x); }

Mul::Mul(Expression* left_in, Expression* right_in) {
    left = left_in;
    right = right_in;
}
Expression* Mul::diff() {
    Expression* U = new Mul(left->diff(), right);
    Expression* V = new Mul(left, right->diff());
    return new Add(U, V);
}
void Mul::print() {
    cout << '(';
    left->print();
    cout << '*';
    right->print();
    cout << ')';
}
float Mul::graf(float x) { return left->graf(x) * right->graf(x); }

Div::Div(Expression* l_in, Expression* r_in) : left(l_in), right(r_in) {}
Expression* Div::diff() {
    Expression* mnog =
        new Sub(new Mul(left->diff(), right), new Mul(left, right->diff()));
    Expression* chastnoe = new Mul(right, right);
    return new Div(mnog, chastnoe);
}
void Div::print() {
    cout << "(";
    left->print();
    cout << "/";
    right->print();
    cout << ")";
}
float Div::graf(float x) { return left->graf(x) / right->graf(x); }

Cos::Cos(Expression* a_in) : arg(a_in){};
void Cos::print() {
    cout << "(cos ";
    arg->print();
    cout << ")";
}
float Cos::graf(float x) { return cos(arg->graf(x)); }

Sin::Sin(Expression* a_in) : arg(a_in){};
Expression* Sin::diff() { return new Mul(arg->diff(), new Cos(arg)); }
void Sin::print() {
    cout << "(sin ";
    arg->print();
    cout << ")";
}
float Sin::graf(float x) { return sin(arg->graf(x)); }

Expression* Cos::diff() {
    return new Mul(arg->diff(), new Sub(new Number(0), new Sin(arg)));
}
