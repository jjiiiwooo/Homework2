#include <stdio.h>
#include <stdlib.h>


//링크리스트로 노드 구현
typedef struct TreeNode
{
	int data; //데이터 
	TreeNode* Left; //왼쪽자식
	TreeNode* Right; //오른쪽 자식
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

//링크 표현법 전위 순회 
void Link_preorder(TreeNode* root)
{
	if (root != NULL)
	{
		printf("%d ", root->data); //루트 순회
		Link_preorder(root->Left); // 왼쪽 트리 재귀 순회
		Link_preorder(root->Right); //오른쪽 트리 재귀 순회
	}
}

//링크 표현법 중위 순회 
void Link_inorder(TreeNode* root)
{
	if (root != NULL)
	{
		Link_inorder(root->Left); //왼쪽 트리 재귀 순회
		printf("%d ", root->data); //루트 순회
		Link_inorder(root->Right); //오른쪽 트리 재귀 순회
	}
}

//링크 표현법 후위 순회 
void Link_postorder(TreeNode* root)
{
	if (root != NULL)
	{
		Link_postorder(root->Left); //왼쪽 트리 재귀 순회
		Link_postorder(root->Right); //오른쪽 트리 재귀 순회
		printf("%d ", root->data); // 루트 순회 

	}
}

//배열 표현법 전위 순회
int Array_preorder(char ArrayTree[100], int size, int index)
{
	//뿌리 노드 출력
	if (ArrayTree[index] != NULL)
		printf("%d ", ArrayTree[index]);

	//왼쪽 자식 노드 출력 
	if (index * 2 < size)
		Array_preorder(ArrayTree, size, index * 2);

	//오른쪽 자식 노드 출력
	if ((index * 2) + 1 < size)
		Array_preorder(ArrayTree, size, (index * 2) + 1);

	return 0;
}

//배열 표현법 중위 순회
int Array_inorder(char ArrayTree[100], int size, int index)
{
	

	//왼쪽 자식 노드 출력 
	if (index * 2 < size)
		Array_inorder(ArrayTree, size, index * 2);

	//뿌리 노드 출력
	if (ArrayTree[index] != NULL)
		printf("%d ", ArrayTree[index]);

	//오른쪽 자식 노드 출력
	if ((index * 2) + 1 < size)
		Array_inorder(ArrayTree, size, (index * 2) + 1);

	return 0;
}

//배열 표현법 후위 순회
int Array_Postorder(char ArrayTree[100], int size, int index)
{
	
	//왼쪽 자식 노드 출력 
	if (index * 2 < size)
		Array_Postorder(ArrayTree, size, index * 2);

	//오른쪽 자식 노드 출력
	if ((index * 2) + 1 < size)
		Array_Postorder(ArrayTree, size, (index * 2 )+ 1);

	//뿌리 노드 출력
	if (ArrayTree[index] != NULL)
		printf("%d ", ArrayTree[index]);

	return 0;
}



int main(void)
{
	printf("<LinkList>\n");
	printf("전위 순회\n");
	Link_preorder(root);
	printf("\n\n");
	printf("중위 순회\n");
	Link_inorder(root);
	printf("\n\n");
	printf("후위 순회\n");
	Link_postorder(root);
	printf("\n\n");

	printf("<Array>\n");
	char ArrayTree[100] = {NULL,1,2,7,3,6,8,9,4,5,NULL,NULL,NULL,NULL,10,11 };
	int TreeSize = sizeof(ArrayTree) / sizeof(char);
	printf("전위 순회\n");
	Array_preorder(ArrayTree, TreeSize, ArrayTree[1]);
	printf("\n\n");
	printf("중위 순회\n");
	Array_inorder(ArrayTree, TreeSize, ArrayTree[1]);
	printf("\n\n");
	printf("후위 순회\n");
	Array_Postorder(ArrayTree, TreeSize, ArrayTree[1]);
	printf("\n\n");

}