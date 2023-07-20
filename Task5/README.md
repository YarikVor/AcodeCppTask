
Ми просунулися ще на один розділ вперед. Щоб закріпити пройдений матеріал, швиденько повторимо теорію і виконаємо 2 практичних завдання.

Зміст:

1.  [Теорія](https://acode.com.ua/rozdil-5-pidsumkovyj-test/#toc-0)
2.  [Завдання №1](https://acode.com.ua/rozdil-5-pidsumkovyj-test/#toc-1)
3.  [Завдання №2](https://acode.com.ua/rozdil-5-pidsumkovyj-test/#toc-2)

## Теорія

**Оператори if**  дозволяють виконати код, враховуючи результат умови (істинна вона чи хибна). Якщо умова хибна, то виконується  **оператор else**. Можна об’єднувати декілька операторів if і else разом.

**Оператор switch**  забезпечує більш зручний і швидкий спосіб використання умов/розгалужень в коді. Він відмінно поєднується з перерахуваннями.

**Оператор goto**  дозволяє переносити точку виконання в програмі з одного місця на інше. Використовувати цей оператор не рекомендується.

**Цикл while**  виконує певний код до тих пір, поки умова істинна. Спочатку обчислюється умова, а потім виконується код.

**Цикл do while**  — це той же цикл while, тільки спочатку виконується код, а потім вже перевіряється умова. Він відмінно підходить для виведення меню або інших елементів, оскільки дозволяє виконати код хоча б один раз.

**Цикли for**  найбільш використовувані цикли. Вони ідеальні, коли потрібно виконати код певну кількість разів.

**Оператор break**  дозволяє негайно завершити виконання операторів switch, циклів while, do while або for.

**Оператор continue**  дозволяє негайно перейти до наступної ітерації циклу. Будьте обережні при використанні цього оператора в зв’язці з циклами while або do while — пам’ятайте про проблеми з інкрементом лічильника циклу.

І, нарешті,  **рандомні числа**  дозволяють отримати різні результати від виконання однієї і тієї ж програми.

## Тест

### Завдання №1

У  [**підсумковому тесті розділу №2**](https://acode.com.ua/glava-2-pidsumkovyj-test/#toc-4)  ми написали програму імітації м’ячика, що падає з вежі. Оскільки тоді ми ще нічого не знали про цикли і не вміли їх використовувати, то час польоту м’ячика становив всього лише 5 секунд.

Використовуючи наступну програму, змініть її так, щоб м’ячик падав рівно ту кількість секунд, яка необхідна йому для досягнення землі.

constants.h:
```
#ifndef CONSTANTS_H
#define CONSTANTS_H
namespace  myConstants
{
const  double  gravity(9.8);
}
#endif
```
Основний файл:
```
#include <iostream>
#include "constants.h"
// Отримуємо початкову висоту від користувача і повертаємо її
double  getInitialHeight()
{
std::cout  <<  "Enter the height of the tower in meters: ";
double  initialHeight;
std::cin  >>  initialHeight;
return  initialHeight;
}
// Повертаємо відстань від землі після "..." секунд падіння
double  calculateHeight(double  initialHeight,  int  seconds)
{
// Використовуємо формулу: [ s = u * t + (a * t^2) / 2 ], де u(початкова швидкість) = 0
double  distanceFallen  =  (myConstants::gravity *  seconds *  seconds)  /  2;
double  currentHeight  =  initialHeight  -  distanceFallen;
return  currentHeight;
}
// Виводимо висоту, на якій знаходиться м'ячик після кожної секунди падіння
void  printHeight(double  height,  int  seconds)
{
if  (height  >  0.0)
{
std::cout  <<  "At "  <<  seconds  <<  " seconds, the ball is at height:\t"  <<  height  <<
" meters\n";
}
else
std::cout  <<  "At "  <<  seconds  <<  " seconds, the ball is on the ground.\n";
}
void  calculateAndPrintHeight(double  initialHeight,  int  seconds)
{
double  height  =  calculateHeight(initialHeight,  seconds);
printHeight(height,  seconds);
}
int  main()
{
const  double  initialHeight  =  getInitialHeight();
calculateAndPrintHeight(initialHeight,  0);
calculateAndPrintHeight(initialHeight,  1);
calculateAndPrintHeight(initialHeight,  2);
calculateAndPrintHeight(initialHeight,  3);
calculateAndPrintHeight(initialHeight,  4);
calculateAndPrintHeight(initialHeight,  5);
return  0;
}
```

### Завдання №2

Напишіть програму-гру типу  _Hi-Lo_:

По-перше, ваша програма повинна вибрати рандомне ціле число в діапазоні від 1 до 100.

Користувачеві дається 7 спроб, щоб вгадати це число.

Якщо користувач не вгадав число, то програма повинна підказувати, чи було його припущення занадто великим чи занадто маленьким.

Якщо користувач вгадав число, то програма повинна повідомити, що все вірно — ви виграли!

Якщо ж у користувача закінчилися спроби, і він не вгадав число, то програма повинна повідомити йому, що він програв і показати правильний результат.

В кінці гри програма повинна запитати у користувача, чи не хоче він зіграти ще раз.

Якщо користувач не ввів ні  `y`  (від англ.  _“**y**es”_), ні  `n`  (від англ.  _“**n**o”_), то програма повинна запитати його ще раз.

Приклад результату виконання програми:

```
Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.  
Guess #1: 64  
Your guess is too high.  
Guess #2: 32  
Your guess is too low.  
Guess #3: 54  
Your guess is too high.  
Guess #4: 51  
Correct! You win!  
Would you like to play again (y/n)? y  
Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.  
Guess #1: 64  
Your guess is too high.  
Guess #2: 32  
Your guess is too low.  
Guess #3: 54  
Your guess is too high.  
Guess #4: 51  
Your guess is too high.  
Guess #5: 36  
Your guess is too low.  
Guess #6: 45  
Your guess is too low.  
Guess #7: 48  
Your guess is too low.  
Sorry, you lose. The correct number was 49.  
Would you like to play again (y/n)? q  
Would you like to play again (y/n)? f  
Would you like to play again (y/n)? n  
Thank you for playing.
```

**_Підказки_:**

Використовуйте виклик функції  `time(0)`  в якості стартового числа під час генерації випадкових чисел.

**_Користувачам Visual Studio_**: Через погану реалізацію функції rand() (перше рандомне число не дуже відрізняється від стартового) — викличте rand() відразу після установки стартового числа, щоб скинути перший результат.

Використовуйте функцію getRandomNumber() з  [**уроку №74**](https://acode.com.ua/urok-74-generatsiya-randomnyh-chysel/#toc-3)  для генерації рандомного числа.

У функції, яка запитуватиме у користувача, чи не хоче він зіграти ще раз, використовуйте механізм обробки некоректного користувацького вводу.
