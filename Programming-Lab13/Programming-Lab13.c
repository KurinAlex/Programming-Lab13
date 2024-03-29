﻿#include <stdio.h>

#define MAX_SIZE 1000
#define FILE_NAME "longest_words.txt"

int main()
{
	int n;
	printf("Enter number of rows: ");
	scanf_s("%d", &n);
	getchar();

	FILE* fin;
	fopen_s(&fin, FILE_NAME, "w");

	for (int r = 0; r < n; r++)
	{
		char s[MAX_SIZE];
		printf("\nEnter row %d:\n", r + 1);
		gets_s(s, MAX_SIZE);

		int longest_start_pos = 0;
		int max_length = 0;
		int i = 0;
		do
		{
			int length = 0;
			while (s[i] != '\0' && s[i] != ' ')
			{
				i++;
				length++;
			}
			if (length > max_length)
			{
				max_length = length;
				longest_start_pos = i - length;
			}
		} while (s[i++] != '\0');
		fprintf(fin, "%.*s %d\n", max_length, s + longest_start_pos, max_length);
	}
	fclose(fin);

	FILE* fout;
	fopen_s(&fout, FILE_NAME, "r");
	printf("\nFile content:\n");
	char s[MAX_SIZE];
	do
	{
		fgets(s, MAX_SIZE, fout);
		printf("%s", s);
	} while (!feof(fout));
	fclose(fout);

	getchar();
}