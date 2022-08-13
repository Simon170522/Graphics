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
    Number(double value) { val = value; }
    Expression* diff() { return (new Number(0)); };
    void print() { cout << val; }
    float graf(float x) { return val; }
};
class Variable : public Expression {
   private:
    char x;

   public:
    Variable(const char x_in) { x = x_in; }
    Expression* diff() { return new Number(1); }
    void print() { cout << x; }
    float graf(float x) { return x / t_c; }
};
class Add : public Expression {
   private:
    Expression* left;
    Expression* right;

   public:
    Add(Expression* left_in, Expression* right_in) {
        left = left_in;
        right = right_in;
    }
    Expression* diff() { return new Add(left->diff(), right->diff()); }
    void print() {
        cout << '(';
        left->print();
        cout << '+';
        right->print();
        cout << ')';
    }
    float graf(float x) { return left->graf(x) + right->graf(x); }
};
class Sub : public Expression {
    Expression* left;
    Expression* right;

   public:
    Sub(Expression* left_in, Expression* right_in) {
        left = left_in;
        right = right_in;
    }
    Expression* diff() { return new Sub(left->diff(), right->diff()); }
    void print() {
        cout << '(';
        left->print();
        cout << '-';
        right->print();
        cout << ')';
    }
    float graf(float x) { return left->graf(x) - right->graf(x); }
};
class Mul : public Expression {
   private:
    Expression* left;
    Expression* right;

   public:
    Mul(Expression* left_in, Expression* right_in) {
        left = left_in;
        right = right_in;
    }
    Expression* diff() {
        Expression* U = new Mul(left->diff(), right);
        Expression* V = new Mul(left, right->diff());
        return new Add(U, V);
    }
    void print() {
        cout << '(';
        left->print();
        cout << '*';
        right->print();
        cout << ')';
    }
    float graf(float x) { return left->graf(x) * right->graf(x); }
};
class Div : public Expression {
   private:
    Expression* left;
    Expression* right;

   public:
    Div(Expression* l_in, Expression* r_in) : left(l_in), right(r_in) {}
    Expression* diff() {
        Expression* mnog =
            new Sub(new Mul(left->diff(), right), new Mul(left, right->diff()));
        Expression* chastnoe = new Mul(right, right);
        return new Div(mnog, chastnoe);
    }
    void print() {
        cout << "(";
        left->print();
        cout << "/";
        right->print();
        cout << ")";
    }
    float graf(float x) { return left->graf(x) / right->graf(x); }
};
class Cos : public Expression {
   private:
    Expression* arg;

   public:
    Cos(Expression* a_in) : arg(a_in){};
    Expression* diff();
    void print() {
        cout << "(cos ";
        arg->print();
        cout << ")";
    }
    float graf(float x) { return cos(arg->graf(x)); }
};
class Sin : public Expression {
   private:
    Expression* arg;

   public:
    Sin(Expression* a_in) : arg(a_in){};
    Expression* diff() { return new Mul(arg->diff(), new Cos(arg)); }
    void print() {
        cout << "(sin ";
        arg->print();
        cout << ")";
    }
    float graf(float x) { return sin(arg->graf(x)); }
};

Expression* Cos::diff() {
    return new Mul(arg->diff(), new Sub(new Number(0), new Sin(arg)));
}
