#include<stdio.h>
#include<stdlib.h>
#include "TreeFunctions.h"

int main() {
	int choose = -10, number, number2 = 0, choose2 = -1;
	node *tree = NULL;
	//Menu
	while (choose != -1) {
		printf("\nChoose one: \n 1-)Add \n 2-)List\n 3-)Delete\n 4-)Count\n 5-)Exit\n");
		scanf_s("%d", &choose);
		switch (choose) {
		case 1:
			system("CLS");
			printf("Enter a number: ");
			scanf_s("%d", &number);
			tree = add(tree, number);
			break;
		case 2:
			system("CLS");
			printf("List\n");
			printf("2.1 - 1-) Inorder\n");
			printf("2.1 - 2-) Preorder\n");
			printf("2.1 - 3-) Postorder\n");
			scanf_s("%d", &choose2);
			if (choose2 == 1) {
				inorderLNR(tree);
				printf("\n");
				inorderRNL(tree);
			}
			if (choose2 == 2) {
				preorderNLR(tree);
				printf("\n");
				preorderNRL(tree);
			}
			if (choose2 == 3) {
				postorderLRN(tree);
				printf("\n");
				postorderRLN(tree);
			}
			break;
		case 5:
			printf("Thanks for using this program.\n");
			choose = -1;
			break;
		case 3:
			printf("Enter a value: ");
			scanf_s("%d", &number2);
			tree = deleting(tree, number2);
			inorderLNR(tree);
			break;
		case 4:
			system("CLS");
			printf("Size of binary search tree= %d\n", size(tree));
			printf("Leafs of binary search tree: ");
			printLeafNodes(tree);
			break;
		}

		system("pause");
		return 0;
	}
}