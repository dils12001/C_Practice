#include<iostream>
 
void dynamic_programming(int*);
using namespace std;

int main(){
    
	int table[6] = {0};
	dynamic_programming(table);
 
    int n;
	cout << "�ӱ観�X��: ";
    while (cin >> n && (n >= 0 && n <= 5)){
		cout << "����" << n << "���A��" << table[n] << "�ب��k\n"
			 << "�ӱ観�X��: ";
	}
	cout << "�ڭ̤����W�L5�����ӱ�A�h�f�q��a~";
}

/*void dynamic_programming(int* table){
    // [Initial]
    table[0] = 1;
    table[1] = 1;
 
    // [Compute]
    for (int i=2; i<=5; i++)
        table[i] = table[i-1] + table[i-2];
}*/
void dynamic_programming(int* table)	//���n�� ����ı
{
    // [Initial]
    for (int i=0; i<=5; i++) table[i] = 0;
    table[0] = 1;
//  table[1] = 1;   // ��n�i�H�Q���
 
    // [Compute]
    for (int i=0; i<=5; i++)
    {
        cout << "i = " << i << endl;
		if (i+1 <= 5){	//���[�W�o�B��A�W�@����table[i+2]�~�|���T
			table[i+1] += table[i];
			cout << "table[" << i+1 << "] = " << table[i+1] << "\n";
		}
			
        if (i+2 <= 5){	//������X��table[i+2]�O�b���~�A�ݦA�[�W�U�@�����W�����ӹB��
			table[i+2] += table[i];
			cout << "table[" << i+2 << "] = " << table[i+2] << "\n";
		}
    }
}