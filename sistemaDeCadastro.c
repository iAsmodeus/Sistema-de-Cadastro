#include <stdio.h>
#include <stdlib.h>

int verificaStringVazia(char string[])
{
	if(string[0] == '\0')
	{
		return 1;
	}
	return 2;
}
int validadorDeSenha(char senha[])
{	
	int cond;
	cond = 0;
	char espec[] = "!@#$&*()/;~`{}[]/|*";

	for(int x = 0;  senha[x] != '\0'; x++)
	{	
		if(senha[x] >= 65 && senha[x] <= 90)
		{
			cond++;
			break;
		}
	}
	for(int y = 0;  senha[y] != '\0'; y++)
	{
		if(senha[y] >= 48 && senha[y] <= 57)
		{
			cond++;
			break;
		}
	}
	for(int y = 0;  senha[y] != '\0'; y++)
	{
		if(senha[y] >= 97 && senha[y] <= 122)
		{
			cond++;
			break;
		}
	}
	for(int x = 0;  senha[x] != '\0'; x++)
	{	for(int y = 0; espec [y] != '\0'; y++)
		{
			if(senha[x] == espec[y])
			{
				cond++;
				break;
			}
		}
	}
	for(int x = 0; senha[x] != '\0'; x++)
	{
		if(senha[x] >= senha[8])
		{
			cond++;
			break;
		}
	}
	if(cond != 5)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}
int main(){
	
	
	int u;
	char tentSenha[50];
	char nUsuario[50];
	nUsuario[0] = '\0';
	char pNome[50];
	char ultNome[50];
	char dtNasc[11];  
	char senha[20];
	char cpf[14];
	int x, y, z;
	char sgn = '.';
	char sgn1 = '-';
	char sgn2 = '/';
	char x1;

	printf("Bem vindo ao sitema integrado de Babilonia.\nDigite 1 para fazer seu login.\nCaso nao tenha cadastro digite 2.\nDigite 's' para cancelar\n");
	do
	{
		scanf("%c", &x1);
		if (x1 == '2')
		{
			printf("Vamos comecar seu cadastro em nosso sistema, por gentileza digite os dados solicitados abaixo.\n");
			printf("Digite seu primeiro nome.\n");
			scanf("%s", &pNome);
			printf("Digite seu sobrenome.\n");
			scanf("%s", &ultNome);
			do
			{
				printf("Agora digite seu cpf:(escreva no inserindo os pontos e o traco. Exemplo:(000.000.000-00))\n");
				scanf("%s", &cpf);
				if(cpf[3] == sgn && cpf[7] == sgn && cpf[11] == sgn1)
				{
					break;
				}
				else
				{
					printf("digite o cpf corretamente.\n");
				}
			}while(cpf[3] != sgn && cpf[7] != sgn && cpf[11] != sgn1);
			do
			{
				printf("Digite sua data de nascimento.(Digite a data inserindo as barras. Exemplo:(00/00/00000))\n");
				scanf("%s", &dtNasc);
				if(dtNasc[2] == sgn2 && dtNasc[5] == sgn2)
				{
					break;
				}
				else
				{
					printf("digite sua data de nascimento corretamente./n");
				}
			}
			while(dtNasc[2] != sgn2 && dtNasc[5] != sgn2);
			int op = 1;
			printf("digite uma senha.\n(precisa ter pelo menos 8 caracteres dentre os quais precisa haver pelo menos um caracter numerico,\n alfabetico em caixa alta, em caixa baixa e especial.\n");
			scanf("%s", senha);
			op = validadorDeSenha(senha);
			while(op == 1)
			{
				printf("digite uma senha valida\n");
				scanf("%s", senha);
				op = validadorDeSenha(senha);
			}
			printf("\aCadastro realizado com sucesso.\nAgora digite 1 para ir para a tela de login.\n");
		}
		else if(x1 == '1')
		{
			int ip;
			ip = verificaStringVazia(pNome);
			if(ip == 1)
			{
				printf("Nao ha registro no sistema. Por favor renicie o programa e faca o cadastro.\n");
				return 0;
			}
			else
			{  
				u = 0;
				do
				{
					printf("Digite seu nome e senha para acessar os dados de sua conta.\n");
					printf("Usuario\n\t--->");
					scanf("%s", &nUsuario);
					printf("Senha\n\t--->");
					scanf("%s", &tentSenha);
					for(int a = 0; nUsuario[a] != '\0'; a++ )
					{
						if(nUsuario[a] != pNome[a])
						{
							printf("Usuario ou senha invalido.\n");
						}
						else
						{
							u++;
							break;
						}
					}
					for(int a = 0; tentSenha[a] != '\0'; a++)
					{	
						if(tentSenha[a] != senha[a])
						{
							printf("Usuario ou senha invalido.\n");
						}
						else
						{
							u++;
							break;
						}
					}
				}while (u != 2);
				printf("\aBem vindo %s\nSeus dados:\n%s %s\n%s\n%s\n", nUsuario, pNome, ultNome, cpf, dtNasc);
			}
			
		}
		else
		{	
			printf("numero invalido.\n");
		}
	}
	while( x1 != '2');
	
return 0;
}
