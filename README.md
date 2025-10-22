# Quiz
## 1. Jak włączyć program?
Aby włączyć program, w terminalu w katalogu `quiz` należy wpisać następującą komendę: 

>g++ code/main.cpp code/quiz_class/algorithm.cpp code/quiz_class/build.cpp code/basic.cpp -o quiz.out && ./quiz.out

## 2. Jak stworzyć swój własny zestaw pytań?
W pliku z zestawami pytań muszą być zamieszczone pytania i odpowiedzi w formacie:
>Ile żołądków mają delfiny? -2

Aby wstawić komentarz, należy umieścić poprzedzający go znak `//`. 
>Ile żołądków mają delfiny? -2  *//Tu jest komentarz!*

Aby stworyć odpowiedź, która składa się z wielu słów w obojętnej kolejności, na początku linii należy umieścić '/K'.
>K/ Ile żołądków mają delfiny? -2, 3, 4

Po stworzeniu pliku z zestawem pytań, należy umieścić go w katalogu `quiz` oraz wpisać jego nazwę do pliku `source.txt`.

## 3. Personalizacja 
W pierwszym wierszu pliku można zamieścić linię, która określa sposób sprawdzania poprawności odpowiedzi.
Linia ta powinna składać się z trzech wartości logicznych określanych symbolami `0` (fałsz) oraz `1` (prawda), np.:
>1 0 1

Wartości te określają prawdziwość kolejnych stwierdzeń:
1. Przy sprawdzaniu zwróć uwagę na **znaki białe**.
2. Przy sprawdzaniu zwróć uwagę na **wielkie litery**.
3. Przy sprawdzaniu zwróć uwagę na **literówki**.

W przypadku nieumieszczenia tych wartości w pliku, program domyślnie przyjmie każde z tych twierdzeń za fałszywe.

### Znaki białe
Do znaków białych zaliczają się: znak nowej linii, klawisz Tab oraz spacja.

### Literówki
Literówka w odpowiedzi następuje kiedy:
- znak znajduje się w nieodpowiednim miejscu, np.:
>opdowiedź

Ten rodzaj literówki w przypadku określeniu wartości logicznej na fałsz jest dozwolony dowolną ilość razy.

-  znak występuje w szablonie w zupełnie innym miejscu lub w ogóle w nim nie występuje, np.:
>odpowxedź

Ten rodzaj literówki jest domyślnie dozwolony jedynie jeden raz w całej odpowiedzi na pytanie.

Niezależnie od podanych wartości logicznych w pliku z pytaniami, program nigdy nie zezwala na popełnianie literówek w odpowiedziach, w których znajduje się liczba (np. w datach).

## 3. Dodatkowe informacje
- Program działa tylko na urządzeniach z systemem Linux.
- W przypadku pomyłki, wpisanie znaku `.` anuluje utratę punktów.
- Aby wyjść z programu, w odpowiedzi na pytanie należy wpisać `e` (exit).
