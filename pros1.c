#include<stdio.h>
#include<math.h>

int main(){

    int pairs;
    float numbers[15] = {};
    int wages[15] = {};
    
    printf("Insert amount of pairs: ");
    scanf("%d", &pairs);
    //if(pairs < 0 && pairs > 15){
    //    return -1;
    //}

    for ( int i = 0; i < pairs; i++){
        printf("Input floating number for pair number %d: ", i+1);
        scanf("%f", &numbers[i]);
        printf("Input wage for number %f: ", numbers[i]);
        scanf("%d", &wages[i]);
    }
        // Variables used to calculate the 
    float licznik1 = 0;
    float mianownik1 = 0;
    float geometric_mean;
    float licznik2 = 0;
    float mianownik2 = 0;
    float srednia_harmoniczna;
    float licznik3 = 0;
    float mianownik3 = 0;
    float srednia_potegowa;
    int power;
    printf("Declare the power of the ... mean");
    scanf("%d", &power);
    
    for ( int i = 0; i< pairs; i++){
            //Geometric mean
        licznik1 += wages[i]*log(numbers[i]);
        mianownik1 += wages[i];
            //Średnia harmoniczna
        licznik2 += wages[i];
        mianownik2 += wages[i]/numbers[i];
            //Średnia potęgowa
        licznik3 += wages[i]*(pow(numbers[i],power));
        mianownik3 += wages[i];
    }
    geometric_mean = exp(licznik1/mianownik1);
    srednia_harmoniczna = licznik2/mianownik2;
    srednia_potegowa = pow(licznik3/mianownik3, 1/power);
    printf("Srednia geometryczna: %f\n", geometric_mean);
    printf("Srednia harmoniczna: %f\n", srednia_harmoniczna);
    printf("Średnia potęgowa: %f\n", srednia_potegowa);
    return 0;
}
