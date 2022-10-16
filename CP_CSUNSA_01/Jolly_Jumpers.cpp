#include <iostream>

int main() {

    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    bool jolly[n];
    for (int i = 0; i < n; ++i) {
        jolly[i] = false;
    }
    for (int i = 0; i < n - 1; ++i) {
        int diff = std::abs(a[i] - a[i + 1]);
        if (diff > 0 && diff < n) {
            jolly[diff] = true;
        }
    }
    bool is_jolly = true;
    for (int i = 1; i < n; ++i) {
        if (!jolly[i]) {
            is_jolly = false;
            break;
        }
    }
    
    if (is_jolly) {
        printf("Jolly");
    } else {
        printf("Not jolly");
    }
    
    return 0;
}