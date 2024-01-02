#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &shrubbery) : AForm(shrubbery), _target(shrubbery._target){

}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	AForm::operator=(rhs);
	this->_target = rhs._target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!this->getSigned())
		throw (AForm::NotSignedException());
	if (executor.getGrade() > this->getGradeToExec())
		throw (AForm::GradeTooLowException());

	std::ofstream file(this->_target + "_shrubbery");
	if (file.is_open())
	{
		file << "		_{\\ _{\\{\\/}/}/}__	" << std::endl;
		file << "		{/{/\\}{/{/\\}(\\}{/\\} _	" << std::endl;
		file << "		{/{/\\}{/{/\\}(_)\\}{/{/\\}  _	" << std::endl;
		file << "	{\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}	" << std::endl;
		file << "	{/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}	" << std::endl;
		file << "	_{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}	" << std::endl;
		file << "	{/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}	" << std::endl;
		file << "	_{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}	" << std::endl;
		file << "	{/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}	" << std::endl;
		file << "	{\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}	" << std::endl;
		file << "	{/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)	" << std::endl;
		file << "	{/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}	" << std::endl;
		file << "	{/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}	" << std::endl;
		file << "		{/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}	" << std::endl;
		file << "		(_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)	" << std::endl;
		file << "			{/{/{\\{\\/}{/{\\{\\{\\(_)/}	" << std::endl;
		file << "			{/{\\{\\{\\/}/}{\\{\\}/}	" << std::endl;
		file << "			{){/ {\\/}{\\/} \\}\\}	" << std::endl;
		file << "			(_)  \\.-'.-/	" << std::endl;
		file << "		__...--- |'-.-'| --...__	" << std::endl;
		file << "_...--\"   .-'   |'-.-'|  ' -.  \"\"--..__	" << std::endl;
		file << "-\"    ' .  . '    |.'-._| '  . .  '   	" << std::endl;
		file << ".  '-  '    .--'  | '-.'|    .  '  . '	" << std::endl;
		file << "		' ..     |'-_.-|	" << std::endl;
		file << ".  '  .       _.-|-._ -|-._  .  '  .	" << std::endl;
		file << "			.'   |'- .-|   '.	" << std::endl;
		file << "..-'   ' .  '.   `-._.-�   .'  '  - .	" << std::endl;
		file << ".-' '        '-._______.-'     '  .	" << std::endl;
		file << "		.      ~,	" << std::endl;
		file << "	.       .   |\\   .    ' '-.	" << std::endl;
		file.close();
	}
	else
	{
		std::cout << "Failed to create file!" << std::endl;
		return ;
	}
}