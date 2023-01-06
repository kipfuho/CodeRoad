#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

struct c2{
    char macuahang[10];
    char diachi[30];
    int sonhanvien;
    long doanhso;
};

void nhapmacuahang(char *s){
	int i,m=0;
    while(m==0){
		scanf("%s",s);
		for(i=0;i<10;i++){			
			int a=s[i]-'0';
			if(s[i]=='\0'){break;}
			if(a<0||a>9){
				m++;
				break;
			}
		}
		if(m!=0){printf("Ma cua hang co ki tu khong phai so moi nhap lai.\n");m=0;}
		else{break;}
	}
}

void sapxep(struct c2 sh[],int n){
    int i,j;
    struct c2 temp;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(sh[i].doanhso<sh[j].doanhso){
                temp=sh[i];
                sh[i]=sh[j];
                sh[j]=temp;
            }
        }
    }
}

void inra(struct c2 sh[],int n){
    int i;
    printf("+-----+-------------+--------------+----------------+---------------------------------+\n");
    printf("| STT | Ma cua hang | So nhan vien |    Doanh so    |             Dia chi             |\n");
    printf("+-----+-------------+--------------+----------------+---------------------------------+\n");
    for(i=0;i<n;i++){
        printf("| %-3d | %-11s | %-12d | %-14d | %-31s |\n",i+1,sh[i].macuahang,sh[i].sonhanvien,sh[i].doanhso,sh[i].diachi);
    }
}

void nhap(){
    int i,n,a3;
    long long a4;
    char a1[31],a2[10];
    printf("Hay nhap so cua hang: ");
    scanf("%d",&n);
    struct c2 sh[n];
    for(i=0;i<n;i++){
        printf("Nhap dia chi cua hang %d: ",i+1);
        fscanf(stdin," ");
        fgets(a1,31,stdin);
        a1[strlen(a1)-1]='\0';
        strcpy(sh[i].diachi,a1);
        printf("Nhap ma cua hang: ");
        nhapmacuahang(a2);
        strcpy(sh[i].macuahang,a2);
        printf("Nhap so nhan vien: ");
        while(0==0){
            scanf("%d",&a3);
            if(a3<0){
                printf("So nhan vien khong hop le, moi nhap lai: ");
            }
            else{
                break;
            }
        }
        sh[i].sonhanvien=a3;
        printf("Nhap doanh so: ");
        while(0==0){
            scanf("%d",&a4);
            if(a4<0){
                printf("Doanh so khong hop le, moi nhap lai: ");
            }
            else{
                break;
            }
        }
        sh[i].doanhso=a4;
    }
    sapxep(sh,n);
    inra(sh,n);
}

int main(){
    nhap();
}