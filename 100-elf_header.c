#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * address - prints address
 * @ptr: magic
 * Return: void
 */

void address(char *ptr)
{
	int i, a;
	char s;

	printf("  Entry point address:               0x");

	s = ptr[4] + '0';
	if (s == '1')
	{
		a = 26;
		printf("80");
		for (i = a; i >= 22; i--)
		{
			if (ptr[i] > 0)
				printf("%x", ptr[i]);
			else if (ptr[i] < 0)
				printf("%x", 256 + ptr[i]);
		}
		if (ptr[7] == 6)
			printf("00");
	}

	if (s == '2')
	{
		a = 26;
		for (i = a; i > 23; i--)
		{
			if (ptr[i] >= 0)
				printf("%02x", ptr[i]);

			else if (ptr[i] < 0)
				printf("%02x", 256 + ptr[i]);
		}
	}
	printf("\n");
}

/**
 * type - prints type
 * @ptr: magic
 * Return: void
 */

void type(char *ptr)
{
	char x = ptr[16];

	if (ptr[5] == 1)
		x = ptr[16];
	else
		x = ptr[17];

	printf("  Type:                              ");
	if (x == 0)
		printf("NONE (No file type)\n");
	else if (x == 1)
		printf("REL (Relocatable file)\n");
	else if (x == 2)
		printf("EXEC (Executable file)\n");
	else if (x == 3)
		printf("DYN (Shared object file)\n");
	else if (x == 4)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", x);
}

/**
 * osabi - prints osabi
 * @ptr: magic
 * Return: void
 */

void osabi(char *ptr)
{
	char y = ptr[7];

	printf("  OS/ABI:                            ");
	if (y == 0)
		printf("UNIX - System V\n");
	else if (y == 2)
		printf("UNIX - NetBSD\n");
	else if (y == 6)
		printf("UNIX - Solaris\n");
	else
		printf("<unknown: %x>\n", y);

	printf("  ABI Version:                       %d\n", ptr[8]);
}

/**
 * version - prints version
 * @ptr: magic
 * Return: void
 */

void version(char *ptr)
{
	int z = ptr[6];

	printf("  Version:                           %d", z);

	if (z == EV_CURRENT)
		printf(" (current)");

	printf("\n");
}

/**
 * data - prints data
 * @ptr: magic
 * Return: void
 */

void data(char *ptr)
{
	char b = ptr[5];

	printf("  Data:                              2's complement");
	if (b == 1)
		printf(", little endian\n");

	if (b == 2)
		printf(", big endian\n");
}

/**
 * magic - prints magic information
 * @ptr: magic
 * Return: void
 */

void magic(char *ptr)
{
	int c;

	printf("  Magic:  ");

	for (c = 0; c < 16; c++)
		printf(" %02x", ptr[c]);

	printf("\n");
}

/**
 * sys - check the version system
 * @ptr: magic
 * Return: void
 */

void sys(char *ptr)
{
	char d = ptr[4] + '0';

	if (d == '0')
		exit(98);

	printf("ELF Header:\n");
	magic(ptr);

	if (d == '1')
		printf("  Class:                             ELF32\n");

	if (d == '2')
		printf("  Class:                             ELF64\n");

	data(ptr);
	version(ptr);
	osabi(ptr);
	type(ptr);
	address(ptr);
}

/**
 * check_elf - check if it is an elf file
 * @ptr: magic
 * Return: 1 if it is an elf file. 0 if not
 */

int check_elf(char *ptr)
{
	int r = (int)ptr[0];
	char E = ptr[1];
	char L = ptr[2];
	char F = ptr[3];

	if (r == 127 && E == 'E' && L == 'L' && F == 'F')
		return (1);

	return (0);
}

/**
 * main - check the code
 * @argc: number of arguments
 * @argv: arguments vector
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	int f, g;
	char ptr[27];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	f = open(argv[1], O_RDONLY);

	if (f < 0)
	{
		dprintf(STDERR_FILENO, "Err: file can not be open\n");
		exit(98);
	}

	lseek(f, 0, SEEK_SET);
	g = read(f, ptr, 27);

	if (g == -1)
	{
		dprintf(STDERR_FILENO, "Err: The file can not be read\n");
		exit(98);
	}

	if (!check_elf(ptr))
	{
		dprintf(STDERR_FILENO, "Err: It is not an ELF\n");
		exit(98);
	}

	sys(ptr);
	close(f);

	return (0);
}
