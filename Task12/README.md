
### Завдання №2

a) Створіть абстрактний клас Shape. Цей клас повинен мати три методи:

чисту віртуальну функцію print() з параметром типу std::ostream;

перевантаження operator<<;

пустий віртуальний деструктор.

**Відповідь №2.a)**

b) Створіть два класи: Triangle і Circle, які наслідують клас Shape.

Triangle повинен мати 3 точки в якості змінних-членів.

Circle повинен мати одну центральну точку і цілочисельний радіус в якості змінних-членів.

Перевантажте функцію print(), щоб наступний код:
```
int  main()
{
Circle  c(Point(1,  2,  3),  7);
std::cout  <<  c  <<  '\n';
Triangle  t(Point(1,  2,  3),  Point(4,  5,  6),  Point(7,  8,  9));
std::cout  <<  t  <<  '\n';
return  0;
}
```
Видавав наступний результат:

```
Circle(Point(1, 2, 3), radius 7)  
Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9))
```

Ось клас Point, який ви можете використовувати:

```
class  Point
{
private:
int  m_x  =  0;
int  m_y  =  0;
int  m_z  =  0;
public:
Point(int  x,  int  y,  int  z)
:  m_x(x),  m_y(y),  m_z(z)
{
}
friend  std::ostream&  operator<<(std::ostream  &out,  const  Point  &p)
{
out  <<  "Point("  <<  p.m_x  <<  ", "  <<  p.m_y  <<  ", "  <<  p.m_z  <<  ")";
return  out;
}
};
```

c) Використовуючи код з попередніх завдань (класи Point, Shape, Circle і Triangle) завершіть наступну програму:
```
#include <iostream>
#include <vector>
int  main()
{
std::vector<Shape*>  v;
v.push_back(new  Circle(Point(1,  2,  3),  7));
v.push_back(new  Triangle(Point(1,  2,  3),  Point(4,  5,  6),  Point(7,  8,  9)));
v.push_back(new  Circle(Point(4,  5,  6),  3));
// Вивід елементів вектора v тут
std::cout  <<  "The largest radius is: "  <<  getLargestRadius(v)  <<  '\n';  // реалізуйте цю функцію
// Видалення елементів вектора v тут
}
```
**_Підказка_:**  Вам потрібно додати метод getRadius() в Circle і виконати понижуюче приведення Shape* в Circle*, щоб отримати доступ до цього методу.
