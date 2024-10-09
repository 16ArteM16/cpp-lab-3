#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

int main(){
    cout<<"Введите число чашек:";
    int n;
    cin>>n;
    int macca[32];
    int totalsum=0;

    cout<<"Введите массы чашечек:";
    for (int i=0; i<n; i++){
        cin>>macca[i];
        totalsum+=macca[i];
    }
    clock_t start= clock();
    int minraz=totalsum; //Минимальную разницу приравниваем сразу к общей сумме
    int maxmask=0;
    for (int i=0;i<n;i++){ // Вычисляем максимальную маски <==> Будет являться максимальным количеством решений
        maxmask=(maxmask<<1)|1;
    }
    for (int mask =0; mask<=maxmask;mask++){
        int summ1=0; // Сумму в 1-ой группе
        for(int i=0;i<n;i++){
            if (mask&(1<<i)){
                summ1+=macca[i];
            }
        }
        int summ2=0; // Сумма во 2-ой группе
        summ2=totalsum-summ1;
        minraz=min(minraz,abs(summ1-summ2));

    }
    clock_t end=clock();
    cout<<"Минимальная разница:"<<minraz<<endl;
    double time_lab2 = double(end - start) / CLOCKS_PER_SEC;
    cout<<fixed<<setprecision(30);
    cout<<"Время выполнения: "<<time_lab2;
    return 0;
}