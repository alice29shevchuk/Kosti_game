#include <iostream>
class Kost
{
	int value;
public:
	Kost()
	{
		this->value = 1 + rand() % 6;
	}
	int getValue()
	{
		return this->value;
	}
	friend std::ostream& operator<<(std::ostream& out, const Kost& kost)
	{
		out << "Выпало: " << kost.value << "\n";
		return out;
	}
};
class Set_Kostey
{
	int size;
	Kost* mas;
public:
	Set_Kostey(int size)
	{
		this->size = size;
		mas = new Kost[size];
	}
	friend std::ostream& operator<<(std::ostream& out, const Set_Kostey& set_kostey)
	{
		for (int i = 0; i < set_kostey.size; i++)
		{
			out << set_kostey.mas[i];
		}
		return out;
	}
	Kost& operator[](const int index)
	{
		return this->mas[index];
	}
	void Sum()
	{
		int sum=0;
		for (int i = 0; i < size; i++)
		{
			sum += mas[i].getValue();
		}
		std::cout << sum;
	}
};
int main()
{
	setlocale(0, "");
	srand(time(0));
	int size;
	std::cout << "Введите размер коллекции: ";
	std::cin >> size;
	Set_Kostey set_kostey(size);
	std::cout << set_kostey;
	int num;
	std::cout << "\nВведите номер кости, на которой хотите посмотреть что выпало: ";
	std::cin >> num;
	if (num > 0 && num <= size)
	{
		std::cout << set_kostey[num - 1];
	}
	else
	{
		std::cout << "Вы ввели некорректный индекс!\n";
	}
	std::cout << "\nСумма значений всех костей = ";
	set_kostey.Sum();
}

