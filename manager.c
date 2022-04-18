#include "manager.h"
int selectMenu(){
    int menu;
    printf("\n*** The Witch's Shop ***\n");
    printf("1. 메뉴조회\n");
    printf("2. 메뉴추가\n");
    printf("3. 메뉴수정\n");
    printf("4. 메뉴삭제\n");
    printf("5. 파일저장\n");
    printf("6. 이름검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
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
void saveData(Menu *m, int count)
{
    FILE *fp;
    fp = fopen("Product.txt", "wt");

    for(int i =0; i < count; i++){
        if(m[i].price == -1) continue;
    //    fprintf(fp,"제품명:%s\n제품설명:%s\n제품량:%s\n제품가격:%d만원\n배송방법(1:새벽배송 /2:택배배송):%d\n"
    //,m[i].name,m[i].ex,m[i].weight,m[i].price,m[i].method);
        
        fprintf(fp,"%s\n", m[i].name);
        fprintf(fp,"%s\n",m[i].ex);
        fprintf(fp,"%s\n",m[i].weight);
        fprintf(fp,"%d\n",m[i].price);
        fprintf(fp,"%d",m[i].method);
    
    }
    fclose(fp);
    printf("=> 저장됨!\n");
}
int loadData(Menu *m){
    int count = 0, i = 0;
    FILE *fp;
    if (fp = fopen("Product.txt", "rt")){
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
void searchName(Menu *m, int count){
    int scnt = 0;
    char search[20];
    
    getchar();
    printf("검색할 이름?:");
    fgets(search,255,stdin);
    search[strlen(search)-1] = '\0';

    printf("\n*****************\n");
    for(int i=0; i < count; i++){
        if(m[i].price == -1) continue;
        if(strstr(m[i].name, search)){
            printf("      <%2d번>\n", i+1);
            readMenu(m[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}

