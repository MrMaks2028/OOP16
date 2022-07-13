#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>

//тривиальные конструкторы и деструкторы
//операторы == < =

class Beast {
public:
	Beast() : Beast(0, " ", false, 0.0) {};
	Beast(
		int id,
		std::string name,
		bool solidity,
		double weight
	): id(id), name(name), solidity(solidity), weight(weight){}


	int id;
	std::string name;
	bool solidity;
	double weight;
};
std::string names[15]{ "Alex", "Aaron", "Benny", "Kris", "Jastin", "Sheryl", "Mike", "Kate", "Paul", "Dwane" };

int main() {
	using namespace std;
	setlocale(LC_ALL, "Russian");

	vector<Beast> circus;
	circus.reserve(10);
	for (int i = 0; i < circus.capacity(); i++){
		srand(time(NULL));
		circus[i].id = rand() % 10;
	}

	for (int i = 0; i < circus.capacity(); i++){
		srand(time(NULL));
		circus[i].name = rand() % names[15].end();
	}

	for (int i = 0; i < circus.capacity(); i++){
		srand(time(NULL));
		circus[i].solidity = rand() % 1;
	}

	for (int i = 0; i < circus.capacity(); i++) {
		srand(time(NULL));
		circus[i].weight = rand() % 10;
	}

	/*for (int i = 0; i < circus.capacity(); i++)
		circus.emplace_back(i, "kitten", false, 7.2);*/

	shuffle(
		circus.begin(),
		circus.end(),
		[](Beast& arg) {
			
		}
	);


	for_each(                         // можно выкинуть в отдельный поток
		circus.begin(),
		circus.end(),
		[](Beast& arg) {
			cout << arg.id << ' '
				 << arg.name << ' '
				<< arg.solidity << ' '
				<< arg.weight << '\n';
		}
	);

	shuffle(
		circus.begin(),
		circus.end(), 
		random_device()
		);

	auto res = find_if(
		circus.begin(),
		circus.end(),
		[](const Beast & arg)->bool{
			if (arg.id == 19)
				return true;
			return false;
		}
	);
	 
	if (res == circus.end())
		cout << "we find nothing\n";
	else
		cout << "we find it on that place: " <<
			res._Ptr << '\n';

	return 0;                                  
}
//большинство алгоритмов работает на стандартных операторах и типах данных
//Заполнить random значениями коллекцию животных. 
//Сделать статистику коллекции по каждому значению: 3 самых лучших, три самых худших.