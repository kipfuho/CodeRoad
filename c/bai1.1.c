// Nguyễn Đình Út Biu - 20215317
/*
Bài 1.1. Viết một chương trình C nhập vào 3 số nguyên. 
Thiết lập một con trỏ để lần lượt trỏ tới từng số nguyên 
và hiển thị kết quả giá trị tham chiếu ngược của con trỏ.
*/

# include <stdio.h>
int main(){
    printf("Nguyen Dinh Ut Biu - 20215317\n");

    int x, y, z;
    
    int* ptr;
    
    printf("Enter three integers: ");
    
    scanf("%d %d %d", &x, &y, &z);
    
    printf("\nThe three integers are:\n");

    // trỏ tới x và in kết quả tham chiếu ngược
    ptr = &x;
    printf("x = %d\n", *ptr);
    
    // trỏ tới y và in kết quả tham chiếu ngược
    ptr = &y;
    printf("y = %d\n", *ptr);
    
    // trỏ tới z và in kết quả tham chiếu ngược
    ptr = &z;
    printf("z = %d\n", *ptr);
    
    return 0;
}
