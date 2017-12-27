#include <stdio.h>

struct fish {
	const char *name;
	const char *species;
	int teeth;
	int age;
};

/* 카탈로그 항목 출력 */
void catalog(const char *name, const char *species, int teeth, int age)
{
	printf("%s 는 %s 종이며, 이빨은 %i 개고, %i 살입니다. \n", name, species, teeth, age);
}

void catalog_s(struct fish f)
{
	printf("%s 는 %s 종이며, 이빨은 %i 개고, %i 살입니다. \n", f.name , f.species, f.teeth, f.age);
}

/* print the label for the tank */
void label(const char *name, const char *species, int teeth, int age)
{
	printf("Name:%s\nSpecies:%s\n%i years old\n%i teeth\n", name, species, teeth, age);
}


int main()
{
	struct fish snappy = {"스내피", "피라냐", 70, 4};

	catalog("스내피", "피라냐", 69, 4);
	label("Snappy", "piranch", 69, 4);

	catalog_s(snappy);

	return 0;
}
