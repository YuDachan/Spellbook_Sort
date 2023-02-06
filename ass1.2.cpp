#include "./ass1.h"

using namespace std;


int main(int argc, char** argv) {
	string str;
	int num = 0;

	ifstream cat;
	cat.open("spellbooks.txt");
	if (cat.fail()) {
		cout << "error opening file ... aborting program" << endl;
		return 0;
	}
	getline(cat, str);
	num = stoi(str);

	spellbook* catalogue = create_spellbooks(num);
	get_spellbook_data(catalogue, num, cat);

	for (int i = 0; i < num; i++) {
		catalogue[i].s = create_spell(num);
	}

	get_spell_data(catalogue, num, cat);

	arg(catalogue, argv, argc, num);

	clear(catalogue, argv, num);
	cat.close();

	return 0;
}