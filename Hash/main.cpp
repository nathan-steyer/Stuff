#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
unsigned long tableSize;

class word
{
public:
	string key;
	int count;
	word() {
		this->key = "";
		this->count = 0;
	}
	word(string key) {
		this->key = key;
		this->count = 1;
	}
};

void insert(vector<word> &, const string &, int & entries);
unsigned long dbhash(const string &);
int search(vector<word> &, const string &);

int main()
{
	cout << "What is the table size? ";
	cin >> tableSize;
	vector<word> HashTable(tableSize);
	string key;
	ifstream ifs("frequencyBig.txt");
	int entries = 0;
	double start = clock();
	while (ifs >> key)
	{
		insert(HashTable, key, entries);
		ifs.ignore();
	}
	double end = clock();
	double total = (end - start) / CLOCKS_PER_SEC;
	cout << total * 1000 << " ms to build frequency table\n";
	cout << "load factor " << entries / (float)tableSize << endl;

	while (true)
	{
		cout << "Enter word to be searched for frequency count or -1 to exit: ";
		cin >> key;
		if (key != "-1")
			cout << key << " apeared " << search(HashTable, key) << " times.\n";
		else
			break;
	}
	cin.ignore();
	cin.get();
	return 0;
}

void insert(vector<word> & HashTable, const string & key, int & entries)
{
	unsigned long start, next;

	start = dbhash(key) % tableSize;
	for (int i = 0; i < tableSize; i++)
	{
		next = (start + i) % tableSize;

		if (HashTable[next].key == key) {
			HashTable[next].count++;
			return;
		}
		else if (HashTable[next].key == "") {
			word newWord(key);
			HashTable[next] = newWord;
			entries++;
			return;
		}
	}
}

int search(vector<word> & HashTable, const string & key)
{
	unsigned long start, next;

	start = dbhash(key) % tableSize;
	for (int i = 0; i < tableSize; i++)
	{
		next = (start + i) % tableSize;
		if (HashTable[next].key == key)
			return HashTable[next].count;
	}

	return -1;
}

unsigned long dbhash(const string & key)
{
	unsigned long h = 5381;
	for (int i = 0; i < key.length(); i++)
		h = ((h << 5) + h) + key[i];
	return h;
}