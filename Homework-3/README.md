**Задача 1.** Професор Х се забавлява като съставя интересни числови редици. Последното му творчество е следната редица:

1, 121, 1213121, 121312141213121, …

Първият член на редицата е 1. Всеки от следващите членове се получава от две копия на предходния член на редицата, между които е изписан поредният номер на текущия член. Тъй като дължината на числата в редицата нараства много бързо и ръчното им изписване е доста трудоемко, професорът се нуждае от програма, която да извежда посочения от него член на тази редица. Помогнете му като напишете програма, която по въведено цяло положително число n < 20 извежда n-тия член на редицата, следван от знак за нов ред.

Пример:
Вход	Изход
5	1213121412131215121312141213121


**Задача 2.** Да се напише програма, която по въведено естествено число number ≤ 32 намира всички възможни “разбивания” на number като сума от естествени числа и извежда само уникалните такива представяния, като числата от всяко представяне са подредени в намаляваща редица, т.е. за всяко разбиване {number = x1 + x2 + x3 + … + xn} е в сила x1 ≥ x2 ≥ x3 ≥ … ≥ xn. Всяко разбиване трябва да бъде изведено във формата {number = x1 + x2 + x3 + … + xn} без къдравите скоби, където x1, …, xn са елементите на поредното разбиване на number. Подредете разбиванията лексикографски спрямо елементите им, започвайки от най-голямото, както е показано в примера по-долу. След всяко разбиване, включително и последното, да има знак за нов ред.

Пример:
Вход	Изход
5	5 = 5
5 = 4 + 1
5 = 3 + 2
5 = 3 + 1 + 1
5 = 2 + 2 + 1
5 = 2 + 1 + 1 + 1
5 = 1 + 1 + 1 + 1 + 1
