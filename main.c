// (c) Daniel Dennis 2018

#include <stdio.h>
#include <string.h>
#define MEM_LIM 32000

unsigned char* memory;
char* next(char* program_counter);

int main(int argc, char** argv)
{
    unsigned char memory_array[MEM_LIM];
    memset(memory_array, 0, MEM_LIM);
    memory = &memory_array[MEM_LIM / 2];
    next(argv[1]);
    putchar('\n');
    return 0;
}

char* next(char* program_counter)
{
    char* end_of_loop;
    int bal;

    switch(*program_counter)
    {
        case '<':
            memory++;
        break;
        case '>':
            memory--;
        break;
        case '+':
            ++*memory;
        break;
        case '-':
            --*memory;
        break;
        case '.':
            putchar(*memory);
        break;
        case ',':
            *memory = getchar();
        break;
        case '[':
            bal = 1;
            end_of_loop = program_counter;

            while(bal)
            {
                end_of_loop++;

                if(*end_of_loop == '[')
                {
                    bal++;
                }
                else if(*end_of_loop == ']')
                {
                    bal--;
                }
            }

            if(*memory)
            {
                while(next(program_counter + 1));
            }

            program_counter = end_of_loop;
        break;
        case ']':
            if(*memory)
            {
                return program_counter;
            }
            else
            {
                return NULL;
            }
        break;
        case '\0':
            return NULL;
        break;
    }

    return next(program_counter + 1);
}
