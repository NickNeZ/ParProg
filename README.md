1) Первая лабораторная:
Была написана программа выполняющая перемножение массива из 4х чисел размером 32 бита при помощи SSE инструкций. Так же была написана программа выполняющая эти действия последовательно. В результате сравнения производительности было выявлено, что программа использующая SSE инструкции выполняется в разы быстрее той (примерно в 7 раз), что делает перемножение последовательно. В сгенерированном коде ассемблера можно видеть что, операции, которые прописаны с помощью SSE были вставлены в код ассемблера.

2) Вторая лабораторная:
Была написана программа, которая используется pthreads, создавая многопоточное вычисление сложной задачи. Так же была написана программа, выполняющая вычисление сложной задачи последовательно. При сравнении производительности выяснилось что программа, использующая Pthreads, выполняется быстрее (примерно в 10 раз), чем та, что делает это последовательно.
