# C_string
В этом проекте я реализую библиотеку string.h с дополнениями на языке С

Мной были реализованы функции string.h и sprintf. Все функции покрыты unit тестами. Тесты запускаются через Makefile.Тестировать библиотеку можено с помощью Docker, для этого я написал Dockerfile и скрипт, который собирает изображение и запускает контейнер. Контейнер создается на базе Ubuntu 

## Руководство по использованию

### Для сборки библиотеки и исполняемого файла тестов, а так же формирования отчета о покрытии кода используй следующие команды:

```make all```

### Для создания статической библиотеки:

```make s21_string.a```

### Для запуска тестов:

```make test```

### Для запуска тестов в docker:

```make test_docker```

### Для запуска тестов и проверки утечек памяти:

```make leaks```

### Для отчистки проекта от всех временных и промежуточных файлов:

```make clean```

### Для удаления статической библиотеки:

```make clean_lib```

### Для начиная с удаления старых файлов и создания новой версии библиотеки и запуска тестов:

```make rebuild```

### Для создания отчета о покрытии кода:

```make gcov_report```

### Для проверки стиля кода:

```make style```

### Для применения стиля форматирования Google к коду:

```make format```


### Функции string.h

| № | Функция | Описание |
| ------ | ------ | ------ |
| 1 | void *memchr(const void *str, int c, size_t n) | Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n байтах строки, на которую указывает аргумент str. |
| 2 | int memcmp(const void *str1, const void *str2, size_t n) | Сравнивает первые n байтов str1 и str2. |
| 3 | void *memcpy(void *dest, const void *src, size_t n) | Копирует n символов из src в dest. |
| 4 | void *memset(void *str, int c, size_t n) | Копирует символ c (беззнаковый тип) в первые n символов строки, на которую указывает аргумент str. |
| 5 | char *strncat(char *dest, const char *src, size_t n) | Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest, длиной до n символов. |
| 6	| char *strchr(const char *str, int c) | Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str. |
| 7 | int strncmp(const char *str1, const char *str2, size_t n) | Сравнивает не более первых n байтов str1 и str2. |
| 8 | char *strncpy(char *dest, const char *src, size_t n) | Копирует до n символов из строки, на которую указывает src, в dest. |
| 9 | size_t strcspn(const char *str1, const char *str2) | Вычисляет длину начального сегмента str1, который полностью состоит из символов, не входящих в str2. |
| 10 | char *strerror(int errnum) | Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает указатель на строку с сообщением об ошибке. Нужно объявить макросы, содержащие массивы сообщений об ошибке для операционных систем mac и linux. Описания ошибок есть в оригинальной библиотеке. Проверка текущей ОС осуществляется с помощью директив.|
| 11 | size_t strlen(const char *str) | Вычисляет длину строки str, не включая завершающий нулевой символ. |
| 12 | char *strpbrk(const char *str1, const char *str2) | Находит первый символ в строке str1, который соответствует любому символу, указанному в str2. |
| 13 | char *strrchr(const char *str, int c) | Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str. |
| 14 | char *strstr(const char *haystack, const char *needle) | Находит первое вхождение всей строки needle (не включая завершающий нулевой символ), которая появляется в строке haystack. |
| 15 | char *strtok(char *str, const char *delim) | Разбивает строку str на ряд токенов, разделенных delim. |
| 16 | void *to_upper(const char *str) | Возвращает копию строки (str), преобразованной в верхний регистр. В случае какой-либо ошибки следует вернуть значение NULL |
| 17 | void *to_lower(const char *str) | Возвращает копию строки (str), преобразованной в нижний регистр. В случае какой-либо ошибки следует вернуть значение NULL |
| 18 | void *insert(const char *src, const char *str, size_t start_index) | Возвращает новую строку, в которой указанная строка (str) вставлена в указанную позицию (start_index) в данной строке (src). В случае какой-либо ошибки следует вернуть значение NULL |
| 19 | void *trim(const char *src, const char *trim_chars) | Возвращает новую строку, в которой удаляются все начальные и конечные вхождения набора заданных символов (trim_chars) из данной строки (src). В случае какой-либо ошибки следует вернуть значение NULL |

### Sprintf

- int sprintf(char *str, const char *format, ...) - отправляет форматированный вывод в строку, на которую указывает str.

где:
- str − Это С-строка, которую функция обрабатывает в качестве источника для извлечения данных;
- format −  это С-строка, содержащая один или несколько следующих элементов: пробельный символ, непробельный символ и спецификаторы формата. Спецификатор формата для печатающих функций следует прототипу: %[флаги][ширина][.точность][длина]спецификатор. Спецификатор формата для сканирующих функций следует прототипу: %[*][ширина][длина]спецификатор.

### sprintf Спецификаторы

| № | Спецификатор | Результат sprintf |
| --- | --- | --- |
| 1 | c | Символ |
| 2 | d | Знаковое десятичное целое число |
| 3 | i | Знаковое десятичное целое число | 
| 4 | e | Научная нотация (мантисса/экспонента) с использованием символа e (вывод чисел должен совпадать с точностью до e-6) | 
| 5 | E | Научная нотация (мантисса/экспонента) с использованием символа Е |
| 6 | f | Десятичное число с плавающей точкой |
| 7 | g | Использует кратчайший из представлений десятичного числа | 
| 8 | G | Использует кратчайший из представлений десятичного числа | 
| 9 | o | Беззнаковое восьмеричное число |
| 10 | s | Строка символов |
| 11 | u | Беззнаковое десятичное целое число |
| 12 | x | Беззнаковое шестнадцатеричное целое число |
| 13 | X | Беззнаковое шестнадцатеричное целое число (заглавные буквы) |
| 14 | p | Адрес указателя |
| 15 | n | Количество символов, напечатанных до появления %n |
| 16 | % | Символ % |

### sprintf Флаги

| № | Флаг | Описание |
| --- | --- | --- |
| 1 | - | Выравнивание по левому краю в пределах заданной ширины поля. Выравнивание по правому краю используется по умолчанию (см. подспецификатор ширины). |
| 2 | + | Заставляет явно указывать знак плюс или минус (+ или -) даже для положительных чисел. По умолчанию только отрицательным числам предшествует знак "-". |
| 3 | (пробел) | Если знак не будет выведен, перед значением вставляется пробел. |
| 4 | # | При использовании со спецификаторами o, x или X перед числом вставляется 0, 0x или 0X соответственно (для значений, отличных от нуля). При использовании с e, E и f "заставляет" записанный вывод содержать десятичную точку, даже если за ней не последует никаких цифр. По умолчанию, если не следует никаких цифр, десятичная точка не записывается. При использовании с g или G результат такой же, как и с e или E, но конечные нули не удаляются. |
| 5 | 0 | Заполняет число слева нулями (0) вместо пробелов, где указан спецификатор ширины (см. подспецификатор ширины). |

### sprintf Ширина

| № | Ширина | Описание |
| --- | --- | --- |
| 1	| (число) | Минимальное количество печатаемых символов. Если выводимое значение короче этого числа, результат дополняется пробелами. Значение не усекается, даже если результат больше. |
| 2 | * | В sprintf знак * значит, что ширина указывается не в строке формата, а в качестве дополнительного аргумента целочисленного значения, предшествующего аргументу, который необходимо отформатировать. В sscanf знак *, помещенный после % и перед спецификатором формата, считывает данные указанного типа, но подавляет их присваивание. |

### sprintf Точность

| № | .точность | Описание |
| --- | --- | --- |
| 1	| .число | Для целочисленных спецификаторов (d, i, o, u, x, X) − точность определяет минимальное количество записываемых цифр. Если записываемое значение короче этого числа, результат дополняется ведущими нулями. Значение не усекается, даже если результат длиннее. Точность 0 означает, что для значения 0 не записывается ни одного символа. Для спецификаторов e, E и f − это количество цифр, которые должны быть напечатаны после десятичной точки. Для спецификаторов g и G − это максимальное количество значащих цифр, которые должны быть напечатаны. Для s − это максимальное количество печатаемых символов. По умолчанию все символы печатаются до тех пор, пока не встретится терминирующий нуль. Для типа с − никак не влияет. Если точность не указана для спецификаторов e, E, f, g и G, то по умолчанию ее значение равно 6. Если точность не указана для остальных спецификаторов, то по умолчанию ее значение равно 1. Если число не указано (нет явного значения точности), то по умолчанию - 0. |
| 2	| .* | Точность указывается не в строке формата, а в качестве дополнительного аргумента целочисленного значения, предшествующего аргументу, который должен быть отформатирован. |

### sprintf Длина

| № | Длина | Описание |
| --- | --- | --- |
| 1 | h | Аргумент интерпретируется как короткое int или короткое int без знака (применяется только к целочисленным спецификаторам: i, d, o, u, x и X). |
| 2 | l | Аргумент интерпретируется как длинное int или длинное int без знака для целочисленных спецификаторов (i, d, o, u, x и X) и как широкий символ или строка широких символов для спецификаторов c и s. |
| 3 | L | Аргумент интерпретируется как длинный double (применяется только к спецификаторам с плавающей точкой − e, E, f, g и G). |