#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int flag[81];

int error(){
	printf("input Error!\n");
}

//检测当前状态下addr处是否能赋值为value
int isAlt(int* sudo, int addr, int value){
	int i = addr / 9; //所在行
	int j = addr % 9; //所在列
	int kj = ((addr % 9)/3)*3;//所在小正方形的左顶点列
	int ki = (addr / 27) * 3; //所在小正方形的左顶点行

	int tmp;
	//同一列不能有相同
	for(int ii = 0; ii < 9; ii++){
		tmp = ii < i? sudo[ii*9 + j]:flag[ii*9 + j];
		if(tmp == value){
			return 0;
		}
	}
	//同一行不能有相同
	for(int jj = 0; jj < 9; jj++){
		tmp = jj < j ? sudo[i*9 + jj]:flag[i*9 + jj];
		if(tmp == value){
			return 0;
		}
	}

	//小正方形内不能有相同
	for(int ii = ki; ii < ki + 3; ii++){
		for(int jj = kj; jj < kj + 3; jj++){
			tmp = ii*9+ jj < addr ? sudo[ii * 9 + jj]:flag[ii * 9 + jj];
			if(tmp == value){
				return 0;
			}
		}
	}

	return 1;
}

//offset之前固定，之后是否存在解
int solve(int* sudo, int offset){
	if(offset == 81){
		return 1;
	}

	int preOk = 0;
	if(flag[offset] == 0){
		for(int k = 1; k < 10; k++){
			if(isAlt(sudo, offset, k)){
				sudo[offset] = k;
				if(solve(sudo, offset+1)){
					flag[offset] = k;
					preOk = 1;
					break;
				}
			}
		}
	}else{
		if(solve(sudo, offset+1)){
			preOk = 1;
		}
	}
	return preOk;
}

void psudoku(int* sudoku){
	for(int i = 0; i < 81; i++){
		printf("%d\t", sudoku[i]);
		if(i % 3 == 2){
			printf("\t");
		}
		if(i % 9 == 8){
			printf("\n");
		}
		if(i % 27 == 26){
			printf("\n\n");
		}
	}
}

int main(int argv, char* argc[]){
	int sudo[81] = {0};
	if(argv > 82) argv = 82;
	for(int i = 0; i < argv -1; i++){
		sudo[i] = atoi(argc[i+1]);
		if(sudo[i] > 9 || sudo[i] < 0){
			error();
			exit(-1);
		}
	}

	memcpy(flag, sudo, 324);
	psudoku(flag);
	printf("***************************************************************************************\n");
	solve(sudo, 0);
	psudoku(flag);
}
