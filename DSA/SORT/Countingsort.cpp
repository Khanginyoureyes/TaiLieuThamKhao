#include<iostream>
using namespace std;
const int MAXN = 1e6;

int n, minn = MAXN, maxx = -MAXN;
int a[MAXN], b[MAXN];
void Input(){
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
        
        if(minn > a[i]) 
            minn = a[i];
            
        if(maxx < a[i])
            maxx = a[i];
    }
}

void Counting1(){
    int c[maxx + 1]; 
    
	for(int i = 0; i <= maxx; i++){
		c[i] = 0;
	}
	
	for(int i = 0; i < n; i++){
		c[a[i]]++;
	}
	
	int j = 0;
	for(int i = 0; i <= maxx; i++){
		while(c[i]--){
			b[j++] = i;
		}
	}
}


void Counting2(){
    int mapping = -minn;
    
    for(int i = 0; i < n; i++)
        a[i] += mapping;
    
    maxx += mapping;
    
    int c[maxx + 1]; 
    
	for(int i = 0; i <= maxx; i++){
		c[i] = 0;
	}
	
	for(int i = 0; i < n; i++){
		c[a[i]]++;
	}
	
	int j = 0;
	for(int i = 0; i <= maxx; i++){
		while(c[i]--){
			b[j++] = i - mapping;
		}
	}
}

void Output(){
    for(int i = 0; i < n; i++)
        cout << b[i] << " ";
}
int main(){
    Input();
    
    if(minn < 0)
        Counting2();
    else
        Counting1();
        
    Output();
    
    return 0;
}