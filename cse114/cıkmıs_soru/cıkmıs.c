/*
1-) size bir adet integer arrayi verildi bu arrayın ilk elemanı k bu arayın içinde k nın 2.defa bulunduğu yeri bulup
2 sinin aynı olup olmadığı kontrol ediniz örneğin: 5,4,3,5,4,3,2,1 de k 5 olur ardından diğer 5 e kadar 4,3 var 
ikinci 5 den sonrada 4,3 var return 1 ama liste 5,4,3,5,4,2,1 olsaydı return 0.
*/

#include <stdio.h>

int q_1(int arr[])
{	
	int j = 0;
	int i = 1;
	int first = arr[0];
	while(arr[i] != first)
		i++;
	while(j != i)
	{
		if(arr[j] != arr[j+i])
			return 0;
		j++;
	}
	return 1;
}

int foo(int n, int last, int a, int s)
{
    printf("%d%d%d%d", n, last, a, s);
    if (n == 1) return s;
    if (n % last == 0) {
        if (a) return foo(n / last, last, a, s);
        else return foo(n / last, last, 1, s + last);
    }
    else return foo(n, ++last, 0, s);
}
// trick : kağıtta eline direkt değer ver sayılara ve gör çıktıları mantık kur
// fonksiyonun amacı farklı asal çarpanları toplama  mesela 12 = 2.2.3 çıktı 2+3 = 5

/*
3-)int is_palindrome(*first,*last) fonksiyonunu yaz.
 ardından elinde 100 kelimelik her kelimeden sonra 1 adet boşluk olan bir string var
bu stringin içindeki palindrome olan kelimeleri bul.
int palindrome_count(*str,spaces[]). spaces[] içinde boşlukların indexlerini bulunduran 
bir array bunu kullan boşlukları kendin bulmak yerine.
*/


int is_palindrome(char *first,char *last)
{
	while(first < last)
	{
		if(*first != *last)
			return 0;
		first++;
		last--;
	}
	return 1;
}

int palindrome_count(char *str,int spaces[])
{
	int count = 0;
	int i = 0;
	int start = 0;
	while(i < 100)
	{
		int end = spaces[i] - 1;
		if(is_palindrome(str + start, str + end))
			count++;
		start = spaces[i] + 1;
		i++; 
	}
	return count;
}


int main()
{
	int arr_1[] = {5,4,3,5,4,3,2,1};
	int arr_2[] = {5,4,3,5,4,2,1};
	int spaces[] = {
    3, 7, 11, 15, 19, 23, 27, 31, 35, 39,
    43, 47, 51, 55, 59, 63, 67, 71, 75, 79,
    83, 87, 91, 95, 99, 103, 107, 111, 115, 119,
    123, 127, 131, 135, 139, 143, 147, 151, 155, 159,
    163, 167, 171, 175, 179, 183, 187, 191, 195, 199,
    203, 207, 211, 215, 219, 223, 227, 231, 235, 239,
    243, 247, 251, 255, 259, 263, 267, 271, 275, 279,
    283, 287, 291, 295, 299, 303, 307, 311, 315, 319,
    323, 327, 331, 335, 339, 343, 347, 351, 355, 359,
    363, 367, 371, 375, 379, 385, 391, 397, 401, 405,
	};
	char str[] = "w01 w02 w03 w04 w05 w06 w07 w08 w09 w10 w11 w12 w13 w14 w15 w16 w17 w18 w19 w20 w21 w22 w23 w24 w25 w26 w27 w28 w29 w30 w31 w32 w33 w34 w35 w36 w37 w38 w39 w40 w41 w42 w43 w44 w45 w46 w47 w48 w49 w50 w51 w52 w53 w54 w55 w56 w57 w58 w59 w60 w61 w62 w63 w64 w65 w66 w67 w68 w69 w70 w71 w72 w73 w74 w75 w76 w77 w78 w79 w80 w81 w82 w83 w84 w85 w86 w87 w88 w89 w90 w91 w92 w93 w94 w95 radar level kayak ama mum ";
	char x[] = "mum";
	char y[] = "arap";
	//printf("%d\n",q_1(arr_1));
	//printf("%d\n",q_1(arr_2));
	//printf("%d\n",is_palindrome(&x[0],&x[2]));
	//printf("%d\n",is_palindrome(&y[0],&y[3]));
	printf("%d\n",palindrome_count(str,spaces));
}

