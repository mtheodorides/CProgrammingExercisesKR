#include <stdio.h>

int main() 
{
	visualizeBlanks();
}

/* Exercise 1-1: Run the "hello, world" program on your system. Experiment with leaving out parts of the program, to see what error 
messages you get */

int helloWorld() {
	printf("hello, world\n");
}

/* Exercise 1-2: Experiment to find out what happens when printf's argument string constains \c, where c is some character not
listed above */

int escapeExperiment() {
	printf("Hello \bWorld\n"); // interesting how backspace will delete a character 
}

/* Exercise 1-3: Modify the temperature conversion program to print a heading above the table. */

int temperatureConversion() {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("\nTemperature Conversion Table\n");
	printf("Fahrenheit\tCelsius\n");

	fahr = lower;
	while(fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f \t \t %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}

/* Exercise 1-4: Write a program to print the corresponding Celsius to Fahrenheit table */

int temperatureConversionTwo() {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("\nTemperature Conversion Table\n");
	printf("Celsius\tFahrenheit\n");

	celsius = lower;
	while(celsius <= upper) {
		fahr = celsius*(9.0/5.0) + 32.0;
		printf("%3.0f \t \t %6.1f\n", celsius, fahr);
		celsius += step;
	}
}

/* Exercise 1-5: Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees
to 0. */

int temperatureConversionReverse() {
	int fahr;

	for(fahr = 300; fahr >= 0; fahr -= 20) {
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
	}
}

/* Exercise 1-6: Verify that the expression getchar() != EOF is 0 or 1. */

int verifyEOF() {
	char result = getchar() != EOF;
	if(result == 0 || result == 1) {
		printf("It's Zero or One!\n");
	}
	else {
		printf("It's not Zero or One?\n");
	}
}

/* Exercise 1-7: Write a program to print the value of EOF */

int printEOF() {
	printf("%d\n", EOF);
}

/* Exercise 1-8: Write a program to count blanks, tabs, and newlines. */

int countsSpaces() {
	int c, count = 0;

	while((c = getchar()) != EOF) {
		if (c == '\n' || c == '\t' || c == ' ') {
			++count;
		}
	}
	printf("Number of Blanks, Tabs, and Newlines: %d\n", count);
}

/* Exercise 1-9: Write a program to copy its input to its output, replacing each string of one or more blanks
by a single blank */

int reduceBlanks() {
	char prevBlank = 0;
	int c;

	while((c = getchar()) != EOF) {
		if(c != ' ') {
			prevBlank = 0;
			putchar(c);
		} else if(prevBlank == 0) {
			prevBlank = 1;
			putchar(c);
		}
	}
}

/* Exercise 1-10: Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\.
This makes tabs and backspaces visible in an unambiguous way */

int visualizeBlanks() {
	int c;
	while((c = getchar()) != EOF) {
		if(c == '\t') {
			putchar('\\');
			putchar('t');
		} else if(c == '\\') {
			putchar('\\');
			putchar('\\');
		} else if(c == '\b') {
			putchar('\\');
			putchar('b');
		} else {
			putchar(c);
		}
	}
}

/* Exercise 1-11: How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any? */

/* Exercise 1-12: Write a program that prints ints input one word per line. */

#define IN 1 /* Inside a blank region */
#define OUT 0 /* Outside a blank region; inside a word */

int wordPerLine() {
	int c, state;
	while((c = getchar()) != EOF) {
		if(c == ' ' || c == '\t' || c == '\n') {
			if(state == OUT) {
				putchar('\n');
				state = IN;
			}
		} else {
			putchar(c);
			state = OUT;
		}
	}
}