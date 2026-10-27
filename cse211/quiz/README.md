# CSE 211 Lab Quiz (42 tarzı)

Konular: linked list, stack, queue (Chapter 4, 6, 7). 18 egzersiz, 7 seviye.

| Seviye | Egzersiz |
|--------|----------|
| 0 | `ex00_sum_list`, `ex01_nth_from_end` |
| 1 | `ex02_delete_all`, `ex03_stack` |
| 2 | `ex04_balanced`, `ex05_circular_queue` |
| 3 | `ex06_merge_sorted`, `ex07_dlist` |
| 4 (20 Ekim lab sınavı) | `ex08_insert_after_max`, `ex09_remove_not_in`, `ex10_new_minimums` |
| 5 (lab 2 tahmini: stack/queue) | `ex11_stack_reverse`, `ex12_queue_move_to_front`, `ex13_reverse_queue`, `ex14_queue_remove_all` |
| 6 (27 Ekim lab, template stack) | `ex15_sorted_insert`, `ex16_count_unique`, `ex17_stack_palindrome` |

## Nasıl çalışılır

1. `subjects/exNN_*.txt` dosyasını oku.
2. Çözümünü `rendu/exNN_*.cpp` dosyasına yaz (isim aynen subject'teki gibi).
3. Notlandır:

```
./grade.sh ex00     # tek egzersiz
./grade.sh all      # hepsi, sonunda skor
```

## Kurallar

- `main()` yazma, grader'ın kendi `main`'i var.
- Derleme: `g++ -std=c++17 -Wall -Wextra -Werror`. Kullanılmayan değişken bile KO.
- `<stack>`, `<queue>`, `<vector>`, `<list>`, `<algorithm>` ve benzerleri yasak. Yapıları kendin yaz. (`ex10` vector döndürdüğü için orada `<vector>` serbest.)
- `ex08`-`ex10`: `include/linked_list.h` içindeki `LinkedList` class'ı hazır, sadece istenen member function'ı yaz.
- `ex11`-`ex14`: `include/stack_queue.h` içindeki pointer-based `Stack` ve `Queue` hazır (slayttakiyle aynı). `ex13` member değil, sadece public operasyonları kullan.
- `ex15`-`ex17`: `include/tstack.h` içindeki template `Stack<T>` hazır. `ex15` ve `ex17` member function (class içinde declare edilmiş), `ex16` normal fonksiyon. Sadece `push`, `pop`, `getTop`, `isEmpty` kullan.
- `valgrind` ile leak kontrolü var: `new` ile açtığın her şeyi `delete` et.
- Her testin 10 saniye süresi var. Sonsuz döngüde KO (timeout) alırsın.
- 42 kuralı: bir egzersizden OK almadan sıradakine geçme. Notlara bakmadan çözmeye çalış.
