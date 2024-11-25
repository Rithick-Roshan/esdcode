#include<stdio.h>
#include<reg51.h>
#define lcd_port P2

// LCD Pins
sbit rs = P3^0;
sbit rw = P3^1;
sbit e  = P3^2;

// Keypad Pins
sbit r1 = P1^0;
sbit r2 = P1^1;
sbit r3 = P1^2;
sbit r4 = P1^3;

sbit c1 = P1^4;
sbit c2 = P1^5;
sbit c3 = P1^6;
sbit c4 = P1^7;

void delay(int t) {
    int i, j;
    for (i = 0; i < t; i++) {
        for (j = 0; j < 100; j++);
    }
}

void lcd_cmd(char cmd) {
    lcd_port = cmd;
    rs = 0;
    rw = 0;
    e = 1;
    delay(5);
    e = 0;
}

void lcd_data(char dat) {
    lcd_port = dat;
    rs = 1;
    rw = 0;
    e = 1;
    delay(5);
    e = 0;
}

void lcd_init() {
    lcd_cmd(0x38); // 8-bit mode
    delay(20);
    lcd_cmd(0x0F); // Display ON, Cursor ON
    delay(20);
    lcd_cmd(0x01); // Clear display
    delay(20);
    lcd_cmd(0x80); // Cursor at home position
    delay(20);
}

char scan_keypad() {
    // Row 1
    r1 = 0; r2 = r3 = r4 = 1;
    if (c1 == 0) { delay(2000); return '7'; }
    if (c2 == 0) { delay(2000); return '8'; }
    if (c3 == 0) { delay(2000); return '9'; }
    if (c4 == 0) { delay(2000); return 'A'; }

    // Row 2
    r2 = 0; r1 = r3 = r4 = 1;
    if (c1 == 0) { delay(2000); return '4'; }
    if (c2 == 0) { delay(2000); return '5'; }
    if (c3 == 0) { delay(2000); return '6'; }
    if (c4 == 0) { delay(2000); return 'B'; }

    // Row 3
    r3 = 0; r1 = r2 = r4 = 1;
    if (c1 == 0) { delay(2000); return '1'; }
    if (c2 == 0) { delay(2000); return '2'; }
    if (c3 == 0) { delay(2000); return '3'; }
    if (c4 == 0) { delay(2000); return 'C'; }

    // Row 4
    r4 = 0; r1 = r2 = r3 = 1;
    if (c1 == 0) { delay(20); return '*'; }
    if (c2 == 0) { delay(20); return '0'; }
    if (c3 == 0) { delay(20); return '#'; }
    if (c4 == 0) { delay(20); return 'D'; }

    return 0; // No key pressed
}

int main() {
    char key;
    lcd_init();

    while (1) {
        key = scan_keypad();
        if (key != 0) { // If a key is pressed
            lcd_data(key); // Display the pressed key
        }
    }
}
