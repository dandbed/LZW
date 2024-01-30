#include "Library.h"
#include "Prototypes.h"

int main()
{
	setlocale(0, "");

	unordered_map <string, int> Book;
	string S, x;
	vector <unsigned char> S_sorted;
	int j = 0;

	cout << "Введите строку для кодирования по алгоритму Лемпеля-Зива-Велча: ";
	getline(cin, S);
	cout << endl;

	for (int i = 0; i < S.size(); i++)
	{
		S_sorted.push_back(S[i]);
	}

	sort(S_sorted.begin(), S_sorted.end());
	x += S_sorted[j];

	Book.insert(pair <string, int>(x, j));

	for (int i = 1; i < size(S_sorted); i++)
	{
		string y;
		y += S_sorted[i];

		if (Book.count(y) == 0)
		{
			j++;
			Book.insert(pair<string, int>(y, j));
		}
	}
	
	cout << "Введенная строка: " << endl << S << endl;

	string Coded_S = Coder(S, Book);
	cout << "Закодированная строка:" << endl << Coded_S << endl;

	/*unordered_map <string, int>::iterator it = Book.begin();
	for (int i = 0; it != Book.end(); it++, i++)
	{
		cout << it->second << " " << it->first << endl;
	}
	cout << endl;*/

	string Decoded_S = Decoder(Coded_S, Book);
	cout << "Строка после дешифровки: " << endl << Decoded_S << endl;
	return 0;
}