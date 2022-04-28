#include <stdio.h>
#include <math.h>

void PrintBits(unsigned int x) {
    int i;
    for (i = 8 * sizeof(x)-1; i >= 0; i--) {
        (x & (1 << i)) ? putchar('1') : putchar('0');
    }
    printf("\n");
}

void PrintBitsOfByte(unsigned int x) {
    int i;
    for (i = 7; i >= 0; i--) {
        (x & (1 << i)) ? putchar('1') : putchar('0');
    }
    printf("\n");
}


// ======================== CHALLENGE ==================================

// Chall 1 - 1.1
int bitAnd(int x,int y){
    // Áp dụng công thức De Morgan: x & y = ~ (~x | ~y)
    int result = ~(~x | ~y);
    return result;
}

// Chall 2 - 1.2
int negative(int x){
    // Áp dụng công thức số bù 2 của một số: -x = ~x + 1 với ~x là số bù 1
    int result = ~x + 1;
    return result;
}

// Chall 3 - 1.3
int getBit(int x,int n){
    // Sử dụng mask và set bit đầu của mask bằng 1, sau đó dịch trái (n -1) bit để số n vào vị trí thích hợp
    // Sau đó sử dụng "and" operator với số ban đầu để đưa ra kết quả tại vị trí đó.
    // Dịch phải n bits để lấy số cần tìm
    int mask = 1 << n ;  // Mask
    int result = x & mask ;
    return  result >> n ; 
}

// Chall 4 - 1.4
int divpw2(int x, int n){
    // Phép chia sử đụng phép dịch phải, phép nhân sử dụng phép dịch trái - Tính chất của số nhị phân Binary
    // x dương thì sẽ là phép chia (dịch sang trái >> số âm), ngược lại nếu x âm thì dịch sang trái dương => Phép nhân 
    int result = x << (~n + 1 );
    return result;
}

// Chall 5 - 1.5
int modul2n(int x, int n){
    // Phép chia x với một sô 2^n thì phần dư luôn nằm trong khoảng [0, 2^n -1], tức là nằm trong n bits của số chia.
    // Vì vậy mình chỉ cần "&" với n bits 1 để lấy phần dư phía sau, phần đầu tất nhiên sẽ là các bit 0.
    int result = x & ((1 << n) + (~1+ 1));
    return result;
}

// Chall 6 - 2.1
int isEven(int x){
    // Kiểm tra phép "&" với 1, trường hợp lẻ khi và chỉ khi bits cuối là 1.
    int result = x & 1;
    return !result;
}

// Chall 7 - 2.2
int is16x(int x){
    // Bài này sử dụng lại kết quả của challenge 5, nếu dư 0 thì chia hết, nếu khác 0 thì không chia hết.
    // SỐ chia là 16 = 2^4 nên thay "n=4" vào công thức trên ta có hệ quả dưới:
    int modulo = x & ((1 << 4) - 1);
    int result = !(modulo & 1);
    return result;
} 

// Chall 8 - 2.3
int isPositive(int x){
    // Kiểm tra dương, âm bằng cách kiểm tra bit đầu tiên
    // Trường hợp đặc biệt là số 0 sẽ trả về 0, nên ta phải tìm cách tìm thêm một biểu thức để xử lý luận lý này, xem như cụm đầu là xét dương âm ta có:
    // 1 ? a = 0
    // 0 ? a = 1
    // 0 ? a = 0
    // Việc tìm a ta liên hệ với số x, phải chắc chắn có x và phân loại được trường hợp x(âm / dương !=0) với trường hợp x=0. Ở đây chọn a = !x
    // Vì !x đối với !=0 sẽ trả về 0, còn nếu đúng bằng 0 thì trả về 1.
    // Vậy ta đã có "a", vậy để có luận lý thích hợp thì ta cần chọn operator chính xác để bảng chân trị đúng. Ta thấy có phép "^" là chuẩn
    int result = (!(x >> 31)  ^ !x);
    return result;
}

int isLess2n(int x,int n){
    // Một số x < 2^n khi và chỉ khi bit 1 có trọng số lớn nhất của x nằm ở vị trí thấp hơn so với n.
    // Tức là dịch phải n bits thì bit 1 có trọng số lớn nhất vẫn nằm trong vùng, tức là khác 0 sau n lần dịch phải.
    return !(x >> n);
}

int main(){
    if (bitAnd(3, -9) == (3 & -9)){
        printf("Pass challenge 1.1\n");
    }
    if (negative(0) == 0 && negative(9) == -9 && negative(-5) == 5){
        printf("Pass challenge 1.2\n");
    }
    if (getBit(8,3) == 1 && getBit(5,0) == 1 && getBit(32,3) == 0){
        printf("Pass challenge 1.3\n");
    }
    if (divpw2(10, -1) == 20 && divpw2(15, -2) == 60 && divpw2(2, -4) == 32){
        printf("Pass challenge 1.4\n");
    }
    if (modul2n(2,1) == 0 && modul2n(30,2) == 2 && modul2n(63,6) == 63) {
        printf("Pass challenge 1.5\n");
    }
    if (isEven(4) && !isEven(13) && isEven(50)){
        printf("Pass challenge 2.1\n");
    }
    if (is16x(16) && !is16x(31) && is16x(0)){
        printf("Pass challenge 2.2\n");
    }
    if (isPositive(10) && !isPositive(-5) && !isPositive(0)){
        printf("Pass challenge 2.3\n");
    }
    if (isLess2n(12,4) && !isLess2n(8,3) && !isLess2n(15,2)){
        printf("Pass challenge 2.4");
    }
}