#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include<stdbool.h>
bool validate(double a);
int main()
{
	double numberOfSeeds, productivityOfSeeds, area , seedingRate , numberOf;
	double realAmount;
	int i = 0 , years = 0;

	printf("%s", "Enter number of seeds(kg): ");
	scanf("%lf", &numberOfSeeds);
	if (!validate(numberOfSeeds)) {
		printf("%s", "Can't be negative");
	}

	printf("%s", "Enter annual productivity of seeds(kg): ");
	scanf("%lf", &productivityOfSeeds);

	if (!validate(productivityOfSeeds)) {
		printf("%s", "Can't be negative");
	}

	printf("%s", "Enter area of the field(hectare): ");
	scanf("%lf", &area);
	if (!validate(area)) {
		printf("%s", "Can't be negative");
	}

	printf("%s", "Enter seeding rate(kg/hectare): ");
	scanf("%lf", &seedingRate);
	if (!validate(seedingRate)) {
		printf("%s", "Can't be negative");
	}

	realAmount = area * seedingRate;

	while (realAmount > 0.0)
	{
		if (numberOfSeeds < seedingRate) {
			realAmount -= numberOfSeeds;
			numberOfSeeds = numberOfSeeds * productivityOfSeeds;
		}
		else {
			numberOfSeeds -= seedingRate;
			realAmount -= seedingRate;
			numberOfSeeds += productivityOfSeeds * seedingRate;
		}
		years++;
	}
	printf("%d", years);

	return 0;
}
bool validate(double a) {
	return a <= 0 ? false : true;
}