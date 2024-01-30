#include "Library.h"
#include "Prototypes.h"

string Decoder(string Coded_S, unordered_map<string, int> Book)
{
	unordered_map <int, string> Book_2;
	unordered_map<string, int> Book_3;

	unordered_map<string, int>::iterator it;
	for (it = Book.begin(); it != Book.end(); it++)
	{
		int x = it->second;
		string y = it->first;
		Book_2.insert(make_pair(x, y));
	}

	string Decoded_S, Inter_S, New_to_Book;

	int i = 0;

	while (i < Coded_S.size())
	{
		if (Coded_S[i] == ' ')
		{
			i++;
		}
		else 
		{
			while (Coded_S[i] != ' ' && i < Coded_S.size())
			{
				Inter_S += Coded_S[i];
				i++;
			}
			
			int Num = stoi(Inter_S);
			
			if (Book_2.count(Num) == 1)
			{
				string Add;
				Add = Book_2[Num];

				New_to_Book += Add;
				Decoded_S += Add;

				int j = 0;
				string Add_to_Book;
				Add_to_Book += New_to_Book[j];
				j++;

				while (Book.count(Add_to_Book) == 1 && j < New_to_Book.size())
				{
					Add_to_Book += New_to_Book[j];
					j++;
				}
				if (Book.count(Add_to_Book) == 0)
				{
					Book.insert(make_pair(Add_to_Book, Book.size()));
					Book_2.insert(make_pair(Book_2.size(), Add_to_Book));

					New_to_Book.erase(0, Add_to_Book.size() - 1);
					
				}
				
			}
			else
			{
				string Buff, Add;
				int count = 0;
				unordered_map<string, int> ::iterator it_3 = Book_3.begin();
				
				if (Book_3.count(New_to_Book) == 0)
				{
					Book_3.insert(make_pair(New_to_Book, 1));
				}
				else
				{
					for (it_3 = Book_3.begin(); it_3 != Book_3.end(); it_3++)
					{
						if (it_3->first == New_to_Book)
						{
							int x = it_3->second;
							x++;

							it_3->second = x;
						}
					}
				}

				for (it_3 = Book_3.begin(); it_3 != Book_3.end(); it_3++)
				{
					if (it_3->first == New_to_Book)
					{
						int j = 0;

						while (j < it_3->second)
						{
							Buff += New_to_Book;
							j++;
						}
					}
				}
				
				New_to_Book += Buff;

				Book.insert(make_pair(New_to_Book, Book.size()));
				Book_2.insert(make_pair(Book_2.size(), New_to_Book));

				Decoded_S += New_to_Book;

				New_to_Book.clear();
				New_to_Book += Buff;
			}
		}

		Inter_S.clear();
	}
	
	return Decoded_S;
}