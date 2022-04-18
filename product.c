#include <stdio.h>
#include <string.h>
#define SIZE 100
#include "product.h"

int selectMenu(){
    int menu;
    printf("\n*** The Witch's Shop ***\n");
    printf("1. 메뉴조회\n");
    printf("2. 메뉴추가\n");
    printf("3. 메뉴수정\n");
    printf("4. 메뉴삭제\n");
    printf("5. 파일저장\n");
    printf("6. 제품구매하기\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}
int main(void){
    Menu s;
    int index =0;
    int count = 0, menu;
    int result = 0;

    count = loadData(&s);
    //index = count;
    //loadData(&s);
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1 || menu == 3 ||menu == 4)
            if(count == 0) continue;
        if (menu == 1){
            if(count>0){
                readMenu(s);
            }
        }
        else if (menu == 2){
            result =  createMenu(&s);
            count++;
            }
        else if (menu == 3){
            updateMenu(&s);
            }
        else if (menu == 4){
            int delete_ok;
            printf("정말로 삭제하시겠습니까?(삭제 :1)");
            scanf("%d", &delete_ok);
            if(delete_ok == 1){
                if(deleteMenu(&s)) count--;
            }
        }
        else if(menu == 5){
            saveData(s);
        }
        else if(menu == 6){
            int buy_ok;
            printf("정말로 구매하시겠습니까?(구매 :1)");
            scanf("%d", &buy_ok);
            if(buy_ok == 1){
                if(buyMenu(&s)) count--;
            }

            //searchName(slist, index);
        }
    }
    printf("종료됨!\n");
    return 0;
}

int createMenu(Menu *m){
    getchar();
    printf("제품명은?:");
    fgets(m->name,255,stdin);
    m->name[strlen(m->name)-1] = '\0';

    printf("제품설명은?:");
    fgets(m->ex,255,stdin);
    m->ex[strlen(m->ex)-1] = '\0';

    printf("제품중량은?:");
    fgets(m->weight,255,stdin);
    m->weight[strlen(m->weight)-1] = '\0';

    printf("가격은?(백만단위):");
    scanf("%d", &m->price);


    printf("배송방법은?(1:새벽배송 /2:택배배송) :");
    scanf("%d", &m->method);

    return 1;
}
void listMenu(Menu *m, int count){
    printf("*****************\n");
    for(int i=0; i<count; i++){
        if(m[i].price == -1){continue;}
        printf("      <%2d번>\n", i+1);
        readMenu(m[i]);

    }
}
void readMenu(Menu m){
    //int count = 1;
    printf("제품명:%s\n제품설명:%s\n제품량:%s\n제품가격:%d만원\n배송방법(1:새벽배송 /2:택배배송):%d\n"
    ,m.name,m.ex,m.weight,m.price,m.method);
}
int selectDataNo(Menu *m, int count){
    int no;
    listMenu(m, count);
    printf("\n번호는 (취소 :0)?");
    scanf("%d", &no);
    return no;
}
int updateMenu(Menu *m){
    getchar();
    printf("새제품명은?:");
    fgets(m->name,255,stdin);
    m->name[strlen(m->name)-1] = '\0';

    printf("새제품설명은?:");
    fgets(m->ex,255,stdin);
    m->ex[strlen(m->ex)-1] = '\0';

    printf("새제품중량은?:");
    fgets(m->weight,255,stdin);
    m->weight[strlen(m->weight)-1] = '\0';

    printf("새가격은?(백만단위):");
    scanf("%d", &m->price);

    printf("새배송방법은?(1:새벽배송 /2:택배배송) :");
    scanf("%d", &m->method);

    return 1;
}
int deleteMenu(Menu *m){
    m->price = -1;
    printf("--> 삭제됨!\n");
    return 1;
}
int buyMenu(Menu *m){
    m->price = -1;
    printf("--> 구매완료!\n");
    return 1;
}
void saveData(Menu m)
{
    FILE *fp;
    fp = fopen("Pro.txt", "wt");

    //for(int i =0; i < count; i++){
    //    if(m[i].price == -1) continue;
    //    fprintf(fp,"제품명:%s\n제품설명:%s\n제품량:%s\n제품가격:%d만원\n배송방법(1:새벽배송 /2:택배배송):%d\n"
    //,m[i].name,m[i].ex,m[i].weight,m[i].price,m[i].method);

    fprintf(fp,"%s\n", m.name);
    fprintf(fp,"%s\n",m.ex);
    fprintf(fp,"%s\n",m.weight);
    fprintf(fp,"%d\n",m.price);
    fprintf(fp,"%d",m.method);

    //}
    fclose(fp);
    printf("=> 저장됨!\n");
}
int loadData(Menu *m){
    int count = 0, i = 0;
    FILE *fp;
    if (fp = fopen("Pro.txt", "rt")){
        for(; i<100; i++){
            fgets(m[i].name,255, fp);
            m[i].name[strlen(m[i].name)-1] = '\0';
            if(feof(fp)) break;

            fgets(m[i].ex,255, fp);
            m[i].ex[strlen(m[i].ex)-1] = '\0';
            if(feof(fp)) break;

            fgets(m[i].weight,255, fp);
            m[i].weight[strlen(m[i].weight)-1] = '\0';
            if(feof(fp)) break;

            fscanf(fp, "%d", &m[i].price);
            if(feof(fp)) break;

            fscanf(fp, "%d", &m[i].method);
            //if(feof(fp)) break;


        }
        fclose(fp);
        printf("\n=> 로딩 성공!\n");
    }else{
        printf("\n=> 파일 없음...\n");
    }

    return i;
}
