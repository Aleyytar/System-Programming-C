#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // #define INT_MIN = -2147483647-1
#include <math.h>   // -lm ile compile edilmeli veya ->  #define fmax(X,Y) ((X) > (Y) ? (X) : (Y))

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* talloc(int data) {
    struct TreeNode* newNode = (struct TreeNode*) malloc(sizeof(struct TreeNode)); // yeni node allocate et ve adresini newNode'a ata
    newNode->val = data;    // data'yı node'un value(val)'si olara ayarla
    newNode->left = NULL;   // sağ ve sol node'lar başlangıçta boş
    newNode->right = NULL;  
    return newNode;         // newNode'un adresini döndür
}


void addnode(struct TreeNode** root, int data) { // verisiyle beraber yeni node ekleme

    if (*root == NULL) {                        // geçerli node boşsa yeni node allocate et ve adresini root'a ata
        *root = talloc(data);
        return;
    }

    if ((*root)->left == NULL)                  // Değilse Soldaki node boşsa sola ekle 
        addnode(&((*root)->left), data);
        
    else if ((*root)->right == NULL)            // Değilse Sağdaki boşsa ekle
        addnode(&((*root)->right), data);       

    else                                        // Değilse (hepsi doluysa) Sol tarafa yönel 
        addnode(&((*root)->left), data); 
        
}

void preorder(struct TreeNode* root) {          // preorder: önce root, sonra sol, sonra sağ
    if (root != NULL) {
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct TreeNode* root) {           // inorder: önce sol, sonra root, sonra sağ
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

int deltree(struct TreeNode* root) {            // Tree'yi temizle
    int count = 0;
    if (root != NULL) {                         // Önce sol sonra sağ sonra current node'u temizle, her temizlemede +1 döndür
        count += deltree(root->left);
        count += deltree(root->right);
        free(root);
        count++;
    }
    return count;                               // toplam silinmiş node sayısı
}


int maxPathSumFinder(struct TreeNode* root, int* maxSum) { 
    if (root == NULL)      return 0;    // node boşsa 0 döndürür
    
    int leftSum = maxPathSumFinder(root->left, maxSum);    // nodun solundaki toplamları getirir
    int rightSum = maxPathSumFinder(root->right, maxSum);  // nodun sağındaki toplamları getirir
    int sum = leftSum + root->val + rightSum;        // sağ+sol+current node, value toplamları

    if (sum > *maxSum)     *maxSum = sum;           // önceki max'tan büyükse yeni max olarak ata
    
    return fmax(0, fmax(leftSum, rightSum) + root->val);    // sağ veya soldan büyük olanı kendinle toplayarak döndür
}

int maxPathSum(struct TreeNode* root)
{
    int maxSum = INT_MIN;    // en küçük int değeri (pathSum'larla karşılaştırma için)
    maxPathSumFinder(root,&maxSum); // karşılaştırma için maxPathSumFinder fonksiyonuna gönder 
    return maxSum;           // maxSum'ın en son değerini döndürür
}



int main() {
    struct TreeNode* root = NULL;
    addnode(&root,3);  // root
    addnode(&root,1); // sol node
    addnode(&root,0); // sağ node
    addnode(&(root->left),2);   // sol>sol
    addnode(&(root->left),8);   // sol>sağ
    addnode(&(root->right),6);  // sağ>sol 
    addnode(&(root->right),5);  // sağ>sağ
    addnode(&(root),9); // (otomatik olarak en sola eklenecek zaten.)
 /* 
level order olarak binary tree'ye eklenmiş hali:
3,1,0,2,8,6,5,9

               3
           /       \
         1           0
      /   \         /   \
     2      8     6       5
   /
  9 
  
 */

    printf("Pre-order traversal: ");
    preorder(root);
    printf("\n");

    printf("In-order traversal: ");
    inorder(root);
    printf("\n");

    printf("Max path sum: %d\n",maxPathSum(root));
    printf("%d node deleted.\n",deltree(root));

    return 0;}