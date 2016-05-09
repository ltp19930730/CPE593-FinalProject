#ifndef OTHERS_HPP
#define OTHERS_HPP


class MandelPoint{
public:
    MandelPoint():x(0.0),y(0.0){}
    MandelPoint(double x, double y):x(x),y(y){}
    double x,y;
};

class ViewPoint{
public:
    ViewPoint():x(0),y(0){}
    ViewPoint(int x,int y):x(x),y(y){}
    int x, y;
};

class ViewParmeters{
  public:
    ViewParmeters():width(0),height(0),origin(ViewPoint()){}
    ViewParmeters(int width,int height,ViewPoint origin){
        this->width = width;
        this->height = height;
        this->origin = origin;
    }
    int width, height;
    ViewPoint origin;
};

class MandelLocation{
public:
    MandelLocation():origin(MandelPoint()),pixelDelta(0){}
    MandelLocation(MandelPoint origin, double pixelDelta){
        this->origin = origin;
        this->pixelDelta = pixelDelta;
    }
    MandelPoint origin;
    double pixelDelta;
};



typedef enum{
    COLOR_START = 0, COLOR_001, COLOR_010, COLOR_011, COLOR_100, COLOR_101, COLOR_110, COLOR_111, COLOR_END
} COLOR_CODE;




#endif // OTHERS_HPP

