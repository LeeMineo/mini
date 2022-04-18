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
void listMenu(Menu *m, int count); // 메뉴 리스트 출력 R-1
void searchMenu(Menu *m, int count); // 제품이름 검색
int updateMenu(Menu *m); // 제품을 수정하는 함수 U
int deleteMenu(Menu *m); //제품을 삭제하는 함수 D
void saveData(Menu *m, int count); //파일저장
int loadData(Menu *s); //데이터 불러옴
int selectMenu(); // 메뉴판 프린트
int selectDataNo(Menu *s, int count);//번호가 맞는지 확인
void searchName(Menu *s, int count);// 이름 검색
