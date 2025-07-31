#include <stdio.h>

#define MAX 100


struct Term {
    int coeff;  
    int power;  
};


int addPolynomials(struct Term poly1[], int n1, struct Term poly2[], int n2, struct Term result[]) {
    int i = 0, j = 0, k = 0;

   
    while (i < n1 && j < n2) {
        if (poly1[i].power == poly2[j].power) {
            result[k].power = poly1[i].power;
            result[k].coeff = poly1[i].coeff + poly2[j].coeff;
            i++; j++; k++;
        } else if (poly1[i].power > poly2[j].power) {
            result[k++] = poly1[i++];
        } else {
            result[k++] = poly2[j++];
        }
    }

    
    while (i < n1) result[k++] = poly1[i++];
    while (j < n2) result[k++] = poly2[j++];

    return k; 
}


void printPolynomial(struct Term poly[], int n) {
    for (int i = 0; i < n; i++) {
        if (poly[i].coeff != 0) {
            if (i > 0 && poly[i].coeff > 0) printf(" + ");
            if (poly[i].power == 0)
                printf("%d", poly[i].coeff);
            else if (poly[i].power == 1)
                printf("%dx", poly[i].coeff);
            else
                printf("%dx^%d", poly[i].coeff, poly[i].power);
        }
    }
    printf("\n");
}

int main() {
    struct Term poly1[MAX], poly2[MAX], result[MAX];
    int n1, n2, n3;

    
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);
    printf("Enter each term as: coefficient power\n");
    for (int i = 0; i < n1; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &poly1[i].coeff, &poly1[i].power);
    }

    
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);
    printf("Enter each term as: coefficient power\n");
    for (int i = 0; i < n2; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &poly2[i].coeff, &poly2[i].power);
    }

   
    n3 = addPolynomials(poly1, n1, poly2, n2, result);

    
    printf("\nSum of final polynomial: ");
    printPolynomial(result, n3);

    return 0;
}

