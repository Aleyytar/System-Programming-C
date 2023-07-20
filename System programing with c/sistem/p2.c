#include <stdio.h>

int largestRectangleArea(int *heights, int heightsSize){ 
    int maxArea = 0, min=0;
    int area= 0;
    int N;
    for ( N = 1; N <= heightsSize; N++) { // 1'den heightsSize'a kadar kontrol edilecek alt dizi eleman sayıları 
        
        int i;
        for (i = 0; i <= (heightsSize - N); i++) { // i'den başlayarak heights dizisindeki her alt dizi
            min = heights[i];
            int j;
            for ( j = i + 1; j < i + N; j++) // alt dizinin en küçük elemanını bulma 
                if (heights[j] < min) 
                    min = heights[j];
                
            area = min * N; // en küçük sayı ile alt dizi boyutu(N) çarpımıyla bulunan altdizindeki area(alan) 
            if (area > maxArea) // önceki max alanlar ile karşılaştırma
                maxArea = area; // yeni maxArea
            
        }
    }
    return maxArea; // en büyük alan değeri 
}

int main() {
    int arr[] = {2,1,5,6,2,3};
    int size = sizeof(arr) / sizeof(int); // heightsSize 
    int max = largestRectangleArea(arr, size); 
    printf("Maximum value: %d\n", max);
    return 0;
}
