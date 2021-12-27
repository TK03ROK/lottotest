#include <stdio.h>

#include <stdlib.h>

#include <time.h>

int main()

{

    int i, i1, i2, i3, i4, i5, Ly, Ld, Lm, Cy, Cm, Cd, yc;

    int l, k, j, lot = 0, line, a[7] = {}, check, demand[7], demand_num = 0, show[7], omitted_num = 0, omitted[7], out, in;

    srand(time(NULL));//이게 추첨기의 기본함수 현재 컴퓨터 시간으로 샛을 맞춰서 항상 새로운 수열들이 srand에 나오게된다네

    printf("##LOTTO PRINTER##\n0 = 공백\n-1 = 줄 개수로 돌아기기\n-2 = 넣어야하는것으로 돌아가기\n-3 = 빼야되는 것으로 돌아가기\n");//요건 공지사항

BACK1:

    line = 0;

    printf("줄 갯수 : ");//라인 갯수로 5줄이나 아니면 더 많은 줄이 나오게 해주는것

    scanf("%d", &line);

    if(line == -1) {

        goto BACK1;

    }

BACK2:

    for(i = 0; i < 6; i++) { //demand 리스트 0을 채움

        demand[i] = 0;

    }

    printf("연도 수정치를 사용하겠습니까? : ");

    scanf("%d", &yc);

    if(yc == 1)

    {

    printf("로또 년도 : ");

    scanf("%d", &Ly);

      scanf("%d", &Ld);

      scanf("%d", &Lm);

      printf("개년 : ");

      scanf("%d", &Cy);

      scanf("%d", &Cm);

      printf("개인 날짜 : ");

      scanf("%d", &Cd);

    }

    for(i = 0; i < 6; i++)

    {

        printf("넣어야 하는 숫자 : ");//이제 demand리스트 쓸꺼

        scanf("%d", &in);//제시문 다음에 나오는거 인식

        if(in == -2) {

            goto BACK2;

        }

        if(in == -1) {

            goto BACK1;

        }

        if(in > 45) {

            printf("로또번호에서 나올 수 있는 숫자 이상을 입력하셨습니다. 처음으로 돌아갑니다\n");

            goto BACK2;

        }

        if(in != 0) {

            demand[i] = in;//0이 아니면 넣고

        }

        else break;//0이면 인식 종료(방금 공지사항 넣은 이유임)

    } // 여까지는 문제 없음 -> 요렇게 오류 생기면 메모하면서 점검함 ㅇㅇ

    for(i = 0; i < 6; i++)//demand리스트에 올라간거 갯수 새서 demand_num 에 넣어주는거, 이거는 하다보니 필요해져서 만듬

    {

        if(demand[i] > 0)//0이면 끝내게 이럴려고 위에 demand 리스트에 0을 채움

        {

            demand_num = demand_num + 1;

        }

        else break;

    }

BACK3:

    for(i = 0; i < 6; i++) { //demand 리스트 0을 채움

        omitted[i] = 0;

    }

    for(i = 0; i < 47; i++)//요거는 싫어하는 숫자들. 여기에 만약 좋아하는거 같이 넣었어도 C언어 특성상 위에명령 먼저해서 오류는 안 나는듯

    {

        printf("빼야하는 숫자 : ");

        scanf("%d", &out);

        if(out == -3) {

            goto BACK3;

        }

        if(out == -2) {

            goto BACK2;

        }

        if(in == -1) {

            goto BACK1;

        }

        if(out == 0) {

            break;

        }

        for(k = 0; k < 6; k++) {

            if(demand[k] == out) {

                printf("공통된 숫자를 넣을 순 없습니다. 처음으로 돌아갑니다\n");

                goto BACK3;

            }

            else {

                if(out != 0) { //omitted리스트에 넣었음

                    omitted[i] = out;

                }

            }

        }

    }

    printf("와! 당첨각~!\n");//요기서 부터 진또배기임 이게 번호 출력하는 과정

    for(i = 0; i < line; i++)//라인 갯수에 따라 요 아래과정이 반복되며 출력

    {

        check = 0;//체크가 내 코드엔 중요한 역할임 라인 만들때마다 필요해서 맨 처음으로 0으로 셋팅

        for(i2 = 0; i2 < demand_num; i2++)

        {

            if(demand != 0)//요건 demand 갯수만큼 나중에 출력할 show라는 리스트에 demand 번호들을 넣어주는거

            {

                show[i2] = demand[i2];

            }

        }

        for(i2 = 0; i2 < 6; i2++)

        {

            a[i2] = "";//a라는 리스트를 부가적으로 쓸건데 얘를 비워주는거

        }

        for (i2 = 0; i2 < 6 - demand_num; i2++)//demand_num이 필요한 이유가 원래 있었던걸 덮어씌우면 안되서 그놈들 빼려고 뺀 만큼 돌리는것

        {

            check = 0;//이거는 하나의 숫자 넣을때마다 다 필요해서 맨 처음으로 0으로 셋팅

            lot = (rand() % 45) + 1;//요개 핵심함수중 하나임 45미만의 숫자에서 랜덤으로 뽑고  거기서 1 더해서(0도 출혁되서 그럼) lot에 넣어줌

            a[i2] = lot;//이 lot는 a라는 리스트에 들어가는거고

            for(k = 0; k < 6; k++)

            {

                if(lot == a[k])//만약 lot가 a라는 리스트에 이미 있으면

                {

                    check = check + 1;//check 올리고

                }

            }

            for(i3 = 0; i3 < demand_num; i3++)

            {

                if(lot == demand[i3])//demand에 check가 있으면 올리고

                {

                    check = check + 1;

                }

            }

            for(k = 0; k < 6; k++)

            {

                if(lot == omitted[k])//뺀거에 있으면 check 있으면 올리고

                {

                    check = check + 1;

                }

            }

            if(check < 2) //위 과정에 안 걸리면 show리스트에 넣어주고

            {

                show[5 - i2] = lot;

            }

            else//아니면 i2(돌린 횃수)를 올렸던걸 다시 내람 = 한번 더해

            {

                i2 = i2 - 1;

            }

        }

        for(j = 2; j < 47; j++)

        {

            for(k = 0; k < 6; k++)

            {

                if(show[k] < j)//요 과정은 리스트 크기 순서되로 정리하려고 만든 과정임

                {

                if(show[k]>0){

                    if(show[k]<10) {

                        printf(" %d ", show[k]);

                    }

                    else printf("%d ", show[k]);

                    show[k] = "";

                  }

                }

            }

        }

        printf("\n");//다 되면 한줄 띄우고 새 줄 뽑고 ㅇㅇ

    }

    system("pause");

    return 0;
}