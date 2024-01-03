#include "opositor.h"

void	ft_leaks(void)
{
	system("leaks -q opositor");
}

int main(void)
{
    atexit(ft_leaks);
    int     fd;
    char    respuesta;
    char    *respuesta_fichero;
    char    *cadena_imprimir;

    fd = open("cuestionario.txt", O_RDONLY);
    cadena_imprimir = ft_get_next_line(fd);
    while (cadena_imprimir && cadena_imprimir[0] != '\n')
    {
        printf("%s", cadena_imprimir);
        free(cadena_imprimir);
        cadena_imprimir = ft_get_next_line(fd);
        printf("%s", cadena_imprimir);
        free(cadena_imprimir);
        cadena_imprimir = ft_get_next_line(fd);
        printf("%s", cadena_imprimir);
        free(cadena_imprimir);
        cadena_imprimir = ft_get_next_line(fd);
        printf("%s", cadena_imprimir);
        free(cadena_imprimir);
        cadena_imprimir = ft_get_next_line(fd);
        printf("%s", cadena_imprimir);
        free(cadena_imprimir);
        
        printf("\n");
        printf("--RESPUESTA--> ");
        scanf("%c", &respuesta);
        respuesta_fichero = ft_get_next_line(fd);
        if (respuesta == respuesta_fichero[0])
            printf("OK\n");
        else
            printf("ERROR - RESPUESTA CORRECTA -> %s", respuesta_fichero);
        printf("\n\n");
        respuesta = getchar();
        free(respuesta_fichero);
        cadena_imprimir = ft_get_next_line(fd);
    }
    return (0);
}