#ifndef PACIENTE_HPP
#define PACIENTE_HPP

class Paciente
{
public:
	Paciente();
	
	~Paciente();
private:
	char DNI[10];
	int id;
	int habitacion;
	bool apendicitis;
	

};

#endif // PACIENTE_HPP
