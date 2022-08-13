#include <cmath>
#include <iostream>
#if defined(linux) || defined(_WIN32)
#include <GL/glut.h>
#else
#include <GLUT/GLUT.h>
#endif
#define WD 800
#define HT 600
#define t_c (HT * 1.0 / 20)  // за единицу считаем 1/20 экрана HT
using namespace std;

void reshape(int w, int h);
void display();
class Expression {  // виртуальный класс
   public:
    virtual Expression* diff() = 0;  //зануляем ссылку функции в стеке
    virtual void print() = 0;
    virtual float graf(float x) = 0;
};

class Number : public Expression {
   private:
    int val;

   public:
    Number(double value);
    Expression* diff();
    void print();
    float graf(float x);
};

class Variable : public Expression {
   private:
    char x;

   public:
    Variable(const char x_in);
    Expression* diff();
    void print();
    float graf(float x);
};

class Add : public Expression {
   private:
    Expression* left;
    Expression* right;

   public:
    Add(Expression* left_in, Expression* right_in);
    Expression* diff();
    void print();
    float graf(float x);
};

class Sub : public Expression {
    Expression* left;
    Expression* right;

   public:
    Sub(Expression* left_in, Expression* right_in);
    Expression* diff();
    void print();
    float graf(float x);
};

class Mul : public Expression {
   private:
    Expression* left;
    Expression* right;

   public:
    Mul(Expression* left_in, Expression* right_in);
    Expression* diff();
    void print();
    float graf(float x);
};

class Div : public Expression {
   private:
    Expression* left;
    Expression* right;

   public:
    Div(Expression* l_in, Expression* r_in);
    Expression* diff();
    void print();
    float graf(float x);
};

class Cos : public Expression {
   private:
    Expression* arg;

   public:
    Cos(Expression* a_in);
    Expression* diff();
    void print();
    float graf(float x);
};

class Sin : public Expression {
   private:
    Expression* arg;

   public:
    Sin(Expression* a_in);
    Expression* diff();
    void print();
    float graf(float x);
};