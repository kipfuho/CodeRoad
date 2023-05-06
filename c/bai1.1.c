# include <stdio.h>
int main(){
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
