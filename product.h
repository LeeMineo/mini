#include <stdio.h>
#include <string.h>
#define SIZE 100 

typedef struct{
     char name[SIZE]; // 제품명
     char ex[SIZE]; //설명
     char weight[SIZE]; //중량
     int price; // 가격
     int method; //배송방법
} Menu;

int createMenu(Menu *m); // 제품을 추가하는 함수 C

void readMenu(Menu m); // 전체 등록된 제품 리스트 출력 R-2

void searchMenu(Menu *m, int count); // 제품이름 검색

int updateMenu(Menu *m); // 제품을 수정하는 함수 U

int deleteMenu(Menu *m); //제품을 삭제하는 함수 D

int buyMenu(Menu *m); // 제품 구매

void saveData(Menu m); //파일저장

int loadData(Menu *s); //데이터 불러옴
