#include <stdio.h>
struct realtype {
    int left;
    int right;
};

struct realtype InputRealNumber() {
    float r;
    struct realtype nums;
    printf("ENTER A REAL NUMBER : ");
    scanf("%f", &r);
    nums.left = (int)r;
    if (r > 0) {
        nums.right = (r - nums.left) * (100000000);
    } else
        nums.right = (r - nums.left) * -1 * (100000000);
    return nums;
}
float realNumber(struct realtype nums) {
    if (nums.left > 0) {
        return (nums.left + nums.right / 100000000.000);
    } else
        return ((nums.left * -1) + nums.right / 100000000.000) * -1;
}
void operationsOnRealNumbers() {
    struct realtype r1 = InputRealNumber();
    struct realtype r2 = InputRealNumber();
    float n1 = realNumber(r1);
    float n2 = realNumber(r2);
    printf("SUM OF TWO REAL NUMBER IS : %f\n", n1 + n2);
    printf("DIFFERENCE OF TWO REAL NUMBER IS : %f\n", n1 - +n2);
    printf("PRODUCT OF TWO REAL NUMBER IS : %f\n", n1 * n2);
    return;
}
int main() {
    struct realtype nums = InputRealNumber();
    float r = realNumber(nums);
    printf("REAL NUMBER IS %f\n", r);
    operationsOnRealNumbers();
}
