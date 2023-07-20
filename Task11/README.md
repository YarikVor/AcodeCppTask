
### Завдання №2

a) Створіть класи Apple і Banana, які наслідують клас Fruit. У класі Fruit є дві змінні-члени:  `name`  і `color`.

Наступний код:

1

2

3

4

5

6

7

8

9

10

int  main()

{

Apple  a("red");

Banana  b;

std::cout  <<  "My "  <<  a.getName()  <<  " is "  <<  a.getColor()  <<  ".\n";

std::cout  <<  "My "  <<  b.getName()  <<  " is "  <<  b.getColor()  <<  ".\n";

return  0;

}

Повинен видавати наступний результат:

`My apple is red.  
My banana is yellow.`

**Відповідь №2.a)**

b) Додайте новий клас GrannySmith, який наслідує клас Apple.

Наступний код:

1

2

3

4

5

6

7

8

9

10

11

12

int  main()

{

Apple  a("red");

Banana  b;

GrannySmith  c;

std::cout  <<  "My "  <<  a.getName()  <<  " is "  <<  a.getColor()  <<  ".\n";

std::cout  <<  "My "  <<  b.getName()  <<  " is "  <<  b.getColor()  <<  ".\n";

std::cout  <<  "My "  <<  c.getName()  <<  " is "  <<  c.getColor()  <<  ".\n";

return  0;

}

Повинен видавати наступний результат:

`My apple is red.  
My banana is yellow.  
My Granny Smith apple is green.`

**Відповідь №2.b)**

### Завдання №3

Найулюбленіше! Будемо створювати просту гру, в якій ви будете битися з монстрами. Ціль гри — зібрати максимум золота, перш ніж ви помрете або досягнете 20 рівня.

Гра складається з трьох класів: Creature, Player і Monster. Player і Monster наслідують клас Creature.

a) Спочатку створіть клас Creature з наступними членами:

ім’я (std::string);

символ (char);

кількість здоров’я (int);

кількість ушкодження, яке він наносить ворогу під час атаки (int);

кількість золота, яке він має (int).

Створіть повний набір геттерів (по одному на кожну змінну-член класу). Додайте ще три методи:

void reduceHealth(int) — зменшує здоров’я Creature на вказане цілочисельне значення;

bool isDead() — повертає  `true`, якщо здоров’я Creature дорівнює  `0`  або менше;

void addGold(int) — додає золото Creature-у.

Наступний код:

1

2

3

4

5

6

7

8

9

10

11

12

#include <iostream>

#include <string>

int  main()

{

Creature  o("orc",  'o',  4,  2,  10);

o.addGold(5);

o.reduceHealth(1);

std::cout  <<  "The "  <<  o.getName()  <<  " has "  <<  o.getHealth()  <<  " health and is carrying "  <<  o.getGold()  <<  " gold.";

return  0;

}

Повинен видавати наступний результат:

`The orc has 3 health and is carrying 15 gold.`

**Відповідь №3.a)**

b) Тепер нам потрібно створити клас Player, який наслідує Creature. Player має:

змінну-член  `level`, яка починається з  `1`;

ім’я (користувач вводить з клавіатури);

символ  `@`;

10 очків здоров’я;

1 очко ушкодження (для початку);

0 золота.

Напишіть метод levelUp(), який збільшує рівень Player-а і його ушкодження на 1. Також напишіть геттер для члену  `level`  і метод hasWon(), який повертає  `true`, якщо Player досяг 20 рівня.

Додайте в функцію main() код, який запитує у користувача його ім’я і виводить кількість його здоров’я і золота:

`Enter your name: Anton  
Welcome, Anton.  
You have 10 health and are carrying 0 gold.`

**Відповідь №3.b)**

c) Наступний клас Monster також наслідує Creature і у нього немає власних змінних-членів. Але є перерахування Type, яке містить 3 енумератори, вони позначають типи монстрів:  `DRAGON`,  `ORC`  і `SLIME`  (вам також потрібен додатковий енумератор  `MAX_TYPES`).

**Відповідь №3.c)**

d) Кожен тип Монстра має своє ім’я, символ, певну кількість здоров’я, ушкодження і золота:

**Type**

**Name**

**Symbol**

**Health**

**Damage**

**Gold**

DRAGON

dragon

D

20

4

100

ORC

orc

o

4

2

25

SLIME

slime

s

1

1

10

Наступний крок — реалізація конструктора класу Monster, за допомогою якого можна створювати монстрів. Цей конструктор повинен приймати перерахування Type в якості параметру, а потім створювати монстра з відповідними таблиці характеристиками.

Це можна реалізувати по-різному. Однак, оскільки всі наші властивості типів монстрів визначені (не випадково), ми можемо використовувати таблицю пошуку.  **Таблиця пошуку**  — це масив, який містить усі визначені атрибути (властивості) будь-чого. Ми можемо використовувати таблицю пошуку для перегляду характеристик певного типу монстра по мірі необхідності.

Як це зробити? Нам потрібні всього лише дві речі. По-перше, масив з окремим елементом для кожного типу монстра. По-друге, цей елемент міститиме структуру, в якій знаходитимуться всі визначені значення атрибутів для конкретного типу монстра.

_Крок №1:_  Створіть структуру MonsterData всередині класу Monster. Ця структура повинна мати наступні енумератори:  `name`,  `symbol`,  `health`,  `damage`  і `gold`.

_Крок №2:_  Оголосіть статичний масив цієї структури з іменем  `monsterData`.

_Крок №3:_  Додайте код визначення нашої таблиці пошуку поза тілом класу:

1

2

3

4

5

6

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]

{

{  "dragon",  'D',  20,  4,  100  },

{  "orc",  'o',  4,  2,  25  },

{  "slime",  's',  1,  1,  10  }

};

Тепер ми можемо шукати будь-які значення, які нам потрібні! Наприклад, щоб дізнатися кількість золота Dragon, ми можемо використати  `monsterData[DRAGON].gold`.

Використовуйте цю таблицю пошуку для реалізації вашого конструктора:

1

Monster(Type type):  Creature(monsterData[type].name,  ...)

Наступний код:

1

2

3

4

5

6

7

8

#include <iostream>

#include <string>

int  main()

{

Monster  m(Monster::ORC);

std::cout  <<  "A "  <<  m.getName()  <<  " ("  <<  m.getSymbol()  <<  ") was created.\n";

}

Повинен видавати наступний результат:

`A orc (o) was created.`

**Відповідь №3.d)**

e) Нарешті, додайте статичний метод getRandomMonster() в клас Monster. Цей метод повинен генерувати випадкове число від  `0`  до  `MAX_TYPES-1`  і повертати (повернення по значенню) певний тип монстра (вам потрібно використати оператор static_cast для конвертації int в Type, щоб передати його конструктору класу Monster).

Ви можете використовувати наступний код для генерації випадкового числа:

1

2

3

4

5

6

7

8

9

10

#include <cstdlib> // для rand() і srand()

#include <ctime> // для time()

// Генеруємо рандомне число між min і max

int  getRandomNumber(int  min,  int  max)

{

static  const  double  fraction  =  1.0  /  (static_cast<double>(RAND_MAX)  +  1.0);

// Рівномірно розподіляємо рандомне число в нашому діапазоні

return  static_cast<int>(rand()  *  fraction  *  (max  -  min  +  1)  +  min);

}

Наступний код:

1

2

3

4

5

6

7

8

9

10

11

12

13

14

15

16

17

18

#include <iostream>

#include <string>

#include <cstdlib> // для rand() и srand()

#include <ctime> // для time()

int  main()

{

srand(static_cast<unsigned  int>(time(0)));  // встановлюємо значення системного годинника в якості стартового значення

rand();  // скидаємо перший результат

for  (int  i  =  0;  i  <  10;  ++i)

{

Monster  m  =  Monster::getRandomMonster();

std::cout  <<  "A "  <<  m.getName()  <<  " ("  <<  m.getSymbol()  <<  ") was created.\n";

}

return  0;

}

Повинен згенерувати 10 рандомних монстрів:

`A slime (s) was created.  
A orc (o) was created.  
A slime (s) was created.  
A slime (s) was created.  
A orc (o) was created.  
A orc (o) was created.  
A dragon (D) was created.  
A slime (s) was created.  
A orc (o) was created.  
A orc (o) was created.`

**Відповідь №3.e)**

f) Готово, тепер нам потрібно розібратися з логікою нашої гри!

Суть:

Гравець стикається з одним випадково вибраним монстром.

З кожним монстром гравець може або (`R`)un, або (`F`)ight.

Якщо гравець вирішує Run, то шанси на вдалу втечу складають 50%.

Якщо гравцеві вдається втекти, то він благополучно переходить до наступного монстру (його здоров’я/ушкодження/золото при цьому не зменшується).

Якщо гравцеві не вдається втекти, то монстр його атакує. Здоров’я гравця зменшується від ушкодження монстром. Потім гравець вибирає свою наступну дію.

Якщо гравець вибирає Fight, то він атакує монстра. Здоров’я монстра зменшується від ушкодження гравцем.

Якщо монстр вмирає, то гравець забирає все золото монстра + збільшує свій  `level`  і ушкодження на 1.

Якщо монстр не вмирає, то він атакує гравця. Здоров’я гравця зменшується від ушкодження монстром.

Гра закінчується, якщо гравець загинув (програш) або досяг 20 рівня (виграш).

Якщо гравець вмирає, то програма повинна повідомити гравцеві, який рівень у нього був і скільки золота він мав.

Якщо гравець перемагає, то гра повинна повідомити гравцеві, що він виграв і скільки у нього є золота.

Приклад гри:

`Enter your name: Anton  
Welcome, Anton  
You have encountered a orc (o).  
(R)un or (F)ight: r  
You successfully fled.  
You have encountered a slime (s).  
(R)un or (F)ight: f  
You hit the slime for 1 damage.  
You killed the slime.  
You are now level 2.  
You found 10 gold.  
You have encountered a dragon (D).  
(R)un or (F)ight: f  
You hit the dragon for 2 damage.  
The dragon hit you for 4 damage.  
(R)un or (F)ight: f  
You hit the dragon for 2 damage.  
The dragon hit you for 4 damage.  
(R)un or (F)ight: f  
You hit the dragon for 2 damage.  
The dragon hit you for 4 damage.  
You died at level 2 and with 10 gold.  
Too bad you can't take it with you!`

**_Підказка_:**  У вас повинні бути наступні 4 функції:

Функція створення Гравця і основний ігровий цикл (в функції main()).

Функція fightMonster(), яка обробляє бій між Гравцем і Монстром, і запитує у гравця, що він хоче зробити: Run чи Fight.

Функція attackMonster(), яка обробляє атаку монстра гравцем, включаючи збільшення рівня гравця.

Функція attackPlayer(), яка обробляє атаку гравця монстром.