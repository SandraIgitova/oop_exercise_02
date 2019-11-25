#include "money.h"

Money::Money(): funt(0), shil(0), pen(0)
{
}

Money::Money(uint64_t f, uint32_t s, uint8_t p): funt(f), shil(s), pen(p)
{
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
	uint16_t s, p;
	is >> f;
	is >> s;
	is >> p;
	this->Set(f, s, p);
}

 std::istream& operator>>(std::istream& is, Money& m){
 	uint32_t tmp;
	is >> m.funt >> m.shil >> tmp;
	m.pen = tmp;
	return  is;
}

// Вывести сумму
void Money::Write(std::ostream& os) const {
	os << funt << ' ';
	os << shil << ' ';
	os << (int)pen << ' ';
	}

 std::ostream& operator<<(std::ostream& os, const Money& m){
	os << m.funt << " " << m.shil << " " << (uint32_t)m.pen;
	return os;
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
	return result;
}

// деление 2х сумм
double Money::operator/(const Money& a2) const {
	return (double)(((double)(this->AllSumGet())) / ((double)(a2.AllSumGet())));
}

// деление суммы на число
Money Money::operator/(float arg) {
	Money result;
	result.SplitUp((uint64_t)((float)(this->AllSumGet())) / arg);
	return result;
}
// умножение суммы на число
Money Money::operator*(float arg) {
	Money result;
	result.SplitUp((uint64_t)((float)(this->AllSumGet())) * arg);
	return result;
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
void Money::Print() {
	std::cout << "Фунты: " << funt << " " << "Шиллинги: " << shil << " " << "Пенсы: " << (uint16_t)pen << " ";
}
// allSum - Сумма в пенсах
uint64_t Money::AllSumGet() const {
	return (funt * 20 * 12 + (uint64_t)shil * 12 + (uint64_t)pen);;
}

Money operator"" _funt(unsigned long long int num)
{
	Money res(num, 0, 0);
	return res;
}

Money operator"" _shil(unsigned long long int num)
{
	Money res(0, num, 0);
	return res;
}

Money operator"" _pen(unsigned long long int num)
{
	Money res(0, 0, num);
	return res;
}