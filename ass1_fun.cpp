#include "./ass1.h"

using namespace std;


spellbook* create_spellbooks(int num) {
	spellbook* books = new spellbook[num];

	return books;
}

spell* create_spell(int num) {
	spell* books = new spell[num];

	return books;
}

void bookinfo(spellbook*& catalogue, ifstream& cat, int num, int skip) {
	string str;
	int x;

	for (int i = 0; i < skip; i++) {
		getline(cat, str);
	}

	getline(cat, str, ' ');
	catalogue[num].title = str;

	getline(cat, str, ' ');
	catalogue[num].author = str;

	getline(cat, str, ' ');
	x = stoi(str);
	catalogue[num].num_pages = x;

	getline(cat, str, ' ');
	x = stoi(str);
	catalogue[num].edition = x;

	getline(cat, str, ' ');
	x = stoi(str);
	catalogue[num].num_spells = x;
}

void get_spellbook_data(spellbook*& catalogue, int num, ifstream& cat) {

	bookinfo(catalogue, cat, 0, 0);

	for (int i = 1; i < num; i++) {
		bookinfo(catalogue, cat, i, catalogue[i - 1].num_spells);
	}

}

void spellinfo(spellbook*& catalogue, ifstream& cat, int num) {
	string str;
	float x;

	for (int i = 0; i < catalogue[num].num_spells; i++) {

		getline(cat, str, ' ');
		catalogue[num].s[i].name = str;
		getline(cat, str, ' ');
		x = stof(str);
		catalogue[num].s[i].success_rate = x;
		getline(cat, str, ' ');
		catalogue[num].s[i].effect = str;

	}

}

void avg(spellbook*& catalogue, int num) {
	float average_succ = 0, succ = 0;

	for (int i = 0; i < num; i++) {
		average_succ = 0;
		for (int j = 0; j < catalogue[i].num_spells; j++) {
			succ = catalogue[i].s[j].success_rate;
			average_succ = average_succ + succ;

		}
		catalogue[i].avg_success_rate = (average_succ / catalogue[i].num_spells);
	}
}

void get_spell_data(spellbook*& catalogue, int num, ifstream& cat) {
	string str;
	cat.seekg(0, ios::beg);

	for (int i = 0; i < 2; i++) {
		getline(cat, str);
	}

	for (int i = 0; i < num; i++) {
		spellinfo(catalogue, cat, i);
		getline(cat, str);
		getline(cat, str);
	}

	avg(catalogue, num);

}

void write(spellbook* catalogue, int num) {
	ofstream out;
	out.open("output.txt", ios::app);
	if (out.is_open()) {
		for (int i = 0; i < num; i++) {
			out << "title: " << catalogue[i].title << endl;
			out << "author: " << catalogue[i].author << endl;
			out << "number of pages: " << catalogue[i].num_pages << endl;
			out << "edition: " << catalogue[i].edition << endl;
			out << "average success rate: " << catalogue[i].avg_success_rate << "%" << endl;
			out << endl;

			out << endl;
			out << "________________" << endl;
			out << endl;
		}
		out.close();
	}
	else {
		cout << "cannot output file" << endl;
		out.close();
	}

}

bool is_digit(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (isdigit(str[i]) == true) {

		}
		else {
			return false;
		}
	}

	return true;
}

int ask() {
	string str;
	int x;
	do {
		cout << "would you like to print to a file?" << endl;
		cout << "[1]yes [2]no" << endl;
		getline(cin, str);
		if (is_digit(str) == true) {
			x = stoi(str);
			if ((x == 1) || (x == 2)) {
				return x;
			}
			else {
				cout << "poor input" << endl;
				cout << endl;
				x = 0;
			}
		}
		else {
			cout << "poor input" << endl;
			cout << endl;
		}
	} while (x != 1);
}

void print(spellbook*& catalogue, int num) {
	int x;
	cout << endl;
	cout << endl;
	for (int i = 0; i < num; i++) {
		cout << "title: " << catalogue[i].title << endl;
		cout << "author: " << catalogue[i].author << endl;
		cout << "number of pages: " << catalogue[i].num_pages << endl;
		cout << "edition: " << catalogue[i].edition << endl;
		cout << "average success rate: " << catalogue[i].avg_success_rate << "%" << endl;
		cout << endl;

		cout << endl;
		cout << "________________" << endl;
		cout << endl;
	}

	x = ask();
	if (x == 1) {
		write(catalogue, num);
	}
	else {}
}

void swap(spellbook*& catalogue, int num) {
	float x = 0;
	string str;
	struct spell* temp;

	str = catalogue[num].title;
	catalogue[num].title = catalogue[num + 1].title;
	catalogue[num + 1].title = str;

	x = catalogue[num].num_pages;
	catalogue[num].num_pages = catalogue[num + 1].num_pages;
	catalogue[num + 1].num_pages = x;

	x = catalogue[num].num_spells;
	catalogue[num].num_spells = catalogue[num + 1].num_spells;
	catalogue[num + 1].num_spells = x;

	str = catalogue[num].author;
	catalogue[num].author = catalogue[num + 1].author;
	catalogue[num + 1].author = str;

	x = catalogue[num].edition;
	catalogue[num].edition = catalogue[num + 1].edition;
	catalogue[num + 1].edition = x;

	x = catalogue[num].avg_success_rate;
	catalogue[num].avg_success_rate = catalogue[num + 1].avg_success_rate;
	catalogue[num + 1].avg_success_rate = x;

	temp = catalogue[num].s;
	catalogue[num].s = catalogue[num + 1].s;
	catalogue[num + 1].s = temp;
}

void pgsort(spellbook*& catalogue, int num) {

	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			if (catalogue[j].num_pages > catalogue[j + 1].num_pages) {
				swap(catalogue, j);
			}
		}
	}

}

void avgsort(spellbook*& catalogue, int num) {
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			if (catalogue[j].avg_success_rate > catalogue[j + 1].avg_success_rate) {
				swap(catalogue, j);
			}
		}
	}
}

void print2(spellbook* catalogue, int i, int j) {
	cout << endl;
	cout << catalogue[i].s[j].name << endl;
	cout << "success rate: " << catalogue[i].s[j].success_rate << "%" << endl;
	cout << "effect: " << catalogue[i].s[j].effect << endl;
	cout << endl;

}

void write2(spellbook* catalogue, int i, int j) {
	ofstream out;
	out.open("output.txt", ios::app);
	if (out.is_open() == true) {
		out << catalogue[i].s[j].name << endl;
		out << "success rate: " << catalogue[i].s[j].success_rate << "%" << endl;
		out << "effect: " << catalogue[i].s[j].effect << endl;
		out << endl;
		out.close();
	}
	else {
		cout << "error in printing to output" << endl;
		out.close();
	}



}

void spellsort(spellbook* catalogue, int num) {

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < catalogue[i].num_spells; j++) {
			if (catalogue[i].s[j].effect == "bubble") {
				print2(catalogue, i, j);
			}
		}
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < catalogue[i].num_spells; j++) {
			if (catalogue[i].s[j].effect == "memory_loss") {
				print2(catalogue, i, j);
			}
		}
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < catalogue[i].num_spells; j++) {
			if (catalogue[i].s[j].effect == "fire") {
				print2(catalogue, i, j);
			}
		}
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < catalogue[i].num_spells; j++) {
			if (catalogue[i].s[j].effect == "poison") {
				print2(catalogue, i, j);
			}
		}
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < catalogue[i].num_spells; j++) {
			if (catalogue[i].s[j].effect == "death") {
				print2(catalogue, i, j);
			}
		}
	}

}

void spellsort2(spellbook* catalogue, int num) {

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < catalogue[i].num_spells; j++) {
			if (catalogue[i].s[j].effect == "bubble") {
				write2(catalogue, i, j);
			}
		}
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < catalogue[i].num_spells; j++) {
			if (catalogue[i].s[j].effect == "memory_loss") {
				write2(catalogue, i, j);
			}
		}
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < catalogue[i].num_spells; j++) {
			if (catalogue[i].s[j].effect == "fire") {
				write2(catalogue, i, j);
			}
		}
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < catalogue[i].num_spells; j++) {
			if (catalogue[i].s[j].effect == "poison") {
				write2(catalogue, i, j);
			}
		}
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < catalogue[i].num_spells; j++) {
			if (catalogue[i].s[j].effect == "death") {
				write2(catalogue, i, j);
			}
		}
	}

}

int inputs() {
	string str;
	int x = 0;

	do {
		cout << "how would you like to sort" << endl;
		cout << "[1]page sort [2]average sort [3]spell sort [4]quit" << endl;

		getline(cin, str);
		if (is_digit(str) == true) {
			x = stoi(str);
			if ((x != 1) && (x != 2) && (x != 3) && (x != 4)) {
				cout << "poor input" << endl;
				cout << endl;
				x = 0;
			}
		}
		else {
			cout << "poor input" << endl;
			cout << endl;
		}
	} while ((x != 1) && (x != 2) && (x != 3) && (x != 4));

	return x;
}

void clear(spellbook*& catalogue, char**& argv, int num) {
	for (int i = 0; i < num; i++) {
		delete[] catalogue[i].s;
	}
	delete[] catalogue;
}

void sort(spellbook*& catalogue, int num, int in) {
	int x = 0;
	do {
		if ((in != 1) && (in != 2) && (in != 3)) {
			in = inputs();
		}
		if (in == 1) {
			pgsort(catalogue, num);
			print(catalogue, num);
			in = 0;
		}
		else if (in == 2) {
			avgsort(catalogue, num);
			print(catalogue, num);
			in = 0;
		}
		else if (in == 3) {
			spellsort(catalogue, num);
			in = 0;
			x = ask();
			if (x == 1) {
				spellsort2(catalogue, num);
			}
			else {}
		}
	} while (in != 4);
}

void arg(spellbook*& catalogue, char**& argv, int argc, int num) {
	int in = 0;
	if (argc == 2) {
		if (is_digit(argv[1]) == true) {
			in = atoi(argv[1]);
			if ((in != 1) && (in != 2) && (in != 3)) {
				cout << endl;
				cout << "poor command argument" << endl;
				sort(catalogue, num, 0);
				argc = 0;
			}
			else {
				sort(catalogue, num, in);
				argc = 0;
			}
		}
		else {
			cout << endl;
			cout << "poor command argument" << endl;
			sort(catalogue, num, 0);
		}

	}
	else {
		sort(catalogue, num, 0);
	}

}