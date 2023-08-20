#include <iostream>

class AbstractEmployee {
	virtual void AskForPromotion() = 0;
};

class Employee: AbstractEmployee {
	private:
		std::string Name;
		std::string Company;
		int	Age;

	public:
		void setName(std::string name) {
			Name = name;
		}
		std::string GetName () {
			return Name;
		}
		void setCompany(std::string company) {
			Company = company;
		}
		std::string GetCompany () {
			return Company;
		}
		void setAge(int age) {
			if (age >= 18)
				Age = age;
		}
		int GetAge () {
			return Age;
		}
		void IntroduceYourself() {
			std::cout << "Name - " << Name << std::endl;
			std::cout << "Company - " << Company << std::endl;
			std::cout << "Age - " << Age << std::endl;
		}
		Employee(std::string name, std::string company, int age) {
			Name = name;
			Company = company;
			Age = age;
		}
		void AskForPromotion() {
			if (Age > 30)
				std::cout << Name << " got promoted" << std::endl;
			else
				std::cout << Name << ", sorry No promotion for you!" << std::endl;

		}
};

int main()
{
	Employee employee1("Carlos", "he dont know!", 3);

	Employee employee2("John", "Amazon", 35);

	employee1.AskForPromotion();
	employee2.AskForPromotion();
}