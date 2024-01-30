#include "Library.h"
#include "Prototypes.h"

string Coder(string S, unordered_map <string, int> Book)
{
	string Coded_S, Inter_S;
	int i = 0;

	while (i < S.size())
	{
		Inter_S.append(S, i, 1);
		
		if (Book.count(Inter_S) == 1)
		{
			i++;
		}
		else
		{
			Book.insert(make_pair(Inter_S, Book.size()));

			string Add_to_Book;
			Add_to_Book.append(Inter_S, 0, Inter_S.size() - 1);

			int Num = Book[Add_to_Book];
			Coded_S += to_string(Num);
			Coded_S.append(" ");

			Inter_S.clear();
		}
	}

	int Num = Book[Inter_S];
	Coded_S += to_string(Num);
	
	return Coded_S;
}