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





#endif // OTHERS_HPP

