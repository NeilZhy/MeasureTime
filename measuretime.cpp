#include <iostream>
#include <chrono>
#include <unistd.h>

struct MeasureTime {
  std::string name;
  pthread_t thid;
  pid_t pid;
  MeasureTime(std::string n)
      : name(n), thid(pthread_self()), pid(getpid()) {
    printf("{\"ts\": %lu, \"pid\":%d, \"tid\":%lu, \"ph\":\"B\", "
           "\"name\":\"MeasureTime:%s\"},\n",
           static_cast<unsigned long>(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count()), pid, thid, name.c_str    ());
  }
  ~MeasureTime() {
    printf("{\"ts\": %lu, \"pid\":%d, \"tid\":%lu, \"ph\":\"E\", "
           "\"name\":\"MeasureTime:%s\"},\n",
           static_cast<unsigned long>(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count()), pid, thid, name.c_str    ());
  }
};

class Shape
{
  public:
  virtual void drawshape() = 0;
};

class DrawCircle : public Shape
{
  public:
  void drawshape() {
    std::cout << "Circle\n";
  }
}; 

class DrawRect : public Shape
{
  public:
  void drawshape() {
    std::cout << "Rect\n";
  }
};

class DrawShape
{
  public:
    Shape* getshape(std::string shape) {
    if ("Circle" == shape) {
      return new DrawCircle();
    }
    if ("Rect" == shape) {
      return new DrawCircle();
    }
    return NULL;
  }
};


int main()
{
  MeasureTime("main");
  DrawShape shape;
  Shape* p_shape = shape.getshape("Circle");
  if (!p_shape) {
    std::cout << "Get shape failed.\n";
    return -1;
  }
  p_shape->drawshape();
  return 0;
}
