#ifndef CIRCLE_H
#define CIRCLE_H
class Circle{
    private:
        int radius;
    public:
        Circle();
        ~Circle();
        Circle(int r);
        Circle(Circle& c);
        double getArea();
};
#endif
