//#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	int main () {
		
		system("color 0d");

		int ns = 0, ne = 0, nef = 0, ei = 0, i = 0, j = 0, k = 0, n = 0, c = 0, e = 0, flag = 0;
		char a[10];
		char nomeprog[15];
		char barra = 92;
		char aspas = 34;
		int  ef[10];

		fflush(stdin);

		printf("quantos simbolos tem o alfabeto? ");
		scanf("%d", &ns);	puts("\n");

		for (i = 0; i < ns; i++) {

			printf("qual o simbolo %d ? ", i);
			scanf("%s", &a[i]);

		}

		puts("");

		printf("quantos estados? ");
		scanf("%d", &ne);	puts("\n");

        printf("quantos estados finais? ");
		scanf("%d", &nef);	puts("\n");

		for (i = 0; i < nef; i++) {

            printf("qual o estado final %i ? ", i);
            scanf("%d", &ef[i]);

		}

		puts("\n");

        printf("qual o estado inicial? ");
        scanf("%d", &ei);

        puts("\n");

        int m[ne][ns];

        for (i = 0; i < ne; i++) {

			printf("para o estado e%d e simbolo %c, qual o proximo estado? ", i, a[0]);
			scanf("%d", &m[i][0]);

			for (j = 1; j < ns; j++) {

				printf("para o estado e%d e simbolo %c, qual o proximo estado? ", i, a[j]);
				scanf("%d", &m[i][j]);

			}

		}

		printf("\n escolha: \n 1 - funcao \n 2 - goto \n digite: ");
		scanf("%d", &c);

		puts("");

		while (c != 1 && c != 2) {

			printf("opcao invalida. digite novamente: ");
			scanf("%d", &c);

		}

		printf("\n nome do programa: ");
		scanf("%s", nomeprog);

		FILE * arquivo = fopen(nomeprog, "w");

		if (arquivo == NULL)
            printf("erro ao criar o arquivo. \n");

        fprintf(arquivo, "#include <conio.h> \n#include <stdio.h> \n#include <stdlib.h> \n#include <string.h> \nchar f[15]; \nint p; \n \n");

		if (c == 1) {

            for (i = 0; i < ne; i++)
                fprintf(arquivo, "void e%d();\n", i);

            fprintf(arquivo, "void aceita(); \nvoid rejeita(); \n \nint main () { \n \n    p = 0; \n    printf(""%cLinha ?%c""); \n    gets(f); \n    e%d(); \n    return(0); \n \n} \n \n", aspas, aspas, ei);
            fprintf(arquivo, "void aceita() { \n \n    printf(""%c%cn aceita %cn%c""); \n    getch(); \n    exit(0); \n \n} \n \n", aspas, barra, barra, aspas);
            fprintf(arquivo, "void rejeita() { \n \n   printf(""%c%cn rejeita %cn%c""); \n    getch(); \n    exit(0); \n \n} \n \n", aspas, barra, barra, aspas);

            for (i = 0; i < ne; i++) {

                fprintf(arquivo, "\nvoid e%d() { \n \n", i);
                
                for (j = 0; j < ns; j++) {
					

                    if (m[i][j] != -1) {
                    	
                    	e++;
					
						for (n = 0; n < e; n++)
						fprintf(arquivo, "    ");
						
                        fprintf(arquivo, "if (f[p] == '%c') { \n \n", a[j]);
						
						for (n = 0; n < e; n++)
						fprintf(arquivo, "    ");						
						
						fprintf(arquivo, "    p++; \n");
						
						for (n = 0; n < e; n++)
						fprintf(arquivo, "        ");
						
						fprintf(arquivo, "    e%d();\n \n", m[i][j]);
						
						for (n = 0; n < e; n++)
						fprintf(arquivo, "    ");
						
						fprintf(arquivo, "} else \n");

					}
					
                }
                
                for (k = 0; k < nef; k++) {

                    if (ef[k] == i)
                    	flag = 1;

                }

                if (flag == 1 && i != 0) {
                	
                	e++;
                	
                	for (n = 0; n < e; n++)
						fprintf(arquivo, "    ");
				
                    fprintf(arquivo, "if (f[p] == '%c0') { \n \n", barra);
                    
                    for (n = 0; n < e; n++)
						fprintf(arquivo, "    ");
						
					fprintf(arquivo, "    aceita(); \n \n");
					
					for (n = 0; n < e; n++)
						fprintf(arquivo, "    ");
					
					fprintf(arquivo, "} else\n");
					
					for (n = 0; n < e; n++)
						fprintf(arquivo, "    ");
					
					fprintf(arquivo, "    rejeita();\n \n");
						
					fprintf(arquivo, "} \n");
								
					e = 0;
					
				}
				
                else {
                	
                	//e++;
                	
                	for (n = 0; n < e; n++)
						fprintf(arquivo, "    ");
                	
                    fprintf(arquivo, "    rejeita(); \n");

						
					fprintf(arquivo, "} \n");
                    				
					e = 0;

				}
				
	            flag = 0;	
				e = 0;			
				
			}

            fclose(arquivo);

		}

		if (c == 2) {

			fprintf(arquivo, "\nint main () { \n \n    p = 0; \n    printf(""%cLinha ?%c""); \n    gets(f); \n    goto e%d; \n", aspas, aspas, ei);
			
			for (i = 0; i < ne; i++) {
			
				fprintf(arquivo, "\n    e%d: \n", i);
				
				for (j = 0; j < ns; j++) {
					

                    if (m[i][j] != -1) {
                    	
                    	e++;
					
						for (n = 0; n < e; n++)
						fprintf(arquivo, "    ");
						
                        fprintf(arquivo, "if (f[p] == '%c') { \n \n", a[j]);
						
						for (n = 0; n < e; n++)
						fprintf(arquivo, "    ");						
						
						fprintf(arquivo, "        p++; \n");
						
						for (n = 0; n < e; n++)
						fprintf(arquivo, "    ");
						
						fprintf(arquivo, "    goto e%d;\n \n", m[i][j]);
						
						for (n = 0; n < e; n++)
						fprintf(arquivo, "    ");
						
						fprintf(arquivo, "} else \n");

					}
					
                }
                
                for (k = 0; k < nef; k++) {

                    if (ef[k] == i)
                    	flag = 1;

                }

                if (flag == 1 && i != 0) {
                	
                	e++;
                	
                	for (n = 0; n < e; n++)
						fprintf(arquivo, "    ");
				
                    fprintf(arquivo, "if (f[p] == '%c0') { \n \n", barra);
                    
                    for (n = 0; n < e; n++)
						fprintf(arquivo, "    ");
						
					fprintf(arquivo, "    goto aceita; \n \n");
					
					for (n = 0; n < e; n++)
						fprintf(arquivo, "    ");
					
					fprintf(arquivo, "} else\n");
					
					for (n = 0; n < e; n++)
						fprintf(arquivo, "    ");
					
					fprintf(arquivo, "    goto rejeita;\n \n");
					
					for (n = 0; n < e; n++)
						fprintf(arquivo, "    ");
								
					e = 0;
					
				}
				
                else {
                	
                	//e++;
                	
                	for (n = 0; n < e; n++)
						fprintf(arquivo, "    ");
                	
                    fprintf(arquivo, "    goto rejeita; \n");
                    
                    for (n = 0; n < e; n++)
						fprintf(arquivo, "    ");
                    				
					e = 0;

				}
				
                flag = 0;	
				e = 0;			
				
			}
			
			fprintf(arquivo, "\n    aceita:  \n        printf(""%c%cn aceita %cn%c""); \n        getch(); \n        exit(0); \n \n", aspas, barra, barra, aspas);
            fprintf(arquivo, "\n    rejeita:  \n        printf(""%c%cn rejeita %cn%c""); \n        getch(); \n        exit(0); \n \n", aspas, barra, barra, aspas);
			fprintf(arquivo, "    return(0); \n \n}");

            fclose(arquivo);

		}

		puts("\n arquivo criado com sucesso!");

	return(0);
	system("pause");
	}
