#include<iostream>
 
void dynamic_programming(int*);
using namespace std;

int main(){
    
	int table[6] = {0};
	dynamic_programming(table);
 
    int n;
	cout << "樓梯有幾階: ";
    while (cin >> n && (n >= 0 && n <= 5)){
		cout << "爬到" << n << "階，有" << table[n] << "種走法\n"
			 << "樓梯有幾階: ";
	}
	cout << "我們不爬超過5階的樓梯，去搭電梯吧~";
}

/*void dynamic_programming(int* table){
    // [Initial]
    table[0] = 1;
    table[1] = 1;
 
    // [Compute]
    for (int i=2; i<=5; i++)
        table[i] = table[i-1] + table[i-2];
}*/
void dynamic_programming(int* table)	//不好用 不直覺
{
    // [Initial]
    for (int i=0; i<=5; i++) table[i] = 0;
    table[0] = 1;
//  table[1] = 1;   // 剛好可以被算到
 
    // [Compute]
    for (int i=0; i<=5; i++)
    {
        cout << "i = " << i << endl;
		if (i+1 <= 5){	//須加上這運算，上一輪的table[i+2]才會正確
			table[i+1] += table[i];
			cout << "table[" << i+1 << "] = " << table[i+1] << "\n";
		}
			
        if (i+2 <= 5){	//本輪算出的table[i+2]是半成品，需再加上下一輪的上面那個運算
			table[i+2] += table[i];
			cout << "table[" << i+2 << "] = " << table[i+2] << "\n";
		}
    }
}