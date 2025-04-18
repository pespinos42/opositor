#include "opositor.h"

void	ft_leaks(void)
{
	system("leaks -q opositor");
}

int main(int argc, char **argv)
{
    //atexit(ft_leaks);
    int     fd;
    //char    respuesta;
    //char    *respuesta_fichero;
    char    *cadena_imprimir;
    //int     total_preguntas;
    //int     total_aciertos;
    //int     total_errores;
    //int	    linea_error;
    char    *comprobacion_total_preguntas;
    int     total_lineas;

    //total_preguntas = 0;
    //total_aciertos = 0;
    //total_errores = 0;
    //linea_error = 1;
    comprobacion_total_preguntas = 0;
    total_lineas = 0;

    if (argc != 2)
    {
        printf("INTRODUZCA COMO PARAMETRO LA RUTA DEL FICHERO\nINTENTELO DE NUEVO\n");
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        printf("NO SE ENCUENTRA EL FICHERO\n");
        exit(1);
    }

    //PARTE NUEVA DE COMPROBACION POR NUMERO DE LINEAS

    comprobacion_total_preguntas = ft_get_next_line(fd);
    cadena_imprimir = ft_get_next_line(fd);
    total_lineas++;
    while (cadena_imprimir)
    {
	    cadena_imprimir = ft_get_next_line(fd);
	    if (cadena_imprimir)
		    total_lineas++;
    }

    if (total_lineas / 6 == atoi(comprobacion_total_preguntas))
    {
	    printf("TOTAL PREGUNTAS = %i\n", atoi(comprobacion_total_preguntas));
	    printf("TOTAL LINEAS = %i\n", total_lineas);
	    printf("TOTAL LINEAS / 6 = %i\n", total_lineas/6);
	    printf("FICHERO CORRECTO\n");
    }
    else
    {
        printf("TOTAL PREGUNTAS = %i\n", atoi(comprobacion_total_preguntas));
	    printf("TOTAL LINEAS = %i\n", total_lineas);
	    printf("TOTAL LINEAS / 6 = %i\n", total_lineas/6);
	    printf("FICHERO CORRUPTO\n");
	    exit(1);
    }

    //FIN DE PARTE NUEVA DE COMPROBACION POR NUMERO DE LINEAS

/*    cadena_imprimir = ft_get_next_line(fd);

    printf("COMPROBANDO INTEGRIDAD DEL FICHERO\n");
    while (cadena_imprimir && cadena_imprimir[0] != '\n')
    {
	    for (int i = 0; i <= 4; i++)
	    {
		    printf("%i-", linea_error);
		    free(cadena_imprimir);
		    cadena_imprimir = ft_get_next_line(fd);
		    linea_error++;
	    }
	    if (strlen(cadena_imprimir) != 2)
	    {
		    printf("ERROR EN LA LINEA -> %i\n", linea_error);
		    printf("LINEA -> %s", cadena_imprimir);
		    printf("NUMERO DE CARACTERES -> %li\n", strlen(cadena_imprimir));
		    free(cadena_imprimir);
		    exit(1);
	    }
	    free(cadena_imprimir);
	    cadena_imprimir = ft_get_next_line(fd);
    }
    printf("\nFICHERO OK\n");
    close(fd);

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
	    printf("NO SE ENCUENTRA EL FICHERO\n");
	    exit(1);
    }
    cadena_imprimir = ft_get_next_line(fd);

    while (cadena_imprimir && cadena_imprimir[0] != '\n')
    {
        printf("%s", cadena_imprimir);
        free(cadena_imprimir);
        cadena_imprimir = ft_get_next_line(fd);
        printf("a) %s", cadena_imprimir);
        free(cadena_imprimir);
        cadena_imprimir = ft_get_next_line(fd);
        printf("b) %s", cadena_imprimir);
        free(cadena_imprimir);
        cadena_imprimir = ft_get_next_line(fd);
        printf("c) %s", cadena_imprimir);
        free(cadena_imprimir);
        cadena_imprimir = ft_get_next_line(fd);
        printf("d) %s", cadena_imprimir);
        free(cadena_imprimir);
        
        printf("\n");
        printf("\033[1;30;47m--RESPUESTA-->\033[0m ");
        scanf("%c", &respuesta);
        respuesta_fichero = ft_get_next_line(fd);
        if (respuesta == respuesta_fichero[0])
        {
            printf("\033[1;37;42mOK\033[0m\n");
            total_aciertos++;
        }
        else
        {
            printf("\033[1;37;41mERROR - RESPUESTA CORRECTA ->\033[0m %s", respuesta_fichero);
            total_errores++;
        }
        total_preguntas++;
        printf("\n\n");
        respuesta = getchar();
        free(respuesta_fichero);
        cadena_imprimir = ft_get_next_line(fd);
    }
    printf("\033[1;30;47mPREGUNTAS = %i    ACIERTOS = %i    ERRORES = %i\033[0m\n", total_preguntas, total_aciertos, total_errores);
    if (total_errores == 0)
    {
        printf("\n");
        printf("\033[1;37;42mTODO PERFE!\033[0m\n");        
    }
    printf("\n");

    */
    return (0);
}
