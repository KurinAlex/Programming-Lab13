#include <stdio.h>

#define MAX_SIZE 1000

int main()
{
	int n;
	printf("Enter number of rows: ");
	scanf_s("%d", &n);
	getchar();

	FILE* stream;
	fopen_s(&stream, "longest_words.txt", "w+");

	for (int i = 0; i < n; i++)
	{
		char s[MAX_SIZE];
		printf("\nEnter row %d\n", i + 1);
		gets_s(s, MAX_SIZE);

		int longest_pos = 0;
		int max_length = 0;
		for (int i = 0; s[i] != '\0';)
		{
			int length = 0;
			for (; s[i] != '\0' && s[i] != ' '; length++)
			{
				i++;
			}
			if (length > max_length)
			{
				max_length = length;
				longest_pos = i - length;
			}
			if (s[i] == ' ')
			{
				i++;
			}
		}
		fprintf(stream, "%.*s %d\n", max_length, s + longest_pos, max_length);
	}
	rewind(stream);

	printf("\nFile content:\n");
	char s[MAX_SIZE];
	while (!feof(stream))
	{
		fgets(s, MAX_SIZE, stream);
		if (feof(stream))
		{
			break;
		}
		printf("%s", s);
	}
	fclose(stream);
}