#include <iostream>
using namespace std;

void set_array(int *p, int n){
    for(int i=0; i<n ; i++){
        cout << i << "번째 정수";
        cin >> p[i];
    }
}

int get_sum(int *p, int n){
    int sum = 0;
    for(int i=0; i<n ; i++){
        sum += p[i];
    }
    return sum;
}

int main(){
    cout << "입력 할 정수 개수 : ";
    int n;
    cin >> n;
    if(n<=0) return 0;
    int *p = new int[n];
    if(!p){
        cout << "ERROR!";
        return 0;
    }

    set_array(p, n);
    int sum = get_sum(p, n);
    cout << "합 : " << sum << " 평균 : " << sum/n << endl;

    delete [] p;
    return 0;
}
