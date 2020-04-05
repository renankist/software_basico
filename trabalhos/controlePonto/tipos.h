struct Date{
	int dia; 
	int mes; 
	int ano;
};

struct Employee{
	int id; 
	char cpf[12];
	char name[20];
	struct Date data; 

};