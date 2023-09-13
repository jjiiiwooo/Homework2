#include <stdio.h>
#include <stdlib.h>


//��ũ����Ʈ�� ��� ����
typedef struct TreeNode
{
	int data; //������ 
	TreeNode* Left; //�����ڽ�
	TreeNode* Right; //������ �ڽ�
}TreeNode;

TreeNode n1 = { 4, NULL,NULL };
TreeNode n2 = { 5, NULL,NULL };
TreeNode n3 = { 3, &n1,&n2 };
TreeNode n4 = { 6, NULL,NULL };
TreeNode n5 = { 2, &n3, &n4 };
TreeNode n6 = { 10, NULL,NULL };
TreeNode n7 = { 11, NULL,NULL };
TreeNode n8 = { 9, &n6, &n7 };
TreeNode n9 = { 8, NULL,NULL };
TreeNode n10 = { 7, &n9,&n8 };
TreeNode n11 = { 1, &n5 ,&n10 };
TreeNode* root = &n11;

//��ũ ǥ���� ���� ��ȸ 
void Link_preorder(TreeNode* root)
{
	if (root != NULL)
	{
		printf("%d ", root->data); //��Ʈ ��ȸ
		Link_preorder(root->Left); // ���� Ʈ�� ��� ��ȸ
		Link_preorder(root->Right); //������ Ʈ�� ��� ��ȸ
	}
}

//��ũ ǥ���� ���� ��ȸ 
void Link_inorder(TreeNode* root)
{
	if (root != NULL)
	{
		Link_inorder(root->Left); //���� Ʈ�� ��� ��ȸ
		printf("%d ", root->data); //��Ʈ ��ȸ
		Link_inorder(root->Right); //������ Ʈ�� ��� ��ȸ
	}
}

//��ũ ǥ���� ���� ��ȸ 
void Link_postorder(TreeNode* root)
{
	if (root != NULL)
	{
		Link_postorder(root->Left); //���� Ʈ�� ��� ��ȸ
		Link_postorder(root->Right); //������ Ʈ�� ��� ��ȸ
		printf("%d ", root->data); // ��Ʈ ��ȸ 

	}
}

//�迭 ǥ���� ���� ��ȸ
int Array_preorder(char ArrayTree[100], int size, int index)
{
	//�Ѹ� ��� ���
	if (ArrayTree[index] != NULL)
		printf("%d ", ArrayTree[index]);

	//���� �ڽ� ��� ��� 
	if (index * 2 < size)
		Array_preorder(ArrayTree, size, index * 2);

	//������ �ڽ� ��� ���
	if ((index * 2) + 1 < size)
		Array_preorder(ArrayTree, size, (index * 2) + 1);

	return 0;
}

//�迭 ǥ���� ���� ��ȸ
int Array_inorder(char ArrayTree[100], int size, int index)
{
	

	//���� �ڽ� ��� ��� 
	if (index * 2 < size)
		Array_inorder(ArrayTree, size, index * 2);

	//�Ѹ� ��� ���
	if (ArrayTree[index] != NULL)
		printf("%d ", ArrayTree[index]);

	//������ �ڽ� ��� ���
	if ((index * 2) + 1 < size)
		Array_inorder(ArrayTree, size, (index * 2) + 1);

	return 0;
}

//�迭 ǥ���� ���� ��ȸ
int Array_Postorder(char ArrayTree[100], int size, int index)
{
	
	//���� �ڽ� ��� ��� 
	if (index * 2 < size)
		Array_Postorder(ArrayTree, size, index * 2);

	//������ �ڽ� ��� ���
	if ((index * 2) + 1 < size)
		Array_Postorder(ArrayTree, size, (index * 2 )+ 1);

	//�Ѹ� ��� ���
	if (ArrayTree[index] != NULL)
		printf("%d ", ArrayTree[index]);

	return 0;
}



int main(void)
{
	printf("<LinkList>\n");
	printf("���� ��ȸ\n");
	Link_preorder(root);
	printf("\n\n");
	printf("���� ��ȸ\n");
	Link_inorder(root);
	printf("\n\n");
	printf("���� ��ȸ\n");
	Link_postorder(root);
	printf("\n\n");

	printf("<Array>\n");
	char ArrayTree[100] = {NULL,1,2,7,3,6,8,9,4,5,NULL,NULL,NULL,NULL,10,11 };
	int TreeSize = sizeof(ArrayTree) / sizeof(char);
	printf("���� ��ȸ\n");
	Array_preorder(ArrayTree, TreeSize, ArrayTree[1]);
	printf("\n\n");
	printf("���� ��ȸ\n");
	Array_inorder(ArrayTree, TreeSize, ArrayTree[1]);
	printf("\n\n");
	printf("���� ��ȸ\n");
	Array_Postorder(ArrayTree, TreeSize, ArrayTree[1]);
	printf("\n\n");

}