#include <iostream>

enum TipoEmpleado {
	Junior,
	Senior,
	Manager
};

float CalcularSalarioSemana(TipoEmpleado tipo, int HorasTrabajadas){
	const float tarifaJunior = 20.0;
	const float tarifaSenior = 30.0;
	const float tarifaManager = 40.0;
	const int HorasNormales = 40;
	const float FactorHorasExtras = 1.5;
	
	float TarifaPorHora;
	switch (tipo){
		case Junior: TarifaPorHora = tarifaJunior; break;
		case Senior: TarifaPorHora = tarifaSenior; break;
		case Manager: TarifaPorHora = tarifaManager; break;
	}
	
	float Salario;
	if (HorasTrabajadas <= HorasNormales){
		Salario = HorasTrabajadas * TarifaPorHora;
	} else{
		int HorasExtras = HorasTrabajadas - HorasNormales;
		Salario = (HorasNormales * TarifaPorHora) + (HorasExtras * TarifaPorHora * FactorHorasExtras);
		}
		
		return Salario;
}
const char* TipoEmpleadoToString(TipoEmpleado tipo){
	switch (tipo){
		case Junior: return "Junior";
		case Senior: return "Senior";
		case Manager: return "Manager";
		default: return "Desconocido";
	}
}
int main () {
	int tipo, HorasTrabajadas;
	std::cout << "Ingrese el tipo de empleado (0:Junior, 1:Senior, 2:Manager):";
	std::cin >> tipo;
	std::cout << "Ingrese la cantidad de horas trabajadas:";
	std::cin >> HorasTrabajadas;
	
	TipoEmpleado Empleado = static_cast<TipoEmpleado>(tipo);
	float Salario = CalcularSalarioSemana(Empleado, HorasTrabajadas);
	std::cout << "El Salario semanal del empleado " << TipoEmpleadoToString(Empleado) << "es: $" << Salario << std::endl;
	
	return 0;
}
