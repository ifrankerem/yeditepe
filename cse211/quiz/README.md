# CSE 211 Lab Quiz (42 tarzı)

Konular: linked list, stack, queue (Chapter 4, 6, 7). 8 egzersiz, 4 seviye.

| Seviye | Egzersiz |
|--------|----------|
| 0 | `ex00_sum_list`, `ex01_nth_from_end` |
| 1 | `ex02_delete_all`, `ex03_stack` |
| 2 | `ex04_balanced`, `ex05_circular_queue` |
| 3 | `ex06_merge_sorted`, `ex07_dlist` |

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
- `<stack>`, `<queue>`, `<vector>`, `<list>`, `<algorithm>` ve benzerleri yasak. Yapıları kendin yaz.
- `valgrind` ile leak kontrolü var: `new` ile açtığın her şeyi `delete` et.
- Her testin 10 saniye süresi var. Sonsuz döngüde KO (timeout) alırsın.
- 42 kuralı: bir egzersizden OK almadan sıradakine geçme. Notlara bakmadan çözmeye çalış.
