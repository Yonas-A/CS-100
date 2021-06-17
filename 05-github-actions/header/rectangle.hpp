#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle {
    private:
        int width;
        int height;
    public:
        Rectangle(int w, int h);
        void set_width(int w);
        void set_height(int h);
        int get_width();
        int get_height();
        int area();
        int perimeter();
};

#endif /* RECTANGLE_HPP*/
