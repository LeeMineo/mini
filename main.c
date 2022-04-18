#include <stdio.h>
#include <string.h>
#define SIZE 100 
#include "manager.h"


int main(void){
#ifdef DEBUG
	while(1){
		char s[100];
		printf("암호를대시오(yes):");
		scanf("%s", s);
        	if(strcmp(s, "yes")== 0){
                	printf("어서오세요 vvip손님.\n");
			break;
		}
        	else
                	printf("비밀번호가 틀렸습니다.\n");
	}

#endif
    Menu slist[100];
    int index =0;
    int count = 0, menu;
    int result = 0;

    count = loadData(slist);
    index = count;
 
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1 || menu == 3 ||menu == 4)
            if(count == 0) continue;
        if (menu == 1){
            if(count>0){
                listMenu(slist, index);
            }
        }
        else if (menu == 2){
            count += createMenu(&slist[index++]);
            }
        else if (menu == 3){
            int no = selectDataNo(slist, index);
            if(no == 0){
                printf("-->취소되었음!\n");
                continue;
            }
            updateMenu(&slist[no-1]);

            }
        else if (menu == 4){
            int no = selectDataNo(slist, index);
            if(no == 0){
                printf("-->취소되었음\n");
                continue;
            }
            int delete_ok;
            printf("정말로 삭제하시겠습니까?(삭제 :1)");
            scanf("%d", &delete_ok);
            if(delete_ok == 1){
                if(deleteMenu(&slist[no-1])) count--;
            }
        }
        else if(menu == 5){
            saveData(slist, index);
        }
        else if(menu == 6){
            searchName(slist, index);
        }
    }
    printf("종료되었습니다.!\n");
    return 0;
}
