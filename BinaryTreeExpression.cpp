#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


enum OpType {
	SYMBOL, NUMBER
};

struct infonode {
	OpType type;
	union {
		int number;
		char symbol;
	};

};

struct node {
	struct infonode info;
	struct node* left;
	struct node* right;
};


struct node* newNode(infonode data) {

	struct node* node = new (struct node);

	node->left = NULL;
	node->right = NULL;
	node->info.type = data.type;
	if (node->info.type == SYMBOL) {
		node->info.symbol = data.symbol;
		printf("NO -> %c INSERIDO \n", node->info.symbol);
	} else {
		node->info.number = data.number;
		printf("NO -> %d INSERIDO \n", node->info.number);
	}
	return node;
}

bool checkInsert;

struct node* insert(struct node* node, infonode data) {

	if (node == NULL) {
		checkInsert = true;
		return (newNode(data));
	} else {
		if (node->info.type == SYMBOL) {
			printf("NO -> %c FUI PRA DIREITA \n", node->info.symbol);
			node->right = insert(node->right, data);

			if (!checkInsert) {
				printf("NO -> %c FUI PRA ESQUERDA \n", node->info.symbol);
				node->left = insert(node->left, data);
			}
		} else if (node->info.type == NUMBER) {
			printf("NO -> %d NUMBER \n", node->info.number);
		}
	}
	return node;
}


// DELETANDO  DELETANDO  DELETANDO  DELETANDO  DELETANDO  DELETANDO  DELETANDO  DELETANDO  DELETANDO

struct node* remove(struct node* node)
{
	delete node;
	node = NULL;
	return node;

}



// DELETANDO  DELETANDO  DELETANDO  DELETANDO  DELETANDO  DELETANDO  DELETANDO  DELETANDO  DELETANDO


// *********************************************opearando**********************************

int evaluate(node* node) {

	int left_val, right_val;

	if(node->info.type == NUMBER){
		return node->info.number;
	}

	else{

		left_val = evaluate(node->left);
		right_val = evaluate(node->right);

		switch(node->info.symbol){

		case '+':
			node->info.number = left_val + right_val;
			break;

		case '-':
			node->info.number = left_val - right_val;
			break;


		case '*':
			node->info.number = left_val * right_val;
			break;

		case '/':
			node->info.number = left_val / right_val;
			break;

		case'^':
			node->info.number = pow(left_val,right_val);

		}

		printf("\nO resultado eh : %d \n\n", node->info.number);

		remove(node->left);
		remove(node->right);

		return node->info.number;
	}

}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$operando$$$$$$$$$$$$$$$$$$$$$$$$

int main() {

	node* root = NULL;
	infonode data;
	int ok1 = 0, choice = 0, numOUop;

	//############################CONSTRUCAO DA ARVORE ###########################################

	do {
		printf(
				"voce quer inserir um numero ou um operador?[0-numero/1-operador]");
		scanf("%d", &numOUop);
		checkInsert = false;
		printf("CHECK INPUT %d\n", checkInsert);
		switch (numOUop) {
		case 0:
			printf("Digite o numero que voce quer botar na conta: \n");
			scanf("%d", &data.number);
			data.type = NUMBER;
			root = insert(root, data);
			break;
		case 1:
			getchar();
			printf("Digite o operador desejado: \n");
			scanf("%c", &data.symbol);
			data.type = SYMBOL;
			root = insert(root, data);
			break;
		default:
			printf("Opção errada\n");
		}

		printf("\nVoce quer inserir um novo no? [y-1/n-0]\n");
		scanf("%d", &choice);

		if (choice == 0)
			ok1++;

	} while (ok1 == 0);

	//############################ BUSCA NA ARVORE ###############################################
	//
	//	int buscaroque, bscnm, bscop, outn, outo, flag, ok2 = 0;
	//	flag = 0;
	//
	//	do {
	//		printf(
	//				"\n\nVoce quer procurar um numero ou um operador?[0-numero/1-operador]\n\n");
	//		scanf("%d", &buscaroque);
	//
	//		switch (buscaroque) {
	//		case 0:
	//			printf("\nDigite o numero que voce deseja procurar:  ");
	//			scanf("%d", &bscnm);
	//			outn = lookup(root, bscnm);
	//			if (outn)
	//				printf("o numero existe");
	//			else
	//				printf("nao ha este numero na arvore");
	//			break;
	//
	//		case 1:
	//			printf("\nDigite o operador que voce deseja procurar:  ");
	//			scanf("%d", &bscop);
	//			outo = lookup(root, bscop);
	//			if (outo)
	//				printf("existe esse operador!");
	//			else
	//				printf("nao ha este operador na arvore");
	//			break;
	//
	//		default:
	//			printf("Opcao errada, eh 1 ou 0");
	//
	//			printf("\nVoce quer procurar outro numero? [y-1/n-0]\n");
	//			scanf("%d", &flag);
	//
	//			if (flag == 0)
	//				ok2++;
	//		}
	//	} while (ok2 == 0);

	//######################################### OPERACAO ########################################

	printf("agora vai comecar a conta/operacao da arvore!\n\n");

	evaluate(root);

	return 0;
}
