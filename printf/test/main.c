#include <stdio.h>
#include "../inc/ft_printf.h"

int main(void)
{
    int ret_ft_printf;
    int ret_printf;
    
    // Testing strings
    ret_ft_printf = ft_printf("My string: %s\n", "Hello, world!");
    ret_printf = printf("My string: %s\n", "Hello, world!");
    printf("[ft_printf returned: %d | printf returned: %d]\n\n", ret_ft_printf, ret_printf);

    // Testing characters
    ret_ft_printf = ft_printf("My character: %c\n", 'A');
    ret_printf = printf("My character: %c\n", 'A');
    printf("[ft_printf returned: %d | printf returned: %d]\n\n", ret_ft_printf, ret_printf);

    // Testing integers
    ret_ft_printf = ft_printf("My integer: %d\n", 12345);
    ret_printf = printf("My integer: %d\n", 12345);
    printf("[ft_printf returned: %d | printf returned: %d]\n\n", ret_ft_printf, ret_printf);

    // Testing unsigned integers
    ret_ft_printf = ft_printf("My unsigned int: %u\n", 4294967295);
    ret_printf = printf("My unsigned int: %u\n", (unsigned int)4294967295);
    printf("[ft_printf returned: %d | printf returned: %d]\n\n", ret_ft_printf, ret_printf);

    // Testing pointers
    int a = 42;
    ret_ft_printf = ft_printf("My pointer: %p\n", &a);
    ret_printf = printf("My pointer: %p\n", &a);
    printf("[ft_printf returned: %d | printf returned: %d]\n\n", ret_ft_printf, ret_printf);

    // Testing hexadecimal (lowercase)
    ret_ft_printf = ft_printf("Hexadecimal lowercase: %x\n", 255);
    ret_printf = printf("Hexadecimal lowercase: %x\n", 255);
    printf("[ft_printf returned: %d | printf returned: %d]\n\n", ret_ft_printf, ret_printf);

    // Testing hexadecimal (uppercase)
    ret_ft_printf = ft_printf("Hexadecimal uppercase: %X\n", 255);
    ret_printf = printf("Hexadecimal uppercase: %X\n", 255);
    printf("[ft_printf returned: %d | printf returned: %d]\n\n", ret_ft_printf, ret_printf);

    // Testing escape character %
    ret_ft_printf = ft_printf("Percentage: %%\n");
    ret_printf = printf("Percentage: %%\n");
    printf("[ft_printf returned: %d | printf returned: %d]\n\n", ret_ft_printf, ret_printf);

    return 0;
}