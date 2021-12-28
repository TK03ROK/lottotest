#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //show me the why!

    int i, i1, i2, i3, i4, i5, Ly, Ld, Lm, Cy, Cm, Cd, yc;

    int l, k, j, lot = 0, line, a[7] = {}, check, demand[7], demand_num = 0, show[7], omitted_num = 0, omitted[7], out, in;

    srand(time(NULL));//�̰� ��÷���� �⺻�Լ� ���� ��ǻ�� �ð����� ���� ���缭 �׻� ���ο� �������� srand�� �����Եȴٳ�

    printf("##LOTTO PRINTER##\n0 = ����\n-1 = �� ������ ���Ʊ��\n-2 = �־���ϴ°����� ���ư���\n-3 = ���ߵǴ� ������ ���ư���\n");//��� ��������

BACK1:

    line = 0;

    printf("�� ���� : ");//���� ������ 5���̳� �ƴϸ� �� ���� ���� ������ ���ִ°�

    scanf("%d", &line);

    if(line == -1) {

        goto BACK1;

    }

BACK2:

    for(i = 0; i < 6; i++) { //demand ����Ʈ 0�� ä��

        demand[i] = 0;

    }

    printf("���� ����ġ�� ����ϰڽ��ϱ�? : ");

    scanf("%d", &yc);

    if(yc == 1)

    {

    printf("�ζ� �⵵ : ");

    scanf("%d", &Ly);

      scanf("%d", &Ld);

      scanf("%d", &Lm);

      printf("���� : ");

      scanf("%d", &Cy);

      scanf("%d", &Cm);

      printf("���� ��¥ : ");

      scanf("%d", &Cd);

    }

    for(i = 0; i < 6; i++)

    {

        printf("�־�� �ϴ� ���� : ");//���� demand����Ʈ ����

        scanf("%d", &in);//���ù� ������ �����°� �ν�

        if(in == -2) {

            goto BACK2;

        }

        if(in == -1) {

            goto BACK1;

        }

        if(in > 45) {

            printf("�ζǹ�ȣ���� ���� �� �ִ� ���� �̻��� �Է��ϼ̽��ϴ�. ó������ ���ư��ϴ�\n");

            goto BACK2;

        }

        if(in != 0) {

            demand[i] = in;//0�� �ƴϸ� �ְ�

        }

        else break;//0�̸� �ν� ����(��� �������� ���� ������)

    } // �������� ���� ���� -> �䷸�� ���� ����� �޸��ϸ鼭 ������ ����

    for(i = 0; i < 6; i++)//demand����Ʈ�� �ö󰣰� ���� ���� demand_num �� �־��ִ°�, �̰Ŵ� �ϴٺ��� �ʿ������� ����

    {

        if(demand[i] > 0)//0�̸� ������ �̷����� ���� demand ����Ʈ�� 0�� ä��

        {

            demand_num = demand_num + 1;

        }

        else break;

    }

BACK3:

    for(i = 0; i < 6; i++) { //demand ����Ʈ 0�� ä��

        omitted[i] = 0;

    }

    for(i = 0; i < 47; i++)//��Ŵ� �Ⱦ��ϴ� ���ڵ�. ���⿡ ���� �����ϴ°� ���� �־�� C��� Ư���� �������� �����ؼ� ������ �� ���µ�

    {

        printf("�����ϴ� ���� : ");

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

                printf("����� ���ڸ� ���� �� �����ϴ�. ó������ ���ư��ϴ�\n");

                goto BACK3;

            }

            else {

                if(out != 0) { //omitted����Ʈ�� �־���

                    omitted[i] = out;

                }

            }

        }

    }

    printf("��! ��÷��~!\n");//��⼭ ���� ���ǹ���� �̰� ��ȣ ����ϴ� ����

    for(i = 0; i < line; i++)//���� ������ ���� �� �Ʒ������� �ݺ��Ǹ� ���

    {

        check = 0;//üũ�� �� �ڵ忣 �߿��� ������ ���� ���鶧���� �ʿ��ؼ� �� ó������ 0���� ����

        for(i2 = 0; i2 < demand_num; i2++)

        {

            if(demand != 0)//��� demand ������ŭ ���߿� ����� show��� ����Ʈ�� demand ��ȣ���� �־��ִ°�

            {

                show[i2] = demand[i2];

            }

        }

        for(i2 = 0; i2 < 6; i2++)

        {

            a[i2] = "";//a��� ����Ʈ�� �ΰ������� ���ǵ� �긦 ����ִ°�

        }

        for (i2 = 0; i2 < 6 - demand_num; i2++)//demand_num�� �ʿ��� ������ ���� �־����� ������ �ȵǼ� �׳�� ������ �� ��ŭ �����°�

        {

            check = 0;//�̰Ŵ� �ϳ��� ���� ���������� �� �ʿ��ؼ� �� ó������ 0���� ����

            lot = (rand() % 45) + 1;//�䰳 �ٽ��Լ��� �ϳ��� 45�̸��� ���ڿ��� �������� �̰�  �ű⼭ 1 ���ؼ�(0�� �����Ǽ� �׷�) lot�� �־���

            a[i2] = lot;//�� lot�� a��� ����Ʈ�� ���°Ű�

            for(k = 0; k < 6; k++)

            {

                if(lot == a[k])//���� lot�� a��� ����Ʈ�� �̹� ������

                {

                    check = check + 1;//check �ø���

                }

            }

            for(i3 = 0; i3 < demand_num; i3++)

            {

                if(lot == demand[i3])//demand�� check�� ������ �ø���

                {

                    check = check + 1;

                }

            }

            for(k = 0; k < 6; k++)

            {

                if(lot == omitted[k])//���ſ� ������ check ������ �ø���

                {

                    check = check + 1;

                }

            }

            if(check < 2) //�� ������ �� �ɸ��� show����Ʈ�� �־��ְ�

            {

                show[5 - i2] = lot;

            }

            else//�ƴϸ� i2(���� ȶ��)�� �÷ȴ��� �ٽ� ���� = �ѹ� ����

            {

                i2 = i2 - 1;

            }

        }

        for(j = 2; j < 47; j++)

        {

            for(k = 0; k < 6; k++)

            {

                if(show[k] < j)//�� ������ ����Ʈ ũ�� �����Ƿ� �����Ϸ��� ���� ������

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

        printf("\n");//�� �Ǹ� ���� ���� �� �� �̰� ����

    }
    system("pause");
    return 0;
}