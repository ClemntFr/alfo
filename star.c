#include <stdio.h>

void my_putchar(char c) {
    printf("%c", c);
}

static void my_putnchar(char c, unsigned int n) {
    for (int i=0; i < n; i++) {
        my_putchar(c);
    }
}

static void display_line(unsigned int n) {
    my_putnchar('*', 2*n+1);
    int off = 1/n;
    my_putnchar(' ', 2*(n+off)-3);
    my_putnchar('*', 2*n+1);
}

static void jsp_encore(unsigned int n, unsigned int a, unsigned int b) {
    for (int i=a; i < b; i++) {
        my_putnchar(' ', 3*n - 1 + 1/n -i);
        my_putchar('*');
        my_putnchar(' ', 2*i-1);
        my_putchar('*');
        my_putchar('\n');
    }
}

static void jsp_encore_inv(unsigned int n, unsigned int a, unsigned int b) {
    for (int i=a; i > b; i--) {
        my_putnchar(' ', 3*n-1 + 1/n -i);
        my_putchar('*');
        my_putnchar(' ', 2*i-1);
        my_putchar('*');
        my_putchar('\n');
    }
}

static void display_head(unsigned int n) {
    my_putnchar(' ', 3*n-1 + 1/n);
    my_putchar('*');
    my_putchar('\n');
    jsp_encore(n, 1, n);
}

static void display_mid(unsigned int n) {
    jsp_encore_inv(n, 3*n-2, 2*n-1);
    jsp_encore(n, 2*n-1+1/n, 3*n-1+1/n);
}

static void star(unsigned int n) {
    if (n == 0) { return; }
    display_head(n);
    display_line(n);
    my_putchar('\n');
    display_mid(n);
    display_line(n);
    my_putchar('\n');
    jsp_encore_inv(n, n-1, 0);
    my_putnchar(' ', 3*n-1 + 1/n);
    my_putchar('*');
    my_putchar('\n');

}

int main(void) {
    star(1);
    return 0;
}

