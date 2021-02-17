#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

////////////////////////////////////////////

class Subject
{
	int mark;		//оценка по предмету, 0 - предмет не сдан
	char name[11];		//название предмета
public:
	Subject();
	bool setName(const char *);	//задать название предмета
	void setMark(int);		//задать оценку
	int getMark();			//узнать оценку
	bool is(const char *);		//проверить является ли этот предмет указанным
	void print();			//распечатать строку
};

Subject::Subject()
{
	mark = 0;
	name[0] = '\0';
}

bool Subject::setName(const char *newName)
{
	if (strlen(newName) > 10)
		return false;
	strcpy(name, newName);
	return true;
}

void Subject::setMark(int newMark)
{
	mark = newMark;
}

int Subject::getMark()
{
	return mark;
}

bool Subject::is(const char * newName)
{
	return (strcmp(newName, name) == 0);
}

void Subject::print()
{
	cout << "  " << name << " : " << mark << endl;
}

////////////////////////////////////////////


class MarkBook
{
	int subjectsNumber;			//количество сданныз предметов (не более 20)
	Subject subjects[20];			//предметы (не более 20)
	bool addSubject(const char *);		//добавить предмет для проставления оценки
	bool checkMark(int);			//проверить оценку на корректность
public:
	MarkBook();
	void average();				//средний балл за сданные предметы
	void addNewResult(const char *, int);	//поставить оценку по предмету
	void print();
};

MarkBook::MarkBook()
{
	subjectsNumber = 0;
}

bool MarkBook::addSubject(const char *str)
{
	if (subjectsNumber >= 20)
		return false;
	if (subjects[subjectsNumber].setName(str))
	{
		subjectsNumber++;
		return true;
	}
	return false;
}

bool MarkBook::checkMark(int newMark)
{
	return (newMark > 2 && newMark <= 5);
}

void MarkBook::addNewResult(const char * subjectName, int mark)
{
	if (checkMark(mark) == false)
	{
		cout << "> Impossible mark" << endl;
		return;
	}
	int i;
	for (i = 0; i < subjectsNumber; i++)
		if (subjects[i].is(subjectName))
		{
			cout << "> Mark was updated" << endl;
			subjects[i].setMark(mark);
			return;
		}

	if (addSubject(subjectName))
	{
		cout << "> Subject and mark was added" << endl;
		subjects[subjectsNumber-1].setMark(mark);
		return;
	}

	cout << "> Impossible subject name" << endl;
}

void MarkBook::average()
{
	double aver = 0;
	for (int i = 0; i < subjectsNumber; i++)
		aver += subjects[i].getMark();
	if (subjectsNumber > 0)
		aver /= subjectsNumber;
	cout << "> Average value is " << fixed << setprecision(4) << aver << endl;
	return;
}

void MarkBook::print()
{
	if (subjectsNumber == 0)
	{
		cout << "> Nothing was passed" << endl;
		return;
	}
	cout << "> " << subjectsNumber << " subjects was passed" << endl;
	for (int i = 0; i < subjectsNumber; i++)
		subjects[i].print();
}

////////////////////////////////////////////

int main()
{
	MarkBook mb;

	char command;	//+ - добавить результат, ? - печать, . - завершить
	char name[100];
	int mark;

	while(1)
	{
		cin >> command;
		switch (command)
		{
			case '+':
			{
				cin.get();			//пропустить пробел после +
				cin.get(name, 99, ' ');		//считать название предмета
				cin >> mark;
				mb.addNewResult(name, mark);
				break;
			}
			case '?':
			{
				mb.print();
				break;
			}
			case '*':
			{
				mb.average();
				break;
			}
			case '.':
			{
				return 0;
			}
		}
	}
	return 0;
}
