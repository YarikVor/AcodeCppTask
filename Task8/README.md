
### Завдання №2

Напишіть деструктор для наступного класу:

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

19

20

21

22

23

24

25

26

27

28

29

30

31

32

33

34

35

#include <iostream>

class  Welcome

{

private:

char  *m_data;

public:

Welcome()

{

m_data  =  new  char[14];

const  char  *init  =  "Hello, World!";

for  (int  i  =  0;  i  <  14;  ++i)

m_data[i]  =  init[i];

}

~Welcome()

{

// Реалізація деструктора

}

void  print()  const

{

std::cout  <<  m_data;

}

};

int  main()

{

Welcome hello;

hello.print();

return  0;

}

**Відповідь №2**

### Завдання №3

Давайте створимо генератор випадкових монстрів.

a) Спочатку створіть перерахування MonsterType з наступними типами монстрів:  `Dragon`,  `Goblin`,  `Ogre`,  `Orc`,  `Skeleton`,  `Troll`,  `Vampire`  і `Zombie`  + додайте  `MAX_MONSTER_TYPES`, щоб мати можливість підрахувати загальну кількість всіх енумераторів.

**Відповідь №3.а)**

b) Тепер створіть клас Monster з наступними трьома атрибутами (змінними-членами): тип (MonsterType), ім’я (std::string) і кількість здоров’я (int).

**Відповідь №3.b)**

c) Перерахування MonsterType є специфічним для Monster, тому перемістіть його всередину класу під специфікатор доступу public.

**Відповідь №3.c)**

d) Створіть конструктор, який дозволить ініціалізувати всі змінні-члени класу.

Наступний фрагмент коду повинен скомпілюватися без помилок:

1

2

3

4

5

6

int  main()

{

Monster jack(Monster::Orc,  "Jack",  90);

return  0;

}

**Відповідь №3.d)**

e) Тепер нам потрібно вивести інформацію про нашого монстра. Для цього потрібно конвертувати MonsterType в std::string. Додайте функцію getTypeString(), яка виконуватиме конвертацію, і функцію виводу print().

Наступна програма:

1

2

3

4

5

6

7

int  main()

{

Monster jack(Monster::Orc,  "Jack",  90);

jack.print();

return  0;

}

Повинна видавати наступний результат:

`Jack is the orc that has 90 health points.`

**Відповідь №3.e)**

f) Тепер ми вже можемо створити сам генератор монстрів. Для цього створіть статичний клас MonsterGenerator і статичний метод з ім’ям generateMonster(), який повертатиме випадкового монстра. Поки що метод нехай повертає анонімний об’єкт:  `(Monster::Orc, "Jack", 90)`.

Наступна програма:

1

2

3

4

5

6

7

int  main()

{

Monster  m  =  MonsterGenerator::generateMonster();

m.print();

return  0;

}

Повинна видавати наступний результат:

`Jack is the orc that has 90 health points.`

**Відповідь №3.f)**

g) Тепер MonsterGenerator повинен генерувати деякі випадкові атрибути. Для цього нам знадобиться генератор випадкового числа. Скористайтеся наступною функцією:

1

2

3

4

5

6

7

8

// Генеруємо випадкове число між min і max (включно).

// Припускається, що srand() уже викликали

int  getRandomNumber(int  min,  int  max)

{

static  const  double  fraction  =  1.0  /  (static_cast<double>(RAND_MAX)  +  1.0);

// Рівномірно розподіляємо рандомне число в нашому діапазоні

return  static_cast<int>(rand()  *  fraction  *  (max  -  min  +  1)  +  min);

}

Оскільки MonsterGenerator покладатиметься безпосередньо на цю функцію, то помістіть її всередину класу в якості статичного методу.

**Відповідь №3.g)**

h) Тепер змініть функцію generateMonster() для генерації випадкового MonsterType (між  `0`  і  `Monster::MAX_MONSTER_TYPES-1`) і випадкової кількості здоров’я (від 1 до 100). Це має бути просто. Після того, як ви це зробите, визначте один статичний фіксований масив  `s_names`  розміром 6 елементів всередині функції generateMonster() і ініціалізуйте його шістьма будь-якими іменами на ваш вибір. Додайте можливість вибору випадкового імені з цього масиву.

Наступний фрагмент коду повинен скомпілюватися без помилок:

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

#include <ctime> // для time()

#include <cstdlib> // для rand() і srand()

int  main()

{

srand(static_cast<unsigned  int>(time(0)));  // використовуємо системний годинник в якості стартового значення

rand();  // користувачам Visual Studio: скидаємо перше згенероване (рандомне) число

Monster  m  =  MonsterGenerator::generateMonster();

m.print();

return  0;

}

**Відповідь №3.h)**

i) Чому ми оголосили масив  `s_names`  статичним?

**Відповідь №3.i)**

### Завдання №4

Настав час для нашого і вашого улюбленого завдання “Blackjack”. На цей раз ми перепишемо гру “Blackjack”, яку написали раніше в  [**підсумковому тесті розділу №6**](https://acode.com.ua/rozdil-6-pidsumkovyj-test/), але вже з використанням класів! Ось повний код без класів:

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

19

20

21

22

23

24

25

26

27

28

29

30

31

32

33

34

35

36

37

38

39

40

41

42

43

44

45

46

47

48

49

50

51

52

53

54

55

56

57

58

59

60

61

62

63

64

65

66

67

68

69

70

71

72

73

74

75

76

77

78

79

80

81

82

83

84

85

86

87

88

89

90

91

92

93

94

95

96

97

98

99

100

101

102

103

104

105

106

107

108

109

110

111

112

113

114

115

116

117

118

119

120

121

122

123

124

125

126

127

128

129

130

131

132

133

134

135

136

137

138

139

140

141

142

143

144

145

146

147

148

149

150

151

152

153

154

155

156

157

158

159

160

161

162

163

164

165

166

167

168

169

170

171

172

173

174

175

176

177

178

179

180

181

182

183

184

185

186

187

188

189

190

191

192

193

194

195

196

197

198

199

200

201

202

203

204

205

206

207

208

209

#include <iostream>

#include <array>

#include <ctime> // для time()

#include <cstdlib> // для rand() і srand()

enum  CardSuit

{

SUIT_CLUB,

SUIT_DIAMOND,

SUIT_HEART,

SUIT_SPADE,

MAX_SUITS

};

enum  CardRank

{

RANK_2,

RANK_3,

RANK_4,

RANK_5,

RANK_6,

RANK_7,

RANK_8,

RANK_9,

RANK_10,

RANK_JACK,

RANK_QUEEN,

RANK_KING,

RANK_ACE,

MAX_RANKS

};

struct  Card

{

CardRank rank;

CardSuit suit;

};

void  printCard(const  Card  &card)

{

switch  (card.rank)

{

case  RANK_2:  std::cout  <<  '2';  break;

case  RANK_3:  std::cout  <<  '3';  break;

case  RANK_4:  std::cout  <<  '4';  break;

case  RANK_5:  std::cout  <<  '5';  break;

case  RANK_6:  std::cout  <<  '6';  break;

case  RANK_7:  std::cout  <<  '7';  break;

case  RANK_8:  std::cout  <<  '8';  break;

case  RANK_9:  std::cout  <<  '9';  break;

case  RANK_10:  std::cout  <<  'T';  break;

case  RANK_JACK:  std::cout  <<  'J';  break;

case  RANK_QUEEN:  std::cout  <<  'Q';  break;

case  RANK_KING:  std::cout  <<  'K';  break;

case  RANK_ACE:  std::cout  <<  'A';  break;

}

switch  (card.suit)

{

case  SUIT_CLUB:  std::cout  <<  'C';  break;

case  SUIT_DIAMOND:  std::cout  <<  'D';  break;

case  SUIT_HEART:  std::cout  <<  'H';  break;

case  SUIT_SPADE:  std::cout  <<  'S';  break;

}

}

void  printDeck(const  std::array<Card,  52>  deck)

{

for  (const  auto  &card :  deck)

{

printCard(card);

std::cout  <<  ' ';

}

std::cout  <<  '\n';

}

void  swapCard(Card  &a,  Card  &b)

{

Card temp  =  a;

a  =  b;

b  =  temp;

}

// Генеруємо випадкове число між min і max (включно).

// Припускається, що srand() вже викликали

int  getRandomNumber(int  min,  int  max)

{

static  const  double  fraction  =  1.0  /  (static_cast<double>(RAND_MAX)  +  1.0);

// Рівномірно розподіляємо рандомне число в нашому діапазоні

return  static_cast<int>(rand()  *  fraction  *  (max  -  min  +  1)  +  min);

}

void  shuffleDeck(std::array<Card,  52>  &deck)

{

// Перебираємо кожну карту в колоді

for  (int  index  =  0;  index  <  52;  ++index)

{

// Вибираємо будь-яку випадкову карту

int  swapIndex  =  getRandomNumber(0,  51);

// Міняємо місцями з нашою поточною картою

swapCard(deck[index],  deck[swapIndex]);

}

}

int  getCardValue(const  Card  &card)

{

switch  (card.rank)

{

case  RANK_2:  return  2;

case  RANK_3:  return  3;

case  RANK_4:  return  4;

case  RANK_5:  return  5;

case  RANK_6:  return  6;

case  RANK_7:  return  7;

case  RANK_8:  return  8;

case  RANK_9:  return  9;

case  RANK_10:  return  10;

case  RANK_JACK:  return  10;

case  RANK_QUEEN:  return  10;

case  RANK_KING:  return  10;

case  RANK_ACE:  return  11;

}

return  0;

}

char  getPlayerChoice()

{

std::cout  <<  "(h) to hit, or (s) to stand: ";

char  choice;

do

{

std::cin  >>  choice;

}  while  (choice  !=  'h'  &&  choice  !=  's');

return  choice;

}

bool  playBlackjack(const  std::array<Card,  52>  deck)

{

const  Card  *cardPtr  =  &deck[0];

int  playerTotal  =  0;

int  dealerTotal  =  0;

// Дилер отримує одну карту

dealerTotal  +=  getCardValue(*cardPtr++);

std::cout  <<  "The dealer is showing: "  <<  dealerTotal  <<  '\n';

// Гравець отримує дві карти

playerTotal  +=  getCardValue(*cardPtr++);

playerTotal  +=  getCardValue(*cardPtr++);

// Гравець починає

while  (1)

{

std::cout  <<  "You have: "  <<  playerTotal  <<  '\n';

char  choice  =  getPlayerChoice();

if  (choice  ==  's')

break;

playerTotal  +=  getCardValue(*cardPtr++);

// Дивимося, чи гравець не програв

if  (playerTotal  >  21)

return  false;

}

// Якщо гравець не програв (у нього не більше 21 очка), тоді дилер отримує карти до тих пір, поки у нього в підсумку буде не менше 17 очків

while  (dealerTotal  <  17)

{

dealerTotal  +=  getCardValue(*cardPtr++);

std::cout  <<  "The dealer now has: "  <<  dealerTotal  <<  '\n';

}

// Якщо у дилера більше 21 очка, то він програв, а гравець виграв

if  (dealerTotal  >  21)

return  true;

return  (playerTotal  >  dealerTotal);

}

int  main()

{

srand(static_cast<unsigned  int>(time(0)));  // використовуємо системний годинник в якості стартового значення

rand();  // користувачам Visual Studio: скидаємо перше згенероване (випадкове) число

std::array<Card,  52>  deck;

// Звичайно, можна було б ініціалізувати кожну карту окремо, але навіщо? Адже є цикли!

int  card  =  0;

for  (int  suit  =  0;  suit  <  MAX_SUITS;  ++suit)

for  (int  rank  =  0;  rank  <  MAX_RANKS;  ++rank)

{

deck[card].suit  =  static_cast<CardSuit>(suit);

deck[card].rank  =  static_cast<CardRank>(rank);

++card;

}

shuffleDeck(deck);

if  (playBlackjack(deck))

std::cout  <<  "You win!\n";

else

std::cout  <<  "You lose!\n";

return  0;

}

Непогано, правда? З чого ж починати? Для початку нам потрібна стратегія. Програма “Blackjack” складається з 4 частин:

Логіка роботи з картами.

Логіка роботи з колодами карт.

Логіка роздачі карт з колоди.

Логіка гри.

Наша стратегія полягає в тому, щоб працювати над кожною з цих частин індивідуально. Таким чином, замість конвертації цілої програми за раз, ми зробимо це спокійно за 4 кроки.

Скопіюйте вищенаведений код в вашу IDE, а потім закоментуйте все, крім рядків, що містять #include.

a) Почнемо з того, що переробимо Card зі структури в клас. Доброю новиною є те, що клас Card дуже схожий на клас Monster з попереднього завдання. Алгоритм дій наступний:

По-перше, перемістіть перерахування CardSuit і CardRank всередину класу Card під специфікатор доступу public (вони невід’ємно пов’язані з Card, тому повинні перебувати всередині класу).

По-друге, створіть закриті змінні-члени  `m_rank`  і `m_suit`  для зберігання значень CardRank і CardSuit.

По-третє, створіть відкритий конструктор класу Card з ініціалізацією карт (змінних-членів класу). Вкажіть параметри за замовчуванням для конструктора (використовуйте  `MAX_RANKS`  і `MAX_SUITS`).

Нарешті, перемістіть функції printCard() і getCardValue() всередину класу під специфікатор доступу public (не забудьте зробити їх const!).

**_Примітка_:**  При використанні std::array (або std::vector), де елементами є об’єкти класу, клас повинен мати конструктор за замовчуванням, щоб елементи могли бути ініціалізовані розумними значеннями за замовчуванням. Якщо ви цього не зробите, то отримаєте помилку спроби посилатися на видалену функцію.

Наступний фрагмент коду повинен скомпілюватися без помилок:

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

#include <iostream>

int  main()

{

const  Card cardQueenHearts(Card::RANK_QUEEN,  Card::SUIT_HEART);

cardQueenHearts.printCard();

std::cout  <<  " has the value "  <<  cardQueenHearts.getCardValue()  <<  '\n';

return  0;

}

**Відповідь №4.а)**

b) Добре, тепер давайте працювати над класом Deck:

По-перше, в Deck має бути 52 карти, тому створіть private-член  `m_deck`, який буде фіксованим масивом з 52-ма елементами (використовуйте std::array).

По-друге, створіть конструктор, який не приймає ніяких параметрів і ініціалізує кожен елемент масиву  `m_deck`  випадковою картою (використовуйте код з функції main() з циклами for з вищенаведеного прикладу, де присутній повний код). Всередині циклів створіть анонімний об’єкт Card і присвоюйте його кожному елементу масиву  `m_deck`.

По-третє, перемістіть функцію printDeck() в клас Deck під специфікатор доступу public (не забудьте про const).

По-четверте, перемістіть функції getRandomNumber() і swapCard() в клас Deck в якості закритих статичних членів.

По-п’яте, перемістіть функцію shuffleDeck() в клас в якості відкритого члена.

**_Підказка_:** Найскладнішою частиною тут є ініціалізація колоди карт з використанням модифікованого коду з вихідної функції main(). У наступному рядку показується, як це зробити:

1

m_deck[card]  =  Card(static_cast<Card::CardRank>(rank),  static_cast<Card::CardSuit>(suit));

Наступний фрагмент коду повинен скомпілюватися без помилок:

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

#include <iostream>

#include <ctime> // для time()

#include <cstdlib> // для rand() і srand()

int  main()

{

srand(static_cast<unsigned  int>(time(0)));  // використовуємо системний годинник в якості стартового значення

rand();  // користувачам Visual Studio: скидаємо перше згенероване (рандомне) число

Deck deck;

deck.printDeck();

deck.shuffleDeck();

deck.printDeck();

return  0;

}

**Відповідь №4.b)**

c) Тепер нам потрібен спосіб відстежити, яка карта роздаватиметься наступною (у вихідній програмі для цього використовується  `cardptr`):

По-перше, додайте в клас Deck цілочисельний член  `m_cardIndex`  і ініціалізуйте його значенням  `0`.

По-друге, створіть відкритий метод dealCard(), який повертатиме константне посилання на поточну карту і збільшуватиме  `m_cardIndex`.

По-третє, метод shuffleDeck() також повинен бути оновлений для скидання  `m_cardIndex`  (тому що після перетасовки колоди роздається верхня карта).

Наступний фрагмент коду повинен скомпілюватися без помилок:

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

int  main()

{

srand(static_cast<unsigned  int>(time(0)));  // використовуємо системний годинник в якості стартового значення

rand();  // користувачам Visual Studio: скидаємо перше згенероване (рандомне) число

Deck deck;

deck.shuffleDeck();

deck.printDeck();

std::cout  <<  "The first card has value: "  <<  deck.dealCard().getCardValue()  <<  '\n';

std::cout  <<  "The second card has value: "  <<  deck.dealCard().getCardValue()  <<  '\n';

return  0;

}

**Відповідь №4.c)**

d) Майже готово! Тепер трохи самостійності:

Додайте в програму функції getPlayerChoice() і playBlackjack().

Змініть функцію playBlackjack() у відповідність з уже наявними класом і методами.

Видаліть зайве і додайте потрібне в функцію main() (див. повний код вище).

**Відповідь №4.d)**

Ура!