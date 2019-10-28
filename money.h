#ifndef MONEY_H
#define MONEY_H

#include <cinttypes>
#include <iostream>
#include "money.h"

class Money {
public:
	Money();
	// разделение всей суммы на фунты, шиллинги и пенсы с записью их в разные переменные
	void SplitUp(uint64_t allSum);
	// Получить сумму
	void Set(uint64_t f, uint16_t s, uint8_t p);
	// Ввести с консоли
	void Read(std::istream& is);
	// Вывести сумму на консоль
	void Write(std::ostream& os) const;
	// сложение сумм
	Money operator+(const Money& a2) const;
	// вычитание сумм
	Money operator-(const Money& a2) const;
	// деление 2х сумм
	double operator/(const Money& a2) const;
	// деление суммы на число
	Money operator/(float arg);
	// умножение суммы на число
	Money operator*(float arg);
	// сравнение
	int8_t Compare(const Money& a2) const;
	//геттер для allSum
	uint64_t AllSumGet() const;

private:
	uint64_t funt; // количество фунтов funt
	uint16_t shil; // количество шиллингов shil
	uint8_t pen; // количество пенсов
};

#endif
