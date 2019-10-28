#include "money.h"

Money::Money() {
	funt = 0;
	shil = 0;
	pen = 0;
}

void Money::SplitUp(uint64_t allSum) {
	funt = (uint64_t)((uint64_t)(allSum/12)/20);
	shil = (uint16_t)((allSum - funt*20*12)/12);
	pen = (uint8_t)(allSum-funt*20*12-((uint64_t)shil)*12);
}

// Записать значений в объект (не обязательно из консоли)
void Money::Set(uint64_t f, uint16_t s, uint8_t p) {
	funt = f;
	shil = s;
	pen = p;
}

// Ввести значения c консоли
void Money::Read(std::istream& is) {
	uint64_t f;
	//uint16_t s, p;
	uint16_t s;
	uint8_t p;
	is >> f;
	is >> s;
	is >> p;
	//p = (uint8_t)(p);
	this->Set(f, s, p);
}

// Вывести сумму
void Money::Write(std::ostream& os) const {
	os << funt << ' ';
	os << shil << ' ';
	os << pen << ' ';
	}
// сложение сумм
Money Money::operator+(const Money& a2) const {
	Money result;
	result.SplitUp(AllSumGet() + a2.AllSumGet());
	return result;
}

// все действия проводяться между текущим объектом и объектом, передаваемым в качестве аргумента

// вычитание сумм
Money Money::operator-(const Money& a2) const {
	Money result;
	result.SplitUp((this->AllSumGet() - a2.AllSumGet()));
}

// деление 2х сумм
double Money::operator/(const Money& a2) const {
	return (double)(((double)(this->AllSumGet())) / ((double)(a2.AllSumGet())));
}

// деление суммы на число
Money Money::operator/(float arg) {
	Money result;
	result.SplitUp((uint64_t)((float)(this->AllSumGet())) / arg);
}
// умножение суммы на число
Money Money::operator*(float arg) {
	Money result;
	result.SplitUp((uint64_t)((float)(this->AllSumGet())) * arg);
}

// сравнение
int8_t Money::Compare(const Money& a2) const
{
	int8_t ret;
	if (a2.AllSumGet() == this->AllSumGet()) { ret = 0; }
	if (a2.AllSumGet() > this->AllSumGet())  { ret = 1; }
	if (a2.AllSumGet() < this->AllSumGet())  { ret = -1; }
	return ret;
}

//выводит фунты, шиллинги и пенсы. 
//void Money::Print() {
	//std::cout << "Фунты: " << funt << " " << "Шиллинги: " << shil << " " << "Пенсы: " << (uint16_t)pen << " ";
//}
// allSum - Сумма в пенсах
uint64_t Money::AllSumGet() const {
	return (funt * 20 * 12 + (uint64_t)shil * 12 + (uint64_t)pen);;
}