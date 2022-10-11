// NAMA		: Figo Arzaki Maulana
// NRP		: 5022221041
// Jurusan	: Elektro

#include <iostream>
#include <cmath>

// Dapatkan vtan dari kecepatan awal
double vtan(double v){
    return v<=5 ? v+1 : v>5 && v<=15 ? v+3 : v>15 && v<= 25 ? v+5:v;
}

int main() {
    int vtanguide;
    double vo,kecepatan_tangensial;
    double smallest_delta = std::numeric_limits<double>::max();
    int jarak;
    scanf("%d",&vtanguide);
    // vtan maksimal adalah 30, jika input lebih dari 30, clip pada 30
    vtanguide = (vtanguide > 30) ? 30 : vtanguide;
    int x_step = 1; // Evaluasi dari jarak pengukuran 1 meter
    while(x_step <= 62){ // Jarak paling maksimum yg bisa dicapai robot adalah 62m (saat vtan 29.8998, karena vtan maksimum adalah 30)
        // cari vo untuk jarak x_step
        vo = sqrt(x_step*10);
        // Cari kecepatan tangensial dari vo yang paling dekat dengan input
        double abs_d = fabs(vtanguide - vtan(vo));
        if(smallest_delta > abs_d){
            // Sepertinya kita dapat angka yang paling dekat input, simpan kecepatan tangensialnya dan jaraknya
            smallest_delta = abs_d;
            kecepatan_tangensial = vtan(vo);
            jarak = x_step;
        }
        x_step++;
    }
    
  	printf("%d %.4f",jarak,kecepatan_tangensial);
    return 0;
}