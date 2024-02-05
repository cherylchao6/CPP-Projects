#ifndef CAR_H
#define CAR_H
namespace seneca {
class Car {
  char m_licencePlate[8];
  char *m_makeModel;
  char *m_serviceDesc;
  double m_cost;

public:
  int PRINT_WIDTH = 35;
  bool isEmpty() const;
  void setEmpty();
  void deallocateMemory();
  void set(const char plateNo[], const char *carMakeModel,
           const char *serviceDesc, double serviceCost);
  void display() const;
};

} // namespace seneca

#endif