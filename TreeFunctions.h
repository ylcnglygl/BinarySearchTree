#pragma once
#include<stdlib.h>
#include<stdio.h>
struct n {
	int data;
	n * left;
	n * right;
};
typedef n node;
//Node oluşturuluyor
node* add(node *tree, int x) {
	if (tree == NULL) {
		node *root = (node *)malloc(sizeof(node));
		root->left = NULL;
		root->right = NULL;
		root->data = x;
		return root;
	}

	if (tree->data <= x) {
		tree->right = add(tree->right, x);
		return tree;
	}
	tree->left = add(tree->left, x);
	return tree;
}
//Sol - Düğüm - Sağ
void inorderLNR(node *tree) {
	if (tree == NULL)
		return;
	inorderLNR(tree->left);
	printf("%d ", tree->data);
	inorderLNR(tree->right);
}
//Sağ - Düğüm - Sağ
void inorderRNL(node *tree) {
	if (tree == NULL)
		return;
	inorderRNL(tree->right);
	printf("%d ", tree->data);
	inorderRNL(tree->left);
}
//Düğüm - Sol - Sağ
void preorderNLR(node *tree) {
	if (tree == NULL)
		return;
	printf("%d ", tree->data);
	preorderNLR(tree->left);
	preorderNLR(tree->right);
}
//Düğüm - Sağ - Sol
void preorderNRL(node *tree) {
	if (tree == NULL)
		return;
	printf("%d ", tree->data);
	preorderNRL(tree->right);
	preorderNRL(tree->left);
}
//Sol - Sağ - Düğüm
void postorderLRN(node *tree) {
	if (tree == NULL)
		return;
	postorderLRN(tree->left);
	postorderLRN(tree->right);
	printf("%d ", tree->data);

}
//Sağ - Sol - Düğüm
void postorderRLN(node *tree) {
	if (tree == NULL)
		return;
	postorderRLN(tree->right);
	postorderRLN(tree->left);
	printf("%d ", tree->data);
}
//Maximum değeri bulan fonksiyon
int max(node *tree) {
	while (tree->right != NULL)
		tree = tree->right;
	return tree->data;
}
//Minimum değeri bulan fonksiyon
int min(node *tree) {
	while (tree->left != NULL)
		tree = tree->left;
	return tree->data;
}
//Silme işlemi yapan fonksiyon
node *deleting(node *tree, int x) {
	if (tree == NULL)
		return NULL;
	if (tree->data == x) {
		if (tree->left == NULL && tree->right == NULL)
			return NULL;
		if (tree->right != NULL) {
			tree->data = min(tree->right);
			tree->right = deleting(tree->right, min(tree->right));
			return tree;
		}
		tree->data = max(tree->left);
		tree->left = deleting(tree->left, max(tree->left));
		return tree;
	}
	if (tree->data < x) {
		tree->right = deleting(tree->right, x);
		return tree;
	}
	tree->left = deleting(tree->left, x);
	return tree;
}
//Ağacın boyutunu döndüren fonksiyon
int size(node *tree) {
	if (tree != NULL)
		return(size(tree->left) + 1 + size(tree->right));
	else
		return 0;
}
//Yaprak düğümlerini yazdıran fonksiyon
void printLeafNodes(node *root)
{
	if (root == NULL)
		return;
	if (root->left != NULL && root->right != NULL)
	{
		printf("%d	", root->data);
	}

	if (root->left != NULL)
		printLeafNodes(root->left);
	if (root->right != NULL)
		printLeafNodes(root->right);
}
