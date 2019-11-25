#ifndef MONEY_H
#define MONEY_H

#include <cinttypes>
#include <iostream>
#include "money.h"

class Money {
public:
	Money();
	Money(uint64_t f, uint32_t s, uint8_t p);
	// разделение всей суммы на фунты, шиллинги и пенсы с записью их в разные переменные
	void SplitUp(uint64_t allSum);
	// Получить сумму
	void Set(uint64_t f, uint16_t s, uint8_t p);
	// Ввести с консоли
	 void Read(std::istream& is);
	// Вывести сумму на консоль
	 void Write(std::ostream& os) const;

	friend std::istream& operator>>(std::istream& is, Money& m);
	friend std::ostream& operator<<(std::ostream& os, const Money& m);
	


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
	
	void Print();


private:
	uint64_t funt; // количество фунтов funt
	uint16_t shil; // количество шиллингов shil
	uint8_t pen; // количество пенсов
};
	// Money operator ""_m(const char* str, size_t size);

Money operator"" _funt(unsigned long long int num);
Money operator"" _shil(unsigned long long int num);
Money operator"" _pen(unsigned long long int num);

#endif
