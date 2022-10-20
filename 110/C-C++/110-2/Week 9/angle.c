#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//degree angle

int main(void) {
    int h, m;
    float angle = 0;

    scanf("%d", &h);

    getchar();

    scanf("%d", &m);

    while((h + m != 0)) {
        if (h == 12) {
            h = 0;
        }
        if (m == 60) {
            m = 0;
            h += 1;
            if (h > 12) {
                h -= 12;
            }
        }

        float h_angle = 0.5 * (h * 60 + m);
        float m_angle = 6 * m;

        angle = fabsf(h_angle - m_angle);

        if (angle > 180) {
            angle = 360 - angle;
        }

        printf("%.3f\n", angle);
        angle = 0;

        scanf("%d", &h);

        getchar();

        scanf("%d", &m);
    }
    
}

    // if (m != 0) {
    //         min = m;
    //         m /= 5;
    //         if ((m - h) < 0) {
    //             m += 12;

    //             float temp = m - h;
    //             temp *= 30;

    //             if (temp > 180) {
    //                 angle = 360 - temp;
    //                 angle += min * 0.5;
    //             } 
    //             else {
    //                 angle = temp;
    //                 angle -= min * 0.5;
    //             }
    //         }
    //         else {
    //             float temp = m - h;
    //             temp *= 30;

    //             if (temp > 180) {
    //                 angle = 360 - temp;
    //                 angle += min * 0.5;
    //             } 
    //             else {
    //                 angle = temp;
    //                 angle -= min * 0.5;
    //             }

    //         }
    //     }
    //     else if (m == 0) {
    //         for (int i = h; i < 12; i++) {
    //             angle += 30;
    //         }
    //     }